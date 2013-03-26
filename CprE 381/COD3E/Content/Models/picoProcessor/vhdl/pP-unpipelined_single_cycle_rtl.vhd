library ieee;  use ieee.numeric_bit.all;

use work.pP_defs.all;

architecture unpipelined_single_cycle_rtl of pP is

  signal PC : instruction_addr;
  signal incr_PC : instruction_addr;
  signal next_PC : instruction_addr;

  signal branch_taken : bit;

  signal IR : instruction;

  alias IR_op2 : op2 is IR(18 downto 17);
  alias IR_op3 : op3 is IR(18 downto 16);
  alias IR_op5 : op5 is IR(18 downto 14);
  alias IR_op6 : op6 is IR(18 downto 13);
  
  alias IR_alu_fn : alu_fn_code is IR(16 downto 14);
  alias IR_shift_fn : shift_fn_code is IR(15 downto 14);
  alias IR_mem_fn : mem_fn_code is IR(15 downto 14);
  alias IR_branch_fn : branch_fn_code is IR(15 downto 14);
  
  alias IR_rd : reg_addr is IR(13 downto 11);
  alias IR_r1 : reg_addr is IR(10 downto 8);
  alias IR_r2 : reg_addr is IR(7 downto 5);
  alias IR_const : const is IR(7 downto 0);
  alias IR_sc : shift_count is IR(7 downto 5);
  alias IR_disp : disp is IR(7 downto 0);
  alias IR_addr : instruction_addr is IR(11 downto 0);
  
  signal int_PC : instruction_addr;
  signal int_z : bit;
  signal int_c : bit;
  signal int_en : bit;

  signal stack_top : instruction_addr;

  signal GPR_r1 : byte;
  signal GPR_r2 : byte;

  signal ALU_result : byte;
  signal ALU_z : bit;
  signal ALU_c : bit;

  signal DMem_out : byte;
  
  signal cc_z : bit;
  signal cc_c : bit;
  
begin

  with IR_branch_fn select
    branch_taken <=     cc_z when branch_fn_bz,
                    not cc_z when branch_fn_bnz,
                        cc_c when branch_fn_bc,
                    not cc_c when branch_fn_bnc;

  incr_PC <= PC + 1;

  next_PC <=
    to_unsigned(1, PC'length) when int_en = '1' and int_req = '1' else
    int_PC                    when IR_op6 = op6_reti else
    stack_top                 when IR_op6 = op6_ret else
    IR_addr                   when IR_op5 = op5_jump or IR_op5 = op5_jsb else
    unsigned(signed(incr_PC) + signed(IR_disp))
                              when IR_op3 = op3_branch and branch_taken = '1' else
    incr_PC;
                    
  PC_reg : process
  begin
    wait until clk = '1';
    if reset = '1' then
      PC <= (others => '0');
    else 
      PC <= next_PC;
    end if;
  end process PC_reg;

  int_reg : process
  begin
    wait until clk = '1';
    if reset = '1' then
      int_en <= '0';
      int_ack <= '0';
    elsif int_en = '1' and int_req = '1' then
      int_PC <= PC;
      int_z <= cc_z;
      int_c <= cc_c;
      int_en <= '0';
      int_ack <= '1';
    else
      int_ack <= '0';
      case IR_op6 is
        when op6_reti | op6_enai =>
          int_en <= '1';
        when op6_disi =>
          int_en <= '0';
        when others =>
          null;
      end case;
    end if;
  end process int_reg;

  instr_mem : process (PC)
    constant IMem : IMem_array := load_program ( program_file_name );
  begin
    IR <= IMem(to_integer(PC));
  end process instr_mem;

  stack_mem : process
    constant SP_length : positive := 2;
    constant stack_depth : positive := 2**SP_length;
    subtype stack_index is natural range 0 to stack_depth - 1;
    type stack_array is array (stack_index) of instruction_addr;
    variable stack : stack_array;
    variable SP : unsigned(SP_length - 1 downto 0);
  begin
    wait until clk = '1';
    if reset = '1' then
      SP := (others => '0');
    elsif not (int_en = '1' and int_req = '1') then
      if IR_op5 = op5_jsb then
        stack(to_integer(SP)) := incr_PC;
        SP := SP + 1;
      elsif IR_op6 = op6_ret then
        SP := SP - 1;
      end if;
    end if;
    stack_top <= stack(to_integer(SP-1));
  end process stack_mem;

  GPR_mem : process (clk, reset, int_en, int_req,
                     IR_op2, IR_op3, IR_r1, IR_r2, IR_rd,
                     ALU_result, DMem_out, port_data)
                     
    subtype reg_index is natural range 0 to 7;
    variable GPR : byte_array(reg_index) := (others => X"00");
  begin
    if clk'event and clk = '1' then
      if reset = '1' then
        GPR := (others => (others => '0'));
      elsif not (int_en = '1' and int_req = '1')
          and (IR_rd /= reg_addr'(others => '0')) then
        if IR_op2 = op2_alu_reg_reg or IR_op2 = op2_alu_reg_immed
          or IR_op3 = op3_shift then
          GPR(to_integer(IR_rd)) := ALU_result;
        elsif IR_op3 = op3_mem and IR_mem_fn = mem_fn_ldm then
          GPR(to_integer(IR_rd)) := DMem_out;
        elsif IR_op3 = op3_mem and IR_mem_fn = mem_fn_inp then
          GPR(to_integer(IR_rd)) := byte(to_bitvector(port_data));
        end if;
      end if;
    end if;
    GPR_r1 <= GPR(to_integer(IR_r1));
    if IR_op3 = op3_mem
      and (IR_mem_fn = mem_fn_stm or IR_mem_fn = mem_fn_out) then
      GPR_r2 <= GPR(to_integer(IR_rd));
    else
      GPR_r2 <= GPR(to_integer(IR_r2));
    end if;
  end process GPR_mem;

  ALU : process (GPR_r2, GPR_r1, cc_c, IR_const, IR_sc,
                 IR_op2, IR_alu_fn, IR_shift_fn)
    variable fn : alu_fn_code;
    variable right_operand : byte;
    variable tmp_result : unsigned(byte'length downto 0);
    variable shift_result : byte;
  begin
    if IR_op2 = op2_alu_reg_reg or IR_op2 = op2_alu_reg_immed
        or IR_op3 = op3_mem then
      if IR_op2 = op2_alu_reg_reg then
        fn := IR_alu_fn;
        right_operand := GPR_r2;
      elsif IR_op2 = op2_alu_reg_immed then
        fn := IR_alu_fn;
        right_operand := IR_const;
      else
        fn := alu_fn_add;
        right_operand := IR_const;      -- same as IR_disp
      end if;
      case fn is
        when alu_fn_add =>
          tmp_result := ('0' & GPR_r1) + ('0' & right_operand);
        when alu_fn_addc =>
          tmp_result := ('0' & GPR_r1) + ('0' & right_operand)
                            + resize(unsigned'('0' & cc_c), byte'length + 1);
        when alu_fn_sub =>
          tmp_result := ('0' & GPR_r1) - ('0' & right_operand);
        when alu_fn_subc =>
          tmp_result := ('0' & GPR_r1) - ('0' & right_operand)
                            - resize(unsigned'('0' & cc_c), byte'length + 1);
        when alu_fn_and =>
          tmp_result := ('0' & GPR_r1) and ('0' & right_operand);
        when alu_fn_or =>
          tmp_result := ('0' & GPR_r1) or ('0' & right_operand);
        when alu_fn_xor =>
          tmp_result := ('0' & GPR_r1) xor ('0' & right_operand);
        when alu_fn_msk =>
          tmp_result := ('0' & GPR_r1) and not ('0' & right_operand);
      end case;
      ALU_result <= tmp_result(byte'length - 1 downto 0);
      ALU_c <= tmp_result(byte'length);
    else
      case IR_shift_fn is
        when shift_fn_shl =>
          tmp_result := ('0' & GPR_r1) sll to_integer(IR_sc);
          shift_result := tmp_result(byte'length - 1 downto 0);
          ALU_c <= tmp_result(byte'length);
        when shift_fn_shr =>
          tmp_result := (GPR_r1 & '0') srl to_integer(IR_sc);
          shift_result := tmp_result(byte'length downto 1);
          ALU_c <= tmp_result(0);
        when shift_fn_rol =>
          shift_result := GPR_r1 rol to_integer(IR_sc);
          ALU_c <= shift_result(byte'right);
        when shift_fn_ror =>
          shift_result := GPR_r1 ror to_integer(IR_sc);
          ALU_c <= shift_result(byte'left);
      end case;
      ALU_result <= shift_result;      
    end if;
  end process ALU;

  ALU_z <= '1' when ALU_result = byte'(others => '0') else
           '0';

  cc_reg : process
  begin
    wait until clk = '1';
    if reset = '1' then
      cc_z <= '0';
      cc_c <= '0';
    elsif not (int_en = '1' and int_req = '1') then
      if IR_op2 = op2_alu_reg_reg or IR_op2 = op2_alu_reg_immed
          or IR_op3 = op3_shift then
        cc_z <= ALU_z;
        cc_c <= ALU_c;
      elsif IR_op6 = op6_reti then
        cc_z <= int_z;
        cc_c <= int_c;
      end if;
    end if;
  end process cc_reg;

  data_mem : process (clk, IR_op3, IR_mem_fn, ALU_result, GPR_r2)
    variable DMem : byte_array(0 to DMem_size - 1);
  begin
    if clk'event and clk = '1' then
      if not (int_en = '1' and int_req = '1')
          and IR_op3 = op3_mem and IR_mem_fn = mem_fn_stm then
        DMem(to_integer(ALU_result)) := GPR_r2;
      end if;
    end if;
    DMem_out <= DMem(to_integer(ALU_result));
  end process data_mem;

  port_addr <=
    ALU_result when not (int_en = '1' and int_req = '1')
                      and IR_op3 = op3_mem
                      and (IR_mem_fn = mem_fn_out or IR_mem_fn = mem_fn_inp) else
    (others => '0');

  port_data <=
    to_stdulogicvector(bit_vector(GPR_r2))
      when not (int_en = '1' and int_req = '1')
                   and IR_op3 = op3_mem and IR_mem_fn = mem_fn_out else
    (others => 'Z');

  port_read <= '1' when not (int_en = '1' and int_req = '1')
                          and IR_op3 = op3_mem and IR_mem_fn = mem_fn_inp else
               '0';

  port_write <= '1' when not (int_en = '1' and int_req = '1')
                           and IR_op3 = op3_mem and IR_mem_fn = mem_fn_out else
                '0';

  debug_monitor : if debug generate

    debugger : process
      use std.textio.all;
      variable disassembled_instr : disassembled_instruction;
      variable debug_line : line;
      variable PC_num : natural;
    begin
      wait until clk = '1';
      PC_num := to_integer(PC);
      if reset = '1' then
        write(debug_line, string'("Resetting"));
      elsif int_en = '1' and int_req = '1' then
        write(debug_line, string'("Interrupt acknowledged at PC = "));
        write(debug_line, PC_num, field => 4, justified => right);
      else
        disassemble(IR, disassembled_instr);
        write(debug_line, PC_num, field => 4, justified => right);
        write(debug_line, string'(": "));
        write(debug_line, disassembled_instr);
      end if;
      writeline(output, debug_line);
    end process debugger;

  end generate debug_monitor;

end architecture unpipelined_single_cycle_rtl;

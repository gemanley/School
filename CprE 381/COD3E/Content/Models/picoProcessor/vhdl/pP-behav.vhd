library ieee;  use ieee.numeric_bit.all;

use work.pP_defs.all;
use std.textio.all;

architecture behav of pP is
begin

  interpreter : process

    constant IMem : IMem_array := load_program ( program_file_name );
    variable DMem : byte_array(0 to DMem_size - 1);

    variable PC : instruction_addr := (others => '0');

    variable IR : instruction;

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

    constant stack_depth : positive := 4;
    subtype stack_index is natural range 0 to stack_depth - 1;
    type stack_array is array (stack_index) of instruction_addr;
    variable stack : stack_array;
    variable SP : stack_index := 0;

    subtype reg_index is natural range 0 to 7;
    variable GPR : byte_array(reg_index) := (others => X"00");

    variable ALU_result : byte;
    variable cc_z : bit := '0';
    variable cc_c : bit := '0';

    variable int_en : bit := '0';
    variable int_PC : instruction_addr;
    variable int_z, int_c : bit;

    variable disassembled_instr : disassembled_instruction;
    variable debug_line : line;

    procedure perform_reset is
    begin
      int_ack <= '0';
      port_read <= '0';
      port_write <= '0';
      port_data <= (others => 'Z');
      PC := (others => '0');
      SP := 0;
      GPR := (others => X"00");
      cc_z := '0';
      cc_c := '0';
      int_en := '0';
    end perform_reset;

    procedure perform_interrupt is
      variable PC_num : natural;
    begin
      PC_num := to_integer(PC);
      int_PC := PC;
      int_z := cc_z;
      int_c := cc_c;
      int_en := '0';
      int_ack <= '1';
      PC := to_unsigned(1, PC'length);
      if debug then
        write(debug_line, string'("Interrupt acknowledged at PC = "));
        write(debug_line, PC_num, field => 4, justified => right);
        writeline(output, debug_line);
      end if;
    end procedure perform_interrupt;

    procedure fetch_instruction is
      variable PC_num : natural;
    begin
      int_ack <= '0';
      PC_num := to_integer(PC);
      IR := IMem(PC_num);
      PC := PC + 1;
      if debug then
        disassemble(IR, disassembled_instr);
        write(debug_line, PC_num, field => 4, justified => right);
        write(debug_line, string'(": "));
        write(debug_line, disassembled_instr);
        writeline(output, debug_line);
      end if;
    end procedure fetch_instruction;

    procedure perform_alu_op ( fn : in alu_fn_code;
                               a, b : in byte;
                               c_in : in bit;
                               result : out byte;
                               z_out, c_out : out bit ) is
      variable tmp_result : unsigned(byte'length downto 0);
    begin
      case fn is
        when alu_fn_add =>
          tmp_result := ('0' & a) + ('0' & b);
        when alu_fn_addc =>
          tmp_result := ('0' & a) + ('0' & b) + bit'pos(c_in);
        when alu_fn_sub =>
          tmp_result := ('0' & a) - ('0' & b);
        when alu_fn_subc =>
          tmp_result := ('0' & a) - ('0' & b) - bit'pos(c_in);
        when alu_fn_and =>
          tmp_result := ('0' & a) and ('0' & b);
        when alu_fn_or =>
          tmp_result := ('0' & a) or ('0' & b);
        when alu_fn_xor =>
          tmp_result := ('0' & a) xor ('0' & b);
        when alu_fn_msk =>
          tmp_result := ('0' & a) and not ('0' & b);
      end case;
      result := tmp_result(byte'length - 1 downto 0);
      if tmp_result(byte'length - 1 downto 0) = byte'(others => '0') then
        z_out := '1';
      else
        z_out := '0';
      end if;
      c_out := tmp_result(byte'length);
    end procedure perform_alu_op;

    procedure perform_shift_op ( fn : in shift_fn_code;
                                 a : in byte;
                                 sc : in shift_count;
                                 result : out byte;
                                 z_out, c_out : out bit ) is
      variable tmp_result : unsigned(byte'length downto 0);
      variable out_result : byte;
    begin
      case fn is
        when shift_fn_shl =>
          tmp_result := ('0' & a) sll to_integer(sc);
          out_result := tmp_result(byte'length - 1 downto 0);
          c_out := tmp_result(byte'length);
        when shift_fn_shr =>
          tmp_result := (a & '0') srl to_integer(sc);
          out_result := tmp_result(byte'length downto 1);
          c_out := tmp_result(0);
        when shift_fn_rol =>
          out_result := a rol to_integer(sc);
          c_out := out_result(byte'right);
        when shift_fn_ror =>
          out_result := a ror to_integer(sc);
          c_out := out_result(byte'left);
      end case;
      if out_result = byte'(others => '0') then
        z_out := '1';
      else
        z_out := '0';
      end if;
      result := out_result;
    end procedure perform_shift_op;

    procedure perform_mem is
      variable mem_addr : byte;
      variable tmp_z, tmp_c : bit;
    begin
      perform_alu_op(fn => alu_fn_add,
                     a => GPR(to_integer(IR_r1)), b => byte(IR_disp),
                     c_in => '0',
                     result => mem_addr, z_out => tmp_z, c_out => tmp_c);
      case IR_mem_fn is
        when mem_fn_ldm =>
          if to_integer(IR_rd) /= 0 then
            GPR(to_integer(IR_rd)) := DMem(to_integer(mem_addr));
          end if;
        when mem_fn_stm =>
          DMem(to_integer(mem_addr)) := GPR(to_integer(IR_rd));
        when mem_fn_inp =>
          port_addr <= mem_addr;
          port_read <= '1';
          inp_loop : loop
            wait until clk = '1';
            if reset = '1' then
              return;
            end if;
            exit inp_loop when port_ready = '1';
          end loop inp_loop;
          if to_integer(IR_rd) /= 0 then
            GPR(to_integer(IR_rd)) := byte(to_bitvector(port_data));
          end if;
          port_addr <= (others => '0');
          port_read <= '0';
        when mem_fn_out =>
          port_addr <= mem_addr;
          port_data <= to_stdulogicvector(bit_vector(GPR(to_integer(IR_rd))));
          port_write <= '1';
          out_loop : loop
            wait until clk = '1';
            if reset = '1' then
              return;
            end if;
            exit out_loop when port_ready = '1';
          end loop out_loop;
          port_addr <= (others => '0');
          port_data <= (others => 'Z');
          port_write <= '0';
      end case;
    end procedure perform_mem;
    
    procedure perform_branch is
      variable branch_taken : boolean;
    begin
      case IR_branch_fn is
        when branch_fn_bz =>
          branch_taken := cc_z = '1';
        when branch_fn_bnz =>
          branch_taken := cc_z = '0';
        when branch_fn_bc =>
          branch_taken := cc_c = '1';
        when branch_fn_bnc =>
          branch_taken := cc_c = '0';
      end case;
      if branch_taken then
        PC := unsigned(signed(PC) + signed(IR_disp));
      end if;
    end procedure perform_branch;

    procedure perform_jump is
    begin
      case IR_op5 is
        when op5_jump =>
          PC := IR_addr;
        when op5_jsb =>
          stack(SP) := PC;
          SP := (SP + 1) mod stack_depth;
          PC := IR_addr;
        when others =>
          report "Program logic error in interpreter" severity failure;
      end case;
    end procedure perform_jump;

    procedure perform_misc is
    begin
      case IR_op6 is
        when op6_ret =>
          SP := (SP - 1) mod stack_depth;
          PC := stack(SP);
        when op6_reti =>
          PC := int_PC;
          cc_z := int_z;
          cc_c := int_c;
          int_en := '1';
        when op6_enai =>
          int_en := '1';
        when op6_disi =>
          int_en := '0';
        when others =>
          report "Program logic error in interpreter" severity failure;
      end case;
    end procedure perform_misc;

  begin
    perform_reset;
    wait on clk until clk = '1' and reset = '0';
    main_loop : loop
      wait until clk = '1';
      exit main_loop when reset = '1';
      if int_en = '1' and int_req = '1' then
        perform_interrupt;
        next main_loop;
      end if;
      
      fetch_instruction;
      
      case IR_op2 is
        when op2_alu_reg_reg =>
          perform_alu_op(fn => IR_alu_fn,
                         a => GPR(to_integer(IR_r1)),
                         b => GPR(to_integer(IR_r2)),
                         c_in => cc_c,
                         result => ALU_result,
                         z_out => cc_z, c_out => cc_c);
          if to_integer(IR_rd) /= 0 then
            GPR(to_integer(IR_rd)) := ALU_result;
          end if;
        when op2_alu_reg_immed =>
          perform_alu_op(fn => IR_alu_fn,
                         a => GPR(to_integer(IR_r1)),
                         b => IR_const,
                         c_in => cc_c,
                         result => ALU_result,
                         z_out => cc_z, c_out => cc_c);
          if to_integer(IR_rd) /= 0 then
            GPR(to_integer(IR_rd)) := ALU_result;
          end if;
        when op2_use_op3_0 | op2_use_op3_1 =>
          case IR_op3 is
            when op3_mem =>
              perform_mem;
              exit main_loop when reset = '1';
            when op3_branch =>
              perform_branch;
            when op3_shift =>
                perform_shift_op(fn => IR_shift_fn,
                                 a => GPR(to_integer(IR_r1)),
                                 sc => IR_sc,
                                 result => ALU_result,
                                 z_out => cc_z, c_out => cc_c);
              if to_integer(IR_rd) /= 0 then
                GPR(to_integer(IR_rd)) := ALU_result;
              end if;
            when op3_use_op5 =>
              case IR_op5 is
                when op5_jump | op5_jsb =>
                  perform_jump;
                when op5_use_op6_0 | op5_use_op6_1 =>
                  perform_misc;
                when others =>
                  report "Program logic error in interpreter" severity failure;
              end case;
            when others =>
              report "Program logic error in interpreter" severity failure;
          end case;
      end case;

    end loop main_loop;
  end process interpreter;

end architecture behav;

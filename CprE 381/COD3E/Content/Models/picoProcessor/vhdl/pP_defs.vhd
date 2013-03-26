library ieee;
use ieee.std_logic_1164.all, ieee.numeric_bit.all;

package pP_defs is

  constant IMem_size : positive := 4096;
  constant DMem_size : positive := 256;

  subtype byte is unsigned(7 downto 0);
  type byte_array is array (natural range <>) of byte;

  subtype instruction is unsigned(18 downto 0);
  type instruction_array is array (natural range <>) of instruction;

  subtype std_ulogic_byte is std_ulogic_vector(7 downto 0);
  subtype std_logic_byte is std_logic_vector(7 downto 0);

  subtype instruction_addr is unsigned(11 downto 0);
  subtype reg_addr is unsigned(2 downto 0);
  subtype const is unsigned(7 downto 0);
  subtype disp is unsigned(7 downto 0);
  subtype shift_count is unsigned(2 downto 0);

  subtype alu_fn_code is unsigned(2 downto 0);
  subtype shift_fn_code is unsigned(1 downto 0);
  subtype mem_fn_code is unsigned(1 downto 0);
  subtype branch_fn_code is unsigned(1 downto 0);
  
  constant alu_fn_add  : alu_fn_code := "000";
  constant alu_fn_addc : alu_fn_code := "001";
  constant alu_fn_sub  : alu_fn_code := "010";
  constant alu_fn_subc : alu_fn_code := "011";
  constant alu_fn_and  : alu_fn_code := "100";
  constant alu_fn_or   : alu_fn_code := "101";
  constant alu_fn_xor  : alu_fn_code := "110";
  constant alu_fn_msk  : alu_fn_code := "111";

  constant shift_fn_shl : shift_fn_code := "00";
  constant shift_fn_shr : shift_fn_code := "01";
  constant shift_fn_rol : shift_fn_code := "10";
  constant shift_fn_ror : shift_fn_code := "11";

  constant mem_fn_ldm : mem_fn_code := "00";
  constant mem_fn_stm : mem_fn_code := "01";
  constant mem_fn_inp : mem_fn_code := "10";
  constant mem_fn_out : mem_fn_code := "11";

  constant branch_fn_bz  : branch_fn_code := "00";
  constant branch_fn_bnz : branch_fn_code := "01";
  constant branch_fn_bc  : branch_fn_code := "10";
  constant branch_fn_bnc : branch_fn_code := "11";

  subtype op2 is unsigned(1 downto 0);
  subtype op3 is unsigned(2 downto 0);
  subtype op5 is unsigned(4 downto 0);
  subtype op6 is unsigned(5 downto 0);

  constant op2_alu_reg_reg   : op2 := "00";
  constant op2_alu_reg_immed : op2 := "01";
  constant op2_use_op3_0     : op2 := "10";
  constant op2_use_op3_1     : op2 := "11";

  constant op3_mem     : op3 := "100";
  constant op3_branch  : op3 := "101";
  constant op3_shift   : op3 := "110";
  constant op3_use_op5 : op3 := "111";

  constant op5_jump      : op5 := "11100";
  constant op5_jsb       : op5 := "11101";
  constant op5_use_op6_0 : op5 := "11110";
  constant op5_use_op6_1 : op5 := "11111";
  
  constant op6_ret  : op6 := "111100";
  constant op6_reti : op6 := "111101";
  constant op6_enai : op6 := "111110";
  constant op6_disi : op6 := "111111";
  
  subtype disassembled_instruction is string(1 to 30);
  
  procedure disassemble ( instr : instruction;
                          result : out disassembled_instruction );

  subtype IMem_array is instruction_array(0 to IMem_size - 1);

  function load_program ( program_file_name : string ) return IMem_array;

end package pP_defs;

package body pP_defs is

  procedure disassemble ( instr : instruction;
                          result : out disassembled_instruction ) is

    subtype name is string(1 to 4);

    type name_table is array (natural range <>) of name;

    constant alu_name_table : name_table(0 to 7)
      := ( 0 => "ADD ", 1 => "ADDC", 2 => "SUB ", 3 => "SUBC",
           4 => "AND ", 5 => "OR  ", 6 => "XOR ", 7 => "MSK " );

    constant shift_name_table : name_table(0 to 3 )
      := ( 0 => "SHL ", 1 => "SHR ", 2 => "ROL ", 3 => "ROR " );

    constant mem_name_table : name_table(0 to 3 )
      := ( 0 => "LDM ", 1 => "STM ", 2 => "INP ", 3 => "OUT " );

    constant branch_name_table : name_table(0 to 3 )
      := ( 0 => "BZ  ", 1 => "BNZ ", 2 => "BC  ", 3 => "BNC " );

    constant jump_name_table : name_table(0 to 1)
      := ( 0 => "JUMP", 1 => "JSB " );

    constant misc_name_table : name_table(0 to 3)
      := ( 0 => "RET ", 1 => "RETI", 2 => "ENAI", 3 => "DISI" );

    procedure disassemble_reg ( reg : reg_addr; index : positive ) is
      constant str : string := integer'image(to_integer(reg));
    begin
      result(index) := str(str'left);
    end procedure disassemble_reg;

    procedure disassemble_unsigned ( n : unsigned; index : positive ) is
      constant str : string := integer'image(to_integer(n));
    begin
      result(index to index + str'length - 1) := str;
    end procedure disassemble_unsigned;
      
    procedure disassemble_signed ( n : signed; index : positive ) is
      constant str : string := integer'image(to_integer(n));
    begin
      result(index to index + str'length - 1) := str;
    end procedure disassemble_signed;
      
    procedure disassemble_effective_addr ( r : reg_addr; d : disp;
                                           index : positive ) is
      constant signed_str : string := integer'image(to_integer(signed(d)));
      constant unsigned_str : string := integer'image(to_integer(d));
    begin
      if r = 0 then
        result(index to index + unsigned_str'length - 1) := unsigned_str;
      else
        result(index to index + signed_str'length - 1) := signed_str;
        result(index + signed_str'length to index + signed_str'length + 3)
          := "(R )";
        disassemble_reg(r, index + signed_str'length + 2);
      end if;
    end procedure disassemble_effective_addr;
      
    alias instr_op2 : op2 is instr(18 downto 17);
    alias instr_op3 : op3 is instr(18 downto 16);
    alias instr_op5 : op5 is instr(18 downto 14);
    alias instr_op6 : op6 is instr(18 downto 13);
    
    alias instr_alu_fn : alu_fn_code is instr(16 downto 14);
    alias instr_shift_fn : shift_fn_code is instr(15 downto 14);
    alias instr_mem_fn : mem_fn_code is instr(15 downto 14);
    alias instr_branch_fn : branch_fn_code is instr(15 downto 14);

    alias instr_rd : reg_addr is instr(13 downto 11);
    alias instr_r1 : reg_addr is instr(10 downto 8);
    alias instr_r2 : reg_addr is instr(7 downto 5);
    alias instr_const : const is instr(7 downto 0);
    alias instr_sc : shift_count is instr(7 downto 5);
    alias instr_disp : disp is instr(7 downto 0);
    alias instr_addr : instruction_addr is instr(11 downto 0);

  begin
    result := (others => ' ');
    case instr_op2 is
      when op2_alu_reg_reg =>
        result(1 to name'length)
          := alu_name_table(to_integer(instr_alu_fn));
        result(name'length + 2 to name'length + 10) := "R , R , R";
        disassemble_reg(instr_rd, name'length + 3);
        disassemble_reg(instr_r1, name'length + 7);
        disassemble_reg(instr_r2, name'length + 11);
      when op2_alu_reg_immed =>
        result(1 to name'length)
          := alu_name_table(to_integer(instr_alu_fn));
        result(name'length + 2 to name'length + 8) := "R , R ,";
        disassemble_reg(instr_rd, name'length + 3);
        disassemble_reg(instr_r1, name'length + 7);
        disassemble_unsigned(instr_const, name'length + 10);
      when op2_use_op3_0 | op2_use_op3_1 =>
        case instr_op3 is
          when op3_mem =>
            result(1 to name'length)
              := mem_name_table(to_integer(instr_mem_fn));
            result(name'length + 2 to name'length + 4) := "R ,";
            disassemble_reg(instr_rd, name'length + 3);
            disassemble_effective_addr(instr_r1, instr_disp, name'length + 6);
          when op3_branch =>
            result(1 to name'length)
              := branch_name_table(to_integer(instr_branch_fn));
            disassemble_signed(signed(instr_disp), name'length + 2);            
          when op3_shift =>
            result(1 to name'length)
              := shift_name_table(to_integer(instr_shift_fn));
            result(name'length + 2 to name'length + 8) := "R , R ,";
            disassemble_reg(instr_rd, name'length + 3);
            disassemble_reg(instr_r1, name'length + 7);
            disassemble_unsigned(instr_sc, name'length + 10);
          when op3_use_op5 =>
            case instr_op5 is
              when op5_jump | op5_jsb =>
                result(1 to name'length)
                  := jump_name_table(
                       to_integer(instr_op5(0 downto 0)));
                disassemble_unsigned(instr_addr, name'length + 2);
              when op5_use_op6_0 | op5_use_op6_1 =>
                result(1 to name'length)
                  := misc_name_table(
                       to_integer(instr_op6(1 downto 0)));
              when others =>
                report "Program logic error in disassemble" severity failure;
            end case;
          when others =>
            report "Program logic error in disassemble" severity failure;
        end case;
    end case;
  end procedure disassemble;

  function load_program ( program_file_name : string ) return IMem_array is

    use std.textio.all;

    file program_file : text;
    variable L : line;
    variable line_number : natural := 0;
    variable addr : natural;
    variable instr_bv : bit_vector(instruction'range);
    variable instr : instruction;
    variable result : IMem_array := (others => (others => '0'));

  begin
    if program_file_name /= "" then
      file_open(program_file, program_file_name, read_mode);
      while not endfile(program_file) loop
        readline(program_file, L);
        line_number := line_number + 1;
        if L'length > 0 then
          read(L, addr);
          read(L, instr_bv);
          instr := instruction(instr_bv);
          if addr > IMem_size - 1 then
            report "Address out of range in file " & program_file_name
                    & " at line " & natural'image(line_number)
              severity error;
          else
            result(addr) := instr;
          end if;
        end if;
      end loop;
      file_close(program_file);
    end if;
    return result;
  end function load_program;

end package body pP_defs;

library ieee;
use ieee.numeric_bit.all;
use ieee.std_logic_1164.all;

use std.textio.all;

architecture bench of test is

  use work.pP_defs.all;

  signal clk : bit;                  -- master clock
  signal reset : bit;                -- synchronous reset
  signal port_addr : byte;
  signal port_data : std_logic_byte;
  signal port_write : bit;
  signal port_read : bit;
  signal port_ready : bit := '0';
  signal int_req : bit := '0';
  signal int_ack : bit;

  component pP is
    port ( clk : in bit;                  -- master clock
           reset : in bit;                -- synchronous reset
           port_addr : out byte;
           port_data : inout std_ulogic_byte;
           port_write : out bit;
           port_read : out bit;
           port_ready : in bit;
           int_req : in bit;
           int_ack : out bit );
  end component pP;


begin

  reset_gen : reset <= '1' after   5 ns,
                       '0' after  25 ns;

  clk_gen : process
  begin
    wait for 10 ns;
    loop
      clk <= '1', '0' after 5 ns;
      wait for 10 ns;
    end loop;
  end process clk_gen;

  int_gen : process
  begin
    for int_count in 1 to 10 loop
      for cycle_count in 1 to 25 loop
        wait until clk = '0';
      end loop;
      int_req <= '1';
      wait on clk until clk = '0' and int_ack = '1';
      int_req <= '0';
    end loop;
    wait;
  end process int_gen;

  io_control : process
    constant input_data : byte_array(0 to 63)  -- Hard-wired input stream
      := ( X"00" , X"01" , X"02" , X"03" , X"04" , X"05" , X"06" , X"07",
           X"08" , X"09" , X"0A" , X"0B" , X"0C" , X"0D" , X"0E" , X"0F",
           X"10" , X"11" , X"12" , X"13" , X"14" , X"15" , X"16" , X"17",
           X"18" , X"19" , X"1A" , X"1B" , X"1C" , X"1D" , X"1E" , X"1F",
           others => X"FF" );
    variable next_input : integer := 0;
    variable debug_line : line;
    constant show_actions : boolean := true;    
  begin
    loop
      wait on clk until clk = '0' and
        ( port_read = '1' or port_write = '1' or port_ready = '1' );
      if port_read = '1' then
        if show_actions then
          write(debug_line, string'("IO: port read; address = "));
          write(debug_line, to_integer(port_addr));
          write(debug_line, string'(", data = "));
          write(debug_line, bit_vector(input_data(next_input)) );
          writeline(output, debug_line);
        end if;
        if next_input <= 63 then
          port_data <= to_stdlogicvector(bit_vector(input_data(next_input)));
        else
          port_data <= to_stdlogicvector(bit_vector(input_data(0)));
        end if;
        next_input := next_input + 1;
        port_ready <= '1';
      elsif port_write = '1' then
        if show_actions then
          write(debug_line, string'("IO: port write; address = "));
          write(debug_line, to_integer(port_addr) );
          write(debug_line, string'(", data = "));
          write(debug_line, to_bitvector(port_data) );
          writeline(output, debug_line);
        end if;
        port_ready <= '1';
      else
        port_ready <= '0';
        port_data <= ( others => 'Z' );
      end if;
    end loop;
  end process io_control;
  
  dut : component pP
    port map ( clk => clk,
               reset => reset,
               port_addr => port_addr,
               std_logic_vector(port_data) => std_ulogic_vector(port_data),
               port_write => port_write,
               port_read => port_read,
               port_ready => port_ready,
               int_req => int_req,
               int_ack => int_ack );

end architecture bench;

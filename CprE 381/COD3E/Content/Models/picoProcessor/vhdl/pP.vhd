library ieee;  use ieee.std_logic_1164.all;

use work.pP_defs.all;

entity pP is

  generic ( program_file_name : string := "";
            debug : boolean := false );

  port ( clk : in bit;                  -- master clock
         reset : in bit;                -- synchronous reset
         port_addr : out byte;
         port_data : inout std_ulogic_byte;
         port_write : out bit;
         port_read : out bit;
         port_ready : in bit;
         int_req : in bit;
         int_ack : out bit );

end entity pP;

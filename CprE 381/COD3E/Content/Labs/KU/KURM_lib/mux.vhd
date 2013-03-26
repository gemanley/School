-------------------------------------------------------------------------------
-- MUX and DEMUX components
--
-- Author: Perry Alexander
-- Version: 1.0
-- Date: Thu Mar  8 00:09:00 EST 2001
-- Uses:
--
-- Objective: Define 2-1 and 4-1 MUX and 1-2 and 1-4 DEMUX components
--
-- Usage:
-- All models use unbounded bit vectors as inputs and outputs.  When multiple
--   control signals are needed, then are specified using a bit vector.  MUX
--   components operate over words while DEMUX components operate over bits
--   only.
-- All models use a generic parameter to specify timing delay.
--
-- Change Log:
--
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- Entity Definitions
-------------------------------------------------------------------------------

entity mux21 is
    
  generic (
    delay : time := 5 ns);             -- Delay time through the MUX
  
  port (
    i0, i1 : in  bit_vector;          -- Input bit vectors
    z      : out bit_vector;		  -- Control input
	c      : in bit);                 -- Output bit vector
  
end entity mux21;

entity mux41 is
  
  generic (
    delay : time := 5 ns);             -- Delay time through the MUX
  
  port (
    i0, i1, i2, i3 : in  bit_vector;              -- Input bit vectors
    z              : out bit_vector;		      -- Output bit vector
	c              : in  bit_vector(1 downto 0)); -- Control inputs
  
end entity mux41;

entity demux12 is
  
  generic (
    delay : time := 5 ns);             -- Delay time through the DEMUX
  
  port (
    e      : in  bit;                 -- Enable
    z0, z1 : out bit;                 -- Ouput bits
    c      : in  bit);                -- Control bit
  
end entity demux12;

entity demux14 is
  
  generic (
    delay : time := 5 ns);             -- Delay time through the DEMUX
  
  port (
    e              : in  bit;                     -- Enable input
    z0, z1, z2, z3 : out bit;					  -- Output bits
	c              : in  bit_vector(1 downto 0));  -- Control bites
  
end entity demux14;

-------------------------------------------------------------------------------
-- Architecture Definitions
-------------------------------------------------------------------------------

architecture beh of mux21 is
  
begin  -- beh
  
  -- purpose: Update outputs of the MUX.
  -- type   : combinational
  -- inputs : i0,i1
  -- outputs: z
  update: process
  begin  -- process update
    if c = '0'
    then z <= i0 after delay;
    else z <= i1 after delay;
    end if;
    wait on c,i0,i1;
  end process update;
  
end architecture beh;

architecture beh of mux41 is
  
begin  -- beh
  
  -- purpose: Update outputs of the MUX.
  -- type   : combinational
  -- inputs : c,i0,i1,i2,i3
  -- outputs: z
  update: process
  begin  -- process update
    case c is
      when b"00" => z <= i0 after delay;
      when b"01" => z <= i1 after delay;
      when b"10" => z <= i2 after delay;
      when b"11" => z <= i3 after delay;
      when others => null;
    end case;
    wait on c,i0,i1,i2,i3;
  end process update;
end architecture beh;

architecture beh of demux12 is
  
begin  -- beh
  
  -- purpose: Update the outputs of the demux
  -- type   : combinational
  -- inputs : c,e
  -- outputs: z0,z1
  update: process
  begin  -- process
    if c='0' then
      z0 <= e after delay;
	  z1 <= '0' after delay;
    else
	  z0 <= '0' after delay;
      z1 <= e after delay;
    end if;
    wait on c,e;            
  end process update;
  
end architecture beh;

architecture beh of demux14 is

begin  -- beh
  
  -- purpose: Update the outputs of the demux
  -- type   : combinational
  -- inputs : c,e
  -- outputs: z0,z1,z2,z3
  update: process
  begin  -- process update
	  
	case c is
      when b"00" => z0 <= e after delay; z1 <= '0' after delay;
	                z2 <= '0' after delay; z3 <= '0' after delay;
      when b"01" => z1 <= e after delay; z0 <= '0' after delay;
	                z2 <= '0' after delay; z3 <= '0' after delay;
      when b"10" => z2 <= e after delay; z1 <= '0' after delay;
	                z0 <= '0' after delay; z3 <= '0' after delay;
      when b"11" => z3 <= e after delay; z1 <= '0' after delay;
	                z2 <= '0' after delay; z0 <= '0' after delay;
      when others => null;
    end case;
    wait on c,e;
  end process update;
  
end architecture beh;

-------------------------------------------------------------------------------
-- Test Bench Definitions
-------------------------------------------------------------------------------

entity testmux is
end entity testmux;

architecture mixed of testmux is
  signal i0,i1,i2,i3,z2,z4 : bit_vector(3 downto 0);  -- test signals
  signal c : bit;                       -- 2-1 control input
  signal c2 : bit_vector(1 downto 0);   -- 4-1 control input
begin  -- mixed

  mux1: entity work.mux21(beh)
    port map (i0,i1,z2,c);
  mux2: entity work.mux41(beh)
    port map (i0,i1,i2,i3,z4,c2);
  test_bench: process
  begin  -- process test_bench
    i0 <= x"0"; i1 <= x"1"; i2 <= x"2"; i3 <= x"3";
    wait for 10ns;
    c <= '0'; c2 <= b"00";
    wait for 10ns;
    c <= '1'; c2 <= b"01";
    wait for 10ns;
    c2 <= b"10";
    wait for 10ns;
    c2 <= b"11";
    wait;
  end process test_bench;

end mixed;

entity testdemux is
end entity testdemux;

architecture mixed of testdemux is
  signal e,y0,y1,z0,z1,z2,z3: bit;      -- test signals
  signal c : bit;                       -- 2-1 control input
  signal c2 : bit_vector(1 downto 0);   -- 4-1 control input
begin  -- mixed

  mux1: entity work.demux12(beh)
    port map (e,y0,y1,c);
  mux2: entity work.demux14(beh)
    port map (e,z0,z1,z2,z3,c2);
  test_bench: process
  begin  -- process test_bench
    e <= '1'; c <= '0'; c2 <= b"00";
    wait for 10ns;
	c <= '1'; c2 <= b"01";
    wait for 10ns;
    c <= '0'; c2 <= b"10";
    wait for 10ns;
    c <= '1'; c2 <= b"11";
    wait for 10ns;
    e <= '0';
    wait;
  end process test_bench;

end mixed;

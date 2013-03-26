-------------------------------------------------------------------------------
-- Word / Bit Logic
--
-- Author: Perry Alexander
-- Version: 1.0
-- Date: Wed Mar  7 23:57:14 EST 2001
-- Uses:
--
-- Objective: Define a collection of components that perform a logical
--   operation on a word and a single bit.
--
-- Usage:
-- For all entities, the first port is an arbitrary length bit vector
--   and the second is a single bit.  The third port is the result of
--   applying the logical operation between each bit in the first argument with
--   the single bit in the second.
-- All entities accept arbitrary length words.
-- All entities have a generic parameter to control delay time.
--
-- Change Log:
--
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- Entity Definitions
-------------------------------------------------------------------------------

entity bit_or is
  
  generic (
    delay : time := ns);              -- Delay through the or
  
  port (
    x : in  bit_vector;               -- Work operand
    y : in  bit;                      -- Bit operand
    z : out bit_vector);              -- Result
  
end entity bit_or;

entity bit_and is
  
  generic (
    delay : time := ns);              -- Delay through the or
  
  port (
    x : in  bit_vector;               -- Work operand
    y : in  bit;                      -- Bit operand
    z : out bit_vector);              -- Result
  
end entity bit_and;

entity bit_xor is
  
  generic (
    delay : time := ns);              -- Delay through the or
  
  port (
    x : in  bit_vector;               -- Work operand
    y : in  bit;                      -- Bit operand
    z : out bit_vector);              -- Result
  
end entity bit_xor;

entity bit_xnor is
  
  generic (
    delay : time := ns);              -- Delay through the or
  
  port (
    x : in  bit_vector;               -- Work operand
    y : in  bit;                      -- Bit operand
    z : out bit_vector);              -- Result
  
end entity bit_xnor;

-------------------------------------------------------------------------------
-- Architecture Definitions
-------------------------------------------------------------------------------

architecture beh of bit_or is
  
begin  -- beh

  -- purpose: Calculate a bit or
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in x'range loop
      z(i) <= x(i) or y after delay;
    end loop;  -- i
    wait on x,y;
  end process update;

end architecture beh;

architecture beh of bit_and is

begin  -- beh
  
  -- purpose: Calculate a bit or
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in x'range loop
      z(i) <= x(i) and y after delay;
    end loop;  -- i
    wait on x,y;
  end process update;
  
end architecture beh;

architecture beh of bit_xor is
  
begin  -- beh
  
  -- purpose: Calculate a bit or
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in x'range loop
      z(i) <= x(i) xor y after delay;
    end loop;  -- i
    wait on x,y;
  end process update;
  
end architecture beh;

architecture beh of bit_xnor is
  
begin  -- beh
  
  -- purpose: Calculate a bit or
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in x'range loop
      z(i) <= x(i) xnor y after delay;
    end loop;  -- i
    wait on x,y;
  end process update;
  
end architecture beh;

-------------------------------------------------------------------------------
-- Test Bench Definitions
-------------------------------------------------------------------------------

entity test_logical_bit is 
end entity test_logical_bit;

architecture mixed of test_logical_bit is
  signal x,z_and,z_or,z_xor,z_xnor : bit_vector(3 downto 0);  -- test sigs
  signal y : bit;                       -- test signal
begin  -- mixed

  and1: entity work.bit_and(beh)
    port map (
      x => x,
      y => y,
      z => z_and);
  or1: entity work.bit_or(beh)
    port map (
      x => x,
      y => y,
      z => z_or);
  xor1: entity work.bit_xor(beh)
    port map (
      x => x,
      y => y,
      z => z_xor);
  xnor1: entity work.bit_xnor(beh)
    port map (
      x => x,
      y => y,
      z => z_xnor);
  -- purpose: test driver process
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  test_bench: process
  begin  -- process test_bench
    x <= x"0"; y <= '1'; wait for 10ns;
    x <= x"F"; y <= '1'; wait for 10ns;
    x <= x"F"; y <= '0'; wait for 10ns;
    x <= x"0"; y <= '0'; wait;
  end process test_bench;

end architecture mixed;


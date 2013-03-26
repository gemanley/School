-------------------------------------------------------------------------------
-- Word Logic
--
-- Author: Perry Alexander
-- Version: 1.0
-- Date: Thu Mar  8 00:17:15 EST 2001
-- Uses:
--
-- Objective: Provide a collection of word logic gates.
--
-- Usage:
-- For all entities, the first and second ports are operands and the third is
--   the result.
-- All models use a generic parameter to specify timing delay.
--
-- Change Log:
--
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- Entity Definitions
-------------------------------------------------------------------------------

entity word_or is
  
  generic (
    delay : time := 5 ns);               -- Delay through the or
  
  port (
    x, y : in  bit_vector;              -- Operands
    z    : out bit_vector);             -- Disjunction
  
end entity word_or;

entity word_and is
  
  generic (
    delay : time := 5 ns);             -- Delay through the and
  
  port (
    x, y : in  bit_vector;            -- Operands
    z    : out bit_vector);           -- Conjunction
  
end entity word_and;

entity word_xor is
  
  generic (
    delay : time := 5 ns);             -- Delay through the xor
  
  port (
    x, y : in  bit_vector;            -- Operands
    z    : out bit_vector);           -- xor
  
end entity word_xor;

entity word_xnor is
  
  generic (
    delay : time := 5 ns);             -- Delay through the xnor
  
  port (
    x, y : in  bit_vector;            -- Operands
    z    : out bit_vector);           -- xnor
  
end entity word_xnor;

-------------------------------------------------------------------------------
-- Architecture Definitions
-------------------------------------------------------------------------------

architecture beh of word_or is

begin  -- beh

  -- purpose: Calculate a word or
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in z'range loop
      z(i) <= x(i) or y(i) after delay;
    end loop;  -- i
    wait on x,y;
  end process update;

end architecture beh;

architecture beh of word_and is

begin  -- beh

  -- purpose: Calculate a word and
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in z'range loop
      z(i) <= x(i) and y(i) after delay;
    end loop;  -- i
    wait on x,y;
  end process update;

end architecture beh;

architecture beh of word_xor is

begin  -- beh

  -- purpose: Calculate a word xor
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in z'range loop
      z(i) <= x(i) xor y(i) after delay;
    end loop;  -- i
    wait on x,y;
  end process update;

end architecture beh;

architecture beh of word_xnor is

begin  -- beh

  -- purpose: Calculate a word xnor
  -- type   : combinational
  -- inputs : x,y
  -- outputs: z
  update: process
  begin  -- process update
    for i in z'range loop
      z(i) <= x(i) xnor y(i) after delay;
    end loop;  -- i
    wait on x,y;
  end process update;

end architecture beh;

entity test_logical is  
end test_logical;

-------------------------------------------------------------------------------
-- Test Bench Definitions
-------------------------------------------------------------------------------

architecture mixed of test_logical is
  signal x,y,z_and,z_or,z_xor,z_xnor : bit_vector(3 downto 0);  -- test sigs
begin  -- mixed

  and1: entity work.word_and(beh)
    port map (
      x => x,
      y => y,
      z => z_and);
  or1: entity work.word_or(beh)
    port map (
      x => x,
      y => y,
      z => z_or);
  xor1: entity work.word_xor(beh)
    port map (
      x => x,
      y => y,
      z => z_xor);
  xnor1: entity work.word_xnor(beh)
    port map (
      x => x,
      y => y,
      z => z_xnor);
  -- purpose: test driver process
  -- type   : combinational
  -- inputs : 
  -- outputs: 
  test_bench: process
  begin  -- process test_bench
    x <= x"0"; y <= x"F"; wait for 10ns;
    x <= x"F"; y <= x"0"; wait for 10ns;
    x <= x"0"; y <= x"F"; wait for 10ns;
    x <= x"0"; y <= x"0"; wait for 10ns;
    x <= x"F"; y <= x"F"; wait;
  end process test_bench;
end architecture mixed;



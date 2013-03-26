-------------------------------------------------------------------------------
-- Mathematical Operations
--
-- Author: Perry Alexander
-- Version: 1.1
-- Date: Thu Mar  8 00:03:56 EST 2001
-- Uses:
--
-- Objective: Define a collection of basic mathematical functions
--
-- Usage:
-- The only two components currently in the math package are an adder and a
--   comparator both are defined to work over arbitrary length bit vectors.
--   Note that the adder implements standard carry in and carry out signals as
--   well as an overflow indicator to be used when performing 2's compliment
--   operations.
-- The comparator accepts to arguments and performs a magnitude comparison
--   generating signals indicating x<y, x=y, and y<x respectively.
-- All models use a generic parameter to specify timing delay.
--
-- Change Log:
--   3/16/01 - wpa - Initialized the temporary less than and greater than
--     variables in the comparator to avoid remembering previous values.
--   3/16/01 - wpa - Made the calculation of the equal signal sane.  Moved
--     it out of the loop and used a general purpose comparison
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- Entity Definitions
-------------------------------------------------------------------------------

entity adder is

  generic (
    delay : time := 5 ns);             -- Delay time through the adder
  
  port (
    x, y     : in  bit_vector;        -- Operands
    z        : out bit_vector;        -- Sum
    overflow : out bit;               -- Overflow indicator
    Cin      : in  bit;               -- Carry in
    Cout     : out bit);              -- Carry out
  
end entity adder;

entity comparator is
  
  generic (
    delay : time := 5 ns);             -- Delay through the comparator
  
  port (
    x, y       : in  bit_vector;      -- Operands
    lt, eq, gt : out bit);            -- x < y, x = y, x > y
  
end entity comparator;

-------------------------------------------------------------------------------
-- Architecture Definitions
-------------------------------------------------------------------------------

architecture beh of adder is

begin  -- beh

  -- purpose: Perform a bit vector addition including carry in and
  --          generating overflow and carry
  -- type   : combinational
  -- inputs : x,y,Cin
  -- outputs: z,Cout,overflow
  update : process
    variable carry    : bit;            -- Carry bit
    variable tmp_over : bit;            -- Temporary overflow
  begin  -- process update
    carry := Cin; tmp_over := '0';
    for i in x'reverse_range loop
	  tmp_over := carry;
      z(i)  <= carry xor x(i) xor y(i) after delay;  -- Sum 
      carry := (carry and x(i)) or (carry and y(i)) or (x(i) and y(i));  -- Carry
    end loop;  -- if
    if tmp_over = carry then tmp_over := '0'; else tmp_over := '1'; end if;
    overflow <= tmp_over after delay;
    Cout     <= carry    after delay;
    wait on x, y, Cin;
  end process update;
  
end architecture beh;

architecture beh of comparator is
  
begin  -- beh

  -- purpose: Perform a magnitude comparison between two bit vectors
  -- type   : combinational
  -- inputs : x,y
  -- outputs: lt,eq,gt
  update: process
    variable tmp_eq,tmp_lt,tmp_gt : bit;  -- Temporary variables
  begin  -- process update
    tmp_lt := '0'; tmp_gt := '0';
    if x = y then tmp_eq := '1'; else tmp_eq := '0'; end if;
    for i in x'reverse_range loop
      if bit'pos(x(i)) < bit'pos(y(i))
      then tmp_lt := '1';
           tmp_gt := '0';
      end if;
      if bit'pos(x(i)) > bit'pos(y(i))
      then tmp_lt := '0';
           tmp_gt := '1';
      end if;
    end loop;  -- i
	eq <= tmp_eq after delay;
	lt <= tmp_lt after delay;
	gt <= tmp_gt after delay;
    wait on x,y;
  end process update;

end architecture beh;

-------------------------------------------------------------------------------
-- Test Bench Definitions
-------------------------------------------------------------------------------

entity test_math is
end entity test_math;

architecture mixed of test_math is
	signal x,y,z: bit_vector(3 downto 0);
	signal overflow,cin,cout,lt,eq,gt: bit;
begin
	add1: entity work.adder(beh)
		port map (x,y,z,overflow,cin,cout);
	comp1: entity work.comparator(beh)
		port map (x,y,lt,eq,gt);
	test_bench: process
	begin
		cin <= '0';
		x <= x"2"; y <= x"2";
		wait for 10ns;
		x <= x"1";
		wait for 10ns;
		x <= x"2";
		wait for 10ns;
		x <= x"3";
		wait for 10ns;
		x <= x"3";
		wait for 10ns;
		cin <= '1';
		wait for 10ns;
		cin <= '0';
		wait for 10ns;
		x <= x"F"; y <= x"3";
		wait for 10ns;
		x <= x"7"; y <= x"1";
		wait;
	end process test_bench;
end architecture mixed;

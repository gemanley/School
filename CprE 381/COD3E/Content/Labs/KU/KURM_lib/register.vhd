-------------------------------------------------------------------------------
-- Register Definitions
--
-- Author: Perry Alexander
-- Version: 1.2
-- Date: Thu Mar  8 00:12:44 EST 2001
-- Uses:
--
-- Objective: Define a register component.
--
-- Usage:
-- Registers are leading edge triggered devices with synchronous load and
--   asynchronous clear signals.  When load is asserted, a rising clock edge
--   causes the device to store its inputs.  If load is not asserted, inputs
--   are ignored on the rising edge.  Clear is an asynchronous, negative logic
--   signal.  When asserted, the resister value is set to zero.
-- The register is fixed at 16 bits in length.
-- All models use a generic parameter to specify timing delay.
--
-- Change Log:
--   3/12/01 - wpa - Corrected an error with the instantiation of register in 
--      the test bench architecture.
--   3/16/01 - wpa - Corrected an error that caused clear to be a leading edge
--      triggered signal rather than a level triggered signal.
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
-- Entity Definition
-------------------------------------------------------------------------------

entity reg is
  
  generic (
    delay : time := 5 ns);               -- Delay time
  
  port (
    i                : in  bit_vector;  -- Input value
    q                : out bit_vector;  -- Output value
    reset, load, clk : in  bit);    -- Clock, reset and load enable inputs.
                                    -- Reset is active low, load is
                                    -- active high. Rising edge triggered.
  
end entity reg;

-------------------------------------------------------------------------------
-- Architecture Definition
-------------------------------------------------------------------------------

architecture beh of reg is
  
begin  -- beh
  
  -- purpose: Define a basic register function with synchronous load and
  --          asynchronous, active low, reset
  -- type   : sequential
  -- inputs : clk, reset, i
  -- outputs: q
  update: process (clk, reset)
    variable store : bit_vector(15 downto 0);    -- Internal storage
  begin  -- process update
    if reset = '0'                 -- asynchronous reset (active low)
      then store := x"0000";
    elsif clk'event and clk = '1'  -- rising clock edge
      then if load='1' then store := i; end if;
    end if;
    q <= store after delay;
  end process update;

end architecture beh;

-------------------------------------------------------------------------------
-- Test Bench Definition
-------------------------------------------------------------------------------

entity reg_test_bench is
end entity reg_test_bench;

architecture beh of reg_test_bench is
	signal i,q: bit_vector(15 downto 0);
	signal reset,load,clk: bit;
begin
	reg1: entity work.reg(beh)
		port map (i,q,reset,load,clk);
	test_bench: process
	begin
		i <= x"1234"; reset <= '0'; wait for 1ns; reset <= '1';
		load <= '0'; wait for 17ns; 
		load <= '1'; wait for 10ns;
		load <= '0'; wait for 10ns;
	end process test_bench;
	clock: process
	begin
		clk <= '1'; wait for 5ns;
		clk <= '0'; wait for 5ns;
	end process clock;
end architecture beh;

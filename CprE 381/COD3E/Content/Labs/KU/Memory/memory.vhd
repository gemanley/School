---- Parameterized Behavioral Memory Module -----------------------------------
--
-- Author: Perry Alexander
-- Version: 1.0
-- Date: 2/18/01
-- Uses: mem_utils
--
-- Objective: Define a memory module with some primitive access functions.
-- 
-- Usage:
-- Memory will be represented as an array of bytes local to the memory
--   update process.  All reads and writes operate on a word of memory.
--   thus, when you access memory location x, you will either read or
--   write m(x) and m(x+1).  Memory is organized with the most significant
--   bit (MSB) of the word formed by m(x) and m(x+1) as the MSB of m(x).
--   the least significant bit (LSB) is the LSB of m(x+1).
-- Be careful to keep in mind that all words start at even addresses when
--   you access memory.  You can access odd addresses, but it's a very good
--   idea to only access even memory addresses.
-- See mem_utils for definitions of types word, byte and nybble.  Many of
--   the functions defined here could (really should) be moved to mem_utils.
--   they remain here to encourage you to write some of your own functions.
--   it's good practice...
-- If you use this package with Symphony or Synopsys simulators the time units
--   will generate a syntax error.  To fix this, put a space between the time
--   value and the unit specifier.  5ns would become 5 ns.
--
-- Change Log:
--   2/23/01 - wpa -- Fixed a small error in the use clause associated with the
--     mem_test entity. 
-------------------------------------------------------------------------------

use work.mem_utils.all,std.textio.all;
entity memory is
  -- Generic parameters:
  --   memSize - specifies how large the actual memory array should be
  --   memSpeed - specifies how long it takes the memory to read/write
  --   initfilename - specifies the name of the memory initialization file
  --     Note that if you provide no absolute path, the file will reside in
  --     the director with your VHDL workspace files.
  --   dumpfilename - specifies the name of the memory dump file.  Same default
  --     path conventions as initfile.
  -- Note that all generic parameters must be specified even if you do not
  --   initialize or dump the memory.  See the instantiation of the memory module
  --   in the test bench at the end of the file to see how to instantiate generics.
  -- The initfile is a simple text file that contains address / value pairs
  --   separated by a single space.  Both values are specified as 4 digit hex
  --   numbers.  To specify that the value ABCD should be stored at addres 1111,
  --   the line 1111 ABCD would be specified in the initialization file.
 
  generic(memSize:natural; memSpeed:time; initfilename:string; dumpfilename:string);

  -- Ports:
  --   datain - input data to be stored in the memory
  --   dataout - output data retrieved from memory
  --   address - address currently being accessed
  --   rd - when asserted, rd causes the memory to output the memory word at
  --     the location addressed by address
  --   wr - when asserted, wr causes the memory to store the memory work in
  --     datain in thelocation addressed by address
  --   init - when asserted causes the memory to load from the init file
  --     specified by the initfilename generic parameter
  --   dump - when asserted causes the memory to dump its contents in the dump
  --     file specified by the dumpfilename generic parameter.  Format is the
  --     same as the initialization file.
  port(datain:in word; dataout:out word; address:in word; rd,wr:in bit; init:in bit; dump:in bit);
end entity memory;

-- Define a behavioral architecture for the memory module
-- Preliminary testing - 2/18/01 -- wpa
architecture beh of memory is
begin
 update: process
           -- Memory is an array of bytes
           type memory is array(0 to memSize-1) of byte;
           variable m: memory;

           -- Convert a bit vector to a natural number.
           -- Preliminary testing - 2/14/01 -- wpa
           function bv2nat(b:bit_vector) return natural is
             variable tmp:natural := 0;
           begin
             for i in b'range loop
               tmp := tmp*2;
               if b(i)='1' then tmp:=tmp+1;
               end if;
             end loop;
             return tmp;
           end function bv2nat;

	   -- Convert a natural number to a word.
	   -- Preliminary testing - 2/18/01  -- wpa
           function nat2word(n:natural) return word is
             variable temp : word := x"0000";
             variable n1 : natural;
           begin
             n1 := n;
             for i in temp'reverse_range loop
               if n1 mod 2 = 1 then temp(i):='1'; else temp(i):='0'; end if;
               n1 := n1/2;
             end loop;
             return temp;
           end function nat2word;

           -- Convert a nybble to a 1 element hex string for debugging
           -- Preliminary testing - 2/14/01 -- wpa
           function nybble2hex(p:nybble) return string is
             variable n:natural :=bv2nat(p);
           begin
             case n is
               when 0|1|2|3|4|5|6|7|8|9 => return natural'image(n);
               when 10 => return "A";
               when 11 => return "B";
               when 12 => return "C";
               when 13 => return "D";
               when 14 => return "E";
               when 15 => return "F";
               when others => report "Error in nybble2hex" severity error;
             end case;
           end function nybble2hex;

           -- Convert a 1 element hex value to a bit vector for loading
           -- Preliminary testing - 2/17/01 -- wpa
           function hex2nybble(c:character) return nybble is
             variable natResult:natural := 0;
             variable nybbleResult:nybble := x"0";
           begin
             if '0' <= c and c <= '9' then
                natResult := character'pos(c)-character'pos('0');
             elsif 'A' <= c and c <= 'F' then
                natResult := character'pos(c)-character'pos('A')+10;
             elsif 'a' <= c and c <= 'f' then
                natResult := character'pos(c)-character'pos('a')+10;
             else report "Format error..." severity error;
             end if;
             case natResult is
                when 0 => nybbleResult := b"0000";
                when 1 => nybbleResult := b"0001";
                when 2 => nybbleResult := b"0010";
                when 3 => nybbleResult := b"0011";
                when 4 => nybbleResult := b"0100";
                when 5 => nybbleResult := b"0101";
                when 6 => nybbleResult := b"0110";
                when 7 => nybbleResult := b"0111";
                when 8 => nybbleResult := b"1000";
                when 9 => nybbleResult := b"1001";
                when 10 => nybbleResult := b"1010";
                when 11 => nybbleResult := b"1011";
                when 12 => nybbleResult := b"1100";
                when 13 => nybbleResult := b"1101";
                when 14 => nybbleResult := b"1110";
                when 15 => nybbleResult := b"1111";
                when others => report
                   "Conversion error in hex2nybble input "&character'image(c)
                   severity error;
             end case;
             return nybbleResult;
           end function hex2nybble;

           -- Convert a hex digit to a natural number
           -- Preliminary testing - 2/17/01 -- wpa
           function hex2nat(c:character) return natural is
             variable natResult: natural := 0;
           begin
             if '0' <= c and c <= '9' then
                natResult := character'pos(c)-character'pos('0');
             elsif 'A' <= c and c <= 'F' then
                natResult := character'pos(c)-character'pos('A')+10;
             elsif 'a' <= c and c <= 'f' then
                natResult := character'pos(c)-character'pos('a')+10;
             else report "Format error in hex2nat input "&character'image(c)
                         severity error;
             end if;
             return natResult;
           end function hex2nat;

           -- Convert a word to a 4 element hex string for debugging
           -- Preliminary testing - 2/14/01 -- wpa
           function word2hex(w:word) return string is
           begin
             return nybble2hex(w(15 downto 12))&nybble2hex(w(11 downto 8))&
                    nybble2hex(w(7 downto 4))&nybble2hex(w(3 downto 0));
           end function word2hex;

           -- Must decode the binary address into a natural
           -- to access the memory array.
           -- Preliminary testing - 2/14/01 -- wpa
           function addressDecode(w:word) return natural is
           begin
             return bv2nat(w);
           end function addressDecode;

           -- Dumps the memory
           -- Preliminary testing - 2/14/01 -- wpa
           procedure memDump is
             file dumpfile : text open write_mode is dumpfilename;
             variable dumpline : line;
             variable i: natural := 0;
           begin
             while i <= m'right loop
               write(dumpline,word2hex(nat2word(i)));
               write(dumpline,string'(" "));
               write(dumpline,word2hex(m(i)&m(i+1)));
               writeline(dumpfile,dumpline);
               i:=i+2;
             end loop;
           end procedure memDump;

           -- Initializes the memory
           -- Preliminary testing - 2/14/01 -- wpa
           procedure initMem is
             file initfile : text open read_mode is initfilename;
             variable l:line;
             variable c:character;
             variable add:natural;
             variable w:word;
           begin
             while not endfile(initfile) loop
               readline(initfile,l);
               for i in 3 downto 0 loop
                 read(l,c);
                 w(4*i+3 downto 4*i) := hex2nybble(c);
               end loop;
               add := bv2nat(w);
               read(l,c);
               for i in 3 downto 0 loop
                 read(l,c);
                 w(4*i+3 downto 4*i) := hex2nybble(c);
               end loop;
               m(add+1) := w(7 downto 0);
               m(add) := w(15 downto 8);
             end loop;
           end procedure initMem;

         -- Now start the update process...
         begin
           assert memSize rem 2 = 0 
             report
	       "Using an odd value for memSize can lead to problematic results"
             severity warning;
           -- Wait on an input to change
           wait on rd,wr,init,dump;

           -- If the write strobe is rising, then write the value on datain
           -- to memory location specified by address
           if wr'event and wr='1'
              then wait for memSpeed;
                   m(addressDecode(address)+1):=datain(7 downto 0);
                   m(addressDecode(address)):=datain(15 downto 8);
           end if;

           -- If the read strobe is rising, then output the word at the
           -- location addressed by address
           if rd'event and rd='1'
	      then dataout(7 downto 0) <= m(addressDecode(address)+1) after memSpeed;
                   dataout(15 downto 8) <= m(addressDecode(address)) after memSpeed;
           end if;

           -- If the init line is high, then load memory contents.  This signal
           -- is used primarily for testing.
           if init'event and init='1' then
               report "Initializing memory...";
               for i in m'range loop
                 m(i):=x"00";
               end loop;
               report "Reading memory initialization file...";
                 initMem;
               report "End memory initialization...";
           end if;

           -- If the dump line is high, then dump memory.  This signal is used
	   -- primarily for testing
           if dump'event and dump='1' then
               report "Dumping memory...";
               memDump;
               report "End memory dump...";
           end if;

 end process update;
end architecture beh;

-- Define a test harness for memory
-- Preliminary testing - 2/18/01 -- wpa
use work.mem_utils.all;
entity mem_test is
end entity mem_test;

architecture mixed of mem_test is
  signal address,datain,dataout: word;  -- Define singals to communicate
  signal rd,wr,init,dump: bit;  	--   between device and test bench
begin
  dut: entity work.memory(beh)  	-- Device under test is a memory
    generic map (memSize => 64,memSpeed => 10 ns,  -- Set generics
                 initfilename=>"initfile.txt",dumpfilename=>"dumpfile.txt")
    port map (datain,dataout,address,rd,wr,init,dump);  -- Set ports
  driver: process
  begin
    -- Initialize the memory
    init <= '1';
    wait for 5 ns;
    -- Make certain to reset the memory init line
    init <= '0';
    wait for 2 ns;
    
    -- Drive the address port with the address desired
    address <= x"0000";
    -- Drive the datain port with the data to store
    datain <= x"1234";
    wait for 2 ns;
    -- Strobe the memory to store the value
    wr <= '1';
    wait for 2 ns;
    -- Make certain to reset the strobe line
    wr <= '0';
    wait for 30 ns;

    -- Drive the address port with the addres desired
    address <= x"0002";
    -- Drive the datain port with the data to store
    datain <= x"5678";
    wait for 2 ns;
    -- Strobe the memory to store the value
    wr <= '1'; wait for 2 ns; wr <= '0';
    wait for 30 ns;

    -- Set the address line to look at a memory value
    address <= x"0000";
    rd <= '1'; wait for 2 ns; rd <= '0';
    wait for 30 ns;

    -- Set the address line to look at a memory value
    address <= x"0002";
    rd <= '1'; wait for 2 ns; rd <= '0';
    wait for 30 ns;

    -- Set the address line to look at a memory value
    address <= x"0004";
    rd <= '1'; wait for 2 ns; rd <= '0';
    wait for 30 ns;

    -- Set the address line to look at a memory value
    address <= x"0006";
    rd <= '1'; wait for 2 ns; rd <= '0';
    wait for 30 ns;

    -- Set the dump line to dump memory contents to a file
    dump <= '1';
    wait for 30 ns;
    -- Reset the dump line.
    dump <= '0';

    -- Just sit and wait forever...
    wait;
  end process driver;
end architecture mixed;


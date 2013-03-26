configuration test_bench_unpipelined_multi_cycle_rtl of test is
  for bench

    for dut : pP
      use entity work.pP(unpipelined_multi_cycle_rtl)
        generic map ( program_file_name => "test.ppe",
                      debug => true );      
    end for;

  end for;
end configuration test_bench_unpipelined_multi_cycle_rtl;

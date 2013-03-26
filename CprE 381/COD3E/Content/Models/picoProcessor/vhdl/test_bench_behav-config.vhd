configuration test_bench_behav of test is
  for bench

    for dut : pP
      use entity work.pP(behav)
        generic map ( program_file_name => "test.ppe",
                      debug => true );      
    end for;

  end for;
end configuration test_bench_behav;

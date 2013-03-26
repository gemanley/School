var BOOK_MENU_STYLE={
	'target'  : '_self',	// name of the frame links will be opened in
							// other possible values are: _blank, _parent, _search, _self and _top

	'icon_e'  : '../resources/icons/empty.gif', // empty image
	'icon_l'  : '../resources/icons/line.gif',  // vertical line
	
	'icon_48' : '../resources/icons/book_closed.gif', // root icon normal
	'icon_52' : '../resources/icons/book_closed.gif', // root icon selected
	'icon_56' : '../resources/icons/book_open.gif',   // root icon opened
	'icon_60' : '../resources/icons/book_open.gif',   // root icon opened selected
	
	'icon_16' : '../resources/icons/folder.gif',     // node icon normal
	'icon_20' : '../resources/icons/folder.gif',     // node icon selected
	'icon_24' : '../resources/icons/folderopen.gif', // node icon opened
	'icon_28' : '../resources/icons/folderopen.gif', // node icon selected opened

	'icon_0'  : '../resources/icons/book_page.gif', // leaf icon normal
	'icon_4'  : '../resources/icons/book_page.gif', // leaf icon selected
	'icon_8'  : '../resources/icons/book_page.gif', // leaf icon opened
	'icon_12' : '../resources/icons/book_page.gif', // leaf icon opened selected
	
	'icon_2'  : '../resources/icons/join_bottom.gif', // junction for leaf
	'icon_3'  : '../resources/icons/join.gif',        // junction for last leaf
	'icon_18' : '../resources/icons/plus_bottom.gif', // junction for closed node
	'icon_19' : '../resources/icons/plus.gif',        // junctioin for last closed node
	'icon_26' : '../resources/icons/minus_bottom.gif',// junction for opened node
	'icon_27' : '../resources/icons/minus.gif',       // junctioin for last opended node

	// styles - root
	'style_48':'menuRootNotLinked', // normal root caption style
	'style_52':'menuRootNotLinked', // selected root catption style
	'style_56':'menuRootNotLinked', // opened root catption style
	'style_60':'menuRootNotLinked', // selected opened root catption style
	'style_112':'menuRootNotLinked', // mouseovered normal root caption style
	'style_116':'menuRootNotLinked', // mouseovered selected root catption style
	'style_120':'menuRootNotLinked', // mouseovered opened root catption style
	'style_124':'menuRootNotLinked', // mouseovered selected opened root catption style
	
	// styles - node
	'style_16':'menuNodeNotLinked', // normal node caption style
	'style_20':'menuNodeNotLinked', // selected node catption style
	'style_24':'menuNodeNotLinked', // opened node catption style
	'style_28':'menuNodeNotLinked', // selected opened node catption style
	'style_80':'menuNodeNotLinked', // mouseovered normal node caption style
	'style_84':'menuNodeNotLinked', // mouseovered selected node catption style
	'style_88':'menuNodeNotLinked', // mouseovered opened node catption style
	'style_92':'menuNodeNotLinked', // mouseovered selected opened node catption style

	// styles - leaf
	'style_0':'menuLeafNotLinked', // normal leaf caption style
	'style_4':'menuLeafNotLinked', // selected leaf catption style
	'style_64':'menuLeafNotLinked', // mouseovered normal leaf caption style
	'style_68':'menuLeafNotLinked', // mouseovered selected leaf catption style

	'onItemOpen' : 'onItemOpenCloseHandler',
	'onItemClose' : 'onItemOpenCloseHandler'
}


function onItemOpenCloseHandler (o_item) {
	o_item.save();
	return true;
}

var BOOK_MENU_ITEMS=[
 [ 'Chapter 1&nbsp;&nbsp;Computer Abstractions and Technology',null,{},
    [ '1.7 Historical Perspective and Further Reading','CDSections/CD1.7.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '1.59 - 1.64: Integrated Circuit Cost (pages IMD 1.8-1 - 1.8-2)','InMoreDepth/IMD1-Integrated-Circuit-Cost.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ]
 ],
 [ 'Computers in the Real World: Information Technology for the 4 Billion without IT',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'Making the Web World-Wide','CDLibrary/Making%20the%20Web%20world-wide.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'The JHAI Foundation','http://www.jhai.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'Computers for the Third World','CDLibrary/Computers%20for%20the%20Third%20World.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Simputer','http://www.simputer.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Chapter 2&nbsp;&nbsp;Instructions: Language of the Computer',null,{},
    [ '2.12 How Compilers Work: An Introduction','CDSections/CD2.12.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '2.14 Implementing an Object Oriented Language','CDSections/CD2.14.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '2.19 Historical Perspective and Further Reading','CDSections/CD2.19.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '2.8 - 2.9: Bit Fields in C (pages IMD 2.20-1 - 2.20-2)','InMoreDepth/IMD2-Bit-Fields-in-C.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.10 - 2.12: Jump Tables (pages IMD 2.20-3 - 2.20-4)','InMoreDepth/IMD2-Jump-Tables.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.16 - 2.18: Tail Recursion (pages IMD 2.20-5 - 2.20-6)','InMoreDepth/IMD2-Tail-Recursion.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.45, 2.57 - 2.58: The IBM/Motorola versus MIPS in C (pages IMD 2.20-11 - 2.20-14)','InMoreDepth/IMD2-The-IBM-Motorola-PowerPC.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.52 - 2.53: Instruction Set Styles (pages IMD 2.20-7 - 2.20-9)','InMoreDepth/IMD2-Instruction-Set-Styles.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.54 - 2.55: The Single Instruction Computer (page IMD 2.20-10)','InMoreDepth/IMD2-The-Single-Instruction-Computer.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '2.59: Logical Instructions (page IMD 2.20-15)','InMoreDepth/IMD2-Logical-Instructions.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMP2.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '2.1: Instruction Formats (page FMP 2.20-1)',null,{} ],
       [ '2.5: MIPS Code and Logical Operations (page FMP 2.20-1)',null,{} ],
       [ '2.7: Logical Operations in MIPS (page FMP 2.20-1)',null,{} ],
       [ '2.14: Writing Assembly Code (page FMP 2.20-2)',null,{} ],
       [ '2.21 - 2.24: MIPS Coding and ASCII Strings (pages FMP 2.20-2 - 2.20-3)',null,{} ],
       [ '2.25: Comparing C/Java to MIPS (page FMP 2.20-3)',null,{} ],
       [ '2.26: Translating MIPS to C (page FMP 2.20-3)',null,{} ],
       [ '2.27 - 2.28: Understanding MIPS Code (pages FMP 2.20-4 - 2.20-5)',null,{} ],
       [ '2.33, 2.36: Translating from C to MIPS (page FMP 2.20-5)',null,{} ],
       [ '2.35: Reverse Translation from MIPS to C (page FMP 2.20-5)',null,{} ],
       [ '2.39: MIPS Pseudoinstructions (pages FMP 2.20-5 - 2.20-6)',null,{} ],
       [ '2.40 - 2.41: Linking MIPS Code (page FMP 2.20-6)',null,{} ],
       [ '2.43 - 2.44: Enhancing MIPS Addressing Modes (page FMP 2.20-6)',null,{} ]
    ],
    [ 'CD Library',null,{},
       [ 'Great Microprocessors of the Past and Present','http://www3.sk.sympatico.ca/jbayko/cpu.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Computers in the Real World: Saving our Environment with Data',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'Redwood\'s Drinking Water from Fog','CDLibrary/Redwoods%20Drinking%20Fog.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Redwood Research','CDLibrary/TED_redwood.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Tagging of Pacific Pelagics','http://www.toppcensus.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'TinyOS','http://www.tinyos.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Chapter 3&nbsp;&nbsp;Arithmetic For Computers',null,{},
    [ '3.10 Historical Perspective and Further Reading','CDSections/CD3.10.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '3.23: Booth\'s Algorithm (pages IMD 3.11-1 - 3.11-5)','InMoreDepth/IMD3-Booths-Algorithm.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '3.25 - 3.26: The Power PC\'s Multiply-Add Instruction (page IMD 3.11-6)','InMoreDepth/IMD3-The-PowerPCs-Multiply-Add-Instruction.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMP3.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '3.8: Number Representations (page FMP 3.11-1)',null,{} ],
       [ '3.11, 3.14 - 3.15: Writing MIPS Code to Perform Arithmetic (page FMP 3.11-1)',null,{} ],
       [ '3.16 - 3.17: Simulating MIPS Machines (pages FMP 3.11-1 - 3.11-2)',null,{} ],
       [ '3.18 - 3.19: Carry Lookahead Adders (page FMP 3.11-2)',null,{} ],
       [ '3.20 - 3.22: Relative Performance of Adders (pages FMP 3.11-2 - 3.11-3)',null,{} ],
       [ '3.24: Special MIPS Registers (page FMP 3.11-3)',null,{} ],
       [ '3.32 - 3.33: Floating Point Number Representations (page FMP 3.11-3)',null,{} ],
       [ '3.34: Writing MIPS Code to Perform FP Arithmetic (page FMP 3.11-3)',null,{} ],
       [ '3.47: Floating Point on Algorithms (page FMP 3.11-3)',null,{} ],
       [ '3.48: Floating Point Rounding Modes (pages FMP 3.11-3 - 3.11-4)',null,{} ],
       [ '3.49: Denormalized Numbers (page FMP 3.11-4)',null,{} ],
       [ '3.50 - 3.53: Evaluating Instruction Frequencies (pages FMP 3.11-4 - 3.11-5)',null,{} ],
       [ '3.54 - 3.55: Evaluating Performance (page FMP 3.11-5)',null,{} ]
    ]
 ],
 [ 'Computers in the Real World: Reconstructing the Ancient World',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'Center for Digital Shape, Archeology, Photogrammetry, and Entropy','http://www.lems.brown.edu/vision/extra/SHAPE',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'Exploring Chav&iacute;n de Hu&aacute;ntar','CDLibrary/Chavin/index.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ]
    ]
 ],
 [ 'Chapter 4&nbsp;&nbsp;Assessing and Understanding Performance',null,{},
    [ '4.7 Historical Perspective and Further Reading','CDSections/CD4.7.pdf',{'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '4.19 - 4.24: Amdahl\'s Law (pages IMD 4.8-1 - 4.8-2)','InMoreDepth/IMD4-Amdahls-Law.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.25 - 4.26: Choosing the Right Mean (pages IMD 4.8-3 - 4.8-5)','InMoreDepth/IMD4-Choosing-the-Right-Mean.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.27 - 4.28: Synthetic Benchmarks (pages IMD 4.8-6 - 4.8-7)','InMoreDepth/IMD4-Synthetic-Benchmarks.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.29: MIPS, MOPS, and other FLOPS (pages IMD 4.8-8 - 4.8-9)','InMoreDepth/IMD4-MIPS-MOPS-and-other-FLOPS.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.30 - 4.32: MFLOPS as a Performance Metric (pages IMD 4.8-10 - 4.8-11)','InMoreDepth/IMD4-MFLOPS-as-a-Performance-Metric.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.33: Embedded Benchmarks (pages IMD 4.8-12 - 4.8-13)','InMoreDepth/IMD4-Embedded-Benchmarks.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.34: Using Hardware-Independent Metrics (pages IMD 4.8-14 - 4.8-15)','InMoreDepth/IMD4-Using-Hardware-Independent-Metrics.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '4.49 - 4.50: The Difficulty with Kernel Benchmarks (pages IMD 4.8-16 - 4.8-17)','InMoreDepth/IMD4-The-Difficulty-with-Kernel-Benchmarks.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMP4.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '4.4 - 4.5: Cost-Effective Computing (page FMP 4.8-1)',null,{} ],
       [ '4.35 - 4.37: Analyzing a Processor with Floating Point Implemented in Hardware or Software (pages FMP 4.8-1 - 4.8-2)',null,{} ],
       [ '4.38 - 4.44: Analyzing Enhancements to a Processor (pages FMP 4.8-2 - 4.8-4)',null,{} ]
    ]
 ],
 [ 'Computers in the Real World: Moving People Faster and More Safely',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'TGVweb','http://mercurio.iet.unipi.it/tgv/tgvindex.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'System Safety in Computer-Controlled Automotive Systems','CDLibrary/System%20Safety.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ]
    ]
 ],
 [ 'Chapter 5&nbsp;&nbsp;The Processor: Data Path and Control',null,{},
    [ '5.7 Microprogramming: Simplifying Control Design','CDSections/CD5.7.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '5.8 An Introduction to Digital Design Using a Hardware Design Language','CDSections/CD5.8.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '5.12 Historical Perspective and Further Reading','CDSections/CD5.12.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'For More Practice','ForMorePractice/FMP5.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '5.4 - 5.6: Single Cycle Datapaths with Floating Point (page FMP 5.13-1)',null,{} ],
       [ '5.15 - 5.18: Effects of Faults in Control Multiplexors (pages FMP 5.13-1 - 5.13-2)',null,{} ],
       [ '5.19 - 5.23, 5.40 - 5.46, 5.52: Adding Instructions to the Datapath (pages FMP 5.13-2 - 5.13-5)',null,{} ],
       [ '5.24 - 5.25: Datapath Control Signals (page FMP 5.13-2)',null,{} ],
       [ '5.26: Modifying the Datapath and Control (pages FMP 5.13-2 - 5.13-3)',null,{} ],
       [ '5.47: Comparing Processor Performance (page FMP 5.13-4)',null,{} ],
       [ '5.48: Implementing Instructions in MIPS (pages FMP 5.13-4 - 5.13-5)',null,{} ],
       [ '5.54 - 5.56: Microcode (page FMP 5.13-5)',null,{} ]
    ],
    [ 'CD Library',null,{},
       [ 'History and Overview of Interrupts and Interrupt Systems','CDLibrary/interrupts.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ]
    ]
 ],
 [ 'Chapter 6&nbsp;&nbsp;Enhancing Performance with Pipelining',null,{},
    [ '6.7 Using a Hardware Description Language to Describe and Model a Pipeline','CDSections/CD6.7.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '6.13 Historical Perspective and Further Reading','CDSections/CD6.13.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'For More Practice','ForMorePractice/FMP6.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '6.5: Delayed Branches (page FMP 6.14-20)',null,{} ],
       [ '6.7 - 6.9: Understanding Pipelines by Drawing Them (pages FMP 6.14-1 - 6.14-5)',null,{} ],
       [ '6.10: Pipeline Registers (page FMP 6.14-20)',null,{} ],
       [ '6.11: Pipelining Floating Point (pages FMP 6.14-20 - 6.14-21)',null,{} ],
       [ '6.15: Labeling Pipeline Diagrams with Control (pages FMP 6.14-6 - 6.14-12)',null,{} ],
       [ '6.16: Illustrating Diagrams with Forwarding (pages FMP 6.14-13 - 6.14-16)',null,{} ],
       [ '6.20: Forwarding in Memory (page FMP 6.14-21)',null,{} ],
       [ '6.24: Illustrating Diagrams with Forwarding and Stalls (pages FMP 6.14-13, 6.14-16 - 6.14-20)',null,{} ],
       [ '6.25: Impact on Forwarding of Moving It to ID Stage (page FMP 6.14-21)',null,{} ],
       [ '6.26: Impact of Memory Addressing Mode on Pipeline (page FMP 6.14-21)',null,{} ],
       [ '6.27: Impact of Arithmetic Operations with Memory Operands on Pipeline (page FMP 6.14-21)',null,{} ],
       [ '6.28: Forwarding Unit Hardware Design (page FMP 6.14-21)',null,{} ],
       [ '6.31: Coding with Conditional Moves (pages FMP 6.14-21 - 6.14-22)',null,{} ],
       [ '6.32: Performance Advantage of Conditional Move (page FMP 6.14-22)',null,{} ]
    ] 
 ],
 [ 'Computers in the Real World: Mass Communication without Gatekeepers',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'OhmyNews (in Korean)','http://ohmynews.com/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'OhmyNews (English version)','http://english.ohmynews.com/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'Google News','http://www.google.com/news',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Chapter 7&nbsp;&nbsp;Large and Fast: Exploiting Memory Hierarchy',null,{},
    [ '7.9 Historical Perspective and Further Reading','CDSections/CD7.9.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '7.17 - 7.19:  Average Memory Access Time (page IMD 7.10-1)','InMoreDepth/IMD7-Average-Memory-Access-Time.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMP7.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '7.6 - 7.8: Locality (page FMP 7.10-1)',null,{} ],
       [ '7.15: Cache Performance (page FMP 7.10-1)',null,{} ],
       [ '7.23 - 7.24, 7.30 - 7.31, 7.36: Cache Configurations (page FMP 7.10-1 - 7.10-2)',null,{} ],
       [ '7.25 - 2.27: Cache Operation (pages FMP 7.10-1 - 7.10-2)',null,{} ],
       [ '7.37: Memory Hierarchy Interactions (page FMP 7.10-2)',null,{} ],
       [ '7.43 - 7.44: Hierarchical Page Tables (pages FMP 7.10-2 - 7.10-3)',null,{} ]
    ],
    [ 'CD Library',null,{},
       [ 'The Influence of Caches on the Performance of Heaps','CDLibrary/ACM-JEA-Vol1Nbr4.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ]
    ]
 ],
 [ 'Computers in the Real World: Saving the World\'s Art Treasures',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'Conserving Paintings','http://www.artmuseums.harvard.edu/Renaissance/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'Sistine Chapel','CDLibrary/Sistine%20Chapel.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Digital Michelangelo Project','http://graphics.stanford.edu/projects/mich/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Chapter 8&nbsp;&nbsp;Storage, Networks, and Other Peripherals',null,{},
    [ '8.3 Networks','CDSections/CD8.3.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ '8.11 Historical Perspective and Further Reading','CDSections/CD8.11.pdf',
      {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
    [ 'In More Depth',null,{},
       [ '8.26: Ethernet Simulation (pages IMD 8.12-1)','InMoreDepth/IMD8-Ethernet-Simulation.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ '8.31 - 8.32: Disk Arrays (page IMD 8.12-2)','InMoreDepth/IMD8-Disk-Arrays.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMP8.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ '8.25: Writing Code to Benchmark I/O Performance (page FMP 8.12-1)',null,{} ],
       [ '8.35 - 8.36: Finding I/O Bandwidth Bottlenecks (page FMP 8.12-1)',null,{} ],
       [ '8.37: I/O System Operation (pages FMP 8.12-1 - 8.12-2)',null,{} ],
       [ '8.41: Using SPIM to Explore I/O (page FMP 8.12-2)',null,{} ],
       [ '8.42 - 8.43: Writing Code to Perform I/O (pages FMP 8.12-2 - 8.12-4)',null,{} ]
    ],
    [ 'CD Library',null,{},
       [ 'OSI Model Layers','CDLibrary/OSI%20Model%20Layers.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ]
    ]
 ],
 [ 'Computers in the Real World: Saving Lives Through Better Diagnosis',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
    [ 'CD Library',null,{},
       [ 'MRI Scans from the Visible Human Project','CDLibrary/Visible%20Human%20Project%20-%20MRI%20Scans.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Basic Principles of MRI','CDLibrary/Basic%20Principles%20of%20MRI.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'Using MRI for Real-time Cardiac Imaging and Angiography (imaging blood vessels)','http://www-mrsrl.stanford.edu',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ],
       [ 'Functional MRI','CDLibrary/About%20Functional%20MRI.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/cdrom24.gif','i4':'../resources/icons/cdrom24.gif','i8':'../resources/icons/cdrom24.gif','i12':'../resources/icons/cdrom24.gif','i64':'../resources/icons/cdrom24.gif','i68':'../resources/icons/cdrom24.gif','i72':'../resources/icons/cdrom24.gif','i76':'../resources/icons/cdrom24.gif'}
       ],
       [ 'High Performance Computing for Complex Images (including MRI and CT imaging)','http://www.sci.utah.edu/cgi-bin/sci_gallery.pl',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../resources/icons/web24.gif','i4':'../resources/icons/web24.gif','i8':'../resources/icons/web24.gif','i12':'../resources/icons/web24.gif','i64':'../resources/icons/web24.gif','i68':'../resources/icons/web24.gif','i72':'../resources/icons/web24.gif','i76':'../resources/icons/web24.gif'}
       ]
    ]
 ],
 [ 'Chapter 9&nbsp;&nbsp;Multiprocessors and Clusters','CDSections/09HP.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover',
    'i0':'../resources/icons/blank24.gif','i4':'../resources/icons/blank24.gif','i8':'../resources/icons/blank24.gif','i12':'../resources/icons/blank24.gif','i64':'../resources/icons/blank24.gif','i68':'../resources/icons/blank24.gif','i72':'../resources/icons/blank24.gif','i76':'../resources/icons/blank24.gif'}
 ],
 [ 'Appendix A&nbsp;&nbsp;Assemblers, Linkers, and the SPIM Simulator','CDSections/HP_AppA.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover',
    'i0':'../resources/icons/blank24.gif','i4':'../resources/icons/blank24.gif','i8':'../resources/icons/blank24.gif','i12':'../resources/icons/blank24.gif','i64':'../resources/icons/blank24.gif','i68':'../resources/icons/blank24.gif','i72':'../resources/icons/blank24.gif','i76':'../resources/icons/blank24.gif'}
 ],
 [ 'Appendix B&nbsp;&nbsp;The Basics of Logic Design','CDSections/HP_AppB.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ 'In More Depth',null,{},
       [ 'B.1 - B.2, B.15 - B.16: DeMorgam\'s Theorems (page IMD B.14-1)','InMoreDepth/IMDB-DeMorgans-Theorems.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}],
       [ 'B.31 - B.32: Carry Save Adders (page IMD B.14-2)','InMoreDepth/IMDB-Carry-Save-Adders.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover'}]
    ],
    [ 'For More Practice','ForMorePractice/FMPB.pdf',
      {'s0':'menuNodeLinked','s4':'menuNodeLinked','s8':'menuNodeLinked','s12':'menuNodeLinked','s64':'menuNodeLinkedRollover','s68':'menuNodeLinkedRollover','s72':'menuNodeLinkedRollover','s76':'menuNodeLinkedRollover'},
       [ 'B.3 - B.4: Truth Tables (page FMP B.14-1)',null,{} ],
       [ 'B.5 - B.6: Building Logic Gates (page FMP B.14-1)',null,{} ],
       [ 'B.17: Multiplexors (page FMP B.14-1)',null,{} ],
       [ 'B.35 - B.36: Flip-Flops and Latches (page FMP B.14-1)',null,{} ],
       [ 'B.37 - B.38: Finite State Machines (pages FMP B.14-1 - B.14-2)',null,{} ],
       [ 'B.39 - B.40: Constructing a Counter (page FMP B.14-2)',null,{} ],
       [ 'B.41 - B.44: Timing Methodologies (pages FMP B.14-2 - B.14-3)',null,{} ]
    ]
 ],
 [ 'Appendix C&nbsp;&nbsp;Mapping Control to Hardware','CDSections/HP_AppC.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover',
    'i0':'../resources/icons/blank24.gif','i4':'../resources/icons/blank24.gif','i8':'../resources/icons/blank24.gif','i12':'../resources/icons/blank24.gif','i64':'../resources/icons/blank24.gif','i68':'../resources/icons/blank24.gif','i72':'../resources/icons/blank24.gif','i76':'../resources/icons/blank24.gif'}
 ],
 [ 'Appendix D&nbsp;&nbsp;A Survey of RISC Architectures for Desktop, Server, and Embedded Computers','CDSections/HP_AppD.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover',
    'i0':'../resources/icons/blank24.gif','i4':'../resources/icons/blank24.gif','i8':'../resources/icons/blank24.gif','i12':'../resources/icons/blank24.gif','i64':'../resources/icons/blank24.gif','i68':'../resources/icons/blank24.gif','i72':'../resources/icons/blank24.gif','i76':'../resources/icons/blank24.gif'}
 ]
];

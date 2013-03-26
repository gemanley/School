var FMP_MENU_STYLE={
	'target'  : '_self',	// name of the frame links will be opened in
							// other possible values are: _blank, _parent, _search, _self and _top

	'icon_e'  : '../../resources/icons/empty.gif', // empty image
	'icon_l'  : '../../resources/icons/line.gif',  // vertical line
	
	'icon_48' : '../../resources/icons/folder.gif', // root icon normal
	'icon_52' : '../../resources/icons/folder.gif', // root icon selected
	'icon_56' : '../../resources/icons/folderopen.gif',   // root icon opened
	'icon_60' : '../../resources/icons/folderopen.gif',   // root icon opened selected
	
	'icon_16' : '../../resources/icons/folder.gif',     // node icon normal
	'icon_20' : '../../resources/icons/folder.gif',     // node icon selected
	'icon_24' : '../../resources/icons/folderopen.gif', // node icon opened
	'icon_28' : '../../resources/icons/folderopen.gif', // node icon selected opened

	'icon_0'  : '../../resources/icons/book_page.gif', // leaf icon normal
	'icon_4'  : '../../resources/icons/book_page.gif', // leaf icon selected
	'icon_8'  : '../../resources/icons/book_page.gif', // leaf icon opened
	'icon_12' : '../../resources/icons/book_page.gif', // leaf icon opened selected
	
	'icon_2'  : '../../resources/icons/join_bottom.gif', // junction for leaf
	'icon_3'  : '../../resources/icons/join.gif',        // junction for last leaf
	'icon_18' : '../../resources/icons/plus_bottom.gif', // junction for closed node
	'icon_19' : '../../resources/icons/plus.gif',        // junctioin for last closed node
	'icon_26' : '../../resources/icons/minus_bottom.gif',// junction for opened node
	'icon_27' : '../../resources/icons/minus.gif',       // junctioin for last opended node

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
};


function onItemOpenCloseHandler (o_item) {
	o_item.save();
	return true;
}


var FMP_MENU_ITEMS=[
 [ 'Chapter 2  Instructions: Language of the Computer','FMP2.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
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
 [ 'Chapter 3  Arithmetic for Computers','FMP3.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
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
 ],
 [ 'Chapter 4  Assessing and Understanding Performance','FMP4.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ '4.4 - 4.5: Cost-Effective Computing (page FMP 4.8-1)',null,{} ],
    [ '4.35 - 4.37: Analyzing a Processor with Floating Point Implemented in Hardware or Software (pages FMP 4.8-1 - 4.8-2)',null,{} ],
    [ '4.38 - 4.44: Analyzing Enhancements to a Processor (pages FMP 4.8-2 - 4.8-4)',null,{} ]
 ],
 [ 'Chapter 5  The Processor: Datapath and Control','FMP5.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ '5.4 - 5.6: Single Cycle Datapaths with Floating Point (page FMP 5.13-1)',null,{} ],
    [ '5.15 - 5.18: Effects of Faults in Control Multiplexors (pages FMP 5.13-1 - 5.13-2)',null,{} ],
    [ '5.19 - 5.23, 5.40 - 5.46, 5.52: Adding Instructions to the Datapath (pages FMP 5.13-2 - 5.13-5)',null,{} ],
    [ '5.24 - 5.25: Datapath Control Signals (page FMP 5.13-2)',null,{} ],
    [ '5.26: Modifying the Datapath and Control (pages FMP 5.13-2 - 5.13-3)',null,{} ],
    [ '5.47: Comparing Processor Performance (page FMP 5.13-4)',null,{} ],
    [ '5.48: Implementing Instructions in MIPS (pages FMP 5.13-4 - 5.15-5)',null,{} ],
    [ '5.54 - 5.56: Microcode (page FMP 5.13-5)',null,{} ]
 ],
 [ 'Chapter 6  Enhancing Performance with Pipelining','FMP6.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
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
 ],
 [ 'Chapter 7  Large and Fast: Exploiting Memory Hierarchy','FMP7.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ '7.6 - 7.8: Locality (page FMP 7.10-1)',null,{} ],
    [ '7.15: Cache Performance (page FMP 7.10-1)',null,{} ],
    [ '7.23 - 7.24, 7.30 - 7.31, 7.36: Cache Configurations (page FMP 7.10-1 - 7.10-2)',null,{} ],
    [ '7.25 - 2.27: Cache Operation (pages FMP 7.10-1 - 7.10-2)',null,{} ],
    [ '7.37: Memory Hierarchy Interactions (page FMP 7.10-2)',null,{} ],
    [ '7.43 - 7.44: Hierarchical Page Tables (pages FMP 7.10-2 - 7.10-3)',null,{} ]
 ],
 [ 'Chapter 8  Storage, Networks, and Other Peripherals','FMP8.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ '8.25: Writing Code to Benchmark I/O Performance (page FMP 8.12-1)',null,{} ],
    [ '8.35 - 8.36: Finding I/O Bandwidth Bottlenecks (page FMP 8.12-1)',null,{} ],
    [ '8.37: I/O System Operation (pages FMP 8.12-1 - 8.12-2)',null,{} ],
    [ '8.41: Using SPIM to Explore I/O (page FMP 8.12-2)',null,{} ],
    [ '8.42 - 8.43: Writing Code to Perform I/O (pages FMP 8.12-2 - 8.12-4)',null,{} ]
 ],
 [ 'Appendix B  The Basics of Logic Design','FMPB.pdf',
   {'s0':'menuRootLinked','s4':'menuRootLinked','s8':'menuRootLinked','s12':'menuRootLinked','s64':'menuRootLinkedRollover','s68':'menuRootLinkedRollover','s72':'menuRootLinkedRollover','s76':'menuRootLinkedRollover'},
    [ 'B.3 - B.4: Truth Tables (page FMP B.14-1)',null,{} ],
    [ 'B.5 - B.6: Building Logic Gates (page FMP B.14-1)',null,{} ],
    [ 'B.17: Multiplexors (page FMP B.14-1)',null,{} ],
    [ 'B.35 - B.36: Flip-Flops and Latches (page FMP B.14-1)',null,{} ],
    [ 'B.37 - B.38: Finite State Machines (pages FMP B.14-1 - B.14-2)',null,{} ],
    [ 'B.39 - B.40: Constructing a Counter (page FMP B.14-2)',null,{} ],
    [ 'B.41 - B.44: Timing Methodologies (pages FMP B.14-2 - B.14-3)',null,{} ]
 ]
];

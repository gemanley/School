var LIB_MENU_STYLE={
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


var LIB_MENU_ITEMS=[
 [ 'Computers in the Real World: Information Technology for the 4 Billion without IT',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'Making the Web World-Wide','Making%20the%20Web%20world-wide.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'The JHAI Foundation','http://www.jhai.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'Computers for the Third World','Computers%20for%20the%20Third%20World.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Simputer','http://www.simputer.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ],
 [ 'Chapter 2&nbsp;&nbsp;Instructions: Language of the Computer',null,{},
       [ 'Great Microprocessors of the Past and Present','http://www3.sk.sympatico.ca/jbayko/cpu.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Saving our Environment with Data',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'Redwood\'s Drinking Water from Fog','Redwoods%20Drinking%20Fog.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Redwood Research','TED_redwood.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Tagging of Pacific Pelagics','http://www.toppcensus.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'TinyOS','http://www.tinyos.org',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Reconstructing the Ancient World',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'Center for Digital Shape, Archeology, Photogrammetry, and Entropy','http://www.lems.brown.edu/vision/extra/SHAPE',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'Exploring Chav&iacute;n de Hu&aacute;ntar','Chavin/index.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Moving People Faster and More Safely',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'TGVweb','http://mercurio.iet.unipi.it/tgv/tgvindex.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'System Safety in Computer-Controlled Automotive Systems','System%20Safety.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ]
 ],
 [ 'Chapter 5&nbsp;&nbsp;The Processor: Data Path and Control',null,{},
       [ 'History and Overview of Interrupts and Interrupt Systems','interrupts.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Mass Communication without Gatekeepers',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'OhmyNews (in Korean)','http://ohmynews.com/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'OhmyNews (English version)','http://english.ohmynews.com/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'Google News','http://www.google.com/news',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ],
 [ 'Chapter 7&nbsp;&nbsp;Large and Fast: Exploiting Memory Hierarchy',null,{},
       [ 'The Influence of Caches on the Performance of Heaps','ACM-JEA-Vol1Nbr4.pdf',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Saving the World\'s Art Treasures',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'Conserving Paintings','http://www.artmuseums.harvard.edu/Renaissance/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'Sistine Chapel','Sistine%20Chapel.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Digital Michelangelo Project','http://graphics.stanford.edu/projects/mich/',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ],
 [ 'Chapter 8&nbsp;&nbsp;Storage, Networks, and Other Peripherals',null,{},
       [ 'OSI Model Layers','OSI%20Model%20Layers.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ]
 ],
 [ 'Computers in the Real World: Saving Lives Through Better Diagnosis',null,
   {'s0':'menuNodeUnlinked','s4':'menuNodeUnlinked','s8':'menuNodeUnlinked','s12':'menuNodeUnlinked','s64':'menuNodeUnlinkedRollover','s68':'menuNodeUnlinkedRollover','s72':'menuNodeUnlinkedRollover','s76':'menuNodeUnlinkedRollover'},
       [ 'MRI Scans from the Visible Human Project','Visible%20Human%20Project%20-%20MRI%20Scans.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Basic Principles of MRI','Basic%20Principles%20of%20MRI.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'Using MRI for Real-time Cardiac Imaging and Angiography (imaging blood vessels)','http://www-mrsrl.stanford.edu',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ],
       [ 'Functional MRI','About%20Functional%20MRI.html',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/cdrom24.gif','i4':'../../resources/icons/cdrom24.gif','i8':'../../resources/icons/cdrom24.gif','i12':'../../resources/icons/cdrom24.gif','i64':'../../resources/icons/cdrom24.gif','i68':'../../resources/icons/cdrom24.gif','i72':'../../resources/icons/cdrom24.gif','i76':'../../resources/icons/cdrom24.gif'}
       ],
       [ 'High Performance Computing for Complex Images (including MRI and CT imaging)','http://www.sci.utah.edu/cgi-bin/sci_gallery.pl',
         {'s0':'menuLeafLinked','s4':'menuLeafLinked','s8':'menuLeafLinked','s12':'menuLeafLinked','s64':'menuLeafLinkedRollover','s68':'menuLeafLinkedRollover','s72':'menuLeafLinkedRollover','s76':'menuLeafLinkedRollover',
          'i0':'../../resources/icons/web24.gif','i4':'../../resources/icons/web24.gif','i8':'../../resources/icons/web24.gif','i12':'../../resources/icons/web24.gif','i64':'../../resources/icons/web24.gif','i68':'../../resources/icons/web24.gif','i72':'../../resources/icons/web24.gif','i76':'../../resources/icons/web24.gif'}
       ]
 ]
];

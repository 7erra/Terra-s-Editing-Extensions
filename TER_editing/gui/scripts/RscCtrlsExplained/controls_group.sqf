[
//--- Examples
[
	[ // Example 1
		"RscControlsGroup",// Class
		[nil,4], // Width, height
		{ // Commands to execute upon creation
			_subCtrl = (findDisplay 73140) ctrlCreate ["RscStructuredText",-1,_this];
			_subCtrl ctrlSetBackgroundColor [0,1,0,1];
			_subCtrl ctrlSetPosition [0,0,1,1];
			_subCtrl ctrlCommit 0;
			_subCtrl ctrlSetText "With scrollbars";
		}
	],
	[ // Example 2
		"RscControlsGroupNoHScrollbars",// Class
		[nil,4], // Width, height
		{ // Commands to execute upon creation
			_subCtrl = (findDisplay 73140) ctrlCreate ["RscStructuredText",-1,_this];
			_subCtrl ctrlSetBackgroundColor [0,1,0,1];
			_subCtrl ctrlSetPosition [0,0,1,1];
			_subCtrl ctrlCommit 0;
			_subCtrl ctrlSetText "No horizontal scrollbars";
		}
	],
	[ // Example 3
		"RscControlsGroupNoVScrollbars",// Class
		[nil,4], // Width, height
		{ // Commands to execute upon creation
			_subCtrl = (findDisplay 73140) ctrlCreate ["RscStructuredText",-1,_this];
			_subCtrl ctrlSetBackgroundColor [0,1,0,1];
			_subCtrl ctrlSetPosition [0,0,1,1];
			_subCtrl ctrlCommit 0;
			_subCtrl ctrlSetText "No vertical scrollbars";
		}
	],
	[ // Example 4
		"RscControlsGroupNoScrollbars",// Class
		[nil,4], // Width, height
		{ // Commands to execute upon creation
			_subCtrl = (findDisplay 73140) ctrlCreate ["RscStructuredText",-1,_this];
			_subCtrl ctrlSetBackgroundColor [0,1,0,1];
			_subCtrl ctrlSetPosition [0,0,1,1];
			_subCtrl ctrlCommit 0;
			_subCtrl ctrlSetText "No scrollbars but still scrollable";
		}
	]
],
//--- Description
"The controls group organizes a set of controls to make them stick together. All the examples and text here are organized inside of a controls group. It is not visible without controls inside of it. The green color in the examples comes from a RscStructuredText control insde of the controls group.",
//--- EH
[],
//--- Commands
[],
//--- Common base classes
["<t color='#FF5555'>RscControlsGroup</t>","RscControlsGroupNoScrollbars","RscControlsGroupNoHScrollbars","RscControlsGroupNoVScrollbars","ctrlControlsGroup"]
]
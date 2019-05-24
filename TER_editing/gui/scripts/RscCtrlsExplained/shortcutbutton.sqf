[
//--- Examples
[
	[ // Example 1
		"RscShortcutButton",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Click me!";
		}
	],
	[ // Example 6
		"RscButtonMenu",// Class
		[nil,1], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetStructuredText parseText "Click me! - <t color='#00FF00'>Formatted</t>";
		}
	],
	[ // Example 7
		"RscButtonMenuSteam",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Click me!";
		}
	],
	[ // Example 8
		"ctrlButton",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Click me!";
		}
	]
],
//--- Description
"A highly customizable button. It is the modern version of CT_BUTTON. It supports structured text (example 2) and can display images (example 3). The first example is an old version. The second example is the default button for ArmA3. As already mentioned in CT_BUTTON the buttonAction and buttonSetAction commands are old commands and were replaced by eventhandlers.",
//--- EH
["ButtonClick","ButtonDblClick","ButtonDown","ButtonUp"],
//--- Commands
["ctrlSetText","ctrlText","ctrlSetStructuredText","buttonAction","buttonSetAction"],
//--- Common base classes
["<t color='#FF5555'>RscButtonMenu</t>","RscButtonMenuOK","RscButtonMenuCancel","RscButtonMenuSteam","ctrlShortcutButton","ctrlShortcutButtonOK","ctrlShortcutButtonCancel","ctrlShortcutButtonSteam"]
]
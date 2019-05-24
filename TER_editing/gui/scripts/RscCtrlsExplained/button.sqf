[
//--- Examples
[
	[ // Example 1
		"RscButton",// Title
		[nil,1], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Click me!";
		}
	]
],
//--- Description
"The simplest form of a button. It is an older version and shouldn't be used anymore to keep the visual appearance of the game consistent. Use RscButtonMenu (<t color='#4444ff'>CT_SHORTCUTBUTTON</t>) instead. The commands buttonAction and buttonSetAction only support the sqs format and are therefore neglectable as you can get the same or even better results with the ""ButtonClick"" eventhandler.",
//--- EH
["ButtonClick","ButtonDblClick","ButtonDown","ButtonUp"],
//--- Commands
["buttonAction","buttonSetAction"],
//--- Common base classes
["<t color='#FF5555'>RscButton</t>","RscButtonTextOnly"]
]
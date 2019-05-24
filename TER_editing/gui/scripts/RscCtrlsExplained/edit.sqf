[
//--- Examples
[
	[ // Example 1
		"RscEdit",// Title
		[nil,1], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Edit me";
		}
	]
	/*,
	[ // Example 2
		"ctrlEdit",// Title
		[nil,1], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "Edit me";
		}
	]*/
],
//--- Description
"The CT_EDIT is the go to option if you want the user to input a number or string. The changed text can be returned with the ctrlText command and also be set with setText. The onChar event doesn't fire for key presses that don't return a character. In this case you can use onKeyDown/Up.",
//--- EH
["Char","IMEChar","IMEComposition","ButtonUp"],
//--- Commands
["ctrlText", "ctrlSetText","ctrlTextHeight","ctrlTextWidth"],
//--- Common base classes
["<t color='#FF5555'>RscEdit</t>","RscEditMulti","ctrlEdit","ctrlEditMulti"]
]
[
//--- Examples
[
	[ // Example 1
		"RscText",// Title
		[nil,1], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetText "This is an example";
			_this ctrlSetBackgroundColor [0,0,0.5,0.8];
		}
	],
	[ // Example 2
		"RscPicture",
		[5,5],
		{
			_this ctrlSetText "\a3\ui_f\data\logos\arma3_expansion_ca.paa";
		}
	]
],
//--- Description
"A static control is, just as the name says, a non interactable control. It can be used for text, background, pictures and videos.",
//--- EH
[],
//--- Commands
["ctrlSetBackgroundColor","ctrlSetFont","ctrlSetText","ctrlSetTextColor","ctrlText","ctrlTextHeight","ctrlTextWidth","ctrlAngle","ctrlSetAngle"],
//--- Common base classes
["<t color='#FF5555'>RscText</t>","RscTextMulti","RscFrame","RscLine","RscPicture","RscPictureKeepAspect","RscVideo","ctrlStaticPicture","ctrlStaticFrame","ctrlStaticLine","ctrlStaticMulti","ctrlStaticBackground","ctrlStaticTitle","ctrlStaticBackgroundDisable","ctrlStaticBackgroundDisableTiles"]
]
[
//--- Examples
[
	[ // Example 1
		"RscActiveText",// Class
		[], // Width, height
		{
			_this ctrlSetText "Click me!";
			_this ctrlSetTextColor [0.8,0.5,0,1];
		} // Commands to execute upon creation
	],
	[ // Example 2
		"RscActivePicture",// Class
		[5,5], // Width, height
		{
			_this ctrlSetText "\a3\ui_f\data\logos\arma3_expansion_ca.paa";
		} // Commands to execute upon creation
	]

],
//--- Description
"An active text control works just like a button with the difference of having no background. When using style = ST_PICTURE you are able to show a clickable picture (see example 2).",
//--- EH
["ButtonClick","ButtonDblClick","ButtonDown","ButtonUp"],
//--- Commands
["ctrlSetText","ctrlSetTextColor","ctrlText"],
//--- Common base classes
["<t color='#FF5555'>RscActiveText</t>","RscActivePicture","RscActivePictureKeepAspect"]
]
[
//--- Examples
[
	[ // Example 1
		"TER_3den_RscCheckboxesExample",// Class
		[5,2], // Width, height
		{} // Commands to execute upon creation
	],
	[ // Example 2
		"TER_3den_RscCheckboxesExample2",// Class
		[5,2], // Width, height
		{} // Commands to execute upon creation
	]
],
//--- Description
"This control type is a group of checkboxes. The amount of checkboxes and content can only be modified in the config. If you want the user to able to select only one entry at a time then use CT_TOOLBOX instead.",
//--- EH
["CheckBoxesSelChanged"],
//--- Commands
["ctrlChecked","ctrlSetChecked"],
//--- Common base classes
["ctrlCheckboxes"]
]
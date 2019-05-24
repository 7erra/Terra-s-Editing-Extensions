[
//--- Examples
[
	[ // Example 1
		"TER_3den_RscToolboxExample",// Class
		[nil,3], // Width, height
		{} // Commands to execute upon creation
	],
	[ // Example 2
		"TER_3den_RscToolboxExample2",
		[12,2],
		{}
	]
],
//--- Description
"The CT_TOOLBOX contains a set of buttons. It is only possible to select one button at a time. If you want to select more than one entry at a time you can use CT_CHECKBOXES instead. All entries are defined in the config and are therefore not changeable during the mission. This control type is used in eg on the left and right panels of the 3den Editor.",
//--- EH
["ToolBoxSelChanged"],
//--- Commands
[],
//--- Common base classes
["<t color='#FF5555'>RscToolbox</t>","RscToolboxButton","ctrlToolbox","ctrlToolboxPicture","ctrlToolboxPictureKeepAspect"]
]
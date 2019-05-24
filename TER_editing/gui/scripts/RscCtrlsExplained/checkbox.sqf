[
//--- Examples
[
	[ // Example 1
		"RscCheckbox",// Class
		[1], // Width, height
		{ // Commands to execute upon creation
		}
	],
	[ // Example 1
		"ctrlCheckbox",// Class
		[1], // Width, height
		{ // Commands to execute upon creation
		}
	]
],
//--- Description
"A single checkbox. It can take on two states: Checked (true/1) and Unchecked (false/0). The commands and eventhandlers are inconsistent when it comes to handling the checked state, meaning that the EH returns 0 for unchecked and 1 for checked while the commands cbChecked and cbSetChecked use boolean values (true/false).",
//--- EH
["onCheckedChanged"],
//--- Commands
["cbChecked","cbSetChecked"],
//--- Common base classes
["<t color='#FF5555'>RscCheckBox</t>","ctrlCheckbox","ctrlCheckboxBaseline","ctrlCheckboxToolbar"]
]


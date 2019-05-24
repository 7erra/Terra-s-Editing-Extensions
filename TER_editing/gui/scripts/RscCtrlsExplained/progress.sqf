[
//--- Examples
[
	[ // Example 1
		"RscProgress",// Class
		[10], // Width, height
		{
			_this spawn {
				_percent = 0;
				while {!isNull _this} do {
					_this progressSetPosition _percent;
					_percent = [0,_percent + 0.01] select (_percent < 1.5);
					uiSleep 0.02;
				};
			};
		} // Commands to execute upon creation
	]
/*	[ // Example 2
		"TER_3den_RscCheckboxesExample2",// Class
		[5,2], // Width, height
		{} // Commands to execute upon creation
	]
*/
],
//--- Description
"The progress bar is another non interactable control. It accepts no user input but can be modified with a few commands. ctrlSetTextColor modifies the color of the progress bar. The example is animated with the progressSetPosition command.",
//--- EH
[],
//--- Commands
["progressSetPosition","progressPosition","ctrlSetTextColor"],
//--- Common base classes
["<t color='#FF5555'>RscProgress</t>","RscIGProgress","ctrlProgress"]
]
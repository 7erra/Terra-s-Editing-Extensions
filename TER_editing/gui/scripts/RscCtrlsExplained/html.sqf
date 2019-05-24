[
//--- Examples
[
	[ // Example 1
		"RscText",// Class
		[], // Width, height
		{
			_this ctrlSetText "WIP";
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
"The HTML control is well known as the ""notebook"" in the Map-View of the game. It can display a text over more pages and can inherit links to other, own defined sections. It has some simple formatting possibilities. It also can display images.",
//--- EH
["onHTMLLink"],
//--- Commands
["htmlLoad","ctrlHTMLLoaded"],
//--- Common base classes
["<t color='#FF5555'>RscHTML</t>", "ctrlHTML"]
]
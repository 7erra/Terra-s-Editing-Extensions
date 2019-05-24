[
//--- Examples
[
	/*[ // Example 1
		"Rsc",// Class
		[nil,6], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetStructuredText parsetext "This control supports all formatting via <a href='https://community.bistudio.com/wiki/Structured_Text'>structured text</a>. <t color='#FF00FF'>You can also change the color and <t font='LCD14'> the font as well.</t></t><t size='1.5'>   This is a big text!</t><br/>And some more...";
		}
	],
	[ // Example 2
		"RscActivePicture",// Class
		[5,5], // Width, height
		{
			_this ctrlSetText "\a3\ui_f\data\logos\arma3_expansion_ca.paa";
		} // Commands to execute upon creation
	]
*/
],
//--- Description
"This context menu is only used on one control in the game: RscDisplayUavTerminalWaypointMenu. It is used in the UAV feed when right clicking on the map. There are no hints on how to use it. Creating it as an independent control makes it not behave like expected. The newer version is CT_MENU as used for the context menu in 3den but shares the same problem.",
//--- EH
[],
//--- Commands
[],
//--- Common base classes
[]
]
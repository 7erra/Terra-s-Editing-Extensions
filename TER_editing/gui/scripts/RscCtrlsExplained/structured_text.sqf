[
//--- Examples
[
	[ // Example 1
		"RscStructuredText",// Class
		[nil,6], // Width, height
		{ // Commands to execute upon creation
			_this ctrlSetStructuredText parsetext "This control supports all formatting via <a href='https://community.bistudio.com/wiki/Structured_Text'>structured text</a>. <t color='#FF00FF'>You can also change the color and <t font='LCD14'> the font as well.</t></t><t size='1.5'>   This is a big text!</t><br/>And some more...";
		}
	]/*,
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
"When displaying text this is the go to control. It supports all kinds of <a colorLink='#5555FF' href='https://community.bistudio.com/wiki/Structured_Text'>formatted text</a>. It is a better alternative to a CT_STATIC control. In fact, the entire part below the examples is only structured text! When using the formats be sure to keep a look at the rpt log because while structured text might not show an error and quit the script it does log a line to the rpt when it encounters a problem like "" a a href='link.com' "". In this case it will log ""Unkown attribute: a"".",
//--- EH
[],
//--- Commands
["ctrlSetText","ctrlSetStructuredText","ctrlTextHeight","ctrlTextWidth"],
//--- Common base classes
["<t color='#FF5555'>RscStructuredText</t>","ctrlStructuredText"]
]
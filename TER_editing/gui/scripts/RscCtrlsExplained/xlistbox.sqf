[
//--- Examples
[
	[ // Example 1
		"RscXListBox",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			{_this lbAdd _x} forEach ["Item 0","Item 1","Item 2","Item 3","Item 4"];
			_this lbSetCurSel 0;
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
"A horizontal version of the CT_LISTBOX.",
//--- EH
["LBSelChanged"],
//--- Commands
["lbClear","lbColor","lbCurSel","lbData","lbDelete","lbIsSelected","lbPicture","lbSelection","lbSetColor","lbSetCurSel","lbSetData","lbSetPicture","lbSetSelected","lbSetTooltip","lbSetValue","lbSize","lbSort","lbSortByValue","lbText","lbValue"],
//--- Common base classes
["<t color='#FF5555'>RscXListBox</t>","ctrlXListbox"]
]
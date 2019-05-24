[
//--- Examples
[
	[ // Example 1
		"RscCombo",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			{
				_this lbAdd _x;
			} forEach ["Item 0","Item 1","Item 2"];
			_this lbSetCurSel 0;
		}
	]
],
//--- Description
"A simple dropdown menu. It is closely related to the control type <t color='#4444ff'>CT_LISTBOX</t> as it shares the same commands and eventhandlers. The advantage is the smaller overall size. On the other hand you are neither able to see the entries beforehand nor are you able to perform a drag and drop operation.",
//--- EH
["LBSelChanged","LBListSelChanged"],
//--- Commands
["lbClear","lbColor","lbCurSel","lbData","lbDelete","lbIsSelected","lbPicture","lbSelection","lbSetColor","lbSetCurSel","lbSetData","lbSetPicture","lbSetSelected","lbSetTooltip","lbSetValue","lbSize","lbSort","lbSortByValue","lbText","lbValue"],
//--- Common base classes
["<t color='#FF5555'>RscCombo</t>","ctrlCombo"]
]
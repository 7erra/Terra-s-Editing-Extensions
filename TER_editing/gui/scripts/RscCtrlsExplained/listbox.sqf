[
//--- Examples
[
	[ // Example 1
		"RscListbox",// Class
		[nil,5], // Width, height
		{ // Commands to execute upon creation
			{
				_this lbAdd _x;
			} forEach ["Item 0","Item 1","Item 2","Item 3","Item 4","Item 5","Item 6"];
			_this lbSetCurSel 0;
		}
	]
],
//--- Description
"The CT_LISTBOX is a bit more versatile than the CT_COMBO as it can also handle drag and drop events. The downside is that it requires more space. The example contains 7 items but is not scrollable which is most likely a bug as it is scrollable when used normally.",
//--- EH
["LBSelChanged","LBListSelChanged"],
//--- Commands
["lbClear","lbColor","lbCurSel","lbData","lbDelete","lbIsSelected","lbPicture","lbSelection","lbSetColor","lbSetCurSel","lbSetData","lbSetPicture","lbSetSelected","lbSetTooltip","lbSetValue","lbSize","lbSort","lbSortByValue","lbText","lbValue"],
//--- Common base classes
["<t color='#FF5555'>RscListbox</t>","ctrlListbox"]
]
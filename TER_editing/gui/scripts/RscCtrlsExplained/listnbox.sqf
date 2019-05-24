[
//--- Examples
[
	[ // Example 1
		"RscListNBox",// Class
		[nil,3], // Width, height
		{ // Commands to execute upon creation
			_this lnbSetColumnsPos [0.01,1/3,2/3];
			for "_i" from 0 to 5 do {
				_row = ["Item %1.0","Item %1.1","Item %1.2"];
				_row = _row apply {format [_x,_i]};
				_this lnbAddRow _row
			};
			_this lnbSetCurSelRow 0;
		}
	],
	[ // Example 2
		"ctrlListNBox",// Class
		[nil,3], // Width, height
		{ // Commands to execute upon creation
			_this lnbSetColumnsPos [0.01,1/3,2/3];
			for "_i" from 0 to 5 do {
				_row = ["Item %1.0","Item %1.1","Item %1.2"];
				_row = _row apply {format [_x,_i]};
				_this lnbAddRow _row
			};
			_this lnbSetCurSelRow 0;
		}
	],
	[ // Example 3
		"TER_3den_RscListNBoxExample",// Class
		[nil,3], // Width, height
		{ // Commands to execute upon creation
			_display = findDisplay 73140;
			_plus = _display ctrlCreate ["RscButtonMenu",198,_display displayCtrl 1500];
			_plus ctrlAddEventHandler ["ButtonClick",{
				_lnb = findDisplay 73140 displayCtrl 102;
				_path = [lnbCurSelRow _lnb, 1];
				_pre = _lnb lnbText _path;
				_new = (parseNumber _pre) +1;
				_lnb lnbSetText [_path,str _new];
			}];
			_plus ctrlSetText "+";
			_minus = _display ctrlCreate ["RscButtonMenu",199,_display displayCtrl 1500];
			_minus ctrlAddEventHandler ["ButtonClick",{
				_lnb = findDisplay 73140 displayCtrl 102;
				_path = [lnbCurSelRow _lnb, 1];
				_pre = _lnb lnbText _path;
				_new = (parseNumber _pre) -1;
				_lnb lnbSetText [_path,str _new];
			}];
			_minus ctrlSettext "-";
			{
				_x ctrlSetPosition [0,0,2.5 * pixelGrid * pixelW,2.5 * pixelGrid * pixelH];
				_x ctrlCommit 0;
				_x ctrlShow false;
				_x setVariable ["doCountY",false];
			} forEach [_plus,_minus];
			for "_i" from 0 to 5 do {
				_row = ["Item %1","0"];
				_row = _row apply {format [_x,_i]};
				_this lnbAddRow _row;
			};
			_this lnbSetCurSelRow 0;
		}
	]
],
//--- Description
"A multi column version of the CT_LISTBOX. It can also be used in conjunction with controls that are displayed alongside the currently selected entry (example 3). The third example requires a bit more scripting but it is used in a very similar way as the listbox for the arsenal when a container (uniform, vest, backpack) is selected. For unknown reasons example one and three are not scrollable here but they are just like example two when used in a dialog. The dissapearance of the background is of unknown reason.",
//--- EH
["LBSelChanged","onLBDblClick"],
//--- Commands
["lnbAddArray","lnbAddColumn","lnbClear","lnbColor","lnbCurSelRow","lnbData","lnbDeleteColumn","lnbDeleteRow","lnbGetColumnsPosition","lnbPicture","lnbSetColor","lnbSetColumnsPos","lnbSetCurSelRow","lnbSetData","lnbSetPicture","lnbSetText","lnbSetValue","lnbSize","lnbText","lnbValue"],
//--- Common base classes
["<t color='#FF5555'>RscListNBox</t>","ctrlListNBox"]
]
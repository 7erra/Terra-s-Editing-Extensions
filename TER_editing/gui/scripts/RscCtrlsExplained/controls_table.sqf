[
//--- Examples
[
	/*
	[ // Example 1
		"TER_3den_RscControlsTable",// Class
		[10,5], // Width, height
		{
			systemChat str _this;
			_header = ctAddHeader _this;
			_header#1 params ["_back","_picCol1","_txtCol2"];
			_back ctrlSetBackgroundColor [0.33,0.33,1,1];
			_picCol1 ctrlSetText "\a3\ui_f\data\map\mapcontrol\waypointcompleted_ca.paa";
			for "_i" from 0 to 5 do {
				_row = ctAddRow _this;
				_row#1 params ["_back","_picCol1","_txtCol2","_btnCol3"];
				_back ctrlSetBackgroundColor [0.5,0.5,0.5,1];
				_picCol1 ctrlSetText "\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
				_txtCol2 ctrlSetText format ["Entry %1",_i];
				_btnCol3 ctrlSetText "CLICK";
			};
		} // Commands to execute upon creation
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
"Just like a listbox this control type hosts a list of items. While the listbox is limited do displaying text only this one can also show any number of the following control types:<br/>
- CT_STATIC<br/>
- CT_BUTTON<br/>
- CT_EDIT<br/>
- CT_ACTIVETEXT<br/>
- CT_STRUCTURED_TEXT<br/>
- CT_SHORTCUTBUTTON<br/>
- CT_XSLIDER<br/>
- CT_CHECKBOX<br/>
There is no example, neither ingame nor here, because it won't be created with the ctrlCreate command and isn't used anywhere. The base class RscControlsTable is not exported even when using the ""all"" parameter for BIS_fnc_exportGUIBaseClasses. You can copy the example from the BIKI and use it as a base class but make sure to adjust the attributes to your needs as it relies heavily on config based settings and especially watch out for changing the ""type = CT_CONTROLS_TABLE;"" line to 19 or add the #define to your default defines.",
//--- EH
[],
//--- Commands
["ctAddRow", "ctAddHeader", "ctClear", "ctCurSel", "ctSetCurSel", "ctRowControls", "ctHeaderControls", "ctRowCount", "ctHeaderCount", "ctSetValue", "ctValue", "ctSetData", "ctData", "ctFindRowHeader", "ctFindHeaderRows", "ctRemoveRows", "ctRemoveHeaders", "ctSetRowTemplate", "ctSetHeaderTemplate"],
//--- Common base classes
["<t color='#FF5555'>RscControlsTable</t>"]
]
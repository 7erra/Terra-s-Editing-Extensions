#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "ctrls.inc"
#define SELF RscDisplayNamespaceVars_script
#define STRSELF #SELF
params ["_mode",["_this",[]]];
//--- Controls
_display = findDisplay IDD_DISPLAY_NAMESPACEVARS;
_comboNamespace = _display displayCtrl IDC_NAMESPACE_COMBONAMESPACE;
_edSearch = _display displayCtrl IDC_NAMESPACE_EDSEARCH;
_btnSortName = _display displayCtrl IDC_NAMESPACE_BTNSORTNAME;
//_lnbHeader = _display displayCtrl IDC_NAMESPACE_LNBVARSHEADER;
_lnbVars = _display displayCtrl IDC_NAMESPACE_LNBVARS;
_edVarname = _display displayCtrl IDC_NAMESPACE_EDVARNAME;
_edValue = _display displayCtrl IDC_NAMESPACE_EDVALUE;
_txtValueType = _display displayCtrl IDC_NAMESPACE_TXTVALUETYPEIS;
_btnDelete = _display displayCtrl IDC_NAMESPACE_BTNDELETE;
_btnSet = _display displayCtrl IDC_NAMESPACE_BTNSET;

switch _mode do {
case "onload":{
	params ["_display"];
	_self = uiNamespace getVariable STRSELF;
	if (isNil "_self") then {
		_self = compile preprocessFileLineNumbers "TER_Editing\gui\scripts\RscNamespaceVars.sqf";
		uiNamespace setVariable [STRSELF,_self];
	};
	//--- Namespace combo
	{
		_ind = _comboNamespace lbAdd _x;
	} forEach ["missionNamespace","uiNamespace","parsingNamespace","profileNamespace"];
	_comboNamespace ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["changenamespace",_this] call SELF};
	}];
	_comboNamespace lbSetCurSel 0;
	//--- Search edit
	_edSearch ctrlAddEventHandler ["KeyDown",{
		with uiNamespace do {["search",_this] spawn SELF};
	}];
	//--- Sort by name button
	_btnSortName ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["sortname",[]] call SELF};
	}];
	//--- Variables list
	with uiNamespace do {["filllnb",[]] call SELF};
	_lnbVars ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["varchange",_this] call SELF};
	}];
	//--- Delete button
	_btnDelete ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["delete",[]] spawn SELF};
	}];
	//--- Set button
	_btnSet ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["set",[]] spawn SELF};
	}];
};
case "filllnb":{
	_filter = ctrlText _edSearch;
	lnbClear _lnbVars;
	_namespace = _display getVariable "curNamespace";
	_allVars = allVariables _namespace;
	_allVars = _allVars select {_x find "_fnc_" == -1};
	_allVars = _allVars select {toLower _x find toLower _filter != -1};
	{
		_var = _x;
		_val = _namespace getVariable _var;
		_ind = _lnbVars lnbAddRow [_var, str _val];
		_lnbVars lnbSetData [[_ind,1],typeName _val];
	} forEach _allVars;
	_lnbVars lnbSort [0,_btnSortName getVariable ["reverse",false]];
};
case "changenamespace":{
	params ["_comboNamespace","_ind"];
	_display setVariable ["curNamespace",call compile (_comboNamespace lbText lbCurSel _comboNamespace)];
	["filllnb",[]] call SELF;
};
case "search":{
	params ["_edSearch", "_key", "_shift", "_ctrl", "_alt"];
	if (ctrlText _edSearch != _edSearch getVariable ["_prevSearch",""]) then {
		_edSearch setVariable ["_prevSearch",ctrlText _edSearch];
		["filllnb",[]] call SELF;
	};
};
case "varchange":{
	params ["_lnbVars","_ind"];
	_var = _lnbVars lnbText [_ind,0];
	_edVarname ctrlSetText _var;
	_val = _lnbVars lnbText [_ind,1];
	_edValue ctrlSetText _val;
	_type = _lnbVars lnbData [_ind,1];
	_acceptTypes = [true,1234,"string"] apply {typeName _x};
	_btnSet ctrlEnable (_type in _acceptTypes);
	_txtValueType ctrlSetText _type;
};
case "delete":{
	_result = ["Are you sure that you want to delete the variable?", "Confirm", true, true, _display, true] call BIS_fnc_GUImessage;
	if (_result) then {
		//--- Reset variable
		_ind = lnbCurSelRow _lnbVars;
		_namespace = _display getVariable "curNamespace";
		_var = _lnbVars lnbText [_ind, 0];
		_lnbVars lnbDeleteRow _ind;
		_namespace setVariable [_var, nil];
		["varchange",[_lnbVars, _ind-1]] call SELF;
	};
};
case "set":{
	_toSet = call compile ctrlText _edValue;
	if (isNil "_toSet") exitWith {
		["delete",[]] call SELF;
	};
	//if (typeName _toSet == ctrltext _txtValueType) then {
	_namespace = _display getVariable "curNamespace";
	_namespace setVariable [ctrlText _edVarname, _toSet];
	_lnbVars lnbSettext [[lnbCurSelRow _lnbVars, 1],str _toSet];
};
case "sortname": {
	_reverse = _btnSortName getVariable ["reverse",false];
	_btnSortName setVariable ["reverse",!_reverse];
	_lnbVars lnbSort [0,!_reverse];
};
case "unload":{

};
};
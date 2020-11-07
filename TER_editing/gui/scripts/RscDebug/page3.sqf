#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage3_script
#define PARAMSROW ["_btnExec","_edCommand","_actpicDelete"]
params ["_mode", "_params"];
//--- CONTROLS
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_3;
_comboLocality = _page controlsGroupCtrl IDC_DEBUG_CCLOCALITY;
_btnAdd = _page controlsGroupCtrl IDC_DEBUG_CCADD;
_ctCCTable = _page controlsGroupCtrl IDC_DEBUG_TABLECC;
_edOutput = _page controlsGroupCtrl IDC_DEBUG_EDOUTPUTCC;

switch (_mode) do {
case "load":{
	waitUntil {!isNull findDisplay 49};
	_displayEscape = findDisplay 49;
	_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_3;
	_comboLocality = _page controlsGroupCtrl IDC_DEBUG_CCLOCALITY;
	_btnAdd = _page controlsGroupCtrl IDC_DEBUG_CCADD;
	_ctCCTable = _page controlsGroupCtrl IDC_DEBUG_TABLECC;
	_edOutput = _page controlsGroupCtrl IDC_DEBUG_EDOUTPUTCC;
	//_params params ["_displayEscape"];
	//_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_3;
	if (_page getVariable ["pageInitialized",false]) exitWith {};
	_page setVariable ["pageInitialized",true];
	//--- Locality combo
	_comboLocality = _page controlsGroupCtrl IDC_DEBUG_CCLOCALITY;
	if (isMultiplayer) then {
		//--- Add general locality options and players
		_targetPlayers = allPlayers apply {[name _x, owner _x]};
		_targetPlayers = _targetPlayers select {_x#1 != 0};
		_targets = [["Local",-1],["Global",0],["Server",2],["!Server",-2]] +_targetPlayers;
		{
			_x params ["_text","_value"];
			_addText = format ["%1 (%2)",_text,_value];
			if (_value == -1) then {
				_addText = _text;
			};
			_ind = _comboLocality lbAdd _addText;
			_comboLocality lbSetValue [_ind,_value];
		} forEach _targets;
		_comboLocality lbSetCurSel (uiNamespace getVariable ["TER_3den_ccLocalityInd",0]);
		_comboLocality ctrlAddEventHandler ["LBSelChanged",{
			with uiNamespace do {["localitychange",_this] call SELF};
		}];
	} else {
		//--- Not MP, disable
		_ind = _comboLocality lbAdd "Local";
		_comboLocality lbSetValue [_ind, -1];
		_comboLocality lbSetCurSel _ind;
		_comboLocality ctrlEnable false;
	};
	//--- Add button
	_btnAdd ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["addcc",[]] spawn SELF};
	}];
	//--- Load previous
	{
		with uiNamespace do {["addcc",[_x]] call SELF};
	} forEach (profileNamespace getVariable ["TER_3den_ccArray",[]]);
};
case "localitychange":{
	_params params ["_comboLocality","_ind"];
	uiNamespace setVariable ["TER_3den_ccLocalityInd",_ind];
};
case "addcc":{
	_command = _params param [0,""];
	_row = ctAddRow _ctCCTable;
	_row#1 params PARAMSROW;
	//--- Exec button
	_btnExec ctrlSetText "EXEC";
	_btnExec ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["ccexec",[]] call SELF};
	}];
	//--- Code edit
	_edCommand ctrlSetText _command;
	_edCommand ctrlAddEventHandler ["KeyDown",{
		with uiNamespace do {["edkey",_this] call SELF};
	}];
	//--- Delete actpic
	_actpicDelete ctrlSetText "\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
	_actpicDelete ctrlSetTextColor [1,0,0,1];
	_actpicDelete ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["deletecc",[]] spawn SELF};
	}];
};
case "ccexec":{
	_ind = ctCurSel _ctCCTable;
	if (_ind < 0) exitWith {};
	_row = _ctCCTable ctRowControls _ind;
	_row params PARAMSROW;
	_command = compile ctrlText _edCommand;
	_locality = _comboLocality lbValue (lbCurSel _comboLocality);
	if (_locality == -1) then {
		//--- Local execution
		_result = with missionNamespace do {
			//--- The following is a workaround to avoid error messages when
			//--- assigning values to global variables
			[nil] apply {[] call _command} param [0, nil]
		};
		if (isNil "_result") then {
			_edOutput ctrlSetText "#NIL";
		} else {
			_edOutput ctrlSetText str _result;
		};
	} else {
		//--- Remote execution
		with missionnamespace do {[[],_command] remoteExec ["call",_locality];};
		_edOutput ctrlSetText "#REMOTE EXECUTION";
	};
};
case "deletecc":{
	_ind = ctCurSel _ctCCTable;
	if (_ind < 0) exitWith {};
	_ctCCTable ctRemoveRows [_ind];
};
case "edkey":{
	_params params ["_edCommand", "_key", "_shift", "_ctrl", "_alt"];
	if (_key in [DIK_RETURN, DIK_NUMPADENTER]) then {
		["ccexec",[]] call SELF;
	};
};
case "unload":{
	if !(_page getVariable ["pageInitialized",false]) exitWith {};
	//--- Save variables
	_saveCommands = [];
	for "_ind" from 0 to (ctRowCount _ctCCTable -1) do {
		_row = _ctCCTable ctRowControls _ind;
		_row params PARAMSROW;
		_command = ctrlText _edCommand;
		_saveCommands pushBack _command;
	};
	profileNamespace setVariable ["TER_3den_ccArray",_saveCommands];
	saveProfileNamespace;
};
};
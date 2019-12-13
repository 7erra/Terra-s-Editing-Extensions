#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage2_script
#define PARAMSROW ["_back","_cbLive","_edCommand","_actpicDelete","_txtOut"]
_mode = _this select 0;
_this = _this select 1;
//--- Controls
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_2;
_tableWatch = _page controlsGroupCtrl IDC_DEBUG_TABLEWATCHFIELDS;

switch (_mode) do {
case "load":{
	if (_page getVariable ["pageInitialized",false]) exitWith {
		//--- Activate watch controls when page is selected
		_inputControls = [];
		for "_ind" from 0 to (ctRowCount _tableWatch -1) do {
			_row = _tableWatch ctRowControls _ind;
			_row params PARAMSROW;
			_inputControls pushBack _edCommand;
		};
		_inputControls apply {
			_x setVariable ["isFocused",false];
			0
		};
	};
	_page setVariable ["pageInitialized",true];

	//--- Add header to table
	_header = ctAddHeader _tableWatch;
	_header#1 params ["_back","_btnAdd"];
	_back ctrlSetStructuredText parseText "<t font='PuristaLight'>More watch fields:</t>";
	_btnAdd ctrlSetText "+";
	_btnAdd ctrlSetTooltip "Add new watch field";
	_btnAdd ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["createfield",[""]] call SELF;};
	}];
	//--- Fill table with prev commands
	_hasLive = false;
	{
		_rowControls = with uiNamespace do {["createfield",[_x]] call SELF;};
		_rowControls params PARAMSROW;
		if (cbChecked _cbLive && !_hasLive) then {_hasLive = true};
	} forEach (profileNamespace getVariable ["TER_3den_watchCommands",[]]);
	if (_hasLive) then {
		with uiNamespace do {["livedebug",[]] call SELF};
	};
};
case "createfield":{
	_command = param [0,""];
	_row = ctAddRow _tableWatch;
	_row#1 params PARAMSROW;
	//--- Live CB
	_curLiveCommands = [];
	if (!isNil "TER_3den_RscLiveWatch_commands") then {
		_curLiveCommands = +TER_3den_RscLiveWatch_commands;
	};
	if (_command != "" && _command in _curLiveCommands) then {
		_cbLive cbSetChecked true;
	};
	_cbLive ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["livedebug",_this] call SELF;};
	}];
	//--- Command edit
	_edCommand ctrlSetText _command;
	_edCommand setVariable ["isFocused",false];
	ctrlSetFocus _edCommand;
	_edCommand ctrlAddEventHandler ["SetFocus",{
		with uiNamespace do {["focuschange",[_this#0,true]] call SELF};
	}];
	_edCommand ctrlAddEventHandler ["KillFocus",{
		with uiNamespace do {["focuschange",[_this#0,false]] call SELF};
	}];
	//--- Delete Actpic
	_actpicDelete ctrlSetText "\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
	_actpicDelete ctrlSetTextColor [1,0,0,1];
	_actpicDelete ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["deletefield",[]] spawn SELF};
	}];
	//--- Output text
	_txtOut ctrlSetBackgroundColor [0,0,0,0.8];
	//--- Call watch loop
	["liveloop",[ctRowCount _tableWatch -1]] spawn SELF;
	//--- Return new controls
	_row#1;
};
case "deletefield":{
	_ind = ctCurSel _tableWatch;
	if (_ind == -1) exitWith {};
	_rowControls = _tableWatch ctRowControls _ind;
	_rowControls params PARAMSROW;
	_updateLive = false;
	if (cbChecked _cbLive) then {
		_updateLive = true;
	};
	_tableWatch ctRemoveRows [_ind];
	if (_updateLive) then {
		["livedebug",_this] call SELF;
	};
};
case "liveloop":{
	params ["_ind"];
	_row = _tableWatch ctRowControls _ind;
	_row params PARAMSROW;
	while {!isNull _edCommand} do {
		_result = with missionnamespace do {call compile ctrlText _edCommand};
		if (isNil "_result") then {
			_txtOut ctrlSetText "#NIL";
			_txtOut ctrlSetBackgroundColor [1,0,0,0.33];
		} else {
			_txtOut ctrlSetText str _result;
			_txtOut ctrlSetBackgroundColor [0,1,0,0.33];
		};
		if (_edCommand getVariable ["isFocused",false]) then {
			waitUntil {!(_edCommand getVariable ["isFocused",true]) || isNull _edCommand};
		} else {
			_frame = diag_frameno;
			waitUntil {_frame != diag_frameno || isNull _edCommand};
		};
	};
};
case "focuschange":{
	params ["_edCommand","_focused"];
	_edCommand setVariable ["isFocused",_focused];
	if (!_focused) then {
		["livedebug",_this] call SELF;
	};
};
case "livedebug":{
	_displayLive = uiNamespace getVariable ["TER_3den_RscLiveWatch_display",displayNull];
	_openLiveDisplay = !isNull _displayLive;

	//--- Get all checked commands
	_liveCommands = [];
	for "_ind" from 0 to (ctRowCount _tableWatch -1) do {
		_row = _tableWatch ctRowControls _ind;
		_row params PARAMSROW;
		if (cbChecked _cbLive) then {
			_liveCommands pushBack (ctrlText _edCommand);
		};
	};
	//--- No commands changed, leave
	//--- No commands selected, close display
	if (count _liveCommands == 0 && _openLiveDisplay) exitWith {
		"TER_3den_RscWatchLive_layer" cutFadeOut 0;
		TER_3den_RscLiveWatch_commands = nil;
	};
	//if (_liveCommands isEqualTo (uiNamespace getVariable ["TER_3den_RscLiveWatch_commands",[]])) exitWith {};
	TER_3den_RscLiveWatch_commands = +_liveCommands;
	if (count _liveCommands == 0) exitWith {};
	//--- Create display, come back when display is open
	if (!_openLiveDisplay) exitWith {
		("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["TER_3den_RscLiveWatch","PLAIN"];
	};
	//--- Update display
	_tableLive = TER_3den_RscLiveWatch_display displayCtrl IDC_LIVE_TABLE;
	ctClear _tableLive;
	{
		_row = ctAddRow _tableLive;
		_row#1 params ["_back", "_txtIn","_txtOut"];
		_txtIn ctrlSetBackgroundColor [0,0,0,0.5];
		_txtIn ctrlSetText _x;
		[_txtOut, _x] spawn {
			params ["_txtOut","_command"];
			_command = compile _command;
			while {!isNull _txtOut} do {
				_result = with missionnamespace do {call _command;};
				if (isNil "_result") then {
					_txtOut ctrlSetText "#NIL";
					_txtOut ctrlSetBackgroundColor [1,0,0,0.5];
				} else {
					_txtOut ctrlSetText str _result;
					_txtOut ctrlSetBackgroundColor [0,1,0,0.5];
				};
				_frame = diag_frameno;
				waitUntil {_frame != diag_frameno};
			};
		};
	} forEach _liveCommands;
};
case "hide":{
	//--- Deactivate watch controls while page is not selected
	_inputControls = [];
	for "_ind" from 0 to (ctRowCount _tableWatch -1) do {
		_row = _tableWatch ctRowControls _ind;
		_row params PARAMSROW;
		_inputControls pushBack _edCommand;
	};
	_inputControls apply {
		_x setVariable ["isFocused",true];
		0
	};
};
case "unload":{
	if (!(_page getVariable ["pageInitialized",false])) exitWith {};
	//--- Update live display
	["livedebug",_this] call SELF;
	//--- Save variables
	_saveCommands = [];
	for "_ind" from 0 to (ctRowCount _tableWatch -1) do {
		_row = _tableWatch ctRowControls _ind;
		_row params PARAMSROW;
		_command = ctrlText _edCommand;
		_saveCommands pushBack _command;
	};
	profileNamespace setVariable ["TER_3den_watchCommands",_saveCommands];
	saveProfileNamespace;
};
};
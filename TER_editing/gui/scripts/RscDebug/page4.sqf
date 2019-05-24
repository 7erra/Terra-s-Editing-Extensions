#include "..\ctrls.inc"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"
#define SELF TER_fnc_debugPage4_script
_mode = _this select 0;
_this = _this select 1;
//--- CONTROLS
_displayEscape = findDisplay 49;
_vanillaDebug = _displayEscape displayCtrl IDC_ESC_DEBUGCONSOLE;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_4;
_comboWatchin = _page controlsGroupCtrl IDC_COMBO_WATCHIN;
_lbWatchHistory = _page controlsGroupCtrl IDC_LB_WATCHHISTORY;
_edMaxentries = _page controlsGroupCtrl IDC_ED_MAXENTRIES;
_btnHistoryMove = _page controlsGroupCtrl IDC_BTN_HISTORYMOVE;
_btnHistoryDeleteEntry = _page controlsGroupCtrl IDC_BTN_HISTORYDELETEENTRY;
_btnClearHistory = _page controlsGroupCtrl IDC_BTN_CLEARHISTORY;
_cbTDEnable = _page controlsGroupCtrl IDC_CB_TARGETDEBUG;
_edTDCommand = _page controlsGroupCtrl IDC_ED_TDCOMMAND;
_btnTDAdd = _page controlsGroupCtrl IDC_BTN_TDADD;
_btnTDRemove = _page controlsGroupCtrl IDC_BTN_TDREMOVE;
_lbTDCommands = _page controlsGroupCtrl IDC_LB_TDCOMMANDS;
_edLink = _page controlsGroupCtrl IDC_ED_LINK;
_btnLinkAdd = _page controlsGroupCtrl IDC_BTN_LINKADD;
_grpLinks = _page controlsGroupCtrl IDC_GRP_LINKS;
_stxtLinks = _page controlsGroupCtrl IDC_STXT_LINKS;
_watchInArray = [IDC_ESC_ED_WATCHIN1,IDC_ESC_ED_WATCHIN2,IDC_ESC_ED_WATCHIN3,IDC_ESC_ED_WATCHIN4];
_watchInArray = _watchInArray apply {_vanillaDebug controlsGroupCtrl _x};
//--- General variables
_historyArray = profileNamespace getVariable ["TER_3den_watchHistory_array",[]];
_debugTargetCommands = uiNamespace getVariable ["TER_3den_targetDebugCommands",[]];

switch (_mode) do {
case "load":{
	if (_page getVariable ["pageInitialized",false]) exitWith {};
	_page setVariable ["pageInitialized",true];

	/* Watch Favourites/History */
	//--- EH for saving entries from the vanilla debug console
	{
		_x ctrlAddEventHandler ["KeyDown",{
			with uiNamespace do {["addfav",_this] call SELF;};
		}];
	} forEach _watchInArray;
	//--- Listbox with commands
	{_lbWatchHistory lbAdd _x} forEach _historyArray;
	_lbWatchHistory ctrlAddEventHandler ["LBDblClick",{
		with uiNamespace do {["showfav",_this] call SELF;};
	}];
	//--- Combo: Which input
	{
	_index = _comboWatchin lbAdd toUpper format ["Input: %1",_x];
		_comboWatchin lbSetTooltip [_index,"Select which Input should be chosen"];
	} forEach ["First empty","Last empty",1,2,3,4];
	_comboWatchin lbSetCurSel 0;

	_lbWatchHistory ctrlAddEventHandler ["KeyDown",{
		with uiNamespace do {["keydownhistory",_this] call SELF;};
	}];
	//--- Move to watch field
	_btnHistoryMove ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["historymove",[]] call SELF;};
	}];
	_btnHistoryMove ctrlSetTooltip "Shortcut: Double click";
	//--- Delete history entry
	_btnHistoryDeleteEntry ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["historydeleteentry",[]] call SELF;};
	}];
	_btnHistoryDeleteEntry ctrlSetTooltip "Shortcut: DELETE";
	//--- Clear History
	_btnClearHistory ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["clearhistory",[]] call SELF;};
	}];

	/* TARGET DEBUG */
	//--- Toggle
	if (!isNull (uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull])) then {
		_cbTDEnable cbSetChecked true;
	};
	_cbTDEnable ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["tdenable",_this] call SELF;};
	}];
	//--- Add command
	_btnTDAdd ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["addcommand",[]] call SELF;};
	}];
	//--- Remove command
	_btnTDRemove ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["removecommand",[]] call SELF;};
	}];
	//--- Listbox TD
	if (count _debugTargetCommands == 0) then {
		_startCommands = ["_object","typeOf _object"];
		{
			_lbTDCommands lbAdd _x;
		} forEach _startCommands;
		uiNamespace setVariable ["TER_3den_targetDebugCommands",_startCommands];
	} else {
		{
			_lbTDCommands lbAdd _x;
		} forEach _debugTargetCommands;
	};
	_lbTDCommands ctrlAddEventHandler ["KeyDown",{
		with uiNamespace do {["tdkeydown",_this] call SELF;};
	}];

	/* BIKI LINKS */
	//--- init stxt links
	_prevLinkText = profileNamespace getVariable ["TER_3den_links",""];
	_stxtLinks ctrlSetStructuredText parseText _prevLinkText;
	_stxtLinks ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight _stxtLinks) max (6 * GUI_GRID_H)];
	_stxtLinks ctrlCommit 0;

	_btnLinkAdd ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["linkadd",[]] call SELF;};
	}];

	_tooltipArray = [
		"You can",
		"a) Add a command (case sensitive)",
		"b) Add a link",
		"c) Use ""#CLEAR"" to wipe the history",
		"d) Remove a link by adding the same link again"
	];
	_edLink ctrlSetTooltip (_tooltipArray joinString toString [10]);
};
case "addfav":{
	params ["_control","_key","_shift","_ctrl","_alt"];
	_textEdit = ctrlText _control;
	if (_ctrl && _key == DIK_F && (!isNil compile _textEdit) && !(toLower _textEdit in (_historyArray apply {toLower _x}))) then {// favourite
		reverse _historyArray;
		_historyArray pushBackUnique _textEdit;
		reverse _historyArray;
		profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
		saveProfileNamespace;
		lbClear _lbWatchHistory;
		{_lbWatchHistory lbAdd _x} forEach _historyArray;
	};
};
case "showfav":{
	params ["_listbox","_index"];
	_command = _listbox lbText _index;
	_edInput = switch (lbCurSel _comboWatchin) do {
		case 1: {
			_emptyTextArray = _watchInArray select {ctrlText _x == ""};
			reverse _emptyTextArray;
			if (count _emptyTextArray == 0) then {_watchInArray#3} else {_emptyTextArray select 0};
		};
		case 2: {_watchInArray#0};
		case 3: {_watchInArray#1};
		case 4: {_watchInArray#2};
		case 5: {_watchInArray#3};
		default {
			_emptyTextArray = _watchInArray select {ctrlText _x == ""};
			if (count _emptyTextArray == 0) then {_watchInArray#0} else {_emptyTextArray select 0};
		};
	};
	_edInput ctrlSetText _command;
};
case "keydownhistory":{
	params ["_listbox","_key"];
	if (_key == DIK_DELETE) then {
		_command = _listbox lbText (lbCurSel _listbox);
		_historyArray = _historyArray -[_command];
		profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
		_listbox lbDelete (lbCurSel _listbox);
	};
};
case "historymove":{
	//--- Move saved command to watch field
	if (lbCurSel _lbWatchHistory != -1) then {
		["showfav",[_lbWatchHistory,lbCurSel _lbWatchHistory]] call SELF;
	};
};
case "historydeleteentry":{
	//--- Move saved command to watch field
	if (lbCurSel _lbWatchHistory != -1) then {
		["keydownhistory",[_lbWatchHistory,DIK_DELETE]] call SELF;
	};
};
case "clearhistory":{
	profileNamespace setVariable ["TER_3den_watchHistory_array",nil];
	lbClear _lbWatchHistory;
};
case "tdenable":{
	params ["_ctrl","_state"];
	if (_state == 1) then {// activate target debugging
		("TER_3den_RscTargetDebug_layer" call BIS_fnc_rscLayer) cutRsc ["TER_RscDisplayTargetDebug","PLAIN"];
		// spawn start
		[] spawn {
			_display = uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull];
			_fncNewLine = {
				params ["_lText","_rText"];
				_text = _text +format ["<t underline='true'>%1</t><br/>   %2<br/>",_lText,_rText,toString [10]];
			};
			// loop start
			_radius = 20;
			while {!isNull _display} do {
				_entities = (getPos player nearEntities _radius)-[player];
				{
					_object = _x;
					_text = "";
					{
						_command = _x;
						_result = call compile _command;
						[_command,str _result] call _fncNewLine;
					} forEach (uiNamespace getVariable ["TER_3den_targetDebugCommands",[]]);

					// create new control for each entity
					private "_stxtInfo";
					if (isNull (_x getVariable ["TER_3den_stxtInfoControl",controlNull])) then{
						_stxtInfo = _display ctrlCreate ["RscStructuredText",-1];
						_stxtInfo ctrlSetBackgroundColor [0,0,0,0.2];
						_x setVariable ["TER_3den_stxtInfoControl",_stxtInfo];
					} else {
						_stxtInfo = _x getVariable ["TER_3den_stxtInfoControl",controlNull];
					};
					// set control pos
					_stxtInfo ctrlSetStructuredText parseText _text;
					if (count worldToScreen getPos _x > 0) then {
						_relPos = worldToScreen getPos _x;
						{_relPos set _x} forEach [[2,ctrlTextWidth _stxtInfo],[3,ctrlTextHeight _stxtInfo]];
						_stxtInfo ctrlSetPosition _relPos;
					};
					_stxtInfo ctrlCommit 0;

				} forEach _entities;
				{
					// hide controls which are beyond 100 m
					_stxtInfo = _x getVariable ["TER_3den_stxtInfoControl",controlNull];
					_stxtInfo ctrlSetPosition [0,0,0,0];
					_stxtInfo ctrlCommit 0;
				} forEach ((getPos player nearEntities (_radius +10))-_entities +allDead);
				_curFrame = diag_frameno;
				waitUntil {_curFrame != diag_frameno};
			};
			// loop end
		};
		// spawn end
	} else {// close display, end target debugging
		"TER_3den_RscTargetDebug_layer" cutFadeOut 0;
	};
};
case "addcommand":{
	_command = ctrlText _edTDCommand;
	//-- TODO: add check, if nil exit
	if !(["_object", _command] call BIS_fnc_inString) then {_command = _command +" _object"};
	//if (isNil compile _command) exitWith {_edTDCommand ctrlSettext "#ERROR - INVALID COMMAND"};
	// update global array
	_targetCommands = _debugTargetCommands;
	_prevCount = count _debugTargetCommands;
	_debugTargetCommands pushBackUnique _command;
	if (_prevCount == count _debugTargetCommands) exitWith {};
	_lbTDCommands lbAdd _command;
	uiNamespace setVariable ["TER_3den_targetDebugCommands",_debugTargetCommands];
	_edTDCommand ctrlSetText "";
	ctrlSetFocus _edTDCommand;
};
case "removecommand":{
	_index = lbCurSel _lbTDCommands;
	if (_index == -1) exitWith {};
	_command = _lbTDCommands lbText _index;
	TER_3den_targetDebugCommands = TER_3den_targetDebugCommands -[_command];
	_lbTDCommands lbDelete _index;
};
case "tdkeydown":{
	params ["_control", "_key", "_shift", "_ctrl", "_alt"];
	if (_key == DIK_DELETE) then {
		["removecommand",[]] call SELF;
	};
};
case "linkadd":{
	_command = ctrlText _edLink;
	if (_command == "#CLEAR") exitWith {
		profileNamespace setVariable ["TER_3den_links",""];
		_stxtLinks ctrlSetStructuredText parseText "";
		saveProfileNamespace;
	};
	_linkText = if (_command find "http" == -1) then {
		format ["<a href='https://community.bistudio.com/wiki/%1'>%1</a><br/>",_command];
	} else {
		format ["<a href='%1'>%1</a><br/>",_command];
	};
	_prevLinkText = profileNamespace getVariable ["TER_3den_links",""];
	if (_prevLinkText find _linkText != -1) then {
		_prevLinkText = (_prevLinkText select [0,_prevLinkText find _linkText]) + (_prevLinkText select [(_prevLinkText find _linkText) +count _linkText, count _prevLinkText]);
	};
	_newLinkText = if (count _prevLinkText == count (profileNamespace getVariable ["TER_3den_links",""])) then {
		 _linkText +_prevLinkText;
	} else {
		_prevLinkText;
	};
	profileNamespace setVariable ["TER_3den_links",_newLinkText];
	_stxtLinks ctrlSetStructuredText parseText _newLinkText;
	_stxtLinks ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight _stxtLinks) max (6 * GUI_GRID_H)];
	_stxtLinks ctrlCommit 0;
	saveProfileNamespace;
};
case "unload":{
};
};
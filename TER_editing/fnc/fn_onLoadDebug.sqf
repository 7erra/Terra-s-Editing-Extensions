/* NON MOD

TER_fnc_createWatchFields = compile preprocessFileLineNumbers "debug\fn_createWatchFields.sqf";
// NON MOD END */
#include "ctrls.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"
disableSerialization;
params ["_control"];
waitUntil {!isNull (findDisplay 49)};
_escapeMenu = findDisplay 49;

// save commands
#define CUR_CC_CONTROLS (allControls ESC_DISPLAY select {ctrlParentControlsGroup _x == GRP_CC_COMMANDS})
_escapeMenu displayAddEventHandler ["unLoad",{
	params ["_display"];
	_inputControls = (allControls ESC_DISPLAY) select {ctrlParentControlsGroup _x == GRP_WATCHFIELDS};
	_inputControls = _inputControls apply {ctrlText (_x controlsGroupCtrl 7490)};
	profileNamespace setVariable ["TER_3den_watchCommands",_inputControls];

	_allCCEdits = CUR_CC_CONTROLS apply {_x controlsGroupCtrl 7494};
	_allCCEditsText = _allCCEdits apply {ctrlText _x};
	_allCCEditsText = _allCCEditsText select {_x != ""};
	profileNamespace setVariable ["TER_3den_ccArray",_allCCEditsText];
	saveProfileNamespace;
}];

// draw grids
_cbDrawGrids = _escapeMenu displayCtrl 7400;
_cbDrawGridsGroupControl = _control controlsGroupCtrl 7400;
if (!isNull (uiNamespace getVariable ["TER_3den_RscGrids_display",displayNull])) then {
	_cbDrawGrids cbSetChecked true;
};

_cbDrawGrids ctrlAddEventHandler ["CheckedChanged",{
	params ["_ctrl","_state"];
	if (_state == 1) then {
		("TER_3den_RscGrids_layer" call BIS_fnc_rscLayer) cutRsc ["TER_RscDisplayGrids", "PLAIN"];
	} else {
		("TER_3den_RscGrids_layer" call BIS_fnc_rscLayer) cutRsc ["default", "PLAIN"];
	};
}];

// Teleport
//--TODO: Add indicator to the rscgrid with pos and distance and 3dicon?
_cbTeleport = _escapeMenu displayCtrl 7401;
if (!isNil {missionNamespace getVariable "TER_3den_teleportEH"}) then {
	_cbTeleport cbSetChecked true;
};

_cbTeleport ctrlAddEventHandler ["CheckedChanged",{
	params ["_control","_state"];
	if (_state == 1) then {
		_displayEH = (findDisplay 46) displayAddEventHandler ["KeyDown",{
			params ["_display","_key","_shift","_ctrl","_alt"];
			if (_key == 0x14 && _shift) then {
				_aimPos = [getPos cursorObject,screenToWorld [0.5,0.5]] select (isNull cursorObject);
				player setPos _aimPos;
			};
		}];
		missionNamespace setVariable ["TER_3den_teleportEH",_displayEH];
	} else {
		_displayEH = missionNamespace getVariable ["TER_3den_teleportEH",-1];
		(findDisplay 46) displayRemoveEventHandler ["KeyDown",_displayEH];
		missionNamespace setVariable ["TER_3den_teleportEH",nil];
	};
}];

// live debug
_btnLiveDebug = _escapeMenu displayCtrl 7402;
_btnLiveDebug ctrlAddEventHandler ["ButtonClick",{
	#define LIVE_DISPLAY (uiNamespace getVariable ["TER_3den_RscLiveWatch_display",displayNull])
	#define LIVE_WATCH(IDC) (LIVE_DISPLAY displayCtrl IDC)
	#define ESCAPE_MENU(IDC) ((findDisplay 49) displayCtrl IDC)
	disableSerialization;
	params ["_control","_state"];
	_fncWatchLoop = {
		params ["_inctrl"];
		_outCtrl = LIVE_WATCH((ctrlIDC _inctrl)+1);
		_startCommand = ctrlText _inctrl;
		while {_startCommand == ctrlText _inctrl} do {
			if (_startCommand == "") exitWith {_outCtrl ctrlSetText ""};
			if (isNil compile _startCommand) exitWith {_outCtrl ctrlSetText "#ERROR - NO VALUE"};
			_result = [] call compile _startCommand;
			//if (isNil {_result}) exitWith {_outCtrl ctrlSetText ""};
			_outCtrl ctrlSetText str _result;
			_curFrame = diag_frameno;
			waitUntil {diag_frameno != _curFrame};
		};
	};
	_state = isNull LIVE_DISPLAY;
	_ctrlIDCArray = [[7301,12285], [7303,12287], [7305,12289], [7307,12291]];
	_textChanged = {
		if (ctrlText LIVE_WATCH((_x select 0)) != ctrlText ESCAPE_MENU((_x select 1))) exitWith {true};
		false
	} forEach _ctrlIDCArray;
	if (_state OR _textChanged) then {
		if (_state) then {
			("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["TER_3den_RscLiveWatch","PLAIN"];
		};
		{
			_escInCommand = ctrlText ESCAPE_MENU((_x select 1));
			if (_escInCommand != ctrlText LIVE_WATCH((_x select 0))) then {
				LIVE_WATCH((_x select 0)) ctrlSetText _escInCommand;
				[LIVE_WATCH((_x select 0))] spawn _fncWatchLoop;
			};
		} forEach _ctrlIDCArray;
	} else {
		("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["default","PLAIN"];
	};
}];

// unit icons
_cbUnitIcons = _escapeMenu displayCtrl 7403;
if ((missionNamespace getVariable ["TER_3den_unitIcons3DMEH",-1]) != -1) then {
	_cbUnitIcons cbSetChecked true;
};

_cbUnitIcons ctrlAddEventHandler ["CheckedChanged",{
	params ["_checkbox","_state"];
	if (_state == 1) then {
		// draw icons
		_3dMEH = addMissionEventHandler ["Draw3D",{
			{
				_bbr = (boundingBoxReal _x) apply {_x apply {abs _x}};
				_absBBR = (_bbr select 0) vectorAdd (_bbr select 1);
				_center = [0,0,(_absBBR select 2)*1.2];
				_center = _x modelToWorld _center;
				_text = [typeOf _x, str _x] select (vehicleVarName _x != "");
				_color = switch (side _x) do {
					case west: { [0,0.3,0.6] };
					case east: { [0.5,0,0] };
					case independent: { [0,0.5,0] };
					case civilian: { [0.4,0,0.5] };
					default { [0.7,0.6,0] };
				};
				_alpha = linearConversion [1000,0,player distance _x,0,1];
				_color pushBack _alpha;
				drawIcon3D ["",_color,_center,0.5,0.5,0,_text];
			} forEach (allUnits +vehicles);
		}];
		missionNamespace setVariable ["TER_3den_unitIcons3DMEH",_3dMEH];
	} else {
		_3dMEH = missionNamespace getVariable ["TER_3den_unitIcons3DMEH",-1];
		removeMissionEventHandler ["Draw3D",_3dMEH];
		missionNamespace setVariable ["TER_3den_unitIcons3DMEH",nil];
	};
}];

// side player
_lbSideplayer = _escapeMenu displayCtrl 7404;
_sideArray = ["west","east","independent","civilian"];
_sideSystemArray = _sideArray apply {call compile _x};
{
	_lbSideplayer lbAdd _x;
} forEach _sideArray;
_lbSideplayer lbSetCurSel (_sideSystemArray find (side group player));
_lbSideplayer ctrlAddEventHandler ["LBSelChanged",{
	params ["_ctrl","_index"];
	_selectedSide = call compile (_ctrl lbText _index);
	if (_selectedSide == side player) exitWith {};
	_sideGroup = createGroup _selectedSide;
	[player] joinSilent _sideGroup;
}];

// target debug
#define DEBUG_TARGET_COMMANDS (uiNamespace getVariable ["TER_3den_targetDebugCommands",[]])
#define DEBUG_TARGET_COMMANDS_SET(VAR) uiNamespace setVariable ["TER_3den_targetDebugCommands",VAR];
_cbTargetDebug = _escapeMenu displayCtrl 7405;
if (!isNull (uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull])) then {
	_cbTargetDebug cbSetChecked true;
};
_cbTargetDebug ctrlAddEventHandler ["CheckedChanged",{
	params ["_ctrl","_state"];
	if (_state == 1) then {
		("TER_3den_RscTargetDebug_layer" call BIS_fnc_rscLayer) cutRsc ["TER_RscDisplayTargetDebug","PLAIN"];
		// spawn start
		[] spawn {
			_display = uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull];
			_stxtTargetDebug = _display displayCtrl 7300;
			_stxtPos = ctrlPosition _stxtTargetDebug;
			_fncNewLine = {
				params ["_lText","_rText"];
				_text = _text +format ["<t underline='true'>%1</t><br/>   %2<br/>",_lText,_rText];
			};
			// loop start
			while {!isNull _display} do {
				if (isNull cursorObject) then {
					_stxtPos set [3,0];
					_stxtTargetDebug ctrlSetPosition _stxtPos;
					_stxtTargetDebug ctrlCommit 0;
				} else {
					_text = "";
					{
						_command = _x;
						_result = call compile _command;
						[_command,str _result] call _fncNewLine;
					} forEach DEBUG_TARGET_COMMANDS;

					_stxtTargetDebug ctrlSetStructuredText parseText _text;
					_tHeight = ctrlTextHeight _stxtTargetDebug;
					_stxtPos set [3,_tHeight];
					_stxtTargetDebug ctrlSetPosition _stxtPos;
					_stxtTargetDebug ctrlCommit 0;

				};
				_curFrame = diag_frameno;
				waitUntil {_curFrame < diag_frameno};
			};
			// loop end
		};
		// spawn end
	} else {
		("TER_3den_RscTargetDebug_layer" call BIS_fnc_rscLayer) cutRsc ["default","PLAIN"];
	};
}];

// target debugging, add command
_btnTargetDebugAdd = _escapeMenu displayCtrl 7407;
_btnTargetDebugAdd ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_escapeMenu = findDisplay 49;
	_edCommand = _escapeMenu displayCtrl 7406;
	_command = ctrlText _edCommand;
	//-- TODO: add check, if nil exit
	if !(["cursorObject", _command] call BIS_fnc_inString) then {_command = _command +" cursorObject"};
	if (isNil compile _command) exitWith {_edCommand ctrlSettext "#ERROR - INVALID COMMAND"};
	// update global array
	_targetCommands = DEBUG_TARGET_COMMANDS;
	_prevCount = count _targetCommands;
	_targetCommands pushBackUnique _command;
	if (_prevCount == count _targetCommands) exitWith {};
	_lb_targetDebug_commands = _escapeMenu displayCtrl 7408;
	_lb_targetDebug_commands lbAdd _command;
	DEBUG_TARGET_COMMANDS_SET(_targetCommands)

	_edCommand ctrlSetText "";
	ctrlSetFocus _edCommand;
}];
// target debugging, listbox
_lb_targetDebug_commands = _escapeMenu displayCtrl 7408;
if (count DEBUG_TARGET_COMMANDS == 0) then {
	_startCommands = ["cursorObject","typeOf cursorObject"];
	{
		_lb_targetDebug_commands lbAdd _x;
	} forEach _startCommands;
	DEBUG_TARGET_COMMANDS_SET(_startCommands)
} else {
	{
		_lb_targetDebug_commands lbAdd _x;
	} forEach DEBUG_TARGET_COMMANDS;
};
_lb_targetDebug_commands ctrlAddEventHandler ["LBDblClick",{
	params ["_listbox","_index"];
	_command = _listbox lbText _index;
	_newCommandArray = DEBUG_TARGET_COMMANDS -[_command];
	DEBUG_TARGET_COMMANDS_SET(_newCommandArray)
	_listbox lbDelete _index;
}];


// add watch field
_btnAddWatch = _escapeMenu displayCtrl 7409;
_btnAddWatch ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	[] call TER_fnc_createWatchFields;
}];

// watch group
_escapeMenu displayRemoveAllEventHandlers "MouseButtonDown"; // thanks @Larrow!
_grpWatch = _escapeMenu displayCtrl 7410;
// load previous commands
{
	_newControls = ["create"] call TER_fnc_createWatchFields;
	_newControls params ["_edInput","_edOutput","_btnDelete"];
	_edInput ctrlSetText _x;
} forEach (profileNamespace getVariable ["TER_3den_watchCommands",[]]);
// -> save commands (code at the beginning)

// custom commands
#define FNC_CC_CREATE _newControl = _escapeMenu ctrlCreate ["TER_3den_RscCCGroup",-1,GRP_CC_COMMANDS];\
	_curPos = ctrlPosition _newControl;\
	_curPos set [1, (count CUR_CC_CONTROLS -1) * 1.1 * GUI_GRID_H];\
	_newControl ctrlSetPosition _curPos;\
	_newControl ctrlCommit 0;\
	_btnCCExec = _newControl controlsGroupCtrl 7493;\
	_edCCCode = _newControl controlsGroupCtrl 7494;\
	_btnCCDelete = _newControl controlsGroupCtrl 7495;\
\
	_btnCCExec setVariable ["TER_3den_codeControl",_edCCCode];\
	_btnCCExec ctrlAddEventHandler ["ButtonClick",{\
		params ["_button"];\
		_codeCtrl = _button getVariable ["TER_3den_codeControl",controlNull];\
		_locality = [-1,0,2] select lbCurSel COMBO_LOCALITY;\
		if (_locality > -1) then {\
			[[],compile ctrlText _codeCtrl] remoteExec ["call",_locality];\
		} else {\
			[] call compile ctrlText _codeCtrl;\
		};\
	}];\
	_btnCCDelete ctrlAddEventHandler ["ButtonClick",{\
		params ["_button"];\
\
		_thisGroup = ctrlParentControlsGroup _button;\
		_ccGroup = ctrlParentControlsGroup _thisGroup;\
		_allGroups = (allControls ESC_DISPLAY select {ctrlParentControlsGroup _x == _ccGroup});\
		_groupsLeft = _allGroups -[_thisGroup];\
		{\
			_curPos = ctrlPosition _x;\
			_yPos = _forEachIndex * 1.1 * GUI_GRID_H;\
			_curPos set [1,_yPos];\
			_x ctrlSetPosition _curPos;\
			_x ctrlCommit 0;\
		} forEach _groupsLeft;\
\
		ctrlDelete _thisGroup;\
	}];
// locality options:
{COMBO_LOCALITY lbAdd _x} forEach ["Local","Global","Server"];
COMBO_LOCALITY lbSetCurSel 0;
//if (!isMultiplayer) then { // will be added after testing
COMBO_LOCALITY ctrlEnable false;
COMBO_LOCALITY ctrlSetTooltip "WIP";
//};
// load previous
{
	FNC_CC_CREATE
	_edCCCode ctrlSetText _x;
} forEach (profileNamespace getVariable ["TER_3den_ccArray",[]]);

BTN_CC_ADD ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_escapeMenu = findDisplay 49;
	FNC_CC_CREATE
}];
// -> save commands, code at the start

//watch history
#define WATCH_HISTORY_ARRAY (profileNamespace getVariable ["TER_3den_watchHistory_array",[]])
// load previous
{
	_x ctrlAddEventHandler ["KillFocus",{
		params ["_edit"];
		_textEdit = ctrlText _edit;
		if (!isNil compile _textEdit) then {
			_historyArray = WATCH_HISTORY_ARRAY;
			reverse _historyArray;
			_historyArray pushBackUnique _textEdit;
			reverse _historyArray;
			if (count _historyArray > 20) then {_historyArray deleteRange [0,1]};
			profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
			saveProfileNamespace;
			lbClear LB_WATCHHISTORY;
			{LB_WATCHHISTORY lbAdd _x} forEach _historyArray;
		};
	}];
} forEach WATCH_IN_ARRAY;
// listbox with commands
{LB_WATCHHISTORY lbAdd _x} forEach WATCH_HISTORY_ARRAY;
LB_WATCHHISTORY ctrlAddEventHandler ["LBDblClick",{
	params ["_listbox","_index"];
	_command = _listbox lbText _index;
	_edInput = switch (lbCurSel COMBO_WATCHIN) do {
		case 1: {
			_emptyTextArray = WATCH_IN_ARRAY select {ctrlText _x == ""};
			reverse _emptyTextArray;
			if (count _emptyTextArray == 0) then {WATCH_IN_4} else {_emptyTextArray select 0};
		};
		case 2: {WATCH_IN_1};
		case 3: {WATCH_IN_2};
		case 4: {WATCH_IN_3};
		case 5: {WATCH_IN_4};
		default {
			_emptyTextArray = WATCH_IN_ARRAY select {ctrlText _x == ""};
			if (count _emptyTextArray == 0) then {WATCH_IN_1} else {_emptyTextArray select 0};
		};
	};
	_edInput ctrlSetText _command;
}];
// combo: which input
{
	_index = COMBO_WATCHIN lbAdd toUpper format ["Input: %1",_x];
	COMBO_WATCHIN lbSetTooltip [_index,"Select which Input should be chosen"];
} forEach ["First empty","Last empty",1,2,3,4];
COMBO_WATCHIN lbSetCurSel 0;

LB_WATCHHISTORY ctrlAddEventHandler ["KeyDown",{
	params ["_listbox","_key"];
	if (_key == DIK_DELETE) then {
		_command = _listbox lbText (lbCurSel _listbox);
		_historyArray = WATCH_HISTORY_ARRAY;
		_historyArray = _historyArray -[_command];
		profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
		_listbox lbDelete (lbCurSel _listbox);
	};

}];
/* maybe later
// max entries:
_maxEntries = uiNamespace getVariable ["TER_3den_maxEntries",25];
ED_MAXENTRIES ctrlSetText str 25;
_fncMaxHistoryEdit = {
	_this spawn {
		params ["_edit"];
		uisleep 0.01;
		_maxEntries = parseNumber ctrlText _edit;
		uiNamespace setVariable ["TER_3den_maxEntries",_maxEntries];
		lbClear LB_WATCHHISTORY;
		_historyArray = WATCH_HISTORY_ARRAY;
		if (count _historyArray > _maxEntries) then {_historyArray resize _maxEntries};
		{LB_WATCHHISTORY lbAdd _x} forEach _historyArray;
	};
};
ED_MAXENTRIES ctrlAddEventHandler ["Char",_fncMaxHistoryEdit];
[ED_MAXENTRIES] call _fncMaxHistoryEdit;
*/
// clear history:
BTN_CLEARHISTORY ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
		profileNamespace setVariable ["TER_3den_watchHistory_array",nil];
		lbClear LB_WATCHHISTORY;
}];

// btn clear chat:
BTN_CLEARCHAT ctrlAddEventHandler ["ButtonClick",{
	clearRadio;
}];

// combo gui grid
_ind = COMBO_GUIGRID lbAdd "---Default---";
COMBO_GUIGRID lbSetData [_ind,str []];
COMBO_GUIGRID lbSetTooltip [_ind,"Use default GUI Editor settings"];

_ind = COMBO_GUIGRID lbAdd "GUI_GRID";
_guigridArray = [
	[
		"safezoneX",
		"safezoneY + safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2)",
		"(safezoneW / safezoneH) min 1.2",
		"((safezoneW / safezoneH) min 1.2) / 1.2"
	],
	"((safezoneW / safezoneH) min 1.2) / 40",
	"(((safezoneW / safezoneH) min 1.2) / 1.2) / 25",
	"GUI_GRID"
];
COMBO_GUIGRID lbSetData [_ind,str _guigridArray];
COMBO_GUIGRID lbSetTooltip [_ind,"GUI_GRID: Based upon safeZone values"];

_uigridArray = [
	["safezoneX","safezoneY","safezoneW","safeZoneH"],
	"5 * 0.5 * pixelW * pixelGrid",
	"5 * 0.5 * pixelH * pixelGrid",
	"UI_GRID"
];
_ind = COMBO_GUIGRID lbAdd "UI_GRID";
COMBO_GUIGRID lbSetData [_ind,str _uigridArray];
COMBO_GUIGRID lbSetTooltip [_ind,"UI_GRID: Based upon pixelGrid values"];

COMBO_GUIGRID ctrlAddEventHandler ["LBSelChanged",{
	params ["_combo","_ind"];
	_data = call compile (_combo lbData _ind);
	uiNamespace setVariable ["TER_3den_GUIGrid", _data];
}];

_curGridVar = uiNamespace getVariable ["TER_3den_GUIGrid",[]];
_curGridInd = [[],_guigridArray,_uigridArray] find _curGridVar;
COMBO_GUIGRID lbSetCurSel _curGridInd;

if (isClass (configfile >> "CfgPatches" >> "TER_guigridfix")) then {
	COMBO_GUIGRID ctrlEnable false;
	COMBO_GUIGRID ctrlSetTooltip "Not compatible with @GUI_GRID Fix";
}; // disable if the gui editor is already overwritten with the GUI_GRID fix

// BIKI Links
_prevLinkText = profileNamespace getVariable ["TER_3den_links",""];
STXT_LINKS ctrlSetStructuredText parseText _prevLinkText;
STXT_LINKS ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight STXT_LINKS) max (6 * GUI_GRID_H)];
STXT_LINKS ctrlCommit 0;

BTN_LINKADD ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_command = ctrlText ED_LINK;
	if (_command == "#CLEAR") exitWith {
		profileNamespace setVariable ["TER_3den_links",""];
		saveProfileNamespace;
		STXT_LINKS ctrlSetStructuredText parseText "";
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
	saveProfileNamespace;
	STXT_LINKS ctrlSetStructuredText parseText _newLinkText;
	STXT_LINKS ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight STXT_LINKS) max (6 * GUI_GRID_H)];
	STXT_LINKS ctrlCommit 0;
}];

_tooltipArray = [
	"You can",
	"a) Add a command (case sensitive)",
	"b) Add a link",
	"c) Use ""#CLEAR"" to wipe the history",
	"d) Remove a link by adding the same link again"
];
ED_LINK ctrlSetTooltip (_tooltipArray joinString toString [10]);

////////////////////////END OF GROUP CONTROLS//////////////////////
// pages listbox:
#define XLB_PAGES ESC_CTRL(7399)
{XLB_PAGES lbAdd format ["- - - PAGE: %1/2 - - -",_x]} forEach [1,2];
XLB_PAGES setVariable ["TER_3den_xlbPagesInit",true];
XLB_PAGES ctrlAddEventHandler ["LBSelChanged",{
	params ["_ctrl","_index"];
	_isInit = XLB_PAGES getVariable ["TER_3den_xlbPagesInit",false];
	if (_isInit) then {_ctrl setVariable ["TER_3den_xlbPagesInit",false];};
	_allPages = [ESC_CTRL(73041),ESC_CTRL(73042)];
	_loadPageCtrl = ESC_CTRL(73041 +_index);
	{
		_curCtrlPos = ctrlPosition _x;
		if (_x == _loadPageCtrl) then { // appear
			_curCtrlPos set [0, 0.5 * GUI_GRID_W];
			_x ctrlSetPosition _curCtrlPos;
			_x ctrlCommit 0;
			_curCtrlPos set [0, 0.5 * GUI_GRID_W];
			_curCtrlPos set [2, 21 * GUI_GRID_W];
		} else { // disappear
			_curCtrlPos set [0, 21.5 * GUI_GRID_W];
			_curCtrlPos set [2, 0 * GUI_GRID_W];
		};
		_x ctrlSetPosition _curCtrlPos;
		_commit = [0.2,0] select _isInit;
		_x ctrlCommit _commit;
	} forEach _allPages;
	uiNamespace setVariable ["TER_3den_debugIndex",_index];
}];
XLB_PAGES lbSetCurSel (uiNamespace getVariable ["TER_3den_debugIndex",0]);


#include "ctrls.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"

waitUntil {!isNull ESC_DISPLAY};
{// execute all scripts which make the ui functional
	[] call compile preprocessFileLineNumbers format ["TER_Editing\gui\scripts\RscDebug\%1.sqf",_x];
} forEach [
	"BIKILinks",
	"customCommands",
	"grids",
	"liveDebug",
	"sidePlayer",
	"targetDebugV2",
	"teleport",
	"uiGrid",
	"unitIcons",
	"watchFields",
	"watchHistory",
	"switchUnit",
	"unitWatch",
	"escapeMenu"
];

disableSerialization;
params ["_control"];
if !([] call BIS_fnc_isDebugConsoleAllowed) exitWith {
	_control ctrlShow false;
	_control ctrlEnable false;
};// debug console disabled
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

// add eh to reset watch fields
#define HISTORY_GETVAR
#define SETVAR_FAVARRAY
{
	_x ctrlAddEventHandler ["KeyDown",{
		params ["_edit","_key","_shift","_ctrl","_alt"];
		if (_ctrl && _key == DIK_F) then {// STRG+F, add to favs
			_curCommand = ctrlText _edit;
			_curFavArray = uiNamespace getVariable ["TER_3den_favArray",[]];
			_curFavArray pushBackUnique _curCommand;
			uiNamespace setVariable ["TER_3den_favArray",_favArray];
		};
	}];
} forEach WATCH_IN_ARRAY;

// btn clear chat:
BTN_CLEARCHAT ctrlAddEventHandler ["ButtonClick",{
	clearRadio;
}];

// pages listbox:
{XLB_PAGES lbAdd _x} forEach [
"Other",
"More Watch Fields",
"Custom Commands",
"BIKI Links / Target Debug / Recent Watch Entries",
"Unit Live Watch"
];
XLB_PAGES setVariable ["TER_3den_xlbPagesInit",true];
XLB_PAGES ctrlAddEventHandler ["LBSelChanged",{
	params ["_ctrl","_index"];
	_isInit = XLB_PAGES getVariable ["TER_3den_xlbPagesInit",false];
	if (_isInit) then {_ctrl setVariable ["TER_3den_xlbPagesInit",false];};
	_pageCount = 5;
	_allPages = [];
	_allPages resize _pageCount;
	_curCount = 0;
	_allPages = _allPages apply {_curCount = _curCount +1; ESC_CTRL(73040 +_curCount)};
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

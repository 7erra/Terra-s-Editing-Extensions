#include "ctrls.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "\a3\ui_f\hpp\defineresincl.inc"
#define SELF "TER_Editing\gui\scripts\RscDebug.sqf"
#define FNCSELF TER_fnc_RscDebug_script

_mode = _this#0;
_this = _this#1;
_pageCount = 7;
_displayEscape = findDisplay 49;

switch _mode do {
case "onLoad":{
	params ["_control"];
	waitUntil {!isNull (findDisplay 49)};
	_displayEscape = findDisplay 49;
	if !([] call BIS_fnc_isDebugConsoleAllowed) exitWith {// debug console disabled
		_control ctrlShow false;
		_control ctrlEnable false;
	};
	if (getResolution select 5 > 0.7) exitWith {
		if !(uiNamespace getVariable ["TER_3den_uiSize2BigShown",false]) then {
			["The debug console is not made for UI sizes greater than Normal (Large, Very Large). The remaining space is just not enough.","@7erra's Editing Extension",false,"CONTINUE",_displayEscape] spawn BIS_fnc_GUImessage;
			uiNamespace setVariable ["TER_3den_uiSize2BigShown",true];
		};
		_control ctrlShow false;
		_control ctrlEnable false;
	};
	uiNamespace setVariable ["TER_3den_uiSize2BigShown",false];
	_displayEscape displayRemoveAllEventHandlers "MouseButtonDown";
	// global functions
	if (isNil {uiNamespace getVariable "TER_fnc_debugPage1"}) then {
		// compile functions
		for "_i" from 1 to _pageCount do {
			uiNamespace setVariable [format ["TER_fnc_debugPage%1_script",_i], compile preprocessFileLineNumbers format ["TER_Editing\gui\scripts\RscDebug\page%1.sqf",_i]];
		};
		uiNamespace setVariable ["TER_fnc_RscDebug_script",compile preprocessFileLineNumbers SELF];
	};
	// pages listbox:
	_lbPages = _control controlsGroupCtrl IDC_LB_PAGES;
	/* {_lbPages lbAdd _x} forEach [
		"General",
		"More Watch Fields",
		"Custom Commands",
		"BIKI Links / Target Debug / Saved Watch Entries",
		"Unit Live Watch",
		"KK Debug"
	]; */
	_lbPages setVariable ["TER_3den_xlbPagesInit",true];
	_lbPages ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["pagechange",_this] call FNCSELF;};
	}];
	_lastIndex = uiNamespace getVariable ["TER_3den_debugIndex",0];
	_lbPages lbSetCurSel _lastIndex;

	// escape menu EHs for restart and exit
	{(_displayEscape displayCtrl _x) ctrlShow false;} forEach [1000,1001];
	_displayEscape displayRemoveAllEventHandlers "MouseButtonDown";
	_displayEscape displayAddEventHandler ["KeyDown",{
		with uiNamespace do {["keydownesc",_this] call FNCSELF;};
	}];

	// Make control movable along x axis
	{
		_x params ["_grpIDC","_idc"];
		_grp = _displayEscape displayCtrl _grpIDC;
		_title = _grp controlsGroupCtrl _idc;
		_title ctrlAddEventHandler ["MouseButtonDown",{
			with uiNamespace do {["moveMouseDown", _this] call FNCSELF;};
		}];
		_title ctrlAddEventHandler ["MouseButtonUp",{
			with uiNamespace do {["moveMouseUp", _this] call FNCSELF;};
		}];
		_title ctrlAddEventHandler ["MouseMoving",{
			with uiNamespace do {["moveMouseMoving", _this] call FNCSELF;};
		}];
	} forEach [
		[IDC_DEBUG, IDC_BTN_TITLE], 
		[IDC_ESC_DEBUGCONSOLE, IDC_ESC_DEBUGTITLE]
	];
	// unload eh
	_displayEscape displayAddEventHandler ["unLoad",{
		with uiNamespace do {["unload",_this] call FNCSELF;};
	}];
};
case "moveMouseDown":{
	params["_title","","_xP","_yP","_shift","_btnCtrl","_alt"];
	_ctrl = ctrlParentControlsGroup _title;
    _ctrl setVariable ["mousedown",true];
    ctrlPosition _title params ["_xN","_yN"];
    _startOffset = [_xP - _xN, _yP - _yN];
    _ctrl setVariable ["mouseOffset", _startOffset];
};
case "moveMouseUp":{
    params ["_title"];
	_ctrl = ctrlParentControlsGroup _title;
    _ctrl setVariable ["mousedown", false];
};
case "moveMouseMoving":{
    params ["_title"];
	_ctrl = ctrlParentControlsGroup _title;
    if !(_ctrl getVariable ["mousedown",false]) exitWith {};
    params ["", "_xR", "_yR", "_moving"];
    _off = _ctrl getVariable ["mouseOffset", [0,0]];
    (_ctrl getVariable ["mouseOffset",[0,0]]) params ["_xN", "_yN"];
    _newX = (getMousePosition#0 - _xN) 
        min (safezonex + safezonew - ctrlPosition _ctrl #2)
        max (safezonex)
    ;
    _newY = ctrlPosition _ctrl #1;
    _ctrl ctrlSetPosition [_newX, _newY];
    _ctrl ctrlCommit 0;
	_saveVar = ["TER_EDITING_VANILLADEBUG_X", "TER_EDITING_DEBUGCONSOLE_X"] select (ctrlIDC _title == IDC_BTN_TITLE);
	_xp = ((ctrlPosition _ctrl # 0) - GUI_GRID_X) / GUI_GRID_W;
	profileNamespace setVariable [_saveVar, _xp];
    true
};
case "pagechange":{
	params ["_ctrl","_index"];
	_isInit = ((_displayEscape displayCtrl IDC_DEBUG) controlsGroupCtrl IDC_LB_PAGES) getVariable ["TER_3den_xlbPagesInit",false];
	if (_isInit) then {_ctrl setVariable ["TER_3den_xlbPagesInit",false];};
	_allPages = [];
	_allPages resize _pageCount;
	_curCount = 0;
	_allPages = _allPages apply {_curCount = _curCount +1; _displayEscape displayCtrl (IDC_DEBUG_PAGE_1 -1 +_curCount)};
	_loadPageCtrl = _displayEscape displayCtrl (IDC_DEBUG_PAGE_1 +_index);
	{
		_pagefnc = uiNamespace getVariable [format ["TER_fnc_debugPage%1_script",_foreachIndex+1],{}];
		_curCtrlPos = ctrlPosition _x;
		if (_x == _loadPageCtrl) then { // appear
			// load script
			["load",[]] call _pagefnc;
			_curCtrlPos set [0, 0.5 * GUI_GRID_W];
			_x ctrlShow true;
			_x ctrlSetPosition _curCtrlPos;
			_x ctrlCommit 0;
			_curCtrlPos set [0, 0.5 * GUI_GRID_W];
			_curCtrlPos set [2, 21 * GUI_GRID_W];
		} else { // disappear
			["hide",[]] call _pagefnc;
			_curCtrlPos set [0, 21.5 * GUI_GRID_W];
			_curCtrlPos set [2, 0 * GUI_GRID_W];
		};
		_x ctrlSetPosition _curCtrlPos;
		_commit = [0.2,0] select _isInit;
		_x ctrlCommit _commit;
	} forEach _allPages;
	//uiNamespace setVariable ["TER_3den_debugIndex",_index];
	TER_3den_debugIndex = _index;
};
case "keydownesc":{
	params ["_display","_key","_shift","_ctrl","_alt"];
	if (_key == DIK_R && _ctrl && !_shift) then { // restart
		_restartBtn = _display displayCtrl IDC_INT_REVERT;
		ctrlActivate _restartBtn;
	};
	if (_key == DIK_E && _ctrl) then { // exit
		_exitBtn = _display displayCtrl IDC_INT_ABORT;
		ctrlActivate _exitBtn;
	};
};
case "unload":{
	params ["_displayEscape"];
	//--- Escpape menu closed, activate unload ehs for pages
	for "_i" from 1 to _pageCount do {
		with uiNamespace do {["unload",[]] call call compile format ["TER_fnc_debugPage%1_script",_i]};
	};
	//--- save position of the debug consoles
	/* _control = _displayEscape displayCtrl IDC_DEBUG;
	_xp = ((ctrlPosition _control # 0) - GUI_GRID_X) / GUI_GRID_W;
	profileNamespace setVariable ["TER_EDITING_DEBUGCONSOLE_X", _xp];
	_vanillaCtrl = _displayEscape displayCtrl IDC_ESC_DEBUGCONSOLE;
	_xp = ((ctrlPosition _vanillaCtrl # 0) - GUI_GRID_X) / GUI_GRID_W;
	profileNamespace setVariable ["TER_EDITING_VANILLADEBUG_X", _xp]; */
	saveProfileNamespace;
};
};

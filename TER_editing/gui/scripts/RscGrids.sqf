#include "ctrls.inc"
params ["_mode", "_this"];
params ["_display"];
_prevDisplay = uiNamespace getVariable ["TER_3den_RscGrids_display",displayNull];
if (!isNull _prevDisplay) then {
	"TER_3den_RscGrids_layer" cutFadeOut 0;
};
uiNamespace setVariable ["TER_3den_RscGrids_display",_display];
//--- get current grid settings
_grid = uiNamespace getVariable ["TER_3den_GUIGrid",[]];
_grid params [
	["_xywhGrid",["0","0","1","1"]],
	["_wGrid","0.025"],
	["_hGrid","0.04"],
	["_gridVar","DEFAULT"]
];
if (_hGrid isEqualType "STRING") then {
	_hGrid = call compile _hGrid;
};
if (_wGrid isEqualType "STRING") then {
	_wGrid = call compile _wGrid;
};
_xywhGrid = _xywhGrid apply {if (_x isEqualType "") then {call compile _x} else {_x}};
_xywhGrid params ["_xG","_yG","_wG","_hG"];
//--- from anchor position to LEFT side of the screen (y, vertical lines)
for "_p" from (_xywhGrid#0) to safeZoneXAbs step -_wGrid do {
	_ctrlPos = [_p, safeZoneY, pixelW, safeZoneH];
	_line = _display ctrlCreate ["RscText",-1];
	_line ctrlSetPosition _ctrlPos;
	_line ctrlCommit 0;
	_line ctrlSetBackgroundColor [0,0,0,0.15];
};
//--- from anchor position to RIGHT side of the screen (y, vertical lines)
for "_p" from (_xywhGrid#0) to (safeZoneXAbs+safeZoneWAbs) step _wGrid do {
	_ctrlPos = [_p, safeZoneY, pixelW, safeZoneH];
	_line = _display ctrlCreate ["RscText",-1];
	_line ctrlSetPosition _ctrlPos;
	_line ctrlCommit 0;
	_line ctrlSetBackgroundColor [0,0,0,0.15];
};
//--- from anchor to TOP (x, horizontal lines)
for "_p" from (_xywhGrid#1) to (safeZoneY) step -_hGrid do {
	_ctrlPos = [safeZoneX, _p, safeZoneW, pixelH];
	_line = _display ctrlCreate ["RscText",-1];
	_line ctrlSetPosition _ctrlPos;
	_line ctrlCommit 0;
	_line ctrlSetBackgroundColor [0,0,0,0.15];
};
//--- from anchor to BOTTOM (x, horizontal lines)
for "_p" from (_xywhGrid#1) to (safeZoneY+safeZoneH) step _hGrid do {
	_ctrlPos = [safeZoneX, _p, safeZoneW, pixelH];
	_line = _display ctrlCreate ["RscText",-1];
	_line ctrlSetPosition _ctrlPos;
	_line ctrlCommit 0;
	_line ctrlSetBackgroundColor [0,0,0,0.15];
};
/*
//--- Draw safe area light green
_txtSafeArea = _display displayCtrl IDC_GRIDS_SAFEAREA;
_overX = GUI_GRID_WAbs - _wGrid * 40;
_xSafe = _xG - _overX/2;
_overY = GUI_GRID_HAbs - _hGrid * 25;
_ySafe = _yG - _overY/2;
_txtSafeArea ctrlSetPosition [_xSafe,_ySafe];
_txtSafeArea  ctrlCommit 0;
*/
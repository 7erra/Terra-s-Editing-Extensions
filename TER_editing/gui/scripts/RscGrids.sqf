#include "ctrls.inc"
params ["_display"];
uiNamespace setVariable ["TER_3den_RscGrids_display",_display];

{
	for "_i" from (0.5) to (safeZoneX + safeZoneW) step UI_GRID_W do {
		_newCtrl = _display ctrlCreate ["RscStructuredText",-1];
		_newCtrl ctrlSetPosition [
			_i,
			_x,
			UI_GRID_W,
			UI_GRID_H
		];
		_newCtrl ctrlCommit 0;
		_newCtrl ctrlSetStructuredText parseText format ["<t size='0.5'>%1</t>",((_i-0.5)/UI_GRID_W)+1];
	};
	for "_i" from (0.5 -UI_GRID_W) to (safeZoneX -UI_GRID_W) step -UI_GRID_W do {
		_newCtrl = _display ctrlCreate ["RscStructuredText",-1];
		_newCtrl ctrlSetPosition [
			_i,
			_x,
			2 * UI_GRID_W,
			UI_GRID_H
		];
		_newCtrl ctrlCommit 0;
		_newCtrl ctrlSetStructuredText parseText format ["<t size='0.5'>%1</t>",-(_i-0.5)/UI_GRID_W];
	};
} forEach [safeZoneY + (0.25 * safeZoneH),safeZoneY + (0.75 * safeZoneH)];
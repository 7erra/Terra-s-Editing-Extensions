#include "..\ctrls.inc"
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
// make default
if (isNil {uiNamespace getVariable "TER_3den_GUIGrid"}) then {
	uiNamespace setVariable ["TER_3den_GUIGrid", _uigridArray];
};
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
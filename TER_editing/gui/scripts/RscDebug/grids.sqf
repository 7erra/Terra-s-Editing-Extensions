#include "..\ctrls.inc"
// draw grids
_cbDrawGrids = CB_GRIDS;
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
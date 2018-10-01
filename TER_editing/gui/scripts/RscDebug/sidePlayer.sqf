#include "..\ctrls.inc"
// side player
_lbSideplayer = COMBO_SIDEPLAYER;
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
/*
	Author: 7erra

	Description:
	Removes the entire loadout from the selected unit. Has to be called from the context menu of the 3den Editor

	Parameter(s):
	none

	Returns:
	nothing
*/
collect3DENHistory {
	_selObj = get3DENSelected "object";
	clear3DENInventory _selObj;
	{
		_x setUnitLoadout [[],[],[],[],[],[],"","",[],["","","","","",""]];
	} foreach _selObj;
	save3DENInventory _selObj;
};
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
	clear3DENInventory (get3DENSelected "object");
	{
		_x setUnitLoadout [[],[],[],[],[],[],"","",[],["","","","","",""]];
	} foreach (get3DENSelected "object")
};
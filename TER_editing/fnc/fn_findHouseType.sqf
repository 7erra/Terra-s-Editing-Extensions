/*
	Author: 7erra
	Description: Find an object with the same classname on the map
		and display it with text and a 3D marker (via 3den)
	Params:
		<None>
	Returns:
		<Nothing>
	Example:
		call TER_fnc_findHouseType;
*/
_selObject = get3DENSelected "object";
if (count _selObject > 1) exitWith {["TER_msg_tooManySelected"] call BIS_fnc_3DENNotification};
_selObject = _selObject select 0;
_type = typeOf _selObject;
_centerPos = [worldSize/2,worldSize/2,0];
_buildings = _centerPos nearObjects [_type, worldSize*1.5];
_buildings = _buildings -[_selObject];
if (!isNil {missionNamespace getVariable "TER_3den_fncHouseType"}) then {
	// remove old vars
	(missionNamespace getVariable "TER_3den_fncHouseType") params [
		"_3dMarkerMEH_old",
		"_buildings_old",
		"_mrkArray_old"
	];
	// delete old 3d marker
	removeMissionEventHandler ["Draw3D",_3dMarkerMEH_old];
	// delete old markers
	{deleteMarker _x} forEach _mrkArray_old;
};
// exit if no objects were found
if (count _buildings == 0) exitWith {["TER_msg_noTypesFound"] call BIS_fnc_3DENNotification};
// 3d text
_3dMarkerMEH = addMissionEventHandler ["Draw3D",{
	_buildings = missionNamespace getVariable ["TER_3den_fncHouseType",[[],[],[]]];
	_buildings = _buildings select 1;
	{
		_alpha = 0 max (linearConversion [0,500,_x distance get3DENCamera,1,0]);
		drawIcon3D ["", [1,0,0,_alpha], _x modelToWorldVisual [0,0,0], 1, 1, 0, typeOf _x, 2];
	} forEach _buildings;
}];
// markers
_mrkArray = [];
{
	_mrk = createMarker [str _x, getPos _x];
	_mrk setMarkerShape "ICON";
	_mrk setMarkerType "mil_dot";
	_mrk setMarkerColor "ColorRed";
	_mrk setMarkerText _type;
	_mrkArray = _mrkArray +[_mrk];
} forEach _buildings;
missionNamespace setVariable ["TER_3den_fncHouseType",[_3dMarkerMEH,_buildings,_mrkArray]];

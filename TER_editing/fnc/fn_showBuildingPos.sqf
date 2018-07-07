scriptName "fn_showBuildingPos:";
/*
	Author: 7erra

	Description:
	Function called upon selecting a building in the 3den Editor and activating Right Click>>Log>>Show building positions

	Parameter(s):
	<none>

	Returns:
	<none>
*/
#define SELF _fnc_fn_showBuildingPos

// get selected object from 3den
_selObject = get3DENSelected "object";
if (count _selObject > 1) exitWith {["TER_msg_tooManySelected"] call BIS_fnc_3DENNotification};
_selObject = _selObject select 0;
//// remove old ones
// remove 3d marker:
_3DMEH_old = missionNamespace getVariable "TER_3den_buildingPos_3DMEH";
if (!isNil "_3DMEH_old") then {
	removeMissionEventHandler ["Draw3D",_3DMEH_old];
};
//// new ones
// find building positions
_allBuildingPos = _selObject buildingPos -1;
if (count _allBuildingPos == 0) then {["TER_msg_noBuildingPos"] call BIS_fnc_3DENNotification};
missionNamespace setVariable ["TER_3den_buildingPos_array",_allBuildingPos];
// 3dMarker
_3DMEH = addMissionEventHandler ["Draw3D",{
	_allBuildingPos = missionNamespace getVariable ["TER_3den_buildingPos_array",[]];
	{
		drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,0,1],_x,0.5,0.5,0,str _forEachIndex];
	} forEach _allBuildingPos;
}];
missionNamespace setVariable ["TER_3den_buildingPos_3DMEH",_3DMEH];

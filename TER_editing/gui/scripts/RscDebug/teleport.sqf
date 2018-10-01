#include "..\ctrls.inc"
// Teleport
//--TODO: Add indicator to the rscgrid with pos and distance and 3dicon?
_cbTeleport = CB_TELEPORT;
if (!isNil {missionNamespace getVariable "TER_3den_teleportEH"}) then {
	_cbTeleport cbSetChecked true;
};

_cbTeleport ctrlAddEventHandler ["CheckedChanged",{
	params ["_control","_state"];
	if (_state == 1) then {
		_displayEH = (findDisplay 46) displayAddEventHandler ["KeyDown",{
			params ["_display","_key","_shift","_ctrl","_alt"];
			if (_key == 0x14 && _shift) then {
				_aimPos = [getPos cursorObject,screenToWorld [0.5,0.5]] select (isNull cursorObject);
				player setPos _aimPos;
			};
		}];
		missionNamespace setVariable ["TER_3den_teleportEH",_displayEH];
	} else {
		_displayEH = missionNamespace getVariable ["TER_3den_teleportEH",-1];
		(findDisplay 46) displayRemoveEventHandler ["KeyDown",_displayEH];
		missionNamespace setVariable ["TER_3den_teleportEH",nil];
	};
}];
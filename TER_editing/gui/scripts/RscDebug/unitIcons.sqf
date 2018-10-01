#include "..\ctrls.inc"
// unit icons
_cbUnitIcons = CB_UNITICONS;
if ((missionNamespace getVariable ["TER_3den_unitIcons3DMEH",-1]) != -1) then {
	_cbUnitIcons cbSetChecked true;
};

_cbUnitIcons ctrlAddEventHandler ["CheckedChanged",{
	params ["_checkbox","_state"];
	if (_state == 1) then {
		// draw icons
		_3dMEH = addMissionEventHandler ["Draw3D",{
			{
				_bbr = (boundingBoxReal _x) apply {_x apply {abs _x}};
				_absBBR = (_bbr select 0) vectorAdd (_bbr select 1);
				_center = [0,0,(_absBBR select 2)*1.2];
				_center = _x modelToWorld _center;
				_text = [typeOf _x, str _x] select (vehicleVarName _x != "");
				_color = switch (side _x) do {
					case west: { [0,0.3,0.6] };
					case east: { [0.5,0,0] };
					case independent: { [0,0.5,0] };
					case civilian: { [0.4,0,0.5] };
					default { [0.7,0.6,0] };
				};
				_alpha = linearConversion [1000,0,player distance _x,0,1];
				_color pushBack _alpha;
				drawIcon3D ["",_color,_center,0.5,0.5,0,_text];
			} forEach (allUnits +vehicles);
		}];
		missionNamespace setVariable ["TER_3den_unitIcons3DMEH",_3dMEH];
	} else {
		_3dMEH = missionNamespace getVariable ["TER_3den_unitIcons3DMEH",-1];
		removeMissionEventHandler ["Draw3D",_3dMEH];
		missionNamespace setVariable ["TER_3den_unitIcons3DMEH",nil];
	};
}];
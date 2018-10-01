#include "..\ctrls.inc"
_removeArray = [];

{
	_x params ["_title","_array"];
	_selectedArray = _array -_removeArray;
	_treePath = TV_UNITWATCH tvAdd [[],format ["%1 (%2)",_title,count _selectedArray]];
	{
		_indexSubPath = TV_UNITWATCH tvAdd [[_treePath],format ["%1   -   %2",_x,(configFile >> "CfgVehicles" >> typeOf _x) call BIS_fnc_displayName]];
		_subPath = [_treePath,_indexSubPath];
		TV_UNITWATCH setVariable [format ["object_%1",_subPath],_x];
	} forEach _selectedArray;
	_removeArray = _removeArray +_array;
} forEach [
	["Players",allPlayers],
	["Units",allUnits],
	["Vehicles",entities [["AllVehicles"], []]],
	["Other",entities [[], []]]
];

#define _CAM TER_3den_unitWatchCamera
if (isNil "TER_3den_unitWatchCamera") then {
	_CAM = "camera" camCreate eyePos player;
	_CAM cameraEffect ["Internal", "Back", "ter_3den_unitrtt"];
	_CAM camSetTarget player;
	_relOffset = (sizeOf typeOf player)/2;
	_CAM attachTo [player,[0,-_relOffset,_relOffset/2]];
	_CAM camCommit 0;
};
TV_UNITWATCH ctrlAddEventHandler ["TreeSelChanged",{
	params ["_tree","_selectionPath"];
	_selectedObject = TV_UNITWATCH getVariable [format ["object_%1",_selectionPath],objNull];
	if (!isNull _selectedObject) then {
		_CAM camSetTarget _selectedObject;
		_relOffset = (sizeOf typeOf _selectedObject)/2;
		_CAM attachTo [_selectedObject,[0,-_relOffset,_relOffset/2]];
		_CAM cameraEffect ["Internal", "Back", "ter_3den_unitrtt"];
		_CAM camCommit 0;
	};
}];

if (!isNull PIC_LIVEFEEDLIVE) then {
	//CB_LIVEFEEDLIVE ctrlSetChecked true;
	CB_LIVEFEEDLIVE cbSetChecked true;
};
CB_LIVEFEEDLIVE ctrlAddEventHandler ["CheckedChanged",{
	params ["_checkbox", "_checked"];
	if (_checked == 0) then {
		if (!isNull PIC_LIVEFEEDLIVE) then {
			{ctrlDelete _x;} forEach [PIC_LIVEFEEDLIVE,FRAME_LIVEFEEDLIVE];
		};
	} else {
		_liveFeedControl = MISSION_DISPLAY ctrlCreate ["RscPicture",7429];
		_liveFeedFrame = MISSION_DISPLAY ctrlCreate ["RscFrame",7430];
		//_liveFeedFrame ctrlSetTextColor [0,1,0,1];
		_liveFeedFrame spawn {
			_liveFeedFrame = _this;
			while {!isNull _liveFeedFrame} do {
				_camTarget = camTarget _CAM;
				_liveFeedFrame ctrlSetText format [
					"%1   -   %2   -   %3",
					_camTarget,
					typeOf _camTarget,
					(configFile >> "CfgVehicles" >> typeOf _camTarget) call BIS_fnc_displayName
				];
				waitUntil {sleep 1; _camTarget != camTarget _CAM};
			};
		};
		ctrlPosition PIC_LIVEFEED params ["_xPos","_yPos","_wPos","_hPos"];
		_liveFeedControl ctrlSetPosition [
			(safeZoneX+SafezoneW) -_wPos,
			(safeZoneY+safeZoneH) -_hPos,
			_wPos,
			_hPos
		];
		_liveFeedFrame ctrlSetPosition [
			(safeZoneX+SafezoneW) -_wPos,// - 0.1 * GUI_GRID_W,
			(safeZoneY+safeZoneH) -_hPos,// - 0.3 * GUI_GRID_H,
			_wPos,// + 0.3 * GUI_GRID_W,
			_hPos// + 0.3 * GUI_GRID_H
		];
		{_x ctrlCommit 0;} forEach [_liveFeedControl, _liveFeedFrame];
		_liveFeedControl ctrlSetText ctrlText PIC_LIVEFEED;
	};
}];
#include "ctrls.inc"
#define DISABLE_ARRAY [BTN_ATTACHOBJECT,CB_MEMPOINTS,BTN_EXPORT]
#define SET_UI_VAR(VAR,VALUE) uiNamespace setVariable [VAR,VALUE]
#define UI_VAR(VAR) (uiNamespace getVariable VAR)
#define BASE_OBJECT (get3DENEntity UI_VAR("base_object"))
#define ATTACH_OBJECT (get3DENEntity UI_VAR("attach_object"))
// disable some controls which rely on each other
if (isNil {BASE_OBJECT}) then {
	BTN_ATTACHOBJECT ctrlEnable false;
};
if (isNil {ATTACH_OBJECT}) then {
	{_x ctrlEnable false;} forEach [CB_MEMPOINTS,BTN_EXPORT];
};
// close button
BTN_ATTACHCLOSE ctrlAddEventHandler ["ButtonClick",
{
	params ["_button"];
	ctrlDelete ctrlParentControlsGroup _button;
}];
// select base object
BTN_BASEOBJECT ctrlAddEventHandler ["ButtonClick",
{
	params ["_buttons"];
	_selectedObjects = get3DENSelected "object";
	if (count _selectedObjects != 1) exitWith {
		["Select 1 object!",1] call BIS_fnc_3DENNotification;
	};
	SET_UI_VAR("base_object",get3DENEntityID (_selectedObjects select 0));
	{// enable other controls:
		_x ctrlEnable true;
	} forEach DISABLE_ARRAY;
	// lb memory points
	lbClear LB_MEMPOINTS;
	{
		_ind = LB_MEMPOINTS lbAdd _x;
		LB_MEMPOINTS lbSetTooltip [_ind,_x];
	} forEach (["<NONE>"] +selectionNames BASE_OBJECT);
}];
// select attached object
BTN_ATTACHOBJECT ctrlAddEventHandler ["ButtonClick",
{
	params ["_buttons"];
	_selectedObjects = get3DENSelected "object";
	if (count _selectedObjects != 1) exitWith {
		["Select 1 object!",1] call BIS_fnc_3DENNotification;
	};
	SET_UI_VAR("attach_object",get3DENEntityID (_selectedObjects select 0));
}];
// cb, show mem points
CB_MEMPOINTS ctrlAddEventHandler ["CheckedChanged",
{
	params ["_checkbox","_state"];
	if (_state == 1) then
	{
		TER_3den_MEH3D_memPoints = addMissionEventHandler ["Draw3D",
		{
			{
				_memName = _x;
				_memPosRelative = BASE_OBJECT selectionPosition _x;
				if !(_memPosRelative isEqualTo [0,0,0]) then {
					_memPos = BASE_OBJECT modelToWorldVisual _memPosRelative;
					drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,0,1],_memPos,0.5,0.5,0,_memName];
				};
			} forEach selectionNames BASE_OBJECT;
		}];
	} else {
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_memPoints];
	};
}];
// lb mem points, eh to display position
LB_MEMPOINTS ctrlAddEventHandler ["LBSelChanged",{
	params ["_listbox","_ind"];
	if (!isNil "TER_3den_MEH3D_lbMemPoints") then {
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_lbMemPoints];
	};
	TER_3den_MEH3D_lbMemPoints = addMissionEventHandler ["Draw3D",{
		if (isNull ATTACH_DISPLAY) exitWith {};
		_memName = LB_MEMPOINTS lbText lbCurSel LB_MEMPOINTS;
		if (_memName == "<NONE>") exitWith {};
		_memPosRelative = BASE_OBJECT selectionPosition _memName;
		_memPosWorld = BASE_OBJECT modelToWorldVisual _memPosRelative;
		drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,0,1],_memPosWorld,0.5,0.5,0,_memName];
	}];
}];
// export button, copy commands to clipboard
BTN_EXPORT ctrlAddEventHandler ["ButtonClick",
{
	params ["_button"];
	_commandOffset = [
		format ["this attachTo [%1,%2];",typeOf BASE_OBJECT,ctrlText ED_OFFSET],
		format ["this attachTo [%1,%2,%3];",typeOf BASE_OBJECT, ctrlText ED_OFFSET, str (LB_MEMPOINTS lbText lbCurSel LB_MEMPOINTS)]
	] select (lbCurSel LB_MEMPOINTS > 0);
	_commandVector = format ["this setVectorDirAndUp %1;",ctrlText ED_VECTOR];
	_commandComplete = [_commandOffset,_commandVector] joinString toString [10];
	copyToClipboard _commandComplete;
	["Commands copied to clipboard"] call BIS_fnc_3DENNotification;
}];
// display loop, keep info up-to-date
#define OFFSET (BASE_OBJECT worldToModel (ATTACH_OBJECT modelToWorld [0,0,0]))
#define VECTOR_DIR_UP ([vectorDir ATTACH_OBJECT,vectorUp ATTACH_OBJECT])
[] spawn {
	if (!isNil {BASE_OBJECT}) then {
		// lb memory points
		lbClear LB_MEMPOINTS;
		{
			_ind = LB_MEMPOINTS lbAdd _x;
			LB_MEMPOINTS lbSetTooltip [_ind,_x];
		} forEach (["<NONE>"] +selectionNames BASE_OBJECT);
	};
	waitUntil {
		{!isNil _x} count [{ATTACH_OBJECT},{BASE_OBJECT}] == 2
		OR
		isNull ATTACH_DISPLAY
	};
	if (isNull ATTACH_DISPLAY) exitWith {};
	// add 3d eh to show center position for base object
	if (!isNil "TER_3den_MEH3D_baseObject") then
	{
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_baseObject];
	};
	TER_3den_MEH3D_baseObject = addMissionEventHandler ["Draw3D",{
		if (!isNil {BASE_OBJECT}) then {
			_memPos = BASE_OBJECT modelToWorldVisual [0,0,0];
			drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,1,1],_memPos,0.5,0.5,0,"BASE OBJECT"];
		};
	}];
	// add 3d eh to show center position
	if (!isNil "TER_3den_MEH3D_attachObject") then
	{
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_attachObject];
	};
	TER_3den_MEH3D_attachObject = addMissionEventHandler ["Draw3D",{
		if (!isNil {ATTACH_OBJECT}) then {
			_memPos = ATTACH_OBJECT modelToWorldVisual [0,0,0];
			drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,1,1],_memPos,0.5,0.5,0,"ATTACH OBJECT"];
		};
	}];
	// start loop
	while {!isNull ATTACH_DISPLAY} do
	{
		if (isNull ATTACH_DISPLAY OR isNil {BASE_OBJECT} OR isNil {ATTACH_OBJECT}) exitWith {};
		_offset = OFFSET;
		_txtOffset = if (lbCurSel LB_MEMPOINTS > 0) then {
			_attachPoint = BASE_OBJECT selectionPosition (LB_MEMPOINTS lbText lbCurSel LB_MEMPOINTS);
			_worldToModel = BASE_OBJECT worldToModel (ATTACH_OBJECT modelToWorld [0,0,0]);
			_offsetFromSelection = _worldToModel vectorDiff _attachPoint;
			_offsetFromSelection
		} else {
			OFFSET
		};
		_txtOffset = _txtOffset apply {parseNumber (_x toFixed 3)};
		ED_OFFSET ctrlSetText str _txtOffset;
		_vector = VECTOR_DIR_UP apply {_x apply {parseNumber (_x toFixed 3)}};
		ED_VECTOR ctrlSetText str _vector;

		_curOffset = OFFSET;
		_curVector = VECTOR_DIR_UP;
		waitUntil {
			isNull ATTACH_DISPLAY OR
			!(_curOffset isEqualTo OFFSET) OR
			!(VECTOR_DIR_UP isEqualTo _curVector)
		};
	};
	// control closed, remove all eh
	{
		if (!isNil _x) then {
			removeMissionEventHandler ["Draw3D",call compile _x];
		};
	} forEach ["TER_3den_MEH3D_memPoints","TER_3den_MEH3D_baseObject","TER_3den_MEH3D_attachObject","TER_3den_MEH3D_lbMemPoints"];
};
// reset control
{
	add3DENEventHandler [_x, {
		params ["_objects", "_groups", "_waypoints", "_markers"];
		ctrlDelete ATTACH_DISPLAY;
	}];
} forEach ["OnMissionPreview","OnMissionLoad","OnMissionNew","OnWorkspacePartSwitch"];

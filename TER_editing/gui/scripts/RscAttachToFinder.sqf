#include "ctrls.inc"
#define SELF TER_3den_RscAttachToFinder_script
_mode = _this#0;
_this = _this#1;
//--- Controls
_groupAttach = findDisplay 313 displayCtrl IDC_ATTACH_GROUP;
_btnSetBase = _groupAttach controlsGroupCtrl IDC_ATTACH_BTNSETBASE;
_btnSetAttached = _groupAttach controlsGroupCtrl IDC_ATTACH_BTNSETATTACHED;
_edOffset = _groupAttach controlsGroupCtrl IDC_ATTACH_EDOFFSET;
_cbMemPoints = _groupAttach controlsGroupCtrl IDC_ATTACH_CBMEMPOINTS;
_lbMemPoints = _groupAttach controlsGroupCtrl IDC_ATTACH_LBMEMPOINTS;
_edVector = _groupAttach controlsGroupCtrl IDC_ATTACH_EDVECTOR;
_btnClose = _groupAttach controlsGroupCtrl IDC_ATTACH_BTNCLOSE;
_btnExport = _groupAttach controlsGroupCtrl IDC_ATTACH_BTNEXPORT;

//--- General variables
_baseObject = get3DENEntity (uiNamespace getVariable "TER_3den_baseObjectID");
_attachedObject = get3DENEntity (uiNamespace getVariable "TER_3den_attachedObjectID");

switch _mode do {
case "onload":{
	_script = compile preprocessFileLineNumbers "\TER_Editing\gui\scripts\RscAttachToFinder.sqf";//---! MOD PATH;
	if (isNil "TER_3den_RscAttachToFinder_script") then {
		uiNamespace setVariable ["TER_3den_RscAttachToFinder_script", _script];
	};
	//--- Disable some controls which rely on each other
	if (isNil "_baseObject") then {
		_btnSetAttached ctrlEnable false;
	};
	if (isNil "_attachedObject") then {
		{_x ctrlEnable false;} forEach [_cbMemPoints,_btnExport];
	};
	//--- Close button
	_btnClose ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["unload",[]] call SELF};
	}];
	//--- Select base object
	_btnSetBase ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["btnsetbase",[]] call SELF};
	}];
	//--- Select attached object
	_btnSetAttached ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["btnsetattached",[]] call SELF};
	}];
	//--- CB, show mem points
	_cbMemPoints ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["drawmempoints",_this] call SELF};
	}];
	//--- LB mem points, eh to display position
	_lbMemPoints ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["lbmempointschanged",_this] call SELF};
	}];
	// export button, copy commands to clipboard
	_btnExport ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["export",_this] call SELF};
	}];
	//--- Display loop, keep info up-to-date
	["updateloop",[]] spawn _script;
	//--- Reset control
	add3DENEventHandler ["OnMissionPreview",{
		with uiNamespace do {["unload",[]] call SELF};
	}];
	{
		add3DENEventHandler [_x, {
			with uiNamespace do {["unload",[true]] call SELF};
		}];
	} forEach ["OnMissionLoad","OnMissionNew","OnWorkspacePartSwitch"];
};
case "btnsetbase":{
	_selectedObjects = get3DENSelected "object";
	if (count _selectedObjects != 1) exitWith {
		["Select one object!",1] call BIS_fnc_3DENNotification;
	};
	_newObject = _selectedObjects select 0;
	TER_3den_baseObjectID = get3DENEntityID _newObject;
	{// enable other controls:
		_x ctrlEnable true;
	} forEach [_btnSetAttached, _cbMemPoints, _btnExport];
	// lb memory points
	lbClear _lbMemPoints;
	{
		_ind = _lbMemPoints lbAdd _x;
		_lbMemPoints lbSetTooltip [_ind,_x];
	} forEach (["<NONE>"] +((selectionNames _newObject) select {!(_newObject selectionPosition _x isEqualTo [0,0,0])}));
	lbSort _lbMemPoints;
};
case "btnsetattached":{
	_selectedObjects = get3DENSelected "object";
	if (count _selectedObjects != 1) exitWith {
		["Select 1 object!",1] call BIS_fnc_3DENNotification;
	};
	if (isNil "TER_3den_attachedObjectID") then {
		["updateloop",[]] spawn _script;
	};
	_wasNil = isNil "TER_3den_attachedObjectID";
	TER_3den_attachedObjectID = get3DENEntityID (_selectedObjects select 0);
	if (_wasNil) then {
		// first time setup, loop isnt running yet
		["updateloop",[]] spawn SELF;
	};
};
case "drawmempoints":{
	params ["_checkbox","_state"];
	if (_state == 1) then
	{
		TER_3den_MEH3D_memPoints = addMissionEventHandler ["Draw3D",{
			with uiNamespace do {["3dmehmempoints",[]] call SELF;};
		}];
	} else {
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_memPoints];
		TER_3den_MEH3D_memPoints = nil;
	};
};
case "3dmehmempoints":{
	{
		_memName = _x;
		_memPosRelative = _baseObject selectionPosition _x;
		if !(_memPosRelative isEqualTo [0,0,0]) then {
			_memPos = _baseObject modelToWorldVisual _memPosRelative;
			drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,0,1],_memPos,0.5,0.5,0,_memName];
		};
	} forEach selectionNames _baseObject;
};
case "lbmempointschanged":{
	params ["_listbox","_ind"];
	if (!isNil "TER_3den_MEH3D_lbMemPoints") then {
		removeMissionEventHandler ["Draw3D",TER_3den_MEH3D_lbMemPoints];
		TER_3den_MEH3D_lbMemPoints = nil;
	};
	TER_3den_MEH3D_lbMemPoints = addMissionEventHandler ["Draw3D",{
		with uiNamespace do {["singlemempoint",[]] call SELF};
	}];
};
case "singlemempoint":{
	if (isNull _groupAttach) exitWith {};
	_memName = _lbMemPoints lbText lbCurSel _lbMemPoints;
	if (_memName == "<NONE>") exitWith {};
	_memPosRelative = _baseObject selectionPosition _memName;
	_memPosWorld = _baseObject modelToWorldVisual _memPosRelative;
	drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,0,1],_memPosWorld,0.5,0.5,0,_memName];
};
case "export":{
	_nameBase = typeOf _baseObject;
	_varName = _baseObject get3DENAttribute "name" select 0;
	if (_varName != "") then {_nameBase = _varName};
	_nameAttached = "this";
	_varName = _attachedObject get3DENAttribute "name" select 0;
	if (_varName != "") then {_nameAttached = _varName};

	_commandOffset = [
		format ["%1 attachTo [%2,%3];",_nameAttached,_nameBase ,ctrlText _edOffset],
		format ["%1 attachTo [%2,%3,""%4""];",_nameAttached, _nameBase, ctrlText _edOffset,  _lbMemPoints lbText lbCurSel _lbMemPoints]
	] select (lbCurSel _lbMemPoints > 0);
	_commandVector = format ["%1 setVectorDirAndUp %2;",_nameAttached,ctrlText _edVector];
	_commandComplete = [_commandOffset,_commandVector] joinString toString [10];
	copyToClipboard _commandComplete;
	["Commands copied to clipboard"] call BIS_fnc_3DENNotification;
};
case "updateloop":{
	if (isNil "_attachedObject") exitWith {};
	if (!isNil "_baseObject") then {
		// lb memory points
		lbClear _lbMemPoints;
		{
			_ind = _lbMemPoints lbAdd _x;
			_lbMemPoints lbSetTooltip [_ind,_x];
		} forEach (["<NONE>"] +((selectionNames _baseObject) select {!(_baseObject selectionPosition _x isEqualTo [0,0,0])}));
		lbSort _lbMemPoints;
	};
	waitUntil {
		{!isNil _x} count [{_attachedObject},{_baseObject}] == 2
		OR
		isNull _groupAttach
	};
	if (isNull _groupAttach) exitWith {};
	// add 3d eh to show center position for base object
	_meh3dBaseobj = uiNamespace getVariable "TER_3den_MEH3D_baseObject";
	if (!isNil "_meh3dBaseobj") then
	{
		removeMissionEventHandler ["Draw3D",_meh3dBaseobj];
	};
	_meh3dBaseobj = addMissionEventHandler ["Draw3D",{
		with uiNamespace do {["3dmehobjects",["base"]] call SELF;};
	}];
	uiNamespace setVariable ["TER_3den_MEH3D_baseObject",_meh3dBaseobj];
	// add 3d eh to show center position
	_meh3dAttachedobj = uiNamespace getVariable "TER_3den_MEH3D_attachedObject";
	if (!isNil "_meh3dAttachedobj") then
	{
		removeMissionEventHandler ["Draw3D",_meh3dAttachedobj];
	};
	_meh3dAttachedobj = addMissionEventHandler ["Draw3D",{
		with uiNamespace do {["3dmehobjects",["attached"]] call SELF;};
	}];
	uiNamespace setVariable ["TER_3den_MEH3D_attachedObject",_meh3dAttachedobj];
	//--- Start loop
	#define OFFSET (_baseObject worldToModel (_attachedObject modelToWorld [0,0,0]))
	#define VECTOR_DIR_UP ([vectorDir _attachedObject,vectorUp _attachedObject])
	while {!isNull _groupAttach} do
	{
		_attachedObject = get3DENEntity (uiNamespace getVariable "TER_3den_attachedObjectID");
		_baseObject = get3DENEntity (uiNamespace getVariable "TER_3den_baseObjectID");
		if (isNull _groupAttach OR isNil "_baseObject" OR isNil "_attachedObject") exitWith {};
		_offset = OFFSET;
		_txtOffset = if (lbCurSel _lbMemPoints > 0) then {
			_attachPoint = _baseObject selectionPosition (_lbMemPoints lbText lbCurSel _lbMemPoints);
			_worldToModel = _baseObject worldToModel (_attachedObject modelToWorld [0,0,0]);
			_offsetFromSelection = _worldToModel vectorDiff _attachPoint;
			_offsetFromSelection
		} else {
			OFFSET
		};
		_txtOffset = _txtOffset apply {parseNumber (_x toFixed 3)};
		_edOffset ctrlSetText str _txtOffset;
		_vector = VECTOR_DIR_UP apply {_x apply {parseNumber (_x toFixed 3)}};
		_edVector ctrlSetText str _vector;

		_curOffset = OFFSET;
		_curVector = VECTOR_DIR_UP;
		waitUntil {
			[
				isNull _groupAttach,
				!(_curOffset isEqualTo OFFSET),
				!(VECTOR_DIR_UP isEqualTo _curVector),
				!(VECTOR_DIR_UP isEqualTo _curVector),
				get3DENEntityID _baseObject != uiNamespace getVariable "TER_3den_baseObjectID",
				get3DENEntityID _attachedObject != uiNamespace getVariable "TER_3den_attachedObjectID"
			] findIf {_x} != -1;
		};
	};
};
case "3dmehobjects":{
	params ["_drawObj"];
	_text3d = ["BASE OBJECT","ATTACHED OBJECT"] select (_drawObj == "attached");
	_drawObj = [_baseObject,_attachedObject] select (_drawObj == "attached");
	if (!isNil {_drawObj}) then {
		_memPos = _drawObj modelToWorldVisual [0,0,0];
		drawIcon3D ["\A3\ui_f\data\map\markers\military\box_CA.paa",[1,0,1,1],_memPos,0.5,0.5,0,_text3d];
	};
};
case "unload":{
	params [["_fullPurge",false]];
	//--- Remove draw ehs
	{
		_var = format ["TER_3den_MEH3D_%1",_x];
		if (!isNil _var) then {
			removeMissionEventHandler ["Draw3D",call compile _var];
			[] call compile format ["%1 = nil;",_var];
		};
	} forEach ["memPoints","baseObject","attachedObject","lbMemPoints"];
	if (_fullPurge) then {
		//--- Delete all variables
		{uiNamespace setVariable [_x,nil]} forEach ["TER_3den_attachedObjectID","TER_3den_baseObjectID"];
	};
	ctrlDelete _groupAttach;
};
};
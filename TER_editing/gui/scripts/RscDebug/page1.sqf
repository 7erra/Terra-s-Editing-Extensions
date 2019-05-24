#include "..\ctrls.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"
#define SELF TER_fnc_debugPage1_script
#define PICDAY "\a3\3den\data\attributes\slidertimeday\sun_ca.paa"
#define PICNIGHT "\a3\3den\data\attributes\date\moon_full_ca.paa"
_mode = _this select 0;
_this = _this select 1;
//controls
_displayEscape = findDisplay 49;
_page1 = _displayEscape displayCtrl IDC_DEBUG_PAGE_1;
_btnLiveDebug = _page1 controlsGroupCtrl IDC_BTN_LIVEDEBUG;
_comboSide = _page1 controlsGroupCtrl IDC_COMBO_SIDEPLAYER;
_cbTeleport = _page1 controlsGroupCtrl IDC_CB_TELEPORT;
_cbUnitIcons = _page1 controlsGroupCtrl IDC_CB_UNITICONS;
_cbGrids = _page1 controlsGroupCtrl IDC_CB_GRIDS;
_cbEditorGrids = _page1 controlsGroupCtrl IDC_CB_GRIDSGUIEDITOR;
_comboGUIGrid = _page1 controlsGroupCtrl IDC_COMBO_GUIGRID;
_btnGridAnchor = _page1 controlsGroupCtrl IDC_BTN_GRIDANCHOR;
_btnGridExport = _page1 controlsGroupCtrl IDC_BTN_GRIDEXPORT;
_edGridXValue = _page1 controlsGroupCtrl IDC_ED_GRIDXVALUE;
_edGridYValue = _page1 controlsGroupCtrl IDC_ED_GRIDYVALUE;
_edGridWValue = _page1 controlsGroupCtrl IDC_ED_GRIDWVALUE;
_edGridHValue = _page1 controlsGroupCtrl IDC_ED_GRIDHVALUE;
_edGridVariable = _page1 controlsGroupCtrl IDC_ED_GRIDVARIABLE;
_btnClearChat = _page1 controlsGroupCtrl IDC_BTN_CLEARCHAT;
_btnSwitchUnit = _page1 controlsGroupCtrl IDC_BTN_SWITCHUNIT;
_picTimeSunrise = _page1 controlsGroupCtrl IDC_PIC_TIMESUNRISE;
_picTimeSunset = _page1 controlsGroupCtrl IDC_PIC_TIMESUNSET;
_comboTimeHour = _page1 controlsGroupCtrl IDC_COMBO_TIMEHOUR;
_comboTimeMinute = _page1 controlsGroupCtrl IDC_COMBO_TIMEMINUTE;
_btnGridSet = _page1 controlsGroupCtrl IDC_BTN_GRIDSET;

switch (_mode) do {
case "load":{
	if (_page1 getVariable ["pageInitialized",false]) exitWith {};
	_page1 setVariable ["pageInitialized",true];
	/* initalize controls */
	//--- PLAYER SIDE COMBO
	_sideArray = ["west","east","independent","civilian"];
	_sideSystemArray = _sideArray apply {call compile _x};
	{
		_ind = _comboSide lbAdd _x;
		_color = [_sideSystemArray#_forEachIndex] call BIS_fnc_sideColor;
		_comboSide lbSetColor [_ind, _color];
	} forEach _sideArray;
	_comboSide lbSetCurSel (_sideSystemArray find (side group player));
	_comboSide ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["sideplayer",_this] call SELF;};
	}];
	//--- TELEPORT CHECKBOX
	if (!isNil {missionNamespace getVariable "TER_3den_teleportEH"}) then {
		_cbTeleport cbSetChecked true;
	};
	_cbTeleport ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["teleport",_this] call SELF;};
	}];
	//--- UNIT ICONS CHECKBOX
	if ((missionNamespace getVariable ["TER_3den_unitIcons3DMEH",-1]) != -1) then {
		_cbUnitIcons cbSetChecked true;
	};
	_cbUnitIcons ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["uniticons",_this] call SELF;};
	}];
	//--- DRAW GRIDS CB
	if (!isNull (uiNamespace getVariable ["TER_3den_RscGrids_display",displayNull])) then {
		_cbGrids cbSetChecked true;
	};
	_cbGrids ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["grids",_this] call SELF;};
	}];
	//--- EDITOR GRIDS CB
	_cbEditorGrids ctrlSetTooltip "Draw the grid upon opening the GUI Editor (recommended)";
	_cbEditorGrids ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["editorgrids",_this] call SELF;};
	}];
	if (uiNamespace getVariable ["TER_3den_drawGridGUIEditor",true]) then {
		_cbEditorGrids cbSetChecked true;
	};
	//--- GUI GRID COMBO
	_ind = _comboGUIGrid lbAdd "---Custom---";
	_customGrid = [];
	_comboGUIGrid lbSetData [_ind,str _customGrid];

	/*
	_ind = _comboGUIGrid lbAdd "---Default---";
	_defaultGrid = ["0.025","0.04","GUI_GRID"];
	_comboGUIGrid lbSetData [_ind,str _defaultGrid];
	_comboGUIGrid lbSetTooltip [_ind,"Use default GUI Editor settings (broken)"];
	*/

	_ind = _comboGUIGrid lbAdd "GUI_GRID";
	_guigridArray = [
		"((safezoneW / safezoneH) min 1.2) / 40",
		"(((safezoneW / safezoneH) min 1.2) / 1.2) / 25",
		"GUI_GRID"
	];
	_comboGUIGrid lbSetData [_ind,str _guigridArray];
	_comboGUIGrid lbSetTooltip [_ind,"GUI_GRID: Based upon safeZone values"];

	_uigridArray = [
		"2.5 * pixelW * pixelGrid",
		"2.5 * pixelH * pixelGrid",
		"UI_GRID"
	];
	_ind = _comboGUIGrid lbAdd "UI_GRID";
	_comboGUIGrid lbSetData [_ind,str _uigridArray];
	_comboGUIGrid lbSetTooltip [_ind,"UI_GRID: Based upon pixelGrid values"];
	// make default
	if !(isNil {profileNamespace getVariable "TER_3den_GUIGrid"}) then {
		uiNamespace setVariable ["TER_3den_GUIGrid",profileNamespace getVariable "TER_3den_GUIGrid"];
	};
	if (isNil {uiNamespace getVariable "TER_3den_GUIGrid"}) then {
		uiNamespace setVariable ["TER_3den_GUIGrid", [["0.5","0.5","0","0"]] +_uigridArray];
	};

	_comboGUIGrid ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["guigrid",_this] call SELF;};
	}];

	_curGridVar = uiNamespace getVariable ["TER_3den_GUIGrid",[]];
	_curGridInd = [nil,_guigridArray,_uigridArray] find [_curGridVar#1,_curGridVar#2,_curGridVar#3];
	_curGridInd = _curGridInd max 0;
	_comboGUIGrid lbSetCurSel _curGridInd;

	if (isClass (configfile >> "CfgPatches" >> "TER_guigridfix")) then {
		// disable if the gui editor is already overwritten with the GUI_GRID fix
		_comboGUIGrid ctrlEnable false;
		_comboGUIGrid ctrlSetTooltip "Not compatible with @GUI_GRID Fix";
	};

	//--- Change anchor position button
	_btnGridAnchor ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["gridanchor",[]] call SELF;};
	}];
	//--- Set grid button
	_btnGridSet ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["gridset",[]] call SELF;};
	}];
	//--- Export grid button
	_btnGridExport ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["gridexport",[]] call SELF;};
	}];
	//--- CLEAR CHAT BUTTON
	_btnClearChat ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["clearchat",_this] call SELF;};
	}];
	//--- SWITCH UNIT BUTTON
	if (isMultiplayer) then {
		_btnSwitchUnit ctrlSetTooltip "WARNING: Switching the unit in MP will have serious consequences for the functionality of the mission. Read more on the BIKI: selectPlayer";
		_btnSwitchUnit ctrlSetTooltipColorText [1,0,0,1];
	};
	_btnSwitchUnit ctrlAddEventHandler ["ButtonDown",{
		with uiNamespace do {["switchunit",_this] call SELF;};
	}];
	//--- Change time
	(call BIS_fnc_sunriseSunsetTime) params ["_sunrise","_sunset"];
	_textSunrise = [_sunrise,"HH:MM"] call BIS_fnc_timeToString;
	_textSunset = [_sunset,"HH:MM"] call BIS_fnc_timeToString;
	_picTimeSunrise ctrlSetTooltip format ["Sunrise: %1", _textSunrise];
	_picTimeSunset ctrlSetTooltip format ["Sunset: %1", _textSunset];

	for "_i" from 0 to 59 do {
		_time = format ["%1%2", ["",0] select (_i<10), _i];
		if (_i <= 23) then {
			_texture = [PICNIGHT,PICDAY] select (_i > floor _sunrise && _i < ceil _sunset);
			_ind = _comboTimeHour lbAdd _time;
			_comboTimeHour lbSetPicture [_ind,_texture];
			if (date#3 == _i) then {_comboTimeHour lbSetCurSel _i};
		};
		_dayformat = date#3 + _i/60;
		_isDay = _dayformat > _sunrise && _dayformat < _sunset;
		_comboTimeMinute lbAdd _time;
		_comboTimeMinute lbSetPicture [_i, [PICNIGHT,PICDAY] select _isDay];
		if (date#4 == _i) then {_comboTimeMinute lbSetCurSel _i};
	};
	{
		_x ctrlAddEventHandler ["LBSelChanged",{
			with uiNamespace do {["changetime",_this] call SELF;};
		}];
	} forEach [_comboTimeHour,_comboTimeMinute];
};
case "sideplayer":{
	params ["_ctrl","_index"];
	_selectedSide = call compile (_ctrl lbText _index);
	if (_selectedSide == side player) exitWith {};
	_sideGroup = createGroup _selectedSide;
	[player] joinSilent _sideGroup;
};
case "teleport":{
	params ["_control","_state"];
	if (_state == 1) then {
		_displayEH = (findDisplay 46) displayAddEventHandler ["KeyDown",{
			params ["_display","_key","_shift","_ctrl","_alt"];
			if (_key == DIK_T && _shift) then {
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
};
case "uniticons":{
	params ["_ctrl","_state"];
	if (_state == 1) then {
		// draw icons
		_3dMEH = addMissionEventHandler ["Draw3D",{
			{
				_bbr = boundingBoxReal _x;
				_bbr deleteAt 2;
				_bbr = _bbr apply {_x apply {abs _x}};
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
};
case "grids":{
	params ["_ctrl","_state"];
	if (_state == 1) then {
		("TER_3den_RscGrids_layer" call BIS_fnc_rscLayer) cutRsc ["TER_RscDisplayGrids", "PLAIN"];
	} else {
		("TER_3den_RscGrids_layer" call BIS_fnc_rscLayer) cutRsc ["default", "PLAIN"];
	};
};
case "editorgrids":{
	params ["_control","_checked"];
	uiNamespace setVariable ["TER_3den_drawGridGUIEditor",_checked == 1];
};
case "guigrid":{
	params ["_combo","_ind"];
	_data = call compile (_combo lbData _ind);
	if (count _data == 0) exitWith {
		["gridupdate",[]] call SELF;
	};
	TER_3den_GUIGrid set [1,_data#0];
	TER_3den_GUIGrid set [2,_data#1];
	TER_3den_GUIGrid set [3,_data#2];
	["gridupdate",[]] call SELF;
};
case "gridanchor":{
	_displayEscape createDisplay "TER_3den_RscDisplayAnchor";
};
case "gridset":{
	TER_3den_GUIGrid set [0,
		[ctrlText _edGridXValue,ctrlText _edGridYValue, "0", "0"]
	];
	TER_3den_GUIGrid set [1,ctrlText _edGridWValue];
	TER_3den_GUIGrid set [2,ctrlText _edGridHValue];
	TER_3den_GUIGrid set [3,ctrlText _edGridVariable];
	_comboGUIGrid lbSetCurSel 0;
};
case "gridexport":{
	_var = ctrlText _edGridVariable;
	_copy = [
		format ["//--- %1", _var],
		format ["#define %1_X (%2)", _var, ctrlText _edGridXValue],
		format ["#define %1_Y (%2)", _var, ctrlText _edGridYValue],
		format ["#define %1_W (%2)", _var, ctrlText _edGridWValue],
		format ["#define %1_H (%2)", _var, ctrlText _edGridHValue]
	];
	_copy = _copy joinString toString[10];
	copyToClipboard _copy;
};
case "gridupdate":{
	_edGridXValue ctrlSetText (TER_3den_GUIGrid#0#0);
	_edGridYValue ctrlSetText (TER_3den_GUIGrid#0#1);
	_edGridWValue ctrlSetText (TER_3den_GUIGrid#1);
	_edGridHValue ctrlSetText (TER_3den_GUIGrid#2);
	_edGridVariable ctrlSetText (TER_3den_GUIGrid#3);
};
case "clearchat":{
	clearRadio;
};
case "switchunit":{
	params ["_button"];
	if (cursorObject isKindOf "MAN" && !isPlayer cursorObject) then {
		selectPlayer cursorObject;
	} else {
		[_button] spawn {
			_button = _this select 0;
			_button ctrlSetText "SWITCH UNIT - INVALID TARGET";
			_button ctrlSetTextColor [1,0,0,1];
			uisleep 1;
			_button ctrlSetText "SWITCH UNIT";
			_button ctrlSetTextColor [1,1,1,1];
		};
	};
};
case "changetime":{
	params ["_control","_ind"];
	_date = date;
	_date set [3, parseNumber(_comboTimeHour lbText (lbCurSel _comboTimeHour))];
	_date set [4, parseNumber(_comboTimeMinute lbText (lbCurSel _comboTimeMinute))];
	setDate _date;
	//--- update minute combo
	if (_control == _comboTimeHour) then {
		(date call BIS_fnc_sunriseSunsetTime) params ["_sunrise","_sunset"];
		for "_i" from 0 to 59 do {
			_dayformat = _date#3 + _i/60;
			_isDay = _dayformat > _sunrise && _dayformat < _sunset;
			_comboTimeMinute lbSetPicture [_i, [PICNIGHT,PICDAY] select _isDay];
		};
	};
};
case "unload":{
	//--- save variables
	if (_page1 getVariable ["pageInitialized",false]) then {
		profileNamespace setVariable ["TER_3den_GUIGrid",uiNamespace getVariable "TER_3den_GUIGrid"];
		saveProfileNamespace;
	};
};
};

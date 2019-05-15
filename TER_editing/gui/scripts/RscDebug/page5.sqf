#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage5
_mode = _this select 0;
_this = _this select 1;
//// CONTROLS
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_5;
_edSearch = _page controlsGroupCtrl IDC_ED_UWSEARCH;
_tvUnitList = _page controlsGroupCtrl IDC_TV_UWTREE;
_picLivefeed = _page controlsGroupCtrl IDC_PIC_UWLIVEFEED;
_cbToggleFeed = _page controlsGroupCtrl IDC_CB_UWLIVEFEEDLIVE;
_displayMission = findDisplay 46;
_picLiveLive = _displayMission displayCtrl IDC_PIC_UWLIVEFEEDLIVE;
_frameLivefeedLive = _displayMission displayCtrl IDC_FRAME_UWLIVEFEEDLIVE;
// general vars
_cam = missionNamespace getVariable ["TER_3den_unitWatchCamera",objNull];

switch (_mode) do {
case "load":{
	_picLivefeed ctrlSetText "#(argb,512,512,1)r2t(ter_3den_unitrtt,1.0)";
	if (_page getVariable ["pageInitialized",false]) exitWith {};
	_page setVariable ["pageInitialized",true];

	_removeArray = [];
	{
		_x params ["_title","_array"];
		_selectedArray = _array -_removeArray;
		_treePath = _tvUnitList tvAdd [[],format ["%1 (%2)",_title,count _selectedArray]];
		{
			_indexSubPath = _tvUnitList tvAdd [[_treePath],format ["%1   -   %2",_x,(configFile >> "CfgVehicles" >> typeOf _x) call BIS_fnc_displayName]];
			_subPath = [_treePath,_indexSubPath];
			_tvUnitList setVariable [format ["object_%1",_subPath],_x];
		} forEach _selectedArray;
		_removeArray = _removeArray +_array;
	} forEach [
		["Players",allPlayers],
		["Units",allUnits],
		["Vehicles",entities [["AllVehicles"], []]],
		["Other",entities [[], []]]
	];

	if (isNull _cam) then {
		_cam = "camera" camCreate eyePos player;
		_cam cameraEffect ["Internal", "Back", "ter_3den_unitrtt"];
		_cam camSetTarget player;
		_relOffset = (sizeOf typeOf player)/2;
		_cam attachTo [player,[0,-_relOffset,_relOffset/2]];
		_cam camCommit 0;
		missionNamespace setVariable ["TER_3den_unitWatchCamera",_cam];
	};
	_tvUnitList ctrlAddEventHandler ["TreeSelChanged",{
		with uiNamespace do {["unitchanged",_this] call SELF;};
	}];

	if (!isNull _picLiveLive) then {
		_cbToggleFeed cbSetChecked true;
	};
	_cbToggleFeed ctrlAddEventHandler ["CheckedChanged",{
		with uiNamespace do {["togglefeed",_this] call SELF;};
	}];
};
case "unitchanged":{
	params ["_tree","_selectionPath"];
	_selectedObject = _tvUnitList getVariable [format ["object_%1",_selectionPath],objNull];
	if (!isNull _selectedObject) then {
		_cam camSetTarget _selectedObject;
		_relOffset = (sizeOf typeOf _selectedObject)/2;
		_cam attachTo [_selectedObject,[0,-_relOffset,_relOffset/2]];
		_cam cameraEffect ["Internal", "Back", "ter_3den_unitrtt"];
		_cam camCommit 0;
	};
};
case "togglefeed":{
	params ["_checkbox", "_checked"];
	if (_checked == 0) then {
		if (!isNull _picLiveLive) then {
			{ctrlDelete _x;} forEach [_picLiveLive,_frameLivefeedLive];
		};
	} else {
		_picLiveLive = _displayMission ctrlCreate ["RscPicture",IDC_PIC_UWLIVEFEEDLIVE];
		_frameLivefeedLive = _displayMission ctrlCreate ["RscFrame",IDC_FRAME_UWLIVEFEEDLIVE];
		with uiNamespace do {["liveloop",[]] spawn SELF;};
		ctrlPosition _picLivefeed params ["_xPos","_yPos","_wPos","_hPos"];
		_picLiveLive ctrlSetPosition [
			(safeZoneX+SafezoneW) -_wPos,
			(safeZoneY+safeZoneH) -_hPos,
			_wPos,
			_hPos
		];
		_frameLivefeedLive ctrlSetPosition [
			(safeZoneX+SafezoneW) -_wPos,// - 0.1 * GUI_GRID_W,
			(safeZoneY+safeZoneH) -_hPos,// - 0.3 * GUI_GRID_H,
			_wPos,// + 0.3 * GUI_GRID_W,
			_hPos// + 0.3 * GUI_GRID_H
		];
		{_x ctrlCommit 0;} forEach [_picLiveLive, _frameLivefeedLive];
		_picLiveLive ctrlSetText ctrlText _picLivefeed;
	};
};
case "liveloop":{
	while {!isNull _frameLivefeedLive} do {
		_camTarget = camTarget _cam;
		_frameLivefeedLive ctrlSetText format [
			"%1   -   %2   -   %3",
			_camTarget,
			typeOf _camTarget,
			(configFile >> "CfgVehicles" >> typeOf _camTarget) call BIS_fnc_displayName
		];
		waitUntil {sleep 1; _camTarget != camTarget _cam};
	};
};
case "hide":{
	_picLivefeed ctrlSetText "";
};
};
/*
	Author: Terra

	Description:
	Handles the UI events of the New Config Viewer

	Parameter(s):
		0 (Optional):
			STRING - Mode in which to execute
		1 (Optional):
			ARRAY - Arguments for the mode
	Returns:
	ANYTHING, depending on mode
*/

#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "ctrls.inc"
#define SELF (uiNamespace getVariable ["TER_3den_RscConfigViewer73_script",{}])
params ["_mode","_this"];

switch _mode do {
	case "onLoad":{
		params ["_display"];
		//--- Init function
		if (isNil {uiNamespace getVariable "TER_3den_RscConfigViewer73_script"}) then {
			uiNamespace setVariable ["TER_3den_RscConfigViewer73_script", compile preprocessFileLineNumbers "\TER_Editing\gui\scripts\RscConfigViewer73.sqf"];
		};
		//--- Initialize Display
		_display displayAddEventHandler ["Unload",{
			["onUnload",_this] call SELF;
		}];
		_display displayAddEventHandler ["KeyDown",{
			["displayKey",_this] call SELF;
		}];
		//--- Directory Listbox
		_btnDirectory = _display displayCtrl IDC_CONFIG_BTNDIRECTORY;
		_btnDirectory ctrlAddEventHandler ["ButtonClick",{
			["dirUp",_this] call SELF;
		}];
		//--- Search edit configs
		_edSearchConfigs = _display displayCtrl IDC_CONFIG_EDCONFIGSEARCH;
		ctrlSetFocus _edSearchConfigs;
		_edSearchConfigs ctrlAddEventHandler ["KeyDown",{
			["keySearch",_this] spawn SELF;
		}];
		_btnEndConfigSearch = _display displayCtrl IDC_CONFIG_BTNENDCONFIGSEARCH;
		_btnEndConfigSearch ctrlAddEventHandler ["ButtonClick",{
			["endConfigSearch",_this] call SELF;
		}];
		//--- Listbox configs
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_lbConfigs ctrlAddEventHandler ["LBDblClick",{
			["configsDblClick",_this] call SELF;
		}];
		_lbConfigs ctrlAddEventHandler ["LBSelChanged",{
			["configChange",_this] call SELF;
		}];
		_lbConfigs ctrlAddEventHandler ["KeyDown",{
			["lbConfigsKey",_this] call SELF;
		}];
		//--- Favorite button
		// [[["configfile","CfgWeapons"],["currentweapon vehicle cameraon"]],[["configfile","CfgMagazines","30Rnd_556x45_Stanag"],"30Rnd_556x45_Stanag"],[["configfile","CfgVehicles","B_Soldier_F"],"B_Soldier_F"],[["configfile","CfgVehicles","Land_Laptop_unfolded_F"],"Land_Laptop_unfolded_F"]]
		// [["configfile","CfgVehicles","Land_Laptop_unfolded_F"],"Land_Laptop_unfolded_F"]
		_btnFavorite = _display displayCtrl IDC_CONFIG_BTNFAVOR;
		_btnFavorite ctrlAddEventHandler ["ButtonClick",{
			["toggleFavorite",_this] call SELF;
		}];
		//--- Favorite combo
		_lbFavorites = _display displayCtrl IDC_CONFIG_LBFAVORITES;
		["fillFavorites",[_display]] call SELF;
		_lbFavorites ctrlAddEventHandler ["LBSelChanged",{
			["changeFavorite",_this] call SELF;
		}];
		//--- View mode toolbox
		_toolViewMode = _display displayCtrl IDC_CONFIG_TOOLVIEW;
		_toolViewMode ctrlAddEventHandler ["ToolBoxSelChanged",{
			["changeView",_this] call SELF;
		}];
		//--- Inheritance toolbox
		_toolInheritance = _display displayCtrl IDC_CONFIG_TOOLINHERITANCE;
		_toolInheritance ctrlAddEventHandler ["ToolBoxSelChanged",{
			["changeInheritance",_this] call SELF;
		}];
		//--- Show classes toolbox
		_toolShowClasses = _display displayCtrl IDC_CONFIG_TOOLSHOWCLASSES;
		_toolShowClasses lbSetCurSel 1;
		_toolShowClasses ctrlAddEventHandler ["ToolBoxSelChanged",{
			["changeShowClasses",_this] call SELF;
		}];
		//--- Property search
		_edPropertySearch = _display displayCtrl IDC_CONFIG_EDPROPERTYSEARCH;
		_edPropertySearch ctrlAddEventHandler ["KeyDown",{
			["edPropSearchKeyDown",_this] spawn SELF;
		}];
		//--- Properties listbox
		_lbProperties = _display displayCtrl IDC_CONFIG_LBPROPERTIES;
		_lbProperties ctrlAddEventHandler ["LBSelChanged",{
			["changeProperty",_this] call SELF;
		}];
		_lbProperties ctrlAddEventHandler ["LBDblClick",{
			["doubleClickProperties", _this] call SELF;
		}];
		_lbProperties ctrlAddEventHandler ["KeyDown",{

		}];
		//--- Error message
		_stxtError = _display displayCtrl IDC_CONFIG_STXTERROR;
		_stxtError ctrlAddEventHandler ["KillFocus",{
			["errorHide",_this] call SELF;
		}];
		_stxtError ctrlAddEventHandler ["MouseButtonDown",{
			["errorHide",_this] call SELF;
		}];
		//--- Info box
		_btnInfoOpen = _display displayCtrl IDC_CONFIG_BTNOPENINFO;
		_btnInfoOpen ctrlAddEventHandler ["ButtonClick",{
			["openInfo",ctrlParent (_this#0)] call SELF;
		}];
		_grpInfo = _display displayCtrl IDC_CONFIG_GRPINFO;
		_btnInfoOk = _display displayCtrl IDC_CONFIG_BTNINFOOK;
		_btnInfoOk ctrlAddEventHandler ["ButtonClick",{
			["infoClose",[ctrlParentControlsGroup (_this#0)]] call SELF;
		}];
		_stxtInfo = _display displayCtrl IDC_CONFIG_STXTINFO;
		_stxtInfo ctrlSetStructuredText parseText call compile loadFile "\TER_Editing\gui\scripts\RscConfigViewer73\info.sqf";
		//--- Load previous config
		_cfgArray = +(profilenamespace getvariable ["BIS_fnc_configviewer_path",[]]);
		_cfgSelected = profilenamespace getvariable ["BIS_fnc_configviewer_selected",""];
		_display setVariable ["_cfgArray",_cfgArray];
		["updateClasses",[_display, _cfgSelected]] spawn SELF;
	};
	case "lbConfigsKey":{
		params ["_lbConfigs", "_key", "_shift", "_ctrl", "_alt"];
		if (_ctrl && _key == DIK_C) exitWith {
			private _selClass = _lbConfigs lbText lbCurSel _lbConfigs;
			copyToClipboard _selClass;
			_lbConfigs ctrlSetFade 0.8;
			_lbConfigs ctrlCommit 0;
			_lbConfigs ctrlSetFade 0;
			_lbConfigs ctrlCommit 0.5;
			true
		};
		false
	};
	case "openInfo":{
		params ["_display"];
		_grpInfo = _display displayCtrl IDC_CONFIG_GRPINFO;
		_btnInfoOk = _display displayCtrl IDC_CONFIG_BTNINFOOK;
		_grpInfo ctrlShow true;
		ctrlSetFocus _grpInfo;
	};
	case "infoClose":{
		params ["_grpInfo"];
		_grpInfo ctrlShow false;
	};
	case "displayKey":{
		params ["_display", "_key", "_shift", "_ctrl", "_alt"];
		_progLoading = _display displayCtrl IDC_CONFIG_PROGLOADING;
		_isLoading = progressPosition _progLoading != 1;
		if (_ctrl && _shift && _key == DIK_F) exitWith {
			ctrlSetFocus (_display displayCtrl IDC_CONFIG_EDPROPERTYSEARCH);
			true
		};
		if (_ctrl && _key == DIK_F && !_isLoading) exitWith {
			ctrlSetFocus (_display displayCtrl IDC_CONFIG_EDCONFIGSEARCH);
			true
		};
		if (_ctrl && _key == DIK_Q && !_isLoading) then {
			["dirUp",[_display displayCtrl IDC_CONFIG_BTNDIRECTORY]] call SELF;
			true
		};
		if (false && _ctrl && _key == DIK_C) exitWith {
			_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
			_selClass = _lbConfigs lbText lbCurSel _lbConfigs;
			copyToClipboard _selClass;
		};
		if (_key == DIK_ESCAPE) exitWith {
			_grpInfo = _display displayCtrl IDC_CONFIG_GRPINFO;
			if (ctrlShown _grpInfo) exitWith {
				_grpInfo ctrlShow false;
				true
			};
			false
		};
		false
	};
	case "doubleClickProperties":{
		//--- Double click to preview entry
		params ["_lbProperties","_ind"];
		_display = ctrlParent _lbProperties;
		_data = _lbProperties lbData _ind;
		_cfgArray = +(_display getVariable ["_cfgArray",[]]);
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_selClass = _lbConfigs lbText lbCurSel _lbConfigs;
		_cfgArray append [_selClass];
		_cfgConfig = [_cfgArray] call BIS_fnc_configPath;
		_propCfg = _cfgConfig >> _data;
		private _handled = false;
		if (isClass _propCfg) exitWith {
			//--- Load class
			_display setVariable ["_cfgArray",_cfgArray];
			["updateClasses",[_display, _data]] call SELF;
		};
		if (isArray _propCfg) then {
			private _value = getArray _propCfg;
			if ({_x isEqualType 0} count _value in [3,4]) then {
				//--- Color RGB or RGBA
				uiNamespace setVariable ["TER_3den_RscColorPicker_loadColor", _value];
				_grpColorPicker = _display ctrlCreate ["TER_3den_RscColorPicker_control", IDC_COLOR_DISPLAYCTRL];
				ctrlSetFocus _grpColorPicker;
				_handled = true;
			};
		};
		if (isText _propCfg) then {
			private _value = getText _propCfg;
			if (_value select [count _value -4, count _value -1] in [".jpg", ".paa"]) then {
				//--- Texture
				private _msg = image _value;
				_msg setAttributes ["size","10","align","center"];
				[
					composeText [_msg],
					[_propCfg, "STRING"] call BIS_fnc_configPath,
					true,
					false,
					_display,
					true
				] spawn BIS_fnc_guiMessage;
				_handled = true;
			};
		};
		if (_handled) exitWith {};
		//--- No special config, display entry as text?

	};
	case "edPropSearchKeyDown":{
		//--- Key was pressed while search is focused
		params ["_edPropertySearch"];
		_filter = ctrlText _edPropertySearch;
		if (_filter == _edPropertySearch getVariable ["prevSearch",""]) exitWith {};
		_edPropertySearch setVariable ["prevSearch",_filter];
		_display = ctrlParent _edPropertySearch;
		_lbProperties = _display displayCtrl IDC_CONFIG_LBPROPERTIES;
		["updateProperties",[_display]] call SELF;
	};
	case "updateProperties":{
		params ["_display"];
		//--- LB view
		_lbProperties = _display displayCtrl IDC_CONFIG_LBPROPERTIES;
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_edPropertySearch = _display displayCtrl IDC_CONFIG_EDPROPERTYSEARCH;
		_toolInheritance = _display displayCtrl IDC_CONFIG_TOOLINHERITANCE;
		_toolShowClasses = _display displayCtrl IDC_CONFIG_TOOLSHOWCLASSES;
		private _ind = lbCurSel _lbConfigs;
		_selConfig = _lbConfigs lbText _ind;
		if (_selConfig == "") exitWith {lbClear _lbProperties};
		_cfgArray = _display getVariable ["_cfgArray",[]];
		_newConfig = if (count _cfgArray == 0) then {
			call compile (_lbConfigs lbText _ind)
		} else {
			_cfgConfig = [_cfgArray] call BIS_fnc_configPath;
			_cfgName = _lbConfigs lbText _ind;
			_cfgConfig >> _cfgName
		};
		_includeInherit = lbCurSel _toolInheritance == 0;
		_condFilter = ["true","!isClass _x"] select (lbCurSel _toolShowClasses == 1);
		_properties = configProperties[_newConfig, _condFilter, _includeInherit];
		_filter = toLower ctrlText _edPropertySearch;
		_propertieNames = _properties apply {configName _x};
		_propertieNames sort true;
		lbClear _lbProperties;
		{
			_alpha = 1;
			_c = 0.4;
			_cfgProp = _newConfig >> _x;
			_paramsLB = switch true do {
				case (isText _cfgProp): {[
					str getText _cfgProp, // value
					[1,_c,_c,_alpha] // color
				]};
				case (isNumber _cfgProp):{[
					getNumber _cfgProp,
					[_c,1,_c,_alpha]
				]};
				case (isArray _cfgProp):{
					//--- Arrays need some more love
					private _strArray = str getArray _cfgProp;
					[
					_strArray select [1, count _strArray -2],
					[_c,_c,1,_alpha],
					"%1[] = {%2};"
				]};
				case (isClass _cfgProp):{[
					_x,
					[1,_c,1,_alpha],
					"class %1 {...};"
				]};
			};
			private _entry = format[_paramsLB param [2, "%1 = %2;"], _x, _paramsLB#0];
			if (_filter in toLower _entry) then {
				private _ind = _lbProperties lbAdd _entry;
				_lbProperties lbSetColor [_ind, _paramsLB#1];
				_lbProperties lbSetData [_ind, _x];
			};
		} forEach _propertieNames;
		//lbSort _lbProperties;
	};
	case "onUnload":{
		params ["_display", "_exitCode"];
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_cfgArray = _display getVariable ["_cfgArray",[]];
		_cfgSelected = _lbConfigs lbText lbCurSel _lbConfigs;
		if (_cfgSelected == "" && count _cfgArray > 0) then {
			_cfgSelected = _cfgArray deleteAt (count _cfgArray -1);
		};
		if (_cfgSelected == "") exitWith {};
		if (count _cfgArray == 0) then {
			_cfgArray = [_cfgSelected];
		};
		profileNamespace setVariable ["BIS_fnc_configviewer_path",_cfgArray];
		profilenamespace setvariable ["BIS_fnc_configviewer_selected",_cfgSelected];
	};
	case "changeProperty":{
		params ["_lbProperties","_ind"];
		_display = ctrlParent _lbProperties;
		["updateEdCfgPath",[_display]] call SELF;
		_edPropValue = _display displayCtrl IDC_CONFIG_EDPROPVALUE;
		_edPropValue ctrlSetText (_lbProperties lbText _ind);
	};
	case "changeShowClasses":{
		params ["_toolShowClasses","_ind"];
		_display = ctrlParent _toolShowClasses;
		["updateProperties",[_display]] call SELF;
	};
	case "changeInheritance":{
		params ["_toolInheritance","_ind"];
		_display = ctrlParent _toolInheritance;
		["updateProperties",[_display]] call SELF;
	};
	case "changeFavorite":{
		params ["_lbFavorites","_ind"];
		if (
			!isNil {_lbFavorites getVariable "update"} OR
			lbCurSel _lbFavorites == -1
		) exitWith {};
		_display = ctrlParent _lbFavorites;
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_cfgString = _lbFavorites lbText _ind;
		_cfgArray = [_cfgString, []] call BIS_fnc_configPath;
		_cfgSelected = _cfgArray deleteAt (count _cfgArray -1);
		_display setVariable ["_cfgArray",_cfgArray];
		["updateClasses",[_display, _cfgSelected]] spawn SELF;
	};
	case "errorHide":{
		params ["_stxtError"];
		_stxtError ctrlSetFade 1;
		_stxtError ctrlSetPositionH 0;
		_stxtError ctrlCommit 0;
	};
	case "toggleFavorite":{
		params ["_btnFavorite"];
		_display = ctrlParent _btnFavorite;
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_lbFavorites = _display displayCtrl IDC_CONFIG_LBFAVORITES;
		_iconPath = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\";
		_favIcon = _iconPath +"mp_serverlike_ca.paa";
		_normalIcon = _iconPath +"mp_serverempty_ca.paa";
		_cfgArray = +(_display getVariable ["_cfgArray",[]]);
		if (lbCurSel _lbConfigs > -1) then {
			_cfgArray pushBack (_lbConfigs lbText lbCurSel _lbConfigs);
		};
		_cfgString = [_cfgArray, "STRING"] call BIS_fnc_configPath;
		_currentFavorites = profileNamespace getVariable ["BIS_fnc_configviewer_bookmarks",[]];
		//[[["configfile","CfgWeapons"],["currentweapon vehicle cameraon"]],[["configfile","CfgMagazines","30Rnd_556x45_Stanag"],"30Rnd_556x45_Stanag"],[["configfile","CfgVehicles","B_Soldier_F"],"B_Soldier_F"],[["configfile","CfgVehicles","Land_Laptop_unfolded_F"],"Land_Laptop_unfolded_F"]]
		if (ctrlText _btnFavorite == _normalIcon) then {
			//--- Add to favorites
			_btnFavorite ctrlSetText _favIcon;
			_currentFavorites pushBack [_cfgArray, _cfgArray#((count _cfgArray) -1)];
			_lbFavorites setVariable ["update",false];
			private _ind = _lbFavorites lbAdd _cfgString;
			_lbFavorites lbSetCurSel _ind;
			_lbFavorites setVariable ["update",nil];
		} else {
			//--- Remove from favorites
			_btnFavorite ctrlSetText _normalIcon;
			_lbFavorites setVariable ["update",false];
			_currentFavorites deleteAt (lbCurSel _lbFavorites);
			lbClear _lbFavorites;
			_lbFavorites lbSetCurSel -1;
			["fillFavorites",[_display]] call SELF;
			_lbFavorites setVariable ["update",nil];
		};
		profileNamespace setVariable ["BIS_fnc_configviewer_bookmarks",_currentFavorites];
		saveProfileNamespace;
	};
	case "configChange":{
		//--- New config selected from list
		params ["_lbConfigs","_ind"];
		_display = ctrlParent _lbConfigs;
		["updateProperties", [_display]] call SELF;
		_currentFavorites = +(profileNamespace getVariable ["BIS_fnc_configviewer_bookmarks",[]]);
		_currentFavorites = _currentFavorites apply {(_x#0) apply {toLower _x}};
		_cfgArray = +(_display getVariable ["_cfgArray",[]]);
		_cfgArray pushBack (_lbConfigs lbText _ind);
		_cfgArray = _cfgArray apply {toLower _x};
		_lbFavorites = _display displayCtrl IDC_CONFIG_LBFAVORITES;
		_lbFavorites setVariable ["update",false];
		_favInd = _currentFavorites find _cfgArray;
		if (_favInd < 0) then {
			//--- Stupid workaround to select non existing favorite
			lbClear _lbFavorites;
			_lbFavorites lbSetCurSel _favInd;
			["fillFavorites",[_display]] call SELF;
		} else {
			_lbFavorites lbSetCurSel _favInd;
		};
		_lbFavorites setVariable ["update",nil];
		_favIcon = [
			"\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\mp_serverempty_ca.paa",
			"\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\mp_serverlike_ca.paa"
		] select (_cfgArray in _currentFavorites);
		_btnFavorite = _display displayCtrl IDC_CONFIG_BTNFAVOR;
		_btnFavorite ctrlSetText _favIcon;
		["updateEdCfgPath",[_display]] call SELF;
		_lbProperties = _display displayCtrl IDC_CONFIG_LBPROPERTIES;
		_lbProperties lbSetCurSel -1;
	};
	case "fillFavorites":{
		params ["_display"];
		_lbFavorites = _display displayCtrl IDC_CONFIG_LBFAVORITES;
		//_lbFavorites lbAdd "";
		lbClear _lbFavorites;
		_currentFavorites = +(profileNamespace getVariable ["BIS_fnc_configviewer_bookmarks",[]]);
		_currentFavorites apply {
			_path = _x#0;
			_strPath = [_path, "STRING"] call BIS_fnc_configPath;
			_ind = _lbFavorites lbAdd _strPath;
		};
	};
	case "endConfigSearch":{
		params ["_btnEndConfigSearch"];
		_display = ctrlParent _btnEndConfigSearch;
		_edSearchConfigs = _display displayCtrl IDC_CONFIG_EDCONFIGSEARCH;
		_edSearchConfigs ctrlSetText "";
		["updateClasses",[_display]] spawn SELF;
	};
	case "updateClasses":{
		params ["_display",["_selectClass",""],["_allowLoading",true]];
		//--- Start loading screen
		//_grpLoading = _display displayCtrl IDC_CONFIG_GRPLOADING;
		_progLoading = _display displayCtrl IDC_CONFIG_PROGLOADING;
		_stxtProgress = _display displayCtrl IDC_CONFIG_STXTPROGRESS;
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_fncLoad = {
			params ["_enable"];
			{
				private _ctrl = _display displayCtrl _x;
				_ctrl ctrlEnable _enable;
			} forEach
			[
				IDC_CONFIG_BTNDIRECTORY,
				//IDC_CONFIG_EDCONFIGSEARCH,
				IDC_CONFIG_LBCONFIGS,
				IDC_CONFIG_LBFAVORITES
			];
			//_grpLoading ctrlShow !_enable;
		};
		if (_allowLoading) then {
			_stxtProgress ctrlSetStructuredText parseText "";
			[false] call _fncLoad;
			_progLoading progressSetPosition 0;
			//ctrlSetFocus _grpLoading;
		};
		//--- Variables
		_cfgArray = _display getVariable ["_cfgArray",[]];
		_cfgString = [_cfgArray, "STRING"] call BIS_fnc_configPath;
		_cfgConfig = [_cfgArray] call BIS_fnc_configPath;
		/* _cachedConfigs = uiNamespace getVariable ["TER_fnc_RscConfigViewer73_cache",[]];
		_cachedConfigsString = _cachedConfigs apply {_x#0};
		_cacheIndCfg = _cachedConfigsString find _cfgString; */
		/* private _classes = if (
			_cacheIndCfg > -1 &&
			!(_cfgConfig in [missionConfigFile,campaignConfigFile])
		) then {
			//--- Config has already been loaded onces
			(_cachedConfigs#_cacheIndCfg)#1
		} else {
			//--- Config has to be loaded and cached
			_subClasses = (configProperties [_cfgConfig, "isClass _x", true]) apply {configName _x};
			_cachedConfigs pushBack [_cfgString, _subClasses];
			uiNamespace setVariable ["TER_fnc_RscConfigViewer73_cache",_cachedConfigs];
			_subClasses
		}; */
		private _classes = if (count _cfgArray == 0) then {
			//--- The most upper part of the cfg hirarchy
			["configFile","missionConfigFile","campaignConfigFile"];
		} else {
			(configProperties [_cfgConfig, "isClass _x", true]) apply {configName _x};
		};
		_edSearchConfigs = _display displayCtrl IDC_CONFIG_EDCONFIGSEARCH;
		_btnDirectory = _display displayCtrl IDC_CONFIG_BTNDIRECTORY;
		_filter = ctrlText _edSearchConfigs;
		_classes = _classes select {toLower _filter in toLower _x};
		_classes sort true;
		private _countClasses = count _classes;
		lbClear _lbConfigs;
		private _foundInd = false;
		_exit = false;
		{
			if (
				isNull _display OR
				_filter != ctrlText _edSearchConfigs
			) exitWith {_exit = true};
			_ind = _lbConfigs lbAdd _x;
			_subPath = _cfgConfig >> _x;
			if (_lbConfigs lbText _ind == _selectClass) then {
				_lbConfigs lbSetCurSel _ind;
				_foundInd = true;
			};
			//--- Detect subclasses
			_hasSubclasses = false;
			_parents = [_subPath] call bis_fnc_returnparents;
			{
				for "_s" from 0 to (count _x - 1) do {
					if (isclass (_x select _s)) exitwith {_hasSubclasses = true;_s = count _x;};
				};
				if (_hasSubclasses) exitwith {};
			} foreach _parents;
			if (_hasSubclasses) then {
				_lbConfigs lbSetTextRight [_ind, "+"];
			};
			if (_allowLoading) then {
				_stxtProgress ctrlSetStructuredText parseText format ["(%1 / %2)",_forEachIndex +1, _countClasses];
				_progLoading progressSetPosition ((_forEachIndex +1)/_countClasses);
			};
		} forEach _classes;
		if (_exit) exitWith {};
		if (!_foundInd) then {_lbConfigs lbSetCurSel 0};
		//--- End loading screen
		if (_allowLoading) then {
			_stxtProgress ctrlSetStructuredText parseText "READY";
			[true] call _fncLoad;
		};
		if (count _cfgArray == 0) then {
			//--- The most upper part of the cfg hirarchy
			_btnDirectory ctrlSetText "(Default directory)";
			_btnDirectory ctrlEnable false;
		} else {
			_btnDirectory ctrlEnable true;
			_btnDirectory ctrlSetText format ["< %1", _cfgArray select (count _cfgArray -1)];
		};
	};
	case "configsDblClick":{
		params ["_lbConfigs","_ind"];
		_display = ctrlParent _lbConfigs;
		_entry = _lbConfigs lbText _ind;
		_cfgArray = _display getVariable ["_cfgArray",[]];
		_cfgConfig = if (count _cfgArray == 0) then {
			[[_entry]]
		} else {
			[_cfgArray +[_entry]]
		} call BIS_fnc_configPath;
		if (count configProperties [_cfgConfig, "isClass _x", true] == 0) exitWith {
			//--- Don't open configs without subclasses
			["showError",[_display, "The selected config has no sub classes."]] call SELF;
		};
		_edSearchConfigs = _display displayCtrl IDC_CONFIG_EDCONFIGSEARCH;
		_edSearchConfigs ctrlSetText "";
		_cfgArray pushBack _entry;
		_display setVariable ["_cfgArray", _cfgArray];
		["updateClasses",[_display]] spawn SELF;
		/* _lbConfigs lbSetCurSel -1; */
	};
	case "showError":{
		params ["_display","_errorMessage"];
		_stxtError = _display displayCtrl IDC_CONFIG_STXTERROR;
		_errorMessage = "<t size='1.25'>ERROR</t><br/>" +_errorMessage;
		_stxtError ctrlSetFade 0;
		_stxtError ctrlSetStructuredText parseText _errorMessage;
		_stxtError ctrlSetPosition getMousePosition;
		_stxtError ctrlSetPositionH ctrlTextHeight _stxtError;
		_stxtError ctrlCommit 0;
		ctrlSetFocus _stxtError;
	};
	case "keySearch":{
		params ["_edSearchConfigs","_key"];
		//if !(_key in [DIK_NUMPADENTER, DIK_RETURN]) exitWith {};
		_filter = ctrlText _edSearchConfigs;
		if (_filter == _edSearchConfigs getVariable ["prevSearch",""]) exitWith {false};
		_edSearchConfigs setVariable ["prevSearch",_filter];
		_display = ctrlParent _edSearchConfigs;
		//_edSearchConfigs ctrlEnable false;
		["updateClasses",[_display, nil, true]] call SELF;
		//_edSearchConfigs ctrlEnable true;
		//ctrlSetFocus _edSearchConfigs;
		false
	};
	case "dirUp":{
		params ["_btnDirectory"];
		_display = ctrlParent _btnDirectory;
		_edSearchConfigs = _display displayCtrl IDC_CONFIG_EDCONFIGSEARCH;
		_edSearchConfigs ctrlSetText "";
		_cfgArray = _display getVariable ["_cfgArray",[]];
		_cfgClass = _cfgArray deleteAt (count _cfgArray -1);
		_display setVariable ["_cfgArray",_cfgArray];
		_loadClass = _cfgArray param [count _cfgArray -1, -1];
		["updateClasses",[_display, _cfgClass]] spawn SELF;
	};
	case "updateEdCfgPath":{
		params ["_display"];
		_edCfgPath = _display displayCtrl IDC_CONFIG_EDCFGPATH;
		_cfgArray = +(_display getVariable ["_cfgArray",[]]);
		_lbConfigs = _display displayCtrl IDC_CONFIG_LBCONFIGS;
		_class = _lbConfigs lbText lbCurSel _lbConfigs;
		if (_class != "") then {
			_cfgArray pushBack _class;
		};
		_lbProperties = _display displayCtrl IDC_CONFIG_LBPROPERTIES;
		_prop = _lbProperties lbData lbCurSel _lbProperties;
		if (_prop != "") then {
			_cfgArray pushBack _prop;
		};
		_cfgString = [_cfgArray, "STRING"] call BIS_fnc_configPath;
		_edCfgPath ctrlSetText _cfgString;
	};
};

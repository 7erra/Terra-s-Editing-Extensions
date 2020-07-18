params [["_mode", ""]];
_fncRecursiveClasses = {
	params["_cfg", "_collectionArray"];
	_fncUnique = {
		params["_cfg", "_arr"];
		!((toLower configName _cfg) in (_arr apply {toLower configName _x}))
	};
	//--- Handle the subclasses, such as scrollbar etc.
	_subClasses  = configProperties[_cfg, "isClass _x", false];
	_subClasses apply {
		private _parent = inheritsFrom _x;
		[_x, _collectionArray] call _fncRecursiveClasses;
		if (
			!isNull _parent &&
			{!(_parent in _subClasses)} &&
			{[parent, _collectionArray] call _fncUnique} &&
			{isClass(configFile >> configName _parent)}
		) then {
			_collectionArray pushBackUnique _parent;
		};
	};
	//--- Handle the parents
	private _p = inheritsFrom _cfg;
	if (
		!isNull _p && 
		{([_p, _collectionArray] call _fncUnique)} &&
		{isClass(configFile >> configName _p)}
	) then {
		[_p, _collectionArray] call _fncRecursiveClasses;
		_collectionArray pushBackUnique _p;
	};
};

_ctrlcfgCond = "isNumber(_x>>'type')";
_ctrlcfgCond = _ctrlcfgCond +(switch toLower _mode do {
	case "a3":{
		"&& toLower configName _x select [0,3] == 'rsc'"
	};
	case "3den":{
		"&& toLower configName _x select [0,4] == 'ctrl'"
	};
	case "withmods":{
		""
	};
	case "default":{
		format["&& toLower configName _x in %1", [
			"Scrollbar",
			"RscObject",
			"RscText",
			"RscFrame",
			"RscLine",
			"RscProgress",
			"RscPicture",
			"RscPictureKeepAspect",
			"RscVideo",
			"RscHTML",
			"RscButton",
			"RscShortcutButton",
			"RscEdit",
			"RscCombo",
			"RscListBox",
			"RscListNBox",
			"RscXListBox",
			"RscTree",
			"RscSlider",
			"RscXSliderH",
			"RscActiveText",
			"RscActivePicture",
			"RscActivePictureKeepAspect",
			"RscStructuredText",
			"RscToolbox",
			"RscControlsGroup",
			"RscControlsGroupNoScrollbars",
			"RscControlsGroupNoHScrollbars",
			"RscControlsGroupNoVScrollbars",
			"RscButtonTextOnly",
			"RscButtonMenu",
			"RscButtonMenuOK",
			"RscButtonMenuCancel",
			"RscButtonMenuSteam",
			"RscMapControl",
			"RscMapControlEmpty",
			"RscCheckbox"
		] apply {toLower _x}];
	};
	default {
		//--- ALL Vanilla
		"&& {configSourceMod _x == ''}"
	};
});

_cfgCtrlArray = _ctrlcfgCond configClasses configFile;

_collectionArray = [];
_cfgCtrlArray apply {
	[_x, _collectionArray] call _fncRecursiveClasses;
	_collectionArray pushBackUnique _x;
};
_collectionArray = _collectionArray apply {
	[_x] call TER_fnc_configToString;
};
_returnString = _collectionArray joinString endl;

//--- Okay, see, I tried "regex"ing the config with sqf but boy oh boy.
//--- I am going for the Python regex now. Hours wasted again.
//[_returnString] call TER_fnc_regexUIConfigMacros;

copyToClipboard _returnString;
_returnString
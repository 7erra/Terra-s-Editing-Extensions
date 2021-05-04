params ["_displayName"];
// Recompile functions
diag_log parseText "### Recompiling of TER_Editing functions started ###";
"true" configClasses (configFile >> "CfgFunctions" >> "TER") apply {
	_path = getText(_x >> "file");
	"true" configClasses _x apply {
		_name = format["TER_fnc_%1", configName _x];

		_file = [
			format["p%1\fn_%2.sqf", _path, configName _x],
			format["p%1", getText(_x >> "file")]
		] select isText(_x >> "file");
		if (fileExists _file) then {
			diag_log parseText format[
				"Recompiling ""%1"" (from ""%2"")",
				_name,
				_file
			];
			missionNamespace setVariable [
				_name,
				compile preprocessFileLineNumbers _file
			];
		} else {
			diag_log parseText format[
				"ERROR while recompiling ""%1"" (from ""%2""), file does not exist!",
				_name,
				_file
			];
		};
	};
};

// Recompile display functions
diag_log parseText "### Recompiling display functions to uiNamespace ###";
"getText(_x >> 'scriptPath') == 'TER_Editing'" configClasses configFile apply {
	private _name = getText (_x >> "scriptName");
	private _file = format["p\TER_Editing\gui\scripts\%1.sqf", _name];
	diag_log parseText format ["Recompiling ""%1"" (from ""%2"")", _name, _file];
	uiNamespace setVariable [
		format ["%1_script", _name],
		compile preprocessFileLineNumbers _file
	];
};

// Enable editing of Python code
if !(isNil "py3_fnc_callExtension") then {
	["pythia.enable_reloader", [True]] call py3_fnc_callExtension;
};

// Merge config.cpp
_cfg = "P:\Terra-s-Editing-Extensions\TER_editing\config.cpp";
diag_log parseText format ["MERGING: ""%1""", _cfg];
diag_mergeConfigFile [_cfg];

//findDisplay 49 createDisplay "";
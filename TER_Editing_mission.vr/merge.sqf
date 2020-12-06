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
				"Recompiling %1 (from %2)",
				_name,
				_file
			];
			missionNamespace setVariable [
				_name,
				compile preprocessFileLineNumbers _file
			];
		} else {
			diag_log parseText format[
				"ERROR while recompiling %1 (from %2",
				_name,
				_file
			];
		};
	};
};

_cfg = "P:\Terra-s-Editing-Extensions\TER_editing\config.cpp";
diag_log parseText format ["MERGING: %1", _cfg];
diag_mergeConfigFile [_cfg];
["pythia.enable_reloader", [True]] call py3_fnc_callExtension;



/* {uiNamespace setVariable _x} forEach [
	["TER_3den_RscDisplay3denViewRPT_script",
	compile preprocessFileLineNumbers "p\TER_editing\gui\scripts\TER_3den_RscDisplay3denViewRPT.sqf"]
];

findDisplay 49 createDisplay "TER_3den_RscDisplay3denViewRPT"; */
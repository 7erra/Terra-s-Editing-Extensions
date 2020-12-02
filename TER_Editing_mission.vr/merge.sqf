_cfg = "P:\Terra-s-Editing-Extensions\TER_editing\config.cpp";
diag_log parseText format ["MERGING: %1", _cfg];
diag_mergeConfigFile [_cfg];
["pythia.enable_reloader", [True]] call py3_fnc_callExtension;
{uiNamespace setVariable _x} forEach [
	["TER_3den_RscDisplay3denViewRPT_script",
	compile preprocessFileLineNumbers "p\TER_editing\gui\scripts\TER_3den_RscDisplay3denViewRPT.sqf"]
];
{missionNamespace setVariable _x} forEach [
	["TER_fnc_getRPT",
	compile preprocessFileLineNumbers "p\TER_editing\fnc\py\fn_getRPT.sqf"],
	["TER_fnc_loadRPTLine",
	compile preprocessFileLineNumbers "p\TER_editing\fnc\py\fn_loadRPTLine.sqf"]
];

findDisplay 49 createDisplay "TER_3den_RscDisplay3denViewRPT";
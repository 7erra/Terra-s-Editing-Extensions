_cfg = "P:\Terra-s-Editing-Extensions\TER_editing\config.cpp";
diag_log parseText format ["MERGING: %1", _cfg];
diag_mergeConfigFile [_cfg];
{uiNamespace setVariable _x} forEach [
	["TER_3den_RscDisplay3denViewRPT_script",
	compile preprocessFileLineNumbers "p\TER_editing\gui\scripts\TER_3den_RscDisplay3denViewRPT.sqf"]
];
missionNamespace setVariable [
	"TER_fnc_getRPT",
	compile preprocessFileLineNumbers "p\TER_editing\fnc\py\fn_getRPT.sqf"
];
findDisplay 49 createDisplay "TER_3den_RscDisplay3denViewRPT";
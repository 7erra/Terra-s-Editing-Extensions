diag_mergeConfigFile ["P:\Terra-s-Editing-Extensions\TER_editing\config.cpp"];
{uiNamespace setVariable _x} forEach [
	["TER_3den_RscDisplayConfigViewer73_script",
	compile preprocessFileLineNumbers "p\TER_editing\gui\scripts\TER_3den_RscDisplayConfigViewer73.sqf"],
	["TER_3den_ctrlColorPicker",
	compile preprocessFileLineNumbers "p\TER_editing\gui\scripts\TER_3den_ctrlColorPicker.sqf"]
];
findDisplay 49 createDisplay "TER_3den_RscDisplayConfigViewer73";

/*
	Author: 7erra
	Description:
		Copies the current config entry to the clipboard.
		Function has to be spawned.
		Only works when Config Viewer is open.
	Params: <None>
	Return: <None>
	Example:
		[] spawn TER_fnc_exportCfg;
*/
disableSerialization;
_cfgViewer = findDisplay 2928;
_ed_config = _cfgViewer displayCtrl 1400;
_btn_export = _cfgViewer displayCtrl 7301;
_curCfgArr = call compile (ctrltext _ed_config);
_dreadReturn = [_curCfgArr] call DREAD_fnc_copyConfigClass;
if (_dreadReturn == "noClass") then {
	_btn_export ctrlSettext "ERROR: Config not found!";
	_btn_export ctrlSetBackgroundColor [1,0,0,0.8];
} else {
	_btn_export ctrlSettext "Config exported!";
	_btn_export ctrlSetBackgroundColor [0,1,0,0.8];
};
uisleep 2;
_btn_export ctrlSettext "Export";
_btn_export ctrlSetBackgroundColor [0,0,0,0.8];
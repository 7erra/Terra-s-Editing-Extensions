#include "ctrls.inc"
_mode = _this#0;
_this = _this#1;
//--- onLoad
switch _mode do {
case "onload":{
	_display = _this#0;
	uiNamespace setVariable ["TER_3den_RscLiveWatch_display",_display];
	//--- Hide unit info for wider live debug
	_defaultShown = shownHUD#0;
	_show = shownHUD;
	_show set [1,false];
	showHUD _show;
	//--- Call a script from the second debug page (\TER_Editing\gui\scripts\RscDebug\page2.sqf)
	with uiNamespace do {["livedebug",[nil,0]] call TER_fnc_debugPage2_script;};
	waitUntil {isNull _display};
	//--- Display is closed, reset vars and HUD
	uiNamespace setVariable ["TER_3den_RscLiveWatch_display",nil];
	_show = shownHUD;
	_show set [1,_defaultShown];
	showHUD _show;
};
};
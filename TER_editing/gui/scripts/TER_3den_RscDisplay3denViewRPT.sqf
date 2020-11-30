/*
   Author: R3vo

   Date: 2020-11-02

   Description:
   Initialises Rsc3DENViewRPT GUI. Script is executed by the GUI.

   Parameter(s):
   0: DISPLAY or CONTROL
   1: STRING - Mode, can be "onLoad" or "reload"

   Returns:
   NOTHING
*/
#include "ctrls.inc"
#define SELF TER_3den_RscDisplay3denViewRPT_script
#define CTRL_GROUP_WIDTH (200 * pixelW * pixelGrid * 0.50)
#define SIZEEX 4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5
params ["_mode", "_params"];
diag_log [_this];
switch _mode do {
	case "onLoad":{
		_params params ["_display"];
		//--- Load RPT
		private _lineCount = profileNamespace getVariable ["ENH_ShowRPT_LinesCount",100];
		_ctrlEditLines = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_EDITLINES;
		_ctrlEditLines ctrlSetText str _lineCount;
		_ctrlReload = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_RELOAD;
		["reload", [_ctrlReload]] spawn SELF;
		_ctrlReload ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["reload", _this] spawn SELF;};
		}];
	};
	case "reload":{
		_params params ["_ctrlReload"];
		_display = ctrlParent _ctrlReload;
		_ctrlContent = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_CONTENT;
		_ctrlContent ctrlSetText "Please wait...";
		_ctrlReload = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_RELOAD;
		_ctrlReload ctrlEnable false;
		_rpt = [] call (missionNamespace getVariable "TER_fnc_getRPT");
		if (count _rpt == 0) exitWith {
			_ctrlContent ctrlSetText "#INFO# No lines loaded. Maybe something went wrong?";
		};
		_rpt = _rpt + endl;
		ctrlPosition ctrlParentControlsGroup _ctrlContent params [
			"_xParent",
			"_yParent",
			"_wParent",
			"_hParent"
		];
		_maxW = selectMax ((_rpt splitString endl) apply {
			_x getTextWidth ["RobotoCondensedLight",SIZEEX]
		});
		_ctrlContent ctrlSetPositionW (_maxW max _wParent);
		_ctrlContent ctrlCommit 0;
		_ctrlContent ctrlSetText _rpt;
		_ctrlContent ctrlSetPosition [
			0,
			0,
			_wParent max _maxW,
			_hParent max ctrlTextHeight _ctrlContent
		];
		_ctrlContent ctrlSetText _rpt;
		diag_log [_wParent, _hParent, _maxW];
		_ctrlContent ctrlCommit 0;
		_ctrlReload ctrlEnable true;
	};

	case "onUnload":{
		_params params ["_display", "_exitCode"];
	};
};
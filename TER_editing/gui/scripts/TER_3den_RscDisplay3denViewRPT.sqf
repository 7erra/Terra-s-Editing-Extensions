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
		_rpt = [] call (missionNamespace getVariable "TER_fnc_getRPT");
		if (count _rpt == 0) exitWith {
			_ctrlContent ctrlSetText "#INFO# No lines loaded. Maybe something went wrong?";
		};
		_rpt = _rpt + endl;
		_ctrlContent ctrlSetText _rpt;
		ctrlPosition ctrlParentControlsGroup _ctrlContent params [
			"_xParent",
			"_yParent",
			"_wParent",
			"_hParent"
		];
		_maxW = selectMax ((_rpt splitString endl) apply {
			_x getTextWidth ["RobotoCondensedLight",SIZEEX]
		});
		_ctrlContent ctrlSetPosition [
			0,
			0,
			_wParent max _maxW,
			_hParent max ctrlTextHeight _ctrlContent
		];
		_ctrlContent ctrlCommit 0;
/* 		if !(isNil "ENH_ShowRPT_Loading") exitWith {};//Prevent the user from starting cycle multiple times
		ENH_ShowRPT_Loading = true;
		_ctrlEditLines = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_EDITLINES;
		_wantedLines = parseNumber ctrlText _ctrlEditLines;

		private _ctrlProgress = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_PROGRESS;
		private _ctrlContent = _display displayCtrl IDC_RSCDISPLAY3DENLASTRPT_CONTENT;
		_ctrlContent ctrlSetText "Please wait..."; //Performance is better if text control is almost empty

		private _content = [];

		private _linesCount = ["count_rpt_lines", []] call TER_fnc_pyTerEden;
		_wantedLines = _wantedLines min _linesCount;
		private _firstLine = _linesCount - _wantedLines;
		_ctrlEditLines ctrlSetText str _wantedLines;

		private _longestLine = 0;

		if (_linesCount isEqualTo []) exitWith {systemChat ".rpt is empty"};

		for "_line" from _firstLine to _linesCount do
		{
			private _lineText = (["load_rpt_line", [_line]] call TER_fnc_pyTerEden);
			_longestLine = _longestLine max  (_lineText getTextWidth ["RobotoCondensedLight",SIZEEX]);
			_ctrlProgress progressSetPosition ((_line - _firstLine) / _linesCount); //Give the user an indication how many lines he is viewing from the total available ones
			_content pushBack (["load_rpt_line", [_line]] call TER_fnc_pyTerEden);
		};
		_content pushBack "";

		profileNamespace setVariable ["ENH_ShowRPT_LinesCount",_wantedLines];
		
		//Change width before adding text. It seems to only work this way. Wait until width is set
		_wGrp = ctrlPosition ctrlParentControlsGroup _ctrlContent select 2;
		_ctrlContent ctrlSetPositionW (_longestLine max _wGrp); //Longest line and not smaller then ctrlGroup width
		_ctrlContent ctrlCommit 0;
		waitUntil {ctrlCommitted _ctrlContent};
		
		_ctrlContent ctrlSetText (_content joinString endl);
		_ctrlContent ctrlSetPositionH ctrlTextHeight _ctrlContent;
		_ctrlContent ctrlCommit 0;
		
		ENH_ShowRPT_Loading = nil;
		diag_log [_linesCount, _wantedLines]; */
	};

	case "onUnload":{
		_params params ["_display", "_exitCode"];
	};
};
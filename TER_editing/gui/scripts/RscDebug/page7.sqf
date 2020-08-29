#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage7_script
params ["_mode", "_params"];
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_7;
_edRPTContent = _page controlsGroupCtrl IDC_ED_RPTCONTENT;
_btnRPTDiagLog = _page controlsGroupCtrl IDC_BTN_RPTDIAGLOG;
_edRPTDiagLogText = _page controlsGroupCtrl IDC_ED_RPTDIAGLOGTEXT;
_edRPTLines = _page controlsGroupCtrl IDC_ED_RPTLINES;
_btnRPTReload = _page controlsGroupCtrl IDC_BTN_RPTRELOAD;
_txtRPTTextSizeText = _page controlsGroupCtrl IDC_TXT_RPTTEXTSIZETEXT;
_btnRPTTextSizePlus = _page controlsGroupCtrl IDC_BTN_RPTTEXTSIZEPLUS;
_btnRPTTextSizeMinus = _page controlsGroupCtrl IDC_BTN_RPTTEXTSIZEMINUS;
switch (_mode) do {
	case "load":{
		if (_page getVariable ["pageInitialized",false]) exitWith {};
		_page setVariable ["pageInitialized",true];
		_expression = profileNamespace getVariable ["TER_fnc_debugPage7_script_expression", ""];
		_edRPTDiagLogText ctrlSetText _expression;
		_setLines = profileNamespace getVariable ["TER_fnc_debugPage7_script_setLines", 50];
		_edRPTLines ctrlSetText str _setLines;
		["loadRPT", _params] call SELF;
		_btnRPTDiagLog ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["log", _this] call SELF;};
		}];
		_btnRPTReload ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["loadRPT"] call SELF};
		}];
		//--- TODO: use ctrlSetScrollValues when implemented
		_btnRPTTextSizePlus ctrlAddEventHandler ["ButtonClick", {
			with uiNamespace do {["changeTextSize", [_this#0, +1]] call SELF};
		}];
		_btnRPTTextSizeMinus ctrlAddEventHandler ["ButtonClick", {
			with uiNamespace do {["changeTextSize", [_this#0, -1]] call SELF};
		}];
		//--- Update size preview text the calculations are bs
		with uiNamespace do {["changeTextSize", [nil, 0]] call SELF};
	};
	case "changeTextSize":{
		_params params ["_btn", "_change"];
		_change = 0.05 * _change;
		systemchat "test";
		_currentSize = profileNamespace getVariable [
			"TER_3den_RscDebug_RPTTextSize", 0.7
		];
		_newSize = (_currentSize + _change) max 0 min 1;
		profileNamespace setVariable ["TER_3den_RscDebug_RPTTextSize",_newSize];
		diag_log [_txtRPTTextSizeText, _newSize, format[
			"<t size='%1'>Aa</t>", _newSize
		]];
		_txtRPTTextSizeText ctrlSetStructuredText parseText format[
			"<t size='%1'>Aa</t>", _newSize
		];
		
	};
	case "log":{
		_params params ["_btnRPTDiagLog"];
		_logText = ctrlText _edRPTDiagLogText;
		diag_log (call compile _logText);
		["loadRPT"] call SELF;
	};
	case "loadRPT":{
		private _rptContent = "";
		with missionNamespace do {
			_maxLines = [] call TER_fnc_countRPTLines;
			_loadLines = parseNumber(ctrlText _edRPTLines);
			_lineCounter = _maxLines - _loadLines;
			for "_l" from _maxLines to _lineCounter step -1 do{
				private _lcontent = [_l] call TER_fnc_loadRPTLine;
				_rptContent = _lcontent + endl + _rptContent;
			};
		};
		_edRPTContent ctrlSetText _rptContent;
		_edRPTContent ctrlSetPositionH (ctrlTextHeight _edRPTContent);
		_edRPTContent ctrlCommit 0;
	};
	case "unload":{
		//--- save current settings
		if !(_page getVariable ["pageInitialized",false]) exitWith {};
		_expression = ctrlText _edRPTDiagLogText;
		profileNamespace setVariable ["TER_fnc_debugPage7_script_expression", _expression];
		_setLines = parseNumber ctrlText _edRPTLines;
		profileNamespace setVariable ["TER_fnc_debugPage7_script_setLines", _setLines];
		saveProfileNamespace;
	};
};
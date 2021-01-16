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
			with uiNamespace do {["log", _this] spawn SELF};
		}];
		_btnRPTReload ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["loadRPT"] spawn SELF};
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
		_currentSize = profileNamespace getVariable [
			"TER_3den_RscDebug_RPTTextSize", 0.7
		];
		_newSize = (_currentSize + _change) max 0 min 1;
		profileNamespace setVariable ["TER_3den_RscDebug_RPTTextSize",_newSize];
		_txtRPTTextSizeText ctrlSetStructuredText parseText format[
			"<t size='%1'>Aa</t>", _newSize
		];
		
	};
	case "log":{
		_params params ["_btnRPTDiagLog"];
		_logText = ctrlText _edRPTDiagLogText;
		diag_log (call compile _logText);
		uiSleep 0.5;
		["loadRPT"] call SELF;
	};
	case "loadRPT":{
		_grpRPTContent = ctrlParentControlsGroup _edRPTContent;
		_rptContent = ["°"] call TER_fnc_getRPT;
		if (isNull _grpRPTContent) exitWith {};
		_maxLines = parseNumber ctrlText _edRPTLines;
		_rptContent = _rptContent splitString "°";
		if (_maxLines < 0) then {_maxLines = count _rptContent};
		_rptContent = _rptContent select [count _rptContent -_maxLines, count _rptContent];
		_maxW = 0;
		_rptContent apply {
			_maxW = _maxW max (str parseText _x getTextWidth ["EtelkaMonospacePro", 0.7 * GUI_GRID_H]);
		};
		_maxW = (_maxW + 0.016) max ((ctrlPosition _grpRPTContent select 2) - 0.01);
		_rptContent = _rptContent joinString "<br/>";
		_hNormal = (ctrlPosition _grpRPTContent select 3) - (1 * GUI_GRID_H);
		_maxH = 0.7 * (_maxLines +1) * GUI_GRID_H max _hNormal;
		diag_log [_maxW, (ctrlPosition _grpRPTContent select 2) - 0.5];
		_edRPTContent ctrlSetPositionW _maxW;
		_edRPTContent ctrlSetStructuredText parseText _rptContent;
		_edRPTContent ctrlSetPositionH _maxH;
		_edRPTContent ctrlCommit 0;
		_grpRPTContent spawn {
			_this ctrlSetScrollValues [1,0];
		};
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
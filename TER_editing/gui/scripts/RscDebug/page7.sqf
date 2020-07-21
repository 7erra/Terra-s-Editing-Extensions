#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage7_script
params ["_mode", "_params"];
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_7;
_edRPTContent = _page controlsGroupCtrl IDC_ED_RPTCONTENT;
switch (_mode) do {
	case "load":{
		if (_page getVariable ["pageInitialized",false]) exitWith {};
		_page setVariable ["pageInitialized",true];
		private _rptContent = "";
		with missionNamespace do {
			_lineCounter = uiNamespace getVariable ["TER_fnc_debugPage7_script_firstLine", 0];
			_maxLines = [] call TER_fnc_countRPTLines;
			_lineCounter = _lineCounter max (_maxLines -10);
			systemChat str [_lineCounter, _maxLines];
			for "_l" from _maxLines to _lineCounter step -1 do{
				private _lcontent = [_l] call TER_fnc_loadRPTLine;
				_rptContent = _lcontent + endl + _rptContent;
			};
		};
		systemChat str [_edRPTContent, _rptContent];
		_edRPTContent ctrlSetText _rptContent;
	};
	case "unload":{
		//--- save current settings
		if !(_page getVariable ["pageInitialized",false]) exitWith {};
	};
};
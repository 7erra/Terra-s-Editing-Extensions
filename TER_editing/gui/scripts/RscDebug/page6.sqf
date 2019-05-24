#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage6_script
_mode = _this select 0;
_this = _this select 1;
//// CONTROLS
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_6;
_cbRed = _page controlsGroupCtrl IDC_CB_KKRED;
_cbGreen = _page controlsGroupCtrl IDC_CB_KKGREEN;
_cbBlue = _page controlsGroupCtrl IDC_CB_KKBLUE;
_picColor = _page controlsGroupCtrl IDC_PIC_KKCOLOR;
_cbTime = _page controlsGroupCtrl IDC_CB_KKTIME;
_cbFile = _page controlsGroupCtrl IDC_CB_KKFILE;
_btnBeep = _page controlsGroupCtrl IDC_BTN_KKBEEP;
_btnClear = _page controlsGroupCtrl IDC_BTN_KKCLEAR;
_btnClose = _page controlsGroupCtrl IDC_BTN_KKCLOSE;
_edInput = _page controlsGroupCtrl IDC_ED_KKINPUT;
_edOutput = _page controlsGroupCtrl IDC_ED_KKOUTPUT;
_btnLog = _page controlsGroupCtrl IDC_BTN_KKLOG;
_cbLoginput = _page controlsGroupCtrl IDC_CB_KKLOGINPUT;

switch (_mode) do {
case "load":{
	if (_page getVariable ["pageInitialized",false]) exitWith {};
	_page setVariable ["pageInitialized",true];
	_settings = uiNamespace getVariable ["TER_3den_KKsettings",[true,true,true,true,true,false,""]];
	//--- CB Colors
	{
		_x ctrlAddEventHandler ["CheckedChanged",{
			with uiNamespace do {["colorcbchanged",_this] call SELF;};
		}];
		_x cbSetChecked (_settings select _forEachIndex);
	} forEach [_cbRed,_cbGreen,_cbBlue];
	//--- CB time, log input, file
	_cbTime cbSetChecked _settings#3;
	_cbLoginput cbSetChecked _settings#4;
	_cbFile cbSetChecked _settings#5;
	with uiNamespace do {["colorcbchanged",[]] call SELF};
	//--- Beep, clear, close button
	{
		_x ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["consoleaction",_this] call SELF;};
		}];
	} forEach [_btnBeep,_btnClear,_btnClose];
	//--- Log button
	_btnLog ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["log",[]] call SELF;};
	}];
	_edInput ctrlSetText _settings#6;
};
case "colorcbchanged":{
	//--- update color
	if !([_cbRed,_cbGreen,_cbBlue] findIf {cbChecked _x} != -1) exitWith {
		_picColor ctrlSetText "#(rgb,8,8,3)color(0.4,0.4,0.4,1)";//grey if no cb is checked
	};
	_picColor ctrlSetText format [
		"#(rgb,8,8,3)color(%1,%2,%3,1)",
		parseNumber(cbChecked _cbRed),
		parseNumber(cbChecked _cbGreen),
		parseNumber(cbChecked _cbBlue)
	];
};
case "consoleaction":{
	params ["_control"];
	_arg = ["A","C","X"] select ([_btnBeep,_btnClear,_btnClose] find _control);
	"debug_console" callExtension (_arg);
};
case "log":{
	_result = call compile ctrlText _edInput;
	if (isNil "_result") exitWith {
		_edOutput ctrlSetText "nil";
	};
	_edOutput ctrlSetText str _result;
	_appendix = ["#","~"] select (cbChecked _cbFile);
	_appendix = format [
		"%1%2%3%4%5",
		_appendix,
		parseNumber(cbChecked _cbRed),
		parseNumber(cbChecked _cbGreen),
		parseNumber(cbChecked _cbBlue),
		parseNumber(cbChecked _cbTime)
	];
	if (cbChecked _cbLoginput) then {
		//--- log input too
		_message = format ["INPUT: %1%2",ctrlText _edInput,_appendix];
		"debug_console" callExtension _message;
	};
	//--- log result
	_message = format ["RESULT: %1%2",_result,_appendix];
	"debug_console" callExtension _message;
};
case "unload":{
	//--- save current settings
	if !(_page getVariable ["pageInitialized",false]) exitWith {};
	_settings = [_cbRed,_cbGreen,_cbBlue,_cbTime,_cbLoginput,_cbFile];
	_settings = _settings apply {cbChecked _x};
	_settings pushBack (ctrlText _edInput);
	uiNamespace setVariable ["TER_3den_KKsettings",_settings];
};
};
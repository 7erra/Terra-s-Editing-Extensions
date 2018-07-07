scriptName "fn_toggleLive:";
/*
	Author: 7erra

	Description:
	Toggles the RscLiveWatch where the command of the debug console is displayed live

	Parameter(s):
	0 - CONTROL: The button that was clicked next to the output control of the debug console

	Returns:
	<nothing>
*/
#define SELF _fnc_fn_toggleLive


#define ESCAPE_MENU(IDC) _escapeMenu displayCtrl IDC;
#define LIVE_DISPLAY (uiNamespace getVariable ["TER_3den_RscLiveWatch_display",displayNull])
#define LIVE_WATCH(IDC) LIVE_DISPLAY displayCtrl IDC
disableSerialization;
params ["_ctrl"];
_fncEmpty = {
	{_x ctrlSetText ""} forEach [_liveInCtrl,_liveOutCtrl];
	_inTextArray = _inLiveArray apply {ctrlText _x};
	if ({_x != ""} count _inTextArray == 0) then {
		("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["default","PLAIN"];
	};
};
// escape menu
_escapeMenu = findDisplay 49;
_cbWatch1 = ESCAPE_MENU(7301)
_cbWatch2 = ESCAPE_MENU(7302)
_cbWatch3 = ESCAPE_MENU(7303)
_cbWatch4 = ESCAPE_MENU(7304)
_cbWatchArray = [_cbWatch1,_cbWatch2,_cbWatch3,_cbWatch4];

_createdNew = false;
if (isNull LIVE_DISPLAY) then {
	// create Rsc
	("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["TER_3den_RscLiveWatch","PLAIN"];
	ctrlSetFocus controlNull;
	_createdNew = true;
};
// cutRsc TER_3den_RscWatchLive
_in1Live = LIVE_WATCH(7301);
_out1Live = LIVE_WATCH(7302);
_in2Live = LIVE_WATCH(7303);
_out2Live = LIVE_WATCH(7304);
_in3Live = LIVE_WATCH(7305);
_out3Live = LIVE_WATCH(7306);
_in4Live = LIVE_WATCH(7307);
_out4Live = LIVE_WATCH(7308);
_inLiveArray = [_in1Live,_in2Live,_in3Live,_in4Live];
_inTextArray = _inLiveArray apply {ctrlText _x};

// no watch selected, close cutRsc
if ({_x != ""} count _inTextArray == 0 && !_createdNew) exitWith {
	("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["default","PLAIN"];
};

_cbArgs = switch (ctrlClassName _ctrl) do {
	case "CB_output1": {[12285,_in1Live,_out1Live]};
	case "CB_output2": {[12287,_in2Live,_out2Live]};
	case "CB_output3": {[12289,_in3Live,_out3Live]};
	case "CB_output4": {[12291,_in4Live,_out4Live]};
	default {-1};
};
_cbArgs params ["_escapeInputIDC","_liveInCtrl","_liveOutCtrl"];
_escapeInputCtrl = ESCAPE_MENU(_escapeInputIDC)

_state = !(ctrlText _liveInCtrl == "") && !(ctrlText _liveInCtrl != ctrlText _escapeInputCtrl);
if (_state) exitWith {call _fncEmpty;};

_commandIn = ctrlText _escapeInputCtrl;
_liveInCtrl ctrlSettext _commandIn;
if (_commandIn == "") exitWith {call _fncEmpty;};
if (isNil (compile _commandIn)) exitWith {
	_liveOutCtrl ctrlSettext "#ERROR: NO RETURN VALUE";
};
// loop for watch live
[_liveInCtrl,_liveOutCtrl] spawn {
	params ["_liveInCtrl","_liveOutCtrl"];
	_startCommand = ctrlText _liveInCtrl;
	while {ctrlText _liveInCtrl == _startCommand} do {
		_result = str ([] call compile _startCommand);
		if (isNil {_result}) then {_result = ""};
		_liveOutCtrl ctrlSetText _result;
		_curFrame = diag_frameno;
		waitUntil {diag_frameno != _curFrame};
	};
};
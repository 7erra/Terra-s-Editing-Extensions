#include "..\ctrls.inc"
// live debug
BTN_LIVEDEBUG ctrlAddEventHandler ["ButtonClick",{
	disableSerialization;
	params ["_control","_state"];
	_fncWatchLoop = {
		params ["_inctrl"];
		_outCtrl = LIVE_WATCH((ctrlIDC _inctrl)+1);
		_startCommand = ctrlText _inctrl;
		while {_startCommand == ctrlText _inctrl} do {
			if (_startCommand == "") exitWith {_outCtrl ctrlSetText ""};
			if (isNil compile _startCommand) exitWith {_outCtrl ctrlSetText "#NIL"};
			_result = [] call compile _startCommand;
			//if (isNil {_result}) exitWith {_outCtrl ctrlSetText ""};
			_outCtrl ctrlSetText str _result;
			_curFrame = diag_frameno;
			waitUntil {diag_frameno != _curFrame};
		};
	};
	_state = isNull LIVE_DISPLAY;
	_ctrlIDCArray = [[7301,12285], [7303,12287], [7305,12289], [7307,12291]];
	_textChanged = {
		if (ctrlText LIVE_WATCH((_x select 0)) != ctrlText ESC_CTRL((_x select 1))) exitWith {true};
		false
	} forEach _ctrlIDCArray;
	if (_state OR _textChanged) then {
		if (_state) then {
			("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["TER_3den_RscLiveWatch","PLAIN"];
		};
		{
			_escInCommand = ctrlText ESC_CTRL((_x select 1));
			if (_escInCommand != ctrlText LIVE_WATCH((_x select 0))) then {
				LIVE_WATCH((_x select 0)) ctrlSetText _escInCommand;
				[LIVE_WATCH((_x select 0))] spawn _fncWatchLoop;
			};
		} forEach _ctrlIDCArray;
	} else {
		("TER_3den_RscWatchLive_layer" call BIS_fnc_rscLayer) cutRsc ["default","PLAIN"];
	};
}];
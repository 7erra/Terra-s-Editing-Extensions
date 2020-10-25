#include "ctrls.inc"
params ["_mode", "_params"];
switch _mode do {
	case "onLoad":{
		_params params ["_display"];
		_ctrlDisclaimerTop = _display displayCtrl IDC_PREVIEWBACKGROUND_TXTDISCLAIMERTOP;
		_ctrlDisclaimerBottom = _display displayCtrl IDC_PREVIEWBACKGROUND_TXTDISCLAIMERBOTTOM;
		[_ctrlDisclaimerTop, _ctrlDisclaimerBottom] apply {
			ctrlPosition _x params ["", "", "_wC"];
			while {ctrlTextWidth _x < _wC} do {
				_x ctrlSetText format ["%2 - %1 - %2", ctrlText _x, "PREVIEW"];
			};
		};
	};
};
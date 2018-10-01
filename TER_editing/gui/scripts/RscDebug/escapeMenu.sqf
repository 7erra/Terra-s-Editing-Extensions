#include "..\ctrls.inc"
{ESC_CTRL(_x) ctrlShow false;} forEach [1000,1001];

ESC_DISPLAY displayAddEventHandler ["KeyDown",{
	params ["_display","_key","_shift","_ctrl","_alt"];
	if (_key == 0x13 && _ctrl && !_shift) then { // restart
		_restartBtn = _display displayCtrl 119;
		ctrlActivate _restartBtn;
	};
	if (_key == 0x12 && _ctrl) then { // exit
		_exitBtn = _display displayCtrl 104;
		ctrlActivate _exitBtn;
	};
}];

scriptName "fn_escapeShortcuts:";
/*
	Author: 7erra

	Description:
	Handles the STRG+R (restarts mission) and STRG+E (exits mission) shortcuts in the Escape menu

	Parameter(s):
	0 - DISPLAY: The escape menu display (Display #49)
	1 - NUMBER: Pressed key, DIK code
	2 - BOOLEAN: State of shift
	3 - BOOLEAN: State of ctrl
	4 - BOOLEAN: State of alt

	Returns:
	<nothing>
*/
#define SELF _fnc_fn_escapeShortcuts


disableSerialization;
params ["_display","_key","_shift","_ctrl","_alt"];
if (_key == 0x13 && _ctrl && !_shift) then { // restart
	_restartBtn = _display displayCtrl 119;
	ctrlActivate _restartBtn;
};
if (_key == 0x12 && _ctrl) then { // exit
	_exitBtn = _display displayCtrl 104;
	ctrlActivate _exitBtn;
};
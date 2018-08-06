/*
	Author: Terra

	Description:
	Execute the script and wait for the message "IDC finder initialized on displays:
	[display array]". Then you can hover above any button and see the IDC of the control.
	The tooltip might not be accurate everytime because of control groups. Systemchat
	 output is more reliable.

	Parameters:
	0 - Delay between execution of the function and activation (NUMBER)
		Default: 5
	1 - exclude displays. (ARRAY OF IDDs)
		Default: Standard displays 0, 46 (Game display), 12 (Map), 49 (Escape menu)
	2 - Display IDD for specific display (NUMBER)
		Default: -1

	Example: [] spawn TER_fnc_findIDC;
*/
if (!canSuspend) exitWith {_this spawn TER_fnc_controlInfo};
disableSerialization;
params [
	["_delay",5,[123]],
	["_exclude",[0,12,46,49],[[]]],
	["_dialogIDD",-1]
];
_exclude = _exclude apply {findDisplay _x};
uisleep _delay;
_displays = [allDisplays -_exclude, [findDisplay _dialogIDD]] select (_dialogIDD > 0);
{
	{
		_x ctrlAddEventHandler ["MouseEnter",{systemChat format ["IDC: %1",ctrlIDC (_this select 0)]}];
		_x ctrlSetTooltip format ["IDC: %1%2Class: %3",ctrlIDC _x,toString [10],ctrlClassName _x];
	} forEach allControls _x;
} forEach _displays;
systemChat format ["IDC finder initialized on displays: %1",_displays];
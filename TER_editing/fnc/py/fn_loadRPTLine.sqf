/*
	Author: Terra

	Description:
	Load the specified line from the current RPT log.

	Parameter(s):
		0: NUMBER - Line number starting at 0.
		1: STRING - Highlight syntax: rpt, TODO

	Returns:
	STRING: The line in the .rpt.
*/
["load_rpt_line", _this] call TER_fnc_pyTerEden;
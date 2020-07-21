/*
	Author: Terra

	Description:
	Load the specified line from the current RPT log.

	Parameter(s):
		0: NUMBER - Line number starting at 0.

	Returns:
	STRING: The line in the .rpt.
*/
params["_line"];
["load_rpt_line", [_line]] call TER_fnc_pyTerEden;
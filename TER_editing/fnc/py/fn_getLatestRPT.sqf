/*
    Author: Terra
    
    Description:
    	Returns the path and file name of the newest rpt.
    
    Parameter(s):
    	None
    
    Returns:
    	STRING - D:\Path\To\RPT\arma_bla.rpt
    
    Example(s):
    	[] call TER_fnc_getLatestRPT; //-> "C:\Users\Terra\AppData\Local\Arma 3\arma3diag_x64_2020-12-05_01-07-48.rpt"
*/
if (isNil {uiNamespace getVariable "TER_fnc_getLatestRPT_rpt"}) then {
	_latestRPT = ["get_latest_rpt", [true]] call TER_fnc_pyTerEden;
	uiNamespace setVariable ["TER_fnc_getLatestRPT_rpt", _latestRPT];
};
uiNamespace getVariable "TER_fnc_getLatestRPT_rpt"
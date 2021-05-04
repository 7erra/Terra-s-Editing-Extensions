/*
    Author: Terra
    
    Description:
    	Return the entire rpt as string. Previous calles are cached in 
		uiNamespace as array: TER_3den_getRPT_RPTArray. Loading rpt lines takes
		quite some time so expect delay.
    
    Parameter(s):
    	0:	STRING - Linebreak character
    
    Returns:
    	STRING - RPT content
    
    Example(s):
    	[] call TER_fnc_getRPT;
    	["<br/>"] call TER_fnc_getRPT;
*/
params [["_br", endl]];
if (isNil {uiNamespace getVariable "TER_3den_getRPT_RPTArray"}) then {
	uiNamespace setVariable ["TER_3den_getRPT_RPTArray", []];
};
private _latestRPT = [] call TER_fnc_getLatestRPT;
if (count supportInfo "n:forceUnicode*" > 0) then {
	call compile "forceUnicode";
};
private _rptArray = uiNamespace getVariable "TER_3den_getRPT_RPTArray";
private _maxLines = [] call TER_fnc_countRPTLines;
for "_i" from (count _rptArray) to (_maxLines -1) do {
	_rptArray pushBack ([_i, "rpt"] call TER_fnc_loadRPTLine);
};
_rptArray joinString _br

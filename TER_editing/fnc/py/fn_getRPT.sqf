/*
    Author: Terra
    
    Description:
    	Return the entire rpt as string. Previous calles are cached in 
		uiNamespace as array: TER_3den_getRPT_RPTArray. Loading rpt lines takes
		quite some time so expect delay.
    
    Parameter(s):
    	None
    
    Returns:
    	STRING - RPT content
    
    Example(s):
    	[] call TER_fnc_getRPT;
*/

if (isNil {uiNamespace getVariable "TER_3den_getRPT_RPTArray"}) then {
	uiNamespace setVariable ["TER_3den_getRPT_RPTArray", []];
};
if (count supportInfo "n:forceUnicode*" > 0) then {
	call compile "forceUnicode";
};
_rptArray = uiNamespace getVariable "TER_3den_getRPT_RPTArray";
_maxLines = [] call TER_fnc_countRPTLines;
for "_i" from count _rptArray to _maxLines do {
	_rptArray pushBack (_i call TER_fnc_loadRPTLine);
};
_rptArray joinString endl

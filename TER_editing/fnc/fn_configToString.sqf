/*
	Author: Terra

	Description:
	Converts a given config to a string.

	Parameter(s):
		0: CONFIG - The config to be converted
		--- Optional: ---
		1: BOOL - Include inherited properties? (default: false)
		2: STRING - New line character (default: endl)
		3: STRING - Tab character (default: "	")
		4: BOOL - Include subclasses? (default: true)
		5: NUMBER - Amount of tab characters to start with (default: 0)

	Returns:
	STRING - The config as string
*/
#define SELF TER_fnc_configToString
params["_cfg", ["_inh", false], ["_breakChar", endl], ["_tabChar", "	"], ["_recursive", true], ["_tabCount", 0]];
private _props = configProperties[_cfg, "true", _inh];
private _fncNewLine = {
	params["_outarr", "_line", "_tabChar", "_tcount"];
	private _strTab = "";
	for "_t" from 1 to _tcount do {
		_strTab = _strTab + _tabChar;
	};
	_outarr pushBack (_strTab + _line);
};
private _outarr = [];
private _parent = "";
if (!_inh && inheritsFrom _cfg != confignull) then {
	_parent = format [": %1", configname inheritsFrom _cfg];
};
[_outarr, format["class %1%2", configName _cfg, _parent], _tabChar, _tabCount] call _fncNewLine;
[_outarr, "{", _tabChar, _tabCount] call _fncNewLine;
_tabCount = _tabCount +1;
_props apply {
	private _xprop = _x;
	private _xname = configName _xprop;
	private _linestr = "";
	switch true do {
		case isClass _xprop:{
			if (_recursive) then {
				_linestr = [_xprop, _inh, _breakChar, _tabChar, _recursive, _tabCount] call SELF;
			} else {
				_linestr = format["class %1;", configName _xprop];
			};
		};
		case isNumber _xprop:{
			_linestr = format["%1 = %2;", _xname, getNumber _xprop];
		};
		case isText _xprop:{
			_linestr = format["%1 = %2;", _xname, str getText _xprop];
		};
		case isArray _xprop:{
			private _xval = str getArray _xprop;
			_linestr = format["%1[] = {%2};", _xname, _xval select [1,count _xval -2]];
		};
		default {_linestr = ""};
	};
	[_outarr, _linestr, _tabChar, [_tabCount, 0] select (isClass _xprop && _recursive)] call _fncNewLine;
};
_tabCount = _tabCount -1;
[_outarr, "};", _tabChar, _tabCount] call _fncNewLine;
_return = _outarr joinString _breakChar;
_return
/*
	Author:
	 7erra <https://forums.bohemia.net/profile/1139559-7erra/>

	Description:
	 Converts a given number from a given base to the desired base

	Parameter(s):
	 0: "STRING" - Number to convert
	 1: "STRING" or NUMBER - Current number's base
	 2: "STRING" or NUMBER - New base
	 Possible bases: 2 ("binary"), 10 ("decimal"), 16 ("hexadecimal")

	Returns:
	 STRING - Number with new base

	Example:
	 ["15",10,16] call TER_fnc_convertNumber; // result: 0x0F
*/

params ["_number",["_base",10],["_toBase",2]];
if (_base isEqualType "") then {
	_base = switch (toLower _base) do {
		case "hexadecimal":{16};
		case "binary":{2};
		default {10};
	};
};

_hexChars = "ABCDEF";
_hexChars = _hexChars splitString "";
_number = _number splitString "";
if (_number#0 == "#") then {_number deleteAt 0};
if (toLower (_number#1) == "x") then {_number deleteAt 1};


// first convert number to decimal system
_decNumber = if (_base != 10) then {
	_decSum = 0;
	_it = count _number -1;
	_number apply {
		if (_x in _hexChars) then {//number is HEX
			_x = str (10 + (_hexChars find toUpper _x));
		};
		_decSum = _decSum + (call compile _x * (_base^_it));
		_it = _it -1;
	};
	_decSum
} else {
	parseNumber (_number joinString "")
};

if (_toBase == 10) exitWith {str _decNumber};
_negative = if (_decNumber < 0) then {_decNumber = _decNumber * -1; true} else {false};
// convert from decimal to desired base
_return = [];
_qoutient = -1;
while {_qoutient != 0} do {
	_qoutient = floor (_decNumber/_toBase);
	_remainder = _decNumber%_toBase;
	_decNumber = _qoutient;

	if (_remainder > 9) then {
		_return pushBack (_hexChars#(_remainder-10));
	} else {
		_return pushBack _remainder;
	};
};
if (_toBase == 16) then {
	_return pushBack (["0x","0x0"] select (count _return == 1));
};
if (_negative) then {
	_return pushBack "-";
};
reverse _return;
_return = _return joinString "";
_return

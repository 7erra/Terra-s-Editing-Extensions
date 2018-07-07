///////////////////////////////////////
// Function file for Armed Assault 3 //
//     Created by: DreadedEntity     //
//                                   //
//     MUST BE COMPILED WITH THE     //
//         FUNCTIONS LIBRARY         //
//Tag = DREAD  Name = copyConfigClass//
///////////////////////////////////////

/*
	TO USE:
		_partialClass = [config] call DREAD_fnc_copyConfigClass;

	INPUT:
		config: TYPE - Config | Anything that is not a config class is rejected.

	OUTPUT:
		_partialClass: TYPE - STRING | USED BY THE FUNCTION TO CREATE OUTPUT, DO NOT OVERWRITE
			HOWEVER, it is possible to save the result outside of the function, to run it multiple times
			ex.
				_textBoxClass = [configFile >> "RscText"] call DREAD_fnc_copyConfigClass;
				_listBoxClass = [configFile >> "RscListBox"] call DREAD_fnc_copyConfigClass;
				_buttonClass = [configFile >> "RscButton"] call DREAD_fnc_copyConfigClass;

	TO CLIPBOARD:
		Outputs a full class definition, even returning subclasses and their attributes, and it's nicely formatted with tabs. I'm such a god.
*/

private ["_parents","_numTabs","_numParams","_param","_newConfig","_params"];

_MAKE_TABS =
{
	_tabs = "";
	for "_t" from 1 to _this do
	{
		_tabs = _tabs + (toString [9]);
	};
	_tabs;
};

if (!isClass (_this select 0)) exitWith {"noClass"};

_newLine = toString [13, 10];
_parents = [_this select 0] call BIS_fnc_returnParents;

_numTabs = _this param [1, 0, [0]];

_output = _this param [2, "", [""]];
_output = _output + (_numTabs call _MAKE_TABS) + "class " + (configName (_this select 0)) + _newLine + (_numTabs call _MAKE_TABS) + "{" + _newline;

_params = [];
{
	_numParams = (count _x) - 1;
	for "_i" from 0 to _numParams do
	{
		_param = configName (_x select _i);
		_newConfig = (_this select 0) >> _param;
		if (isClass _newConfig) then
		{
			_output = [_newConfig, _numTabs + 1, _output] call DREAD_fnc_copyConfigClass;
		} else
		{
			_newParam = _param;
			_data = nil;
			switch (true) do
			{
				case (isNumber _newConfig):
				{
					_data = getNumber _newConfig;
				};
				case (isText _newConfig):
				{
					_data = str(getText _newConfig);
				};
				case (isArray _newConfig):
				{
					_newParam = _newParam + "[]";
					_data = str(getArray _newConfig);
					_data = "{" + (_data select [1, (count _data) - 2]) + "}";
				};
			};
			if (_params find _param == -1) then
			{
				_output = _output + ((_numTabs + 1) call _MAKE_TABS) + format["%1 = %2;%3", _newParam, _data, _newLine];
				_params pushBack _param;
			};
		};
	};
} forEach _parents;
_output = _output + (_numTabs call _MAKE_TABS) + "};" + _newline;
copyToClipboard _output;
_output;
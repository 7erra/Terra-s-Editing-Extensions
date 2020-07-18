MF_fnc_replaceInString = {
	params ["_str", "_find", "_replace"];
	private _matchPos = _str find _find;
	if (_matchPos isEqualTo -1) exitWith {_str};
	private _parts = [];
	private _len = count _find;
	while {_matchPos >= 0} do {
		_parts pushBack (_str select [0, _matchPos]);
		_str = _str select [_matchPos + _len];
		_matchPos = _str find _find;
	};
	_parts pushBack _str;
	_parts joinString _replace;  
};
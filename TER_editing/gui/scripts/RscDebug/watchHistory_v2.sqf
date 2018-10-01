#include "..\ctrls.inc"
//watch history
#define WATCH_HISTORY_ARRAY (profileNamespace getVariable ["TER_3den_watchHistory_array",[]])
// load previous

{
	_x ctrlAddEventHandler ["KillFocus",{
		params ["_edit"];
		_textEdit = ctrlText _edit;
		if (!isNil compile _textEdit) then {
			_historyArray = WATCH_HISTORY_ARRAY;
			reverse _historyArray;
			_historyArray pushBackUnique _textEdit;
			if (count _historyArray > 20) then {_historyArray deleteRange [0,1]};
			reverse _historyArray;
			profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
			saveProfileNamespace;
			lbClear LB_WATCHHISTORY;
			{LB_WATCHHISTORY lbAdd _x} forEach _historyArray;
		};
	}];
} forEach WATCH_IN_ARRAY;

// listbox with commands
{LB_WATCHHISTORY lbAdd _x} forEach WATCH_HISTORY_ARRAY;
LB_WATCHHISTORY ctrlAddEventHandler ["LBDblClick",{
	params ["_listbox","_index"];
	_command = _listbox lbText _index;
	_edInput = switch (lbCurSel COMBO_WATCHIN) do {
		case 1: {
			_emptyTextArray = WATCH_IN_ARRAY select {ctrlText _x == ""};
			reverse _emptyTextArray;
			if (count _emptyTextArray == 0) then {WATCH_IN_4} else {_emptyTextArray select 0};
		};
		case 2: {WATCH_IN_1};
		case 3: {WATCH_IN_2};
		case 4: {WATCH_IN_3};
		case 5: {WATCH_IN_4};
		default {
			_emptyTextArray = WATCH_IN_ARRAY select {ctrlText _x == ""};
			if (count _emptyTextArray == 0) then {WATCH_IN_1} else {_emptyTextArray select 0};
		};
	};
	_edInput ctrlSetText _command;
}];
// combo: which input
{
	_index = COMBO_WATCHIN lbAdd toUpper format ["Input: %1",_x];
	COMBO_WATCHIN lbSetTooltip [_index,"Select which Input should be chosen"];
} forEach ["First empty","Last empty",1,2,3,4];
COMBO_WATCHIN lbSetCurSel 0;

LB_WATCHHISTORY ctrlAddEventHandler ["KeyDown",{
	params ["_listbox","_key"];
	if (_key == DIK_DELETE) then {
		_command = _listbox lbText (lbCurSel _listbox);
		_historyArray = WATCH_HISTORY_ARRAY;
		_historyArray = _historyArray -[_command];
		profileNamespace setVariable ["TER_3den_watchHistory_array",_historyArray];
		_listbox lbDelete (lbCurSel _listbox);
	};

}];
/* maybe later
// max entries:
_maxEntries = uiNamespace getVariable ["TER_3den_maxEntries",25];
ED_MAXENTRIES ctrlSetText str 25;
_fncMaxHistoryEdit = {
	_this spawn {
		params ["_edit"];
		uisleep 0.01;
		_maxEntries = parseNumber ctrlText _edit;
		uiNamespace setVariable ["TER_3den_maxEntries",_maxEntries];
		lbClear LB_WATCHHISTORY;
		_historyArray = WATCH_HISTORY_ARRAY;
		if (count _historyArray > _maxEntries) then {_historyArray resize _maxEntries};
		{LB_WATCHHISTORY lbAdd _x} forEach _historyArray;
	};
};
ED_MAXENTRIES ctrlAddEventHandler ["Char",_fncMaxHistoryEdit];
[ED_MAXENTRIES] call _fncMaxHistoryEdit;
*/
// clear history:
BTN_CLEARHISTORY ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
		profileNamespace setVariable ["TER_3den_watchHistory_array",nil];
		lbClear LB_WATCHHISTORY;
}];
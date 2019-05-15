#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage2
_mode = _this select 0;
_this = _this select 1;
//// CONTROLS
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_2;
_btnAddWatch = _page controlsGroupCtrl IDC_BTN_ADDWATCH;
_grpWatchfields = _page controlsGroupCtrl IDC_GRP_WATCHFIELDS;
_watchgroupControls = (allControls _displayEscape) select {ctrlParentControlsGroup _x == _grpWatchfields};

switch (_mode) do {
case "load":{
	if (_page getVariable ["pageInitialized",false]) exitWith {
		_inputControls = allControls _displayEscape select {ctrlIDC _x == 7490};
		_inputControls apply {
			_x setVariable ["TER_3den_isFocused",false];
			true
		};
	};
	_page setVariable ["pageInitialized",true];

	_btnAddWatch ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["createwatch",[]] call SELF;};
	}];

	// load previous commands
	{
		_newControls = ["createwatch",[]] call (uiNamespace getVariable "TER_fnc_debugPage2");
		_newControls params ["_edInput","_edOutput","_btnDelete"];
		_edInput ctrlSetText _x;
	} forEach (profileNamespace getVariable ["TER_3den_watchCommands",[]]);
};
case "deletewatch":{
	params ["_button"];

	_thisGroup = ctrlParentControlsGroup _button;
	_groupsLeft = (_watchgroupControls -[_thisGroup]);
	{
		_curPos = ctrlPosition _x;
		_yPos = _forEachIndex * 2.3 * GUI_GRID_H;
		_curPos set [1,_yPos];
		_x ctrlSetPosition _curPos;
		_x ctrlCommit 0;
	} forEach _groupsLeft;

	ctrlDelete _thisGroup;
};
case "createwatch":{
	//--- Create a new group consisting of three controls: input, output, delete button
	_newWatchGroup = _displayEscape ctrlCreate ["TER_3den_RscWatchGroupControl",-1,_grpWatchfields];
	_yPos = (count _watchgroupControls) * 2.3 * GUI_GRID_H + 0.1 * GUI_GRID_H;
	_newWatchGroup ctrlSetPositionY _yPos;
	_newWatchGroup ctrlCommit 0;
	_edInput = _newWatchGroup controlsGroupCtrl IDC_ED_WATCHIN;
	_btnDelete = _newWatchGroup controlsGroupCtrl IDC_BTN_WATCHDELETE;
	_edOutput = _newWatchGroup controlsGroupCtrl IDC_ED_WATCHOUT;

	_edInput setVariable ["TER_3den_isFocused",false];
	_edInput ctrlAddEventHandler ["SetFocus",{(_this select 0) setVariable ["TER_3den_isFocused",true];}];
	_edInput ctrlAddEventHandler ["KillFocus",{(_this select 0) setVariable ["TER_3den_isFocused",false];}];
	[_edInput,_edOutput] spawn {
		params ["_edInput","_edOutput"];
		while {!isNull _edInput} do {
			_command = ctrlText _edInput;
			_result = if (isNil compile _command) then {""} else {
				str ([] call compile _command);
			};
			_edOutput ctrlSetText _result;
			if (_edInput getVariable ["TER_3den_isFocused",false]) then {
				waitUntil {uisleep 0.1; !(_edInput getVariable ["TER_3den_isFocused",false])};
			} else {
				_frame = diag_frameno;
				waitUntil {_frame < diag_frameno};//each frame when unfocused
			};
		};
	};
	_btnDelete ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["deletewatch",_this] call SELF;};
	}];

	_inputCtrlList = _page getVariable ["activeInputs",[]];
	_inputCtrlList pushBackUnique _edInput;
	ctrlSetFocus _edInput;
	[_edInput,_edOutput,_btnDelete]
};
case "hide":{
	//--- Deactivate watch controls while page is not selected
	_inputControls = allControls _displayEscape select {ctrlIDC _x == IDC_ED_WATCHIN};
	_inputControls apply {
		_x setVariable ["TER_3den_isFocused",true];
		0
	};
};
case "unload":{
	//--- save variables
	if (_page getVariable ["pageInitialized",false]) then {
		_inputControls = (allControls _displayEscape) select {ctrlParentControlsGroup _x == _grpWatchfields};
		_inputControlsText = _inputControls apply {ctrlText (_x controlsGroupCtrl IDC_ED_WATCHIN)};
		profileNamespace setVariable ["TER_3den_watchCommands",_inputControlsText];
		saveProfileNamespace;
	};
};
};
#include "..\ctrls.inc"
#define SELF TER_fnc_debugPage3
_mode = _this select 0;
_this = _this select 1;
//// CONTROLS
_displayEscape = findDisplay 49;
_page = _displayEscape displayCtrl IDC_DEBUG_PAGE_3;
_btnAdd = _page controlsGroupCtrl IDC_BTN_CCADD;
_comboLocality = _page controlsGroupCtrl IDC_COMBO_CCLOCALITY;
_grpCommands = _page controlsGroupCtrl IDC_GRP_CCCOMMANDS;

switch (_mode) do {
case "load":{
	if (_page getVariable ["pageInitialized",false]) exitWith {};
	_page setVariable ["pageInitialized",true];
	// locality options:
	{_comboLocality lbAdd _x} forEach ["Local","Global","Server"];
	_comboLocality lbSetCurSel 0;
	if (!isMultiplayer) then {_comboLocality ctrlEnable false};
	// load previous
	{
		private ["_edCCCode"];
		with uiNamespace do {["cccreate",[_x]] call SELF;};
	} forEach (profileNamespace getVariable ["TER_3den_ccArray",[]]);

	_btnAdd ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["cccreate",[""]] call SELF;};
	}];
};
#define CCFORMULA  * 1.2 * GUI_GRID_H + 0.1 * GUI_GRID_H
case "cccreate":{
	_codeText = param[0,""];
	_newControl = _displayEscape ctrlCreate ["TER_3den_RscCCGroup",-1,_grpCommands];
	_yPos = (count (allControls _displayEscape select {ctrlParentControlsGroup _x == _grpCommands}) -1) CCFORMULA;
	_newControl ctrlSetPositionY _yPos;
	_newControl ctrlCommit 0;
	_btnCCExec = _newControl controlsGroupCtrl IDC_BTN_CCEXEC;
	_edCCCode = _newControl controlsGroupCtrl IDC_ED_CCCODE;
	_edCCCode ctrlSetText _codeText;
	_btnCCDelete = _newControl controlsGroupCtrl IDC_BTN_CCDELETE;

	_btnCCExec setVariable ["TER_3den_codeControl",_edCCCode];
	_btnCCExec ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["ccexec",_this] call SELF;};
	}];
	_btnCCDelete ctrlAddEventHandler ["ButtonClick",{
		with uiNamespace do {["ccdelete",_this] call SELF;};
	}];
};
case "ccdelete":{
	params ["_button"];
	_thisGroup = ctrlParentControlsGroup _button;
	_ccGroup = ctrlParentControlsGroup _thisGroup;
	_allGroups = (allControls _displayEscape select {ctrlParentControlsGroup _x == _ccGroup});
	_groupsLeft = _allGroups -[_thisGroup];
	{
		_yPos = _forEachIndex CCFORMULA;
		_x ctrlSetPositionY _yPos;
		_x ctrlCommit 0;
	} forEach _groupsLeft;
	ctrlDelete _thisGroup;
};
case "ccexec":{
	params ["_button"];
	_codeCtrl = _button getVariable ["TER_3den_codeControl",controlNull];
	[lbCurSel _comboLocality,compile ctrlText _codeCtrl] call BIS_fnc_debugConsoleExec;
};
case "unload":{
	//--- save variables
	if (_page getVariable ["pageInitialized",false]) then {
		_curCCCtrls = (allControls _displayEscape select {ctrlParentControlsGroup _x == _grpCommands});
		_allCCEdits = _curCCCtrls apply {_x controlsGroupCtrl IDC_ED_CCCODE};
		_allCCEditsText = _allCCEdits apply {ctrlText _x};
		_allCCEditsText = _allCCEditsText select {_x != ""};
		profileNamespace setVariable ["TER_3den_ccArray",_allCCEditsText];
		saveProfileNamespace;
	};
};
};
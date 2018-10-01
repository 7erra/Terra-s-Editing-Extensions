#include "..\ctrls.inc"
// custom commands
TER_fnc_ccCreate = {
	_newControl = ESC_DISPLAY ctrlCreate ["TER_3den_RscCCGroup",-1,GRP_CC_COMMANDS];
	_curPos = ctrlPosition _newControl;
	_curPos set [1, (count CUR_CC_CONTROLS -1) * 1.1 * GUI_GRID_H];
	_newControl ctrlSetPosition _curPos;
	_newControl ctrlCommit 0;
	_btnCCExec = _newControl controlsGroupCtrl 7493;
	_edCCCode = _newControl controlsGroupCtrl 7494;
	_btnCCDelete = _newControl controlsGroupCtrl 7495;

	_btnCCExec setVariable ["TER_3den_codeControl",_edCCCode];
	_btnCCExec ctrlAddEventHandler ["ButtonClick",{
		params ["_button"];
		_codeCtrl = _button getVariable ["TER_3den_codeControl",controlNull];
		[lbCurSel COMBO_LOCALITY,compile ctrlText _codeCtrl] call BIS_fnc_debugConsoleExec;
	}];
	_btnCCDelete ctrlAddEventHandler ["ButtonClick",{
		params ["_button"];

		_thisGroup = ctrlParentControlsGroup _button;
		_ccGroup = ctrlParentControlsGroup _thisGroup;
		_allGroups = (allControls ESC_DISPLAY select {ctrlParentControlsGroup _x == _ccGroup});
		_groupsLeft = _allGroups -[_thisGroup];
		{
			_curPos = ctrlPosition _x;
			_yPos = _forEachIndex * 1.1 * GUI_GRID_H;
			_curPos set [1,_yPos];
			_x ctrlSetPosition _curPos;
			_x ctrlCommit 0;
		} forEach _groupsLeft;

		ctrlDelete _thisGroup;
	}];
};
// locality options:
{COMBO_LOCALITY lbAdd _x} forEach ["Local","Global","Server"];
COMBO_LOCALITY lbSetCurSel 0;
//};
// load previous
{
	private ["_edCCCode"];
	[] call TER_fnc_ccCreate;
	_edCCCode ctrlSetText _x;
} forEach (profileNamespace getVariable ["TER_3den_ccArray",[]]);

BTN_CC_ADD ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	[] call TER_fnc_ccCreate;
}];
// -> save commands, code at the start
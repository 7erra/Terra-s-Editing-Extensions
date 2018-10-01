#include "..\ctrls.inc"
// target debug
#define DEBUG_TARGET_COMMANDS (uiNamespace getVariable ["TER_3den_targetDebugCommands",[]])
#define DEBUG_TARGET_COMMANDS_SET(VAR) uiNamespace setVariable ["TER_3den_targetDebugCommands",VAR];
_cbTargetDebug = CB_TARGETDEBUG;
if (!isNull (uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull])) then {
	_cbTargetDebug cbSetChecked true;
};
_cbTargetDebug ctrlAddEventHandler ["CheckedChanged",{
	params ["_ctrl","_state"];
	if (_state == 1) then {// activate target debugging
		("TER_3den_RscTargetDebug_layer" call BIS_fnc_rscLayer) cutRsc ["TER_RscDisplayTargetDebug","PLAIN"];
		// spawn start
		[] spawn {
			_display = uiNamespace getVariable ["TER_3den_RscTargetDebug_display",displayNull];
			_fncNewLine = {
				params ["_lText","_rText"];
				_text = _text +format ["<t underline='true'>%1</t><br/>   %2<br/>",_lText,_rText,toString [10]];
			};
			// loop start
			_radius = 20;
			while {!isNull _display} do {
				_entities = (getPos player nearEntities _radius)-[player];
				{
					_object = _x;
					_text = "";
					{
						_command = _x;
						_result = call compile _command;
						[_command,str _result] call _fncNewLine;
					} forEach DEBUG_TARGET_COMMANDS;

					// create new control for each entity
					private "_stxtInfo";
					if (isNull (_x getVariable ["TER_3den_stxtInfoControl",controlNull])) then{
						_stxtInfo = _display ctrlCreate ["RscStructuredText",-1];
						_stxtInfo ctrlSetBackgroundColor [0,0,0,0.2];
						_x setVariable ["TER_3den_stxtInfoControl",_stxtInfo];
					} else {
						_stxtInfo = _x getVariable ["TER_3den_stxtInfoControl",controlNull];
					};
					// set control pos
					_stxtInfo ctrlSetStructuredText parseText _text;
					if (count worldToScreen getPos _x > 0) then {
						_relPos = worldToScreen getPos _x;
						{_relPos set _x} forEach [[2,ctrlTextWidth _stxtInfo],[3,ctrlTextHeight _stxtInfo]];
						_stxtInfo ctrlSetPosition _relPos;
					};
					_stxtInfo ctrlCommit 0;

				} forEach _entities;
				{
					// hide controls which are beyond 100 m
					_stxtInfo = _x getVariable ["TER_3den_stxtInfoControl",controlNull];
					_stxtInfo ctrlSetPosition [0,0,0,0];
					_stxtInfo ctrlCommit 0;
				} forEach ((getPos player nearEntities (_radius +10))-_entities +allDead);
				_curFrame = diag_frameno;
				waitUntil {_curFrame != diag_frameno};
			};
			// loop end
		};
		// spawn end
	} else {// close display, end target debugging
		"TER_3den_RscTargetDebug_layer" cutFadeOut 0;
	};
}];

// target debugging, add command
_btnTargetDebugAdd = BTN_TARGETDEBUG_ADD;
_btnTargetDebugAdd ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_escapeMenu = findDisplay 49;
	_edCommand = _escapeMenu displayCtrl 7406;
	_command = ctrlText _edCommand;
	//-- TODO: add check, if nil exit
	if !(["_object", _command] call BIS_fnc_inString) then {_command = _command +" _object"};
	//if (isNil compile _command) exitWith {_edCommand ctrlSettext "#ERROR - INVALID COMMAND"};
	// update global array
	_targetCommands = DEBUG_TARGET_COMMANDS;
	_prevCount = count _targetCommands;
	_targetCommands pushBackUnique _command;
	if (_prevCount == count _targetCommands) exitWith {};
	_lb_targetDebug_commands = LB_TARGETDEBUG_COMMANDS;
	_lb_targetDebug_commands lbAdd _command;
	DEBUG_TARGET_COMMANDS_SET(_targetCommands)

	_edCommand ctrlSetText "";
	ctrlSetFocus _edCommand;
}];
// target debugging, listbox
_lb_targetDebug_commands = LB_TARGETDEBUG_COMMANDS;
if (count DEBUG_TARGET_COMMANDS == 0) then {
	_startCommands = ["_object","typeOf _object"];
	{
		_lb_targetDebug_commands lbAdd _x;
	} forEach _startCommands;
	DEBUG_TARGET_COMMANDS_SET(_startCommands)
} else {
	{
		_lb_targetDebug_commands lbAdd _x;
	} forEach DEBUG_TARGET_COMMANDS;
};
_lb_targetDebug_commands ctrlAddEventHandler ["LBDblClick",{
	params ["_listbox","_index"];
	_command = _listbox lbText _index;
	_newCommandArray = DEBUG_TARGET_COMMANDS -[_command];
	DEBUG_TARGET_COMMANDS_SET(_newCommandArray)
	_listbox lbDelete _index;
}];
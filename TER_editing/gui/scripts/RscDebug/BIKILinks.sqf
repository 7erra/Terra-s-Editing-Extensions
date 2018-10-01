#include "..\ctrls.inc"
// BIKI Links
_prevLinkText = uiNamespace getVariable ["TER_3den_links",""];
STXT_LINKS ctrlSetStructuredText parseText _prevLinkText;
STXT_LINKS ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight STXT_LINKS) max (6 * GUI_GRID_H)];
STXT_LINKS ctrlCommit 0;

BTN_LINKADD ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_command = ctrlText ED_LINK;
	if (_command == "#CLEAR") exitWith {
		uiNamespace setVariable ["TER_3den_links",""];
		STXT_LINKS ctrlSetStructuredText parseText "";
	};
	_linkText = if (_command find "http" == -1) then {
		format ["<a href='https://community.bistudio.com/wiki/%1'>%1</a><br/>",_command];
	} else {
		format ["<a href='%1'>%1</a><br/>",_command];
	};
	_prevLinkText = uiNamespace getVariable ["TER_3den_links",""];
	if (_prevLinkText find _linkText != -1) then {
		_prevLinkText = (_prevLinkText select [0,_prevLinkText find _linkText]) + (_prevLinkText select [(_prevLinkText find _linkText) +count _linkText, count _prevLinkText]);
	};
	_newLinkText = if (count _prevLinkText == count (uiNamespace getVariable ["TER_3den_links",""])) then {
		 _linkText +_prevLinkText;
	} else {
		_prevLinkText;
	};
	uiNamespace setVariable ["TER_3den_links",_newLinkText];
	STXT_LINKS ctrlSetStructuredText parseText _newLinkText;
	STXT_LINKS ctrlSetPosition [0,0,21 * GUI_GRID_W,(ctrlTextHeight STXT_LINKS) max (6 * GUI_GRID_H)];
	STXT_LINKS ctrlCommit 0;
}];

_tooltipArray = [
	"You can",
	"a) Add a command (case sensitive)",
	"b) Add a link",
	"c) Use ""#CLEAR"" to wipe the history",
	"d) Remove a link by adding the same link again"
];
ED_LINK ctrlSetTooltip (_tooltipArray joinString toString [10]);
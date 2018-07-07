#include "ctrls.inc"
waitUntil {!isNull STXTEDITOR_DISPLAY};
params ["_display"];

// add lb formats
_formatArray = [
	["Line break","<br/>"],
	["Color","<t color='#ffff0000'>Color</t>"],
	["Size","<t size='1'>Size</t>"],
	["Font","<t font='RobotoCondensed'>Font</t>"],
	["Align","<t align='left'>Align</t>"],
	["Underline","<t underline='true'>Underline</t>"],
	["Shadow","<t shadow='0'>Shadow</t>"],
	["Image","<img image='path\file.paa' />"],
	["Hyperlink","<a href='http://youtube.com'>Hyperlink</a>"],
	//["End text format","</t>"],
	["Non breaking space"," ","ALT+255"]
];

{
	_x params ["_title","_format"];
	_tooltip = _x param [2, _format, ["string"]];
	_index = LB_FORMATS lbAdd _title;
	LB_FORMATS lbSetTooltip [_index,_tooltip];
	LB_FORMATS lbSetData [_index, _format];
} forEach _formatArray;

LB_FORMATS ctrlAddEventHandler ["LBDblClick",{
	params ["_listbox","_index"];
	_format = _listbox lbData _index;
	_curTxt = ctrlText ED_INPUT;
	ED_INPUT ctrlSetText (_curTxt +_format);
}];
/*
LB_FORMATS ctrlAddEventHandler ["LBSelChanged",{
	params ["_listbox","_index"];
	_infoFile = _listbox lbText _index;
	_infoFile = format ["stxt_editor\text\%1.txt",_infoFile];
	_infoText = parseText preprocessFile _infoFile;
	STXT_INFO ctrlSetStructuredText _infoText;
}];
*/
BTN_ADDFORMAT ctrlAddEventHandler ["ButtonClick",{
	params ["_button"];
	_edText = ctrlText ED_INPUT;
	_tBegin = "<t ";
	_curSelected = lbSelection LB_FORMATS;
	_formats = _curSelected apply {LB_FORMATS lbData _x};
	_tArray = [];
	{
		if (_x find "<t " != -1) then {
			_tArray pushBack _x;
			_formats = _formats -[_x];
		};
	} forEach _formats;
	_tArray = _tArray apply {[_x, count _tBegin, (_x find ">") -1] call  BIS_fnc_trimString};
	_tText = _tArray joinString " ";
	_tText = _tText +">";
	_formats = _formats apply {[_x, 0, (_x find ">")] call BIS_fnc_trimString};
	_formats = _formats joinString "";
	_tText = _edText +_formats +_tBegin +_tText +"Format";
	if (_tText find "<t " != -1) then {_tText = _tText +"</t>"};
	if (_tText find "<a " != -1) then {_tText = _tText +"</a>"};
	ED_INPUT ctrlSetText _tText;
}];

[] spawn {
	while {!isNull STXTEDITOR_DISPLAY} do {
		_curText = ctrlText ED_INPUT;
		STXT_OUTPUT ctrlSetStructuredText (parseText _curText);
		waitUntil {_curText != ctrlText ED_INPUT};
	};
};

BTN_COLORPICKER ctrlAddEventHandler ["ButtonClick",{
	STXTEDITOR_DISPLAY createDisplay "TER_3den_RscColorPicker";
}];

BTN_FONTPICKER ctrlAddEventHandler ["ButtonClick",{
	STXTEDITOR_DISPLAY createDisplay "TER_3den_RscFontList";
}];

STXT_BISLINK ctrlSetStructuredText parseText "<t align='center'><a href='https://community.bistudio.com/wiki/Structured_Text'>BIKI: Structured text</a></t>";
#include "ctrls.inc"
disableSerialization;
params ["_display"];
uiNamespace setVariable ["TER_3den_chapterDisplay", _display];
_chapter = uiNamespace getVariable ["TER_3den_chapter",0];
TER_fnc_loadChapter = compile preprocessFileLineNumbers "TER_Editing\gui\scripts\fn_loadChapter.sqf";
//-- Setting up the dialog
// Populating the RscGroup
[] call TER_fnc_loadChapter;

//-- adding function to the buttons
// Prev
BTN_PREV ctrlAddEventHandler ["ButtonClick",{
	_curChapter = uiNamespace getVariable ["TER_3den_chapter",0];
	_curChapter = (_curChapter -1) max 0;
	uiNamespace setVariable ["TER_3den_chapter",_curChapter];
	[] call TER_fnc_loadChapter;
}];
// next
BTN_NEXTCHAPTER ctrlAddEventHandler ["ButtonClick",{
	_curChapter = uiNamespace getVariable ["TER_3den_chapter",0];
	_curChapter = (_curChapter +1) min 6;
	uiNamespace setVariable ["TER_3den_chapter",_curChapter];
	[] call TER_fnc_loadChapter;
}];
//-- setting up the index
_chapterNameArr = [
	["Beginner",[
		"Introduction",
		"Files",
		"description.ext",
		"defines.hpp",
		"dialog.hpp",
		"GUI Editor",
		"Afterword"
	]]
];

_countChapter = 0;
{
	_levelInd = TREE_INDEX tvAdd [[],_x select 0];
	{
		_levelInd2 = TREE_INDEX tvAdd [[_levelInd],format ["%1 - %2", _countChapter, _x]];
		TREE_INDEX tvSetData [[_levelInd,_levelInd2],str _countChapter];
		_countChapter = _countChapter +1;
	} forEach (_x select 1);
} forEach _chapterNameArr;

tvExpandAll TREE_INDEX;
TREE_INDEX ctrlAddEventHandler ["TreeSelChanged",{
	params ["_ctrl","_path"];
	if (count _path != 2) exitWith {};
	_chapterNo = parseNumber (_ctrl tvData _path);
	uiNamespace setVariable ["TER_3den_chapter", _chapterNo];
	[] call TER_fnc_loadChapter;
}];

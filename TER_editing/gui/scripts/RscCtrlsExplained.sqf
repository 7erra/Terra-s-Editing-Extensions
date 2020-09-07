#include "ctrls.inc"
#define SELF TER_3den_RscDisplayCtrlsExplained_script
_mode = _this#0;
_this = _this#1;
//--- controls
_display = findDisplay IDD_DISPLAY_CTRLSEXPLAINED;
_stxtCurTitle = _display displayCtrl IDC_EXPLAIN_CURTITLE;
_grpContent = _display displayCtrl IDC_EXPLAIN_GRPCONTENT;
_lnbCTTypes = _display displayCtrl IDC_EXPLAIN_LNBCTTYPES;
_btnClose = _display displayCtrl IDC_EXPLAIN_BTNCLOSE;
_edOutput = _display displayCtrl IDC_EXPLAIN_OUTPUT;
_htmlLoadTest = _display displayCtrl IDC_EXPLAIN_HTMLLOADTEST;
//--- General variables
_wGrp = ctrlPosition _grpContent select 2;
_hGrp = ctrlPosition _grpContent select 3;
_fncCurY = {
	_gC = (allControls _display) select {ctrlParentControlsGroup _x == _grpContent};
	_gC deleteAt (count _gC -1);
	_gC = _gC select {_x getVariable ["doCountY",true]};
	_y = 0.1 * UI_GRID_H;
	_gC apply {_y = _y + ((ctrlPosition _x) select 3) + 0.1 * UI_GRID_H};
	_y
};
_fncSpacer = {
	params [["_margin",0.5]];
	_spacer = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
	_spacer ctrlSetPosition [0,[] call _fncCurY,_wGrp,_margin * UI_GRID_H];
	_spacer ctrlCommit 0;
};
_fncSeperator = {
	params [["_margin",0.5]];
	[_margin] call _fncSpacer;
	_seperator = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
	_seperator ctrlSetPosition [0,[] call _fncCurY,_wGrp,pixelH];
	_seperator ctrlSetBackgroundColor [1,1,1,1];
	_seperator ctrlCommit 0;
	[_margin] call _fncSpacer;
};

switch _mode do {
case "onload":{
	params ["_display"];
	if (isNil {uiNamespace getVariable "TER_3den_RscDisplayCtrlsExplained_script"}) then {
		uiNamespace setVariable ["TER_3den_RscDisplayCtrlsExplained_script",compile preprocessFileLineNumbers "TER_Editing\gui\scripts\RscCtrlsExplained.sqf"];
	};
	//--- LNB control types
	_ind = _lnbCTTypes lnbAddRow ["Introduction",""];
	{
		_x params ["_ct","_value"];
		_ind = _lnbCTTypes lnbAddRow [format ["CT_%1",_ct], str _value];
	} forEach [
		["STATIC",0],
		["BUTTON",1],
		["EDIT",2],
		["SLIDER",3],
		["COMBO",4],
		["LISTBOX",5],
		["TOOLBOX",6],
		["CHECKBOXES",7],
		["PROGRESS",8],
		["HTML",9],
		["ACTIVETEXT",11],
		["TREE",12],
		["STRUCTURED_TEXT",13],
		["CONTEXT_MENU",14],
		["CONTROLS_GROUP",15],
		["SHORTCUTBUTTON",16],
		["CONTROLS_TABLE",19],
		["XLISTBOX",42],
		["XSLIDER",43],
		["MENU",46],
		["MENU_STRIP",47],
		["CHECKBOX",77],
		["OBJECT",80],
		["MAP_MAIN",101],
		["LISTNBOX",102]
	];
	_lnbCTTypes ctrlAddEventHandler ["LBSelChanged",{
		with uiNamespace do {["ctchanged",_this] call SELF};
	}];
	_lnbCTTypes lbSetCurSel (uiNamespace getVariable ["TER_3den_indCtrlsExplained",0]);
};
case "ctchanged":{
	params ["_ctrl","_ind"];
	uiNamespace setVariable ["TER_3den_indCtrlsExplained",_ind];
	//--- Update title
	_ctName = _ctrl lnbText [_ind,0];
	_value = _ctrl lnbText [_ind,1];
	if (_value == "") then {
		_stxtCurTitle ctrlSetText _ctName;
	} else {
		_stxtCurTitle ctrlSetText format ["%1   -   %2   -   %3",_ctName,_value,[_value,10,16] call TER_fnc_convertNumber];
	};
	//--- Remove previous content
	{
		if (ctrlParentControlsGroup _x == _grpContent) then {
			ctrlDelete _x;
		};
	} forEach allControls _display;
	_edOutput ctrlSetText "";
	//--- Get content from file
	_fileName = tolower _ctName;
	_isCT = false;
	if (_ctName select [0,3] == "ct_") then {
		_fileName = toLower (_ctName select [3,count _ctName -1]);
		_isCT = true;
	};
	_file = format ["TER_Editing\gui\scripts\RscCtrlsExplained\%1.sqf",_fileName];
	_htmlLoadTest htmlLoad _file;
	if !(ctrlHTMLLoaded _htmlLoadTest) exitWith {
		_stxtEmptyFile = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
		_stxtEmptyFile ctrlSetPosition [0,0,_wGrp,_hGrp];
		_stxtEmptyFile ctrlSetStructuredText parseText format ["<t align='center' valign='middle'>The requested file doesn't exist:<br/>%1</t>",_file];
		_stxtEmptyFile ctrlCommit 0;
	};
	_content = [] call compile preprocessFileLineNumbers _file;
	if (!_isCT) exitWith {
		//--- Non standardised content, eg introduction.sqf
		_stxtContent = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
		_stxtContent ctrlSetPositionW _wGrp;
		_stxtContent ctrlCommit 0;
		_stxtContent ctrlSetStructuredText parseText _content;
		_stxtContent ctrlSetPositionH ctrlTextHeight _stxtContent;
		_stxtContent ctrlCommit 0;
	};
	_content params ["_examples","_description","_ehs","_commands","_baseClasses"];
	_ehs sort true;
	_commands sort true;
	//--- Create example controls
	_txtExample = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
	_txtExample ctrlSetText "Examples:";
	_txtExample ctrlSetPosition [0,[] call _fncCurY,_wGrp,UI_GRID_H];
	_txtExample ctrlCommit 0;
	_allBspCtrls = [];
	{
		_x params ["_class","_posWH","_loadFnc"];
		_posWH params [["_w",_wGrp/UI_GRID_W/2],["_h",1]];
		_w = _w * UI_GRID_W;
		_h = _h * UI_GRID_H;
		_idc = 100 + _forEachIndex;
		_bspCtrl = _display ctrlCreate [_class,_idc,_grpContent];
		_bspCtrl ctrlSetPosition [_wGrp/2 -_w/2, [] call _fncCurY, _w, _h];
		_bspCtrl ctrlCommit 0;
		_bspCtrl call _loadFnc;
		_bspCtrl setVariable ["examplecount",_forEachIndex +1];
		_allBspCtrls pushBack _bspCtrl;

		[] call _fncSpacer;
		_stxtCountExample = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
		_stxtCountExample ctrlSetPosition [0,[] call _fncCurY, _wGrp, UI_GRID_H];
		_stxtCountExample ctrlCommit 0;
		_stxtCountExample ctrlSetStructuredText parseText format ["<t align='center'>Example %1: %2</t>",_forEachIndex +1, _class];
		if (count _examples > 1 && _forEachIndex < count _examples -1) then {
			[] call _fncSpacer;
		};
	} forEach _examples;
	[] call _fncSeperator;
	//--- Set description text
	//--- Eventhandlers
	_description = format ["<t underline='true'>Information:</t><br/>%1<br/><br/><t underline='true'>Eventhandlers:</t><br/>",_description];
	{
		_ehName = _x;
		if (_ehName select [0,2] == "on") then {_ehName = _ehName select [2,count _ehName -1]};
		_description = format ["%1%3<a colorLink='#5555ff' href='https://community.bistudio.com/wiki/User_Interface_Event_Handlers#on%2'>on%2</a>",_description, _ehName, ["",", "] select (_forEachIndex != 0)];
		{
			_x ctrlAddEventHandler [_ehName,format [
				"with uiNamespace do {[""exampleeh"", [""%1""] +_this] call %2};",
				_ehName,SELF
			]];
		} forEach _allBspCtrls;
	} forEach _ehs;
	//--- Important commands
	_description = format ["%1<br/><br/><t underline='true'>Important commands:</t><br/>",_description];
	{
		_description = format ["%1%3<a colorLink='#5555ff' href='https://community.bistudio.com/wiki/%2'>%2</a>",_description, _x, ["",", "] select (_forEachIndex != 0)];
	} forEach _commands;
	//--- Common base classes
	_description = format ["%1<br/><br/><t underline='true'>Common base classes:</t><br/>",_description];
	{
		_description = format ["%1%3%2",_description, _x, ["",", "] select (_forEachIndex != 0)];
	} forEach _baseClasses;

	//--- BIKI link
	_description = format ["%1<br/><br/><t underline='true'>Further links:</t><br/><a href='https://community.bistudio.com/wiki/%2'>%2 on the BIKI</a>",_description,_ctName];

	_txtDesc = _display ctrlCreate ["TER_3den_ctrlStructuredText",-1,_grpContent];
	_txtDesc ctrlSetStructuredText parseText _description;
	_txtDesc ctrlSetPosition [0, [] call _fncCurY, _wGrp, ctrlTextHeight _txtDesc];
	_txtDesc ctrlCommit 0;
	_txtDesc ctrlSetPositionH (ctrlTextHeight _txtDesc + 1 * UI_GRID_H);
	_txtDesc ctrlCommit 0;
};
case "exampleeh":{
	_ehName = _this#0;
	_this deleteAt 0;
	_prevText = ctrlText _edOutput;
	_edOutput ctrlSetText format ["%1 (Example %2): %3%4%5",_ehName, _this#0 getVariable "examplecount", _this, endl, _prevText];
};
case "unload":{
};
};
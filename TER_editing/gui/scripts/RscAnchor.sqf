#include "ctrls.inc"
#define SELF TER_3den_RscDisplayAnchor_script
_mode = _this#0;
_this = _this#1;

//--- Controls
#define BTNIDCS [IDC_ANCHOR_LEFTTOP,IDC_ANCHOR_LEFTMID,IDC_ANCHOR_LEFTBOTTOM,IDC_ANCHOR_CENTERTOP,IDC_ANCHOR_CENTERMID,IDC_ANCHOR_CENTERBOTTOM,IDC_ANCHOR_RIGHTTOP,IDC_ANCHOR_RIGHTMID,IDC_ANCHOR_RIGHTBOTTOM]
//waitUntil {!isNull (findDisplay 73130)};
_display = findDisplay 73130;

switch _mode do {
case "load":{
	uiNamespace setVariable ["TER_3den_RscDisplayAnchor_script",compile preprocessFileLineNumbers "TER_Editing\gui\scripts\RscAnchor.sqf"];
	//--- Button texts
	_textsBtn = ["LEFT<br/>TOP","LEFT<br/>MIDDLE","LEFT<br/>BOTTOM","CENTER<br/>TOP","CENTER<br/>MIDDLE","CENTER<br/>BOTTOM","RIGHT<br/>TOP","RIGHT<br/>MIDDLE","RIGHT<br/>BOTTOM"];
	for "_i" from 0 to ((count _textsBtn) -1) do {
		_ctrl = _display displayCtrl (IDC_ANCHOR_LEFTTOP + _i);
		_textBtn = _textsBtn#_i;
		_align = _textBtn splitString "<br/>";
		_align = _align apply {toLower _x};
		_align = format (["<t align='%1' valign='%2'>"] + _align);
		_textBtn = format ["%1%2</t>",_align,_textBtn];
		_ctrl ctrlSetStructuredText parseText (_textsBtn#_i);
	};
	//--- Button EHs
	for "_idc" from IDC_ANCHOR_LEFTTOP to IDC_ANCHOR_RIGHTBOTTOM do {
		_ctrl = _display displayCtrl _idc;
		_ctrl ctrlAddEventHandler ["ButtonClick",{
			with uiNamespace do {["anchorselect",_this] call SELF;};
		}];
	};
};
case "anchorselect":{
	params ["_ctrl"];
	if (isNil "TER_3den_GUIGrid") exitWith {["No GUI grid set!"] call BIS_fnc_error};
	if (count TER_3den_GUIGrid == 0) exitWith {["No GUI grid!"] call BIS_fnc_error};
	/*
		_xLeft = "safeZoneX";
		_xCenter = "0.5";
		_xRight = "safeZoneX + safeZoneW";
		_yTop = "safeZoneY";
		_yMiddle = "0.5";
		_yBottom = "safeZoneY + safeZoneH";
		_modGrid = [
			[_xLeft,_yTop,"(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],//top left
			[_xLeft,"0.5 - (((safezoneW / safezoneH) min 1.2)/1.2)/2","(safezoneW / safezoneH) min 1.2","(((safezoneW / safezoneH) min 1.2)/1.2)"],
			[_xLeft,"safeZoneY + safeZoneH - (((safezoneW / safezoneH) min 1.2)/1.2)", "(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],
			["0.5 - ((safezoneW / safezoneH) min 1.2)/2",_yTop,"(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],
			["0.5 - ((safezoneW / safezoneH) min 1.2)/2","0.5 - (((safezoneW / safezoneH) min 1.2)/1.2)/2","(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],
			["0.5 - ((safezoneW / safezoneH) min 1.2)/2","safeZoneY + safeZoneH - ((safezoneW / safezoneH) min 1.2)/1.2","(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],
			["safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)",_yTop,"(safezoneW / safezoneH) min 1.2",	"((safezoneW / safezoneH) min 1.2)/1.2"],
			["safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)","0.5 - ((safezoneW / safezoneH) min 1.2)/1.2","(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"],
			["safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)","safeZoneY + safeZoneH - ((safezoneW / safezoneH) min 1.2)/1.2", "(safezoneW / safezoneH) min 1.2","((safezoneW / safezoneH) min 1.2)/1.2"]
		] select (BTNIDCS find (ctrlIDC _ctrl));
	*/
	_posCtrl = ctrlPosition _ctrl;
	_xAnchor = switch (_posCtrl#0) do {
		case safeZoneX: {"safeZoneX"};
		case (0.5 - _posCtrl#2/2): {"0.5"};
		case (safeZoneX + safeZoneW - _posCtrl#2):{"safeZoneX + safeZoneW"};
		default {"0.5"};
	};
	_yAnchor = switch (_posCtrl#1) do {
		case safeZoneY: {"safeZoneY"};
		case (0.5 - _posCtrl#3/2): {"0.5"};
		case (safeZoneY + safeZoneH - _posCtrl#3):{"safeZoneY + safeZoneH"};
		default {"0.5"};
	};
	_modGrid = [_xAnchor,_yAnchor,0,0];
	TER_3den_GUIGrid set [0,_modGrid];
	["gridupdate",[]] call TER_fnc_debugPage1_script;
	_display closeDisplay 1;
};
};

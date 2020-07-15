#include "ctrls.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"
#define SELF (uiNamespace getVariable ["TER_3den_RscColorPicker_script",{}])
params ["_mode","_this"];
switch _mode do {
	case "loadColor":{
		params ["_grpColorPicker", ["_rgba",[1,1,1,1]]];
		{
			_slider = _grpColorPicker controlsGroupCtrl _x;
			private _c = _rgba param [_forEachIndex, 1];
			_slider sliderSetRange [0,1];
			_slider sliderSetSpeed [0.01, 1];
			_slider sliderSetPosition _c;
			["updateColor", [_slider,_c]] call SELF;
		} forEach [
			IDC_COLOR_SLIDERR, 
			IDC_COLOR_SLIDERG, 
			IDC_COLOR_SLIDERB, 
			IDC_COLOR_SLIDERA
		];
	};
	case "onLoad":{
		params ["_grpColorPicker"];
		if (isNil {uiNamespace getVariable "TER_3den_RscColorPicker_script"}) then {
			uiNamespace setVariable ["TER_3den_RscColorPicker_script", compile preprocessFileLineNumbers "TER_Editing\gui\scripts\RscColorPicker.sqf"];
		};
		_loadColor = uiNamespace getVariable ["TER_3den_RscColorPicker_loadColor",[1,1,1,1]];
		["loadColor", [_grpColorPicker, _loadColor]] call SELF;
		{
			_slider = _grpColorPicker controlsGroupCtrl _x;
			_slider ctrlAddEventHandler ["SliderPosChanged",{
				["updateColor",_this] call SELF;
			}];
		} forEach [
			IDC_COLOR_SLIDERR, 
			IDC_COLOR_SLIDERG, 
			IDC_COLOR_SLIDERB, 
			IDC_COLOR_SLIDERA
		];
		/* _btnClose = _grpColorPicker controlsGroupCtrl IDC_COLOR_BTNCLOSE;
		_btnClose ctrlAddEventHandler ["ButtonClick",{
			["close",_this] call SELF;
		}];
		_grpColorPicker ctrlAddEventHandler ["KeyDown",{
			["keyEH",_this] call SELF;
		}]; */
	};
	case "updateColor": {
		params ["_slider", "_newValue"];
		_grpColorPicker = ctrlParentControlsGroup _slider;
		_picRGBA = _grpColorPicker controlsGroupCtrl IDC_COLOR_PICRGBA;
		_edArray = _grpColorPicker controlsGroupCtrl IDC_COLOR_EDARRAY;
		_edTexture = _grpColorPicker controlsGroupCtrl IDC_COLOR_EDTEXTURE;
		_edConfig = _grpColorPicker controlsGroupCtrl IDC_COLOR_EDCONFIG;
		_edHTML = _grpColorPicker controlsGroupCtrl IDC_COLOR_EDHTML;
		_edit = _grpColorPicker controlsGroupCtrl (ctrlIDC _slider +4);
		_pic = _grpColorPicker controlsGroupCtrl (ctrlIDC _slider -5);
		_sliderArray = [IDC_COLOR_SLIDERR, IDC_COLOR_SLIDERG, IDC_COLOR_SLIDERB, IDC_COLOR_SLIDERA] apply {
			_grpColorPicker controlsGroupCtrl _x
		};
		// set edit number
		_edit ctrlSetText (_newValue toFixed 2);
		// set pic color
		_formatColors = [0,0,0,1];
		_index = ctrlIDC _slider - IDC_COLOR_SLIDERR;
		if (_index != 3) then {
			_formatColors set [_index, _newValue];
		} else {
			_formatColors = [1,1,1,_newValue];
		};
		_pic ctrlSetText format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +_formatColors);
		// set big picture color
		_picRGBA ctrlSetText format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +(_sliderArray apply {sliderPosition _x}));
		// set outputs
		_arrEdColor = [IDC_COLOR_EDR, IDC_COLOR_EDG, IDC_COLOR_EDB, IDC_COLOR_EDA] apply {
			_grpColorPicker controlsGroupCtrl _x
		};
		_colorArray = _arrEdColor apply {parseNumber ctrlText _x};
		_edArray ctrlSetText str _colorArray;
		_edTexture ctrlSetText str format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +_colorArray);
		_edConfig ctrlSetText format (["color[] = {%1,%2,%3,%4};"] +_colorArray);
		_edHTML ctrlSetText (_colorArray call BIS_fnc_colorRGBAtoHTML);
		uiNamespace setVariable ["TER_3den_RscColorPicker_loadColor", _colorArray];
	};
	case "keyEH":{
		params ["_grpColorPicker","_key"];
		/* if (_key == DIK_ESCAPE) exitWith {
			_btnClose = _grpColorPicker controlsGroupCtrl IDC_COLOR_BTNCLOSE;
			["close",[_btnClose]] call SELF;
			true
		};
		false */
	};
	case "close":{
		params ["_btnClose"];
		/* _display = ctrlParent _btnClose;
		diag_log _display;
		if (ctrlIDD ctrlParent _btnClose == IDC_COLOR_DISPLAYCTRL) exitWith {
			_display closeDisplay 1;
		};
		_grpColorPicker = ctrlParentControlsGroup _btnClose;
		ctrlDelete _grpColorPicker; */
	};
};

//STXT_KKCOLORPICKERLINK ctrlSetStructuredText parseText "<a href='http://killzonekid.com/hex-2-arma-gui-colour-converter/'>KillzoneKid's color picker</a>";
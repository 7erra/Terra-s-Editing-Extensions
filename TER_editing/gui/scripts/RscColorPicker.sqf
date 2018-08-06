#include "ctrls.inc"
waitUntil {!isNull COLOR_DISPLAY};
_fncUpdateColor = {
	params ["_slider", "_newValue"];
	_edit = COLOR_CTRL(ctrlIDC _slider +4);
	_pic = COLOR_CTRL(ctrlIDC _slider -5);
	// set edit number
	_edit ctrlSetText (_newValue toFixed 2);
	// set pic color
	_formatColors = [0,0,0,1];
	_index = SLIDER_ARRAY find _slider;
	if (_index != 3) then {
		_formatColors set [_index, _newValue];
	} else {
		_formatColors = [1,1,1,_newValue];
	};
	_pic ctrlSetText format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +_formatColors);
	// set big picture color
	PIC_RGBA ctrlSetText format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +(SLIDER_ARRAY apply {sliderPosition _x}));
	// set outputs
	_colorArray = EDIT_COLOR_ARRAY apply {parseNumber ctrlText _x};
	ED_ARRAY ctrlSetText str _colorArray;
	ED_TEXTURE ctrlSetText str format (["#(argb,8,8,3)color(%1,%2,%3,%4)"] +_colorArray);
	ED_CONFIG ctrlSetText format (["color[] = {%1,%2,%3,%4};"] +_colorArray);
	ED_HTML ctrlSetText (_colorArray call BIS_fnc_colorRGBAtoHTML);
};

{
	_x sliderSetRange [0,1];
	_x sliderSetSpeed [0.01, 1];
	_x sliderSetPosition 1;
	[_x,1] call _fncUpdateColor;
	_x ctrlAddEventHandler ["SliderPosChanged",_fncUpdateColor];
} forEach SLIDER_ARRAY;

//STXT_KKCOLORPICKERLINK ctrlSetStructuredText parseText "<a href='http://killzonekid.com/hex-2-arma-gui-colour-converter/'>KillzoneKid's color picker</a>";
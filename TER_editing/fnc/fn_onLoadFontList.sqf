#include "ctrls.inc"
waitUntil {!isNull FONT_DISPLAY};
// add fonts to the lb
_allFonts = ("isClass _x" configClasses (configfile >> "CfgFontFamilies")) apply {configName _x};
{
	_index = LB_FONTS lbAdd _x;
	if (_x == "RobotoCondensed") then {
		LB_FONTS lbSetTextRight [_index, "DEFAULT"];
	}
} forEach _allFonts;
_allChars = "qwertzuiopasdfghjklyxcvbnm";
_allChars = _allChars +toUpper _allChars;
_allChars = "0123456789" +_allChars +"!$%&/()=?,.-;:_<>+#*'";
_allChars = _allChars splitString "" joinString " ";
//_allChars = _allChars +preprocessFile "fontPicker\loremIpsum.txt";
STXT_FONTPREVIEW ctrlSetText _allChars;
LB_FONTS ctrlAddEventHandler ["LBSelChanged",{
	params ["_listbox","_index"];
	_newFont = _listbox lbText _index;
	STXT_FONTPREVIEW ctrlSetFont _newFont;
}];
LB_FONTS ctrlAddEventHandler ["KeyDown",{
	params ["_listbox", "_key", "_shift", "_ctrl", "_alt"];
	if (_key == 0x2E && _ctrl) then {
		copyToClipboard (_listbox lbText (lbCurSel _listbox));
	};
}];
#include "..\ctrls.inc"

if (isMultiplayer) then {
	BTN_SWITCHUNIT ctrlSetTooltip "WARNING: Switching the unit in MP will have serious consequences for the functionality of the mission. Read more on the BIKI: selectPlayer";
	BTN_SWITCHUNIT ctrlSetTooltipColorText [1,0,0,1];
};
BTN_SWITCHUNIT ctrlAddEventHandler ["ButtonDown",{
	params ["_button"];
	if (cursorObject isKindOf "MAN" && !isPlayer cursorObject) then {
		selectPlayer cursorObject;
	} else {
		[_button] spawn {
			_button = _this select 0;
			_button ctrlSetText "SWITCH UNIT - INVALID TARGET";
			_button ctrlSetTextColor [1,0,0,1];
			uisleep 1;
			_button ctrlSetText "SWITCH UNIT";
			_button ctrlSetTextColor [1,1,1,1];
		};
	};
}];
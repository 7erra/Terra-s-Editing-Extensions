class RscDisplayConfigViewer
{
	class controls
	{
		class BTN_exportCfg: RscButtonMenu
		{
			idc=7301;
			text = "Export";
			x="32.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
			y="safezoneY + safezoneH - 2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="11.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			onButtonClick = "[] spawn TER_fnc_exportCfg; true";
			tooltip = "Copy the content of the current config to the clipboard";
		};
	};
};

class RscTER_3den_ezGUITip
{
	idd = 73002;
	onLoad = "uiNamespace setVariable [""TER_3den_tipDisplay"",_this select 0];";
	class controlsBackground
	{
		class full_backgroundTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class full_background: ctrlStaticBackgroundDisable
		{
		};
		class background: ctrlStaticBackground
		{
			idc = -1;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.178 * safezoneH + safezoneY;
			w = 0.49875 * safezoneW;
			h = 0.644 * safezoneH;
		};
		class TITLE_tip: TER_3den_RscTitleBackground
		{
			idc = 7310;
			text = "Title"; //--- ToDo: Localize;
			x = 0.250625 * safezoneW + safezoneX;
			y = 0.1416 * safezoneH + safezoneY;
			w = 0.49875 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
	class controls
	{
		class BTN_ok: RscButtonMenuOK
		{
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.78 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class GRP_tipMain: RscControlsGroup
		{
			idc = 7300;
			x = 0.257187 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.485625 * safezoneW;
			h = 0.574 * safezoneH;
			class controls
			{
				class STXT_tipText: RscStructuredText
				{
					idc = 7320;
					x=0;
					y=0;
					w = 0.485625 * safezoneW;
					h = 0.574 * safezoneH;
				};
			};
		};
	};
};
class RscTER_3den_ezGUI
{
	idd = 73001;
	ONLOAD(EzGUI)
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
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.0520002 * safezoneH + safezoneY;
			w = 0.525 * safezoneW;
			h = 0.938 * safezoneH;
		};
		class INDEX_background: ctrlStaticBackground
		{
			idc = 7330;

			x = 0.0078125 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.223125 * safezoneW;
			h = 0.938 * safezoneH;
		};
		class INDEX_title: RscText
		{
			idc = 7301;
			text = "Select chapter:"; //--- ToDo: Localize;
			x = 0.014375 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.21 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TITLE_easyGUI: TER_3den_RscTitleBackground
		{
			idc = -1;
			text = "Easy GUI"; //--- ToDo: Localize;
			x = 0.2375 * safezoneW + safezoneX;
			y = 0.0156 * safezoneH + safezoneY;
			w = 0.525 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class TXT_current: RscText
		{
			idc = 7300;
			style = ST_CENTER;
			text = "Part X: Name of part X"; //--- ToDo: Localize;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.906 * safezoneH + safezoneY;
			w = 0.511875 * safezoneW;
			h = 0.028 * safezoneH;
		};
	};
	class controls
	{
		class BTN_next: RscButtonMenu
		{
			idc = 7310;
			text = "Part X+1: Name of part X+1"; //--- ToDo: Localize;
			x = 0.506562 * safezoneW + safezoneX;
			y = 0.948 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class BTN_prev: RscButtonMenu
		{
			idc = 7311;
			text = "Part x-1: Name of part x-1"; //--- ToDo: Localize;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.948 * safezoneH + safezoneY;
			w = 0.249375 * safezoneW;
			h = 0.028 * safezoneH;
		};
		class GRP_main: RscControlsGroup
		{
			idc = 7320;
			x = 0.244062 * safezoneW + safezoneX;
			y = 0.066 * safezoneH + safezoneY;
			w = 0.511875 * safezoneW;
			h = 0.826 * safezoneH;
			class Controls
			{
			};
		};
		class BTN_close: RscActivePictureKeepAspect
		{
			text = "\A3\Modules_F_Kart\data\TimeTrials\quit_igui_ca.paa"; //--- ToDo: Localize;
			style = ST_PICTURE;
			x = 0.74675 * safezoneW + safezoneX;
			y = 0.0156 * safezoneH + safezoneY;
			w = 3024/192000 * safezoneW;
			h = 3024/108000 * safezoneH;
			action = "(findDisplay 73001) closeDisplay 1;";
		};
		class TREE_index: RscTree
		{
			idc = 7321;

			x = 0.014375 * safezoneW + safezoneX;
			y = 0.108 * safezoneH + safezoneY;
			w = 0.203437 * safezoneW;
			h = 0.868 * safezoneH;
			//class Controls
			//{
			//};
		};/*
		class BTN_index: RscButtonMenu
		{
			idc = 2402;
			style = ST_VERTICAL;
			text = "INDEX"; //--- ToDo: Localize;
			x = 0.209937 * safezoneW + safezoneX;
			y = 0.052 * safezoneH + safezoneY;
			w = 0.0196875 * safezoneW;
			h = 0.938 * safezoneH;
		};*/

	};
};

////////////////////////////////////////////////////////

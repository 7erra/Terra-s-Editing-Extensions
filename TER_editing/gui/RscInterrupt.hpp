#include "RscDebug.hpp"
class RscDebugConsole
{
	class controls
	{
		class Title: RscButton
		{
			idc=11884;
			text="$STR_UI_DEBUG_TITLE";
			x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			style = ST_LEFT;
			colorText[] = {1,1,1,1};
			period = -1;
			//blinkingPeriod = 0;
			colorDisabled[] = GUI_BCG_COLOR;
			colorBackground[] = GUI_BCG_COLOR;
			colorBackgroundDisabled[] = GUI_BCG_COLOR;
			colorBackgroundActive[] = GUI_BCG_COLOR;
			colorFocused[] = GUI_BCG_COLOR;
			colorShadow[] = {0,0,0,0};
			colorBorder[] = {0,0,0,1};
			soundEnter[] = {"", 0.09, 1};
			soundPush[] = {"", 0.09, 1};
			soundClick[] = {"", 0.09, 1};
			soundEscape[] = {"", 0.09, 1};
		};
	};
};
class RscDisplayInterrupt
{
	class controls 
	{
		class TER_3den_RscDebugConsoleControl: TER_3den_debugConsole 
		{
		};
		class DebugConsole: RscDebugConsole
		{
			x = GUI_GRID_X + (profileNamespace getVariable ["TER_EDITING_VANILLADEBUG_X", 17]) * GUI_GRID_W;
			/* class controls
			{
				class Title: RscButton
				{
					colorBackground[]=
					{
						"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
					};
					idc=11884;
					text="$STR_UI_DEBUG_TITLE";
					x= 0 * GUI_GRID_W;
					y= 0 * GUI_GRID_H;
					w= 22 * GUI_GRID_W;
					h= 1 * GUI_GRID_H;
				};
			}; */
		};
	};
};
class RscDisplayMPInterrupt
{
	class controls 
	{
		class TER_3den_RscDebugConsoleControl: TER_3den_debugConsole 
		{
		};
		class DebugConsole: RscDebugConsole
		{
			x = GUI_GRID_X + (profileNamespace getVariable ["TER_EDITING_VANILLADEBUG_X", 17]) * GUI_GRID_W;
		};
	};
};
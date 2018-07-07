class RscTitles
{
	class default
	{
		idd = -1;
		fadein = 0;
		fadeout = 0;
		duration = 0;
	};
	class TER_RscDisplayTargetDebug
	{
		idd = 73042;
		fadeIn = 0;
		fadeOut = 0;
		duration = 1e+6;
		onLoad = "uiNamespace setVariable [""TER_3den_RscTargetDebug_display"",_this select 0]";
		class controls
		{
			class sText_debug: RscStructuredText
			{
				idc = 7300;
				size = 0.7 * GUI_GRID_H;
				class Attributes
				{
					font="EtelkaMonospacePro";
				};
				colorBackground[] = {0,0,0,0.2};
				x = 1 * GUI_GRID_W + GUI_GRID_X;
				y = 0 * GUI_GRID_H + GUI_GRID_Y;
				w = 19 * GUI_GRID_W;
				h = 1 * GUI_GRID_H;
			};
		};
	};
	
	#include "..\watch\RscLiveWatch.hpp"
	#include "..\debug\RscGrids.hpp"
};
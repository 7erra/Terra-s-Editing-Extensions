class TER_RscDisplayGrids
{
	idd = 73041;
	duration = 1e+6;
	fadeIn = 0;
	fadeOut = 0;
	onLoad = "uiNamespace setVariable [""TER_3den_RscGrids_display"",_this select 0];";
	class controls 
	{
		class line_middleV: RscText
		{
			x = 0.5;
			y = safeZoneY;
			w = pixelW;
			h = safeZoneH;
			colorBackground[] = {0,1,1,1};
		};
		class line_middleH: RscText
		{
			x = safeZoneX;
			y = 0.5;
			w = safeZoneW;
			h = pixelh;
			colorBackground[] = {0,1,1,1};
		};
		class frame_absolute: RscFrame
		{
			x = 0;
			y = 0;
			w = 1;
			h = 1;
			colorText[] = {0,1,1,1};
		};
	};
};
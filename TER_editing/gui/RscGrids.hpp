class TER_RscDisplayGrids
{
	idd = IDD_DISPLAY_GRIDS;
	duration = 1e+6;
	fadeIn = 0;
	fadeOut = 0;
	ONLOAD(RscGrids);
	class controls 
	{
		class background : RscText
		{
			x = safeZoneXAbs;
			y = safeZoneY;
			w = safeZoneWAbs;
			h = safeZoneH;
			colorBackground[] = { 1,1,1,0.8 };
		};
		class absXT : RscText
		{
			x = 0;
			y = 0;
			w = 1;
			h = pixelH;
			colorBackground[] = { 0,1,0,0.5 };
		};
		class absXB : absXT
		{
			y = 1;
		};
		class absYL : absXT
		{
			w = pixelW;
			h = 1;
		};
		class absYR : absYL
		{
			x = 1;
		};
		class line_middleV: RscText
		{
			x = 0.5 - pixelW;
			y = safeZoneY;
			w = 2 * pixelW;
			h = safeZoneH;
			colorBackground[] = { 1,1,0,1 };
		};
		class line_middleH: RscText
		{
			x = safeZoneX;
			y = 0.5 - pixelH;
			w = safeZoneW;
			h = 2 * pixelh;
			colorBackground[] = { 1,1,0,1 };
		};
		/*
		class txt_safeArea: RscText
		{
			idc = IDC_GRIDS_SAFEAREA;
			colorBackground[] = {0,1,0,0.2};
			x = 0;
			y = 0;
			w = GUI_GRID_WAbs;
			h = GUI_GRID_HAbs;
		};
		class txt_unsafeLeft: RscText
		{
			idc = IDC_GRIDS_UNSAFELEFT;
			x = 0;
			y = 0;
			w = 0;
			h = 0;
			colorBackground[] = {1,0,0,0.2};
		};
		class txt_unsafeRight: txt_unsafeLeft
		{
			idc = IDC_GRIDS_UNSAFERIGHT;
		};
		class txt_unsafeTop: txt_unsafeLeft
		{
			idc = IDC_GRIDS_UNSAFETOP;
		};
		class txt_unsafeBottom: txt_unsafeLeft
		{
			idc = IDC_GRIDS_UNSAFEBOTTOM;
		};
		class test_safeUIGrid: RscText
		{
			colorBackground[] = {0,1,0,0.5};
			x = 0.5 - (getNumber(configFile >> "uiScaleMaxGrids") * pixelGrid * pixelW)/2;
			y = 0.5 - (getNumber(configFile >> "uiScaleMaxGrids") * pixelGrid * pixelH)/2;
			w = getNumber(configFile >> "uiScaleMaxGrids") * pixelGrid * pixelW;
			h = getNumber(configFile >> "uiScaleMaxGrids") * pixelGrid * pixelH;
		};
		*/
	};
};
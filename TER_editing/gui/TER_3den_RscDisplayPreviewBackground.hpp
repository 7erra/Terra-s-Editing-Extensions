class TER_3den_RscDisplayPreviewBackground
{
	idd = -1;
	fadeIn = 0;
	fadeOut = 0;
	duration = 10e+6;
	INIT_DISPLAY(TER_3den_RscDisplayPreviewBackground, "TER_Eden")
	class controlsBackground
	{		
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroudnDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
	};
	class controls
	{
		class DisclaimerTop: RscText
		{
			idc = IDC_PREVIEWBACKGROUND_TXTDISCLAIMERTOP;
			text = "PREVIEW";
			style = ST_CENTER;
			shadow = 0;
			x = safeZoneXAbs;
			y = safeZoneY + 1 * GUI_GRID_H;
			w = safeZoneWAbs;
			h = 1 * GUI_GRID_H;
		};
		class DisclaimerBottom: DisclaimerTop
		{
			idc = IDC_PREVIEWBACKGROUND_TXTDISCLAIMERBOTTOM;
			y = safeZoneY + safeZoneH - 2 * GUI_GRID_H;
		};
	};
};
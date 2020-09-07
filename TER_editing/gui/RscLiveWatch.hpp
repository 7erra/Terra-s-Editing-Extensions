class TER_3den_RscLiveWatch
{
	idd = IDD_DISPLAY_LIVEWATCH;
	duration = 1e+6;
	fadeIn = 0;
	fadeOut = 0;
	onLoad = "[""onload"",_this] execVM ""TER_Editing\gui\scripts\RscLiveWatch.sqf"";";
	class controls
	{
		class table_watch: RscControlsTable
		{
			idc = IDC_LIVE_TABLE;
			x = 0.5 - 15 * GUI_GRID_W;
			y = safeZoneY + 0.1 * GUI_GRID_H;
			w = 30 * GUI_GRID_W;
			h = 23 * GUI_GRID_H;
			lineSpacing = 0.1 * GUI_GRID_H;
			firstIDC = IDC_LIVE_STARTIDC;
			lastIDC = IDC_LIVE_LASTIDC;
			class RowTemplate
			{
				class RowBackground
				{
					controlBaseClassPath[] = {"RscText"};
					columnX = 0;
					columnW = 0 * GUI_GRID_W;
					controlOffsetY = 0;
				};
				class Column1: RowBackground
				{
					columnW = 14.95 * GUI_GRID_W;
				};
				class Column2: Column1
				{
					columnX = 15.05 * GUI_GRID_W;
				};
			};
		};
	};
};

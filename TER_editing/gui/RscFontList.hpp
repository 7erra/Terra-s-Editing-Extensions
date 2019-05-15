class TER_3den_RscFontList
{
	idd = IDD_DISPLAY_FONTLIST;
	enableSimulation = false;
	ONLOAD(FontList)
	class controlsBackground
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class title_fontpicker: ctrlStaticTitle
		{
			text = "Font picker"; //--- ToDo: Localize;
			x = 19.9 * UI_GRID_W + UI_GRID_X;
			y = 6.4 * UI_GRID_H + UI_GRID_Y;
			w = 24.2 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class background: ctrlStaticBackground
		{
			x = 19.9 * UI_GRID_W + UI_GRID_X;
			y = 7.4 * UI_GRID_H + UI_GRID_Y;
			w = 24.2 * UI_GRID_W;
			h = 20.2 * UI_GRID_H;
		};
		class txt_hintControl: ctrlStructuredText
		{
			text = "Press CTRL+C to copy font name"; //--- ToDo: Localize;
			x = 20 * UI_GRID_W + UI_GRID_X;
			y = 26.1 * UI_GRID_H + UI_GRID_Y;
			w = 12 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class stxt_fontPreview: ctrlStructuredText
		{
			idc = 7300;
			text = "Preview:"; //--- ToDo: Localize;
			x = 32 * UI_GRID_W + UI_GRID_X;
			y = 7.5 * UI_GRID_H + UI_GRID_Y;
			w = 12 * UI_GRID_W;
			h = 18.5 * UI_GRID_H;
		};
	};
	class controls
	{
		class lb_fonts: ctrlListbox
		{
			idc = 7301;
			x = 20 * UI_GRID_W + UI_GRID_X;
			y = 7.5 * UI_GRID_H + UI_GRID_Y;
			w = 12 * UI_GRID_W;
			h = 18.5 * UI_GRID_H;
		};
		class btn_ok: ctrlButtonClose
		{
			x = 32 * UI_GRID_W + UI_GRID_X;
			y = 26.1 * UI_GRID_H + UI_GRID_Y;
			w = 12 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};

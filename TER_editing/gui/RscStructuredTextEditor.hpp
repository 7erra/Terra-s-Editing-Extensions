class TER_3den_RscStxtEditor
{
	idd = IDD_DISPLAY_STRUCTUREDTEXTEDITOR;
	enableSimulation = false;
	ONLOAD(StxtEditor)
	class controlsBackground
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class background: ctrlStaticBackground
		{
			x = 10.5 * UI_GRID_W + UI_GRID_X;
			y = 5.4 * UI_GRID_H + UI_GRID_Y;
			w = 43 * UI_GRID_W;
			h = 28 * UI_GRID_H;
		};
		class title_stxtEditor: ctrlStaticTitle
		{
			text = "Structured Text Editor"; //--- ToDo: Localize;
			x = 10.5 * UI_GRID_W + UI_GRID_X;
			y = 4.4 * UI_GRID_H + UI_GRID_Y;
			w = 43 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
	class controls
	{
		class edit_stxt_input: ctrlEdit
		{
			idc = 7300;
			style = ST_MULTI;
			x = 11 * UI_GRID_W + UI_GRID_X;
			y = 6 * UI_GRID_H + UI_GRID_Y;
			w = 30.5 * UI_GRID_W;
			h = 12.5 * UI_GRID_H;
		};
		class stxt_stxt_output: ctrlStructuredText
		{
			idc = 7301;
			colorBackground[] = {0,0,0,0.8};
			x = 11 * UI_GRID_W + UI_GRID_X;
			y = 19 * UI_GRID_H + UI_GRID_Y;
			w = 30.5 * UI_GRID_W;
			h = 12.5 * UI_GRID_H;
		};
		class lb_stxt_formats: ctrlListbox
		{
			idc = 7302;
			style = LB_MULTI;
			x = 42 * UI_GRID_W + UI_GRID_X;
			y = 6 * UI_GRID_H + UI_GRID_Y;
			w = 11 * UI_GRID_W;
			h = 11 * UI_GRID_H;
		};
		class btn_addFormat: ctrlButton
		{
			idc = 7306;
			text = "ADD";
			x = 42 * UI_GRID_W + UI_GRID_X;
			y = 17.5 * UI_GRID_H + UI_GRID_Y;
			w = 11 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class stxt_info: ctrlStructuredText
		{
			idc = 7305;
			x = 42 * UI_GRID_W + UI_GRID_X;
			y = 19 * UI_GRID_H + UI_GRID_Y;
			w = 11 * UI_GRID_W;
			h = 11 * UI_GRID_H;
		};
		class btn_cancel: ctrlButtonClose
		{
			x = 11 * UI_GRID_W + UI_GRID_X;
			y = 32 * UI_GRID_H + UI_GRID_Y;
			w = 11 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class stxt_bisLink: ctrlStructuredText
		{
			idc = 7304;
			x = 23 * UI_GRID_W + UI_GRID_X;
			y = 32 * UI_GRID_H + UI_GRID_Y;
			w = 18 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class btn_colorPicker: ctrlButton
		{
			idc = 7303;
			text = "COLOR PICKER"; //--- ToDo: Localize;
			x = 42 * UI_GRID_W + UI_GRID_X;
			y = 32 * UI_GRID_H + UI_GRID_Y;
			w = 11 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class btn_fontPicker: btn_colorPicker
		{
			idc = 7307;
			text = "FONT LIST";
			y = 30.5 * UI_GRID_H + UI_GRID_Y;
		};
		
	};
};

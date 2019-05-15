class TER_3den_RscColorPicker
{
	idd = IDD_DISPLAY_COLORPICKER;
	enableSimulation = false;
	ONLOAD(ColorPicker)
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
			x = 17.4 * UI_GRID_W + UI_GRID_X;
			y = 10.9 * UI_GRID_H + UI_GRID_Y;
			w = 29.5 * UI_GRID_W;
			h = 8.9 * UI_GRID_H;
		};
		class title_colorPicker: ctrlStaticTitle
		{
			text = "Color Picker"; //--- ToDo: Localize;
			x = 17.4 * UI_GRID_W + UI_GRID_X;
			y = 9.9 * UI_GRID_H + UI_GRID_Y;
			w = 29.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_red: ctrlStructuredText
		{
			idc = 1000;
			text = "R"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W + UI_GRID_X;
			y = 11 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_green: ctrlStructuredText
		{
			idc = 1001;
			text = "G"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W + UI_GRID_X;
			y = 12.1 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_blue: ctrlStructuredText
		{
			idc = 1002;
			text = "B"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W + UI_GRID_X;
			y = 13.2 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_alpha: ctrlStructuredText
		{
			idc = 1003;
			text = "A"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W + UI_GRID_X;
			y = 14.3 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_array: ctrlStructuredText
		{
			idc = 1004;
			text = "Array:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 15.4 * UI_GRID_H + UI_GRID_Y;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_config: ctrlStructuredText
		{
			idc = 1005;
			text = "config:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 17.6 * UI_GRID_H + UI_GRID_Y;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_html: ctrlStructuredText
		{
			idc = 1006;
			text = "HTML:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 18.7 * UI_GRID_H + UI_GRID_Y;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_texture: ctrlStructuredText
		{
			idc = 1007;
			text = "Texture:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 16.5 * UI_GRID_H + UI_GRID_Y;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_red: ctrlStaticPicture
		{
			idc = 7300;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W + UI_GRID_X;
			y = 11 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_green: ctrlStaticPicture
		{
			idc = 7301;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W + UI_GRID_X;
			y = 12.1 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_blue: ctrlStaticPicture
		{
			idc = 7302;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W + UI_GRID_X;
			y = 13.2 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_alpha: ctrlStaticPicture
		{
			idc = 7303;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W + UI_GRID_X;
			y = 14.3 * UI_GRID_H + UI_GRID_Y;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_rgba: ctrlStaticPicture
		{
			idc = 7304;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 42.5 * UI_GRID_W + UI_GRID_X;
			y = 11 * UI_GRID_H + UI_GRID_Y;
			w = 4.3 * UI_GRID_W;
			h = 4.3 * UI_GRID_H;
		};
	};
	class controls
	{
		class slider_red: ctrlXSliderH
		{
			idc = 7305;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 11 * UI_GRID_H + UI_GRID_Y;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {1,0,0,0.6};
			colorActive[] = {1,0,0,1};
		};
		class slider_green: ctrlXSliderH
		{
			idc = 7306;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 12.1 * UI_GRID_H + UI_GRID_Y;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {0,1,0,0.6};
			colorActive[] = {0,1,0,1};
		};
		class slider_blue: ctrlXSliderH
		{
			idc = 7307;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 13.2 * UI_GRID_H + UI_GRID_Y;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {0,0,1,0.6};
			colorActive[] = {0,0,1,1};
		};
		class slider_alpha: ctrlXSliderH
		{
			idc = 7308;
			x = 17.5 * UI_GRID_W + UI_GRID_X;
			y = 14.3 * UI_GRID_H + UI_GRID_Y;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_red: ctrlEdit
		{
			idc = 7309;
			canModify = 0;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 11 * UI_GRID_H + UI_GRID_Y;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_green: ed_red
		{
			idc = 7310;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 12.1 * UI_GRID_H + UI_GRID_Y;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_blue: ed_red
		{
			idc = 7311;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 13.2 * UI_GRID_H + UI_GRID_Y;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_alpha: ed_red
		{
			idc = 7312;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 14.3 * UI_GRID_H + UI_GRID_Y;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_array: ctrlEdit
		{
			idc = 7313;
			x = 21.5 * UI_GRID_W + UI_GRID_X;
			y = 15.4 * UI_GRID_H + UI_GRID_Y;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_texture: ctrlEdit
		{
			idc = 7314;
			x = 21.5 * UI_GRID_W + UI_GRID_X;
			y = 16.5 * UI_GRID_H + UI_GRID_Y;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_config: ctrlEdit
		{
			idc = 7315;
			x = 21.5 * UI_GRID_W + UI_GRID_X;
			y = 17.6 * UI_GRID_H + UI_GRID_Y;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_html: ctrlEdit
		{
			idc = 7316;
			x = 21.5 * UI_GRID_W + UI_GRID_X;
			y = 18.7 * UI_GRID_H + UI_GRID_Y;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
/*		class stxt_kkcolorpickerLink: ctrlStructuredText
		{
			idc = 7317;
			text = "KillzoneKid's color picker"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 17.6 * UI_GRID_H + UI_GRID_Y;
			w = 9.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
*/		class btn_ok: ctrlButtonClose
		{
			x = 37.5 * UI_GRID_W + UI_GRID_X;
			y = 18.7 * UI_GRID_H + UI_GRID_Y;
			w = 9.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};

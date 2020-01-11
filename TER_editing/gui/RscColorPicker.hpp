class TER_3den_RscColorPicker_control: ctrlControlsGroupNoScrollbars
{
	idc = IDC_COLOR_DISPLAYCTRL;
	x = safeZoneX;
	y = safeZoneY;
	w = safeZoneW;
	h = safeZoneH;
	ONLOAD(RscColorPicker);
	class controls
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class background: ctrlStaticBackground
		{
			x = 17.4 * UI_GRID_W;
			y = 10.9 * UI_GRID_H;
			w = 29.5 * UI_GRID_W;
			h = 8.9 * UI_GRID_H;
		};
		class title_colorPicker: ctrlStaticTitle
		{
			text = "Color Picker"; //--- ToDo: Localize;
			x = 17.4 * UI_GRID_W;
			y = 9.9 * UI_GRID_H;
			w = 29.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_red: ctrlStructuredText
		{
			text = "R"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W;
			y = 11 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_green: ctrlStructuredText
		{
			text = "G"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W;
			y = 12.1 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_blue: ctrlStructuredText
		{
			text = "B"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W;
			y = 13.2 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_alpha: ctrlStructuredText
		{
			text = "A"; //--- ToDo: Localize;
			x = 40 * UI_GRID_W;
			y = 14.3 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_array: ctrlStructuredText
		{
			text = "Array:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W;
			y = 15.4 * UI_GRID_H;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_config: ctrlStructuredText
		{
			text = "config:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W;
			y = 17.6 * UI_GRID_H;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_html: ctrlStructuredText
		{
			text = "HTML:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W;
			y = 18.7 * UI_GRID_H;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_texture: ctrlStructuredText
		{
			text = "Texture:"; //--- ToDo: Localize;
			x = 17.5 * UI_GRID_W;
			y = 16.5 * UI_GRID_H;
			w = 3.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_red: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICR;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W;
			y = 11 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_green: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICG;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W;
			y = 12.1 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_blue: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICB;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W;
			y = 13.2 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_alpha: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICA;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 41 * UI_GRID_W;
			y = 14.3 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class pic_rgba: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICRGBA;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 42.5 * UI_GRID_W;
			y = 11 * UI_GRID_H;
			w = 4.3 * UI_GRID_W;
			h = 4.3 * UI_GRID_H;
		};
		class slider_red: ctrlXSliderH
		{
			idc = IDC_COLOR_SLIDERR;
			x = 17.5 * UI_GRID_W;
			y = 11 * UI_GRID_H;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {1,0,0,0.6};
			colorActive[] = {1,0,0,1};
		};
		class slider_green: ctrlXSliderH
		{
			idc = IDC_COLOR_SLIDERG;
			x = 17.5 * UI_GRID_W;
			y = 12.1 * UI_GRID_H;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {0,1,0,0.6};
			colorActive[] = {0,1,0,1};
		};
		class slider_blue: ctrlXSliderH
		{
			idc = IDC_COLOR_SLIDERB;
			x = 17.5 * UI_GRID_W;
			y = 13.2 * UI_GRID_H;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {0,0,1,0.6};
			colorActive[] = {0,0,1,1};
		};
		class slider_alpha: ctrlXSliderH
		{
			idc = IDC_COLOR_SLIDERA;
			x = 17.5 * UI_GRID_W;
			y = 14.3 * UI_GRID_H;
			w = 19.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_red: ctrlEdit
		{
			idc = IDC_COLOR_EDR;
			canModify = 0;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W;
			y = 11 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_green: ed_red
		{
			idc = IDC_COLOR_EDG;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W;
			y = 12.1 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_blue: ed_red
		{
			idc = IDC_COLOR_EDB;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W;
			y = 13.2 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_alpha: ed_red
		{
			idc = IDC_COLOR_EDA;
			text = "0.888"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W;
			y = 14.3 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_array: ctrlEdit
		{
			idc = IDC_COLOR_EDARRAY;
			x = 21.5 * UI_GRID_W;
			y = 15.4 * UI_GRID_H;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_texture: ctrlEdit
		{
			idc = IDC_COLOR_EDTEXTURE;
			x = 21.5 * UI_GRID_W;
			y = 16.5 * UI_GRID_H;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_config: ctrlEdit
		{
			idc = IDC_COLOR_EDCONFIG;
			x = 21.5 * UI_GRID_W;
			y = 17.6 * UI_GRID_H;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_html: ctrlEdit
		{
			idc = IDC_COLOR_EDHTML;
			x = 21.5 * UI_GRID_W;
			y = 18.7 * UI_GRID_H;
			w = 15.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
/*		class stxt_kkcolorpickerLink: ctrlStructuredText
		{
			idc = IDC_COLOR_STXTKKCOLORPICKERLINK;
			text = "KillzoneKid's color picker"; //--- ToDo: Localize;
			x = 37.5 * UI_GRID_W;
			y = 17.6 * UI_GRID_H;
			w = 9.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
*/		class btn_close: ctrlButton
		{
			idc = IDC_COLOR_BTNCLOSE;
			text = "CLOSE";
			x = 37.5 * UI_GRID_W;
			y = 18.7 * UI_GRID_H;
			w = 9.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};
class TER_3den_RscColorPicker
{
	idd = IDC_COLOR_DISPLAYCTRL;
	class controls
	{
		class colorPicker: TER_3den_RscColorPicker_control
		{
		};
	};
};
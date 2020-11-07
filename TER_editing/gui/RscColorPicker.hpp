#define W_COLORPICKER 30
#define H_COLORPICKER 8.9
class TER_3den_ctrlColorPicker: ctrlControlsGroupNoScrollbars
{
	idc = IDC_COLOR_DISPLAYCTRL;
	INIT_CONTROL(TER_3den_ctrlColorPicker, "TER_Editing")
	x = 0;
	y = 0;
	w = W_COLORPICKER * UI_GRID_W;
	h = H_COLORPICKER * UI_GRID_H;
	class controls
	{
		class background: ctrlStaticBackground
		{
			x = 0;
			y = 0;
			w = W_COLORPICKER * UI_GRID_W;
			h = H_COLORPICKER * UI_GRID_H;
		};
		class txt_red: ctrlStructuredText
		{
			text = "R"; //--- ToDo: Localize;
			x = 0.1 * UI_GRID_W;
			y = 0.1 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class slider_red: ctrlXSliderH
		{
			idc = IDC_COLOR_SLIDERR;
			x = 1.1 * UI_GRID_W;
			y = 0.1 * UI_GRID_H;
			w = (W_COLORPICKER - H_COLORPICKER - 3.4) * UI_GRID_W;
			h = 1 * UI_GRID_H;
			color[] = {1,0,0,0.6};
			colorActive[] = {1,0,0,1};
		};
		class ed_red: ctrlEdit
		{
			idc = IDC_COLOR_EDR;
			canModify = 0;
			text = "0.888"; //--- ToDo: Localize;
			x = (W_COLORPICKER - H_COLORPICKER - 3.4 + 1.2) * UI_GRID_W;
			y = 0.1 * UI_GRID_H;
			w = 2 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_green: txt_red
		{
			text = "G"; //--- ToDo: Localize;
			y = 1.2 * UI_GRID_H;
		};
		class slider_green: slider_red
		{
			idc = IDC_COLOR_SLIDERG;
			y = 1.2 * UI_GRID_H;
			color[] = {0,1,0,0.6};
			colorActive[] = {0,1,0,1};
		};
		class ed_green: ed_red
		{
			idc = IDC_COLOR_EDG;
			y = 1.2 * UI_GRID_H;
		};
		class txt_blue: txt_red
		{
			text = "B"; //--- ToDo: Localize;
			y = 2.3 * UI_GRID_H;
		};
		class slider_blue: slider_red
		{
			idc = IDC_COLOR_SLIDERB;
			y = 2.3 * UI_GRID_H;
			color[] = {0,0,1,0.6};
			colorActive[] = {0,0,1,1};
		};
		class ed_blue: ed_red
		{
			idc = IDC_COLOR_EDB;
			y = 2.3 * UI_GRID_H;
		};
		class txt_alpha: txt_red
		{
			text = "A"; //--- ToDo: Localize;
			y = 3.4 * UI_GRID_H;
		};
		class slider_alpha: slider_red
		{
			idc = IDC_COLOR_SLIDERA;
			y = 3.4 * UI_GRID_H;
			color[] = {1,1,1,0.6};
			colorActive[] = {1,1,1,1};
		};
		class ed_alpha: ed_red
		{
			idc = IDC_COLOR_EDA;
			text = "0.888"; //--- ToDo: Localize;
			y = 3.4 * UI_GRID_H;
		};
		class txt_array: txt_red
		{
			text = "Array:"; //--- ToDo: Localize;
			y = 4.5 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_array: ctrlEdit
		{
			idc = IDC_COLOR_EDARRAY;
			x = 2.6 * UI_GRID_W;
			y = 4.5 * UI_GRID_H;
			w = (W_COLORPICKER - H_COLORPICKER - 2.8) * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_config: txt_red
		{
			text = "config:"; //--- ToDo: Localize;
			y = 5.6 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
		};
		class ed_config: ed_array
		{
			idc = IDC_COLOR_EDCONFIG;
			y = 5.6 * UI_GRID_H;
		};
		class txt_html: txt_red
		{
			text = "HTML:"; //--- ToDo: Localize;
			y = 6.7 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
		};
		class ed_html: ed_array
		{
			idc = IDC_COLOR_EDHTML;
			y = 6.7 * UI_GRID_H;
		};
		class txt_texture: txt_red
		{
			text = "Texture:"; //--- ToDo: Localize;
			y = 7.8 * UI_GRID_H;
			w = 2.5 * UI_GRID_W;
		};
		class ed_texture: ed_array
		{
			idc = IDC_COLOR_EDTEXTURE;
			y = 7.8 * UI_GRID_H;
		};
		/* class pic_red: ctrlStaticPicture
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
		}; */
		class frame_rgba: ctrlStaticFrame
		{
			x = (W_COLORPICKER - H_COLORPICKER) * UI_GRID_W - pixelW;
			y = 0.1 * UI_GRID_H - pixelH;
			w = (H_COLORPICKER - 0.1) * UI_GRID_W + 3 * pixelW;
			h = (H_COLORPICKER - 0.2) * UI_GRID_H + 3 * pixelH;
		};
		class pic_rgba: ctrlStaticPicture
		{
			idc = IDC_COLOR_PICRGBA;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = (W_COLORPICKER - H_COLORPICKER) * UI_GRID_W;
			y = 0.1 * UI_GRID_H;
			w = (H_COLORPICKER - 0.1) * UI_GRID_W;
			h = (H_COLORPICKER - 0.2) * UI_GRID_H;
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
*/		
	};
};

#define X_COLORPICKER (0.5 - 0.5 * W_COLORPICKER * UI_GRID_W)
#define Y_COLORPICKER (0.5 - 0.5 * H_COLORPICKER * UI_GRID_H)
class TER_3den_RscColorPicker
{
	idd = IDC_COLOR_DISPLAYCTRL;
	class controlsBackground
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class title_colorPicker: ctrlStaticTitle
		{
			text = "Color Picker"; //--- ToDo: Localize;
			x = X_COLORPICKER;
			y = Y_COLORPICKER - 1 * UI_GRID_H;
			w = W_COLORPICKER * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class footer_background: ctrlStaticBackground
		{
			x = X_COLORPICKER;
			y = Y_COLORPICKER + H_COLORPICKER * UI_GRID_H;
			w = W_COLORPICKER * UI_GRID_W;
			h = 1.4 * UI_GRID_H;
		};
		class footer: ctrlStaticFooter
		{
			x = X_COLORPICKER;
			y = Y_COLORPICKER + H_COLORPICKER * UI_GRID_H;
			w = W_COLORPICKER * UI_GRID_W;
			h = 1.4 * UI_GRID_H;
		};
	};
	class controls
	{
		class colorPicker: TER_3den_ctrlColorPicker
		{
			x = X_COLORPICKER;
			y = Y_COLORPICKER;
		};
		class btn_close: ctrlButtonClose
		{
			//idc = IDC_COLOR_BTNCLOSE;
			//text = "CLOSE";
			x = X_COLORPICKER +(W_COLORPICKER - 10.2) * UI_GRID_W;
			y = Y_COLORPICKER + (H_COLORPICKER + 0.2) * UI_GRID_H;
			w = 10 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};
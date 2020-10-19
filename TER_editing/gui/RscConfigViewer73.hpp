// Debug
#ifdef DEBUG_W
#undef DEBUG_W
#endif
#define DEBUG_W onLoad = "systemchat str [ctrltextwidth (_this#0) / (2.5 * pixelGrid * pixelW)];";
// Positions
#define _L (safeZoneX)
#define _R (safeZoneX + safeZoneW)
#define _T (safeZoneY)
#define _B (safeZoneY + safeZoneH)
#define MARGIN(COUNT) (COUNT * 0.1)
#define COLUMN_L_W 12.5
// Appearance
#define TECH_FONT 			font = "EtelkaMonospacePro";\
			sizeEx = 0.7 * UI_GRID_H;\
			shadow=0;

// Beginning of display config
class TER_3den_RscDisplayConfigViewer73
{
	idd = IDD_DISPLAY_CONFIGVIEWER;
	//ONLOAD(RscConfigViewer73);
	INIT_DISPLAY(TER_3den_RscDisplayConfigViewer73, "TER_Editing")
	class controlsBackground
	{
		class background: ctrlStaticBackground
		{
			x = _L;
			y = _T;
			w = safeZoneW;
			h = safeZoneH;
			colorBackground[] = GUI_BCG_MENU;
		};
		class 3denBackground: RscText
		{
			x = _L;
			y = _T;
			w = safeZoneW;
			h = safeZoneH;
			colorBackground[] = GUI_BCG_EDITOR;
			//onLoad="(_this select 0) ctrlshow is3DEN;";
		};
		class title: ctrlStaticTitle
		{
			text = "Config Viewer 73"; //--- ToDo: Localize;
			moving = 0;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _T + MARGIN(1) * UI_GRID_H;
			w = safeZoneW - MARGIN(2) * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
	class controls
	{
		class stxt_error: TER_3den_ctrlStructuredText
		{
			idc = IDC_CONFIG_STXTERROR;
			fade = 1;
			w = 10 * UI_GRID_W;
			h = 1;
			colorBackground[] = {0,0,0,1};
			shadow = 0;
			class Attributes
			{
				align = "left";
				color = "#b20000";
				colorLink = "#0000ff";
				size = 1;
				font = "RobotoCondensedLight";
			};
		};
		class btn_directory: ctrlButton
		{
			idc = IDC_CONFIG_BTNDIRECTORY;
			style = ST_LEFT + ST_FRAME;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _T + (MARGIN(2) + 1) * UI_GRID_H;
			w = COLUMN_L_W * UI_GRID_W;
			h = 1 * UI_GRID_H;
			
			/* class TextPos
			{
				left = 1 * UI_GRID_W;
				top = 0;//-0.1 * UI_GRID_H;
				right = 0;
				bottom = 0;
			};
			class ShortcutPos
			{
				left = 0;
				top = 0;
				w = 1 * UI_GRID_W;
				h = 1 * UI_GRID_H;
			};
			textureNoShortcut = "\a3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa"; */
		};
		class ed_configSearch: ctrlEdit
		{
			idc = IDC_CONFIG_EDCONFIGSEARCH;
			TECH_FONT
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _T + (MARGIN(3) + 2) * UI_GRID_H;
			w = (COLUMN_L_W - 1) * UI_GRID_W;
			h = 1 * UI_GRID_H;
			colorBackground[] = GUI_BCG_MENU;
		};
		class btn_endConfigSearch: ctrlActivePicture
		{
			idc = IDC_CONFIG_BTNENDCONFIGSEARCH;
			text = "\a3\3den\data\displays\display3den\search_end_ca.paa";
			x = _L + (MARGIN(2) + COLUMN_L_W -1) * UI_GRID_W;
			y = _T + (MARGIN(3) + 2) * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class grp_listCache: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPLISTCACHE;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _T + (MARGIN(4) + 3) * UI_GRID_H;
			w = COLUMN_L_W * UI_GRID_W;
			h = safeZoneH - (MARGIN(8) + 6) * UI_GRID_H;
		};
		class lb_configs: ctrlListbox
		{
			idc = IDC_CONFIG_LBCONFIGS;
			//TECH_FONT
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _T + (MARGIN(4) + 3) * UI_GRID_H;
			w = COLUMN_L_W * UI_GRID_W;
			h = safeZoneH - (MARGIN(8) + 6) * UI_GRID_H;
			colorBackground[] = GUI_BCG_MENU;
		};
		class prog_loading: ctrlProgress
		{
			idc = IDC_CONFIG_PROGLOADING;
			colorBar[] = GUI_BCG_COLOR;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _B - (MARGIN(3) + 3) * UI_GRID_H;
			w = COLUMN_L_W * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class stxt_loading: TER_3den_ctrlStructuredText
		{
			idc = IDC_CONFIG_STXTPROGRESS;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _B - (MARGIN(3) + 3) * UI_GRID_H;
			w = COLUMN_L_W * UI_GRID_W;
			h = 1 * UI_GRID_H;
			class Attributes
			{
				align = "center";
				color = "#ffffff";
				colorLink = "#0000ff";
				size = 1;
				font = "RobotoCondensedLight";
			};
		};
		class btn_favor: ctrlActivePicture
		{
			idc = IDC_CONFIG_BTNFAVOR;
			x = _L + MARGIN(1) * UI_GRID_W;
			y = _B - (MARGIN(2) + 2) * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			size = 1 * UI_GRID_H;
			text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\mp_serverempty_ca.paa";
			colorActive[] = {1,1,0,1};
		};
		class lb_favorites: ctrlCombo
		{
			idc = IDC_CONFIG_LBFAVORITES;
			font = "EtelkaMonospacePro";
			sizeEx = 1 * UI_GRID_H;
			shadow=0;
			x = _L + (MARGIN(2) + 1) * UI_GRID_W;
			y = _B - (MARGIN(2) + 2) * UI_GRID_H;
			w = (COLUMN_L_W - MARGIN(1) - 1) * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		#define W_CFGWINDOW (safeZoneW - (COLUMN_L_W + MARGIN(3)) * UI_GRID_W)
		#define W_TOOL 5
		__EXEC(_dX = 2 * 0.1 + COLUMN_L_W;)
		#define ADD_W(W) __EXEC(_dX = _dX + W;)
		#define _DX __EVAL(_dX)
		class txt_view: ctrlStatic
		{
			text = "View mode:";
			style = ST_RIGHT;
			x = _L + (MARGIN(2) + COLUMN_L_W) * UI_GRID_W;
			y = _T + (MARGIN(2) + 1) * UI_GRID_H;
			w = 3.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class tool_toggleView: ctrlToolbox
		{
			idc = IDC_CONFIG_TOOLVIEW;
			//TECH_FONT
			x = _L + (MARGIN(2) + COLUMN_L_W + 3.3) * UI_GRID_W;
			y = _T + (MARGIN(2) + 1) * UI_GRID_H;
			w = W_TOOL * UI_GRID_W;
			h = 1 * UI_GRID_H;
			strings[] = {"LIST","TEXT"};
			tooltips[] = {"Displays the config entry as a list of properties", "Displays the config entry as text"};
			columns = 2;
			rows = 1;
			//colorBackground[] = GUI_BCG_MENU;
		};
		class txt_inhertiance: txt_view
		{
			text = "Inheritance:";
			x = _L + (MARGIN(3) + COLUMN_L_W + 3.3 + W_TOOL) * UI_GRID_W;
			w = 3.3 * UI_GRID_W;
		};
		class tool_inheritance: tool_toggleView
		{
			idc = IDC_CONFIG_TOOLINHERITANCE;
			onLoad = "";
			x = _L + (MARGIN(3) + COLUMN_L_W + 3.3 + W_TOOL + 3.3) * UI_GRID_W;
			strings[] = {"ON","OFF"};
			tooltips[] = {"Show inherited properties","Only show config specific properties"};
		};
		class txt_showClasses: txt_view
		{
			text = "Show classes:";
			x = _L + (MARGIN(4) + COLUMN_L_W + 3.3 + 2 * W_TOOL + 3.3) * UI_GRID_W;
			w = 4 * UI_GRID_W;
		};
		class tool_showClasses: tool_toggleView
		{
			idc = IDC_CONFIG_TOOLSHOWCLASSES;
			onLoad = "";
			x = _L + (MARGIN(4) + COLUMN_L_W + 3.3 + 2 * W_TOOL + 3.3 + 4) * UI_GRID_W;
			strings[] = {"ON", "OFF"};
			tooltips[] = {"",""};
		};
		class grp_list: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPLIST;
			x = _L + (MARGIN(2) + COLUMN_L_W) * UI_GRID_W;
			y = _T + (MARGIN(3) + 2) * UI_GRID_H;
			w = W_CFGWINDOW;
			h = safeZoneH - (MARGIN(8) + 6) * UI_GRID_H;
			show = 0;
			class controls
			{
				#define W_TXT_PROPERTYSEARCH 7.2
				class txt_propertySearch: txt_view
				{
					text = "Search properties:";
					TECH_FONT
					x = 0;
					y = 0.1 * UI_GRID_H;
					w = W_TXT_PROPERTYSEARCH * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class ed_propertySearch: ed_configSearch
				{
					idc = IDC_CONFIG_EDPROPERTYSEARCH;
					TECH_FONT
					x = W_TXT_PROPERTYSEARCH * UI_GRID_W;
					y = 0.1 * UI_GRID_H;
					w = W_CFGWINDOW - W_TXT_PROPERTYSEARCH * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class lb_properties: ctrlListbox
				{
					idc = IDC_CONFIG_LBPROPERTIES;
					TECH_FONT
					x = 0;
					y = (1 + MARGIN(2)) * UI_GRID_H;
					w = W_CFGWINDOW;
					h = safeZoneH - (MARGIN(10) + 7) * UI_GRID_H;
				};
			};
		};
		class grp_text: grp_list
		{
			idc = IDC_CONFIG_GRPTEXT;
			show = 0;
			class VScrollBar
			{
				width = 0.5 * UI_GRID_W;
				height = 0;
				autoScrollEnabled = 0;
				autoScrollDelay = 1;
				autoScrollRewind = 1;
				autoScrollSpeed = 1;
			};
			class controls
			{
				class ed_properties: ed_configSearch
				{
					idc = IDC_CONFIG_EDPROPERTIES;
					x = 0;
					y = 0.1 * UI_GRID_H;
					w = W_CFGWINDOW - 0.5 * UI_GRID_W;
					h = safeZoneH - (MARGIN(6) + 5) * UI_GRID_H;
					canModify = 0;
					style = ST_MULTI;
				};
			};
		};
		class ed_cfgPath: ed_configSearch
		{
			idc = IDC_CONFIG_EDCFGPATH;
			canModify = 0;
			TECH_FONT
			x = _L + (MARGIN(2) + COLUMN_L_W) * UI_GRID_W;
			y = _B - (MARGIN(1) + 2.1) * UI_GRID_H;
			w = W_CFGWINDOW;
			h = 1 * UI_GRID_H;
		};
		class ed_propValue: ed_cfgPath
		{
			idc = IDC_CONFIG_EDPROPVALUE;
			text = "";
			y = _B - (MARGIN(3) + 3) * UI_GRID_H;
		};
		class txt_parents: txt_showClasses
		{
			text = "Parents:";
			x = _L + (MARGIN(2) + COLUMN_L_W) * UI_GRID_W;
			y = _B - (MARGIN(4) + 4) * UI_GRID_H;
			w = 2.6 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class lb_parents: lb_favorites
		{
			idc = IDC_CONFIG_COMBOPARENTS;
			x = _L + (MARGIN(3) + COLUMN_L_W + 2.6) * UI_GRID_W;
			y = _B - (MARGIN(4) + 4) * UI_GRID_H;
			w = W_CFGWINDOW - 2.7 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class grp_info: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPINFO;
			show = 0;
			x = safeZoneX;
			y = safeZoneY;
			w = safeZoneW;
			h = safeZoneH;
			class controls
			{
				#define W_INFO 20
				#define H_INFO 24
				class backDisable: ctrlStaticBackgroundDisable
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class backDisableTiles: ctrlStaticBackgroundDisableTiles
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class backDialog: ctrlStaticBackground
				{
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * UI_GRID_W;
					y = 0.5 * safezoneH - (H_INFO/2 + 0.1) * UI_GRID_H;
					w = (W_INFO + 0.2) * UI_GRID_W;
					h = (H_INFO + 1.3) * UI_GRID_H;
				};
				class title: ctrlStaticTitle
				{
					text = "Config Viewer 73 (@Terra's Editing Extensions)";
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * UI_GRID_W;
					y = 0.5 * safezoneH - (H_INFO/2 + 1.1) * UI_GRID_H;
					w = (W_INFO + 0.2) * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class footer: ctrlStaticFooter
				{
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * UI_GRID_W;
					y = 0.5 * safezoneH + (H_INFO/2) * UI_GRID_H;
					w = (W_INFO + 0.2) * UI_GRID_W;
					h = 1.2 * UI_GRID_H;
				};
				class btn_ok: ctrlButton
				{
					idc = IDC_CONFIG_BTNINFOOK;
					text = "OK";
					x = 0.5 * safeZoneW - 10 * UI_GRID_W;
					y = 0.5 * safezoneH + (H_INFO/2 + 0.1) * UI_GRID_H;
					w = 5 * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class stxt_info: TER_3den_ctrlStructuredText
				{
					idc = IDC_CONFIG_STXTINFO;
					x = 0.5 * safeZoneW - (W_INFO/2) * UI_GRID_W;
					y = 0.5 * safeZoneH - (H_INFO/2) * UI_GRID_H;
					w = W_INFO * UI_GRID_W;
					h = (H_INFO - 1.1) * UI_GRID_H;
				};
			};
		};
		class btn_close: ctrlButtonCancel
		{
			text = "CLOSE";
			x = _R - (MARGIN(1) + 10) * UI_GRID_W;
			y = _B - (1 + MARGIN(1)) * UI_GRID_H;
			w = 10 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class btn_export: btn_close
		{
			idc = IDC_CONFIG_BTNEXPORT;
			text = "EXPORT";
			tooltip = "Export the selected class to clipboard";
			x = _R - (MARGIN(2) + 20) * UI_GRID_W;
		};
		class btn_openInfo: btn_close
		{
			idc = IDC_CONFIG_BTNOPENINFO;
			text = "?";
			x = _R - (MARGIN(3) + 21) * UI_GRID_W;
			w = 1 * UI_GRID_W;
			shortcuts[] = {DIK_F1};
		};
		#define W_PREVIEW 30
		#define H_PREVIEW 22
		#define X_PREVIEW (0.5 * safeZoneW - 0.5 * W_PREVIEW * UI_GRID_W)
		#define Y_PREVIEW (0.5 * safeZoneH - 0.5 * H_PREVIEW * UI_GRID_H)
		class grp_preview: ctrlControlsGroupNoScrollbars
		{
			show = 0;
			idc = IDC_CONFIG_GRPPREVIEW;
			x = safeZoneX;
			y = safeZoneY;
			w = safeZoneW;
			h = safeZoneH;
			class controls
			{
				class backDisable: ctrlStaticBackgroundDisable
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class backDisableTiles: ctrlStaticBackgroundDisableTiles
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class title: ctrlStaticTitle
				{
					text = "Property preview";
					x = X_PREVIEW - 0.1 * UI_GRID_W;
					y = Y_PREVIEW - 1.1 * UI_GRID_H;
					/* x = 0.5 * safeZoneW - (0.5 * W_PREVIEW + 0.1) * UI_GRID_W;
					y = 0.5 * safeZoneH - (0.5 * H_PREVIEW + 1.1) * UI_GRID_H; */
					w = (W_PREVIEW + 0.2) * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class background: ctrlStaticBackground
				{
					/* x = 0.5 * safeZoneW - (0.5 * W_PREVIEW + 0.1) * UI_GRID_W;
					y = 0.5 * safeZoneH - (0.5 * H_PREVIEW + 0.1) * UI_GRID_H; */
					x = X_PREVIEW - 0.1 * UI_GRID_W;
					y = Y_PREVIEW - 0.1 * UI_GRID_H;
					w = (W_PREVIEW + 0.2) * UI_GRID_W;
					h = (H_PREVIEW + 1.5) * UI_GRID_H;
				};
				//--- Color preview
				class grp_colorPicker: TER_3den_ctrlColorPicker
				{
					idc = IDC_CONFIG_GRPCOLORPICKER;
					show = 0;
					x = X_PREVIEW;
					y = Y_PREVIEW;
				};
				//--- Image preview
				class grp_picPreview: ctrlControlsGroupNoScrollbars
				{
					show = 0;
					idc = IDC_CONFIG_GRPPICPREVIEW;
					x = X_PREVIEW;
					y = Y_PREVIEW;
					w = W_PREVIEW * UI_GRID_W;
					h = H_PREVIEW * UI_GRID_H;
					class controls
					{
						class pic_preview: ctrlStaticPictureKeepAspect
						{
							idc = IDC_CONFIG_PICPREVIEW;
							//text = "icons\logo.paa";
							//text = "#(argb,8,8,3)color(1,0,0,1)";
							//text = "icons\2048_thumb_V2.paa";
							x = (1.3/2) * UI_GRID_W;
							y = 0;
							w = (W_PREVIEW - 1.3) * UI_GRID_W;
							h = (H_PREVIEW - 1.3) * UI_GRID_H;
						};
						class slider_picScale: ctrlXSliderH
						{
							idc = IDC_CONFIG_SLIDERPREVIEWSCALE;
							x = 0;
							y = (H_PREVIEW - 1.1) * UI_GRID_H;
							w = W_PREVIEW * UI_GRID_W;
							h = 1 * UI_GRID_H;
						};
					};
				};
				class footer: ctrlStaticFooter
				{
					/* x = 0.5 * safeZoneW - (0.5 * W_PREVIEW + 0.1) * UI_GRID_W;
					y = 0.5 * safeZoneH + (0.5 * H_PREVIEW) * UI_GRID_H; */
					x = X_PREVIEW - 0.1 * UI_GRID_W;
					y = Y_PREVIEW + (H_PREVIEW) * UI_GRID_H;
					w = (W_PREVIEW + 0.2) * UI_GRID_W;
					h = 1.4 * UI_GRID_H;
				};
				class btn_close: ctrlButton
				{
					idc = IDC_CONFIG_BTNPREVIEWCLOSE;
					text = "CLOSE";
					x = X_PREVIEW + (W_PREVIEW - 10.2) * UI_GRID_W;
					y = Y_PREVIEW + (H_PREVIEW + 0.2) * UI_GRID_H;
					w = 10 * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
			};
		};
		#define W_HISTORY_MAX 40
		#define H_HISTORY_MAX 24
		#define W_HISTORY(W) ((W_HISTORY_MAX + W) * UI_GRID_W)
		#define H_HISTORY(H) ((H_HISTORY_MAX + H) * UI_GRID_H)
		#define X_HISTORY(X) (0.5 * safeZoneW - 0.5 * W_HISTORY(0)) + (X * UI_GRID_W)
		#define Y_HISTORY(Y) (0.5 * safeZoneH - 0.5 * H_HISTORY(0)) + (Y * UI_GRID_H)
		class grp_history: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPHISTORY;
			show = 0;
			x = safeZoneX;
			y = safeZoneY;
			w = safeZoneW;
			h = safeZoneH;
			class controls
			{
				class backDisable: ctrlStaticBackgroundDisable
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class backDisableTiles: ctrlStaticBackgroundDisableTiles
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class title: ctrlStaticTitle
				{
					text = "History";
					x = X_HISTORY(0);
					y = Y_HISTORY(0);
					w = W_HISTORY(0);
					h = 1 * UI_GRID_H;
				};
				class background: ctrlStaticBackground
				{
					x = X_HISTORY(0);
					y = Y_HISTORY(1);
					w = W_HISTORY(0);
					h = H_HISTORY(-1);
				};
				class lb_history: ctrlListbox
				{
					idc = IDC_CONFIG_IDCLBHISTORY;
					x = X_HISTORY(0.2);
					y = Y_HISTORY(1.2);
					w = W_HISTORY(-0.4);
					h = H_HISTORY(-2.8);
				};
				class footer: ctrlStaticFooter
				{
					idc = IDC_CONFIG_BTNCLOSEHISTORY;
					x = X_HISTORY(0);
					y = Y_HISTORY((H_HISTORY_MAX - 1.4));
					w = W_HISTORY(0);
					h = 1.4 * UI_GRID_H;
				};
				class btn_HistoryClose: ctrlButton
				{
					text = "CLOSE";
					x = X_HISTORY((W_HISTORY_MAX - 10.2));
					y = Y_HISTORY((H_HISTORY_MAX - 1.2));
					w = 10 * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
			};
		};
		class grp_export: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPEXPORT;
			show = 0;
			x = safeZoneX;
			y = safeZoneY;
			w = safeZoneW;
			h = safeZoneH;
			class controls
			{
				class backDisable: ctrlStaticBackgroundDisable
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class backDisableTiles: ctrlStaticBackgroundDisableTiles
				{
					x = 0;
					y = 0;
					w = safeZoneW;
					h = safeZoneH;
				};
				class title: ctrlStaticTitle
				{
					text = "Export";
					x = X_PREVIEW - 0.1 * UI_GRID_W;
					y = Y_PREVIEW - 1.1 * UI_GRID_H;
					w = (W_PREVIEW + 0.2) * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class background: ctrlStaticBackground
				{
					x = X_PREVIEW - 0.1 * UI_GRID_W;
					y = Y_PREVIEW - 0.1 * UI_GRID_H;
					w = (W_PREVIEW + 0.2) * UI_GRID_W;
					h = (H_PREVIEW + 1.5) * UI_GRID_H;
				};
				class txt_config: TER_3den_ctrlStructuredText
				{
					text = "Config:";
					x = X_PREVIEW;
					y = Y_PREVIEW;
					w = 0.25 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
					class Attributes
					{
						align = "right";
						color = "#ffffff";
						colorLink = "#0000ff";
						size = 1;
						font = "RobotoCondensedLight";
					};
				};
				class ed_config: ctrlEdit
				{
					idc = IDC_CONFIG_EXPORT_EDCONFIG;
					x = X_PREVIEW + 0.25 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW;
					w = 0.75 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class txt_inherit: txt_config
				{
					text = "Include inherited properties:";
					y = Y_PREVIEW + 1.1 * UI_GRID_H;
				};
				class cb_inherited: ctrlCheckbox
				{
					idc = IDC_CONFIG_EXPORT_CBINHERITED;
					x = X_PREVIEW + 0.25 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW + 1.1 * UI_GRID_H;
					w = 1 * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
				class txt_newlinechar: txt_config
				{
					text = "New line character:";
					y = Y_PREVIEW + 2.2 * UI_GRID_H;
				};
				class tool_newlinechar: ctrlToolbox
				{
					idc = IDC_CONFIG_EXPORT_TOOLNEWLINECHAR;
					x = X_PREVIEW + 0.25 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW + 2.2 * UI_GRID_H;
					w = 0.75 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
					columns = 4;
					strings[] = {"endl", "<br/>", "\n", "toString[10]"};
				};
				class txt_tabchar: txt_config
				{
					text = "Tab character:";
					y = Y_PREVIEW + 3.3 * UI_GRID_H;
				};
				class tool_tabchar: tool_newlinechar
				{
					idc = IDC_CONFIG_EXPORT_TOOLTABCHAR;
					y = Y_PREVIEW + 3.3 * UI_GRID_H;
					columns = 2;
					strings[] = {"Tab", "Spaces"};
				};
				class txt_indent: txt_config
				{
					text = "Tab size:";
					y = Y_PREVIEW + 4.4 * UI_GRID_H;
				};
				class ed_indent: ed_config
				{
					idc = IDC_CONFIG_EXPORT_EDINDENT;
					text = "1";
					y = Y_PREVIEW + 4.4 * UI_GRID_H;
				};
				class txt_recursive: txt_config
				{
					text = "Include subclasses:";
					y = Y_PREVIEW + 5.5 * UI_GRID_H;
				};
				class cb_recursive: cb_inherited
				{
					idc = IDC_CONFIG_EXPORT_CBRECURSIVE;
					checked = 1;
					y = Y_PREVIEW + 5.5 * UI_GRID_H;
				};
				class txt_tabcount: txt_config
				{
					text = "Initial tab count:";
					y = Y_PREVIEW + 6.6 * UI_GRID_H;
				};
				class ed_tabcount: ed_config
				{
					idc = IDC_CONFIG_EXPORT_EDTABCOUNT;
					text = "0";
					y = Y_PREVIEW + 6.6 * UI_GRID_H;
				};
				class btn_copy: ctrlButton
				{
					idc = IDC_CONFIG_EXPORT_BTNCOPY;
					text = "EXPORT TO CLIPBOARD";
					x = X_PREVIEW + 0.25 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW + 7.7 * UI_GRID_H;
					w = 0.75 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
					shortcuts[] = {DIK_ENTER};
				};
				class txt_status: txt_config
				{
					text = "Status:";
					y = Y_PREVIEW + 8.8 * UI_GRID_H;
				};
				class stxt_status: TER_3den_ctrlStructuredText
				{
					idc = IDC_CONFIG_EXPORT_TXTSTATUS;
					text = "<t color='#00FF00'>Ready</t>";
					x = X_PREVIEW + 0.25 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW + 8.8 * UI_GRID_H;
					w = 0.75 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
					class Attributes
					{
						align = "center";
						color = "#ffffff";
						colorLink = "#0000ff";
						size = 1;
						font = "RobotoCondensedLight";
					};
				};

				class btn_close: ctrlButton
				{
					idc = IDC_CONFIG_EXPORT_BTNCANCEL;
					text = "Close";
					x = X_PREVIEW + 0.5 * W_PREVIEW * UI_GRID_W;
					y = Y_PREVIEW + (H_PREVIEW + 0.3) * UI_GRID_H;
					w = 0.5 * W_PREVIEW * UI_GRID_W;
					h = 1 * UI_GRID_H;
				};
			};
		};
	};
};

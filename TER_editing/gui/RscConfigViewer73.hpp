// Debug
#undef DEBUG_W
#define DEBUG_W onLoad = "systemchat str [ctrltextwidth (_this#0) / (2.5 * pixelGrid * pixelW)];";
// UI_GRID
#define _W UI_GRID_W
#define _H UI_GRID_H
// Positions
#define _L (safeZoneX)
#define _R (safeZoneX + safeZoneW)
#define _T (safeZoneY)
#define _B (safeZoneY + safeZoneH)
#define MARGIN(COUNT) (COUNT * 0.1)
#define COLUMN_L_W 12.5
// Appearance
#define TECH_FONT 			font = "EtelkaMonospacePro";\
			sizeEx = 0.7 * _H;\
			shadow=0;

// Beginning of display config
class TER_3den_RscDisplayConfigViewer73
{
	idd = IDD_DISPLAY_CONFIGVIEWER;
	ONLOAD(RscConfigViewer73);
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
			x = _L + MARGIN(1) * _W;
			y = _T + MARGIN(1) * _H;
			w = safeZoneW - MARGIN(2) * _W;
			h = 1 * _H;
		};
	};
	class controls
	{
		class stxt_error: ctrlStructuredText
		{
			idc = IDC_CONFIG_STXTERROR;
			fade = 1;
			w = 10 * _W;
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
			x = _L + MARGIN(1) * _W;
			y = _T + (MARGIN(2) + 1) * _H;
			w = COLUMN_L_W * _W;
			h = 1 * _H;
			
			/* class TextPos
			{
				left = 1 * _W;
				top = 0;//-0.1 * _H;
				right = 0;
				bottom = 0;
			};
			class ShortcutPos
			{
				left = 0;
				top = 0;
				w = 1 * _W;
				h = 1 * _H;
			};
			textureNoShortcut = "\a3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa"; */
		};
		class ed_configSearch: ctrlEdit
		{
			idc = IDC_CONFIG_EDCONFIGSEARCH;
			TECH_FONT
			x = _L + MARGIN(1) * _W;
			y = _T + (MARGIN(3) + 2) * _H;
			w = (COLUMN_L_W - 1) * _W;
			h = 1 * _H;
			colorBackground[] = GUI_BCG_MENU;
		};
		class btn_endConfigSearch: ctrlActivePicture
		{
			idc = IDC_CONFIG_BTNENDCONFIGSEARCH;
			text = "\a3\3den\data\displays\display3den\search_end_ca.paa";
			x = _L + (MARGIN(2) + COLUMN_L_W -1) * _W;
			y = _T + (MARGIN(3) + 2) * _H;
			w = 1 * _W;
			h = 1 * _H;
		};
		class lb_configs: ctrlListbox
		{
			idc = IDC_CONFIG_LBCONFIGS;
			//TECH_FONT
			x = _L + MARGIN(1) * _W;
			y = _T + (MARGIN(4) + 3) * _H;
			w = COLUMN_L_W * _W;
			h = safeZoneH - (MARGIN(8) + 6) * _H;
			colorBackground[] = GUI_BCG_MENU;
		};
		class prog_loading: ctrlProgress
		{
			idc = IDC_CONFIG_PROGLOADING;
			colorBar[] =
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
			};
			x = _L + MARGIN(1) * _W;
			y = _B - (MARGIN(3) + 3) * _H;
			w = COLUMN_L_W * _W;
			h = 1 * _H;
		};
		class stxt_loading: ctrlStructuredText
		{
			idc = IDC_CONFIG_STXTPROGRESS;
			text = "TEST";
			x = _L + MARGIN(1) * _W;
			y = _B - (MARGIN(3) + 3) * _H;
			w = COLUMN_L_W * _W;
			h = 1 * _H;
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
			x = _L + MARGIN(1) * _W;
			y = _B - (MARGIN(2) + 2) * _H;
			w = 1 * _W;
			h = 1 * _H;
			size = 1 * _H;
			text = "\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\mp_serverempty_ca.paa";
			colorActive[] = {1,1,0,1};
		};
		class lb_favorites: ctrlCombo
		{
			idc = IDC_CONFIG_LBFAVORITES;
			font = "EtelkaMonospacePro";
			sizeEx = 1 * _H;
			shadow=0;
			x = _L + (MARGIN(2) + 1) * _W;
			y = _B - (MARGIN(2) + 2) * _H;
			w = (COLUMN_L_W - MARGIN(1) - 1) * _W;
			h = 1 * _H;
		};
		/*
			#define H_LOADINGGROUP (safeZoneH - (MARGIN(4) + 2) * _H)
			class grp_loading: ctrlControlsGroupNoScrollbars
			{
				idc = IDC_CONFIG_GRPLOADING;
				x = _L + MARGIN(1) * _W;
				y = _T + (MARGIN(2) + 1) * _H; // y = _T + (MARGIN(4) + 3) * _H;
				w = COLUMN_L_W * _W;
				h = H_LOADINGGROUP;
				class controls 
				{
					class coverBackground: ctrlStaticBackgroundDisable {};
					class coverTiles: ctrlStaticBackgroundDisableTiles {};
					class stxt_loadingText: ctrlStructuredText
					{
						idc = IDC_CONFIG_STXTLOADINGTEXT;
						text = "LOADING...";
						colorBackground[] = {0,0,0,1};
						x = 1 * _W;
						y = 0.5 * H_LOADINGGROUP - 1.6 * _H;
						w = (COLUMN_L_W - 2) * _W;
						h = 1 * _H;
					};
					class loadingBar: ctrlProgress
					{
						idc = IDC_CONFIG_PROGLOADING;
						x = 1 * _W;
						y = 0.5 * H_LOADINGGROUP - 0.5 * _H;
						w = (COLUMN_L_W - 2) * _W;
						h = 1 * _H;
						colorBackground[] = {0,0,0,1};
					};
					class stxt_progress: stxt_loadingText
					{
						idc = IDC_CONFIG_STXTPROGRESS;
						text = "TEST";
						y = 0.5 * H_LOADINGGROUP - 0.5 * _H;
						colorBackground[] = {0,0,0,0};
						class Attributes
						{
							align = "center";
							color = "#000000";
							colorLink = "#0000ff";
							size = 1;
							font = "RobotoCondensedLight";
						};
					};
				};
			}; 
		*/
		//////////////////////////////////////
		//////////////////////////////////////
		#define W_CFGWINDOW (safeZoneW - (COLUMN_L_W + MARGIN(3)) * _W)
		#define W_TOOL 5
		__EXEC(_dX = 2 * 0.1 + COLUMN_L_W;)
		#define ADD_W(W) __EXEC(_dX = _dX + W;)
		#define _DX __EVAL(_dX)
		class txt_view: ctrlStatic
		{
			text = "View mode:";
			style = ST_RIGHT;
			x = _L + (MARGIN(2) + COLUMN_L_W) * _W;
			y = _T + (MARGIN(2) + 1) * _H;
			w = 3.3 * _W;
			h = 1 * _H;
		};
		class tool_toggleView: ctrlToolbox
		{
			idc = IDC_CONFIG_TOOLVIEW;
			onLoad = "_this#0 ctrlEnable false;";
			//TECH_FONT
			x = _L + (MARGIN(2) + COLUMN_L_W + 3.3) * _W;
			y = _T + (MARGIN(2) + 1) * _H;
			w = W_TOOL * _W;
			h = 1 * _H;
			//strings[] = {"LIST","TEXT"};
			strings[] = {"WIP","WIP"};
			//tooltips[] = {"Displays the config entry as a list of properties", "Displays the config entry as text"};
			tooltips[] = {"Nothing to see here","YET"};
			columns = 2;
			rows = 1;
			//colorBackground[] = GUI_BCG_MENU;
		};
		class txt_inhertiance: txt_view
		{
			text = "Inheritance:";
			x = _L + (MARGIN(3) + COLUMN_L_W + 3.3 + W_TOOL) * _W;
			w = 3.3 * _W;
		};
		class tool_inheritance: tool_toggleView
		{
			idc = IDC_CONFIG_TOOLINHERITANCE;
			onLoad = "";
			x = _L + (MARGIN(3) + COLUMN_L_W + 3.3 + W_TOOL + 3.3) * _W;
			strings[] = {"ON","OFF"};
			tooltips[] = {"Show inherited properties","Only show config specific properties"};
		};
		class txt_showClasses: txt_view
		{
			text = "Show classes:";
			x = _L + (MARGIN(4) + COLUMN_L_W + 3.3 + 2 * W_TOOL + 3.3) * _W;
			w = 4 * _W;
		};
		class tool_showClasses: tool_toggleView
		{
			idc = IDC_CONFIG_TOOLSHOWCLASSES;
			onLoad = "";
			x = _L + (MARGIN(4) + COLUMN_L_W + 3.3 + 2 * W_TOOL + 3.3 + 4) * _W;
			strings[] = {"ON", "OFF"};
			tooltips[] = {"",""};
		};
		class grp_list: ctrlControlsGroupNoScrollbars
		{
			idc = IDC_CONFIG_GRPLIST;
			x = _L + (MARGIN(2) + COLUMN_L_W) * _W;
			y = _T + (MARGIN(3) + 2) * _H;
			w = W_CFGWINDOW;
			h = safeZoneH - (MARGIN(7) + 5) * _H;
			class controls
			{
				#define W_TXT_PROPERTYSEARCH 7.2
				class txt_propertySearch: txt_view
				{
					text = "Search properties:";
					TECH_FONT
					x = 0;
					y = 0.1 * _H;
					w = W_TXT_PROPERTYSEARCH * _W;
					h = 1 * _H;
				};
				class ed_propertySearch: ed_configSearch
				{
					idc = IDC_CONFIG_EDPROPERTYSEARCH;
					TECH_FONT
					x = W_TXT_PROPERTYSEARCH * _W;
					y = 0.1 * _H;
					w = W_CFGWINDOW - W_TXT_PROPERTYSEARCH * _W;
					h = 1 * _H;
				};
				class lb_properties: ctrlListbox
				{
					idc = IDC_CONFIG_LBPROPERTIES;
					TECH_FONT
					x = 0;
					y = (1 + MARGIN(2)) * _H;
					w = W_CFGWINDOW;
					h = safeZoneH - (MARGIN(9) + 6) * _H;
				};
			};
		};
		class grp_text: grp_list
		{
			idc = IDC_CONFIG_GRPTEXT;
			show = 0;
			class controls
			{
				class ed_properties: ed_configSearch
				{
					idc = IDC_CONFIG_EDPROPERTIES;
					x = 0;
					y = 0;
					w = W_CFGWINDOW;
					h = safeZoneH - (MARGIN(6) + 4) * _H;
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
			x = _L + (MARGIN(2) + COLUMN_L_W) * _W;
			y = _B - (MARGIN(1) + 2.1) * _H;
			w = W_CFGWINDOW;
			h = 1 * _H;
			//canModify = 0;
		};
		class ed_propValue: ed_cfgPath
		{
			idc = IDC_CONFIG_EDPROPVALUE;
			text = "";
			y = _B - (MARGIN(3) + 3) * _H;
		};
		/* class btn_preview: ctrlButton
		{
			idc = IDC_CONFIG_BTNPREVIEW;
			text = "PREVIEW";
			x = _L + (MARGIN(2) + COLUMN_L_W) * _W;
			y = _B - (MARGIN(1) + 1) * _H;
			w = W_CFGWINDOW/2;
			h = 1 * _H;
		};
		class btn_export: btn_preview
		{
			idc = IDC_CONFIG_BTNEXPORT;
			text = "EXPORT";
			x = _L + W_CFGWINDOW/2 + (MARGIN(3) + COLUMN_L_W) * _W;
			w = W_CFGWINDOW/2 - 0.1 * _W;
		}; */
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
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * _W;
					y = 0.5 * safezoneH - (H_INFO/2 + 0.1) * _H;
					w = (W_INFO + 0.2) * _W;
					h = (H_INFO + 1.3) * _H;
				};
				class title: ctrlStaticTitle
				{
					text = "Config Viewer 73 (@Terra's Editing Extensions)";
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * _W;
					y = 0.5 * safezoneH - (H_INFO/2 + 1.1) * _H;
					w = (W_INFO + 0.2) * _W;
					h = 1 * _H;
				};
				class footer: ctrlStaticFooter
				{
					x = 0.5 * safeZoneW - (W_INFO/2 + 0.1) * _W;
					y = 0.5 * safezoneH + (H_INFO/2) * _H;
					w = (W_INFO + 0.2) * _W;
					h = 1.2 * _H;
				};
				class btn_ok: ctrlButton
				{
					idc = IDC_CONFIG_BTNINFOOK;
					text = "OK";
					x = 0.5 * safeZoneW - 10 * _W;
					y = 0.5 * safezoneH + (H_INFO/2 + 0.1) * _H;
					w = 5 * _W;
					h = 1 * _H;
				};
				class stxt_info: ctrlStructuredText
				{
					idc = IDC_CONFIG_STXTINFO;
					x = 0.5 * safeZoneW - (W_INFO/2) * _W;
					y = 0.5 * safeZoneH - (H_INFO/2) * _H;
					w = W_INFO * _W;
					h = (H_INFO - 1.1) * _H;
				};
			};
		};
		class btn_print: ctrlButton
		{
			idc = IDC_CONFIG_BTNPRINTCONFIG
			text = "PRINT CONFIG";
			x =_R - (MARGIN(2) + 20) * _W;
			y = _B - (1 + MARGIN(1)) * _H;
			w = 10 * _W;
			h = 1 * _H;
		};
		class btn_close: ctrlButtonCancel
		{
			text = "CLOSE";
			x =_R - (MARGIN(1) + 10) * _W;
			y = _B - (1 + MARGIN(1)) * _H;
			w = 10 * _W;
			h = 1 * _H;
		};
		class btn_openInfo: btn_close
		{
			idc = IDC_CONFIG_BTNOPENINFO;
			text = "?";
			x = _R - (MARGIN(3) + 21) * _W;
			w = 1 * _W;
			shortcuts[] = {DIK_F1};
		};
	};
};

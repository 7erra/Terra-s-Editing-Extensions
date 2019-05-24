#define DEBUG_W (22 * GUI_GRID_W)
#define DEBUG_H (safeZoneH - (1 + (25-22.4)) * GUI_GRID_H)
#define L_BORDER (0.5 * GUI_GRID_W)
#define R_BORDER (21.5 * GUI_GRID_W)
#define H_BORDER (DEBUG_H - 2.4 * GUI_GRID_H)
#define W_BORDER (R_BORDER - L_BORDER)
#define DEEP_RED {0.5,0,0,1}
class TER_3den_RscEditCode: RscEdit
{
	font="EtelkaMonospacePro";
	sizeEx = 0.7 * GUI_GRID_H;
	autocomplete = "scripting";
	h = GUI_GRID_H;
};
class TER_3den_RscEditCodeOutput: TER_3den_RscEditCode
{
	style = 512;
	colorBackground[]={0,0,0,0.80000001};
	canModify = 0;
	h = GUI_GRID_H;
};
class TER_3den_RscWatchGroupControl: RscControlsGroupNoScrollBars
{
	x = 0;
	y = 0 * GUI_GRID_H;
	w = W_BORDER;
	h = 2.2 * GUI_GRID_H;
	class controls 
	{
		class cb_liveOutput: RscCheckbox
		{
			idc = IDC_CB_WATCHLIVE;
			tooltip = "Add to live watch";
			x = 0.1 * GUI_GRID_W;
			y = 0.1 * GUI_GRID_H;
			w = GUI_GRID_W;
			h = GUI_GRID_H;
		};
		class ed_input: TER_3den_RscEditCode
		{
			idc = IDC_ED_WATCHIN;
			x = 1.2 * GUI_GRID_W;
			y = 0.1 * GUI_GRID_H;
			w = W_BORDER-(2.3 * GUI_GRID_W);
			h = GUI_GRID_H;
		};
		class btn_delete: RscActivePicture
		{
			idc = IDC_BTN_WATCHDELETE;
			text = "\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
			tooltip = "Delete";
			color[] = {1,0,0,0.5};
			colorActive[] = {1,0,0,1};
			x = W_BORDER-(1 * GUI_GRID_W);
			y = 0.1 * GUI_GRID_H;
			w = GUI_GRID_W;
			h = GUI_GRID_H;
		};
		class ed_output: TER_3den_RscEditCodeOutput
		{
			idc = IDC_ED_WATCHOUT;
			x = 0;
			y = 1.2 * GUI_GRID_H;
			w = W_BORDER;
			h = GUI_GRID_H;
		};
	};
};
class TER_3den_RscCCGroup: RscControlsGroupNoScrollBars
{
	x = 0;
	y = 0;
	w = W_BORDER;
	h = GUI_GRID_H;
	class controls 
	{
		class btn_cc_exec: RscButtonMenu
		{
			idc = IDC_BTN_CCEXEC;
			text = "Execute";
			x = 0;
			y = 0;
			w = 2.5 * GUI_GRID_W;
			h = GUI_GRID_H;
		};
		class ed_cc_code: TER_3den_RscEditCode
		{
			idc = IDC_ED_CCCODE;
			x = 2.6 * GUI_GRID_W;
			y = 0;
			w = W_BORDER - (3.7 * GUI_GRID_W);
			h = GUI_GRID_H;
		};
		class btn_cc_delete: RscButtonMenu
		{
			idc = IDC_BTN_CCDELETE;
			text = "X";
			tooltip = "Delete";
			style = ST_CENTER;
			colorBackground[] = DEEP_RED;
			x = W_BORDER-(1 * GUI_GRID_W);
			y = 0 * GUI_GRID_H;
			w = GUI_GRID_W;
			h = GUI_GRID_H;
		};
	};
};

#define ADD_Y(VAL) __EXEC(_curY = _curY +0.1 +VAL)
#define CUR_Y __EVAL(_curY) * GUI_GRID_H
#define ADD_HEIGHT(HEIGHT) HEIGHT * GUI_GRID_H; ADD_Y(HEIGHT)

#define SEPERATOR_COUNT __EVAL(_seperatorCount)
#define SEPERATOR_COUNT_ADD __EXEC(_seperatorCount = _seperatorCount +1)
#define SEPERATOR(NUMBER) class seperator##NUMBER: seperator1\
				{\
					y = CUR_Y;\
				};ADD_Y(0)

/* 
 page 1: live debug, side player, teleport, unit icons, grids, clear chat, editor grid
 page 2: watch fields
 page 3: Custom commands
 page 4: BIKI links, target debug, recent watch entries
 page 5: Unit live watch
 page 6: KK Debug
 */
class TER_3den_debugConsole: RscControlsGroupNoScrollBars
{
	idc = IDC_DEBUG;
	x = 40 * GUI_GRID_W + GUI_GRID_X;
	y = safezoneY + 1 * GUI_GRID_H;
	w = DEBUG_W;
	h = DEBUG_H;
	onLoad = "[""load"",_this] execVM ""\TER_Editing\gui\scripts\RscDebug.sqf"";";
	class controls 
	{
		class background: RscText
		{
			x = 0;
			y = 1.1 * GUI_GRID_H;
			w = DEBUG_W;
			h = DEBUG_H -(1.1 * GUI_GRID_H);
			colorBackground[] = {0,0,0,0.8};
		};
		class title_debug: RscTitle
		{
			text = "7erra's Editing Debug Console"; //--- ToDo: Localize;
			colorBackground[]=
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
			};
			x = 0 * GUI_GRID_W;
			y = 0 * GUI_GRID_H;
			w = DEBUG_W;
			h = 1 * GUI_GRID_H;
		};
		// START PAGE 1
		// page 1: everything else
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page1: RscControlsGroupNoScrollBars
		{
			idc = IDC_DEBUG_PAGE_1;
			show = false;
			x = L_BORDER;
			y = 1.1 * GUI_GRID_H;
			w = W_BORDER;
			h = H_BORDER;
			class Controls
			{
				class txt_sideplayer: RscText
				{
					font="PuristaLight";
					//sizeEx = 0.8 * GUI_GRID_H;
					x = 0;
					w = W_BORDER;
					h = GUI_GRID_H;
					
					text = "Side player:";
					y = CUR_Y;
				};
				class combo_sideplayer: RscCombo
				{
					font="PuristaLight";
					idc = IDC_COMBO_SIDEPLAYER;
					x = W_BORDER-(0.25 * DEBUG_W);
					y = CUR_Y;
					w = 0.25 * DEBUG_W;
					h = ADD_HEIGHT(1)
				};
				class seperator1: RscText
				{
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = pixelH;
					colorBackground[] = {1,1,1,1};
				};ADD_Y(0)
				__EXEC(_seperatorCount = 1);
				class txt_teleport: txt_sideplayer
				{
					text = "Enable teleport (SHIFT+T):"; //--- ToDo: Localize;
					y = CUR_Y;
				};
				class cb_teleport: RscCheckbox
				{
					idc = IDC_CB_TELEPORT;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				SEPERATOR(2)
				class txt_unitIcons: txt_sideplayer
				{
					text = "Show icons over units:";
					y = CUR_Y;
				};
				class cb_unitIcons: cb_teleport
				{
					idc = IDC_CB_UNITICONS;
					y = CUR_Y;
				};ADD_Y(1)
				SEPERATOR(3)
				class txt_grids: txt_sideplayer
				{
					text = "Draw grids:";
					y = CUR_Y;
				};
				class cb_grids: cb_teleport
				{
					idc = IDC_CB_GRIDS;
					y = CUR_Y;
				};
				class cb_gridsGUIEditor: cb_teleport
				{
					idc = IDC_CB_GRIDSGUIEDITOR;
					y = CUR_Y;
					x = W_BORDER-(2.1 * GUI_GRID_W);
				}; ADD_Y(1)
				SEPERATOR(4)
				class txt_guigrid: txt_sideplayer
				{
					text = "Change GUI Editor Grid:";
					y = CUR_Y;
				};
				class combo_guigrid: combo_sideplayer
				{
					idc = IDC_COMBO_GUIGRID;
					x = 0.5 * W_BORDER;
					y = CUR_Y;
					w = 0.5 * W_BORDER;
				};ADD_Y(1)
				class btn_gridAnchor: RscButtonMenu
				{
					text = "ORIGIN";
					idc = IDC_BTN_GRIDANCHOR;
					x = 0;
					y = CUR_Y;
					w = 1/3 * W_BORDER - 0.1 * GUI_GRID_W;
					h = 1 * GUI_GRID_H;
				};
				class btn_gridSet: btn_gridAnchor
				{
					idc = IDC_BTN_GRIDSET;
					text = "SET";
					x = 1/3 * W_BORDER;
				};
				class btn_gridExport: btn_gridAnchor
				{
					idc = IDC_BTN_GRIDEXPORT;
					text = "Export Grid";
					x = 2/3 * W_BORDER;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_gridXValue: txt_sideplayer
				{
					text = "X";
					y = CUR_Y;
					w = GUI_GRID_W;
				};
				class ed_gridXValue: RscEdit
				{
					idc = IDC_ED_GRIDXVALUE;
					x = 1.2 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - 1.2 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				class txt_gridYValue: txt_gridXValue
				{
					text = "Y";
					y = CUR_Y;
				};
				class ed_gridYValue: ed_gridXValue
				{
					idc = IDC_ED_GRIDYVALUE;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_gridWValue: txt_gridXValue
				{
					text = "W";
					y = CUR_Y;
				};
				class ed_gridWValue: ed_gridXValue
				{
					idc = IDC_ED_GRIDWVALUE;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_gridHValue: txt_gridXValue
				{
					text = "H";
					y = CUR_Y;
				};
				class ed_gridHValue: ed_gridXValue
				{
					idc = IDC_ED_GRIDHVALUE;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_gridVariable: txt_gridXValue
				{
					text = "Variable";
					y = CUR_Y;
					w = 3 * GUI_GRID_W;
				};
				class ed_gridVariable: ed_gridXValue
				{
					idc = IDC_ED_GRIDVARIABLE;
					x = 3.2 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - 3.2 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				SEPERATOR(5)
				class btn_clearChat: RscButtonMenu
				{
					idc = IDC_BTN_CLEARCHAT;
					text = "Clear chat";
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(1)
				};
				SEPERATOR(6)
				class btn_switchUnit: RscButtonMenu
				{
					idc = IDC_BTN_SWITCHUNIT;
					text = "Switch unit";
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(1)
				};
				SEPERATOR(7)
				class txt_changeTime: txt_sideplayer
				{
					text = "Set time:";
					y = CUR_Y;
				};
				class btn_timeSunrise: RscPictureKeepAspect
				{
					idc = IDC_PIC_TIMESUNRISE;
					text = "\a3\3den\data\attributes\slidertimeday\sun_ca.paa";
					x = W_BORDER - 10.3 * GUI_GRID_W;
					y = CUR_Y;
					w = GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_timeSunset: btn_timeSunrise
				{
					idc = IDC_PIC_TIMESUNSET;
					text = "\a3\3den\data\attributes\date\moon_full_ca.paa";
					x = W_BORDER - 9.2 * GUI_GRID_W;
				};
				class combo_timeHour: combo_sideplayer
				{
					idc = IDC_COMBO_TIMEHOUR;
					x = W_BORDER - 8.1 * GUI_GRID_W;
					y = CUR_Y;
					w = 4 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class combo_timeMinute: combo_timeHour
				{
					idc = IDC_COMBO_TIMEMINUTE;
					x = W_BORDER - 4 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
			};
		};
		// START PAGE 2
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page2: TER_3den_debugConsole_page1
		{
			idc = IDC_DEBUG_PAGE_2;
			class controls 
			{
				class table_watchfields: RscControlsTable
				{
					idc = IDC_DEBUG_TABLEWATCHFIELDS;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = H_BORDER - 0.1 * GUI_GRID_H;
					firstIDC = IDC_DEBUG_WATCHFIELDSFIRSTIDC;
					lastIDC = IDC_DEBUG_WATCHFIELDSLASTIDC;
					lineSpacing = 0.2 * GUI_GRID_H;
					rowHeight = 2.1 * GUI_GRID_H;
					headerHeight = 1.1 * GUI_GRID_H;
					selectedRowColorFrom[] = {0,0,0,0};
					selectedRowColorTo[] = {0,0,0,0};
					selectedRowAnimLength = 1e+6;
					class VScrollBar
					{
						width = 0;
					};
					class HScrollBar
					{
						height = 0;
					};
					class HeaderTemplate
					{
						class HeaderBackground
						{
							controlBaseClassPath[] = {"RscStructuredText"};
							columnX = 0;
							controlOffsetY = 0;
							columnW = W_BORDER;
							controlH = 1 * GUI_GRID_H;
						};
						//--- Add field button
						class Column1: HeaderBackground
						{
							controlBaseClassPath[] = {"RscButtonMenu"};
							columnX = W_BORDER - GUI_GRID_W;
							columnW = GUI_GRID_W;
						};
					};
					class RowTemplate
					{
						class RowBackground
						{
							controlBaseClassPath[] = {"RscText"};
							columnX = 0;
							controlOffsetY = 0;
							columnW = 0;
							controlH = 0;
						};
						//--- Live checkbox
						class Column1 
						{
							controlBaseClassPath[] = {"RscCheckbox"};
							columnX = 0;
							controlOffsetY = 0;
							columnW = 1 * GUI_GRID_W;
							controlH = GUI_GRID_H;
						};
						//--- Command edit
						class Column2: Column1 
						{
							controlBaseClassPath[] = {"RscDebugConsole","controls","WatchInput1"};
							columnX = 1.1 * GUI_GRID_W;
							//controlOffsetY = 0.1 * GUI_GRID_H;
							columnW = W_BORDER - 2.2 * GUI_GRID_W;
						};
						//--- ActPic delete
						class Column3: Column1
						{
							controlBaseClassPath[] = {"RscActivePicture"};
							columnX = W_BORDER - 1 * GUI_GRID_W;
							columnW = 1 * GUI_GRID_W;
						};
						//--- Text output
						class Column4: Column1
						{
							controlBaseClassPath[] = {"RscDebugConsole","controls","WatchOutput1"};
							columnX = 0;
							controlOffsetY = 1.1 * GUI_GRID_H;
							columnW = W_BORDER;
						};
					};
				};
			};
		};
		// START PAGE 3
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page3: TER_3den_debugConsole_page1
		{
			idc = IDC_DEBUG_PAGE_3;
			class controls 
			{
				class txt_cc: RscText
				{
					font="PuristaLight";
					text = "Custom Commands:";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = 1 * GUI_GRID_H;
				};
				class combo_cc_locality: RscCombo
				{
					idc = IDC_DEBUG_CCLOCALITY;
					font="PuristaLight";
					x = W_BORDER -((1.2 +8) * GUI_GRID_W);
					y = CUR_Y;
					w = 8 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_cc_add: RscButtonMenu
				{
					idc = IDC_DEBUG_CCADD;
					text = "+";
					style = ST_CENTER;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
					tooltip = "Add custom command";
				};
				class table_customcommands: RscControlsTable
				{
					idc = IDC_DEBUG_TABLECC;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = H_BORDER - 2.3 * GUI_GRID_H;
					firstIDC = IDC_DEBUG_CCFIRSTIDC;
					lastIDC = IDC_DEBUG_CCLASTIDC;
					lineSpacing = 0.2 * GUI_GRID_H;
					rowHeight = 1 * GUI_GRID_H;
					headerHeight = 1.1 * GUI_GRID_H;
					selectedRowColorFrom[] = {0,0,0,0};
					selectedRowColorTo[] = {0,0,0,0};
					selectedRowAnimLength = 1e+6;
					class VScrollBar
					{
						width = 0;
					};
					class HScrollBar
					{
						height = 0;
					};
					class RowTemplate
					{
						//--- Exec button
						class Column1 
						{
							controlBaseClassPath[] = {"RscButtonMenu"};
							columnX = 0;
							controlOffsetY = 0;
							columnW = 2.5 * GUI_GRID_W;
							controlH = GUI_GRID_H;
						};
						//--- Code edit
						class Column2: Column1 
						{
							controlBaseClassPath[] = {"RscDebugConsole","controls","WatchInput1"};
							columnX = 2.6 * GUI_GRID_W;
							controlOffsetY = 0.1 * GUI_GRID_H;
							columnW = W_BORDER - 3.7 * GUI_GRID_W;
						};
						//--- ActPic delete
						class Column3: Column1
						{
							controlBaseClassPath[] = {"RscActivePicture"};
							columnX = W_BORDER - 1 * GUI_GRID_W;
							columnW = 1 * GUI_GRID_W;
						};
					};
				};
				class ed_ccoutput: TER_3den_RscEditCodeOutput
				{
					idc = IDC_DEBUG_EDOUTPUTCC;
					x = 0;
					y = H_BORDER - 1 * GUI_GRID_H;
					w = W_BORDER;
					h = GUI_GRID_H;
				};
			};
		};
		// START PAGE 4
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page4: TER_3den_debugConsole_page1
		{
			idc = IDC_DEBUG_PAGE_4;
			class controls 
			{
				class txt_watchHistory: RscText
				{
					font="PuristaLight";
					text = "Saved Watch entries:";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = 1 * GUI_GRID_H;
				};
				class combo_watchIn: RscCombo
				{
					idc = IDC_COMBO_WATCHIN;
					x = W_BORDER -(10 * GUI_GRID_W);
					y = CUR_Y;
					w = 10 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				class lb_watchHistory: RscListbox
				{
					idc = IDC_LB_WATCHHISTORY;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(4)
				};
				class btn_historyMove: RscButtonMenu
				{
					idc = IDC_BTN_HISTORYMOVE;
					text = "Move to watch";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/3 - 0.1 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_historyDeleteEntry: btn_historyMove
				{
					idc = IDC_BTN_HISTORYDELETEENTRY;
					text = "DELETE ENTRY";
					x = 1/3 * W_BORDER;
				};
				class btn_clearHistory: btn_historyMove
				{
					idc = IDC_BTN_CLEARHISTORY;
					text = "Clear list";
					colorBackground[] = DEEP_RED;
					x = 2/3 * W_BORDER;
					h = ADD_HEIGHT(1)
				};
				class seperator1: RscText
				{
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = pixelH;
					colorBackground[] = {1,1,1,1};
				};ADD_Y(0)
				class txt_targetDebug: RscText
				{
					font="PuristaLight";
					//sizeEx = 0.8 * GUI_GRID_H;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = GUI_GRID_H;
					text = "Enable target debugging:";
					//tooltip = __EVAL( format ["Add: Write you command in the edit and click ADD %1 You can only write your command, cursorObject will get added automatically%1Remove: Double click the command in the list box%1Commands are persistent throughout the session",toString [10]]; );
				};
				class cb_targetDebug: RscCheckbox
				{
					idc = IDC_CB_TARGETDEBUG;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				class ed_targetDebug_command: TER_3den_RscEditCode
				{
					idc = IDC_ED_TDCOMMAND;
					tooltip = "Write your command here and add it with the + button";
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - (2.3 * GUI_GRID_W);
					h = 1 * GUI_GRID_H;
				};
				class btn_targetDebug_add: RscButtonMenu
				{
					idc = IDC_BTN_TDADD;
					text = "+";
					tooltip = "Add your command to the watch list";
					x = W_BORDER -(2.1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_targetDebug_remove: btn_targetDebug_add
				{
					idc = IDC_BTN_TDREMOVE;
					text = "-";
					tooltip = "Remove selected entry";
					x = W_BORDER -(1 * GUI_GRID_W);
					h = ADD_HEIGHT(1)
				};
				class lb_targetDebug_commands: RscListbox
				{
					idc = IDC_LB_TDCOMMANDS;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(3)
				};
				SEPERATOR(2)
				class txt_links: RscText
				{
					font="PuristaLight";
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = GUI_GRID_H;
					text = "BIKI Links";
				};ADD_Y(1)
				class ed_link: TER_3den_RscEditCode
				{
					idc = IDC_ED_LINK;
					tooltip = "Write your command here and add it with the + button";
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - (1.2 * GUI_GRID_W);
					h = 1 * GUI_GRID_H;
				};
				class btn_linkAdd: RscButtonMenu
				{
					idc = IDC_BTN_LINKADD;
					text = "+";
					tooltip = "Add Link";
					x = W_BORDER -(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				class grp_links: RscControlsGroup
				{
					idc = IDC_GRP_LINKS;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(6)
					class controls
					{
						class stxt_links: RscStructuredText
						{
							idc = IDC_STXT_LINKS;
							colorBackground[] = {0,0,0,0.8};
							x = 0;
							y = 0;
							w = W_BORDER;
							h = 6 * GUI_GRID_H;
						};
					};
				};
			};
		};
		// START PAGE 5
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page5: TER_3den_debugConsole_page1
		{
			idc = IDC_DEBUG_PAGE_5;
			class controls
			{
				class txt_unitWatch: RscText
				{
					idc = -1;
					text = "Watch unit";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = ADD_HEIGHT(1)
				};
				class ed_unitWatch_search: RscEdit
				{
					idc = IDC_ED_UWSEARCH;
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER -(0.3 * GUI_GRID_W);
					h = ADD_HEIGHT(1)
				};
				class tv_unitWatch: RscTreeSearch
				{
					idc = IDC_TV_UWTREE;
					idcSearch = IDC_ED_UWSEARCH;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(10)
				};
				class pic_liveFeed: RscPicture
				{
					idc = IDC_PIC_UWLIVEFEED;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = W_BORDER;
				};
				class cb_liveFeedLive: RscCheckbox
				{
					idc = IDC_CB_UWLIVEFEEDLIVE;
					tooltip = "Keep feed open";
					x = W_BORDER -(GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h= GUI_GRID_H;
				};
			};
		};
		// START PAGE 6
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page6: TER_3den_debugConsole_page1
		{
			idc = IDC_DEBUG_PAGE_6;
			class controls
			{
				class txt_kkDebug: RscText
				{
					idc = -1;
					text = "KK Debug";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = ADD_HEIGHT(1)
				};
				class txt_kkColor: txt_kkDebug
				{
					text = "Color:";
					y = CUR_Y;
				};
				class cb_kkRed: RscCheckbox
				{
					idc = IDC_CB_KKRED;
					x = W_BORDER - 4.4 * GUI_GRID_W;
					y = CUR_Y;
					w = GUI_GRID_W;
					h = GUI_GRID_H;
					checked = 1;
				};
				class cb_kkGreen: cb_kkRed
				{
					idc = IDC_CB_KKGREEN;
					x = W_BORDER - 3.3 * GUI_GRID_W;
				};
				class cb_kkBlue: cb_kkRed
				{
					idc = IDC_CB_KKBLUE;
					x = W_BORDER - 2.2 * GUI_GRID_W;
				};
				class pic_kkColor: RscPicture
				{
					idc = IDC_PIC_KKCOLOR;
					text = "#(rgb,8,8,3)color(1,1,1,1)";
					x = W_BORDER - 1.1 * GUI_GRID_W;
					y = CUR_Y;
					w = GUI_GRID_W;
					h = ADD_HEIGHT(1)
				};
				class txt_kkTime: txt_kkDebug
				{
					text = "Log time:";
					y = CUR_Y;
				};
				class cb_kkTime: cb_kkRed
				{
					idc = IDC_CB_KKTIME;
					x = W_BORDER - 1.1 * GUI_GRID_W;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_kkLogInput: txt_kkDebug
				{
					text = "Log input:";
					y = CUR_Y;
				};
				class cb_kkLogInput: cb_kkTime
				{
					idc = IDC_CB_KKLOGINPUT;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class txt_kkFile: txt_kkDebug
				{
					text = "Log to file:";
					y = CUR_Y;
				};
				class cb_kkFile: cb_kkTime
				{
					idc = IDC_CB_KKFILE;
					checked = 0;
					y = CUR_Y;
					h = ADD_HEIGHT(1)
				};
				class btn_kkBeep: RscButtonMenu
				{
					idc = IDC_BTN_KKBEEP;
					text = "Beep";
					x = 0;
					y = CUR_Y;
					w = 1/4 * W_BORDER - 0.3 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_kkClear: btn_kkBeep
				{
					idc = IDC_BTN_KKCLEAR;
					text = "Clear";
					x = 1/4 * W_BORDER;
				};
				class btn_kkClose: btn_kkBeep
				{
					idc = IDC_BTN_KKCLOSE;
					text = "Close";
					x = 2/4 * W_BORDER;
				};
				class btn_kkLog: btn_kkBeep
				{
					idc = IDC_BTN_KKLOG;
					text = "LOG";
					x = 3/4 * W_BORDER;
				};
				ADD_Y(1)
				class ed_kkInput: RscEdit
				{
					idc = IDC_ED_KKINPUT;
					style = ST_MULTI;
					autocomplete = "scripting";
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - 0.3 * GUI_GRID_W;
					h = DEBUG_H - 10.4 * GUI_GRID_H;
				};
				class ed_kkOutput: ed_kkInput
				{
					idc = IDC_ED_KKOUTPUT;
					y = DEBUG_H - 3.6 * GUI_GRID_H;
					h = GUI_GRID_H;
				};
			};
		};
		class lb_pages: RscCombo
		{
			idc = IDC_LB_PAGES;
			x = 0;
			y = DEBUG_H - GUI_GRID_H;
			w = DEBUG_W;
			h = GUI_GRID_H;
			arrowEmpty = "\a3\ui_f\data\gui\cfg\scrollbar\arrowempty_ca.paa";
			arrowFull = "\a3\ui_f\data\gui\cfg\scrollbar\arrowfull_ca.paa";
		};
	};
};

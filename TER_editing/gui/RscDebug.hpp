#define DEBUG_W (22 * GUI_GRID_W)
#define DEBUG_H (32.2 * GUI_GRID_H)
#define L_BORDER (0.5 * GUI_GRID_W)
#define R_BORDER (21.5 * GUI_GRID_W)
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
		class ed_input: TER_3den_RscEditCode
		{
			idc = 7490;
			x = 0.1 * GUI_GRID_W;
			y = 0.1 * GUI_GRID_H;
			w = W_BORDER-(1.2 * GUI_GRID_W);
			h = GUI_GRID_H;
		};
		class btn_delete: RscButtonMenu
		{
			idc = 7491;
			text = "X";
			tooltip = "Delete";
			style = ST_CENTER;
			colorBackground[] = DEEP_RED;
			x = W_BORDER-(1 * GUI_GRID_W);
			y = 0.1 * GUI_GRID_H;
			w = GUI_GRID_W;
			h = GUI_GRID_H;
		};
		class ed_output: TER_3den_RscEditCodeOutput
		{
			idc = 7492;
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
			idc = 7493;
			text = "Execute";
			x = 0;
			y = 0;
			w = 2.5 * GUI_GRID_W;
			h = GUI_GRID_H;
		};
		class ed_cc_code: TER_3den_RscEditCode
		{
			idc = 7494;
			x = 2.6 * GUI_GRID_W;
			y = 0;
			w = W_BORDER - (3.7 * GUI_GRID_W);
			h = GUI_GRID_H;
		};
		class btn_cc_delete: RscButtonMenu
		{
			idc = 7495;
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
//#define GLUE(PART_ONE, PART_TWO) PART_ONE##PART_TWO
#define SEPERATOR(NUMBER) class seperator##NUMBER: seperator1\
				{\
					y = CUR_Y;\
				};ADD_Y(0)

/* 
 page 1: live debug, side player, teleport, unit icons, grids, clear chat, editor grid
 page 2: watch fields
 page 3: Custom commands
 page 4: BIKI links, target debug, recent watch entries
 */
class TER_3den_debugConsole: RscControlsGroupNoScrollBars
{
	idc = 73040;
	x = 40 * GUI_GRID_W + GUI_GRID_X;
	y = safezoneY + 1 * GUI_GRID_H;
	w = DEBUG_W;
	h = DEBUG_H;
	ONLOAD(Debug)
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
		// page 1: everything
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page1: RscControlsGroupNoScrollBars
		{
			idc = 73041;
			x = L_BORDER;
			y = 1.1 * GUI_GRID_H;
			w = W_BORDER;
			h = DEBUG_H -(2.3 * GUI_GRID_H);
			class Controls
			{
				class btn_liveDebug: RscButtonMenu
				{
					idc = 7402;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(1);
					text = "Live Debug";
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
					idc = 7404;
					x = W_BORDER-(0.25 * DEBUG_W);
					y = CUR_Y;
					w = 0.25 * DEBUG_W;
					h = ADD_HEIGHT(1);
				};
				SEPERATOR(2)
				class txt_teleport: txt_sideplayer
				{
					text = "Enable teleport (SHIFT+T):"; //--- ToDo: Localize;
					y = CUR_Y;
				};
				class cb_teleport: RscCheckbox
				{
					idc = 7401;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h = ADD_HEIGHT(1);
				};
				SEPERATOR(3)
				class txt_unitIcons: txt_sideplayer
				{
					text = "Show icons over units:";
					y = CUR_Y;
				};
				class cb_unitIcons: cb_teleport
				{
					idc = 7403;
					y = CUR_Y;
				};ADD_Y(1)
				SEPERATOR(4)
				class txt_grids: txt_sideplayer
				{
					text = "Draw grids:";
					y = CUR_Y;
				};
				class cb_grids: cb_teleport
				{
					idc = 7400;
					y = CUR_Y;
				};ADD_Y(1)
				SEPERATOR(5)
				class txt_guigrid: txt_sideplayer
				{
					text = "Change GUI Editor Grid:";
					y = CUR_Y;
				};
				class combo_guigrid: combo_sideplayer
				{
					idc = 7419;
					x = 0.5 * W_BORDER;
					y = CUR_Y;
					w = 0.5 * W_BORDER;
				};ADD_Y(1)
				class txt_exportGrid: txt_sideplayer
				{
					text = "How to: Export Grid";
					tooltip = "Press CTRL+SHIFT+P in the GUI Editor to export the current grid variables";
					x = 0.5 * W_BORDER;
					y = CUR_Y;
					w = 0.5 * W_BORDER;
				};ADD_Y(1)
				SEPERATOR(6)
				class btn_clearChat: RscButtonMenu
				{
					idc = 7418;
					text = "Clear chat";
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(1);
				};
				SEPERATOR(7)
				class btn_switchUnit: RscButtonMenu
				{
					idc = 7424;
					text = "Switch unit";
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(1);
				};
			};
		};
		// START PAGE 2
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page2: TER_3den_debugConsole_page1
		{
			idc = 73042;
			class controls 
			{
				class txt_moreWatch: RscText
				{
					font="PuristaLight";
					text = "More watch fields:";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = 1 * GUI_GRID_H;
				};
				class btn_addWatch: RscButtonMenu
				{
					idc = 7409;
					text = "+";
					style = ST_CENTER;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1);
					tooltip = "Create new watch field";
				};
				class grp_watchFields: RscControlsGroupNoScrollBars
				{
					idc = 7410;
					colorBackground[] = {1,0,0,1};
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = DEBUG_H - 3.5 * GUI_GRID_H;
				};
			};
		};
		// START PAGE 3
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page3: TER_3den_debugConsole_page1
		{
			idc = 73043;
			class controls 
			{
				class txt_customCommands: RscText
				{
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = 1 * GUI_GRID_H;
					font="PuristaLight";
					text = "Custom commands:";
				};
				class combo_cc_locality: RscCombo
				{
					idc = 7416;
					x = W_BORDER -((1.2 +3.5) * GUI_GRID_W);
					y = CUR_Y;
					w = 3.5 * GUI_GRID_W;
					h = GUI_GRID_H;
				};
				class btn_cc_add: RscButtonMenu
				{
					idc = 7411;
					text = "+";
					style = ST_CENTER;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1);
					tooltip = "Add custom command";
				};
				class grp_cc_commands: RscControlsGroupNoScrollBars
				{
					idc = 7412;
					colorBackground[] = {1,0,0,1};
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = DEBUG_H - 3.5 * GUI_GRID_H;
				};
			};
		};
		// START PAGE 4
		__EXEC(_curY = 0.1)
		class TER_3den_debugConsole_page4: TER_3den_debugConsole_page1
		{
			idc = 73044;
			class controls 
			{
				class txt_watchHistory: RscText
				{
					font="PuristaLight";
					tooltip = "Double click to activate. Press ""DEL"" to delete the selected entry";
					text = "Recent Watch entries:";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = 1 * GUI_GRID_H;
				};
				class combo_watchIn: RscCombo
				{
					idc = 7414;
					x = W_BORDER -(10 * GUI_GRID_W);
					y = CUR_Y;
					w = 10 * GUI_GRID_W;
					h = ADD_HEIGHT(1);
				};
				class lb_watchHistory: RscListbox
				{
					idc = 7413;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(4);
				};
				class btn_clearHistory: RscButtonMenu
				{
					idc = 7415;
					text = "Clear history";
					colorBackground[] = DEEP_RED;
					x = (W_BORDER/2)+ (0.1 * GUI_GRID_W);
					y = CUR_Y;
					w = (W_BORDER/2)- (0.1 * GUI_GRID_W);
					h = ADD_HEIGHT(1);
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
					idc = 7405;
					x = W_BORDER-(1 * GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h = ADD_HEIGHT(1);
				};
				class ed_targetDebug_command: TER_3den_RscEditCode
				{
					idc = 7406;
					tooltip = "Write your command here and add it with the + button";
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - (1.2 * GUI_GRID_W);
					h = 1 * GUI_GRID_H;
				};
				class btn_targetDebug_add: RscButtonMenu
				{
					idc = 7407;
					text = "+";
					tooltip = "Add your command to the watch list";
					x = W_BORDER -(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1);
				};
				class lb_targetDebug_commands: RscListbox
				{
					idc = 7408;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(3);
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
					idc = 7420;
					tooltip = "Write your command here and add it with the + button";
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER - (1.2 * GUI_GRID_W);
					h = 1 * GUI_GRID_H;
				};
				class btn_linkAdd: RscButtonMenu
				{
					idc = 7421;
					text = "+";
					tooltip = "Add Link";
					x = W_BORDER -(1 * GUI_GRID_W);
					y = CUR_Y;
					w = 1 * GUI_GRID_W;
					h = ADD_HEIGHT(1);
				};
				class grp_links: RscControlsGroup
				{
					idc = 7422;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(6);
					class controls
					{
						class stxt_links: RscStructuredText
						{
							idc = 7423;
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
			idc = 73045;
			class controls
			{
				class txt_unitWatch: RscText
				{
					idc = -1;
					text = "Watch unit";
					x = 0;
					y = CUR_Y;
					w = W_BORDER/2;
					h = ADD_HEIGHT(1);
				};
				class ed_unitWatch_search: RscEdit
				{
					idc = 7425;
					x = 0.1 * GUI_GRID_W;
					y = CUR_Y;
					w = W_BORDER -(0.3 * GUI_GRID_W);
					h = ADD_HEIGHT(1);
				};
				class tv_unitWatch: RscTreeSearch
				{
					idc = 7426;
					idcSearch = 7425;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = ADD_HEIGHT(10);
				};
				class pic_liveFeed: RscPicture
				{
					idc = 7427;
					x = 0;
					y = CUR_Y;
					w = W_BORDER;
					h = W_BORDER;
					text = "#(argb,512,512,1)r2t(ter_3den_unitrtt,1.0)";
				};
				class cb_liveFeedLive: RscCheckbox
				{
					idc = 7428;
					tooltip = "Keep feed open";
					x = W_BORDER -(GUI_GRID_W);
					y = CUR_Y;
					w = GUI_GRID_W;
					h= GUI_GRID_H;
				};
			};
		};
		class xlb_pages: RscCombo
		{
			idc = 7399;
			x = 0;
			y = DEBUG_H - GUI_GRID_H;
			w = DEBUG_W;
			h = GUI_GRID_H;
		};
	};
};

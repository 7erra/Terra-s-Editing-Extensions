#define W_DISPLAY (32 * UI_GRID_W)
#define H_DISPLAY (24 * UI_GRID_H)
class TER_3den_RscDisplayCtrlsExplained
{
	idd = IDD_DISPLAY_CTRLSEXPLAINED;
	onLoad = "[""onload"",_this] execVM ""TER_Editing\gui\scripts\RscCtrlsExplained.sqf"";";
	class controlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class background: ctrlStaticBackground
		{
			x = -16.1 * UI_GRID_W + 0.5;
			y = -11.1 * UI_GRID_H + 0.5;
			w = 32.2 * UI_GRID_W;
			h = 23.2 * UI_GRID_H;
		};
		class title: ctrlStaticTitle
		{
			text = "GUI Controls Explained";
			x = -16.1 * UI_GRID_W + 0.5;
			y = -12.1 * UI_GRID_H + 0.5;
			w = 32.2 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class backContent: ctrlStaticOverlay
		{
			x = -16 * UI_GRID_W + 0.5;
			y = -9.9 * UI_GRID_H + 0.5;
			w = 23.4 * UI_GRID_W;
			h = 18.7 * UI_GRID_H;
		};
		class html_loadTest: ctrlHTML
		{
			idc = IDC_EXPLAIN_HTMLLOADTEST;
			show = false;
			x=0; y=0; w=0; h=0;
		};
	};
	class controls
	{
		class stxt_curTitle: ctrlStructuredText
		{
			idc = IDC_EXPLAIN_CURTITLE;
			x = -16 * UI_GRID_W + 0.5;
			y = -11 * UI_GRID_H + 0.5;
			w = 23.4 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class grp_content: ctrlControlsGroup
		{
			idc = IDC_EXPLAIN_GRPCONTENT;
			x = -15.9 * UI_GRID_W + 0.5;
			y = -9.8 * UI_GRID_H + 0.5;
			w = 23.3 * UI_GRID_W;
			h = 18.6 * UI_GRID_H;
		};
		class ed_output: ctrlEdit
		{
			idc = IDC_EXPLAIN_OUTPUT;
			style = ST_MULTI;
			canmodify = 0;
			x = -15.9 * UI_GRID_W + 0.5;
			y = 9 * UI_GRID_H + 0.5;
			w = 23.3 * UI_GRID_W;
			h = 3 * UI_GRID_H;
		};
		class lnb_cttypes: ctrlListNBox
		{
			idc = IDC_EXPLAIN_LNBCTTYPES;
			columns[] = {0.01,0.7};
			x = 7.5 * UI_GRID_W + 0.5;
			y = -11 * UI_GRID_H + 0.5;
			w = 8.5 * UI_GRID_W;
			h = 21.9 * UI_GRID_H;
		};
		class btn_close: ctrlButtonOK
		{
			text = "Close"; //--- ToDo: Localize;
			x = 7.5 * UI_GRID_W + 0.5;
			y = 11 * UI_GRID_H + 0.5;
			w = 8.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};

class TER_3den_RscToolboxExample: RscToolbox
{
	strings[] = {"Entry 0","Entry 1","Entry 2","Entry 3","Entry 4","Entry 5"};
	rows = 3;
	columns = 2;
};
class TER_3den_RscToolboxExample2: TER_3den_RscToolboxExample
{
	style= ST_CENTER + ST_PICTURE + ST_KEEP_ASPECT_RATIO;
	rows=1;
	columns=6;
	strings[]=
	{
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa"
	};
	tooltips[]=
	{
		"$STR_3DEN_Object_textPlural",
		"$STR_3DEN_Group_textPlural",
		"$STR_3DEN_Trigger_textPlural",
		"$STR_3DEN_Waypoint_textPlural",
		"$STR_3DEN_Logic_textPlural",
		"$STR_3DEN_Marker_textPlural"
	};
};
class TER_3den_RscCheckboxesExample: ctrlCheckboxes
{
	style = ST_MULTI + ST_CENTER;
	rows = 2;
	columns = 5;
	strings[] = {"0","1","2","3","4","5","6","7","8","9"};
	checked_strings[] = {"[0]","[1]","[2]","[3]","[4]","[5]","[6]","[7]","[8]","[9]"};
};
class TER_3den_RscCheckboxesExample2: TER_3den_RscCheckboxesExample
{
	style = ST_LEFT;
	rows = 2;
	columns = 1;
	strings[] = {"Option 1: No","Option 2: Yes"};
	checked_strings[] = {"Option 1: Yes","Option 2: No"};
};
class TER_3den_RscListNBoxExample: RscListNBox
{
	columns[] = {0.1,0.75};
	idcLeft = 199;
	idcRight = 198;
	drawSideArrows = 1;
};
class TER_3den_ctrlMenuStripExample: ctrlMenuStrip
{
	class items
	{
		items[] = {};
		class Default
		{
			text="";
			data="Empty";
			enable=0;
		};
	};
};

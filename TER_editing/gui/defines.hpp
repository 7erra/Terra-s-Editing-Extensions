#define STR(TEXT) #TEXT
#define ARGS [STR(STR(onLoad)), _this]
#define SCRIPT_STR(FILE) STR(STR(TER_Editing\gui\scripts\FILE.sqf))
#define ONLOAD(SCRIPT) onLoad = STR(ARGS execVM SCRIPT_STR(SCRIPT);)

#define DEBUG_TEXTWIDTH_UIGRID onLoad = STR(diag_log ((ctrlTextWidth (_this select 0)) / UI_GRID_W));

#include "\a3\ui_f\hpp\definedikcodes.inc"

#include "defaultControls.hpp"
class TER_3den_RscEditMulti: RscEdit
{
	style = ST_MULTI;
	canModify = 0;
};
class TER_3den_RscTitleBackground: RscTitle
{
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
};
class TER_3den_RscBackground: RscText
{
	colorBackground[] = {0,0,0,0.8};
};
class TER_3den_ctrlStructuredText: ctrlStructuredText
{
	class Attributes
	{
		align = "left";
		color = "#ffffff";
		colorLink = "#0000ff";
		size = 1;
		font = "RobotoCondensedLight";
	};
};

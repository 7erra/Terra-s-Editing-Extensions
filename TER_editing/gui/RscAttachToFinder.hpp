#define ATTACH_H (8.5 * UI_GRID_H)
#define ATTACH_W (18.3 * UI_GRID_W)
class TER_3den_RscAttachToFinder: RscControlsGroupNoScrollbars
{
	idc = 73100;
	ONLOAD(AttachToFinder)
	x = safezoneX + safeZoneW/2 - (ATTACH_W/2);
	y = 26 * UI_GRID_H + UI_GRID_Y;
	w = ATTACH_W;
	h = ATTACH_H;
	class controls
	{
		//back
		class background: ctrlStaticBackground
		{
			x = 0;
			y = 0;
			w = ATTACH_W;
			h = ATTACH_H;
		};
		class title: ctrlStaticTitle
		{
			colorBackground[] = {0,0,0,1};
			text = "attachTo Finder";
			x = 0;
			y = 0;
			w = ATTACH_W;
			h = 1 * UI_GRID_H;
		};
		class txt_offest: ctrlStructuredText
		{
			idc = -1;
			text = "Offset:"; //--- ToDo: Localize;
			x = 0.1 * UI_GRID_W;
			y = 2.2 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_mempoint: ctrlStructuredText
		{
			idc = -1;
			text = "Memory Points:"; //--- ToDo: Localize;
			x = 0.1 * UI_GRID_W;
			y = 3.3 * UI_GRID_H;
			w = 8 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txt_vetor: ctrlStructuredText
		{
			idc = -1;
			text = "VectorDirAndUp:"; //--- ToDo: Localize;
			x = 0.1 * UI_GRID_W;
			y = 6.4 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		// foreground
		class btn_close: ctrlButtonPicture
		{
			idc = 7306;
			x = ATTACH_W - UI_GRID_W;
			y = 0;
			w = UI_GRID_W;
			h = UI_GRID_H;
			text="\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
		};
		class btn_baseobject: ctrlButton
		{
			idc = 7300;
			text = "Set as base object"; //--- ToDo: Localize;
			x = 0.1 * UI_GRID_W;
			y = 1.1 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class btn_attachedobject: ctrlButton
		{
			idc = 7301;
			text = "Set as attached object"; //--- ToDo: Localize;
			x = 9.2 * UI_GRID_W;
			y = 1.1 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class ed_offset: ctrlEdit
		{
			idc = 7302;
			x = 9.2 * UI_GRID_W;
			y = 2.2 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			canModify = 0;
		};
		class cb_showMemPoints: ctrlCheckbox
		{
			idc = 7303;
			x = 8 * UI_GRID_W;
			y = 3.3 * UI_GRID_H;
			w = 1 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			tooltip = "Show memory points"; //--- ToDo: Localize;
		};
		class lb_mempoints: ctrlListbox
		{
			idc = 7304;
			x = 9.2 * UI_GRID_W;
			y = 3.3 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 3 * UI_GRID_H;
		};
		class ed_vector: ctrlEdit
		{
			idc = 7305;
			x = 9.2 * UI_GRID_W;
			y = 6.4 * UI_GRID_H;
			w = 9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			canModify = 0;
		};
		class btn_export: ctrlButton
		{
			idc = 7307;
			text = "Export commands";
			x = 0.1 * UI_GRID_W;
			y = 7.5 * UI_GRID_H;
			w = ATTACH_W -(0.2 * UI_GRID_W);
			h = UI_GRID_H;
		};
	};
};

#define DIALOG_W 35
#define DIALOG_H (safeZoneH - 2 * CUI_GRID_H)
class TER_3den_RscDisplay3denViewRPT
{
	idd = -1;
	movingEnable = 1;
	INIT_DISPLAY(TER_3den_RscDisplay3denViewRPT,TER_Editing)
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class TitleHeader: ctrlStaticTitle
		{
			text = "Latest RPT";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = safeZoneY + 1 * UI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = CUI_GRID_H;
		};
		class Background: ctrlStaticBackground
		{
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = safeZoneY + 2 * UI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = DIALOG_H - 1 * CUI_GRID_H;
		};
	};
	class Controls
	{
		class ContentGroup: ctrlControlsGroup
		{
			x = CUI_GRID_X - 0.5 * DIALOG_W * CUI_GRID_W + 0.1 * CUI_GRID_W;
			y = safeZoneY + 2.1 * CUI_GRID_H;
			w = (DIALOG_W - 0.2) * CUI_GRID_W;
			h = DIALOG_H - 2.2 * CUI_GRID_H;
			colorBackground[] = {1,0,0,0.1};
			class Controls
			{
				class Content: ctrlStructuredText
				{
					idc = IDC_RSCDISPLAY3DENLASTRPT_CONTENT;
					text = "Loading RPT...";
					x = 0;
					y = 0;
					w = (DIALOG_W - 0.2) * CUI_GRID_W;
					h = DIALOG_H - 2.2 * CUI_GRID_H;
					style = ST_NO_RECT + ST_MULTI;
					canModify = 0;
					size = 0.7 * CUI_GRID_H;
					shadow = 0;
					colorBackground[] = {0,0,0,0.8};
					class Attributes
					{
						font = "EtelkaMonospacePro";
					};
				};
			};
		};
		class Reload: ctrlButton
		{
			idc = IDC_RSCDISPLAY3DENLASTRPT_RELOAD;
			text = "Reload";
			x = CUI_GRID_X - 0.5 * DIALOG_W * CUI_GRID_W + 0.1 * CUI_GRID_W;
			y = safeZoneY + DIALOG_H - 0.1 * CUI_GRID_H;
			w = 5 * UI_GRID_W;
			h = CUI_GRID_H;
		};
		class Open: Reload
		{
			idc = IDC_RSCDISPLAY3DENLASTRPT_OPEN;
			text = "Open RPT";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W + 5.2 * CUI_GRID_W;
		};
		class Close: ctrlButtonClose
		{
			x = CUI_GRID_X + DIALOG_W / 2 * CUI_GRID_W - 5.1 * CUI_GRID_W;
			y = safeZoneY + DIALOG_H - 0.1 * CUI_GRID_H;
			w = 5 * CUI_GRID_W;
			h = CUI_GRID_H;
		};
	};
};

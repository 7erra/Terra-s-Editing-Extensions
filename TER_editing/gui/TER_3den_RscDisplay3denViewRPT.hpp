#define DIALOG_W 35
#define DIALOG_H 20
class TER_3den_RscDisplay3denViewRPT
{
	idd = -1;
	movingEnable = 1;
	INIT_DISPLAY(TER_3den_RscDisplay3denViewRPT,TER)
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Background: ctrlStaticBackground
		{
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = CUI_GRID_Y - 13 * CUI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = DIALOG_H * CUI_GRID_H;
		};
		class TitleHeader: ctrlStaticTitle
		{
			text = "Latest RPT";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = CUI_GRID_Y - 14 * CUI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = CUI_GRID_H;
		};
	};
	class Controls
	{
		class ContentGroup: ctrlControlsGroup
		{
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = CUI_GRID_Y - 13 * CUI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = DIALOG_H * CUI_GRID_H - CUI_GRID_H - 3/5 * CUI_GRID_H;
			class Controls
			{
				class Content: ctrlStructuredText
				{
					idc = IDC_RSCDISPLAY3DENLASTRPT_CONTENT;
					x = 0;
					y = 0;
					w = DIALOG_W * CUI_GRID_W;
					h = DIALOG_H * CUI_GRID_H - CUI_GRID_H - 3/5 * CUI_GRID_H;
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
		class Lines: ctrlStatic
		{
			text = "Lines:";
			tooltip = "Define the number of lines to be shown. 30 means the last 30 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
			x = CUI_GRID_X + DIALOG_W / 2 * CUI_GRID_W - 12 * CUI_GRID_W;
			y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.2 * CUI_GRID_H;
			w = 3 * CUI_GRID_W;
			h = CUI_GRID_H;
		};
		class EditLines: ctrlEdit
		{
			idc = IDC_RSCDISPLAY3DENLASTRPT_EDITLINES;
			tooltip = "Define the number of lines to be shown. 30 means the last 30 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
			x = CUI_GRID_X + DIALOG_W / 2 * CUI_GRID_W - 9 * CUI_GRID_W;
			y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.2 * CUI_GRID_H;
			w = 3 * CUI_GRID_W;
			h = CUI_GRID_H;
			maxChars = 3;
		};
		class Progress: ctrlProgress
		{
			idc = IDC_RSCDISPLAY3DENLASTRPT_PROGRESS;
			tooltip = "Shows the progress. A full bar indicates that all available lines were loaded.";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
			y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.6 * CUI_GRID_H;
			w = DIALOG_W * CUI_GRID_W;
			h = 1/5 * CUI_GRID_H;
			colorFrame[] = {0,0,0,0};
		};
		class Reload: ctrlButton
		{
			idc = IDC_RSCDISPLAY3DENLASTRPT_RELOAD;
			text = "Reload";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W + 0.1 * CUI_GRID_W;
			y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.2 * CUI_GRID_H;
			w = 5 * UI_GRID_W;
			h = CUI_GRID_H;
			//onButtonClick = "[_this # 0, 'reload'] execVM ""TER_Editing\gui\scripts\Rsc3DENViewRPT.sqf"";";
		};
		class Open: Reload
		{
			idc = -1;
			text = "Open RPT";
			x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W + 5.2 * CUI_GRID_W;
		};
		class Close: ctrlButtonClose
		{
			x = CUI_GRID_X + DIALOG_W / 2 * CUI_GRID_W - 5.2 * CUI_GRID_W;
			y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.2 * CUI_GRID_H;
			w = 5 * CUI_GRID_W;
			h = CUI_GRID_H;
		};
	};
};

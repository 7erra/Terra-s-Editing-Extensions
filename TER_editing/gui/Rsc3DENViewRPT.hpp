class TER_3DENViewRPT
{
	idd = -1;
	movingEnable = "true";
	onLoad = "[_this # 0, 'onLoad'] call compile preprocessFileLineNumbers 't.sqf'";
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
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50)))";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + (5 * (pixelH * pixelGrid * 	0.50))";
			w = "200 * (pixelW * pixelGrid * 	0.50)";
			h = "106 * (pixelH * pixelGrid * 	0.50)";
		};
		class TitleHeader: ctrlStaticTitle
		{
			text = "Latest RPT";
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50)))";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50))";
			w = "200 * (pixelW * pixelGrid * 	0.50)";
			h = "(5 * (pixelH * pixelGrid * 	0.50))";
		};
	};
	class Controls
	{
		class Group: ctrlControlsGroup
		{
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50)))";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + (5 * (pixelH * pixelGrid * 	0.50))";
			w = "200 * (pixelW * pixelGrid * 	0.50)";
			h = "(106 - 7) * (pixelH * pixelGrid * 	0.50)";
			class Controls
			{
				class Content: ctrlEditMulti
				{
					idc = 100;
					x = 0;
					y = 0;
					w = "40 * (pixelW * pixelGrid * 	0.50)";
					h = "(106 - 7) * (pixelH * pixelGrid * 	0.50)";
					style = "0x200 + 0x10";
					canModify = "false";
				};
			};
		};
		class Lines: ctrlStatic
		{
			text = "Lines:";
			tooltip = "Define the number of lines to be shown. 50 means the last 50 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50))) + (200 - 80) * (pixelW * pixelGrid * 	0.50)";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + 105 * (pixelH * pixelGrid * 	0.50)";
			w = "15 * (pixelW * pixelGrid * 	0.50)";
			h = "(5 * (pixelH * pixelGrid * 	0.50))";
		};
		class EditLines: ctrlEdit
		{
			idc = 200;
			tooltip = "Define the number of lines to be shown. 50 means the last 50 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50))) + (200 - 65) * (pixelW * pixelGrid * 	0.50)";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + 105 * (pixelH * pixelGrid * 	0.50)";
			w = "12 * (pixelW * pixelGrid * 	0.50)";
			h = "(5 * (pixelH * pixelGrid * 	0.50))";
			maxChars = 3;
		};
		class Progress: ctrlProgress
		{
			idc = 300;
			tooltip = "Shows the progress. A full bar indicates that all available lines were loaded.";
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50)))";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + 104 * (pixelH * pixelGrid * 	0.50)";
			w = "200 * (pixelW * pixelGrid * 	0.50)";
			h = "(pixelH * pixelGrid * 	0.50)";
			colorFrame[] = {0,0,0,0};
		};
		class Reload: ctrlButton
		{
			text = "Reload";
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50))) + (174 - 26) * (pixelW * pixelGrid * 	0.50)";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + 105 * (pixelH * pixelGrid * 	0.50)";
			w = "25 * (pixelW * pixelGrid * 	0.50)";
			h = "(5 * (pixelH * pixelGrid * 	0.50))";
			onButtonClick = "[_this # 0, 'reload'] call compile preprocessFileLineNumbers 't.sqf'";
		};
		class Close: ctrlButtonClose
		{
			x = "(	((getResolution select 2) * 0.5 * pixelW) - ((200) / 2 * (pixelW * pixelGrid * 	0.50))) + 174 * (pixelW * pixelGrid * 	0.50)";
			y = "(safezoneY + 16 * (pixelH * pixelGrid * 	0.50)) + 105 * (pixelH * pixelGrid * 	0.50)";
			w = "25 * (pixelW * pixelGrid * 	0.50)";
			h = "(5 * (pixelH * pixelGrid * 	0.50))";
		};
	};
};

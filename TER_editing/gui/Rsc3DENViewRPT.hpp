//Width and height of GUI. Can be used to adjust size efficiently
#define DIALOG_W 35
#define DIALOG_H 20

class TER_3DENViewRPT
{
	idd = -1;
	movingEnable = "true";
	onLoad = "[_this # 0, 'onLoad'] execVM ""TER_Editing\gui\scripts\Rsc3DENViewRPT.sqf"";";
	class ControlsBackground
  {
    class BackgroundDisable: ctrlStaticBackgroundDisable {};
    class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles {};
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
    class Group: ctrlControlsGroup
    {
      x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
      y = CUI_GRID_Y - 13 * CUI_GRID_H;
      w = DIALOG_W * CUI_GRID_W;
      h = DIALOG_H * CUI_GRID_H - CUI_GRID_H - 3/5 * CUI_GRID_H;
      class Controls
      {
        class Content: ctrlEditMulti
        {
          idc = IDC_RPT_CONTENT;
          x = 0;
          y = 0;
          w = DIALOG_W * CUI_GRID_W;
          h = DIALOG_H * CUI_GRID_H - CUI_GRID_H - 3/5 * CUI_GRID_H;
          style = ST_NO_RECT + ST_MULTI;
          canModify = false;
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
      idc = IDC_RPT_LINES;
      tooltip = "Define the number of lines to be shown. 30 means the last 30 lines are shown. Use a small number to speed up the process. Use a very large number to display all lines.";
      x = CUI_GRID_X + DIALOG_W / 2 * CUI_GRID_W - 9 * CUI_GRID_W;
      y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.2 * CUI_GRID_H;
      w = 3 * CUI_GRID_W;
      h = CUI_GRID_H;
      maxChars = 3;
    };
    class Progress: ctrlProgress
    {
      idc = IDC_RPT_PROGRESS;
      tooltip = "Shows the progress. A full bar indicates that all available lines were loaded.";
      x = CUI_GRID_X - DIALOG_W / 2 * CUI_GRID_W;
      y = CUI_GRID_Y + DIALOG_H * CUI_GRID_H - 14.6 * CUI_GRID_H;
      w = DIALOG_W * CUI_GRID_W;
      h = 1/5 * CUI_GRID_H;
      colorFrame[] = {0,1,1,1};
    };
    class Reload: ctrlButton
    {
      text = "Reload";
      x = CENTERED_X(DIALOG_W) + (174 - 26) * GRID_W;
      y = DIALOG_TOP + 105 * UI_GRID_H;
      w = 5 * CUI_GRID_W;
      h = CUI_GRID_H;
      onButtonClick = "[_this # 0, 'reload'] call ENH_fnc_rpt_load";
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

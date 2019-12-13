class TER_3den_RscDisplayNamespaceVars
{
	idd = IDD_DISPLAY_NAMESPACEVARS;
	onLoad = "[""onload"",_this] execVM ""\TER_Editing\gui\scripts\RscNamespaceVars.sqf"";";
	class controlsBackground
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class Background: ctrlStaticBackground
		{
			x = -15.6 * UI_GRID_W + 0.5;
			y = -11 * UI_GRID_H + 0.5;
			w = 31.2 * UI_GRID_W;
			h = 22.7 * UI_GRID_H;
		};
		class Title: ctrlStaticTitle
		{
			text = "Namespace Variables"; //--- ToDo: Localize;
			x = -15.6 * UI_GRID_W + 0.5;
			y = -11.98 * UI_GRID_H + 0.5;
			w = 31.2 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class TxtVarname: ctrlStructuredText
		{
			text = "Variable:"; //--- ToDo: Localize;
			x = -15.5 * UI_GRID_W + 0.5;
			y = 8.3 * UI_GRID_H + 0.5;
			w = 4 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class TxtValue: ctrlStructuredText
		{
			text = "Value:"; //--- ToDo: Localize;
			x = -15.5 * UI_GRID_W + 0.5;
			y = 9.4 * UI_GRID_H + 0.5;
			w = 4 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class TxtValuetype: ctrlStructuredText
		{
			text = "Value type:"; //--- ToDo: Localize;
			x = -15.5 * UI_GRID_W + 0.5;
			y = 10.5 * UI_GRID_H + 0.5;
			w = 4 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class TxtValuetypeIs: ctrlStructuredText
		{
			idc = IDC_NAMESPACE_TXTVALUETYPEIS;
			x = -11.4 * UI_GRID_W + 0.5;
			y = 10.5 * UI_GRID_H + 0.5;
			w = 22.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			colorBackground[] = {0,0,0,0.5};
		};
		class TxtBackVars: ctrlStaticOverlay
		{
			x = -15.5 * UI_GRID_W + 0.5;
			y = -8.7 * UI_GRID_H + 0.5;
			w = 31 * UI_GRID_W;
			h = 16.9 * UI_GRID_H;
		};
	};
	class controls
	{
		class ComboNamespace: ctrlCombo
		{
			idc = IDC_NAMESPACE_COMBONAMESPACE;
			x = -15.5 * UI_GRID_W + 0.5;
			y = -10.9 * UI_GRID_H + 0.5;
			w = 10 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class EdSearch: ctrlEdit
		{
			idc = IDC_NAMESPACE_EDSEARCH;
			x = -5.4 * UI_GRID_W + 0.5;
			y = -10.9 * UI_GRID_H + 0.5;
			w = 20.9 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class BtnSortName: ctrlButtonFilter
		{
			idc = IDC_NAMESPACE_BTNSORTNAME;
			text = "Variable";
			x = -15.5 * UI_GRID_W + 0.5;
			y = -9.8 * UI_GRID_H + 0.5;
			w = 0.4 * 31 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class txtSortValue: ctrlStatic
		{
			idc = IDC_NAMESPACE_BTNSORTVALUE;
			font = "PuristaLight";
			style = ST_CENTER + ST_FRAME + ST_HUD_BACKGROUND;
			text = "VALUE";
			x = -15.5 * UI_GRID_W + 0.5 + 0.4 * 31 * UI_GRID_W;
			y = -9.8 * UI_GRID_H + 0.5;
			w = 0.6 * 31 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		/*
		class LnbVarsHeader: ctrlListNBox
		{
			idc = IDC_NAMESPACE_LNBVARSHEADER;
			x = -15.5 * UI_GRID_W + 0.5;
			y = -9.8 * UI_GRID_H + 0.5;
			w = 31 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		*/
		class LnbVars: ctrlListNBox
		{
			idc = IDC_NAMESPACE_LNBVARS;
			columns[] = {0,0.4};
			x = -15.5 * UI_GRID_W + 0.5;
			y = -8.7 * UI_GRID_H + 0.5;
			w = 31 * UI_GRID_W;
			h = 16.9 * UI_GRID_H;
		};
		class EdVarname: ctrlEdit
		{
			idc = IDC_NAMESPACE_EDVARNAME;
			canModify = false;
			x = -11.4 * UI_GRID_W + 0.5;
			y = 8.3 * UI_GRID_H + 0.5;
			w = 22.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class EdValue: ctrlEdit
		{
			idc = IDC_NAMESPACE_EDVALUE;
			x = -11.4 * UI_GRID_W + 0.5;
			y = 9.4 * UI_GRID_H + 0.5;
			w = 22.5 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class BtnDelete: ctrlButton
		{
			idc = IDC_NAMESPACE_BTNDELETE;
			text = "DELETE"; //--- ToDo: Localize;
			x = 11.2 * UI_GRID_W + 0.5;
			y = 8.3 * UI_GRID_H + 0.5;
			w = 4.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
			colorBackground[] = {0.66,0,0,1};
		};
		class BtnSet: ctrlButton
		{
			idc = IDC_NAMESPACE_BTNSET;
			text = "SET"; //--- ToDo: Localize;
			x = 11.2 * UI_GRID_W + 0.5;
			y = 9.4 * UI_GRID_H + 0.5;
			w = 4.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
		class BtnClose: ctrlButtonClose
		{
			x = 11.2 * UI_GRID_W + 0.5;
			y = 10.5 * UI_GRID_H + 0.5;
			w = 4.3 * UI_GRID_W;
			h = 1 * UI_GRID_H;
		};
	};
};

class TER_3den_RscDisplayKeyCodes
{
	idd = IDD_DISPLAY_KEYCODES;
	ONLOAD(KeyCodes)
	class controlsBackground
	{
		class backDisable: ctrlStaticBackgroundDisable 
		{
		};
		class backDisableTiles: ctrlStaticBackgroundDisableTiles 
		{
		};
		class background: ctrlStaticBackground
		{
			x = -16.1 * CUI_GRID_W + CUI_GRID_X;
			y = -6.1 * CUI_GRID_H + CUI_GRID_Y;
			w = 32.2 * CUI_GRID_W;
			h = 15.3 * CUI_GRID_H;
		};
		class title: ctrlStaticTitle
		{
			text = "Key Code Finder"; //--- ToDo: Localize;
			x = -16.1 * CUI_GRID_W + CUI_GRID_X;
			y = -7.2 * CUI_GRID_H + CUI_GRID_Y;
			w = 32.2 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
		};
		class txt_info: ctrlStructuredText
		{
			text = "Press any key or combination (CTRL, SHIFT, ALT) to get information about the key."; //--- ToDo: Localize;
			x = -16 * CUI_GRID_W + CUI_GRID_X;
			y = -6 * CUI_GRID_H + CUI_GRID_Y;
			w = 32 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
		};
	};
	class controls
	{
		class lnb_keycodesheadline: ctrlListNbox
		{
			idc = IDC_KEYCODES_LISTKEYCODESHEAD;
			enable = 0;
			x = -16 * CUI_GRID_W + CUI_GRID_X;
			y = -4.9 * CUI_GRID_H + CUI_GRID_Y;
			w = 32 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
			columns[] = {0.001, 1/3, 2/3};
		};
		class lnb_keycodes: ctrlListNbox
		{
			idc = IDC_KEYCODES_LISTKEYCODES;
			x = -16 * CUI_GRID_W + CUI_GRID_X;
			y = -3.9 * CUI_GRID_H + CUI_GRID_Y;
			w = 32 * CUI_GRID_W;
			h = 11.9 * CUI_GRID_H;
			columns[] = {0.001, 1/3, 2/3};
		};
		class btn_clear: ctrlButton
		{
			idc = IDC_KEYCODES_BTNCLEAR;
			text = "CLEAR";
			x = -16 * CUI_GRID_W + CUI_GRID_X;
			y = 8.1 * CUI_GRID_H + CUI_GRID_Y;
			w = 6.5 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
		};
		class lnk_dikcodes: ctrlActiveText
		{
			idc = IDC_KEYCODES_LINKBIKI;
			text = "BIKI: DIK KeyCodes";
			url = "https://community.bistudio.com/wiki/DIK_KeyCodes";
			x = -9.4 * CUI_GRID_W + CUI_GRID_X;
			y = 8.1 * CUI_GRID_H + CUI_GRID_Y;
			w = 6.5 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
		};
		class btn_close: ctrlButtonCancel
		{
			text = "Close"; //--- ToDo: Localize;
			x = 9.5 * CUI_GRID_W + CUI_GRID_X;
			y = 8.1 * CUI_GRID_H + CUI_GRID_Y;
			w = 6.5 * CUI_GRID_W;
			h = 1 * CUI_GRID_H;
		};
	};
};

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by Terra, v1.063, #Tebeha)
		////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

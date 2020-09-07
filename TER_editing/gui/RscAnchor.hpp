class TER_3den_RscDisplayAnchor
{
	idd = IDD_DISPLAY_ANCHOR;
	enableSimulation = false;
	onLoad = "[""load"",_this] spawn compile preprocessfilelinenumbers ""TER_Editing\gui\scripts\RscAnchor.sqf"";";
	class controlsBackground
	{
		class background: RscText
		{
			colorBackground[] = {0,0,0,0.8};
			x = safeZoneXAbs;
			y = safeZoneY;
			w = safeZoneWAbs;
			h = safeZoneH;
		};
		class line_v: RscText
		{
			colorBackground[] = {1,0,0,1};
			x = 0.5;
			y = safeZoneY;
			w = pixelW;
			h = safeZoneH;
		};
		class line_h: line_v
		{
			x = safeZoneX;
			y = 0.5;
			w = safeZoneW;
			h = pixelH;
		};
	};
	class controls
	{
		#define W_BTN (4 * UI_GRID_W)
		#define H_BTN (2 * UI_GRID_H)
		class btn_leftTop: RscButtonMenu
		{
			idc = IDC_ANCHOR_LEFTTOP;
			x = safeZoneX;
			y = safeZoneY;
			w = W_BTN;
			h = H_BTN;
		};
		class btn_leftMiddle: btn_leftTop
		{
			idc = IDC_ANCHOR_LEFTMID;
			y = 0.5 - H_BTN/2;
		};
		class btn_leftBottom: btn_leftTop
		{
			idc = IDC_ANCHOR_LEFTBOTTOM;
			y = safeZoneY + safeZoneH - H_BTN;
		};
		class btn_centerTop: btn_leftTop
		{
			idc = IDC_ANCHOR_CENTERTOP;
			x = 0.5 - W_BTN/2;
		};
		class btn_centerMid: btn_centerTop
		{
			idc = IDC_ANCHOR_CENTERMID;
			y = 0.5 - H_BTN/2;
		};
		class btn_centerBottom: btn_centerTop
		{
			idc = IDC_ANCHOR_CENTERBOTTOM;
			y = safeZoneY + safeZoneH - H_BTN;
		};
		class btn_rightTop: btn_leftTop
		{
			idc = IDC_ANCHOR_RIGHTTOP;
			x = safeZoneX + safeZoneW - W_BTN;
		};
		class btn_rightMid: btn_rightTop
		{
			idc = IDC_ANCHOR_RIGHTMID;
			y = 0.5 - H_BTN/2;
		};
		class btn_rightBottom: btn_rightTop
		{
			idc = IDC_ANCHOR_RIGHTBOTTOM;
			y = safeZoneY + safeZoneH - H_BTN;
		};
	};
};
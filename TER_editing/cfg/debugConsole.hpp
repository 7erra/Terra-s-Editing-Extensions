#define ONLOAD_OUTPUT onLoad = "_ctrl = _this select 0;\
	_ctrl = _this select 0;\
	_curPos = ctrlPosition _ctrl;\
	_curPos set [2, 19.5*(((safezoneW / safezoneH) min 1.2) / 40)];\
	_ctrl ctrlSetPosition _curPos;\
	_ctrl ctrlCommit 0;";

class RscDebugConsole
{
	class controls 
	{
		class WatchOutput1
		{
			ONLOAD_OUTPUT
			w="19 * (((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class CB_output1: RscButton
		{
			idc=7301;
			x = 20 * GUI_GRID_W;
			y = 12 * GUI_GRID_H;
			w = 1.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			onLoad = "if (is3DEN) then {(_this select 0) ctrlEnable false;};";
			onButtonClick = "_this call TER_fnc_toggleLive;";
			text = "LIVE";
		};
		class WatchOutput2: WatchOutput1
		{
		};
		class CB_output2: CB_output1
		{
			idc = 7302;
			y = 14 * GUI_GRID_H;
		};
		class WatchOutput3: WatchOutput1
		{
		};
		class CB_output3: CB_output1
		{
			idc = 7303;
			y = 16 * GUI_GRID_H;
		};
		class WatchOutput4: WatchOutput1
		{
		};
		class CB_output4: CB_output1
		{
			idc = 7304;
			y = 18 * GUI_GRID_H;
		};
	};
};

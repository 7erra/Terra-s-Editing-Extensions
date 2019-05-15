class TER_3den_RscLiveWatch
{
	idd = IDD_DISPLAY_LIVEWATCH;
	duration = 1e+6;
	fadeIn = 0;
	fadeOut = 0;
	onLoad = "uiNamespace setVariable [""TER_3den_RscLiveWatch_display"",_this select 0];";
	class controlsBackground
	{
		class background: RscText
		{
			colorBackground[]={0,0,0,0.69999999};
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -10 * GUI_GRID_H + GUI_GRID_Y;
			w = 31 * GUI_GRID_W;
			h = 4 * GUI_GRID_H;
		};
		class frame_input1Live: RscFrame
		{
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -10 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class frame_output1Live: frame_input1Live
		{
			x = 31.7 * GUI_GRID_W + GUI_GRID_X;
		};
		class frame_input2Live: frame_input1Live
		{
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
		};
		class frame_outputLive2: frame_output1Live
		{
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
		};
		class frame_inputLive3: frame_input1Live
		{
			y = -8 * GUI_GRID_H + GUI_GRID_Y;
		};
		class frame_outputLive3: frame_output1Live
		{
			y = -8 * GUI_GRID_H + GUI_GRID_Y;
		};
		class frame_inputLive4: frame_input1Live
		{
			y = -7 * GUI_GRID_H + GUI_GRID_Y;
		};
		class frame_outputLive4: frame_output1Live
		{
			y = -7 * GUI_GRID_H + GUI_GRID_Y;
		};
	};
	class controls
	{
		class inputLive1: RscText
		{
			idc = IDC_LIVE_INPUT1;
			shadow=0;
			font="EtelkaMonospacePro";
			canModify=0;
			forceDrawCaret = false;
			sizeEx = 0.7 * GUI_GRID_H;
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -10 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class outputLive1: inputLive1
		{
			idc = IDC_LIVE_OUTPUT1;
			x = 31.7 * GUI_GRID_W + GUI_GRID_X;
			y = -10 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class inputLive2: inputLive1
		{
			idc = IDC_LIVE_INPUT2;
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class outputLive2: inputLive1
		{
			idc = IDC_LIVE_OUTPUT2;
			x = 31.7 * GUI_GRID_W + GUI_GRID_X;
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class inputLive3: inputLive1
		{
			idc = IDC_LIVE_INPUT3;
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -8 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class outputLive3: inputLive1
		{
			idc = IDC_LIVE_OUTPUT3;
			x = 31.7 * GUI_GRID_W + GUI_GRID_X;
			y = -8 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class inputLive4: inputLive1
		{
			idc = IDC_LIVE_INPUT4;
			x = 16.2 * GUI_GRID_W + GUI_GRID_X;
			y = -7 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
		class outputLive4: inputLive1
		{
			idc = IDC_LIVE_OUTPUT4;
			x = 31.7 * GUI_GRID_W + GUI_GRID_X;
			y = -7 * GUI_GRID_H + GUI_GRID_Y;
			w = 15.5 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
	};
};

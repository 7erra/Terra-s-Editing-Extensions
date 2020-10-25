class RscTitles
{
	class default
	{
		idd = -1;
		fadein = 0;
		fadeout = 0;
		duration = 0;
	};
	class TER_RscDisplayTargetDebug
	{
		idd = 73042;
		fadeIn = 0;
		fadeOut = 0;
		duration = 1e+6;
		onLoad = "uiNamespace setVariable [""TER_3den_RscTargetDebug_display"",_this select 0]";
		class controls
		{
		};
	};
	
	#include "RscLiveWatch.hpp"
	#include "RscGrids.hpp"
	#include "TER_3den_RscDisplayPreviewBackground.hpp"
};
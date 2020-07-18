#ifndef NONMOD
#define FNC_PATH(PATH) __EVAL("TER_Editing\" + PATH)
#else
#define FNC_PATH(PATH) __EVAL("TER_Editing\" + PATH)
#endif
class CfgFunctions
{
	class TER
	{
		class 3den
		{
			file = FNC_PATH("fnc");
			class exportCfg {};
			class findHouseType {};
			class showBuildingPos {};
			class exportMarker {};
			class clearInventory {};
		};
		class GUI
		{
			file = FNC_PATH("gui\scripts");
			// general
			class controlInfo;
			class exportGUIBaseClasses;
		};
		class Debug
		{
			class configViewer73 {file= FNC_PATH("gui\scripts\RscConfigViewer73.sqf");};
			class configToString {file = FNC_PATH("fnc\fn_configToString.sqf");};
		};
		class Numbers
		{
			file = FNC_PATH("fnc");
			class convertNumber {};
		};
		class Python
		{
			file = FNC_PATH("fnc\py");
			class pyTerEden;
		};
	};
	class DREAD
	{
		class config
		{
			class copyConfigClass {file = FNC_PATH("fnc\fn_copyConfigClass.sqf");};
		};
	};
	class MF
	{
		class String
		{
			class replaceInString 
			{
				file = FNC_PATH("fnc\fn_replaceInString.sqf");
			};
		};
	};
};
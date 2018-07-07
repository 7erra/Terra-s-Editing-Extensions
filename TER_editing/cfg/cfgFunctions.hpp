class CfgFunctions
{
	class TER
	{
		class 3den
		{
			file = "TER_editing\fnc";
			class exportCfg {};
			class findHouseType {};
			class showBuildingPos {};
			class toggleLive {};
			class escapeShortcuts {};
		};
		class GUI
		{
			file = "TER_editing\fnc";
			// ezGUI
			class createRscEzGUI {};
			class onLoadEzGUI {};
			class loadChapter {};
			// debug
			class createWatchFields {};
			class onLoadDebug {};
			// stxt Editor
			class onLoadStxtEditor {};
			// color picker
			class onLoadColorPicker {};
			// font picker
			class onLoadFontList {};
		};
		
	};
	class DREAD
	{
		class config
		{
			class copyConfigClass {file = "TER_editing\fnc\fn_copyConfigClass.sqf";};
		};
	};
};
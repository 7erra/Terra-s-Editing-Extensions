class CfgFunctions
{
	class TER
	{
		class 3den
		{
			file = "TER_Editing\fnc";
			class exportCfg {};
			class findHouseType {};
			class showBuildingPos {};
			class escapeShortcuts {};
			class clearInventory {};
		};
		class GUI
		{
			file = "TER_Editing\gui\scripts";
			// general
			class controlInfo {};
			// ezGUI
			class createRscEzGUI {};
			class loadChapter {};
			// debug
			class createWatchFields {};
		};
		
	};
	class DREAD
	{
		class config
		{
			class copyConfigClass {file = "TER_Editing\fnc\fn_copyConfigClass.sqf";};
		};
	};
};
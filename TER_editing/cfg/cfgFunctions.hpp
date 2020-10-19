class CfgFunctions
{
	class TER
	{
		class 3den
		{
			file = "\TER_Editing\fnc";
			class exportCfg {};
			class findHouseType {};
			class showBuildingPos {};
			class exportMarker {};
			class clearInventory {};
		};
		class GUI
		{
			file = "\TER_Editing\gui\scripts";
			// general
			class controlInfo;
		};
		class Debug
		{
			class configViewer73 {file = "\TER_Editing\gui\scripts\RscConfigViewer73.sqf";};
			class configToString {file = "\TER_Editing\fnc\fn_configToString.sqf";};
		};
		class Numbers
		{
			file = "\TER_Editing\fnc";
			class convertNumber {};
		};
		class Python
		{
			file = "\TER_Editing\fnc\py";
			class pyTerEden;
			class loadRPTLine;
			class countRPTLines;
		};
	};
	class DREAD
	{
		class config
		{
			class copyConfigClass {file = "\TER_Editing\fnc\fn_copyConfigClass.sqf";};
		};
	};
};
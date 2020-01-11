#ifdef MOD
#define FNC_PATH "\TER_Editing\fnc"
#else
#define FNC_PATH "fnc\"
#endif
class CfgFunctions
{
	class TER
	{
		class 3den
		{
			file = FNC_PATH;
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
			class controlInfo {};
		};
		class Numbers
		{
			file = FNC_PATH;
			class convertNumber {};
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
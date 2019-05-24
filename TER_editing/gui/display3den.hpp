class Display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class Tools
				{
					items[] += {"TER_3den_folder"}; // += must be used; you want to expand the array, not override it!
				};
				class TER_3den_folder
				{
					text = "7'3 Editing";
					picture = "";
					items[] = {
						"TER_3den_stxtEditor",
						"TER_3den_colorPicker",
						"TER_3den_fontPicker",
						"TER_3den_attachToFinder",
						"TER_3den_dikCodes",
						"TER_3den_ctrlExplained"
					};
				};
				#define STR(ARG) #ARG
				#define ACT_DISPLAY(DISPLAY) action = STR((findDisplay 313) createDisplay STR(STR(TER_3den_Rsc##DISPLAY)))
				class TER_3den_stxtEditor
				{
					text = "Structured Text Editor";
					picture = "";
					ACT_DISPLAY(StxtEditor);
				};
				class TER_3den_colorPicker: TER_3den_stxtEditor
				{
					text = "Color Picker";
					ACT_DISPLAY(ColorPicker);
				};
				class TER_3den_fontPicker: TER_3den_colorPicker
				{
					text = "Font Picker";
					ACT_DISPLAY(FontList);
				};
				class TER_3den_attachToFinder
				{
					text = "attachTo Finder";
					picture = "TER_editing\icons\attachTo.paa";
					action = "(findDisplay 313) ctrlCreate [""TER_3den_RscAttachToFinder"",73100];";
				};
				class TER_3den_dikCodes
				{
					text = "Key Codes";
					ACT_DISPLAY(DisplayKeyCodes);
				};
				class TER_3den_ctrlExplained
				{
					text = "Control Types";
					ACT_DISPLAY(DisplayCtrlsExplained);
				};
			};
		};
	};
	class ContextMenu: ctrlMenu
	{
	    class Items
	    {
			class Log//The easiest way to add an entry is to use one of the already available folders, here we use the class '''Log''' '''(Level 1)'''
			{
				items[] +=//Here we list all items we want to add to the '''Log''' class. 
				{
					"TER_showTypes",
					"TER_buildingPos",
					"TER_exportMarker",
					"TER_clearInventory"
				};
			};
			class TER_showTypes//Now we need to define the entry itself which will be inside the '''Log''' folder '''(Level 2)'''
			{
				text = "Find Object Type on Map";//Name of the entry, ideally localised
				action = "call TER_fnc_findHouseType;";//The code which is executed when the entry was selected
				conditionShow = "selectedObject";//The Condition, see below
			};
			class TER_buildingPos
			{
				text = "Show Building Positions";
				action = "call TER_fnc_showBuildingPos;";
				conditionShow = "hoverObject";
			};
			class TER_exportMarker
			{
				text = "Export Marker As String";
				action = "call TER_fnc_exportMarker";
				conditionShow = "selectedMarker";
			};
			class TER_clearInventory
			{
				text = "Clear Inventory";
				action = "call TER_fnc_clearInventory";
				conditionShow = "hoverObjectBrain";
			};
		};
	};
};
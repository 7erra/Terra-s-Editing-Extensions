class Display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class DebugConsole
				{
					shortcuts[] = {"512+0x20"};
				};
				class Tools
				{
					items[] += {"TER_3den_folder"}; // += must be used; you want to expand the array, not override it!
				};
				class TER_3den_folder
				{
					text = "7'3 Editing";
					picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[] = {
						"TER_3den_ConfigViewer73",
						"TER_3den_stxtEditor",
						"TER_3den_colorPicker",
						"TER_3den_fontPicker",
						"TER_3den_attachToFinder",
						"TER_3den_dikCodes",
						"TER_3den_namespaceVars",
						"TER_3den_ctrlExplained"
					};
				};
				#define STR(ARG) #ARG
				#define ACT_DISPLAY(DISPLAY) action = STR((findDisplay 313) createDisplay STR(STR(TER_3den_Rsc##DISPLAY)))
				class TER_3den_ConfigViewer73
				{
					text = "Config Viewer 73";
					picture = "";
					ACT_DISPLAY(DisplayConfigViewer73);
					opensNewWindow = 1;
					shortcuts[] = {"1024+0x2E"}; // Left Shift + C
				};
				class TER_3den_stxtEditor
				{
					text = "Structured Text Editor";
					picture = "";
					ACT_DISPLAY(StxtEditor);
					opensNewWindow = 1;
				};
				class TER_3den_colorPicker: TER_3den_stxtEditor
				{
					text = "Color Picker";
					ACT_DISPLAY(ColorPicker);
					opensNewWindow = 1;
				};
				class TER_3den_fontPicker: TER_3den_colorPicker
				{
					text = "Font Picker";
					ACT_DISPLAY(FontList);
					opensNewWindow = 1;
				};
				class TER_3den_attachToFinder
				{
					text = "attachTo Finder";
					picture = "TER_editing\icons\attachTo.paa";
					action = "(findDisplay 313) ctrlCreate [""TER_3den_RscAttachToFinder"",73100];";
					opensNewWindow = 1;
				};
				class TER_3den_dikCodes
				{
					text = "Key Codes";
					ACT_DISPLAY(DisplayKeyCodes);
					opensNewWindow = 1;
				};
				class TER_3den_namespaceVars
				{
					text = "Namespace Variables";
					ACT_DISPLAY(DisplayNamespaceVars);
					opensNewWindow = 1;
				};
				class TER_3den_ctrlExplained
				{
					text = "Control Types";
					ACT_DISPLAY(DisplayCtrlsExplained);
					opensNewWindow = 1;
				};
			};
		};
	};
	class ContextMenu: ctrlMenu
	{
	    class Items
	    {
			class Edit
			{
				items[] +=
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
			//--- Overwrite old config viewer context menu entry
			class FindConfig
			{
				text="$STR_3DEN_Display3DEN_EntityMenu_FindConfig_text";
				data="FindConfig";
				value=0;
				conditionShow="hoverObject 	+ hoverWaypoint 	+ hoverLogic 	+ hoverMarker";
				action="['findconfig'] call TER_fnc_configViewer73;";
				picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findConfig_ca.paa";
				opensNewWindow=1;
			};
		};
	};
};

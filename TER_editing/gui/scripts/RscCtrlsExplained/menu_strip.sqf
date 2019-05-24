[
//--- Examples
[
	[ // Example 1
		"TER_3den_ctrlMenuStripExample",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			{
				_path = _this menuAdd [[], _x];
				{
					_subPath = _this menuAdd [[_path], _x];
					{
						_this menuAdd [[_path,_subPath], _x];
					} forEach ["SubSubItem 0","SubSubItem 1","SubSubItem 2","SubSubItem 3","SubSubItem 4"];
				} forEach ["SubItem 0","SubItem 1","SubItem 2","SubItem 3","SubItem 4"];
			} forEach ["Item 0","Item 1","Item 2","Item 3","Item 4"];


		}
	]
],
//--- Description
"The top bar of the 3den Editor. Contrary to the other menu controls it is reproducable. The ""onMenuSelected"" EH doesn't seem to fire though.",
//--- EH
["MenuSelected"],
//--- Commands
["menuEnable","menuExpand","menuCollapse","menuSetData","menuSetValue","‎menuSetCheck","menuSetAction","menuDelete","‎menuHover","menuValue","menuURL","‎menuText","menuSort","‎menuSize","menuEnabled","‎menuChecked","menuAction","menuShortcutText","menuShortcut","menuPicture","menuData","menuClear","menuSetPicture"],
//--- Common base classes
["<t color='#FF5555'>ctrlMenuStrip</t>"]
]
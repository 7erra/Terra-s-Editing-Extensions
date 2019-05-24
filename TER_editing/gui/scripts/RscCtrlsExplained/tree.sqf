[
//--- Examples
[
	[ // Example 1
		"RscTree",// Class
		[nil,5], // Width, height
		{
			_this tvAdd [ [],"Parent_A"];
			_this tvAdd [ [0],"Child_A"];
			_this tvAdd [ [0,0],"Grandchild_A"];
			_this tvAdd [ [],"Parent_B"];
			_this tvAdd [ [1],"Child_B"];
		} // Commands to execute upon creation
	]/*,
	[ // Example 2
		"RscActivePicture",// Class
		[5,5], // Width, height
		{
			_this ctrlSetText "\a3\ui_f\data\logos\arma3_expansion_ca.paa";
		} // Commands to execute upon creation
	]
*/
],
//--- Description
"Similar to the CT_LISTBOX this control shows a list of items. It can be organized in different ""branches"" or children and parents. When combined with a CT_EDIT it can also serve as a browser with search capabilities. To connect an edit field you have to set the idcSearch attribute to the idc of the edit.",
//--- EH
["onTreeSelChanged","onTreeLButtonDown","onTreeDblClick","onTreeExpanded","onTreeCollapsed","onTreeMouseMove","onTreeMouseHold","onTreeMouseExit"],
//--- Commands
["tvClear","tvCollapse","tvCount","tvCurSel","tvData","tvDelete","tvExpand","tvPicture","tvSetCurSel","tvSetData","tvSetValue","tvSort","tvSortByValue","tvValue","tvText","tvSetText","tvSetPicture","tvSetPictueColor","tvSetPictureRight","tvSetPictureRightColor"],
//--- Common base classes
["<t color='#FF5555'>RscTree</t>","RscTreeSearch","ctrlTree"]
]
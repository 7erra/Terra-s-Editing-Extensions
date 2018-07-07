#define	GUI_DISPLAY_DEFAULT	(uinamespace getvariable "BIS_RscGUIEditor")
#define	GUI_DISPLAY		(uinamespace getvariable "BIS_RscGUIEditor_main")
#define GUI_CONTROL		(GUI_DISPLAY displayctrl _idc)

GUI_version = 1.063;
//startloadingscreen [""];

//--- Dialog
createdialog "RscGUIEditor";
waituntil {!isnil {GUI_DISPLAY_DEFAULT}};
uinamespace setvariable ["BIS_RscGUIEditor_main",GUI_DISPLAY_DEFAULT];
uinamespace setvariable ["BIS_RscGUIEditor_tool",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_elementEdit",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_elementEditCustom",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_elementsList",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_elementAdd",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_gridAdd",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_importConfig",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_help",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_exit",displaynull];
uinamespace setvariable ["BIS_RscGUIEditor_title",displaynull];

//--- Functions
GUI_path = gettext (configfile >> "RscGUIEditor" >> "path_BIS");
GUI_fnc_compile = {
	GUI_fnc_getIDC = {getnumber (configfile >> "RscGUIEditor" >> "controls" >> _this >> "idc")};
	GUI_fnc_reset = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_reset.sqf");
	GUI_fnc_export = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_export.sqf");
	GUI_fnc_exportMenu = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_exportMenu.sqf");
	GUI_fnc_exportDefine = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_exportDefine.sqf");
	GUI_fnc_exportParents = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_exportParents.sqf");
	GUI_fnc_exportStringtable = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_exportStringtable.sqf");
	GUI_fnc_import = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_import.sqf");
	GUI_fnc_undo = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_undo.sqf");
	GUI_fnc_elementSet = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementSet.sqf");
	GUI_fnc_elementRemove = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementRemove.sqf");
	GUI_fnc_elementAdd = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementAdd.sqf");
	GUI_fnc_elementEdit = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementEdit.sqf");
	GUI_fnc_elementEditCustom = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementEditCustom.sqf");
	GUI_fnc_elementsList = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_elementsList.sqf");
	GUI_fnc_gridSet = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_gridSet.sqf");
	GUI_fnc_gridAdd = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_gridAdd.sqf");
	GUI_fnc_displayKey = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_displayKey.sqf");
	GUI_fnc_displayMouseButton = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_displayMouseButton.sqf");
	GUI_fnc_ctrlMouseMoving = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_ctrlMouseMoving.sqf");
	GUI_fnc_convertPosition = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_convertPosition.sqf");
	GUI_fnc_help = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_help.sqf");
	GUI_fnc_returnConfig = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_returnConfig.sqf");
	GUI_fnc_stringSplit = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_stringSplit.sqf");
	GUI_fnc_importConfig = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_importConfig.sqf");
	GUI_fnc_exit = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_exit.sqf");
	GUI_fnc_title = compile preprocessfilelinenumbers (GUI_path + "GUI_fnc_title.sqf");
};
call GUI_fnc_compile;

//--- Init params
call  compile preprocessfilelinenumbers (GUI_path + "GUI_initParams.sqf");

GUI_fnc_elementIndex = {
	GUI_listElements find _this;
};
GUI_fnc_elementData = {
	private ["_idcIndex"];
	_idcIndex = _this call GUI_fnc_elementIndex;
	if (_idcIndex >= 0) then {GUI_listElementsData select _idcIndex} else {[]};
};
GUI_fnc_elementDataCustom = {
	private ["_idcIndex"];
	_idcIndex = _this call GUI_fnc_elementIndex;
	if (_idcIndex >= 0) then {GUI_listElementsDataCustom select _idcIndex} else {[]};
};
GUI_fnc_elementClass = {
	private ["_idcIndex"];
	_idcIndex = _this call GUI_fnc_elementIndex;
	if (_idcIndex >= 0) then {GUI_listElementsClass select _idcIndex} else {""};
};
GUI_fnc_elementClassFiltered = {
	private ["_idcClassArray","_idcClass","_allowedChars"];
	_idcClassArray = toArray _this;
	_idcClass = "";
	_allowedChars = toarray "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";
	{
		if !(_x in _allowedChars) exitwith {};
		_idcClass = _idcClass + tostring [_x];
	} foreach _idcClassArray;
	_idcClass
};
GUI_fnc_elementLayer = {
	private ["_result"];
	_result = -1;
	{
		_min = _x;
		_max = _x + 99;
		if (_this >= _min && _this <= _max) exitwith {_result = _x};
	} foreach GUI_listLayers;
	_result
};
GUI_fnc_elementParent = {
	private ["_layerIndex"];
	_layerIndex = GUI_listLayers find (_this call GUI_fnc_elementLayer);
	if (_layerIndex >= 0) then {GUI_listLayersParents select _layerIndex} else {"ERROR_MISSING_LAYER"};
};
GUI_fnc_elementType = {
	GUI_listLayersTypes select _this
};
GUI_fnc_elementString = {
	GUI_listLayersStrings select _this
};

#define GUI_FNC_DEFAULT 	private ["_idc","_idcIndex","_input","_idcData","_idcType"]; \
				_idc = _this select 0; \
				_input = _this select 1; \
				_idcData = _idc call GUI_fnc_elementData; \
				_idcType = _idParam call GUI_fnc_elementType; \
				if (isnil "_input") exitwith {debuglog format ["Log: ERROR: Nil value %1",_idParam]}; \
				if (typename _input != _idcType) exitwith {debuglog format ["Log: ERROR: %1 type %2, must be %3",_input,typename _input,_idcType]}; \
				_idcData set [_idParam,_input];

#define GUI_FNC_ARRAY 		if (typename _input == typename []) then { \
					_input = +_input; \
					{ \
						if (typename _x == typename "") then {_input set [_forEachIndex,call compile _x];}; \
					} foreach _input; \
					if ((_input select 3) < 0) then { \
						private ["_inputDefault"]; \
						_inputDefault = getArray (configfile >> (_idc call GUI_fnc_elementParent) >> ((_idParam call GUI_fnc_elementString) select 0)); \
						_input = if (count _inputDefault > 0) then { \
							{ \
								_inputDefault set [_forEachIndex,_x call bis_fnc_parsenumber]; \
							} foreach _inputDefault; \
							_inputDefault \
						} else { \
							[1,1,1,1] \
						}; \
					}; \
				};
GUI_fnc_elementSetClass = {
	private ["_idc","_idcClass","_idcIndex"];
	_idc = _this select 0;
	_idcClass = _this select 1;
	_idcIndex = _idc call GUI_fnc_elementIndex;
	GUI_listElementsClass set [_idcIndex,_idcClass];
};
GUI_fnc_elementSetIDC = {
	_idParam = GUI_param_idc;
	GUI_FNC_DEFAULT
};
GUI_fnc_elementSetText = {
	private ["_inputArray"];
	_idParam = GUI_param_text;
	GUI_FNC_DEFAULT
	_idcLayer = _idc call GUI_fnc_elementLayer;
	if (_input == "" && _idcLayer in [GUI_layer_ButtonMenuOK,GUI_layer_ButtonMenuCancel]) then {
		if (_idcLayer == GUI_layer_ButtonMenuOK) then {_input = "$STR_DISP_OK";};
		if (_idcLayer == GUI_layer_ButtonMenuCancel) then {_input = "$STR_DISP_CANCEL";};
	};
	_inputArray = toarray _input;

	//--- If the text is localized, replace it by its loc key
	if !(isnil {_enableAutoLocalize}) then {
		_idcClass = _idc call GUI_fnc_elementClass;
		_locKey = "STR_A3_" + GUI_title + "_" + _idcClass;
		if (islocalized _locKey) then {
			_input = localize _locKey;
			_idcData set [_idParam,"$" + _locKey];
		};
	};

	if ((_inputArray select 0) == (toarray "$" select 0)) then {
		_inputArray set [0,-1];
		_inputArray = _inputArray - [-1];
		_input = localize tostring _inputArray;
	};
	if ((_idc call GUI_fnc_elementLayer) == GUI_layer_structuredtext) then {
		GUI_CONTROL ctrlsetstructuredtext parsetext _input;
	} else {
		GUI_CONTROL ctrlsettext _input;
	};
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetPosition = {
	_idParam = GUI_param_position;
	GUI_FNC_DEFAULT
	_input = _idc call GUI_fnc_convertPosition;
	_idcData set [_idParam,_input];
	_input = _idcData select GUI_param_position;
	GUI_FNC_ARRAY

	//--- Child of Controls group
	_positionType = _idcData select GUI_param_positionType;
	if (_positionType > 2) then {
		private ["_grpIdcData"];
		_grpIdcData = _positionType call GUI_fnc_elementData;

		//--- Control group not yet defined during inital import - will be positioned when control group is loaded
		if (count _grpIdcData >= GUI_param_position) then {
			_grpPos = +(_grpIdcData select GUI_param_position);
			{
				_grpPos set [_foreachindex,_x call bis_fnc_parsenumber];
			} foreach _grpPos;
			_input set [0,(_input select 0) + (_grpPos select 0)];
			_input set [1,(_input select 1) + (_grpPos select 1)];
			if (isnil "_childIdcData") then {[_positionType] call GUI_fnc_displayAll};
		};
	};

	//--- Controls group - move children
	if ((_idc call GUI_fnc_elementLayer) == (GUI_layer_controlsgroup)) then {
		_disableGroupAdjust = true; //--- Disable counter adjusting
		{
			_childIdcData = _x call GUI_fnc_elementData;
			if ((_childIdcData select GUI_param_positionType) == _idc) then {
				[_x,_childIdcData select GUI_param_position] call GUI_fnc_elementSetPosition;
			};
		} foreach GUI_listElements;
	};
	GUI_CONTROL ctrlsetposition _input;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetTextColor = {
	_idParam = GUI_param_textColor;
	GUI_FNC_DEFAULT
	GUI_FNC_ARRAY
	GUI_CONTROL ctrlsettextcolor _input;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetBackgroundColor = {
	_idParam = GUI_param_backgroundColor;
	GUI_FNC_DEFAULT
	GUI_FNC_ARRAY
	GUI_CONTROL ctrlsetbackgroundcolor _input;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetActiveColor = {
	_idParam = GUI_param_activeColor;
	GUI_FNC_DEFAULT
	GUI_FNC_ARRAY
	GUI_CONTROL ctrlsetactivecolor _input;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetTooltip = {
	_idParam = GUI_param_tooltip;
	GUI_FNC_DEFAULT
	GUI_FNC_ARRAY
	GUI_CONTROL ctrlsettooltip _input;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_elementSetPositionType = {
	_idParam = GUI_param_positionType;
	GUI_FNC_DEFAULT
};
GUI_fnc_elementSetSizeEx = {
	_idParam = GUI_param_sizeEx;
	GUI_FNC_DEFAULT
	_inputNumber = call compile (_input);
	if (_inputNumber < 0) then {
		_inputNumber = getNumber (configfile >> (_idc call GUI_fnc_elementParent) >> "sizeEx");
	} else {
		_gridH = gui_grid select 2;
		if (typename _gridH == typename "") then {_gridH = call compile _gridH;};
		_inputNumber = _inputNumber * _gridH;
	};
	GUI_CONTROL ctrlsetfontheight _inputNumber;
};
GUI_fnc_elementSetDataCustom = {
	private ["_idc","_dataId","_data","_idcDataCustom","_idcIndex"];
	_idc = _this select 0;
	_data = _this select 1;
	if (count _this > 2) then {

		//--- Array element setting
		_dataId = _this select 2;
		_idcDataCustom = _idc call GUI_fnc_elementDataCustom;
		if (_dataId > count _idcDataCustom) then {_dataId = count _idcDataCustom;};

		//--- Remove export strings (cannot be saved)
		_dataArray = toArray _data;
		//_dataArray = _dataArray - toarray """'";
		{
			_letterExport = _x select 1;
			_dataArray = _dataArray - [_letterExport];
		} foreach GUI_listExportReplace;
		_data = tostring _dataArray;

		//--- Save
		_idcDataCustom set [_dataId,_data];
		[_idc,_idcDataCustom - [""]] call GUI_fnc_elementSetDataCustom;
	} else {

		//--- Array setting
		_idcIndex = _idc call GUI_fnc_elementIndex;
		GUI_listElementsDataCustom set [_idcIndex,_data];
	};
};

GUI_fnc_elementDefault = {
	private ["_idcParent","_parent","_positionType","_text","_position","_colorText","_colorBackground","_colorBackgroundActive","_tooltip","_idcData"];

	_idcParent = _this call GUI_fnc_elementParent;
	_parent = configfile >> _idcParent;
	_idcData = [];

	{
		_idcData = _idcData + [call _x];
	} foreach GUI_listLayersDefaults;

	_idcData
};

GUI_fnc_gridShow = {
	private ["_idc","_show"];
	_show = [1,0] select _this;
	for "_idc" from GUI_layer_grid to (GUI_layer_grid + 99) do {
		GUI_CONTROL ctrlsetfade _show;
		GUI_CONTROL ctrlcommit 0;
	};
	_idc = GUI_layer_tool_defaultSize;
	GUI_CONTROL ctrlsetfade _show;
	GUI_CONTROL ctrlcommit 0;
};
GUI_fnc_gridVisible = {
	private ["_idc"];
	_idc = GUI_layer_grid;
	ctrlfade GUI_CONTROL == 0
};

GUI_fnc_displayAll = {
	_listHighlight = if (count _this == 0) then {GUI_listElements} else {_this};
	{
		private ["_idc","_idcData","_input"];
		_idc = _x;
		_idcData = _idc call GUI_fnc_elementData;
		_input = _idcData select GUI_param_position;

		GUI_FNC_ARRAY

		//--- Exception: Controls group
		_positionType = _idcData select GUI_param_positionType;
		if (_positionType > 2) then {
			private ["_grpIdcData","_grpPos"];
			_grpIdcData = _positionType call GUI_fnc_elementData;
			_grpPos = +(_grpIdcData select GUI_param_position);
			{
				_grpPos set [_foreachindex,_x call bis_fnc_parsenumber];
			} foreach _grpPos;
			_input set [0,(_input select 0) + (_grpPos select 0)];
			_input set [1,(_input select 1) + (_grpPos select 1)];
		};

		_color = if (_idc in GUI_listElementsLocked) then {[0,1,1,0.5]} else {[1,0,1,0.7]};
		if (_forEachIndex < 50) then {
			_idc = GUI_layer_tool_selection + 1 + _forEachIndex;
			GUI_CONTROL ctrlsetposition _input;
			GUI_CONTROL ctrlsetbackgroundcolor _color;
			GUI_CONTROL ctrlsetfade 0;
			GUI_CONTROL ctrlcommit 0;
			GUI_CONTROL ctrlsetfade 1;
			GUI_CONTROL ctrlcommit 0.5;
		};
	} foreach _listHighlight;
};

//--- Variables
GUI_title = "";
GUI_export_format = 0;
GUI_export_indent = 0;
GUI_export_idc = 0;
GUI_export_localize = 0;
GUI_exportHash = "";
GUI_listElements = [];
GUI_listElementsClass = [];
GUI_listElementsData = [];
GUI_listElementsDataCustom = [];
GUI_listElementsLocked = [];
GUI_listKeys = [];
GUI_listHistory = [];
GUI_listHistoryIndex = -1;
GUI_listCopy = [];
GUI_keyCtrl = 29;
GUI_keyAlt = 56;
GUI_keyShift = 42;
GUI_LMB = false;
GUI_RMB = false;
GUI_LMB_pos = [0,0];
GUI_RMB_pos = [0,0];
GUI_mousePos = [0,0];
GUI_idcActive = -1;
GUI_positionType = 2;
GUI_importConfig = "configfile";
GUI_listExportReplace = [
	[toarray """" select 0,toarray "|" select 0],
	[toarray "'" select 0,toarray "^" select 0],
	[toarray "*" select 0,toarray "~" select 0]
];

GUI_layer_tool_mouseArea =	"MouseArea" call GUI_fnc_getIDC;
GUI_layer_tool =		"Tool_0" call GUI_fnc_getIDC;
GUI_layer_tool_background =		GUI_layer_tool + 0;
GUI_layer_tool_defaultSize =		GUI_layer_tool + 1;
GUI_layer_tool_mousepos =		GUI_layer_tool + 2;
GUI_layer_tool_selection =		GUI_layer_tool + 3; //--- Has to stay last
GUI_layer_grid =		"Grid_0" call GUI_fnc_getIDC;
GUI_layer_text =		"Text_0" call GUI_fnc_getIDC;
GUI_layer_structuredtext =	"StructuredText_0" call GUI_fnc_getIDC;
GUI_layer_picturenoshadow =	"Picture_0" call GUI_fnc_getIDC;
GUI_layer_pictureshadow =	"PictureShadow_0" call GUI_fnc_getIDC;
GUI_layer_edit =		"Edit_0" call GUI_fnc_getIDC;
GUI_layer_listbox =		"Listbox_0" call GUI_fnc_getIDC;
GUI_layer_combo =		"Combo_0" call GUI_fnc_getIDC;
GUI_layer_button =		"Button_0" call GUI_fnc_getIDC;
GUI_layer_shortcutButton =	"ShortcutButton_0" call GUI_fnc_getIDC;
GUI_layer_buttonmenumain =	"ShortcutButtonMain_0" call GUI_fnc_getIDC;
GUI_layer_frame =		"Frame_0" call GUI_fnc_getIDC;
GUI_layer_slider =		"Slider_0" call GUI_fnc_getIDC;
GUI_layer_iguiback =		"IGUIBack_0" call GUI_fnc_getIDC;
GUI_layer_controlsgroup =	"ControlsGroup_0" call GUI_fnc_getIDC;
GUI_layer_CheckBox =		"CheckBox_0" call GUI_fnc_getIDC;
GUI_layer_TextCheckBox =	"TextCheckBox_0" call GUI_fnc_getIDC;
GUI_layer_ButtonMenu =		"ButtonMenu_0" call GUI_fnc_getIDC;
GUI_layer_ButtonMenuOK =	"ButtonMenuOK_0" call GUI_fnc_getIDC;
GUI_layer_ButtonMenuCancel =	"ButtonMenuCancel_0" call GUI_fnc_getIDC;
GUI_layer_comment =		0;


GUI_listLayers = [
	GUI_layer_text,
	GUI_layer_structuredtext,
	GUI_layer_picturenoshadow,
	//GUI_layer_pictureshadow,
	GUI_layer_edit,
	GUI_layer_combo,
	GUI_layer_listbox,
	GUI_layer_button,
	GUI_layer_shortcutButton,
	GUI_layer_buttonmenumain,
	GUI_layer_frame,
	GUI_layer_slider,
	GUI_layer_iguiback,
	GUI_layer_CheckBox,
	GUI_layer_TextCheckBox,
	GUI_layer_ButtonMenu,
	GUI_layer_ButtonMenuOK,
	GUI_layer_ButtonMenuCancel,
	GUI_layer_controlsgroup,
	GUI_layer_comment
];
GUI_listLayersParents = [
	"RscText",
	"RscStructuredText",
	"RscPicture",
	"RscEdit",
	"RscCombo",
	"RscListbox",
	"RscButton",
	"RscShortcutButton",
	"RscShortcutButtonMain",
	"RscFrame",
	"RscSlider",
	"IGUIBack",
	"RscCheckbox",
	"RscTextCheckbox",
	"RscButtonMenu",
	"RscButtonMenuOK",
	"RscButtonMenuCancel",
	"RscControlsGroup",
	"<Comment>"
];

GUI_window_sizeFull = [safezoneX,safezoneY,safezoneW,safezoneH];
GUI_window_colorBackground = [0,0,0,0.6];
GUI_window_sizeText = 0.04;
GUI_window_borderX = 0.02;
GUI_window_borderY = GUI_window_borderX * 4/3;
GUI_window_elementAdd_curSel = 0;
GUI_window_elementsList_curSel = 0;

GUI_selection_thicknessX = 0.005;
GUI_selection_thicknessY = GUI_selection_thicknessX * 4/3;

//--- Event handlers
//GUI_DISPLAY displayaddeventhandler ["unload","endmission 'end1';"];
GUI_DISPLAY displayaddeventhandler ["keydown","[1,_this] call GUI_fnc_displayKey;"];
GUI_DISPLAY displayaddeventhandler ["keyup","[0,_this] call GUI_fnc_displayKey;"];
GUI_DISPLAY displayaddeventhandler ["mousebuttondown","[1,_this] call GUI_fnc_displayMouseButton;"];
GUI_DISPLAY displayaddeventhandler ["mousebuttonup","[0,_this] call GUI_fnc_displayMouseButton;"];

//--- Mouse area
_idc = GUI_layer_tool_mouseArea;
GUI_CONTROL ctrlsetbackgroundcolor [0,0,0,0];
GUI_CONTROL ctrlsetposition GUI_window_sizeFull;
GUI_CONTROL ctrlcommit 0;
GUI_CONTROL ctrladdeventhandler ["mousemoving","_this call GUI_fnc_ctrlMouseMoving;"];

//--- Grey background
_idc = GUI_layer_tool_background;
GUI_CONTROL ctrlsetposition [safezoneXAbs,safezoneY,safezoneWAbs,safezoneH];
GUI_CONTROL ctrlsetbackgroundcolor [0.5,0.5,0.5,1];
GUI_CONTROL ctrlsetfade 1;
GUI_CONTROL ctrlcommit 0;

//--- Center background
_idc = GUI_layer_tool_defaultSize;
GUI_CONTROL ctrlsetbackgroundcolor [1,1,1,0.3];
GUI_CONTROL ctrlsetposition [0,0,1,1];
GUI_CONTROL ctrlcommit 0;

//--- Selection
_idc = GUI_layer_tool_selection;
GUI_CONTROL ctrlsetbackgroundcolor [0,0,0,0.5];
GUI_CONTROL ctrlsetposition [0,0,0,0];
GUI_CONTROL ctrlcommit 0;

//--- Set grid
(uiNamespace getVariable ["TER_3den_GUIGrid",[]]) call GUI_fnc_gridSet;

//--- Reset
call GUI_fnc_reset;

//--- Test
[0] call GUI_fnc_import;
[1] call GUI_fnc_export;

//--- Remove overlays
cuttext ["","plain"];
titletext ["","plain"];
clearradio;
enableradio false;

//endloadingscreen;
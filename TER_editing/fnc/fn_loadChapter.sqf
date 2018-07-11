// general defines
#include "ctrls.inc"
#define TFNC_NEW call _fncNewControl;
#define TFNC_TIP(TIP_TXT)  _curBtnEH = {\
		params ["_ctrl"];\
		CHAPTER_DISPLAY createDisplay "RscTER_3den_ezGUITip";\
		TITLE_TIP ctrlSettext (ctrlText _ctrl);\
		STXT_TIPTEXT ctrlSetStructuredText parseText TIP_TXT;\
	};\
	"RscButton" TFNC_NEW

disableSerialization;
_chapter = uiNamespace getVariable ["TER_3den_chapter",0];
(ctrlPosition GRP_CHAPTER) params ["_grpX","_grpY","_grpW","_grpH"];

_fncTotalHeight = {
	private _grpControls = CHAPTER_CONTROLS;
	private _sum = 0;
	private _ctrlPos = _grpControls apply {1.05*((ctrlPosition _x) select 3)};
	_ctrlPos = _ctrlPos apply {_sum	= _sum +_x};
	_sum
};

_PX_fnc_splitReplace = {
    params["_str", "_find", "_replace"];
    private _result = ([" "+_str+" ", _find, true] call BIS_fnc_splitString) joinString _replace;
    _result select [1, (count _result)-2];
};

_fncRemoveClutter = {
    _curTxt = ([" "+_curTxt+" ", toString [9], true] call BIS_fnc_splitString) joinString "";
	_curTxt select [1, (count _curTxt)-2];
    _curTxt = ([" "+_curTxt+" ", toString [10], true] call BIS_fnc_splitString) joinString "<br/>";
	_curTxt select [1, (count _curTxt)-2];
};
// Param: _this: ["RscControlType1","=2","=3",...]
// return: new controls
_fncNewControl = {
	_type = param [0,"RscStructuredText"];
	_typeSpecial = param [1,_type];
	// new control
	_ctrlNew = CHAPTER_DISPLAY ctrlCreate [_type,-1,GRP_CHAPTER];
	_ctrlNewPos = [0.025, call _fncTotalHeight, 0.95*_grpW, GUI_GRID_H];
	_ctrlNew ctrlSetPosition _ctrlNewPos;
	_ctrlNew ctrlCommit 0;
	switch _typeSpecial do {
		case "RscStructuredText": {
			call _fncRemoveClutter;
			_ctrlNew ctrlSetStructuredText parseText _curTxt;
			_posAdjusted = ctrlPosition _ctrlNew;
			_posAdjusted set [3,ctrlTextHeight _ctrlNew];
			_ctrlNew ctrlSetPosition _posAdjusted;
			_ctrlNew ctrlCommit 0;
		};
		case "RscButtonMenu":{
			_ctrlNew ctrlSetText _curTxt;
			_ctrlNew ctrlAddEventHandler ["ButtonClick",_curBtnEH];
		};
		case "RscButton":{
			_ctrlNew ctrlSetText _curTxt;
			_ctrlNew ctrlAddEventHandler ["ButtonClick",_curBtnEH];
		};
		case "TER_3den_RscEditMulti":{
			_curTxt = [_curTxt,toString [9],""] call _PX_fnc_splitReplace;
			_ctrlNew ctrlSetText _curTxt;
			_ctrlNewPos set [3,1.05*(ctrlTextHeight _ctrlNew)];
			_ctrlNew ctrlSetPosition _ctrlNewPos;
			_ctrlNew ctrlCommit 0;
		};
		case "RscCopy": {
			_ctrlNew ctrlSetText "Copy";
			_ctrlNew ctrlAddEventHandler ["ButtonClick",{
				params ["_ctrlNew"];
				copyToClipboard ctrlText (_ctrlNew getVariable ["TER_3den_contentCtrl",""]);
			}];
		};
		default {};
		};
	_ctrlNew
};
//-- change buttons
_chapterNameArr = [
	"Introduction",
	"Files",
	"description.ext",
	"defines.hpp",
	"dialog.hpp",
	"GUI Editor",
	"Afterword"
];
// prev button
if (_chapter == 0) then {
	BTN_PREV ctrlEnable false;
	BTN_PREV ctrlSettext "";
} else {
	BTN_PREV ctrlEnable true;
	_chapterName = _chapterNameArr select (0 max _chapter-1);
	BTN_PREV ctrlSettext format ["< Chapter %1: %2",_chapter-1,_chapterName];
};
// current chapter
_chapterName = _chapterNameArr select _chapter;
TXT_CURRENT ctrlSettext toUpper format ["Chapter %1: %2",_chapter,_chapterName];
// next chapter
if (_chapter == 6) then {
	BTN_NEXTCHAPTER ctrlEnable false;
	BTN_NEXTCHAPTER ctrlSettext "";
} else {
	BTN_NEXTCHAPTER ctrlEnable true;
	_chapterName = _chapterNameArr select (0 max (_chapter+1));
	BTN_NEXTCHAPTER ctrlSettext format ["Chapter %1: %2 >",_chapter+1,_chapterName];
};

// clear all previous controls
{ctrlDelete _x} forEach CHAPTER_CONTROLS;

switch (_chapter) do {
	case 0: { //-- Chapter 0
		_curTxt =
			"<t size='2'>Welcome to the Easy GUI tutorial!</t>
			With the following 7 chapters you will learn to create your own dialog. In between the chapters you might find some buttons like this one:";
			TFNC_NEW
			_curTxt = "Suspicious button - click me";
			TFNC_TIP("Right here you will find additional information that might not be that important to you. Otherwise the text will prompt you to take a look at it.")

			_curTxt = "
			Here is a brief summary of the content of the chapters:

			<t size='1.5'>Chapter 1: Files</t>
			The files which you have to create beforehand.

			<t size='1.5'>Chapter 2: description.ext</t>
			What the description.ext has to contain.

			<t size='1.5'>Chapter 3: defines.hpp</t>
			Content of the defines.hpp and ways to get it.

			<t size='1.5'>Chapter 4: dialog.hpp</t>
			Creating the template for this dialog and future ones.

			<t size='1.5'>Chapter 5: GUI Editor</t>
			An introduction to the A3 GUI Editor

			<t size='1.5'>Chapter 6: Afterword</t>
			A summary of what we learned and infos for even better dialog creation.

			That's it for the introduction. You can now select a chapter from the editor, press the button on the bottom-right or jump to a chapter by using the index on the left.
			";
		"RscStructuredText" TFNC_NEW
	};
	case 1: {//-- chapter 1
		_curTxt =
			"<t size='2'>Chapter 1: Files</t>
			Before we actually get our hands on the code we have to create some basis on which we can build up on. The first one is the file structure. For better overview we will create a new folder in the mission's root called ""GUI"" where we will create all our files in.";
		"RscStructuredText" TFNC_NEW
		_curTxt = "Where is the mission root?";
		TFNC_TIP("The mission root is where the mission.sqm is stored. After saving your scenario it should appear here:<br/>Documents\Arma 3 - Other Profiles\profilename\missions\missionname.world<br/><br/>Another way of finding it is saving your mission and then going into the 3den Editor. There you have the menu option ""Scenario"". The option ""Open Scenario Folder"" will direct you to the mission root")

		_curTxt = "Next up are the files itself. Create three new files. To create a new file right click >> New >> Text document. Select the ENTIRE file name including the file extension (.txt) and rename them after the following list:";
		"RscStructuredText" TFNC_NEW
		_curTxt = "I can't see the file extension";
		TFNC_TIP("To display file extensions you have to enable it in the Windows Explorer:<br/>Windows Explorer >> View >> File  name extensions<br/><t size='4.5' align='center'><img image='TER_Editing\data\fileextensions.jpg'/></t>")

		_curTxt = "- description.ext
			- defines.hpp
			- dialog.hpp

			Your folder should now look like this:
			<t size='15' align=center><img image='TER_Editing\data\c1_folders.jpg'/></t>

			The defines.hpp and the dialog.hpp can be named whatever you want as long as you keep track of the names and adjust the next steps accordingly.";
		"RscStructuredText" TFNC_NEW
	};
	case 2: {//-- chapter 2
		_curTxt = "<t size='2'>Chapter 2: description.ext</t>
		After creating all those files we have to fill them of course. The description.ext is the config file of the mission, therefore it will also be used for other stuff like mission settings. That is why it has to stay in the mission root. For the sake of clarity we will put our defines and our dialog into external files. Put these 2 lines into the description.ext:";
		TFNC_NEW
		_curTxt = "#include ""GUI\defines.hpp""
		#include ""GUI\dialog.hpp""";
		_contentControl = ["TER_3den_RscEditMulti"] TFNC_NEW
		_newBtn = ["RscButton","RscCopy"] TFNC_NEW
		_newBtn setVariable ["TER_3den_contentCtrl",_contentControl];
		_curTxt = "
		<t color='#FF0000'>Be sure that the path is correct! The #include command is unforgiving and will crash your game!</t>

		Links:
		<a href='https://community.bistudio.com/wiki/Description.ext'>Description.ext</a>
		<a href='https://community.bistudio.com/wiki/PreProcessor_Commands#.23include'>#include</a>";
		TFNC_NEW
	};
	case 3: {//-- chapter 3
		_curTxt = "<t size='2'>Chapter 3: defines.hpp</t>
		The defines.hpp is the foundation for our dialog. Here we will define the style of our dialog and make some shortcuts. You now have multiple options to choose from how to get your own defines.hpp:

		<t size='1.2'>Make your own one!</t>
		See you in a week.

		<t size='1.2'>Use the most common A3 classes</t>
		There is a neat little function called ""BIS_fnc_exportGUIBaseClasses"". The first mode is called ""Default"":";
		TFNC_NEW
		_curTxt = "[""Default""] call BIS_fnc_exportGUIBaseClasses;";
		_curBtnEH = {["Default"] call BIS_fnc_exportGUIBaseClasses;};
		"RscButton" TFNC_NEW
		_curTxt = "By clicking the button you copy everything you need to the clipboard. Go to the defines.hpp and hit CTRL+V.

		<t size='1.2'>3den classes</t>
		Normally you don't need them but if you want to work in the style of the Editor then here you go:";
		TFNC_NEW
		_curTxt = "[""3den""] call BIS_fnc_exportGUIBaseClasses;";
		_curBtnEH = {["3den"] call BIS_fnc_exportGUIBaseClasses;};
		"RscButton" TFNC_NEW
		_curTxt = "
		<t size='1.2'>EVERYTHING</t>
		Just as the title says. This mode will give you access to all the classes available even those that you'll probably never use. Be aware that the file size will be nearly thrice as big as the ""Default"" export. Therefore try to avoid it especially for MP missions.";
		TFNC_NEW
		_curTxt = "[""""] call BIS_fnc_exportGUIBaseClasses;";
		_curBtnEH = {[""] call BIS_fnc_exportGUIBaseClasses;};
		"RscButton" TFNC_NEW
		_curTxt = "
		<t size='1.2'>Mod creators</t>
		If you are working on a mod then you have the easiest option. Just write";
		TFNC_NEW
		_curTxt = "class ""RscClassname"";";
		"TER_3den_RscEditMulti" TFNC_NEW
		_curTxt = "into your defines.hpp or config.cpp. This method will also use the default A3 settings.

		Links:
		<a href='https://community.bistudio.com/wiki/BIS_fnc_exportGUIBaseClasses'>BIS_fnc_exportGUIBaseClasses</a>";
		TFNC_NEW
	};
	case 4: {//-- chapter 4
		_curTxt = "<t size='2'>Chapter 4: dialog.hpp</t>
		The dialog.hpp will contain the controls and properties of your dialog. We will add controls to it in chapter 5. For now we have to create a basic layout of the dialog. You can copy the following one (you might wanna change the spaces to tabs):";
		TFNC_NEW
_curTxt = "class YOUR_DIALOG_CLASS
{
	idd = YOUR_IDD;
	class controlsBackground
	{
	};
	class controls
	{
	};
};";
		_curTxt = [_curTxt,toString [9],"   "] call _PX_fnc_splitReplace;
		_contentControl = "TER_3den_RscEditMulti" TFNC_NEW
		_newBtn = ["RscButton","RscCopy"] TFNC_NEW
		_newBtn setVariable ["TER_3den_contentCtrl",_contentControl];
		_curTxt = "
		You have to change two important things:
		1) YOUR_IDD: Change it to a number that you can remember as this is the go to option for accessing your dialog with ""findDisplay YOUR_IDD"". Higher numbers will result in a position further in the foreground, eg IDD=2 will cover a dialog with IDD=1 where they overlap. Also use a unique number.

		2) YOUR_DIALOG_CLASS: Choose a name that you can remember and add your tag. The class has to be unique therefore you can't have two dialogs which have the same classname. This name is used to create the dialog with ""createDialog 'YOUR_DIALOG_CLASS'"".

		The difference between controlsBackground and controls isn't huge. You can also only use the controls class. Usually you put the controls you can interact with (eg RscEdit, RscButton,...) into the controls class. Everything else goes into the controlsBackground section.

			Example:
			<t size='8' align='center'><img image='TER_Editing\data\c4_example.JPG'/></t><br/>Don't worry about the suddenly increasing numbers. This is an already finished dialog. In fact, it is this one:";
		TFNC_NEW
		_curTxt = "Example dialog";
		TFNC_TIP("---The title is acutally ""Title"" and this text shouldn't exist---")

	};
	case 5: {//-- chapter 5
		_curTxt = "<t size='2'>Chapter 5: GUI Editor</t>
		Now comes the moment we all have waited for: Creating a control. BIS has created a GUI Editor which you can find in the escape menu while you are in a mission and have the console enabled. This tool has so many functions that it would require a tutorial on it's own so this is only a quick rundown. After reading this chapter you can go and try it out yourself.

		These are the most important controls:
		<t color='#FF0000'>- HELP: F1</t>
		- Create a new control: Right click on an empty space
		- Edit a control: Right click on a control
		- Move a control: Drag while holding the left mouse button
		- Change the size of a control: ALT+LMB
		- Highlight controls: Space
		- Export in config (dialog.hpp) format: CTRL+SHIFT+S
		- Import from config: STRG+I
		- Export in import format: STRG+S
		- Import from Clipboard (with import format): STRG+O

		Change the Position type attribute to ""SafeZone"" as the GUI_GRID is broken (even though it is better). Every control created from now on will use this grid until you restart the GUI Editor.
		The first control will be the furthest in the back, so you might not be able to edit it if you put another control on top of it.

		When you are satisfied with the looks export it in the config format. Paste it below the actual dialog as you have to sort it. Move the non-interactable controls to the controlsBackground and the interactable ones to the class controls {};. You might want to save your dialog with STRG+S as well since you can quickly edit it then.

		Here is the full example of what the dialog might look like:
		<t size='30' align=center><img image='TER_Editing\data\c5_dialog.JPG'/></t>
		Note: The IGUIBack class is not a standard class. You have to create it in the defines.hpp to use it.

		Links:
		<a href='https://community.bistudio.com/wiki/User_Interface_Editor_(Arma_3)'>User Interface Editor (Arma 3)</a>";
		TFNC_NEW

	};
	case 6: {//-- chapter 6
		_curTxt = "<t size='2'>Chapter 6: Afterword</t>
		With the end of this tutorial we layed the basics for creating a dialog. Everything that goes beyond that are specific apllications. Going over every command that A3 has to offer about dialogs would be too much for this simple tutorial. The BIKI has everything documented really good. After all this is where I learned half of everything, the other half by trial and error and the remaining quarter by luck.

		Of course there are many ways to get better and better. Take a look at other tutorials. Personally I recommend <a href='http://killzonekid.com/arma-scripting-tutorials-gui-part-1/'>KillzoneKid's website</a>.

		Here are some more useful links:
		<a href='https://community.bistudio.com/wiki/Dialog_Control'>Introduction to dialogs on the BIKI</a>
		<a href='https://community.bistudio.com/wiki/Category:Dialogs'>Further links to pages on the BIKI</a>
		<a href='https://community.bistudio.com/wiki/User_Interface_Event_Handlers'>User Interface Event Handlers</a>

		";
		//This work is not final. Changes will be listed here:
		TFNC_NEW
		//_curTxt = "Changelog";
		//TFNC_TIP(preprocessFile "TER_Eden\ezGUI\changelog.txt")

	};
	default {
	};
};

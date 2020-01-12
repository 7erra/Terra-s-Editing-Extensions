// a3
#ifdef MOD
class RscText;
class RscTextSmall;
class RscTitle;
class RscProgress;
class RscProgressNotFreeze;
class RscPicture;
class RscLadderPicture;
class RscPictureKeepAspect;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscButtonSmall;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscSliderH;
class RscXSliderH;
class RscActiveText;
class RscStructuredText;
class RscControlsGroup;
class RscBackgroundStripeTop;
class RscBackgroundStripeBottom;
class RscToolbox;
class RscMapControl;
class RscCheckBox;
class RscIGText;
class RscIGProgress;
class RscListBoxKeys;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscControlsGroupNoVScrollbars;
class RscLine;
class RscActivePicture;
class RscButtonTextOnly;
class RscShortcutButtonMain;
class RscButtonEditor;
class RscIGUIShortcutButton;
class RscGearShortcutButton;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscLoadingText;
class RscIGUIListBox;
class RscIGUIListNBox;
class RscFrame;
class RscBackground;
class RscBackgroundGUI;
class RscBackgroundGUILeft;
class RscBackgroundGUIRight;
class RscBackgroundGUIBottom;
class RscBackgroundGUITop;
class RscBackgroundGUIDark;
class RscBackgroundLogo;
class RscMapControlEmpty;
class RscVignette;
class RscTextMulti;
class RscTreeSearch;
class RscPictureAllowPixelSplit;
class RscPictureKeepAspectAllowPixelSplit;
class RscVideo;
class RscVideoKeepAspect;
class RscActivePictureKeepAspect;
class RscEditMulti;
class RscMapSignalBackground;
class RscMapSignalPicture;
class RscMapSignalText;
class RscColorPicker;
class RscInterlacingScreen;
class RscFeedback;
class RscTrafficLight;
class RscButtonSearch;
class RscIGUIText;
class RscOpticsText;
class RscOpticsValue;
class RscIGUIValue;
class RscButtonMenuMain;
class RscButtonTestCentered;
class RscButtonArsenal;
class RscTextNoShadow;
class RscButtonNoColor;
class RscToolboxButton;
class RscControlsTable;
// 3den
class ctrlCheckbox;
class ctrlCheckboxBaseline;
class ctrlActivePicture;
class ctrlStatic;
class ctrlControlsGroupNoScrollbars;
class ctrlStructuredText;
class ctrlDefault;
class ctrlDefaultText;
class ctrlDefaultButton;
class ctrlStaticPicture;
class ctrlStaticPictureKeepAspect;
class ctrlStaticPictureTile;
class ctrlStaticFrame;
class ctrlStaticLine;
class ctrlStaticMulti;
class ctrlStaticBackground;
class ctrlStaticOverlay;
class ctrlStaticTitle;
class ctrlStaticFooter;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlButton;
class ctrlButtonPicture;
class ctrlButtonPictureKeepAspect;
class ctrlButtonOK;
class ctrlButtonCancel;
class ctrlButtonClose;
class ctrlButtonToolbar;
class ctrlButtonSearch;
class ctrlButtonExpandAll;
class ctrlButtonCollapseAll;
class ctrlButtonFilter;
class ctrlEdit;
class ctrlEditMulti;
class ctrlSliderV;
class ctrlSliderH;
class ctrlCombo;
class ctrlComboToolbar;
class ctrlListbox;
class ctrlToolbox;
class ctrlToolboxPicture;
class ctrlToolboxPictureKeepAspect;
class ctrlCheckboxes;
class ctrlCheckboxesCheckbox;
class ctrlProgress;
class ctrlHTML;
class ctrlActiveText;
class ctrlActivePictureKeepAspect;
class ctrlTree;
class ctrlControlsGroup;
class ctrlControlsGroupNoHScrollbars;
class ctrlControlsGroupNoVScrollbars;
class ctrlShortcutButton;
class ctrlShortcutButtonOK;
class ctrlShortcutButtonCancel;
class ctrlShortcutButtonSteam;
class ctrlXListbox;
class ctrlXSliderV;
class ctrlXSliderH;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlMap;
class ctrlMapEmpty;
class ctrlMapMain;
class ctrlListNBox;
class ctrlCheckboxToolbar;

#else

class ScrollBar
{
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.3};
	thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
	arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	shadow = 0;
	scrollSpeed = 0.06;
	width = 0;
	height = 0;
	autoScrollEnabled = 0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
};
class RscObject
{
	access = 0;
	type = CT_OBJECT;
	scale = 1;
	direction[] = {0,0,1};
	up[] = {0,1,0};
	shadow = 0;
};
class RscText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_STATIC;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	text = "";
	fixedWidth = 0;
	colorShadow[] = {0,0,0,0.5};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = ST_LEFT;
	shadow = 1;
	font = "RobotoCondensed";
	SizeEx = GUI_TEXT_SIZE_MEDIUM;
	linespacing = 1;
};
class RscTextSmall: RscText
{
	h = 0.03;
	sizeEx = 0.027;
};
class RscTitle: RscText
{
	x = 0.15;
	y = 0.06;
	w = 0.7;
	shadow = 0;
	colorText[] = {0.95,0.95,0.95,1};
	style = ST_LEFT;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	font = "PuristaMedium";
};
class RscProgress
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_PROGRESS;
	style = ST_HORIZONTAL;
	colorFrame[] = {0,0,0,0};
	colorBar[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	x = 0.344;
	y = 0.619;
	w = 0.313726;
	h = 0.0261438;
	shadow = 2;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
};
class RscProgressNotFreeze
{
	deletable = 0;
	fade = 0;
	idc = -1;
	type = CT_ANIMATED_TEXTURE;
	style = ST_LEFT;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.5;
	h = 0.1;
	texture = "#(argb,8,8,3)color(0,0,0,0)";
};
class RscPicture
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_STATIC;
	idc = -1;
	style = ST_MULTI + ST_TITLE_BAR;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	fixedWidth = 0;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
};
class RscLadderPicture: RscPicture
{
	bottomValue = 0;
	topValue = 100;
	visibleRange = -1;
};
class RscPictureKeepAspect: RscPicture
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class RscHTML
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_HTML;
	idc = -1;
	style = ST_LEFT;
	filename = "";
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	colorBold[] = {1,1,1,1};
	colorLink[] = {1,1,1,0.75};
	colorLinkActive[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureLink[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureBorder[] = {0,0,0,0};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class H1
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_LARGE;
		align = "left";
	};
	class H2
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "right";
	};
	class H3
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "left";
	};
	class H4
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "left";
	};
	class H5
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "left";
	};
	class H6
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "left";
	};
	class P
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "left";
	};
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.1;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	prevPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
	nextPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
	shadow = 2;
};
class RscButton
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_BUTTON;
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {0,0,0,0.5};
	colorBackgroundDisabled[] = {0,0,0,0.5};
	colorBackgroundActive[] = {0,0,0,1};
	colorFocused[] = {0,0,0,1};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,1};
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.09,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundClick[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.09,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.09,
		1
	};
	idc = -1;
	style = ST_CENTER;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	url = "";
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	borderSize = 0;
};
class RscShortcutButton
{
	deletable = 0;
	fade = 0;
	type = CT_SHORTCUTBUTTON;
	x = 0.1;
	y = 0.1;
	class HitZone
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0;
		top = ((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_MEDIUM) / 2;
		w = GUI_TEXT_SIZE_MEDIUM * (3/4);
		h = GUI_TEXT_SIZE_MEDIUM;
	};
	class TextPos
	{
		left = GUI_TEXT_SIZE_MEDIUM * (3/4);
		top = ((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_MEDIUM) / 2;
		right = 0.005;
		bottom = 0;
	};
	shortcuts[] = {};
	textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
	color[] = {1,1,1,1};
	colorFocused[] = {1,1,1,1};
	color2[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	colorBackgroundFocused[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	colorBackground2[] = {1,1,1,1};
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.09,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundClick[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.09,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.09,
		1
	};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	colorSecondary[] = {1,1,1,1};
	colorFocusedSecondary[] = {1,1,1,1};
	color2Secondary[] = {0.95,0.95,0.95,1};
	colorDisabledSecondary[] = {1,1,1,0.25};
	class AttributesImage
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "left";
	};
	idc = -1;
	style = ST_LEFT;
	default = 0;
	shadow = 1;
	w = 0.183825;
	h = (GUI_GRID_HAbs / 20);
	textSecondary = "";
	sizeExSecondary = GUI_TEXT_SIZE_MEDIUM;
	fontSecondary = "RobotoCondensed";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
	periodFocus = 1.2;
	periodOver = 0.8;
	period = 0.4;
	font = "RobotoCondensed";
	size = GUI_TEXT_SIZE_MEDIUM;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	text = "";
	url = "";
	action = "";
};
class RscButtonSmall: RscButton
{
	w = 0.12;
};
class RscEdit
{
	style="0x00 + 0x40";
	font="RobotoCondensed";
	shadow=2;
	sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	colorBackground[]={0,0,0,0};
	colorText[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelection[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	canModify=1;
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
};
class RscCombo
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_COMBO;
	colorSelect[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,1};
	colorScrollbar[] = {1,0,0,1};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {0,0,0,1};
	colorSelect2Right[] = {0,0,0,1};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundSelect",
		0.1,
		1
	};
	soundExpand[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundExpand",
		0.1,
		1
	};
	soundCollapse[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundCollapse",
		0.1,
		1
	};
	maxHistoryDelay = 1;
	class ComboScrollBar: ScrollBar
	{
		color[] = {1,1,1,1};
	};
	colorSelectBackground[] = {1,1,1,0.7};
	colorActive[] = {1,0,0,1};
	style = ST_MULTI + ST_NO_RECT;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.12;
	h = 0.035;
	arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
};
class RscListBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_LISTBOX;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorScrollbar[] = {1,0,0,0};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,0.3};
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {0,0,0,1};
	colorSelect2Right[] = {0,0,0,1};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class ListScrollBar: ScrollBar
	{
		color[] = {1,1,1,1};
		autoScrollEnabled = 1;
	};
	colorShadow[] = {0,0,0,0.5};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	style = LB_TEXTURES;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	shadow = 0;
	period = 1.2;
	maxHistoryDelay = 1;
};
class RscListNBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_LISTNBOX;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,1};
	maxHistoryDelay = 1;
	soundSelect[] =
	{
		"",
		0.1,
		1
	};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	drawSideArrows = 0;
	columns[] = {0.3,0.6,0.7};
	idcLeft = -1;
	idcRight = -1;
	class ListScrollBar: ScrollBar
	{
	};
	color[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,1};
	class ScrollBar: ScrollBar
	{
	};
	style = ST_MULTI;
	shadow = 0;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	period = 1.2;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
};
class RscXListBox
{
	deletable = 0;
	fade = 0;
	idc = -1;
	enabled = 1;
	type = CT_XLISTBOX;
	x = 0.1;
	y = 0.1;
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorText[] = {1,1,1,1};
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	style = ST_CENTER + LB_TEXTURES + SL_HORZ;
	shadow = 2;
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	w = 0.14706;
	h = 0.039216;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
};
class RscTree
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_TREE;
	colorBackground[] = {0,0,0,0};
	colorSelect[] = {1,1,1,0.7};
	colorDisabled[] = {1,1,1,0.25};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {0,0,0,1};
	colorBorder[] = {0,0,0,0};
	colorSearch[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	colorMarked[] = {0.2,0.3,0.7,1};
	colorMarkedText[] = {0,0,0,1};
	colorMarkedSelected[] = {0,0.5,0.5,1};
	multiselectEnabled = 0;
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {0,0,0,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {0,0,0,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorArrow[] = {1,1,1,1};
	maxHistoryDelay = 1;
	shadow = 0;
	colorSelectBackground[] = {0,0,0,0.5};
	colorLines[] = {0,0,0,0};
	class ScrollBar: ScrollBar
	{
	};
	style = ST_LEFT;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa";
	hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa";
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.2;
	rowHeight = 0.0439091;
	borderSize = 0;
	expandOnDoubleclick = 1;
};
class RscSlider
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_SLIDER;
	style = SL_HORZ;
	color[] = {1,1,1,0.8};
	colorActive[] = {1,1,1,1};
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.025;
};
class RscSliderH: RscSlider
{
};
class RscXSliderH
{
	deletable = 0;
	fade = 0;
	type = CT_XSLIDER;
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisable[] = {1,1,1,0.4};
	colorDisabled[] = {1,1,1,0.2};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	style = SL_TEXTURES + SL_HORZ;
	shadow = 0;
	x = 0;
	y = 0;
	h = 0.029412;
	w = 0.4;
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
};
class RscActiveText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_ACTIVETEXT;
	style = ST_CENTER;
	color[] = {0,0,0,1};
	colorActive[] = {0.3,0.4,0,1};
	colorDisabled[] = {1,1,1,0.25};
	soundEnter[] =
	{
		"",
		0.1,
		1
	};
	soundPush[] =
	{
		"",
		0.1,
		1
	};
	soundClick[] =
	{
		"",
		0.1,
		1
	};
	soundEscape[] =
	{
		"",
		0.1,
		1
	};
	text = "";
	default = 0;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	idc = -1;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.035;
	font = "RobotoCondensed";
	shadow = 2;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
	url = "";
};
class RscStructuredText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_STRUCTURED_TEXT;
	idc = -1;
	style = ST_LEFT;
	colorText[] = {1,1,1,1};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#ffffff";
		colorLink = "#D09B43";
		align = "left";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = GUI_TEXT_SIZE_MEDIUM;
	shadow = 1;
};
class RscControlsGroup
{
	deletable = 0;
	fade = 0;
	class VScrollbar: ScrollBar
	{
		color[] = {1,1,1,1};
		width = 0.021;
		autoScrollEnabled = 1;
	};
	class HScrollbar: ScrollBar
	{
		color[] = {1,1,1,1};
		height = 0.028;
	};
	class Controls
	{
	};
	type = CT_CONTROLS_GROUP;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = ST_MULTI;
};
class RscBackgroundStripeTop: RscText
{
	colorBackground[] = {0.1,0.1,0.1,1};
	access = 0;
	x = "safezoneX";
	y = "safezoneY";
	w = "safezoneW";
	h = "0.125*safezoneH";
	text = "";
};
class RscBackgroundStripeBottom: RscText
{
	access = 0;
	colorBackground[] = {0.1,0.1,0.1,1};
	x = "safezoneX";
	y = "safezoneY + safezoneH - 0.125*safezoneH";
	w = "safezoneW";
	h = "0.125*safezoneH";
	text = "";
};
class RscToolbox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_TOOLBOX;
	style = ST_CENTER;
	colorText[] = {0.95,0.95,0.95,1};
	color[] = {0.95,0.95,0.95,1};
	colorTextSelect[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorTextDisable[] = {0.4,0.4,0.4,1};
	colorDisable[] = {0.4,0.4,0.4,1};
	colorSelectedBg[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		0.5
	};
	shadow = 0;
	strings[] =
	{
		"",
		""
	};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.025;
	rows = 1;
	columns = 2;
	font = "RobotoCondensed";
	sizeEx = GUI_TEXT_SIZE_SMALL;
};
class RscToolboxButton: RscToolbox
{
	font = "RobotoCondensedLight";
	color[] = {1,1,1,1};
	colorTextSelect[] = {0,0,0,1};
	colorSelectedBg[] = {1,1,1,1};
};
class RscMapControl
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = CT_MAP_MAIN;
	idc = 51;
	style = ST_MULTI + ST_TITLE_BAR;
	colorBackground[] = {0.969,0.957,0.949,1};
	colorOutside[] = {0,0,0,1};
	colorText[] = {0,0,0,1};
	font = "TahomaB";
	sizeEx = 0.04;
	colorSea[] = {0.467,0.631,0.851,0.5};
	colorForest[] = {0.624,0.78,0.388,0.5};
	colorRocks[] = {0,0,0,0.3};
	colorCountlines[] = {0.572,0.354,0.188,0.25};
	colorMainCountlines[] = {0.572,0.354,0.188,0.5};
	colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
	colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
	colorForestBorder[] = {0,0,0,0};
	colorRocksBorder[] = {0,0,0,0};
	colorPowerLines[] = {0.1,0.1,0.1,1};
	colorRailWay[] = {0.8,0.2,0,1};
	colorNames[] = {0.1,0.1,0.1,0.9};
	colorInactive[] = {1,1,1,0.5};
	colorLevels[] = {0.286,0.177,0.094,0.5};
	colorTracks[] = {0.84,0.76,0.65,0.15};
	colorRoads[] = {0.7,0.7,0.7,1};
	colorMainRoads[] = {0.9,0.5,0.3,1};
	colorTracksFill[] = {0.84,0.76,0.65,1};
	colorRoadsFill[] = {1,1,1,1};
	colorMainRoadsFill[] = {1,0.6,0.4,1};
	colorGrid[] = {0.1,0.1,0.1,0.6};
	colorGridMap[] = {0.1,0.1,0.1,0.6};
	stickX[] = {0.2,["Gamma",1,1.5]};
	stickY[] = {0.2,["Gamma",1,1.5]};
	class Legend
	{
		colorBackground[] = {1,1,1,0.5};
		color[] = {0,0,0,1};
		x = SafeZoneX + GUI_GRID_W;
		y = SafeZoneY + safezoneH - 4.5 * GUI_GRID_H;
		w = 10 * GUI_GRID_W;
		h = 3.5 * GUI_GRID_H;
		font = "RobotoCondensed";
		sizeEx = GUI_TEXT_SIZE_SMALL;
	};
	class ActiveMarker
	{
		color[] = {0.3,0.1,0.9,1};
		size = 50;
	};
	class Command
	{
		color[] = {1,1,1,1};
		icon = "\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Task
	{
		taskNone = "#(argb,8,8,3)color(0,0,0,0)";
		taskCreated = "#(argb,8,8,3)color(0,0,0,1)";
		taskAssigned = "#(argb,8,8,3)color(1,1,1,1)";
		taskSucceeded = "#(argb,8,8,3)color(0,1,0,1)";
		taskFailed = "#(argb,8,8,3)color(1,0,0,1)";
		taskCanceled = "#(argb,8,8,3)color(1,0.5,0,1)";
		colorCreated[] = {1,1,1,1};
		colorCanceled[] = {0.7,0.7,0.7,1};
		colorDone[] = {0.7,1,0.3,1};
		colorFailed[] = {1,0.3,0.2,1};
		color[] =
		{
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
			"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
		};
		icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
		iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
		iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
		iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
		iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class CustomMark
	{
		color[] = {1,1,1,1};
		icon = "\a3\ui_f\data\map\mapcontrol\custommark_ca.paa";
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Tree
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class SmallTree
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		size = "14/2";
		importance = "0.2 * 14 * 0.05 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Church
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Chapel
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Cross
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Rock
	{
		color[] = {0.1,0.1,0.1,0.8};
		icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bunker
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size = 14;
		importance = "1.5 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fountain
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
		size = 11;
		importance = "1 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class ViewTower
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Lighthouse
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Quay
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Fuelstation
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Hospital
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class BusStop
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\busstop_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class LineMarker
	{
		textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
		lineWidthThin = 0.008;
		lineWidthThick = 0.014;
		lineDistanceMin = 3e-005;
		lineLengthMin = 5;
	};
	class Transmitter
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Stack
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.4;
		coefMax = 2;
	};
	class Ruin
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
		size = 16;
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class Tourism
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Watertower
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Waypoint
	{
		color[] = {1,1,1,1};
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size = 18;
	};
	class WaypointCompleted
	{
		color[] = {1,1,1,1};
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\a3\ui_f\data\map\mapcontrol\waypointcompleted_ca.paa";
		size = 18;
	};
	colorTrails[] = {0.84,0.76,0.65,0.15};
	colorTrailsFill[] = {0.84,0.76,0.65,0.65};
	class power
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class powersolar
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class powerwave
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class powerwind
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	class Shipwreck
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Shipwreck_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
	};
	moveOnEdges = 1;
	x = "SafeZoneXAbs";
	y = SafeZoneY + 1.5 * GUI_GRID_H;
	w = "SafeZoneWAbs";
	h = SafeZoneH - 1.5 * GUI_GRID_H;
	shadow = 0;
	ptsPerSquareSea = 5;
	ptsPerSquareTxt = 20;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = 9;
	ptsPerSquareForEdge = 9;
	ptsPerSquareRoad = 6;
	ptsPerSquareObj = 9;
	showCountourInterval = 0;
	scaleMin = 0.001;
	scaleMax = 1;
	scaleDefault = 0.16;
	maxSatelliteAlpha = 0.85;
	alphaFadeStartScale = 2;
	alphaFadeEndScale = 2;
	fontLabel = "RobotoCondensed";
	sizeExLabel = GUI_TEXT_SIZE_SMALL;
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = GUI_TEXT_SIZE_SMALL;
	fontNames = "EtelkaNarrowMediumPro";
	sizeExNames = GUI_TEXT_SIZE_SMALL * 2;
	fontInfo = "RobotoCondensed";
	sizeExInfo = GUI_TEXT_SIZE_SMALL;
	fontLevel = "TahomaB";
	sizeExLevel = 0.02;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	idcMarkerColor = -1;
	idcMarkerIcon = -1;
	textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
	showMarkers = 1;
};
class RscCheckBox
{
	color[] = {1,1,1,0.7};
	colorFocused[] = {1,1,1,1};
	colorHover[] = {1,1,1,1};
	colorPressed[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.2};
	colorBackground[] = {0,0,0,0};
	colorBackgroundFocused[] = {0,0,0,0};
	colorBackgroundHover[] = {0,0,0,0};
	colorBackgroundPressed[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	soundEnter[] =
	{
		"",
		0.1,
		1
	};
	soundPush[] =
	{
		"",
		0.1,
		1
	};
	soundClick[] =
	{
		"",
		0.1,
		1
	};
	soundEscape[] =
	{
		"",
		0.1,
		1
	};
	idc = -1;
	type = CT_CHECKBOX;
	deletable = 0;
	style = ST_LEFT;
	checked = 0;
	x = "0.375 * safezoneW + safezoneX";
	y = "0.36 * safezoneH + safezoneY";
	w = "0.025 * safezoneW";
	h = "0.04 * safezoneH";
	textureChecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureUnchecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureFocusedChecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureFocusedUnchecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureHoverChecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked = "A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
};
class RscIGText: RscText
{
	access = 0;
	h = 0.04;
	colorText[] = {0.8,0.8,0.8,1};
	font = "TahomaB";
	sizeEx = 0.024;
	style = ST_SHADOW;
};
class RscIGProgress: RscProgress
{
	colorFrame[] = {0.706,0.098,0.9294,0};
	colorBar[] =
	{
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
	};
	style = ST_VERTICAL;
	w = 0.009;
	h = 0.178;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
};
class RscListBoxKeys: RscListBox
{
	collisionColor[] =
	{
		"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])",
		"(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])",
		"(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",
		1
	};
	collisionColorFirstKey[] =
	{
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",
		1
	};
	disabledKeyColor[] = {0.4,0.4,0.4,1};
	mainCollumW = 0.4;
	secndCollumW = 0.6;
};
class RscControlsGroupNoScrollbars: RscControlsGroup
{
	class VScrollbar: VScrollbar
	{
		width = 0;
	};
	class HScrollbar: HScrollbar
	{
		height = 0;
	};
};
class RscControlsGroupNoHScrollbars: RscControlsGroup
{
	class HScrollbar: HScrollbar
	{
		height = 0;
	};
};
class RscControlsGroupNoVScrollbars: RscControlsGroup
{
	class VScrollbar: VScrollbar
	{
		width = 0;
	};
};
class RscLine: RscText
{
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	idc = -1;
	style = ST_MULTI + ST_TITLE_BAR + ST_HUD_BACKGROUND;
	x = 0.17;
	y = 0.48;
	w = 0.66;
	h = 0;
	text = "";
};
class RscActivePicture: RscActiveText
{
	color[] = {1,1,1,0.5};
	colorActive[] = {1,1,1,1};
	style = ST_MULTI + ST_TITLE_BAR;
};
class RscButtonTextOnly: RscButton
{
	colorBackground[] = {1,1,1,0};
	colorBackgroundActive[] = {1,1,1,0};
	colorBackgroundDisabled[] = {1,1,1,0};
	colorFocused[] = {1,1,1,0};
	colorShadow[] = {1,1,1,0};
	SizeEx = GUI_TEXT_SIZE_SMALL;
	borderSize = 0;
};
class RscShortcutButtonMain: RscShortcutButton
{
	color[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	class HitZone
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0.0145;
		top = ((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_LARGE) / 2;
		w = GUI_TEXT_SIZE_LARGE * (3/4);
		h = GUI_TEXT_SIZE_LARGE;
	};
	class TextPos
	{
		left = (GUI_GRID_WAbs / 32) * 1.5;
		top = ((GUI_GRID_HAbs / 20)*2 - GUI_TEXT_SIZE_LARGE) / 2;
		right = 0.005;
		bottom = 0;
	};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class AttributesImage
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "false";
	};
	idc = -1;
	style = ST_LEFT;
	default = 0;
	w = 0.313726;
	h = 0.104575;
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	period = 0.5;
	font = "RobotoCondensed";
	size = GUI_TEXT_SIZE_LARGE;
	sizeEx = GUI_TEXT_SIZE_LARGE;
	text = "";
	action = "";
};
class RscButtonEditor: RscShortcutButton
{
	class ShortcutPos
	{
		left = 0;
		top = 0;
		w = 0;
		h = 0;
	};
	class TextPos
	{
		left = 0;
		top = ((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_MEDIUM) / 2;
		right = 0;
		bottom = 0;
	};
};
class RscIGUIShortcutButton: RscShortcutButton
{
	class HitZone
	{
		left = 0.002;
		top = "0.003 * 0.7";
		right = 0.002;
		bottom = "0.016 * 0.7";
	};
	class ShortcutPos
	{
		left = -0.006;
		top = "-0.007 * 0.7";
		w = 0;
		h = "0.0522876 * 0.7";
	};
	class TextPos
	{
		left = 0;
		top = "0.000 * 0.7";
		right = 0;
		bottom = "0.016 * 0.7";
	};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "center";
		shadow = "true";
	};
	w = 0.183825;
	h = "0.0522876 * 0.7";
	style = ST_CENTER;
};
class RscGearShortcutButton: RscShortcutButton
{
	color[] = {1,1,1,1};
	color2[] = {1,1,1,0.85};
	colorBackground[] = {1,1,1,1};
	colorbackground2[] = {1,1,1,0.85};
	colorDisabled[] = {1,1,1,0.4};
	class HitZone
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = -0.006;
		top = -0.007;
		w = 0.0392157;
		h = 0.0522876;
	};
	class TextPos
	{
		left = 0.003;
		top = 0.001;
		right = 0;
		bottom = 0;
	};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "center";
		shadow = "false";
	};
	w = 0.0392157;
	h = 0.0522876;
	style = ST_CENTER;
	sizeEx = 0.1;
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\disabled_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\down_ca.paa";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\normal_ca.paa";
};
class RscButtonMenu: RscShortcutButton
{
	colorBackground[] = {0,0,0,0.8};
	colorBackgroundFocused[] = {1,1,1,1};
	colorBackground2[] = {0.75,0.75,0.75,1};
	color[] = {1,1,1,1};
	colorFocused[] = {0,0,0,1};
	color2[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSecondary[] = {1,1,1,1};
	colorFocusedSecondary[] = {0,0,0,1};
	color2Secondary[] = {0,0,0,1};
	colorDisabledSecondary[] = {1,1,1,0.25};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class TextPos
	{
		left = 0.25 * GUI_GRID_W;
		top = (GUI_GRID_H - GUI_TEXT_SIZE_MEDIUM) / 2;
		right = 0.005;
		bottom = 0;
	};
	class Attributes
	{
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class ShortcutPos
	{
		left = 5.25 * GUI_GRID_W;
		top = 0;
		w = 1 * GUI_GRID_W;
		h = 1 * GUI_GRID_H;
	};
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",
		0.09,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundPush",
		0.09,
		1
	};
	soundClick[] =
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundClick",
		0.09,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",
		0.09,
		1
	};
	idc = -1;
	type = CT_SHORTCUTBUTTON;
	style = ST_CENTER + ST_FRAME + ST_HUD_BACKGROUND;
	default = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
	textSecondary = "";
	sizeExSecondary = GUI_TEXT_SIZE_MEDIUM;
	fontSecondary = "PuristaLight";
	period = 1.2;
	periodFocus = 1.2;
	periodOver = 1.2;
	size = GUI_TEXT_SIZE_MEDIUM;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
};
class RscButtonMenuOK: RscButtonMenu
{
	shortcuts[] =
	{
		"0x00050000 + 0",
		28,
		57,
		156
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",
		0.09,
		1
	};
	idc = 1;
	default = 1;
	text = "OK";
};
class RscButtonMenuCancel: RscButtonMenu
{
	shortcuts[] =
	{
		"0x00050000 + 1"
	};
	idc = 2;
	text = "Cancel";
};
class RscButtonMenuSteam: RscButtonMenu
{
	colorBackground[] = {0.0313726,0.721569,0.917647,1};
	class TextPos
	{
		left = 0.0325;
		top = (GUI_GRID_H - GUI_TEXT_SIZE_MEDIUM) / 2;
		right = 0.005;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0.005;
		top = 0.005;
		w = 0.0225;
		h = 0.03;
	};
	textureNoShortcut = "\A3\Ui_f\data\GUI\RscCommon\RscButtonMenuSteam\steam_ca.paa";
};
class RscLoadingText: RscText
{
	colorText[] = {1,1,1,1};
	style = ST_CENTER;
	x = 0.29412;
	y = 0.666672;
	w = 0.411768;
	h = 0.039216;
	sizeEx = GUI_TEXT_SIZE_MEDIUM;
};
class RscIGUIListBox: RscListBox
{
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorSelect2[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {0,0,0,0.4};
	colorSelectBackground2[] = {0,0,0,1};
	colorBackground[] = {0,0,0,0};
	class ScrollBar: ScrollBar
	{
	};
	period = 0;
	sizeEx = GUI_TEXT_SIZE_SMALL;
};
class RscIGUIListNBox: RscListNBox
{
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,0.75};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorSelect2[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {1,1,1,1};
	colorSelectBackground2[] = {1,1,1,1};
	colorBackground[] = {0,0,0,1};
	columns[] = {0.1,0.7,0.1,0.1};
	class ScrollBar: ScrollBar
	{
	};
	style = ST_MULTI;
	shadow = 2;
	period = 0;
};
class RscFrame
{
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	type = CT_STATIC;
	idc = -1;
	deletable = 0;
	style = ST_FRAME;
	shadow = 2;
	font = "RobotoCondensed";
	sizeEx = 0.02;
	text = "";
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
};
class RscBackground: RscText
{
	ColorBackground[] = {0.48,0.5,0.35,1};
	ColorText[] = {0.1,0.1,0.1,1};
	type = CT_STATIC;
	IDC = -1;
	style = ST_NO_RECT;
	shadow = 0;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	text = "";
	font = "RobotoCondensed";
	SizeEx = 1;
};
class RscBackgroundGUI: RscText
{
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	background = 1;
};
class RscBackgroundGUILeft: RscPicture
{
	colorText[] =
	{
		1,
		1,
		1,
		"0.3*0"
	};
	colorBackground[] = {0,0,0,0};
	text = "A3\ui_f\data\gui\rsccommon\rscbackgroundgui\gradient_left_gs.paa";
	background = 1;
};
class RscBackgroundGUIRight: RscPicture
{
	colorText[] =
	{
		0,
		0,
		0,
		"0.4*0"
	};
	colorBackground[] = {0,0,0,0};
	text = "A3\ui_f\data\gui\rsccommon\rscbackgroundgui\gradient_right_gs.paa";
	background = 1;
};
class RscBackgroundGUIBottom: RscPicture
{
	colorText[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		0.8
	};
	text = "A3\ui_f\data\gui\rsccommon\rscshortcutbutton\background_ca.paa";
	align = "bottom";
	background = 1;
};
class RscBackgroundGUITop: RscText
{
	colorBackground[] = {0,0,0,1};
	align = "top";
	moving = 1;
	background = 1;
};
class RscBackgroundGUIDark: RscText
{
	colorBackground[] = {0,0,0,0.2};
	background = 1;
};
class RscBackgroundLogo: RscPictureKeepAspect
{
	text = "\A3\Ui_f\data\Logos\arma3_splash_ca.paa";
	align = "top";
	background = 1;
	x = safezoneX + safezoneW - (9 * (GUI_GRID_WAbs / 32));
	y = safezoneY - 2 * (GUI_GRID_HAbs / 20);
	w = (8 * (GUI_GRID_WAbs / 32));
	h = (8 * (GUI_GRID_HAbs / 20));
};
class RscMapControlEmpty: RscMapControl
{
	colorBackground[] = {1,1,1,1};
	colorOutside[] = {1,1,1,1};
	colorSea[] = {0,0,0,0};
	colorForest[] = {0,0,0,0};
	colorForestBorder[] = {0,0,0,0};
	colorRocks[] = {0,0,0,0};
	colorRocksBorder[] = {0,0,0,0};
	colorLevels[] = {0,0,0,0};
	colorMainCountlines[] = {0,0,0,0};
	colorCountlines[] = {0,0,0,0};
	colorMainCountlinesWater[] = {0,0,0,0};
	colorCountlinesWater[] = {0,0,0,0};
	colorPowerLines[] = {0,0,0,0};
	colorRailWay[] = {0,0,0,0};
	colorNames[] = {0,0,0,0};
	colorInactive[] = {0,0,0,0};
	colorGrid[] = {0,0,0,0};
	colorGridMap[] = {0,0,0,0};
	class Task: Task
	{
		color[] = {0,0,0,0};
		colorCreated[] = {0,0,0,0};
		colorCanceled[] = {0,0,0,0};
		colorDone[] = {0,0,0,0};
		colorFailed[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		iconCreated = "#(argb,8,8,3)color(0,0,0,0)";
		iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
		iconDone = "#(argb,8,8,3)color(0,0,0,0)";
		iconFailed = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Waypoint: Waypoint
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class WaypointCompleted: WaypointCompleted
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class CustomMark: CustomMark
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Command: Command
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Bush: Bush
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Rock: Rock
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class SmallTree: SmallTree
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Tree: Tree
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class busstop: BusStop
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class fuelstation: Fuelstation
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class hospital: Hospital
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class church: Church
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class lighthouse: Lighthouse
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class power: power
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class powersolar: powersolar
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class powerwave: powerwave
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class powerwind: powerwind
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class quay: Quay
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class shipwreck: Shipwreck
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class transmitter: Transmitter
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class watertower: Watertower
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Bunker: Bunker
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Cross: Cross
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Fortress: Fortress
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Fountain: Fountain
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Chapel: Chapel
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Ruin: Ruin
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Stack: Stack
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class Tourism: Tourism
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	class ViewTower: ViewTower
	{
		color[] = {0,0,0,0};
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		size = 0;
	};
	type = CT_MAP_MAIN;
	ptsPerSquareSea = 1000;
	ptsPerSquareTxt = 1000;
	ptsPerSquareCLn = 1000;
	ptsPerSquareExp = 1000;
	ptsPerSquareCost = 1000;
	ptsPerSquareFor = 1000;
	ptsPerSquareForEdge = 1000;
	ptsPerSquareRoad = 1000;
	ptsPerSquareObj = 1000;
	alphaFadeStartScale = 0;
	alphaFadeEndScale = 0;
};
class RscVignette: RscPicture
{
	colortext[] = {0,0,0,0.3};
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	text = "\A3\ui_f\data\gui\rsccommon\rscvignette\vignette_gs.paa";
};
class CA_Mainback: RscPicture
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
	};
	x = 0.35;
	y = 0.8;
	w = 0.3;
	h = 0.2;
	text = "#(argb,8,8,3)color(0,0,0,0.5)";
};
class CA_Back: CA_Mainback
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
	};
	x = 0.29;
	y = 0.38;
	w = 0.56;
	h = 0.57;
	text = "#(argb,8,8,3)color(0,0,0,0.5)";
};
class CA_Title_Back: CA_Mainback
{
	colorText[] = {0.95,0.95,0.95,1};
	x = 0.014706;
	y = 0;
	w = 0.950743;
	h = 0.058824;
	text = "#(argb,8,8,3)color(0,0,0,0)";
};
class CA_Black_Back: CA_Mainback
{
	colorText[] = {0,0,0,1};
	color[] = {0,0,0,1};
	colorBackground[] = {0,0,0,1};
	x = "SafeZoneX - SafeZoneW";
	y = "SafeZoneY - SafeZoneH";
	w = "SafeZoneW * 4";
	h = "SafeZoneH * 4";
	text = "#(argb,8,8,3)color(0,0,0,1)";
};
class CA_Title: RscTitle
{
};
class CA_Logo: RscPictureKeepAspect
{
	idc = 1220;
	x = 0.638;
	y = 0.333;
	w = 0.25;
	h = 0.08;
	text = "#(argb,8,8,3)color(1,1,1,1)";
};
class CA_Logo_Small: CA_Logo
{
	w = 0.2;
	h = 0.0666;
};
class CA_RscButton: RscButton
{
	color[] = {0,0,0,0};
	colorActive[] = {0,0,0,0};
	idc = -1;
	default = 0;
	x = 0.843144;
	y = 0.8;
	w = 0.14706;
	h = 0.039216;
	borderSize = 0.009804;
};
class CA_RscButton_dialog: CA_RscButton
{
	x = 0.823536;
	y = 0.85;
	w = 0.198531;
	borderSize = 0;
};
class CA_Ok: RscActiveText
{
	color[] = {0,0,0,0};
	colorActive[] = {0,0,0,0};
	idc = -1;
	style = ST_MULTI + ST_TITLE_BAR;
	default = 0;
	x = 0.85;
	y = 0.8;
	w = 0.15;
	h = 0.035;
	text = "#(argb,8,8,3)color(0,0,0,0)";
};
class CA_Ok_image: RscText
{
	colortext[] = {1,1,1,0.8};
	idc = -1;
	x = 0.86;
	y = 0.8;
	w = 0.14;
	h = 0.04;
	text = "#(argb,8,8,3)color(1,1,1,0.9)";
	style = ST_MULTI + ST_TITLE_BAR;
};
class CA_Ok_image2: RscText
{
	colortext[] = {0,0,0,0.8};
	idc = -1;
	x = 0.85;
	y = 0.8;
	w = 0.01;
	h = 0.04;
	text = "#(argb,8,8,3)color(1,1,1,0.9)";
	style = ST_MULTI + ST_TITLE_BAR;
};
class CA_Ok_text: RscText
{
	colortext[] = {0,0,0,0.8};
	sizeEx = GUI_TEXT_SIZE_SMALL;
	idc = -1;
	x = 0.86;
	y = 0.8;
	w = 0.14;
	h = 0.04;
	style = ST_LEFT;
};
class ctrlDefault
{
	access = 0;
	idc = -1;
	style = ST_LEFT;
	default = 0;
	show = 1;
	fade = 0;
	blinkingPeriod = 0;
	deletable = 0;
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	tooltip = "";
	tooltipMaxWidth = 0.5;
	tooltipColorShade[] = {0,0,0,1};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {0,0,0,0};
	class ScrollBar
	{
		width = 0;
		height = 0;
		scrollSpeed = 0.06;
		arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[] = {1,1,1,1};
	};
};
class ctrlCheckbox: ctrlDefault
{
	type = CT_CHECKBOX;
	checked = 0;
	color[] = {1,1,1,0.7};
	colorFocused[] = {1,1,1,1};
	colorHover[] = {1,1,1,1};
	colorPressed[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {0,0,0,0};
	colorBackgroundFocused[] = {0,0,0,0};
	colorBackgroundHover[] = {0,0,0,0};
	colorBackgroundPressed[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	textureChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa";
	textureUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa";
	textureFocusedChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa";
	textureFocusedUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa";
	textureHoverChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa";
	textureHoverUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa";
	texturePressedChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa";
	texturePressedUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa";
	textureDisabledChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa";
	textureDisabledUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa";
	soundClick[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.09,
		1
	};
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.09,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.09,
		1
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onCheckedChanged = "";
};
class ctrlCheckboxBaseline: ctrlCheckbox
{
	textureChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa";
	textureUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa";
	textureFocusedChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa";
	textureFocusedUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa";
	textureHoverChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa";
	textureHoverUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa";
	texturePressedChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa";
	texturePressedUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa";
	textureDisabledChecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa";
	textureDisabledUnchecked = "\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa";
};
class ctrlDefaultText: ctrlDefault
{
	sizeEx = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	font = "RobotoCondensedLight";
	shadow = 1;
};
class ctrlDefaultButton: ctrlDefaultText
{
	soundClick[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.09,
		1
	};
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.09,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.09,
		1
	};
};
class ctrlActiveText: ctrlDefaultButton
{
	type = CT_ACTIVETEXT;
	text = "";
	color[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		0.75
	};
	colorActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorDisabled[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onButtonClick = "";
	onButtonDown = "";
	onButtonUp = "";
};
class ctrlActivePicture: ctrlActiveText
{
	style = ST_MULTI + ST_TITLE_BAR;
	color[] = {1,1,1,1};
};
class ctrlStatic: ctrlDefaultText
{
	type = CT_STATIC;
	colorBackground[] = {0,0,0,0};
	text = "";
	lineSpacing = 1;
	fixedWidth = 0;
	colorText[] = {1,1,1,1};
	colorShadow[] = {0,0,0,1};
	moving = 0;
	autoplay = 0;
	loops = 0;
	tileW = 1;
	tileH = 1;
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onVideoStopped = "";
};
class ctrlControlsGroup: ctrlDefault
{
	type = CT_CONTROLS_GROUP;
	style = ST_MULTI;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	class VScrollBar: ScrollBar
	{
		width = 2 * GRID_W;
		height = 0;
		autoScrollEnabled = 0;
		autoScrollDelay = 1;
		autoScrollRewind = 1;
		autoScrollSpeed = 1;
	};
	class HScrollBar: ScrollBar
	{
		width = 0;
		height = 2 * GRID_H;
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
};
class ctrlControlsGroupNoScrollbars: ctrlControlsGroup
{
	class VScrollbar: VScrollBar
	{
		width = 0;
	};
	class HScrollbar: HScrollBar
	{
		height = 0;
	};
};
class ctrlStructuredText: ctrlDefaultText
{
	type = CT_STRUCTURED_TEXT;
	colorBackground[] = {0,0,0,0};
	size = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	text = "";
	class Attributes
	{
		align = "left";
		color = "#ffffff";
		colorLink = "#0000ff";
		size = 1;
		font = "RobotoCondensedLight";
	};
	onCanDestroy = "";
	onDestroy = "";
};
class RscTextMulti: RscText
{
	style = ST_MULTI;
};
class RscTreeSearch: RscTree
{
	idcSearch = 645;
};
class RscPictureAllowPixelSplit: RscPicture
{
	pixelPrecise = 0;
};
class RscPictureKeepAspectAllowPixelSplit: RscPictureAllowPixelSplit
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class RscVideo: RscPicture
{
	autoplay = 1;
	loops = 1;
};
class RscVideoKeepAspect: RscPictureKeepAspect
{
	autoplay = 1;
	loops = 1;
};
class RscActivePictureKeepAspect: RscActivePicture
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class RscEditMulti: RscEdit
{
	style = ST_MULTI;
};
class RscMapSignalBackground: RscText
{
	colorBackground[] = {0.1,0.1,0.1,0.8};
	x = 12.5 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2);
	y = 10 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2);
	w = 15.5 * GUI_GRID_W;
	h = 5 * GUI_GRID_H;
};
class RscMapSignalPicture: RscPicture
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"
	};
	text = "\A3\ui_f\data\map\diary\signal_ca.paa";
	x = 19 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2);
	y = 10.5 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2);
	w = 2 * GUI_GRID_W;
	h = 2 * GUI_GRID_H;
};
class RscMapSignalText: RscText
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",
		"(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"
	};
	style = ST_CENTER;
	text = "Cannot connect to the positioning system.";
	x = 13 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2);
	y = 13.5 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2);
	w = 14.5 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	sizeEx = 0.8 * GUI_GRID_H;
};
class RscColorPicker: RscControlsGroupNoScrollbars
{
	class controls
	{
	};
	idc = 2351;
	x = -1;
	y = -1;
	w = 0;
	h = 0;
};
class RscInterlacingScreen: RscPicture
{
	text = "a3\ui_f\data\igui\rsctitles\interlacing\interlacing_ca.paa";
	x = "safeZoneX";
	y = "safeZoneY";
	w = "safeZoneW";
	h = "safeZoneH";
};
class RscFeedback: RscHTML
{
	colorBackground[] = {0.67451,0.290196,0.290196,1};
	colorLink[] = {1,1,1,1};
	colorLinkActive[] = {1,1,1,1};
	class P
	{
		font = "RobotoCondensedBold";
		fontBold = "RobotoCondensedBold";
		sizeEx = GUI_TEXT_SIZE_MEDIUM;
		align = "center";
	};
	idc = 6455;
	x = 1 * GUI_GRID_W + GUI_GRID_X;
	y = "safezoneY";
	w = 15 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	shadow = 0;
};
class RscTrafficLight: RscActiveText
{
	color[] = {1,1,1,0.7};
	colorText[] = {1,1,1,0.7};
	colorActive[] = {1,1,1,1};
	style = ST_MULTI + ST_TITLE_BAR;
	text = "\A3\Ui_f\data\GUI\RscCommon\RscTrafficLight\TrafficLight_ca.paa";
	tooltip = "You are running a modded version of the game. Click to see the list of active mods.";
	x = SafezoneX + SafezoneW - (2 * GUI_GRID_W);
	y = 23 * GUI_GRID_H + GUI_GRID_Y;
	w = 1 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
};
class RscButtonSearch: RscButton
{
	idc = 646;
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
	text = "\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_start_ca.paa";
	textSearch = "\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_end_ca.paa";
	tooltip = "Search";
	onButtonClick = "_display = ctrlparent (_this select 0);_ctrlSearch = _display displayctrl 645;_ctrlSearch ctrlsettext '';ctrlsetfocus _ctrlSearch;";
};
class RscIGUIText: RscText
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
	};
	sizeEx = GUI_TEXT_SIZE_SMALL;
	style = ST_LEFT;
};
class RscOpticsText: RscText
{
	colorText[] = {0.95,0.95,0.95,1};
	sizeEx = 0.048;
	style = ST_LEFT;
	h = 0.048;
};
class RscOpticsValue: RscOpticsText
{
	fixedWidth = 1;
};
class RscIGUIValue: RscIGUIText
{
	colorText[] =
	{
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"
	};
	sizeEx = GUI_TEXT_SIZE_SMALL;
	style = ST_LEFT;
};
class RscButtonMenuMain: RscButtonMenu
{
	size = "(pixelH * pixelGrid * 2)";
	style = ST_FRAME + ST_HUD_BACKGROUND;
	colorBackground[] = {1,1,1,0.75};
	colorBackgroundFocused[] = {1,1,1,1};
	colorBackground2[] = {1,1,1,1};
	class Attributes
	{
		align = "left";
		color = "#ffffff";
		font = "PuristaLight";
	};
	class TextPos
	{
		left = "0.1 * 1.5 * (pixelW * pixelGrid * 2)";
		top = "0.1 * 1.5 * (pixelH * pixelGrid * 2)";
		right = "0.1 * 1.5 * (pixelW * pixelGrid * 2)";
		bottom = "0.1 * 1.5 * (pixelH * pixelGrid * 2)";
	};
	animTextureNormal = "#(argb,8,8,3)color(0,0,0,1)";
	animTextureDisabled = "#(argb,8,8,3)color(0,0,0,1)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed = "#(argb,8,8,3)color(0,0,0,1)";
	animTextureDefault = "#(argb,8,8,3)color(0,0,0,1)";
};
class RscButtonTestCentered: RscButton
{
	style = ST_CENTER + ST_MULTI;
	text = "Line 1\nLine 2";
	shadow = 1;
	x = 0;
	y = 0;
	w = "10 * (pixelW * pixelGrid * 2)";
	h = "10 * (pixelH * pixelGrid * 2)";
};
class RscDisplaySingleMission_ChallengeOverviewGroup: RscControlsGroupNoHScrollbars
{
	idc = 2302;
	x = 17 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2);
	y = SafezoneY + (18.4 * GUI_GRID_H) + (0.5 * (safezoneH - GUI_GRID_HAbs));
	w = 22 * GUI_GRID_W;
	h = 3.5 * GUI_GRID_H + (0.5 * (safezoneH - GUI_GRID_HAbs));
	class controls
	{
	};
};
class RscDisplayDebriefing_RscTextMultiline: RscText
{
	style = ST_MULTI + ST_NO_RECT;
};
class RscDisplayDebriefing_ListGroup: RscControlsGroupNoHScrollbars
{
	idc = 21903;
	x = 2.2 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2);
	y = 8.9 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2);
	w = 36.8 * GUI_GRID_W;
	h = 12.2 * GUI_GRID_H;
	class controls
	{
	};
};
class RscButtonArsenal: RscButton
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
	colorBackground[] = {0,0,0,0.8};
	colorDisabled[] = {1,1,1,1};
};
class RscTextNoShadow: RscText
{
	style = ST_CENTER;
	shadow = 0;
};
class RscButtonNoColor: RscButton
{
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	colorFocused[] = {0,0,0,0};
	text = "";
	soundEnter[] =
	{
		"\A3\ui_f\data\sound\ReadOut\readoutClick",
		0.5,
		1
	};
	soundPush[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundClick[] =
	{
		"\A3\ui_f\data\sound\CfgNotifications\addItemOK",
		0.5,
		1
	};
	soundEscape[] =
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
};
class ctrlStaticPicture: ctrlStatic
{
	style = ST_MULTI + ST_TITLE_BAR;
};
class ctrlStaticPictureKeepAspect: ctrlStaticPicture
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class ctrlStaticPictureTile: ctrlStatic
{
	style = ST_MULTI + ST_HUD_BACKGROUND;
};
class ctrlStaticFrame: ctrlStatic
{
	style = ST_FRAME;
};
class ctrlStaticLine: ctrlStatic
{
	style = ST_MULTI + ST_TITLE_BAR + ST_HUD_BACKGROUND;
};
class ctrlStaticMulti: ctrlStatic
{
	style = ST_MULTI + ST_NO_RECT;
};
class ctrlStaticBackground: ctrlStatic
{
	colorBackground[] = {0.2,0.2,0.2,1};
};
class ctrlStaticOverlay: ctrlStatic
{
	colorBackground[] = {0,0,0,0.5};
};
class ctrlStaticTitle: ctrlStatic
{
	moving = 1;
	colorBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[] = {1,1,1,1};
};
class ctrlStaticFooter: ctrlStatic
{
	colorBackground[] = {0,0,0,0.3};
};
class ctrlStaticBackgroundDisable: ctrlStatic
{
	x = -4;
	y = -2;
	w = 8;
	h = 4;
	colorBackground[] = {1,1,1,0.5};
};
class ctrlStaticBackgroundDisableTiles: ctrlStaticPictureTile
{
	x = -4;
	y = -2;
	w = 8;
	h = 4;
	text = "\a3\3DEN\Data\Displays\Display3DENEditAttributes\backgroundDisable_ca.paa";
	tileW = "8 / (32 * pixelW)";
	tileH = "4 / (32 * pixelH)";
	colorText[] = {1,1,1,0.05};
};
class ctrlButton: ctrlDefaultButton
{
	type = CT_BUTTON;
	style = ST_CENTER + ST_FRAME + ST_HUD_BACKGROUND;
	colorBackground[] = {0,0,0,1};
	colorBackgroundDisabled[] = {0,0,0,0.5};
	colorBackgroundActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorFocused[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	font = "PuristaLight";
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	borderSize = 0;
	colorBorder[] = {0,0,0,0};
	colorShadow[] = {0,0,0,0};
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = "pixelW";
	offsetPressedY = "pixelH";
	period = 0;
	periodFocus = 2;
	periodOver = 0.5;
	class KeyHints
	{
		class A
		{
			key = "0x00050000 + 0";
			hint = "KEY_XBOX_A";
		};
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onButtonClick = "";
	onButtonDown = "";
	onButtonUp = "";
};
class ctrlButtonPicture: ctrlButton
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR;
};
class ctrlButtonPictureKeepAspect: ctrlButton
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class ctrlButtonOK: ctrlButton
{
	default = 1;
	idc = 1;
	text = "OK";
};
class ctrlButtonCancel: ctrlButton
{
	idc = 2;
	text = "Cancel";
};
class ctrlButtonClose: ctrlButtonCancel
{
	text = "Close";
};
class ctrlButtonToolbar: ctrlButtonPictureKeepAspect
{
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
};
class ctrlButtonSearch: ctrlButton
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
	text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
	textSearch = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
	tooltip = "Search";
};
class ctrlButtonExpandAll: ctrlButtonToolbar
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
	text = "\a3\3DEN\Data\Displays\Display3DEN\tree_expand_ca.paa";
	tooltip = "Expand All";
};
class ctrlButtonCollapseAll: ctrlButtonToolbar
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
	text = "\a3\3DEN\Data\Displays\Display3DEN\tree_collapse_ca.paa";
	tooltip = "Collapse All";
};
class ctrlButtonFilter: ctrlButton
{
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {1,1,1,0.3};
	colorFocused[] = {0,0,0,0};
};
class ctrlEdit: ctrlDefaultText
{
	type = CT_EDIT;
	colorBackground[] = {0,0,0,0.5};
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelection[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	canModify = 1;
	autocomplete = "";
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
};
class ctrlEditMulti: ctrlEdit
{
	style = ST_MULTI;
};
class ctrlSliderV: ctrlDefault
{
	type = CT_SLIDER;
	style = SL_VERT;
	color[] = {0,0,0,1};
	colorDisabled[] = {1,1,1,0.25};
	colorActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	sliderRange[] = {0,1};
	sliderPosition = 1;
	lineSize = 0.1;
	pageSize = 3;
	class Title
	{
		idc = -1;
		colorBase[] = {1,1,1,1};
		colorActive[] =
		{
			"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
			1
		};
	};
	class Value
	{
		idc = -1;
		format = "%.f";
		type = CT_STATIC;
		colorBase[] = {1,1,1,1};
		colorActive[] =
		{
			"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
			1
		};
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onSliderPosChanged = "";
};
class ctrlSliderH: ctrlSliderV
{
	style = SL_HORZ;
};
class ctrlCombo: ctrlDefaultText
{
	type = CT_COMBO;
	style = ST_MULTI + ST_NO_RECT;
	colorBackground[] = {0.05,0.05,0.05,1};
	colorSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {0,0,0,1};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {1,1,1,0.25};
	colorSelect2Right[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmpty_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowFull_ca.paa";
	wholeHeight = 12 * 5 * UI_GRID_H;
	maxHistoryDelay = 1;
	soundExpand[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundExpand",
		0.1,
		1
	};
	soundCollapse[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundCollapse",
		0.1,
		1
	};
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscCombo\soundSelect",
		0.1,
		1
	};
	class ComboScrollBar
	{
		width = 0;
		height = 0;
		scrollSpeed = 0.01;
		arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[] = {1,1,1,1};
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
};
class ctrlComboToolbar: ctrlCombo
{
	colorBackground[] = {0.05,0.05,0.05,1};
	colorSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmptyToolbar_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmptyToolbar_ca.paa";
	wholeHeight = 12 * 5 * GRID_H;
};
class ctrlListbox: ctrlDefaultText
{
	type = CT_LISTBOX;
	style = LB_TEXTURES;
	colorBackground[] = {0,0,0,0.5};
	colorSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorSelectBackground2[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorShadow[] = {0,0,0,0.5};
	colorDisabled[] = {1,1,1,0.25};
	colorText[] = {1,1,1,1};
	colorSelect[] = {1,1,1,1};
	colorSelect2[] = {1,1,1,1};
	colorTextRight[] = {1,1,1,1};
	colorSelectRight[] = {1,1,1,1};
	colorSelect2Right[] = {1,1,1,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	period = 1;
	rowHeight = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	itemSpacing = 0;
	maxHistoryDelay = 1;
	canDrag = 0;
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	class ListScrollBar: ScrollBar
	{
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
	onLBDblClick = "";
	onLBDrag = "";
	onLBDragging = "";
	onLBDrop = "";
};
class ctrlToolbox: ctrlDefaultText
{
	type = CT_TOOLBOX;
	style = ST_CENTER;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	colorTextSelect[] = {1,1,1,1};
	rows = 1;
	columns = 1;
	strings[] = {};
	values[] = {};
	color[] = {1,0,1,1};
	colorSelect[] = {0,0,0,0};
	colorTextDisable[] = {0,0,0,0};
	colorDisable[] = {0,0,0,0};
	colorSelectedBg[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onToolBoxSelChanged = "";
};
class ctrlToolboxPicture: ctrlToolbox
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR;
};
class ctrlToolboxPictureKeepAspect: ctrlToolbox
{
	style = ST_CENTER + ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class ctrlCheckboxes: ctrlDefaultText
{
	type = CT_CHECKBOXES;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	colorTextSelect[] = {1,1,1,1};
	rows = 1;
	columns = 1;
	strings[] = {};
	checked_strings[] = {};
	color[] = {1,0,1,1};
	colorSelect[] = {0,0,0,0};
	colorTextDisable[] = {0,0,0,0};
	colorDisable[] = {0,0,0,0};
	colorSelectedBg[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onCheckBoxesSelChanged = "";
};
class ctrlCheckboxesCheckbox: ctrlCheckboxes
{
	style = ST_MULTI + ST_TITLE_BAR;
	strings[] =
	{
		"\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa"
	};
	checked_strings[] =
	{
		"\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa"
	};
	colorBackground[] = {0,0,0,0};
	colorSelectedBg[] = {0,0,0,0};
};
class ctrlProgress: ctrlDefault
{
	type = CT_PROGRESS;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
	colorBar[] = {1,1,1,1};
	colorFrame[] = {0,0,0,1};
	onCanDestroy = "";
	onDestroy = "";
};
class ctrlHTML: ctrlDefaultText
{
	type = CT_HTML;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	colorBold[] = {1,1,1,0.5};
	colorLink[] = {1,1,1,1};
	colorLinkActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorPicture[] = {1,1,1,1};
	colorPictureBorder[] = {0,0,0,0};
	colorPictureLink[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	prevPage = "\a3\3DEN\Data\Controls\CtrlHTML\prevPage_ca.paa";
	nextPage = "\a3\3DEN\Data\Controls\CtrlHTML\nextPage_ca.paa";
	filename = "";
	cycleLinks = 0;
	cycleAllLinks = 0;
	class P
	{
		font = "RobotoCondensedLight";
		fontBold = "RobotoCondensedBold";
		sizeEx = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	};
	class H1: P
	{
		sizeEx = "5.58 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	};
	class H2: P
	{
		sizeEx = "4.86 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	};
	class H3: P
	{
	};
	class H4: P
	{
	};
	class H5: P
	{
	};
	class H6: P
	{
		font = "RobotoCondensedLight";
		fontBold = "RobotoCondensedLight";
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onHTMLLink = "";
};
class ctrlActivePictureKeepAspect: ctrlActiveText
{
	style = ST_MULTI + ST_TITLE_BAR + ST_KEEP_ASPECT_RATIO;
};
class ctrlTree: ctrlDefaultText
{
	type = CT_TREE;
	colorBorder[] = {0,0,0,1};
	colorLines[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorSelect[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorMarked[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		0.5
	};
	colorMarkedSelected[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {1,1,1,1};
	colorMarkedText[] = {1,1,1,1};
	colorSearch[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	multiselectEnabled = 0;
	expandOnDoubleclick = 1;
	hiddenTexture = "\a3\3DEN\Data\Controls\ctrlTree\hiddenTexture_ca.paa";
	expandedTexture = "\a3\3DEN\Data\Controls\ctrlTree\expandedTexture_ca.paa";
	maxHistoryDelay = 1;
	disableKeyboardSearch = 0;
	class ScrollBar: ScrollBar
	{
		scrollSpeed = 0.05;
	};
	colorDisabled[] = {0,0,0,0};
	colorArrow[] = {0,0,0,0};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onTreeSelChanged = "";
	onTreeLButtonDown = "";
	onTreeDblClick = "";
	onTreeExpanded = "";
	onTreeCollapsed = "";
	onTreeMouseExit = "";
};
class ctrlControlsGroupNoHScrollbars: ctrlControlsGroup
{
	class HScrollbar: HScrollBar
	{
		height = 0;
	};
};
class ctrlControlsGroupNoVScrollbars: ctrlControlsGroup
{
	class VScrollbar: VScrollBar
	{
		width = 0;
	};
};
class ctrlShortcutButton: ctrlDefaultButton
{
	type = CT_SHORTCUTBUTTON;
	style = ST_FRAME + ST_HUD_BACKGROUND;
	colorBackground[] = {0,0,0,1};
	colorBackground2[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorBackgroundFocused[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorBackgroundActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	text = "";
	size = "4.86 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	shadow = 0;
	color[] = {1,1,1,1};
	color2[] = {1,1,1,1};
	colorFocused[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
	period = 1;
	periodFocus = 1;
	periodOver = 0.5;
	shortcuts[] =
	{
		"0x00050000 + 0",
		28,
		57,
		156
	};
	textureNoShortcut = "#(argb,8,8,3)color(1,1,1,1)";
	class Attributes
	{
		align = "center";
		color = "#ffffff";
		font = "PuristaLight";
		shadow = 0;
	};
	class HitZone
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class TextPos
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0;
		top = 0;
		w = 0;
		h = 0;
	};
	onCanDestroy = "";
	onDestroy = "";
	onMouseEnter = "";
	onMouseExit = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onButtonClick = "";
	onButtonDown = "";
	onButtonUp = "";
};
class ctrlShortcutButtonOK: ctrlShortcutButton
{
	default = 1;
	idc = 1;
	text = "OK";
};
class ctrlShortcutButtonCancel: ctrlShortcutButton
{
	idc = 2;
	text = "Cancel";
};
class ctrlShortcutButtonSteam: ctrlShortcutButton
{
	colorBackground[] = {0.0313726,0.721569,0.917647,1};
	textureNoShortcut = "\a3\3DEN\Data\Controls\CtrlShortcutButton\steam_ca.paa";
	class TextPos
	{
		left = 1.5 * 5 * GRID_W;
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0;
		top = 0;
		w = 5 * GRID_W;
		h = 5 * GRID_H;
	};
};
class ctrlXListbox: ctrlDefaultText
{
	type = CT_XLISTBOX;
	style = ST_CENTER + LB_TEXTURES + SL_HORZ;
	color[] = {1,1,1,1};
	colorActive[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[] = {1,1,1,1};
	colorSelect[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	cycle = 1;
	arrowEmpty = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowEmpty_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowFull_ca.paa";
	border = "\a3\3DEN\Data\Controls\CtrlXSlider\border_ca.paa";
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
	onLBDblClick = "";
};
class ctrlXSliderV: ctrlDefault
{
	type = CT_XSLIDER;
	style = SL_VERT;
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	sliderRange[] = {0,1};
	sliderPosition = 1;
	lineSize = 0.1;
	arrowEmpty = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowEmpty_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowFull_ca.paa";
	border = "\a3\3DEN\Data\Controls\CtrlXSlider\border_ca.paa";
	thumb = "\a3\3DEN\Data\Controls\CtrlXSlider\thumb_ca.paa";
	class Title
	{
		idc = -1;
		colorBase[] = {1,1,1,1};
		colorActive[] =
		{
			"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
			1
		};
	};
	class Value
	{
		idc = -1;
		format = "%.f";
		type = CT_STATIC;
		colorBase[] = {1,1,1,1};
		colorActive[] =
		{
			"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
			"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
			1
		};
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onSliderPosChanged = "";
};
class ctrlXSliderH: ctrlXSliderV
{
	style = SL_HORZ;
};
class ctrlMenu: ctrlDefaultText
{
	type = 46;
	font = "RobotoCondensedLight";
	colorBorder[] = {0,0,0,0};
	colorBackground[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorSelect[] = {0,0,0,1};
	colorSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelect[] = {0,0,0,1};
	colorPictureDisabled[] = {1,1,1,0.5};
	arrow = "\a3\3DEN\Data\Controls\ctrlMenu\arrow_ca.paa";
	rowHeight = 0;
	itemSpacingW = 0.01;
	itemSpacingH = 0.01;
	pictureCheckboxEnabled = "\a3\3DEN\Data\Controls\CtrlMenu\pictureCheckboxEnabled_ca.paa";
	pictureCheckboxDisabled = "#(argb,8,8,3)color(0,0,0,0)";
	pictureRadioEnabled = "\a3\3DEN\Data\Controls\CtrlMenu\pictureRadioEnabled_ca.paa";
	pictureRadioDisabled = "#(argb,8,8,3)color(0,0,0,0)";
};
class ctrlMenuStrip: ctrlMenu
{
	type = 47;
	colorStripBackground[] = {0,0,0,1};
	colorStripText[] = {1,1,1,1};
	colorStripSelect[] = {0,0,0,1};
	colorStripSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorStripDisabled[] = {1,1,1,0.25};
};
class ctrlMap: ctrlDefault
{
	type = CT_MAP_MAIN;
	style = ST_MULTI + ST_TITLE_BAR;
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	sizeEx = 0.05;
	font = "RobotoCondensedLight";
	colorText[] = {0,0,0,1};
	moveOnEdges = 1;
	ptsPerSquareSea = 5;
	ptsPerSquareTxt = 20;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = 9;
	ptsPerSquareForEdge = 9;
	ptsPerSquareObj = 9;
	ptsPerSquareForLod1 = 4;
	ptsPerSquareForLod2 = 1;
	ptsPerSquareRoad = 6;
	ptsPerSquareMainRoad = 6;
	ptsPerSquareRoadSimple = 1;
	ptsPerSquareMainRoadSimple = 1;
	drawShaded = 0.25;
	runwayFont = "LCD14";
	scaleMin = 0.0001;
	scaleMax = 1;
	scaleDefault = 0.16;
	maxSatelliteAlpha = 0.85;
	alphaFadeStartScale = 2;
	alphaFadeEndScale = 2;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	colorBackground[] = {0.969,0.957,0.949,1};
	colorOutside[] = {0,0,0,1};
	colorSea[] = {0.467,0.631,0.851,0.5};
	colorForest[] = {0.624,0.78,0.388,0.5};
	colorForestTextured[] = {0.624,0.78,0.388,0.25};
	colorForestBorder[] = {0,0,0,0.5};
	colorRocks[] = {0,0,0,0.3};
	colorRocksBorder[] = {0,0,0,0};
	colorLevels[] = {0.286,0.177,0.094,0.5};
	colorMainCountlines[] = {0.572,0.354,0.188,0.5};
	colorCountlines[] = {0.572,0.354,0.188,0.25};
	colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
	colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
	colorPowerLines[] = {0.1,0.1,0.1,1};
	colorRailWay[] = {0.8,0.2,0,1};
	colorNames[] = {0.1,0.1,0.1,0.9};
	colorInactive[] = {1,1,1,0.5};
	colorTracks[] = {0.84,0.76,0.65,0.15};
	colorTracksFill[] = {0.84,0.76,0.65,1};
	colorRoads[] = {0.7,0.7,0.7,1};
	colorRoadsFill[] = {1,1,1,1};
	colorMainRoads[] = {0.9,0.5,0.3,1};
	colorMainRoadsFill[] = {1,0.6,0.4,1};
	colorTrails[] = {0.84,0.76,0.65,0.15};
	colorTrailsFill[] = {0.84,0.76,0.65,0.65};
	colorGrid[] = {0.1,0.1,0.1,0.6};
	colorGridMap[] = {0.1,0.1,0.1,0.6};
	fontLabel = "RobotoCondensedLight";
	sizeExLabel = 0.05;
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = 0.05;
	fontNames = "EtelkaNarrowMediumPro";
	sizeExNames = 0.05;
	fontInfo = "RobotoCondensedLight";
	sizeExInfo = 0.05;
	fontLevel = "TahomaB";
	sizeExLevel = 0.02;
	showCountourInterval = 1;
	idcMarkerColor = -1;
	idcMarkerIcon = -1;
	textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
	showMarkers = "true";
	class LineMarker
	{
		lineWidthThin = 0.008;
		lineWidthThick = 0.014;
		lineDistanceMin = 3e-005;
		lineLengthMin = 5;
	};
	class Legend
	{
		x = 0.5;
		y = 0.5;
		w = 0.4;
		h = 0.1;
		color[] = {0,0,0,1};
		colorBackground[] = {1,1,1,0.5};
		font = "RobotoCondensedLight";
		sizeEX = "3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	};
	class Task
	{
		icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
		color[] = {1,1,1,1};
		iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
		colorCreated[] = {1,1,0,1};
		iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
		colorCanceled[] = {0.7,0.7,0.7,1};
		iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
		colorDone[] = {0.7,1,0.3,1};
		iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
		colorFailed[] = {1,0.3,0.2,1};
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class ActiveMarker
	{
		color[] = {0,0,0,1};
		size = 2;
	};
	class Waypoint
	{
		coefMax = 1;
		coefMin = 1;
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		importance = 1;
		size = 24;
	};
	class WaypointCompleted: Waypoint
	{
		icon = "\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
	};
	class CustomMark: Waypoint
	{
		icon = "\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
	};
	class Command: Waypoint
	{
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
		size = 18;
	};
	class Bush: Waypoint
	{
		coefMax = 4;
		coefMin = 0.25;
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.007;
		size = 7;
	};
	class SmallTree: Bush
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.36;
		size = 12;
	};
	class Tree: SmallTree
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
		importance = 0.72;
	};
	class Rock: SmallTree
	{
		color[] = {0.1,0.1,0.1,0.8};
		icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
		importance = 0.3;
	};
	class BusStop: Bush
	{
		color[] = {0.45,0.64,0.33,0.4};
		icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
	};
	class FuelStation: Waypoint
	{
		coefMax = 1;
		coefMin = 0.85;
		color[] = {1,1,1,1};
		icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
	};
	class Hospital: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
	};
	class Church: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
	};
	class Lighthouse: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
	};
	class Power: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
	};
	class PowerSolar: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
	};
	class PowerWave: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
	};
	class PowerWind: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
	};
	class Quay: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
	};
	class Transmitter: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
	};
	class Watertower: FuelStation
	{
		icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
	};
	class Cross: Waypoint
	{
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
	};
	class Chapel: Cross
	{
		icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
	};
	class Shipwreck: Cross
	{
		icon = "\A3\ui_f\data\map\mapcontrol\Shipwreck_CA.paa";
	};
	class Bunker: Waypoint
	{
		coefMax = 4;
		coefMin = 0.25;
		color[] = {0,0,0,1};
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		importance = 1.05;
		size = 14;
	};
	class Fortress: Bunker
	{
		icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
		importance = 1.6;
		size = 16;
	};
	class Fountain: Bunker
	{
		icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
		importance = 0.6;
		size = 11;
	};
	class Ruin: Waypoint
	{
		coefMax = 4;
		coefMin = 1;
		icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
		importance = 0.96;
		size = 16;
	};
	class Stack: Waypoint
	{
		coefMax = 2;
		coefMin = 0.4;
		icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
		importance = 1.6;
		size = 16;
	};
	class Tourism: Waypoint
	{
		coefMax = 4;
		coefMin = 0.7;
		icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
		importance = 2.8;
		size = 16;
	};
	class ViewTower: Waypoint
	{
		coefMax = 4;
		coefMin = 0.5;
		icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
		importance = 2;
		size = 16;
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onDraw = "";
};
class ctrlMapEmpty: ctrlMap
{
	ptsPerSquareSea = 1000;
	ptsPerSquareTxt = 1000;
	ptsPerSquareCLn = 1000;
	ptsPerSquareExp = 1000;
	ptsPerSquareCost = 1000;
	ptsPerSquareFor = 1000;
	ptsPerSquareForEdge = 1000;
	ptsPerSquareRoad = 1000;
	ptsPerSquareObj = 1000;
	alphaFadeStartScale = 0;
	alphaFadeEndScale = 0;
	colorBackground[] = {1,1,1,1};
	colorOutside[] = {1,1,1,1};
	colorSea[] = {0,0,0,0};
	colorForest[] = {0,0,0,0};
	colorForestBorder[] = {0,0,0,0};
	colorRocks[] = {0,0,0,0};
	colorRocksBorder[] = {0,0,0,0};
	colorLevels[] = {0,0,0,0};
	colorMainCountlines[] = {0,0,0,0};
	colorCountlines[] = {0,0,0,0};
	colorMainCountlinesWater[] = {0,0,0,0};
	colorCountlinesWater[] = {0,0,0,0};
	colorPowerLines[] = {0,0,0,0};
	colorRailWay[] = {0,0,0,0};
	colorNames[] = {0,0,0,0};
	colorInactive[] = {0,0,0,0};
	colorGrid[] = {0,0,0,0};
	colorGridMap[] = {0,0,0,0};
	class Task: Task
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		iconCreated = "#(argb,8,8,3)color(0,0,0,0)";
		iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
		iconDone = "#(argb,8,8,3)color(0,0,0,0)";
		iconFailed = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		colorCreated[] = {0,0,0,0};
		colorCanceled[] = {0,0,0,0};
		colorDone[] = {0,0,0,0};
		colorFailed[] = {0,0,0,0};
		size = 0;
	};
	class Waypoint: Waypoint
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class WaypointCompleted: WaypointCompleted
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class CustomMark: CustomMark
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Command: Command
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Bush: Bush
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Rock: Rock
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class SmallTree: SmallTree
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Tree: Tree
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class busstop: BusStop
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class fuelstation: FuelStation
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class hospital: Hospital
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class church: Church
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class lighthouse: Lighthouse
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class power: Power
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powersolar: PowerSolar
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powerwave: PowerWave
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powerwind: PowerWind
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class quay: Quay
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class shipwreck: Shipwreck
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class transmitter: Transmitter
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class watertower: Watertower
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Bunker: Bunker
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Cross: Cross
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Fortress: Fortress
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Fountain: Fountain
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Chapel: Chapel
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Ruin: Ruin
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Stack: Stack
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class Tourism: Tourism
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class ViewTower: ViewTower
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
};
class ctrlMapMain: ctrlMap
{
};
class ctrlListNBox: ctrlDefaultText
{
	type = CT_LISTNBOX;
	style = ST_MULTI;
	colorSelectBackground[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorSelectBackground2[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {1,1,1,1};
	colorSelect2[] = {1,1,1,1};
	colorShadow[] = {0,0,0,0.5};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	columns[] = {0};
	drawSideArrows = 0;
	idcLeft = -1;
	idcRight = -1;
	period = 1;
	disableOverflow = 0;
	rowHeight = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	maxHistoryDelay = 1;
	soundSelect[] =
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	class ListScrollBar: ScrollBar
	{
	};
	onCanDestroy = "";
	onDestroy = "";
	onSetFocus = "";
	onKillFocus = "";
	onKeyDown = "";
	onKeyUp = "";
	onMouseButtonDown = "";
	onMouseButtonUp = "";
	onMouseButtonClick = "";
	onMouseButtonDblClick = "";
	onMouseZChanged = "";
	onMouseMoving = "";
	onMouseHolding = "";
	onLBSelChanged = "";
	onLBDblClick = "";
};
class ctrlCheckboxToolbar: ctrlCheckbox
{
	color[] = {1,1,1,1};
	colorBackgroundHover[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorBackgroundPressed[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
};
class RscControlsTable
{
	idc=-1;
	x=0;
	y=0;
	w=1;
	h=1;
	type=19;
	style=16;
	lineSpacing=0;
	rowHeight="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	headerHeight="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	firstIDC=-1;
	lastIDC=-1;
	selectedRowColorFrom[]={0.69999999,0.85000002,1,0.25};
	selectedRowColorTo[]={0.69999999,0.85000002,1,0.5};
	selectedRowAnimLength=1.2;
	class VScrollBar: ScrollBar
	{
		width=0.021;
	};
	class HScrollBar: ScrollBar
	{
		height=0.028000001;
	};
	class RowTemplate
	{
	};
	class HeaderTemplate
	{
	};
};
#endif
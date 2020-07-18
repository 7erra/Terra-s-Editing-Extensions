class RscText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 1;
	colorShadow[] = {0,0,0,0.5};
	font = "RobotoCondensed";
	SizeEx = "GUI_TEXT_SIZE_SMALL";
	linespacing = 1;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
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
	style = 0;
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	colorText[] = {0.95,0.95,0.95,1};
	font = "PuristaMedium";
};
class RscProgress
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 8;
	style = 0;
	colorFrame[] = {0,0,0,0};
	colorBar[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
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
	type = 45;
	style = 0;
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
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	fixedWidth = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};
class RscLadderPicture: RscPicture
{
	bottomValue = 0;
	topValue = 100;
	visibleRange = -1;
};
class RscPictureKeepAspect: RscPicture
{
	style = "0x30 + 0x800";
};
class RscHTML
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 9;
	idc = -1;
	style = 0;
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
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	class H2
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "right";
	};
	class H3
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	class H4
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	class H5
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	class H6
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	class P
	{
		font = "RobotoCondensed";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "left";
	};
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.1;
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	prevPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
	nextPage = "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
	shadow = 2;
};
class RscButton
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 1;
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {0,0,0,0.5};
	colorBackgroundDisabled[] = {0,0,0,0.5};
	colorBackgroundActive[] = {0,0,0,1};
	colorFocused[] = {0,0,0,1};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	idc = -1;
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
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
	type = 16;
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
		top = "((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_SMALL) / 2";
		w = "GUI_TEXT_SIZE_SMALL * (3/4)";
		h = "GUI_TEXT_SIZE_SMALL";
	};
	class TextPos
	{
		left = "GUI_TEXT_SIZE_SMALL * (3/4)";
		top = "((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_SMALL) / 2";
		right = 0.005;
		bottom = 0;
	};
	shortcuts[] = {};
	textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";
	color[] = {1,1,1,1};
	colorFocused[] = {1,1,1,1};
	color2[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
	colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
	colorBackground2[] = {1,1,1,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	idc = -1;
	style = 0;
	default = 0;
	shadow = 1;
	w = 0.183825;
	h = "(GUI_GRID_HAbs / 20)";
	textSecondary = "";
	colorSecondary[] = {1,1,1,1};
	colorFocusedSecondary[] = {1,1,1,1};
	color2Secondary[] = {0.95,0.95,0.95,1};
	colorDisabledSecondary[] = {1,1,1,0.25};
	sizeExSecondary = "GUI_TEXT_SIZE_SMALL";
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
	size = "GUI_TEXT_SIZE_SMALL";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	text = "";
	url = "";
	action = "";
	class AttributesImage
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "left";
	};
};
class RscButtonSmall: RscButton
{
	w = 0.12;
};
class RscEdit
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 2;
	x = 0;
	y = 0;
	h = 0.04;
	w = 0.2;
	colorBackground[] = {0,0,0,0};
	colorText[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
	autocomplete = "";
	text = "";
	size = 0.2;
	style = "0x00 + 0x40";
	font = "RobotoCondensed";
	shadow = 2;
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	canModify = 1;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};
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
class RscCombo
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 4;
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
	soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
	soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
	soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
	maxHistoryDelay = 1;
	class ComboScrollBar: ScrollBar
	{
		color[] = {1,1,1,1};
	};
	style = "0x10 + 0x200";
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.12;
	h = 0.035;
	colorSelectBackground[] = {1,1,1,0.7};
	arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	colorActive[] = {1,0,0,1};
};
class RscListBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 5;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorScrollbar[] = {1,0,0,0};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,0.3};
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
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
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	style = 16;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	shadow = 0;
	colorShadow[] = {0,0,0,0.5};
	period = 1.2;
	maxHistoryDelay = 1;
};
class RscListNBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 102;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,1};
	maxHistoryDelay = 1;
	soundSelect[] = {"",0.1,1};
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
	style = 16;
	shadow = 0;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	color[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,1};
	period = 1.2;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	class ScrollBar: ScrollBar
	{
	};
};
class RscXListBox
{
	deletable = 0;
	fade = 0;
	idc = -1;
	type = 42;
	x = 0.1;
	y = 0.1;
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorText[] = {1,1,1,1};
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	style = "0x400 + 0x02 +0x10";
	shadow = 2;
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	w = 0.14706;
	h = 0.039216;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
};
class RscTree
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 12;
	colorBackground[] = {0,0,0,0};
	colorSelect[] = {1,1,1,0.7};
	colorDisabled[] = {1,1,1,0.25};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {0,0,0,1};
	colorBorder[] = {0,0,0,0};
	colorSearch[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
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
	style = 0;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	expandedTexture = "A3\ui_f\data\gui\rsccommon\rsctree\expandedTexture_ca.paa";
	hiddenTexture = "A3\ui_f\data\gui\rsccommon\rsctree\hiddenTexture_ca.paa";
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.2;
	rowHeight = 0.0439091;
	colorSelectBackground[] = {0,0,0,0.5};
	colorLines[] = {0,0,0,0};
	borderSize = 0;
	expandOnDoubleclick = 1;
	class ScrollBar: ScrollBar
	{
	};
};
class RscSlider
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 3;
	style = 1024;
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
	type = 43;
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisable[] = {1,1,1,0.4};
	style = "0x400+ 0x10";
	shadow = 0;
	x = 0;
	y = 0;
	h = 0.029412;
	w = 0.4;
	colorDisabled[] = {1,1,1,0.2};
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};
class RscActiveText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 11;
	style = 2;
	color[] = {0,0,0,1};
	colorActive[] = {0.3,0.4,0,1};
	colorDisabled[] = {1,1,1,0.25};
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
	text = "";
	default = 0;
	idc = -1;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.035;
	font = "RobotoCondensed";
	shadow = 2;
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	url = "";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};
class RscStructuredText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 13;
	idc = -1;
	style = 0;
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
	size = "GUI_TEXT_SIZE_SMALL";
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
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
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
	type = 6;
	style = 2;
	colorText[] = {0.95,0.95,0.95,1};
	color[] = {0.95,0.95,0.95,1};
	colorTextSelect[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorTextDisable[] = {0.4,0.4,0.4,1};
	colorDisable[] = {0.4,0.4,0.4,1};
	colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",0.5};
	shadow = 0;
	strings[] = {"",""};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.025;
	rows = 1;
	columns = 2;
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
};
class RscHitZones
{
	type = 17;
	style = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.1;
	xCount = 1;
	yCount = 1;
	xSpace = 0;
	ySpace = 0;
};
class RscXKeyShadow
{
	type = 40;
	idc = -1;
	style = 0;
	h = 0.06;
	size = "( 21 / 408 )";
	shadow = 0;
	class Attributes
	{
		font = "FontX";
		color = "#C0C1BF";
		align = "left";
	};
	class AttributesImage
	{
		color = "#ffffff";
	};
};
class RscXKey: RscXKeyShadow
{
	class Attributes
	{
		shadow = 0;
	};
};
class RscMapControl
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 101;
	idc = 51;
	style = 48;
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
		x = "SafeZoneX + GUI_GRID_W";
		y = "SafeZoneY + safezoneH - 4.5 * GUI_GRID_H";
		w = "10 * GUI_GRID_W";
		h = "3.5 * GUI_GRID_H";
		font = "RobotoCondensed";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
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
		color[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
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
	moveOnEdges = 1;
	x = "SafeZoneXAbs";
	y = "SafeZoneY + 1.5 * GUI_GRID_H";
	w = "SafeZoneWAbs";
	h = "SafeZoneH - 1.5 * GUI_GRID_H";
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
	colorTrails[] = {0.84,0.76,0.65,0.15};
	colorTrailsFill[] = {0.84,0.76,0.65,0.65};
	widthRailWay = 4;
	fontLabel = "RobotoCondensed";
	sizeExLabel = "GUI_TEXT_SIZE_SMALL";
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = "GUI_TEXT_SIZE_SMALL";
	fontNames = "RobotoCondensed";
	sizeExNames = "GUI_TEXT_SIZE_SMALL * 2";
	fontInfo = "RobotoCondensed";
	sizeExInfo = "GUI_TEXT_SIZE_SMALL";
	fontLevel = "TahomaB";
	sizeExLevel = 0.02;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	idcMarkerColor = -1;
	idcMarkerIcon = -1;
	textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
	showMarkers = 1;
	class power
	{
		icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powersolar
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powerwave
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class powerwind
	{
		icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {1,1,1,1};
	};
	class Shipwreck
	{
		icon = "\A3\ui_f\data\map\mapcontrol\Shipwreck_CA.paa";
		size = 24;
		importance = 1;
		coefMin = 0.85;
		coefMax = 1;
		color[] = {0,0,0,1};
	};
};
class RscObject
{
	access = 0;
	type = 80;
	scale = 1;
	direction[] = {0,0,1};
	up[] = {0,1,0};
	shadow = 0;
};
class RscLineBreak
{
	idc = -1;
	type = 98;
	shadow = 0;
};
class RscCompass: RscObject
{
	idc = -1;
	type = 81;
	selectionArrow = "arrow";
	position[] = {0.026,0.047,0.2};
	direction[] = {0,0.5,0.5};
	up[] = {0,1,0};
	positionBack[] = {0,-0.02,0.075};
	inBack = 1;
	enableZoom = 0;
	zoomDuration = 0.5;
	model = "\A3\ui_f\objects\compass.p3d";
	scale = "0.47 * 0.875 * (SafeZoneW Min SafeZoneH)";
};
class RscCheckBox
{
	idc = -1;
	type = 77;
	deletable = 0;
	style = 0;
	checked = 0;
	x = "0.375 * safezoneW + safezoneX";
	y = "0.36 * safezoneH + safezoneY";
	w = "0.025 * safezoneW";
	h = "0.04 * safezoneH";
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
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
};
class RscDisplayUavTerminalWaypointMenu
{
	colorBackground[] = {0,0,0,0.5};
	colorBorder[] = {0,0,0,0};
	colorSeparator[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {1,1,1,0.3};
	colorChecked[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
	colorEnabled[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	idc = 108;
	type = 14;
	font = "RobotoCondensed";
	sizeEx = "0.028*SafezoneH";
	style = 0;
	x = 0;
	y = 0;
	w = 0;
	h = 0;
};
class RscIGText: RscText
{
	access = 0;
	h = 0.04;
	colorText[] = {0.8,0.8,0.8,1};
	font = "TahomaB";
	sizeEx = 0.024;
	style = "0x00 + 0x100";
};
class RscIGProgress: RscProgress
{
	colorFrame[] = {0.706,0.098,0.9294,0};
	colorBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
	style = 1;
	w = 0.009;
	h = 0.178;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
};
class RscListBoxKeys: RscListBox
{
	collisionColor[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])",1};
	collisionColorFirstKey[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])",1};
	disabledKeyColor[] = {0.4,0.4,0.4,1};
	mainCollumW = 0.4;
	secndCollumW = 0.6;
};
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
	idc = -1;
	style = 176;
	x = 0.17;
	y = 0.48;
	w = 0.66;
	h = 0;
	text = "";
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
};
class RscActivePicture: RscActiveText
{
	style = 48;
	color[] = {1,1,1,0.5};
	colorActive[] = {1,1,1,1};
};
class RscButtonTextOnly: RscButton
{
	SizeEx = "GUI_TEXT_SIZE_SMALL";
	colorBackground[] = {1,1,1,0};
	colorBackgroundActive[] = {1,1,1,0};
	colorBackgroundDisabled[] = {1,1,1,0};
	colorFocused[] = {1,1,1,0};
	colorShadow[] = {1,1,1,0};
	borderSize = 0;
};
class RscShortcutButtonMain: RscShortcutButton
{
	idc = -1;
	style = 0;
	default = 0;
	w = 0.313726;
	h = 0.104575;
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
		top = "((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_SMALL) / 2";
		w = "GUI_TEXT_SIZE_SMALL * (3/4)";
		h = "GUI_TEXT_SIZE_SMALL";
	};
	class TextPos
	{
		left = "(GUI_GRID_WAbs / 32) * 1.5";
		top = "((GUI_GRID_HAbs / 20)*2 - GUI_TEXT_SIZE_SMALL) / 2";
		right = 0.005;
		bottom = 0;
	};
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	period = 0.5;
	font = "RobotoCondensed";
	size = "GUI_TEXT_SIZE_SMALL";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	text = "";
	action = "";
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
		top = "((GUI_GRID_HAbs / 20) - GUI_TEXT_SIZE_SMALL) / 2";
		right = 0;
		bottom = 0;
	};
};
class RscIGUIShortcutButton: RscShortcutButton
{
	w = 0.183825;
	h = "0.0522876 * 0.7";
	style = 2;
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
};
class RscGearShortcutButton: RscShortcutButton
{
	w = 0.0392157;
	h = 0.0522876;
	style = 2;
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
	sizeEx = 0.1;
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\disabled_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\down_ca.paa";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscGearShortcutButton\normal_ca.paa";
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#E5E5E5";
		align = "center";
		shadow = "false";
	};
};
class RscButtonMenu: RscShortcutButton
{
	idc = -1;
	type = 16;
	style = "0x02 + 0xC0";
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
	colorBackground[] = {0,0,0,0.8};
	colorBackgroundFocused[] = {1,1,1,1};
	colorBackground2[] = {0.75,0.75,0.75,1};
	color[] = {1,1,1,1};
	colorFocused[] = {0,0,0,1};
	color2[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	textSecondary = "";
	colorSecondary[] = {1,1,1,1};
	colorFocusedSecondary[] = {0,0,0,1};
	color2Secondary[] = {0,0,0,1};
	colorDisabledSecondary[] = {1,1,1,0.25};
	sizeExSecondary = "GUI_TEXT_SIZE_SMALL";
	fontSecondary = "PuristaLight";
	period = 1.2;
	periodFocus = 1.2;
	periodOver = 1.2;
	size = "GUI_TEXT_SIZE_SMALL";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class TextPos
	{
		left = "0.25 * GUI_GRID_W";
		top = "(GUI_GRID_H - GUI_TEXT_SIZE_SMALL) / 2";
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
		left = "5.25 * GUI_GRID_W";
		top = 0;
		w = "1 * GUI_GRID_W";
		h = "1 * GUI_GRID_H";
	};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
};
class RscButtonMenuOK: RscButtonMenu
{
	idc = 1;
	shortcuts[] = {"0x00050000 + 0",28,57,156};
	default = 1;
	text = "OK";
	soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",0.09,1};
};
class RscButtonMenuCancel: RscButtonMenu
{
	idc = 2;
	shortcuts[] = {"0x00050000 + 1"};
	text = "Cancel";
};
class RscButtonMenuSteam: RscButtonMenu
{
	colorBackground[] = {0.0313726,0.721569,0.917647,1};
	textureNoShortcut = "\A3\Ui_f\data\GUI\RscCommon\RscButtonMenuSteam\steam_ca.paa";
	class TextPos
	{
		left = 0.0325;
		top = "(GUI_GRID_H - GUI_TEXT_SIZE_SMALL) / 2";
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
};
class RscLoadingText: RscText
{
	style = 2;
	x = 0.29412;
	y = 0.666672;
	w = 0.411768;
	h = 0.039216;
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	colorText[] = {1,1,1,1};
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
	period = 0;
	colorBackground[] = {0,0,0,0};
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	class ScrollBar: ScrollBar
	{
	};
};
class RscIGUIListNBox: RscListNBox
{
	style = "0 + 0x10";
	shadow = 2;
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,0.75};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorSelect2[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {1,1,1,1};
	colorSelectBackground2[] = {1,1,1,1};
	period = 0;
	colorBackground[] = {0,0,0,1};
	columns[] = {0.1,0.7,0.1,0.1};
	class ScrollBar: ScrollBar
	{
	};
};
class RscFrame
{
	type = 0;
	idc = -1;
	deletable = 0;
	style = 64;
	shadow = 2;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
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
	type = 0;
	IDC = -1;
	style = 512;
	shadow = 0;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	text = "";
	ColorBackground[] = {0.48,0.5,0.35,1};
	ColorText[] = {0.1,0.1,0.1,1};
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
	text = "A3\ui_f\data\gui\rsccommon\rscbackgroundgui\gradient_left_gs.paa";
	colorText[] = {1,1,1,"0.3*0"};
	colorBackground[] = {0,0,0,0};
	background = 1;
};
class RscBackgroundGUIRight: RscPicture
{
	text = "A3\ui_f\data\gui\rsccommon\rscbackgroundgui\gradient_right_gs.paa";
	colorText[] = {0,0,0,"0.4*0"};
	colorBackground[] = {0,0,0,0};
	background = 1;
};
class RscBackgroundGUIBottom: RscPicture
{
	colorText[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",0.8};
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
	x = "safezoneX + safezoneW - (9 * (GUI_GRID_WAbs / 32))";
	y = "safezoneY - 2 * (GUI_GRID_HAbs / 20)";
	w = "(8 * (GUI_GRID_WAbs / 32))";
	h = "(8 * (GUI_GRID_HAbs / 20))";
};
class RscMapControlEmpty: RscMapControl
{
	type = 101;
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
	class fuelstation: Fuelstation
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
	class power: power
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powersolar: powersolar
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powerwave: powerwave
	{
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0};
		size = 0;
	};
	class powerwind: powerwind
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
class IGUIBack
{
	type = 0;
	idc = 124;
	style = 128;
	text = "";
	colorText[] = {0,0,0,0};
	font = "RobotoCondensed";
	sizeEx = 0;
	shadow = 0;
	x = 0.1;
	y = 0.1;
	w = 0.1;
	h = 0.1;
	colorbackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
};
class RscVignette: RscPicture
{
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	text = "\A3\ui_f\data\gui\rsccommon\rscvignette\vignette_gs.paa";
	colortext[] = {0,0,0,0.3};
};
class RscMapControlTooltip: RscControlsGroupNoScrollbars
{
	idc = 2350;
	x = -1;
	y = -1;
	w = 0;
	h = 0;
	class Controls
	{
		class Background: RscText
		{
			idc = 235000;
			x = 1;
			y = 1;
			w = 1;
			h = 1;
			colorBackground[] = {0,0,0,1};
		};
		class InfoBackground: RscStructuredText
		{
			idc = 235001;
			x = 0;
			y = 0;
			w = 1;
			h = "GUI_GRID_H";
			colorBackground[] = {1,1,1,0.15};
		};
		class Info: RscStructuredText
		{
			idc = 235002;
			x = 1;
			y = 1;
			w = 1;
			h = 1;
		};
		class AssetsBackground: RscStructuredText
		{
			idc = 235003;
			x = 1;
			y = 1;
			w = 1;
			h = 1;
			colorBackground[] = {0,0,0,1};
		};
		class Assets: RscStructuredText
		{
			idc = 235004;
			x = 1;
			y = 1;
			w = 1;
			h = 1;
		};
		class PictureBackground: RscText
		{
			idc = 235005;
			x = 1;
			y = 1;
			w = 1;
			h = 1;
			colorBackground[] = {0,0,0,1};
		};
		class PictureX: RscPictureKeepAspect
		{
			idc = 235006;
			x = -1;
			y = -1;
			w = 0;
			h = 0;
			autoplay = 1;
			loops = 1;
		};
	};
};
class CA_Mainback: RscPicture
{
	x = 0.35;
	y = 0.8;
	w = 0.3;
	h = 0.2;
	text = "#(argb,8,8,3)color(0,0,0,0.5)";
	colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
};
class CA_Back: CA_Mainback
{
	x = 0.29;
	y = 0.38;
	w = 0.56;
	h = 0.57;
	colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
	text = "#(argb,8,8,3)color(0,0,0,0.5)";
};
class CA_Title_Back: CA_Mainback
{
	x = 0.014706;
	y = 0;
	w = 0.950743;
	h = 0.058824;
	text = "#(argb,8,8,3)color(0,0,0,0)";
	colorText[] = {0.95,0.95,0.95,1};
};
class CA_Black_Back: CA_Mainback
{
	x = "SafeZoneX - SafeZoneW";
	y = "SafeZoneY - SafeZoneH";
	w = "SafeZoneW * 4";
	h = "SafeZoneH * 4";
	text = "#(argb,8,8,3)color(0,0,0,1)";
	colorText[] = {0,0,0,1};
	color[] = {0,0,0,1};
	colorBackground[] = {0,0,0,1};
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
	idc = -1;
	default = 0;
	x = 0.843144;
	y = 0.8;
	w = 0.14706;
	h = 0.039216;
	borderSize = 0.009804;
	color[] = {0,0,0,0};
	colorActive[] = {0,0,0,0};
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
	idc = -1;
	style = 48;
	default = 0;
	x = 0.85;
	y = 0.8;
	w = 0.15;
	h = 0.035;
	text = "#(argb,8,8,3)color(0,0,0,0)";
	color[] = {0,0,0,0};
	colorActive[] = {0,0,0,0};
};
class CA_Ok_image: RscText
{
	idc = -1;
	x = 0.86;
	y = 0.8;
	w = 0.14;
	h = 0.04;
	text = "#(argb,8,8,3)color(1,1,1,0.9)";
	style = 48;
	colortext[] = {1,1,1,0.8};
};
class CA_Ok_image2: RscText
{
	idc = -1;
	x = 0.85;
	y = 0.8;
	w = 0.01;
	h = 0.04;
	text = "#(argb,8,8,3)color(1,1,1,0.9)";
	style = 48;
	colortext[] = {0,0,0,0.8};
};
class CA_Ok_text: RscText
{
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	idc = -1;
	x = 0.86;
	y = 0.8;
	w = 0.14;
	h = 0.04;
	style = 0;
	colortext[] = {0,0,0,0.8};
};
class ctrlDefault
{
	access = 0;
	idc = -1;
	style = 0;
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
	type = 77;
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
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
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
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};
class ctrlActiveText: ctrlDefaultButton
{
	type = 11;
	text = "";
	color[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.75};
	colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorDisabled[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = 48;
	color[] = {1,1,1,1};
};
class ctrlStatic: ctrlDefaultText
{
	type = 0;
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
	type = 15;
	style = 16;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	class VScrollBar: ScrollBar
	{
		width = "2 * (pixelW * pixelGrid * 0.50)";
		height = 0;
		autoScrollEnabled = 0;
		autoScrollDelay = 1;
		autoScrollRewind = 1;
		autoScrollSpeed = 1;
	};
	class HScrollBar: ScrollBar
	{
		width = 0;
		height = "2 * (pixelH * pixelGrid * 0.50)";
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
	type = 13;
	colorBackground[] = {0,0,0,0};
	size = "4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	text = "";
	class Attributes
	{
		align = "left";
		color = "#ffffff";
		colorLink = "";
		size = 1;
		font = "RobotoCondensedLight";
	};
	onCanDestroy = "";
	onDestroy = "";
};
class RscTextMulti: RscText
{
	style = 16;
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
	style = "0x30 + 0x800";
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
	style = "0x30 + 0x800";
};
class RscButtonMenuBIKI: RscButtonMenu
{
	url = "https://community.bistudio.com/wiki/";
};
class RscTextCheckBox
{
	idc = -1;
	type = 7;
	style = 0;
	x = "0.375 * safezoneW + safezoneX";
	y = "0.36 * safezoneH + safezoneY";
	w = "0.025 * safezoneW";
	h = "0.04 * safezoneH";
	colorText[] = {1,0,0,1};
	color[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorTextSelect[] = {0,0.8,0,1};
	colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
	colorSelect[] = {0,0,0,1};
	colorTextDisable[] = {0.4,0.4,0.4,1};
	colorDisable[] = {0.4,0.4,0.4,1};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	font = "RobotoCondensed";
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	rows = 1;
	columns = 1;
	strings[] = {"UNCHECKED"};
	checked_strings[] = {"CHECKED"};
};
class RscListBoxMulti: RscListBox
{
	style = "0x10 + 0x20";
};
class RscEditMulti: RscEdit
{
	style = 16;
};
class RscEditReadOnly: RscEdit
{
	canModify = 0;
};
class RscEditMultiReadOnly: RscEdit
{
	style = 16;
	canModify = 0;
};
class RscMapSignalBackground: RscText
{
	x = "12.5 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)";
	y = "10 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2)";
	w = "15.5 * GUI_GRID_W";
	h = "5 * GUI_GRID_H";
	colorBackground[] = {0.1,0.1,0.1,0.8};
};
class RscMapSignalPicture: RscPicture
{
	colorText[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
	text = "\A3\ui_f\data\map\diary\signal_ca.paa";
	x = "19 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)";
	y = "10.5 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2)";
	w = "2 * GUI_GRID_W";
	h = "2 * GUI_GRID_H";
};
class RscMapSignalText: RscText
{
	style = 2;
	colorText[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
	text = "Cannot connect to the positioning system.";
	x = "13 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)";
	y = "13.5 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2)";
	w = "14.5 * GUI_GRID_W";
	h = "1 * GUI_GRID_H";
	sizeEx = "0.8 * GUI_GRID_H";
};
class RscMessageBox: RscControlsGroupNoScrollbars
{
	idc = 2351;
	x = -1;
	y = -1;
	w = 0;
	h = 0;
	class Controls
	{
		class BcgCommonTop: RscBackgroundGUITop
		{
			idc = 235100;
			x = 0;
			y = 0;
			w = "18.8 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",1};
		};
		class BcgCommon: RscBackgroundGUI
		{
			idc = 235101;
			x = 0;
			y = "1.1 * GUI_GRID_H";
			w = "18.8 * GUI_GRID_W";
			h = "1.7 * GUI_GRID_H";
			colorBackground[] = {0,0,0,1};
		};
		class Text: RscStructuredText
		{
			idc = 235102;
			x = "0.7 * GUI_GRID_W";
			y = "1.8 * GUI_GRID_H";
			w = "17 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class BackgroundButtonOK: RscBackgroundGUI
		{
			idc = 235103;
			x = 0;
			y = "2.9 * GUI_GRID_H";
			w = "6.2 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			colorBackground[] = {0,0,0,1};
		};
		class BackgroundButtonMiddle: BackgroundButtonOK
		{
			idc = 235104;
			x = "6.3 * GUI_GRID_W";
		};
		class BackgroundButtonCancel: BackgroundButtonOK
		{
			idc = 235105;
			x = "12.6 * GUI_GRID_W";
		};
		class ButtonOK: RscButtonMenuOK
		{
			default = 1;
			idc = 235106;
			colorBackground[] = {0,0,0,1};
			x = 0;
			y = "2.9 * GUI_GRID_H";
			w = "6.2 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			idc = 235107;
			colorBackground[] = {0,0,0,1};
			x = "12.6 * GUI_GRID_W";
			y = "2.9 * GUI_GRID_H";
			w = "6.2 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
	};
};
class RscWIP: RscControlsGroup
{
	class VScrollbar: VScrollbar
	{
		width = 0;
	};
	class HScrollbar: HScrollbar
	{
		height = 0;
	};
	x = "safezoneX + safezoneW - 10 * GUI_GRID_W";
	y = "safezoneY + safezoneH - 5.3 * GUI_GRID_H";
	idc = 2300;
	w = "9.5 * GUI_GRID_W";
	h = "5.3 * GUI_GRID_H";
	class controls
	{
		class WIP_VersionText: RscText
		{
			style = 2;
			shadow = 0;
			idc = 1001;
			text = "Development Build";
			x = "0 * GUI_GRID_W";
			y = "3 * GUI_GRID_H";
			w = "9.5 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			colorText[] = {1,1,1,0.3};
			colorBackground[] = {0.2,0.2,0.2,0.05};
		};
		class WIP_VersionNumber: RscText
		{
			style = 2;
			shadow = 0;
			idc = 1000;
			x = "0 * GUI_GRID_W";
			y = "4 * GUI_GRID_H";
			w = "9.5 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			colorText[] = {1,1,1,0.3};
			colorBackground[] = {0.2,0.2,0.2,0.05};
		};
	};
};
class DLCActionNotification: RscControlsGroup
{
	class VScrollbar: VScrollbar
	{
		width = 0;
	};
	class HScrollbar: HScrollbar
	{
		height = 0;
	};
	idc = 2303;
	x = "6 * GUI_GRID_W + (profilenamespace getvariable [""IGUI_GRID_MENU_X"",(1.5 * GUI_GRID_W + safezoneX)])";
	y = "0 * GUI_GRID_H + (profilenamespace getvariable [""IGUI_GRID_MENU_Y"",(5 * GUI_GRID_H + safezoneY)])";
	w = "17.8 * GUI_GRID_W";
	h = "4.6 * GUI_GRID_H";
	class controls
	{
		class ANBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 1010;
			x = "1 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "15.8 * GUI_GRID_W";
			h = "4.6 * GUI_GRID_H";
		};
		class ANTitle: RscText
		{
			idc = 102;
			shadow = 0;
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			text = "Vehicle Locked";
			x = "1 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "12 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
			sizeEx = "1.2 * GUI_GRID_H";
		};
		class ANLogo: RscPicture
		{
			idc = 100;
			x = "13 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.8 * GUI_GRID_W";
			h = "3.8 * GUI_GRID_H";
		};
		class ANShortcut: RscText
		{
			style = 2;
			shadow = 0;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			idc = 1011;
			text = "LShift+P";
			x = "13 * GUI_GRID_W";
			y = "3.8 * GUI_GRID_H";
			w = "3.8 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
			colorBackground[] = {0.0313726,0.721569,0.917647,1};
		};
		class ANText: RscText
		{
			idc = 101;
			shadow = 0;
			style = "0x10+0x200";
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			x = "1 * GUI_GRID_W";
			y = "1.4 * GUI_GRID_H";
			w = "12 * GUI_GRID_W";
			h = "3.2 * GUI_GRID_H";
		};
	};
};
class RscColorPicker: RscControlsGroupNoScrollbars
{
	idc = 2351;
	x = -1;
	y = -1;
	w = 0;
	h = 0;
	class controls
	{
	};
};
class RscInterlacingScreen: RscPicture
{
	text = "a3\ui_f\data\igui\rsctitles\interlacing\interlacing_ca.paa";
	x = "safeZoneX";
	y = "safeZoneY";
	w = "safeZoneW";
	h = "safeZoneH";
};
class ctrlButton: ctrlDefaultButton
{
	type = 1;
	style = "0x02 + 0xC0";
	colorBackground[] = {0,0,0,1};
	colorBackgroundDisabled[] = {0,0,0,0.5};
	colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
class ctrlButtonPictureKeepAspect: ctrlButton
{
	style = "0x02 + 0x30 + 0x800";
};
class RscDebugConsole: RscControlsGroupNoScrollbars
{
	idc = 13184;
	x = "9 * GUI_GRID_W + GUI_GRID_X";
	y = "0.5 * GUI_GRID_H + (safezoneY + safezoneH - GUI_GRID_HAbs)";
	w = "21.5 * GUI_GRID_W";
	h = "21.5 * GUI_GRID_H";
	class controls
	{
		class Title: RscButton
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 11884;
			text = "Debug console";
			x = "0 *    (   GUI_GRID_WAbs / 40)";
			y = "0 *    (   (   GUI_GRID_WAbs / 1.2) / 25)";
			w = "22 *    (   GUI_GRID_WAbs / 40)";
			h = "1 *    (   (   GUI_GRID_WAbs / 1.2) / 25)";
			style = 0;
			colorText[] = {1,1,1,1};
			period = -1;
			colorDisabled[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			colorBackgroundDisabled[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			colorFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			colorShadow[] = {0,0,0,0};
			colorBorder[] = {0,0,0,1};
			soundEnter[] = {"",0.09,1};
			soundPush[] = {"",0.09,1};
			soundClick[] = {"",0.09,1};
			soundEscape[] = {"",0.09,1};
		};
		class Link: RscHTML
		{
			idc = 11891;
			x = "7 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "15 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ExpressionBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 11885;
			x = "0 * GUI_GRID_W";
			y = "1.1 * GUI_GRID_H";
			w = "22 * GUI_GRID_W";
			h = "8 * GUI_GRID_H";
		};
		class ExpressionText: RscText
		{
			idc = 11892;
			text = "Execute";
			x = "0.2 * GUI_GRID_W";
			y = "1.1 * GUI_GRID_H";
			w = "22 * GUI_GRID_W";
			h = "0.5 * GUI_GRID_H";
			sizeEx = "0.8 * GUI_GRID_H";
		};
		class Expression: RscEdit
		{
			style = 16;
			autocomplete = "scripting";
			font = "EtelkaMonospacePro";
			idc = 12284;
			x = "0.5 * GUI_GRID_W";
			y = "1.7 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "6 * GUI_GRID_H";
			sizeEx = "0.75 * GUI_GRID_H";
			onMouseButtonDblClick = "ctrlSetFocus (_this select 0)";
		};
		class ExpressionOutputBackground: RscText
		{
			show = "isMultiplayer";
			colorBackground[] = {0,0,0,0};
			idc = 13191;
			x = "0.5 * GUI_GRID_W";
			y = "7.7 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ExpressionOutput: RscEdit
		{
			style = 512;
			canModify = 0;
			font = "EtelkaMonospacePro";
			colorBackground[] = {0,0,0,0.8};
			sizeEx = "0.7 * GUI_GRID_H";
			idc = 13190;
			x = "0.5 * GUI_GRID_W";
			y = "7.7 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			onMouseButtonDblClick = "ctrlSetFocus (_this select 0)";
			onLoad = "parsingNamespace setVariable [""BIS_RscDebugConsoleExpressionResultCtrl"", _this select 0]";
		};
		class ButtonCodePerformance: RscButtonMenu
		{
			text = "<img image='\a3\Ui_f\data\GUI\RscCommon\RscDebugConsole\performance_ca.paa' align='center' size='0.7' />";
			class TextPos
			{
				left = 0;
				top = 0;
				right = 0;
				bottom = 0;
			};
			style = 2;
			idc = 13284;
			x = "0 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "1 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteServerBackground: RscText
		{
			show = "isMultiplayer";
			colorBackground[] = {0,1,0,0.25};
			idc = -1;
			x = "1.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteServer: RscButtonMenu
		{
			idc = 13286;
			text = "SERVER EXEC";
			x = "1.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteAllBackground: RscText
		{
			show = "isMultiplayer";
			colorBackground[] = {1,0,0,0.25};
			idc = -1;
			x = "8.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteAll: RscButtonMenu
		{
			idc = 13285;
			text = "GLOBAL EXEC";
			x = "8.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteLocalBackground: RscText
		{
			show = "isMultiplayer";
			colorBackground[] = {0,0,1,0.25};
			idc = -1;
			x = "15.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonExecuteLocal: RscButtonMenu
		{
			default = 1;
			idc = 13484;
			text = "LOCAL EXEC";
			x = "15.1 * GUI_GRID_W";
			y = "9.2 * GUI_GRID_H";
			w = "6.9 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 11886;
			x = "0 * GUI_GRID_W";
			y = "10.4 * GUI_GRID_H";
			w = "22 * GUI_GRID_W";
			h = "8.9 * GUI_GRID_H";
		};
		class WatchText: RscText
		{
			idc = 11893;
			text = "Watch:";
			x = "0.2 * GUI_GRID_W";
			y = "10.4 * GUI_GRID_H";
			w = "22 * GUI_GRID_W";
			h = "0.5 * GUI_GRID_H";
			sizeEx = "0.8 * GUI_GRID_H";
		};
		class WatchInput1: RscEdit
		{
			autocomplete = "scripting";
			shadow = 0;
			font = "EtelkaMonospacePro";
			idc = 12285;
			x = "0.5 * GUI_GRID_W";
			y = "11 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			sizeEx = "0.7 * GUI_GRID_H";
			onMouseButtonDblClick = "ctrlSetFocus (_this select 0)";
			onSetFocus = "_this select 0 setVariable ['RscDebugConsole_watchPaused', true]";
			onKillFocus = "_this select 0 setVariable ['RscDebugConsole_watchPaused', false]";
		};
		class WatchOutput1: RscEdit
		{
			style = 512;
			canModify = 0;
			font = "EtelkaMonospacePro";
			colorBackground[] = {0,0,0,0.8};
			sizeEx = "0.7 * GUI_GRID_H";
			idc = 12286;
			x = "0.5 * GUI_GRID_W";
			y = "12 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
			onMouseButtonDblClick = "ctrlSetFocus (_this select 0)";
		};
		class WatchInput2: WatchInput1
		{
			idc = 12287;
			x = "0.5 * GUI_GRID_W";
			y = "13 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchOutput2: WatchOutput1
		{
			idc = 12288;
			x = "0.5 * GUI_GRID_W";
			y = "14 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchInput3: WatchInput1
		{
			idc = 12289;
			x = "0.5 * GUI_GRID_W";
			y = "15 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchOutput3: WatchOutput1
		{
			idc = 12290;
			x = "0.5 * GUI_GRID_W";
			y = "16 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchInput4: WatchInput1
		{
			idc = 12291;
			x = "0.5 * GUI_GRID_W";
			y = "17 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class WatchOutput4: WatchOutput1
		{
			idc = 12293;
			x = "0.5 * GUI_GRID_W";
			y = "18 * GUI_GRID_H";
			w = "21 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonSpectatorCamera: RscButtonMenu
		{
			idc = 13287;
			text = "SPECTATOR";
			x = "0 * GUI_GRID_W";
			y = "19.4 * GUI_GRID_H";
			w = "7.4 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonFunctions: RscButtonMenu
		{
			idc = 13289;
			text = "FUNCTIONS";
			x = "7.5 * GUI_GRID_W";
			y = "19.4 * GUI_GRID_H";
			w = "7.4 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonAnimations: RscButtonMenu
		{
			idc = 13291;
			text = "ANIMATIONS";
			x = "15 * GUI_GRID_W";
			y = "19.4 * GUI_GRID_H";
			w = "7 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonSplendidCamera: RscButtonMenu
		{
			idc = 13288;
			text = "CAMERA";
			x = "0 * GUI_GRID_W";
			y = "20.5 * GUI_GRID_H";
			w = "7.4 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonConfig: RscButtonMenu
		{
			idc = 13290;
			text = "CONFIG";
			x = "7.5 * GUI_GRID_W";
			y = "20.5 * GUI_GRID_H";
			w = "7.4 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonGUI: RscButtonMenu
		{
			idc = 13292;
			text = "GUI EDITOR";
			x = "15 * GUI_GRID_W";
			y = "20.5 * GUI_GRID_H";
			w = "7 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ENH_ButtonFunctions: ctrlButtonPictureKeepAspect
		{
			idc = 0;
			deletable = 0;
			text = "\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
			tooltip = "3den Enhanced Functions Viewer";
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			onButtonClick = "ctrlParent (_this # 0) createDisplay 'ENH_FunctionsViewer'";
			x = "getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'w') - (4.1 * GUI_GRID_W)";
			y = "getNumber(configFile >> 'RscDebugConsole' >> 'controls' >> 'Title' >> 'y')";
			w = "1 * GUI_GRID_W";
			h = "1 *GUI_GRID_H";
		};
	};
};
class RscFeedback: RscHTML
{
	idc = 6455;
	x = "1 * GUI_GRID_W + GUI_GRID_X";
	y = "safezoneY";
	w = "15 * GUI_GRID_W";
	h = "1 * GUI_GRID_H";
	colorBackground[] = {0.67451,0.290196,0.290196,1};
	colorLink[] = {1,1,1,1};
	colorLinkActive[] = {1,1,1,1};
	shadow = 0;
	class P
	{
		font = "RobotoCondensedBold";
		fontBold = "RobotoCondensedBold";
		sizeEx = "GUI_TEXT_SIZE_SMALL";
		align = "center";
	};
};
class RscMissionStatus: RscControlsGroupNoScrollbars
{
	w = "(2.5 * GUI_GRID_W)";
	h = "(15 * GUI_GRID_H)";
	idc = 15283;
	x = "0 * GUI_GRID_W + (profilenamespace getvariable [""IGUI_GRID_MP_X"",(safezoneX + safezoneW - 2 * GUI_GRID_W)])";
	y = "0 * GUI_GRID_H + (profilenamespace getvariable [""IGUI_GRID_MP_Y"",(5 * GUI_GRID_H + safezoneY)])";
	class controls
	{
		class BarBridge: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 13983;
			x = "0.5 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "1.5 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class BarWEST: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",0.75};
			idc = 13984;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "0.5 * GUI_GRID_W";
			h = "14.9 * GUI_GRID_H";
		};
		class BarEAST: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",0.75};
			idc = 13985;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "0.5 * GUI_GRID_W";
			h = "14.9 * GUI_GRID_H";
		};
		class BarGUER: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",0.75};
			idc = 13986;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "0.5 * GUI_GRID_W";
			h = "14.9 * GUI_GRID_H";
		};
		class BarCIV: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",0.75};
			idc = 13987;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "0.5 * GUI_GRID_W";
			h = "14.9 * GUI_GRID_H";
		};
		class BarUnknown: RscText
		{
			style = 16;
			idc = 13988;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "0.5 * GUI_GRID_W";
			h = "14.9 * GUI_GRID_H";
			colorBackground[] = {0.25,0.25,0.25,0.75};
		};
		class Slot1Background: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
			idc = 13989;
			x = "0.6 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot1Progress: RscProgress
		{
			style = 1;
			colorBar[] = {1,1,1,0.5};
			texture = "\a3\Ui_f\data\IGUI\RscTitles\MPProgress\progress_ca.paa";
			idc = 13990;
			x = "0.6 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot1: RscActivePictureKeepAspect
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			shadow = 0;
			idc = 14183;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "0.1 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot1Text: RscStructuredText
		{
			colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			style = 2;
			shadow = 0;
			idc = 14093;
			x = "0.3 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "2 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
			sizeEx = "1.2 * GUI_GRID_H";
		};
		class Slot2Background: Slot1Background
		{
			idc = 13991;
			x = "0.6 * GUI_GRID_W";
			y = "1.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot2Progress: Slot1Progress
		{
			idc = 13992;
			x = "0.6 * GUI_GRID_W";
			y = "1.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot2: Slot1
		{
			idc = 14184;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "1.6 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot2Text: Slot1Text
		{
			idc = 14094;
			y = "1.5 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot3Background: Slot1Background
		{
			idc = 13993;
			x = "0.6 * GUI_GRID_W";
			y = "3 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot3Progress: Slot1Progress
		{
			idc = 13994;
			x = "0.6 * GUI_GRID_W";
			y = "3 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot3: Slot1
		{
			idc = 14185;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "3.1 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot3Text: Slot1Text
		{
			idc = 14095;
			y = "3 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot4Background: Slot1Background
		{
			idc = 13995;
			x = "0.6 * GUI_GRID_W";
			y = "4.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot4Progress: Slot1Progress
		{
			idc = 13996;
			x = "0.6 * GUI_GRID_W";
			y = "4.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot4: Slot1
		{
			idc = 14186;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "4.6 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot4Text: Slot1Text
		{
			idc = 14096;
			y = "4.5 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot5Background: Slot1Background
		{
			idc = 13997;
			x = "0.6 * GUI_GRID_W";
			y = "6 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot5Progress: Slot1Progress
		{
			idc = 13998;
			x = "0.6 * GUI_GRID_W";
			y = "6 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot5: Slot1
		{
			idc = 14187;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "6.1 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot5Text: Slot1Text
		{
			idc = 14097;
			y = "6 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot6Background: Slot1Background
		{
			idc = 13999;
			x = "0.6 * GUI_GRID_W";
			y = "7.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot6Progress: Slot1Progress
		{
			idc = 14000;
			x = "0.6 * GUI_GRID_W";
			y = "7.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot6: Slot1
		{
			idc = 14188;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "7.6 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot6Text: Slot1Text
		{
			idc = 14098;
			y = "7.5 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot7Background: Slot1Background
		{
			idc = 14001;
			x = "0.6 * GUI_GRID_W";
			y = "9 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot7Progress: Slot1Progress
		{
			idc = 14002;
			x = "0.6 * GUI_GRID_W";
			y = "9 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot7: Slot1
		{
			idc = 14189;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "9.1 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot7Text: Slot1Text
		{
			idc = 14099;
			y = "9 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot8Background: Slot1Background
		{
			idc = 14003;
			x = "0.6 * GUI_GRID_W";
			y = "10.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot8Progress: Slot1Progress
		{
			idc = 14004;
			x = "0.6 * GUI_GRID_W";
			y = "10.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot8: Slot1
		{
			idc = 14190;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "10.6 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot8Text: Slot1Text
		{
			idc = 14100;
			y = "10.5 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot9Background: Slot1Background
		{
			idc = 14005;
			x = "0.6 * GUI_GRID_W";
			y = "12 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot9Progress: Slot1Progress
		{
			idc = 14006;
			x = "0.6 * GUI_GRID_W";
			y = "12 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot9: Slot1
		{
			idc = 14191;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "12.1 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot9Text: Slot1Text
		{
			idc = 14101;
			y = "12 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot0Background: Slot1Background
		{
			idc = 14007;
			x = "0.6 * GUI_GRID_W";
			y = "13.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
		};
		class Slot0Progress: Slot1Progress
		{
			idc = 14008;
			x = "0.6 * GUI_GRID_W";
			y = "13.5 * GUI_GRID_H";
			w = "1.4 * GUI_GRID_W";
			h = "1.4 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
		class Slot0: Slot1
		{
			idc = 14192;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "0.7 * GUI_GRID_W";
			y = "13.6 * GUI_GRID_H";
			w = "1.2 * GUI_GRID_W";
			h = "1.2 * GUI_GRID_H";
		};
		class Slot0Text: Slot1Text
		{
			idc = 14102;
			y = "13.5 * GUI_GRID_H";
			colorBackground[] = {0,0,0,0};
		};
	};
};
class RscNotificationArea: RscControlsGroupNoScrollbars
{
	idc = 312;
	x = "0 * GUI_GRID_W + (profilenamespace getvariable [""IGUI_GRID_NOTIFICATION_X"",(0.5 - 6 * GUI_GRID_W)])";
	y = "0 * GUI_GRID_H + (profilenamespace getvariable [""IGUI_GRID_NOTIFICATION_Y"",(safezoneY + 6.5 * GUI_GRID_H)])";
	w = "12 * GUI_GRID_W";
	h = "6 * GUI_GRID_H";
	class controls
	{
		class Notification: RscControlsGroupNoScrollbars
		{
			x = 0;
			y = 0;
			idc = 13435;
			w = "12 * GUI_GRID_W";
			h = "3 * GUI_GRID_H";
			class controls
			{
				class Title: RscText
				{
					colorBackground[] = {0,0,0,0.7};
					idc = 12135;
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "12 * GUI_GRID_W";
					h = "0.8 * GUI_GRID_H";
					sizeEx = "0.8 * GUI_GRID_H";
				};
				class PictureBackground: RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.7};
					idc = 12136;
					x = "0 * GUI_GRID_W";
					y = "0.9 * GUI_GRID_H";
					w = "2 * GUI_GRID_W";
					h = "2 * GUI_GRID_H";
				};
				class Picture: RscPictureKeepAspect
				{
					idc = 12335;
					x = "0.1 * GUI_GRID_W";
					y = "1 * GUI_GRID_H";
					w = "1.8 * GUI_GRID_W";
					h = "1.8 * GUI_GRID_H";
				};
				class Score: RscText
				{
					shadow = 0;
					style = 2;
					idc = 12137;
					x = "0 * GUI_GRID_W";
					y = "0.9 * GUI_GRID_H";
					w = "2 * GUI_GRID_W";
					h = "2 * GUI_GRID_H";
					sizeEx = "1.2 * GUI_GRID_H";
				};
				class DescriptionBackground: RscText
				{
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.7};
					idc = 12138;
					x = "2.1 * GUI_GRID_W";
					y = "0.9 * GUI_GRID_H";
					w = "9.9 * GUI_GRID_W";
					h = "2 * GUI_GRID_H";
				};
				class Description: RscStructuredText
				{
					class Attributes
					{
						size = 0.8;
						align = "center";
					};
					idc = 12235;
					x = "2.1 * GUI_GRID_W";
					y = "0.9 * GUI_GRID_H";
					w = "9.9 * GUI_GRID_W";
					h = "2 * GUI_GRID_H";
					colorBackground[] = {0,0,0,0};
					sizeEx = "1 * GUI_GRID_H";
				};
			};
		};
	};
};
class RscHintGroup: RscControlsGroupNoScrollbars
{
	w = "(12 * GUI_GRID_W)";
	idc = 12957;
	x = "0 * GUI_GRID_W + (profilenamespace getvariable [""IGUI_GRID_HINT_X"",((safezoneX + safezoneW) - (12 * GUI_GRID_W) - 1 * GUI_GRID_W)])";
	y = "0 * GUI_GRID_H + (profilenamespace getvariable [""IGUI_GRID_HINT_Y"",(safezoneY + 6 * GUI_GRID_H)])";
	h = "5 * GUI_GRID_H";
	class controls
	{
		class Title: RscStructuredText
		{
			colorBackground[] = {0,0,0,0.7};
			w = "(12 * GUI_GRID_W)";
			idc = 11657;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			h = "1 * GUI_GRID_H";
		};
		class Hint: RscStructuredText
		{
			colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.7};
			size = "GUI_TEXT_SIZE_SMALL";
			w = "(12 * GUI_GRID_W)";
			idc = 11757;
			x = "0 * GUI_GRID_W";
			y = "1 * GUI_GRID_H";
			h = "4 * GUI_GRID_H";
		};
	};
};
class RscVehicleToggles
{
	idc = 112;
	type = 18;
	style = -1;
	xSpace = "0.1 * GUI_GRID_W";
	x = "0.1 * GUI_GRID_W + (profilenamespace getvariable [""IGUI_GRID_VEHICLE_X"",(safezoneX + 0.5 * GUI_GRID_W)])";
	y = "3.4 * GUI_GRID_H + (profilenamespace getvariable [""IGUI_GRID_VEHICLE_Y"",(safezoneY + 0.5 * GUI_GRID_H)])";
	w = "9.8 * GUI_GRID_W";
	h = "0.8 * GUI_GRID_H";
	iconW = "0.8 * GUI_GRID_W";
	iconH = "0.8 * GUI_GRID_H";
	class Icons
	{
		class EngineIcon
		{
			type = "Engine";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\EngineIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\EngineIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\EngineIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class LightsIcon
		{
			type = "Lights";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LightsIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LightsIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LightsIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class CollisionLightsIcon
		{
			type = "CollisionLights";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\CollisionLightsIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\CollisionLightsIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\CollisionLightsIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class LandingGearIcon
		{
			type = "LandingGear";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingGearIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingGearIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingGearIconOn_ca.paa";
			colorOff[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn[] = {1,1,1,0.15};
			colorOn2[] = {1,1,1,0.15};
		};
		class FlapsIcon
		{
			type = "Flaps";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\FlapsIconOff_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\FlapsIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\FlapsIconOn2_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class AutohoverIcon
		{
			type = "Autohover";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\AutohoverIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\AutohoverIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\AutohoverIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class LandingAutopilotIcon
		{
			type = "LandingAutopilot";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingAutopilotIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingAutopilotIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\LandingAutopilotIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class SlingLoadRopeIcon
		{
			type = "SlingLoadRope";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\SlingLoadRopeIconOn2_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class PeriscopeDepthIcon
		{
			type = "PeriscopeDeep";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\PeriscopeIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\PeriscopeIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\PeriscopeIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class VTolIcon
		{
			type = "VTol";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VTOLIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VTOLIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VTOLIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class TRQIcon
		{
			type = "Torque";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\TRQIconOff_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\TRQIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\TRQIconOn2_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_A',1.0])"};
		};
		class RPMIcon
		{
			type = "RPM";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\RPMIconOn2_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\RPMIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\RPMIconOff_ca.paa";
			colorOff[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_ERROR_RGB_A',1.0])"};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
			colorOn2[] = {1,1,1,0.15};
		};
		class WheelBrakeIcon
		{
			type = "WheelBrake";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\WheelBreakIconOn_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\WheelBreakIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\WheelBreakIconOn_ca.paa";
			colorOff[] = {1,1,1,0.15};
			colorOn[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
		class VehicleCargoIcon
		{
			type = "VehicleCargo";
			textureOff = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VehicleCargoIconOff_ca.paa";
			textureOn = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VehicleCargoIconOn_ca.paa";
			textureOn2 = "\A3\Ui_f\data\IGUI\Cfg\VehicleToggles\VehicleCargoIconOn2_ca.paa";
			colorOff[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])","(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])","(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])","(profilenamespace getvariable ['IGUI_WARNING_RGB_A',0.8])"};
			colorOn[] = {1,1,1,0.15};
			colorOn2[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
		};
	};
};
class RscTrafficLight: RscActiveText
{
	style = 48;
	color[] = {1,1,1,0.7};
	colorText[] = {1,1,1,0.7};
	colorActive[] = {1,1,1,1};
	text = "\A3\Ui_f\data\GUI\RscCommon\RscTrafficLight\TrafficLight_ca.paa";
	tooltip = "You are running a modded version of the game. Click to see the list of active mods.";
	x = "SafezoneX + SafezoneW - (2 * GUI_GRID_W)";
	y = "23 * GUI_GRID_H + (safezoneY + safezoneH - GUI_GRID_HAbs)";
	w = "1 * GUI_GRID_W";
	h = "1 * GUI_GRID_H";
};
class RscButtonSearch: RscButton
{
	idc = 646;
	style = "0x02 + 0x30 + 0x800";
	text = "\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_start_ca.paa";
	textSearch = "\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_end_ca.paa";
	tooltip = "Search";
	onButtonClick = "_display = ctrlparent (_this select 0);_ctrlSearch = _display displayctrl 645;_ctrlSearch ctrlsettext '';ctrlsetfocus _ctrlSearch;";
};
class RscMsgBoxKeysPreset: RscControlsGroupNoScrollbars
{
	scriptName = "RscMsgBoxKeysPreset";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscMsgBoxKeysPreset"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscMsgBoxKeysPreset"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	idc = -1;
	deletable = 1;
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	class controls
	{
		class Background: RscText
		{
			colorBackground[] = {1,1,1,0.5};
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class Vignette: RscVignette
		{
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class MessageBox: RscControlsGroupNoScrollbars
		{
			x = "(safezoneWAbs - 18 * GUI_GRID_W) / 2";
			y = "(safezoneH - 10 * GUI_GRID_H) / 2";
			idc = 2300;
			w = "18 * GUI_GRID_W";
			h = "10.5 * GUI_GRID_H";
			class controls
			{
				class BackgroundImage: RscPicture
				{
					idc = 1200;
					text = "\a3\Ui_f\data\GUI\RscCommon\RscMsgBoxKeysPresets\background_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class LogoTextBackground: RscText
				{
					idc = 1000;
					x = "0 * GUI_GRID_W";
					y = "6 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "3 * GUI_GRID_H";
					colorText[] = {0,0,0,0};
					colorBackground[] = {0,0,0,0.6};
				};
				class Logo: RscPicture
				{
					idc = 1201;
					text = "\A3\Data_F_Exp\Logos\arma3_exp_logo_ca.paa";
					x = "0.25 * GUI_GRID_W";
					y = "6.25 * GUI_GRID_H";
					w = "2.5 * GUI_GRID_W";
					h = "2.5 * GUI_GRID_H";
				};
				class Text: RscText
				{
					shadow = 0;
					style = "0x10+0x200";
					sizeEx = "GUI_TEXT_SIZE_SMALL";
					idc = 1001;
					text = "Arma 3 Apex introduces new controls preset. Do you want to go to the controls menu and preview it?";
					x = "3 * GUI_GRID_W";
					y = "6.5 * GUI_GRID_H";
					w = "14.5 * GUI_GRID_W";
					h = "2 * GUI_GRID_H";
					colorText[] = {1,1,1,1};
				};
				class ButtonClose: RscButtonMenuCancel
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Not now";
					x = "0 * GUI_GRID_W";
					y = "9.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
				class ButtonOK: RscButtonMenuOK
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Yes";
					x = "11.5 * GUI_GRID_W";
					y = "9.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
			};
		};
	};
};
class RscMsgBoxKeysPresetJets: RscControlsGroupNoHScrollbars
{
	scriptName = "RscMsgBoxKeysPresetJets";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscMsgBoxKeysPresetJets"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscMsgBoxKeysPresetJets"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	idc = -1;
	deletable = 1;
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	class controls
	{
		class Background: RscText
		{
			colorBackground[] = {1,1,1,0.5};
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class Vignette: RscVignette
		{
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class MessageBox: RscControlsGroupNoScrollbars
		{
			x = "(safezoneWAbs - 18 * GUI_GRID_W) / 2";
			y = "(safezoneH - 10 * GUI_GRID_H) / 2";
			idc = 2300;
			w = "18 * GUI_GRID_W";
			h = "11.5 * GUI_GRID_H";
			class controls
			{
				class BackgroundImage: RscPicture
				{
					idc = 1200;
					text = "\a3\Ui_f\data\GUI\RscCommon\RscMsgBoxKeysPresetsJets\background_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
				};
				class LogoTextBackground: RscText
				{
					idc = 1000;
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
					colorText[] = {0,0,0,0};
					colorBackground[] = {0,0,0,0.6};
				};
				class Logo: RscPicture
				{
					idc = 1201;
					text = "\A3\Data_F_Jets\Logos\jets_logo_ca.paa";
					x = "0.25 * GUI_GRID_W";
					y = "0.25 * GUI_GRID_H";
					w = "2.5 * GUI_GRID_W";
					h = "2.5 * GUI_GRID_H";
				};
				class Text: RscStructuredText
				{
					shadow = 0;
					style = "0x10+0x200";
					sizeEx = "GUI_TEXT_SIZE_SMALL";
					idc = 1001;
					text = "With the addition of these new features and deepening of existing gameplay, there have been several <t color='%1'>control additions and tweaks</t>. You can inspect these in the CONTROLS section of the OPTIONS menu. It's also possible to reset to the Arma 3 or now standard Arma 3 Apex PRESETS, but please be aware that doing so will remove any customized control bindings.";
					x = "3 * GUI_GRID_W";
					y = "0.25 * GUI_GRID_H";
					w = "14.5 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
					colorText[] = {1,1,1,1};
				};
				class ButtonClose: RscButtonMenuCancel
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Close";
					x = "0 * GUI_GRID_W";
					y = "10.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
				class ButtonOK: RscButtonMenuOK
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Controls";
					tooltip = "View or change game controls.";
					x = "11.5 * GUI_GRID_W";
					y = "10.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
			};
		};
	};
};
class RscMsgBoxKeysPresetCustomInfoPanel: RscControlsGroupNoHScrollbars
{
	scriptName = "RscMsgBoxKeysPresetCustomInfoPanel";
	scriptPath = "GUI";
	onLoad = "[""onLoad"",_this,""RscMsgBoxKeysPresetCustomInfoPanel"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscMsgBoxKeysPresetCustomInfoPanel"",'GUI',0] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
	idc = -1;
	deletable = 1;
	x = "safezoneXAbs";
	y = "safezoneY";
	w = "safezoneWAbs";
	h = "safezoneH";
	class controls
	{
		class Background: RscText
		{
			colorBackground[] = {1,1,1,0.5};
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class Vignette: RscVignette
		{
			x = 0;
			y = 0;
			w = "safezoneWAbs";
			h = "safezoneH";
		};
		class MessageBox: RscControlsGroupNoScrollbars
		{
			x = "(safezoneWAbs - 18 * GUI_GRID_W) / 2";
			y = "(safezoneH - 10 * GUI_GRID_H) / 2";
			idc = 2300;
			w = "18 * GUI_GRID_W";
			h = "11.5 * GUI_GRID_H";
			class controls
			{
				class BackgroundImage: RscPicture
				{
					idc = 1200;
					text = "\A3\Ui_f\data\GUI\RscCommon\RscMsgBoxKeysPresetCustomInfoPanel\background_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
				};
				class LogoTextBackground: RscText
				{
					idc = 1000;
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
					colorText[] = {0,0,0,0};
					colorBackground[] = {0,0,0,0.6};
				};
				class Logo: RscPicture
				{
					idc = 1201;
					text = "\A3\Ui_f\data\GUI\RscCommon\RscMsgBoxKeysPresetCustomInfoPanel\infoPanelIcon_ca.paa";
					x = "0.25 * GUI_GRID_W";
					y = "0.25 * GUI_GRID_H";
					w = "2.5 * GUI_GRID_W";
					h = "2.5 * GUI_GRID_H";
				};
				class Text: RscStructuredText
				{
					shadow = 0;
					style = "0x10+0x200";
					sizeEx = "GUI_TEXT_SIZE_SMALL";
					idc = 1001;
					text = "$str_a3_rscmsgboxkeyspresetcustominfopanel_text";
					x = "3 * GUI_GRID_W";
					y = "0.25 * GUI_GRID_H";
					w = "14.5 * GUI_GRID_W";
					h = "10 * GUI_GRID_H";
					colorText[] = {1,1,1,1};
				};
				class ButtonClose: RscButtonMenuCancel
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Not now";
					x = "0 * GUI_GRID_W";
					y = "10.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
				class ButtonOK: RscButtonMenuOK
				{
					onButtonClick = "ctrlDelete (ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0));";
					text = "Controls";
					tooltip = "View or change game controls.";
					x = "11.5 * GUI_GRID_W";
					y = "10.1 * GUI_GRID_H";
					w = "6.5 * GUI_GRID_W";
					h = "1 * GUI_GRID_H";
				};
			};
		};
	};
};
class RscControlsTable
{
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	type = 19;
	style = 16;
	lineSpacing = 0;
	rowHeight = "GUI_GRID_H";
	headerHeight = "GUI_GRID_H";
	firstIDC = -1;
	lastIDC = -1;
	selectedRowColorFrom[] = {0.7,0.85,1,0.25};
	selectedRowColorTo[] = {0.7,0.85,1,0.5};
	selectedRowAnimLength = 1.2;
	class VScrollBar: ScrollBar
	{
		width = 0.021;
	};
	class HScrollBar: ScrollBar
	{
		height = 0.028;
	};
	class RowTemplate
	{
	};
	class HeaderTemplate
	{
	};
};
class RscIGUIText: RscText
{
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
	style = 0;
};
class RscOpticsText: RscText
{
	sizeEx = 0.048;
	colorText[] = {0.95,0.95,0.95,1};
	style = 0;
	h = 0.048;
};
class RscOpticsValue: RscOpticsText
{
	fixedWidth = 1;
};
class RscIGUIValue: RscIGUIText
{
	sizeEx = "GUI_TEXT_SIZE_SMALL";
	colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
	style = 0;
};
class RscButtonMenuMain: RscButtonMenu
{
	size = "(pixelH * pixelGrid * 2)";
	style = "0x00 + 0xC0";
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
	style = "0x02 + 0x10";
	text = "Line 1\nLine 2";
	shadow = 1;
	x = 0;
	y = 0;
	w = "10 * (pixelW * pixelGrid * 2)";
	h = "10 * (pixelH * pixelGrid * 2)";
};
class RscMainMenuSpotlight: RscControlsGroupNoScrollbars
{
	fade = 1;
	x = "0.5 - (1.5 * 10) * (pixelW * pixelGridNoUIScale * 2) - (2 * pixelW)";
	y = "0.5 - (10 / 2) * (pixelH * pixelGridNoUIScale * 2)";
	w = "10 * (pixelW * pixelGridNoUIScale * 2)";
	h = "10 * (pixelH * pixelGridNoUIScale * 2)";
	class Controls
	{
		class GroupPicture: RscControlsGroupNoScrollbars
		{
			x = 0;
			y = 0;
			w = "10 * (pixelW * pixelGridNoUIScale * 2)";
			h = "10 * (pixelH * pixelGridNoUIScale * 2)";
			class Controls
			{
				class Picture: RscPictureKeepAspect
				{
					idc = 1023;
					text = "#(argb,8,8,3)color(1,0,1,1)";
					x = 0;
					y = 0;
					w = "10 * (pixelW * pixelGridNoUIScale * 2)";
					h = "10 * (pixelH * pixelGridNoUIScale * 2)";
				};
				class Video: RscVideo
				{
					idc = 1024;
					show = 0;
					x = 0;
					y = 0;
					w = "10 * (pixelW * pixelGridNoUIScale * 2)";
					h = "10 * (pixelH * pixelGridNoUIScale * 2)";
				};
			};
		};
		class GroupHover: RscControlsGroupNoScrollbars
		{
			idc = 1025;
			fade = 1;
			x = 0;
			y = 0;
			w = "10 * (pixelW * pixelGridNoUIScale * 2)";
			h = "10 * (pixelH * pixelGridNoUIScale * 2)";
			class Controls
			{
				class Overlay: RscPicture
				{
					text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\hover_ca.paa";
					colorText[] = {0,0,0,0.5};
					x = 0;
					y = 0;
					w = "10 * (pixelW * pixelGridNoUIScale * 2)";
					h = "10 * (pixelH * pixelGridNoUIScale * 2)";
				};
				class LineLeft: RscText
				{
					colorBackground[] = {1,1,1,1};
					x = 0;
					y = 0;
					w = "pixelW";
					h = "10 * (pixelH * pixelGridNoUIScale * 2)";
				};
				class LineRight: LineLeft
				{
					x = "10 * (pixelW * pixelGridNoUIScale * 2) - pixelW";
				};
				class LineTop: LineLeft
				{
					idc = 1027;
					x = 0;
					y = 0;
					w = "10 * (pixelW * pixelGridNoUIScale * 2)";
					h = "(pixelH * pixelGrid * 2)";
					colorText[] = {0,0,0,1};
					shadow = 0;
					style = 0;
					sizeEx = "(pixelH * pixelGrid * 2)";
					font = "PuristaLight";
					onLoad = "(_this select 0) ctrlsettext toupper ctrltext (_this select 0);";
				};
				class LineBottom: LineTop
				{
					y = "10 * (pixelH * pixelGridNoUIScale * 2) - pixelH";
					h = "pixelH";
				};
			};
		};
		class TextBackground: RscPicture
		{
			idc = 1029;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\spotlight_backgroundText_ca.paa";
			colorText[] = {0,0,0,0.5};
			x = 0;
			y = 0;
			w = "10 * (pixelW * pixelGridNoUIScale * 2)";
			h = "10 * (pixelH * pixelGridNoUIScale * 2)";
		};
		class Text: RscStructuredText
		{
			idc = 1028;
			size = "1.00 * (pixelH * pixelGridNoUIScale * 2)";
			shadow = 2;
			x = 0;
			y = 0;
			w = "10 * (pixelW * pixelGridNoUIScale * 2)";
			h = "10 * (pixelH * pixelGridNoUIScale * 2)";
			class Attributes
			{
				align = "center";
				color = "#ffffff";
				font = "PuristaBold";
			};
		};
		class Button: RscButton
		{
			idc = 1026;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			x = 0;
			y = 0;
			w = "10 * (pixelW * pixelGridNoUIScale * 2)";
			h = "10 * (pixelH * pixelGridNoUIScale * 2)";
		};
	};
};
class RscDisplaySingleMission_ChallengeOverviewGroup: RscControlsGroupNoHScrollbars
{
	idc = 2302;
	x = "17 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)";
	y = "SafezoneY + (18.4 * GUI_GRID_H) + (0.5 * (safezoneH - GUI_GRID_HAbs))";
	w = "22 * GUI_GRID_W";
	h = "3.5 * GUI_GRID_H + (0.5 * (safezoneH - GUI_GRID_HAbs))";
	class controls
	{
	};
};
class RscDisplayDebriefing_RscTextMultiline: RscText
{
	style = "0x10+0x200";
};
class RscDisplayDebriefing_ListGroup: RscControlsGroupNoHScrollbars
{
	idc = 21903;
	x = "2.2 * GUI_GRID_W + (safezoneX + (safezoneW - GUI_GRID_WAbs)/2)";
	y = "8.9 * GUI_GRID_H + (safezoneY + (safezoneH - GUI_GRID_HAbs)/2)";
	w = "36.8 * GUI_GRID_W";
	h = "12.2 * GUI_GRID_H";
	class controls
	{
	};
};
class RscButtonArsenal: RscButton
{
	style = "0x30 + 0x800";
	colorBackground[] = {0,0,0,0.8};
	colorDisabled[] = {1,1,1,1};
};
class RscDisplayDLCContentBrowser_DLC: RscControlsGroupNoScrollbars
{
	class Controls
	{
		class PictureBackground: RscText
		{
			idc = 2000;
			colorBackground[] = {0,0,0,1};
		};
		class Picture: RscPicture
		{
			idc = 2001;
		};
		class Video: RscControlsGroupNoScrollbars
		{
			idc = 2002;
			class Controls
			{
			};
		};
		class Icon: RscPicture
		{
			idc = 2004;
		};
		class LineL: RscText
		{
			idc = 2005;
			fade = 1;
			w = "pixelW";
		};
		class LineR: LineL
		{
			idc = 2006;
		};
		class LineT: LineL
		{
			idc = 2007;
			h = "GUI_GRID_H";
			text = "Purchase";
			style = 2;
		};
		class LineB: LineL
		{
			idc = 2008;
			h = "pixelH";
		};
		class Title: RscText
		{
			idc = 2010;
			h = "1.2 * GUI_GRID_H";
			sizeEx = "1.2 * GUI_GRID_H";
			font = "RobotoCondensedBold";
			style = 2;
			shadow = 0;
		};
		class Button: RscButton
		{
			idc = 2009;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
		};
		class Hover: RscText
		{
			idc = 2011;
			colorBackground[] = {1,1,1,0.2};
			fade = 1;
		};
	};
};
class RscDisplayDLCPreview_List: RscControlsGroupNoScrollbars
{
	x = 0;
	y = 0;
	w = "38 * GUI_GRID_W";
	h = "15 * GUI_GRID_H";
	class Controls
	{
		class PictureGroup: RscControlsGroupNoScrollbars
		{
			idc = 32563;
			x = "1 * GUI_GRID_W + 0";
			y = "1 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "9 * GUI_GRID_H";
			class Controls
			{
				class PictureAnimBackground: RscPicture
				{
					idc = 31472;
					text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\background_co.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureAnim: RscPictureKeepAspect
				{
					idc = 31463;
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureAnimOverlay: RscPicture
				{
					show = 0;
					idc = 31467;
					text = "\A3\Ui_f\data\GUI\Rsc\RscDisplaySingleMission\Stripe_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureAnimOverlayIcon: RscPicture
				{
					show = 0;
					idc = 31469;
					text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\overlayIcon_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureBackground: RscPicture
				{
					idc = 31471;
					text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\background_co.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class Picture: RscPictureKeepAspect
				{
					idc = 31464;
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureOverlay: RscPicture
				{
					show = 0;
					idc = 31468;
					text = "\A3\Ui_f\data\GUI\Rsc\RscDisplaySingleMission\Stripe_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
				class PictureOverlayIcon: RscPicture
				{
					show = 0;
					idc = 31470;
					text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\overlayIcon_ca.paa";
					x = "0 * GUI_GRID_W";
					y = "0 * GUI_GRID_H";
					w = "18 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
			};
		};
		class BrowsePrev: RscActivePicture
		{
			color[] = {1,1,1,0.5};
			idc = 31465;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\browsePrev_ca.paa";
			x = "1.5 * GUI_GRID_W + 0";
			y = "1.5 * GUI_GRID_H + 0";
			w = "1 * GUI_GRID_W";
			h = "8 * GUI_GRID_H";
		};
		class BrowseNext: BrowsePrev
		{
			idc = 31466;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\browseNext_ca.paa";
			x = "17.5 * GUI_GRID_W + 0";
			y = "1.5 * GUI_GRID_H + 0";
			w = "1 * GUI_GRID_W";
			h = "8 * GUI_GRID_H";
		};
		class PictureListGroup: RscControlsGroup
		{
			idc = 32564;
			x = "1 * GUI_GRID_W + 0";
			y = "10.5 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "4 * GUI_GRID_H";
			class Controls
			{
			};
		};
		class InfoTitle: RscText
		{
			style = 2;
			shadow = 0;
			idc = 31264;
			x = "19.5 * GUI_GRID_W + 0";
			y = "1 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "2 * GUI_GRID_H";
			colorBackground[] = {1,0,1,1};
			sizeEx = "1.5 * GUI_GRID_H";
		};
		class Background: RscText
		{
			idc = 31263;
			x = "19.5 * GUI_GRID_W + 0";
			y = "3 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "11.5 * GUI_GRID_H";
			colorBackground[] = {0.1,0.1,0.1,0.8};
		};
		class BackgroundBottom: RscText
		{
			idc = 31266;
			x = "19.5 * GUI_GRID_W + 0";
			y = "12 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "2.5 * GUI_GRID_H";
			colorBackground[] = {1,1,1,0.05};
		};
		class InfoGroup: RscControlsGroup
		{
			idc = 32565;
			x = "19.5 * GUI_GRID_W + 0";
			y = "3 * GUI_GRID_H + 0";
			w = "18 * GUI_GRID_W";
			h = "9 * GUI_GRID_H";
			class Controls
			{
				class Info: RscStructuredText
				{
					idc = 31363;
					x = "0.5 * GUI_GRID_W";
					y = "0.5 * GUI_GRID_H";
					w = "17 * GUI_GRID_W";
					h = "9 * GUI_GRID_H";
				};
			};
		};
		class ButtonTry: RscButtonMenu
		{
			show = 0;
			idc = 32663;
			text = "Try";
			x = "31 * GUI_GRID_W + 0";
			y = "12.75 * GUI_GRID_H + 0";
			w = "6 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class ButtonPurchase: RscButtonMenuSteam
		{
			show = 0;
			idc = 32664;
			text = "Purchase";
			x = "31 * GUI_GRID_W + 0";
			y = "12.75 * GUI_GRID_H + 0";
			w = "6 * GUI_GRID_W";
			h = "1 * GUI_GRID_H";
		};
		class InfoStats: RscStructuredText
		{
			idc = 31364;
			x = "19.5 * GUI_GRID_W + 0";
			y = "12.25 * GUI_GRID_H + 0";
			w = "11 * GUI_GRID_W";
			h = "2 * GUI_GRID_H";
		};
	};
};
class RscDisplayDLCPreview_ListItem: RscControlsGroup
{
	idc = 43183;
	x = "0 * GUI_GRID_W + 0";
	y = "0 * GUI_GRID_H + 0";
	w = "6 * GUI_GRID_W";
	h = "4 * GUI_GRID_H";
	class Controls
	{
		class Select: RscText
		{
			fade = 1;
			idc = 41883;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "6 * GUI_GRID_W";
			h = "3.1 * GUI_GRID_H";
			colorBackground[] = {1,1,1,1};
		};
		class Hover: RscText
		{
			fade = 1;
			idc = 41884;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "6 * GUI_GRID_W";
			h = "3.1 * GUI_GRID_H";
			colorBackground[] = {1,1,1,1};
		};
		class Background: RscPicture
		{
			idc = 42085;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\background_co.paa";
			x = "0.1 * GUI_GRID_W";
			y = "0.1 * GUI_GRID_H";
			w = "5.8 * GUI_GRID_W";
			h = "2.9 * GUI_GRID_H";
			colorBackground[] = {1,1,1,1};
		};
		class Picture: RscPictureKeepAspect
		{
			idc = 42083;
			text = "#(argb,8,8,3)color(1,0,1,1)";
			x = "0.1 * GUI_GRID_W";
			y = "0.1 * GUI_GRID_H";
			w = "5.8 * GUI_GRID_W";
			h = "2.9 * GUI_GRID_H";
		};
		class Button: RscButton
		{
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			idc = 42483;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "6 * GUI_GRID_W";
			h = "3.1 * GUI_GRID_H";
		};
		class SessionNotification: RscPicture
		{
			show = 0;
			idc = 42084;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayDLCPreview\session_ca.paa";
			x = "0.1 * GUI_GRID_W";
			y = "2.2 * GUI_GRID_H";
			w = "0.7 * GUI_GRID_W";
			h = "0.7 * GUI_GRID_H";
		};
	};
};
class RscDisplayDLCPreview_ListItemSquare: RscDisplayDLCPreview_ListItem
{
	w = "3 * GUI_GRID_W";
	class Controls: Controls
	{
		class Select: Select
		{
			w = "3 * GUI_GRID_W";
		};
		class Hover: Hover
		{
			w = "3 * GUI_GRID_W";
		};
		class Background: Background
		{
			text = "#(argb,8,8,3)color(0,0,0,0)";
			w = "2.8 * GUI_GRID_W";
		};
		class Picture: Picture
		{
			w = "2.8 * GUI_GRID_W";
		};
		class Button: Button
		{
			w = "3 * GUI_GRID_W";
		};
	};
};
class RscTextNoShadow: RscText
{
	style = 2;
	shadow = 0;
};
class RscButtonNoColor: RscButton
{
	colorBackground[] = {0,0,0,0};
	colorText[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	colorFocused[] = {0,0,0,0};
	text = "";
	soundEnter[] = {"\A3\ui_f\data\sound\ReadOut\readoutClick",0.5,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\CfgNotifications\addItemOK",0.5,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
};
class RscDisplayMPScoreTable_SideLineTemplate: RscControlsGroup
{
	idc = 104;
	x = "0 * GUI_GRID_W";
	y = "0 * GUI_GRID_H";
	w = "38 * GUI_GRID_W";
	h = "0.8 * GUI_GRID_H";
	class controls
	{
		class LineBackground: RscText
		{
			idc = 105;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "38 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class PlayersName: RscText
		{
			idc = 107;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			text = "Player 007";
			x = "0 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "15 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class KillsInfantry: RscText
		{
			idc = 108;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "10";
			x = "15 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.2 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class KillsSoft: RscText
		{
			idc = 109;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "10";
			x = "18.2 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.2 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class KillsArmor: RscText
		{
			idc = 110;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "10";
			x = "21.4 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.2 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class KillsAir: RscText
		{
			idc = 111;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "10";
			x = "24.6 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.2 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class Killed: RscText
		{
			idc = 112;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "10";
			x = "27.8 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "3.2 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class KillsTotal: RscText
		{
			idc = 113;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			style = 2;
			text = "150";
			x = "31 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "6 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
	};
};
class RscDisplayMPScoreTable_LineTemplate: RscDisplayMPScoreTable_SideLineTemplate
{
	class controls: controls
	{
		class LineBackground: LineBackground
		{
		};
		class KillsInfantry: KillsInfantry
		{
		};
		class KillsSoft: KillsSoft
		{
		};
		class KillsArmor: KillsArmor
		{
		};
		class KillsAir: KillsAir
		{
		};
		class Killed: Killed
		{
		};
		class KillsTotal: KillsTotal
		{
		};
		class Order: RscText
		{
			idc = 106;
			sizeEx = "GUI_TEXT_SIZE_SMALL";
			shadow = 0;
			text = "1";
			x = "0.5 * GUI_GRID_W";
			y = "0 * GUI_GRID_H";
			w = "1.5 * GUI_GRID_W";
			h = "0.8 * GUI_GRID_H";
		};
		class PlayersName: PlayersName
		{
			x = "2 * GUI_GRID_W";
			w = "13 * GUI_GRID_W";
		};
	};
};
class ctrlStaticPicture: ctrlStatic
{
	style = 48;
};
class ctrlStaticPictureKeepAspect: ctrlStaticPicture
{
	style = "0x30 + 0x800";
};
class ctrlStaticPictureTile: ctrlStatic
{
	style = 144;
};
class ctrlStaticFrame: ctrlStatic
{
	style = 64;
};
class ctrlStaticLine: ctrlStatic
{
	style = 176;
};
class ctrlStaticMulti: ctrlStatic
{
	style = "0x10 + 0x200";
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
	colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
class ctrlButtonPicture: ctrlButton
{
	style = "0x02 + 0x30";
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
	style = "0x02 + 0x30 + 0x800";
	text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
	textSearch = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
	tooltip = "Search";
};
class ctrlButtonExpandAll: ctrlButtonToolbar
{
	style = "0x02 + 0x30 + 0x800";
	text = "\a3\3DEN\Data\Displays\Display3DEN\tree_expand_ca.paa";
	tooltip = "Expand All";
};
class ctrlButtonCollapseAll: ctrlButtonToolbar
{
	style = "0x02 + 0x30 + 0x800";
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
	type = 2;
	colorBackground[] = {0,0,0,0.5};
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = 16;
};
class ctrlSliderV: ctrlDefault
{
	type = 3;
	style = 0;
	color[] = {0,0,0,1};
	colorDisabled[] = {1,1,1,0.25};
	colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	sliderRange[] = {0,1};
	sliderPosition = 1;
	lineSize = 0.1;
	pageSize = 3;
	class Title
	{
		idc = -1;
		colorBase[] = {1,1,1,1};
		colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	};
	class Value
	{
		idc = -1;
		format = "%.f";
		type = "SPTPlain";
		colorBase[] = {1,1,1,1};
		colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = 1024;
};
class ctrlCombo: ctrlDefaultText
{
	type = 4;
	style = "0x00 + 0x10 + 0x200";
	colorBackground[] = {0.05,0.05,0.05,1};
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	wholeHeight = "12 * 5 * (pixelH * pixelGrid * 0.50)";
	maxHistoryDelay = 1;
	soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1};
	soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1};
	soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1};
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
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmptyToolbar_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmptyToolbar_ca.paa";
	wholeHeight = "12 * 5 * (pixelH * pixelGrid * 0.50)";
};
class ctrlListbox: ctrlDefaultText
{
	type = 5;
	style = "0x00 + 0x10";
	colorBackground[] = {0,0,0,0.5};
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorSelectBackground2[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
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
	type = 6;
	style = 2;
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
	colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = "0x02 + 0x30";
};
class ctrlToolboxPictureKeepAspect: ctrlToolbox
{
	style = "0x02 + 0x30 + 0x800";
};
class ctrlCheckboxes: ctrlDefaultText
{
	type = 7;
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
	colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = 48;
	strings[] = {"\a3\3DEN\Data\Controls\ctrlCheckbox\textureUnchecked_ca.paa"};
	checked_strings[] = {"\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa"};
	colorBackground[] = {0,0,0,0};
	colorSelectedBg[] = {0,0,0,0};
};
class ctrlProgress: ctrlDefault
{
	type = 8;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
	colorBar[] = {1,1,1,1};
	colorFrame[] = {0,0,0,1};
	onCanDestroy = "";
	onDestroy = "";
};
class ctrlHTML: ctrlDefaultText
{
	type = 9;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	colorBold[] = {1,1,1,0.5};
	colorLink[] = {1,1,1,1};
	colorLinkActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = "0x30 + 0x800";
};
class ctrlTree: ctrlDefaultText
{
	type = 12;
	colorBorder[] = {0,0,0,1};
	colorLines[] = {0,0,0,0};
	colorBackground[] = {0,0,0,0};
	colorSelect[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorMarked[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",0.5};
	colorMarkedSelected[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {1,1,1,1};
	colorMarkedText[] = {1,1,1,1};
	colorSearch[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	type = 16;
	style = 192;
	colorBackground[] = {0,0,0,1};
	colorBackground2[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	shortcuts[] = {"0x00050000 + 0",28,57,156};
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
		left = "1.5 * 5 * (pixelW * pixelGrid * 0.50)";
		top = 0;
		right = 0;
		bottom = 0;
	};
	class ShortcutPos
	{
		left = 0;
		top = 0;
		w = "5 * (pixelW * pixelGrid * 0.50)";
		h = "5 * (pixelH * pixelGrid * 0.50)";
	};
};
class ctrlXListbox: ctrlDefaultText
{
	type = 42;
	style = "0x400 + 0x02 + 0x10";
	color[] = {1,1,1,1};
	colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorText[] = {1,1,1,1};
	colorSelect[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	cycle = 1;
	arrowEmpty = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowEmpty_ca.paa";
	arrowFull = "\a3\3DEN\Data\Controls\CtrlXSlider\arrowFull_ca.paa";
	border = "\a3\3DEN\Data\Controls\CtrlXSlider\border_ca.paa";
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
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
	type = 43;
	style = 0;
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
		colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	};
	class Value
	{
		idc = -1;
		format = "%.f";
		type = "SPTPlain";
		colorBase[] = {1,1,1,1};
		colorActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	style = 1024;
};
class ctrlMenu: ctrlDefaultText
{
	type = 46;
	font = "RobotoCondensedLight";
	colorBorder[] = {0,0,0,0};
	colorBackground[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorSelect[] = {0,0,0,1};
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	colorStripSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorStripDisabled[] = {1,1,1,0.25};
};
class ctrlMap: ctrlDefault
{
	type = 101;
	style = 48;
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
	shadedSea = 0.3;
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
	colorForestBorder[] = {0,0,0,0};
	colorRocks[] = {0,0,0,0.3};
	colorRocksBorder[] = {0,0,0,0};
	colorLevels[] = {0.286,0.177,0.094,0.5};
	colorMainCountlines[] = {0.572,0.354,0.188,0.5};
	colorCountlines[] = {0.572,0.354,0.188,0.25};
	colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
	colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
	colorPowerLines[] = {0.1,0.1,0.1,1};
	colorRailWay[] = {1,0,0,1};
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
	widthRailWay = 4;
	fontLabel = "RobotoCondensedLight";
	sizeExLabel = 0.05;
	fontGrid = "TahomaB";
	sizeExGrid = 0.02;
	fontUnits = "TahomaB";
	sizeExUnits = 0.05;
	fontNames = "RobotoCondensed";
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
	type = 102;
	style = "0x00 + 0x10";
	colorSelectBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorSelectBackground2[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
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
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
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
	colorBackgroundHover[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
	colorBackgroundPressed[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1};
};
class ctrlControlsGroupHighlight: ctrlControlsGroupNoScrollbars
{
	class Controls
	{
		class TL: ctrlStaticPicture
		{
			idc = 313130;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_TL_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class TM: ctrlStaticPicture
		{
			idc = 313131;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_TM_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class TR: ctrlStaticPicture
		{
			idc = 313132;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_TR_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class ML: ctrlStaticPicture
		{
			idc = 313133;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_ML_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class MR: ctrlStaticPicture
		{
			idc = 313134;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_MR_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class BL: ctrlStaticPicture
		{
			idc = 313135;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_BL_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class BM: ctrlStaticPicture
		{
			idc = 313136;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_BM_ca.paa";
			colorText[] = {0,1,1,1};
		};
		class BR: ctrlStaticPicture
		{
			idc = 313137;
			text = "\a3\3DEN\Data\ControlsGroups\Highlight\highlight_BR_ca.paa";
			colorText[] = {0,1,1,1};
		};
	};
};
class ctrlControlsGroupTutorial: ctrlControlsGroupNoScrollbars
{
	w = "(80 + 1) * (pixelW * pixelGrid * 0.50)";
	h = 0;
	class Controls
	{
		class Shadow: ctrlStatic
		{
			idc = 323231;
			x = "3 * pixelW";
			y = "3 * pixelH";
			w = "80 * (pixelW * pixelGrid * 0.50)";
			h = "40 * (pixelH * pixelGrid * 0.50)";
			colorBackground[] = {0,0,0,0.75};
		};
		class Background: ctrlStatic
		{
			idc = 323232;
			w = "80 * (pixelW * pixelGrid * 0.50)";
			h = "40 * (pixelH * pixelGrid * 0.50)";
			colorBackground[] = {1,0.9,0.4,1};
		};
		class Text: ctrlStructuredText
		{
			idc = 323233;
			x = "3 * (pixelW * pixelGrid * 0.50)";
			y = "(3 + 1) * (pixelH * pixelGrid * 0.50)";
			w = "(80 - 2 * 3) * (pixelW * pixelGrid * 0.50)";
			h = "20 * (pixelH * pixelGrid * 0.50)";
			shadow = 0;
			class Attributes: Attributes
			{
				color = "#000000";
				colorLink = "#0000ff";
			};
		};
		class Page: ctrlStatic
		{
			idc = 323234;
			style = 2;
			y = "(40 - 6 - 1) * (pixelH * pixelGrid * 0.50)";
			w = "80 * (pixelW * pixelGrid * 0.50)";
			h = "6 * (pixelH * pixelGrid * 0.50)";
			colorText[] = {0,0,0,0.2};
			shadow = 0;
		};
		class ButtonClose: ctrlActivePicture
		{
			idc = 323235;
			x = "(80 - 3 - 1) * (pixelW * pixelGrid * 0.50)";
			y = "(pixelH * pixelGrid * 0.50)";
			w = "3 * (pixelW * pixelGrid * 0.50)";
			h = "3 * (pixelH * pixelGrid * 0.50)";
			color[] = {0,0,0,1};
			text = "\a3\3DEN\Data\ControlsGroups\Tutorial\close_ca.paa";
		};
		class ButtonBack: ctrlActivePicture
		{
			idc = 323236;
			x = "1 * (pixelW * pixelGrid * 0.50)";
			y = "(40 - 6 - 1) * (pixelH * pixelGrid * 0.50)";
			w = "6 * (pixelW * pixelGrid * 0.50)";
			h = "6 * (pixelH * pixelGrid * 0.50)";
			color[] = {0,0,0,0.1};
			text = "\a3\3DEN\Data\ControlsGroups\Tutorial\back_ca.paa";
		};
		class ButtonNext: ButtonBack
		{
			idc = 323237;
			x = "(80 - 6 - 1) * (pixelW * pixelGrid * 0.50)";
			y = "(40 - 6 - 1) * (pixelH * pixelGrid * 0.50)";
			w = "6 * (pixelW * pixelGrid * 0.50)";
			h = "6 * (pixelH * pixelGrid * 0.50)";
			color[] = {0,0,0,1};
			text = "\a3\3DEN\Data\ControlsGroups\Tutorial\next_ca.paa";
		};
		class ButtonExit: ButtonBack
		{
			idc = 323238;
			x = "(80 - 6 - 1) * (pixelW * pixelGrid * 0.50)";
			y = "(40 - 6 - 1) * (pixelH * pixelGrid * 0.50)";
			w = "6 * (pixelW * pixelGrid * 0.50)";
			h = "6 * (pixelH * pixelGrid * 0.50)";
			color[] = {0,0,0,1};
			text = "\a3\3DEN\Data\ControlsGroups\Tutorial\exit_ca.paa";
		};
	};
};
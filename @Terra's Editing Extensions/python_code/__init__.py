import re
import os
from pathlib import Path
def replace(pattern, replacement, text, c=0, f=0):
	return re.sub(pattern, replacement, text, c, f)

def regex_ui_config_macros(text):
	# First of all, remove all those annoying tabs in the defines
	text = re.sub(r"(?<=[^\t\n])(\t+)(?=[^\t])", "", text)
	macros = {
		#("MACRO":r"regex"),
		"GUI_GRID_WAbs": r"((safezoneW / safezoneH) min 1.2)",
		"GUI_GRID_HAbs": r"(GUI_GRID_WAbs / 1.2)",
		"GUI_GRID_W": r"(GUI_GRID_WAbs / 40)",
		"GUI_GRID_H": r"(GUI_GRID_HAbs / 25)",
		"GUI_GRID_X": r"(safezoneX)",
		"GUI_GRID_Y": r"(safezoneY + safezoneH - GUI_GRID_HAbs)",
		"GUI_GRID_CENTER_X": r"(safezoneX + (safezoneW - GUI_GRID_WAbs)/2)",
		"GUI_GRID_CENTER_Y": r"(safezoneY + (safezoneH - GUI_GRID_HAbs)/2)",
		# Text sizes
		"GUI_TEXT_SIZE_SMALL": r"(GUI_GRID_H * 0.8)",
		"GUI_TEXT_SIZE_MEDIUM": r"(GUI_GRID_H * 1)",
		"GUI_TEXT_SIZE_LARGE": r"(GUI_GRID_H * 1.2)",
		# Fonts
		"GUI_FONT_NORMAL":	'"RobotoCondensed"',
		"GUI_FONT_BOLD":	'"RobotoCondensedBold"',
		"GUI_FONT_THIN":	'"RobotoCondensedLight"',
		"GUI_FONT_MONO":	'"EtelkaMonospacePro"',
		"GUI_FONT_NARROW":	'"EtelkaNarrowMediumPro"',
		"GUI_FONT_SYSTEM": '"TahomaB"',
		# Colors
		"GUI_BCG_COLOR": """{"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"}""",
		"ProcTextWhite": '"#(argb,8,8,3)color(1,1,1,1)"',
		"ProcTextTransparent": '"#(argb,8,8,3)color(0,0,0,0)"',
		"GUI_TEXT_COLOR": "{1,1,1,1}",
		"Color_Empty": "{0,0,0,0}"
	}
	macros_types = {
		"CT_STATIC":				0,
		"CT_BUTTON":				1,
		"CT_EDIT":					2,
		"CT_SLIDER":				3,
		"CT_COMBO":					4,
		"CT_LISTBOX":				5,
		"CT_TOOLBOX":				6,
		"CT_CHECKBOXES":			7,
		"CT_PROGRESS":				8,
		"CT_HTML":					9,
		"CT_STATIC_SKEW":			10,
		"CT_ACTIVETEXT":			11,
		"CT_TREE":					12,
		"CT_STRUCTURED_TEXT":		13,
		"CT_CONTEXT_MENU":			14,
		"CT_CONTROLS_GROUP":		15,
		"CT_SHORTCUTBUTTON":		16,
		"CT_HITZONES":				17,
		"CT_VEHICLETOGGLES":		18,
		"CT_CONTROLS_TABLE":		19,
		"CT_XKEYDESC":				40,
		"CT_XBUTTON":				41,
		"CT_XLISTBOX":				42,
		"CT_XSLIDER":				43,
		"CT_XCOMBO":				44,
		"CT_ANIMATED_TEXTURE":		45,
		"CT_MENU":					46,
		"CT_MENU_STRIP":			47,
		"CT_CHECKBOX":				77,
		"CT_OBJECT":				80,
		"CT_OBJECT_ZOOM":			81,
		"CT_OBJECT_CONTAINER":		82,
		"CT_OBJECT_CONT_ANIM":		83,
		"CT_LINEBREAK":				98,
		"CT_USER":					99,
		"CT_MAP":					100,
		"CT_MAP_MAIN":				101,
		"CT_LISTNBOX":				102,
		"CT_ITEMSLOT":				103,
		"CT_LISTNBOX_CHECKABLE":	104,
		"CT_VEHICLE_DIRECTION":		105
	}
	""" for m, ct in macros_types:
		macros.append(("type = {}".format(m), "type = {}".format(ct))) """
	macros_styles = [
	]
	for define, define_content in macros:
		# Convert to macro based text
		text = text.replace(define_content, define)
		# Remove strings from the macros so they are actually interpreted
		# as such
		pattern = '\\"(.*?{define}.*?)\\";'.format(define=define)
		
		
		text = re.sub(pattern, "\\1;", text)
		text = re.sub(r'(^[^\"]*?)\"(\".*?\")\"(?!.*?\")', r'\1\2', text, 0, re.MULTILINE)
		
	""" for macro, regex in macros:
		#replace macros
		regex = r"= \"?(?P<pre>.*)" + regex + r"(?P<post>.*?)\"?;"
		macro = r"= \g<pre>" + macro + r"\g<post>;"
		text = re.sub(regex, macro, text, 0, re.MULTILINE)
		#repair double quotes which we ripped out
		dqregex = r"(^[^\"]*?)\"(\".*?\")\"(?!.*?\")"
		text = re.sub(dqregex, "\\1\\2", text, 0, re.MULTILINE) """
	return text

def get_latest_rpt():
	dirrpt = Path(os.getenv('LOCALAPPDATA')) / "Arma 3"
	return max(dirrpt.glob("*.rpt"), key=os.path.getmtime)

def count_rpt_lines():
	rpt = get_latest_rpt()
	with rpt.open() as f:
		for i, _ in enumerate(f):
			pass
	return i+1

def load_rpt_line(load_line=0):
	latest_rpt = get_latest_rpt()
	with latest_rpt.open() as f:
		for _ in range(load_line):
			try:
				next(f)
			except StopIteration:
				line = ""
		line = f.readline().strip('\n')
	return line

import re
def replace(pattern, replacement, text, c=0, f=0):
	return re.sub(pattern, replacement, text, c, f)

def regex_ui_config_macros(text):
	# First of all, remove all those annoying tabs in the defines
	text = re.sub(r"(?<=[^\t\n])(\t+)(?=[^\t])", "", text)
	macros = [
		#("MACRO", r"regex"),
		("GUI_GRID_WAbs", r"\(\(safezoneW / safezoneH\) min 1\.2\)"),
		("GUI_GRID_HAbs", r"\(GUI_GRID_WAbs / 1.2\)"),
		("GUI_GRID_W", r"\(GUI_GRID_WAbs / 40\)"),
		("GUI_GRID_H", r"\(GUI_GRID_HAbs / 25\)"),
		("GUI_GRID_X", r"\(safezoneX\)"),
		("GUI_GRID_Y", r"\(safezoneY + safezoneH - GUI_GRID_HAbs\)"),
		("GUI_GRID_CENTER_X", r"\(safezoneX + \(safezoneW - GUI_GRID_WAbs\)/2\)"),
		("GUI_GRID_CENTER_Y", r"\(safezoneY + \(safezoneH - GUI_GRID_HAbs\)/2\)"),
		# Text sizes
		("GUI_TEXT_SIZE_SMALL", r"\(GUI_GRID_H \* 0\.8\)"),
		("GUI_TEXT_SIZE_SMALL", r"\(GUI_GRID_H \* 1\)"),
		("GUI_TEXT_SIZE_SMALL", r"\(GUI_GRID_H \* 1\.2\)")
	]
	for m, r in macros:
		text = re.sub(r, m, text)
	return text

#test this shit
testFile = "P:\\-Terra-s-Editing-Extensions\\testing\\testcfg.hpp"
with open(testFile) as f:
	content = f.read()

content = regex_ui_config_macros(content)

testOut = "P:\\-Terra-s-Editing-Extensions\\testing\\testcfg_mod.hpp"
with open(testOut, "w") as f:
	f.write(content)
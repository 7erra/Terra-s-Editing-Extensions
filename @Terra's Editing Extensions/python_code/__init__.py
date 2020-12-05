#%%
import re
import os
from pathlib import Path

#%%

def replace(pattern, replacement, text, c=0, f=0):
	return re.sub(pattern, replacement, text, c, f)

def get_latest_rpt(return_string=False):
	dirrpt = Path(os.getenv('LOCALAPPDATA')) / "Arma 3"
	latest_rpr = max(dirrpt.glob("*.rpt"), key=os.path.getmtime)
	if return_string:
		return str(latest_rpr)
	else:
		return latest_rpr

def count_rpt_lines():
	rpt = get_latest_rpt()
	with rpt.open() as f:
		for i, _ in enumerate(f):
			pass
	return i+1

def load_rpt_line(load_line=0, syntax=''):
	latest_rpt = get_latest_rpt()
	with latest_rpt.open() as f:
		for _ in range(load_line):
			try:
				next(f)
			except StopIteration:
				line = ""
		line = f.readline().strip('\n')
		line = highlight(line, syntax)
	return line
#%% Apply highlighting for structured text
def highlight(text, syntax):
	if not syntax:
		return text
	elif syntax == 'rpt':
		text = text.replace('&', '&amp;').replace(r'<', '&lt;').replace(r'>', '&gt;')
		# String
		temp_dq = '__DQ__'
		text = text.replace(r'""', temp_dq)
		text = re.sub(r'(\".*?\")', r"<t color='#ce8349'>\1</t>", text)
		text = text.replace(temp_dq, '""')
		# Number
		text = re.sub(r'(?<!\w|\.)(0[Xx][0-9a-fA-F]+|-?\d+(?:\.\d*)?)(?!\w)', r"<t color='#b5cea8'>\1</t>", text)
		# Error
		text = text.replace('Error', "<t color='#ff0000'>Error</t>")
		return text

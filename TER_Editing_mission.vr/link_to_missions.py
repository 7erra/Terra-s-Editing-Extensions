#%%
from pathlib import Path
import ctypes
from ctypes.wintypes import MAX_PATH

dll = ctypes.windll.shell32
buf = ctypes.create_unicode_buffer(MAX_PATH + 1)
if dll.SHGetSpecialFolderPathW(None, buf, 0x0005, False):
    print(f'Documents folder is: {buf.value}')
else:
    print("Failure! Can't find the ")
ter_mission = Path(buf.value) / 'Arma 3' / 'missions' / 'TER_Editing_mission.vr'
#%%
try:
   ter_mission.symlink_to('P:/Terra-s-Editing-Extensions/TER_Editing_mission.vr')
   print(f'Creation of "{ter_mission}" was successful. A symlinkd has been created')
except FileExistsError:
   print(f'The mission "{ter_mission}" already exists.')

# %%

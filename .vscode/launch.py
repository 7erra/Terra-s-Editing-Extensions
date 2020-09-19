#%% Libraries and...
from pathlib import Path
import subprocess
import json
# ... variables
a3_version = 'arma3diag_x64'
a3_dir = Path('M:\SteamLibraryM\steamapps\common\Arma 3')
a3_exe = a3_dir / f'{a3_version}.exe'

modslist = [r'!Workshop\@CBA_A3',
            r'!Workshop\@Pythia',
            r"P:\Terra-s-Editing-Extensions\@Terra's Editing Extensions"]
mods = f'-mod={";".join(modslist)}'

with open('.vscode/TER_Editing.code-workspace', 'r') as f:
    workspace_settings = json.load(f)
try:
    mission_root = workspace_settings['settings']['A3MissionRoot']
    mission = f'"{mission_root}\\TER_Editing_mission.vr\\mission.sqm"'
except KeyError:
    print('Mission to load is not set in the TER_Editing.code-workspace settings!')
    mission = ''
#%% Launch the game with parameters
print(f'Launching {a3_exe}')
subprocess.Popen([a3_exe.absolute(),
                '-noSplash',
                '-enableHT',
                '-hugePages',
                '-loadMissionToMemory',
                '-noLand',
                '-showScriptErrors',
                '-filePatching',
                '-window',
                '-posX=-1290',
                f'-posY=340',
                mods,
                mission],
                stdout=None,
                stdin=None,
                stderr=None)
# %%

#%%
from pathlib import Path
import subprocess
#%%
a3_version = 'arma3diag_x64'
a3_dir = Path('M:\SteamLibraryM\steamapps\common\Arma 3')
a3_exe = a3_dir / f'{a3_version}.exe'

modslist = [r'!Workshop\@CBA_A3',
            r'!Workshop\@Pythia',
            r"P:\-Terra-s-Editing-Extensions\@Terra's Editing Extensions"]
mods = f'-mod={";".join(modslist)}'

mission = '"E:\Documents\Arma 3\missions\TER_Editing_mission.vr\mission.sqm"'
#%%
subprocess.Popen([a3_exe.absolute(),
                '-noSplash',
                '-enableHT',
                '-hugePages',
                '-loadMissionToMemory',
                '-noLand',
                '-showScriptErrors',
                '-filePatching',
                '-window',
                '-posX=-1600',
                f'-posY={1080/2 - 720/2}',
                mods,
                mission],
                stdout=None,
                stdin=None,
                stderr=None)
# %%

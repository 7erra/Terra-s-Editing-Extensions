#%%
from pathlib import Path
import subprocess
import sys
import shutil
#%%
folder = Path('P:/TER_Editing')
source = Path('P:/-Terra-s-Editing-Extensions/TER_editing')
destination = Path("P:/-Terra-s-Editing-Extensions/@Terra's Editing Extensions")
logfile = Path(f'P:/temp/{folder.name}.packing.log')
#%%
try:
    folder.symlink_to(source, target_is_directory=True)
except FileExistsError:
    pass
#%%
pboProject = subprocess.run(['pboProject',
                '-P',
                '-R',
                '+K',
                folder,
                f'-M={destination.absolute()}'])
try:
    print('Return code is:', pboProject.returncode)
    pboProject.check_returncode()
    print('pboProject completed successfuly.')
except subprocess.CalledProcessError as e:
    with logfile.open() as log:
        for line in log:
            print(line.rstrip())
    print(f'pboProject failed with exitcode {e.returncode}! See above for details!')
finally:
    try:
        folder.unlink()
    except FileNotFoundError:
        pass
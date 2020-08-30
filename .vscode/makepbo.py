#%% Import libraries and set variables
from pathlib import Path
import subprocess
import sys
import shutil

folder = Path('P:/TER_Editing')
source = Path('P:/Terra-s-Editing-Extensions/TER_editing')
destination = Path("P:/Terra-s-Editing-Extensions/@Terra's Editing Extensions")
logfile = Path(f'P:/temp/{folder.name}.packing.log')
#%% Create a symlink to the P drive so pboProject can work correctly
# Note: User has to have symlink rights
try:
    folder.symlink_to(source, target_is_directory=True)
except FileExistsError:
    pass
#%% The real magic brought to you by mikero
pboProject = subprocess.run(['pboProject',
                            '-R',
                            '-P',
                            '+K',
                            folder,
                            f'-M={destination.absolute()}'
                            ])
# Let's see if everything worked...
try:
    print('Return code from pboProject is:', pboProject.returncode)
    pboProject.check_returncode()
    # Yes it did
    print('pboProject completed successfuly.')
except subprocess.CalledProcessError as e:
    # Nope. Print log to screen.
    with logfile.open() as log:
        for line in log:
            print(line.rstrip())
    print(f'pboProject failed with exitcode {e.returncode}! See above for details!')
finally:
    print("Full log can be found here:", logfile)
    # We still have to remove the symlink from before to keep P clean
    try:
        folder.unlink()
    except FileNotFoundError:
        pass
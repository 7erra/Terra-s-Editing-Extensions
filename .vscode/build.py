#%% Import libraries and set variables
from pathlib import Path
import subprocess

repo_local = Path(__file__).parents[1]
source = repo_local / 'TER_Editing'
destination = repo_local / "@Terra's Editing Extensions"
packing_folder = Path('P:/TER_Editing')
logfile = Path(f'P:/temp/{source.name}.packing.log')
#%% Create a symlink to the P drive so pboProject can work correctly
# Note: User has to have symlink rights
try:
    packing_folder.symlink_to(source, target_is_directory=True)
except FileExistsError:
    pass
#%% The real magic brought to you by mikero
pboProject = subprocess.run(['pboProject',
                            '-R',
                            '-P',
                            '+K',
                            packing_folder,
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
        packing_folder.unlink()
    except FileNotFoundError:
        pass
# %%

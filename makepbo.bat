@echo off
echo Building mod...
set folder=TER_Editing
echo Folder: %folder%
set source="P:\%folder%"
set dest="P:\@Terra's Editing Extensions"
pboProject -P -R +K %source% -M=%dest%
set packingError=%ERRORLEVEL%
echo Error level is %packingError%
if %packingError% NEQ 0 color 0C
echo ###################################
echo:
type "P:\temp\%folder%.packing.log"
echo:
echo ###################################
if %packingError% NEQ 0 (
	echo PboProject failed, this is the log:
	pause
)
//redf
#define ATT(T) ((_markerName get3DENAttribute T) select 0)

if (count (get3DENSelected "marker") == 0) exitWith {["No markers selected",1] call BIS_fnc_3DENNotification; ""};
_markerName = (get3DENSelected "marker") #0;

private _markerShape = ATT("markerType");
_markerShape = ["ICON","RECTANGLE","ELLIPSE"] # (_markerShape +1);

private _markerType = configName (configFile >> "CfgMarkers" >> ATT("itemClass"));

toFixed 4;
private _markerPosition = str ASLToAGL ATT("position");
toFixed -1;

_ret = [
	"",
	_markerName,
	_markerPosition,
	_markerType,
	_markerShape,
	ATT("size2"),
	ATT("rotation"),
	ATT("brush"),
	ATT("baseColor"),
	ATT("alpha"),
	ATT("text")
] joinString "|";

copyToClipboard str _ret;
[format ["%1<br/>Copied to clipboard",_ret],0,3] call BIS_fnc_3DENNotification;

_ret

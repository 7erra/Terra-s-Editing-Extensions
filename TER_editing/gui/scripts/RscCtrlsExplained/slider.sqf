[
//--- Examples
[
	[ // Example 1
		"RscSlider",// Class
		[], // Width, height
		{ // Commands to execute upon creation
			_this sliderSetPosition 7;
		}
	]
],
//--- Description
"An older version of a slider control. The modern one is <t color='#4444ff'>CT_XSLIDER</t>.",
//--- EH
["SliderPosChanged"],
//--- Commands
["sliderPosition", "sliderRange", "sliderSetPosition", "sliderSetRange", "sliderSetSpeed", "sliderSpeed"],
//--- Common base classes
["<t color='#FF5555'>RscSlider</t>","RscSliderH","ctrlSliderV"]
]
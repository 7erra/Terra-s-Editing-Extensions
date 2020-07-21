"
<t size='2' align='center'>Welcome to GUI Controls Explained!</t><br/><br/>
<t underline='true'>Foreword</t><br/>
This dialog will explain the different control types with an example for each one. It will give an overview over the event handlers which can be used together with the respective control type as well as the relevant commands.<br/><br/>
 <t underline='true'>Examples</t><br/>
Usually the example controls will have their base class displayed below them. Some examples will start with ""Rsc"" and others with ""ctrl"". The Rsc base classes are used in the majority of the game while ctrl base classes are 3den Editor exclusive but can also be used outside of it. To keep a consistent look I'd recommend to use Rsc for every dialog which is not part of 3den. In some cases it was neccessary to use a new class. You can recognize it by the class name as it will look like ""TER_3den_Rsc*Class*Example"". If you ommit the ""TER_3den_"" and ""Example"" part you get the normal base class. Keep in mind that the base classes are not always full functional.<br/><br/>
<t underline='true'>Commands and event handlers</t><br/>
All available commands and event handlers are listed in their section as links to their BIKI pages. Additionally you can test the eventhandlers by activating the control. The result will be printed to the edit box at the bottom. The output has the following format: ""Event (Example #): Params"".<br/><br/>
<t underline='true'>Code</t><br/>
If you are interested in the code behind this project then you can find the scripts in ""TER_Editing\gui\scripts\RscCtrlsExplained"". The main function is in the GUI scripts folder and is called ""RscCtrlsExplained.sqf"". For the config go to the <a href='https://github.com/7erra/-Terra-s-Editing-Extensions'>mod's GitHub page</a> to look at it or download the source code. It is not advisable to debinarise the config.bin in ""TER_Editing\config.bin"" because too much information is lost during the binarization process (eg. #define macros).<br/><br/>
<t underline='true'>Epilogue</t><br/>
I am not claiming that this dialog will contain every information there is to dialog controls. In fact I would say it is far from it as there is so much to know. I suggest going to the BIKI page of the control type which will be linked at the end of each section. There you usually find more information, examples and an indepth look at the attributes. There might also be threads on the BI Forums about a problem you are (going to be) having so search that one too.<br/><br/>
<t underline='true'>About myself</t><br/>
My BI profile: <a href='https://forums.bohemia.net/profile/1139559-7erra/'>https://forums.bohemia.net/profile/1139559-7erra/</a><br/>
My Steam profile: <a href='https://steamcommunity.com/id/7erra'>https://steamcommunity.com/id/7erra</a><br/>
My GitHub profile: <a href='https://github.com/7erra'>https://github.com/7erra</a><br/> 
"
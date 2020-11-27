# Change Log

## [Unreleased] - yyyy-mm-dd
### Added
### Changed
- Config Viewer 73: Non favorited entries are now displayed as "--" in the favorite comobox
### Fixed

--------------------------------------------------------------------------------
## [2.6.5] - 2020-10-25
See [2.6.2](#262---23102020)
### Added
### Changed
### Fixed

--------------------------------------------------------------------------------
## [2.6.4] - 2020-10-23
Can't continue work atm because the packing is failing <s>for unknown reasons...</s>  
EDIT: because of an update to the tools that breaks some of my macros
### Added
### Changed
- [Reverted to [v2.6.1]](#261---15102020)
### Fixed

--------------------------------------------------------------------------------
## [2.6.3] - 2020-10-23
### Added
### Changed
### Fixed
- Upload of dev version

--------------------------------------------------------------------------------
## [2.6.2] - 2020-10-23
### Added
### Changed
- [Config Viewer Shortcut is F12[/url] (changed to "SHIFT+C")](https://github.com/7erra/Terra-s-Editing-Extensions/issues/41)
### Fixed
- [Color Picker doesn't work.](https://github.com/7erra/Terra-s-Editing-Extensions/issues/43)

--------------------------------------------------------------------------------
## [2.6.1] - 2020-10-15
### Added
- [Added shortcut for Config Viewer 73.](https://github.com/7erra/Terra-s-Editing-Extensions/pull/30)
- [Added shortcut for Config Viewer 73.](https://github.com/7erra/Terra-s-Editing-Extensions/pull/30)
### Changed
### Fixed
- [Color is not set in Color Picker when previewing color in config Viewer](https://github.com/7erra/Terra-s-Editing-Extensions/issues/38)
- [Help text is cut off in Config Viewer](https://github.com/7erra/Terra-s-Editing-Extensions/issues/37)
- [Config Viewer 73: Search Bars Do Not Initiate List Updates](https://github.com/7erra/Terra-s-Editing-Extensions/issues/36)
- [Remove shadow on debug console title](https://github.com/7erra/Terra-s-Editing-Extensions/issues/26)
- [KillzonKid -> Killzone_Kid](https://github.com/7erra/Terra-s-Editing-Extensions/pull/34)

--------------------------------------------------------------------------------
## [2.6] - 2020-10-02
**"Config Viewer 73 Preview" update**  
If you have another idea for configs which can be previewed just drop a comment or open an issue.
### Added
- You can now preview certain classes from the Config Viewer 73 (see the Steam description)
- Shortcut for opening the debug console changed from "^" key to CTRL+D (same as CBA)
### Changed
- Some background stuff, I am transitioning to using BIS_fnc_display for my displays
### Fixed

--------------------------------------------------------------------------------
## [2.5] - 2020-09-07
**"RPT Page" update**  
***!!! IMPORTANT !!!***  
With this release there is a dependency on the @Pythia mod. This enables me to do file operations such as reading the RPT and opening up even more options for the future ;)
### Added
- RPT page for the debug console
### Changed
- Added dependency on the @Pythia mod
### Fixed
- Various minor fixes by R3vo and myself

--------------------------------------------------------------------------------
## [2.4.1] - 2020-07-18
### Added
### Changed
### Fixed
- Vanilla debug console was gone

--------------------------------------------------------------------------------
## [2.4] - 2020-07-15
**"Export config" update**
### Added
- TER_fnc_configToString
- UI for the above function in the Config Viewer 73
### Changed
### Fixed

--------------------------------------------------------------------------------
## [2.3] - 2020-01-12
**"Config Viewer 73" Update**  
This is one of my favourite additions so far. The idea had been there for a longer time but now I was finally able to pull it off. There are still some functionalities missing such as config inheritance. I will be working on adding other options to access the config viewer (shortcut in 3den, escape menu) as you can only access it via the toolbar in 3den atm.
### Added
- Config Viewer 73: Modern config viewer to replace the Splendid Config Viewer
### Changed
### Fixed

--------------------------------------------------------------------------------
## [2.2] - 2019-12-13
**"Namespace Explorer" Update**  
### Added
- Added "Namespace Variables" in the "Tools" folder. This feature will enable you to browse through the different namespaces and see what variables are used.
- "Namespace Variables" button in the Debug Console.
### Changed
- Custom Commands, More Watchfields and Live Debug now operate in missionNamespace.
- Custom Commands: Remote execution now gives an appropriate message.
### Fixed

--------------------------------------------------------------------------------
## [2.1] - 2019-05-24
**"Custom Commands and More Watch Fields updated" Update**  
### Added
- Other players as targets for Custom Commands
### Changed
- Custom Commands and More Watch Fields now use CT_CONTROLS_TABLE
- Moved Live Debug to More Watch Fields page
### Fixed
- Live debug messed up

--------------------------------------------------------------------------------
## [2.0] - 2019-05-16
**"Next Level" Update**  
Skipping version v1.9 because it is in fact a major update. Maybe not so much on the content side of things but there are some important changes under the hood. If you have security concerns regarding the debug_console_x64.dll then you are free to delete it. It will have no effect on the mod whatsoever but will make the whole KK Debug page non-functional.
### Added
- KK Debug page
### Changed
- Only the selected page get loaded when selected
### Fixed

--------------------------------------------------------------------------------
## Older versions
The changelogs for all older versions are in this Bohemia Interactive Forums thread: https://forums.bohemia.net/forums/topic/217263-7erras-editing-extensions/

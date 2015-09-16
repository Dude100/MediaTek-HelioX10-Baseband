cd ..
rem rem XGConsole /command="tools\make.exe  -j1  ACTION=remake  -k    -r -R COMPONENT=abm     -fmake\comp.mak  "  /profile="tools\XGConsole.xml"

@call XGConsole.exe
@echo errorlevel==%ERRORLEVEL%

@if %ERRORLEVEL%==0  XGConsole /command="tools\make.exe  -j1  ACTION=remake  -k    -r -R COMPONENT=abm     -fmake\comp.mak "  /profile="tools\XGConsole.xml"
@if %ERRORLEVEL%==1  tools\make.exe  -j1  ACTION=remake  -j1 -k    -r -R COMPONENT=abm     -fmake\comp.mak  


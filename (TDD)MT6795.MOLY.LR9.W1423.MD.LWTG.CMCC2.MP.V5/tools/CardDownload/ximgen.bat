@set configFile=%1
@set outputFolder=%2
@set outputPrefix=%3
@set internalFlag=%4

@echo [ximgen]Para1:%configFile%
@echo [ximgen]Para2:%outputFolder%
@echo [ximgen]Para3:%outputPrefix%
@echo [ximgen]Para4:%internalFlag%

@set IMMaker=.\tools\CardDownload\IM_Maker.exe
@if %internalFlag%==TRUE set XIMMaker=.\tools\CardDownload\XIM_Maker.exe
@if %internalFlag%==FALSE set XIMMaker=.\mtk_tools\CardDownload\XIM_Maker.exe
@echo [ximgen]XIMMaker Path: %XIMMaker%
@if NOT EXIST %XIMMaker% echo [ximgen]XIMMaker Path: %XIMMaker% not exist, please build one! 
@if NOT EXIST %XIMMaker% goto ERROR

%IMMaker% -i %configFile% -x %outputFolder%\XIM_Maker.ini -o %outputFolder%\%outputPrefix%.IM
@if %ERRORLEVEL% neq 0 goto ERROR

@echo ===================
@echo  IM_Maker Passed!
@echo ===================

%XIMMaker% -s %outputFolder%\XIM_Maker.ini -i %outputFolder%\%outputPrefix%.IM -o %outputFolder%\%outputPrefix%.XIM
@if %ERRORLEVEL% neq 0 goto ERROR





@echo ===================
@echo  XIM_Maker Passed!
@echo ===================

:OK
@goto END

:ERROR
@echo ========
@echo  ERROR!
@echo ========
@exit /b 1


:END
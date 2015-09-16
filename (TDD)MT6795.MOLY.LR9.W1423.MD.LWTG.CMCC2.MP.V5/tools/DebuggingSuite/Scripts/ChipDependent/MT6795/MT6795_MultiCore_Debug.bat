::
::  MT6795_MultiCore_Debug.bat
::

@ECHO off

SET EnableSerialJTAG=0

:SHOW_COMMAND

CLS

ECHO [MT6795 Multi-Core Debugging]
IF EXIST "SerialWireJTAG.txt" (
    ECHO Current default JTAG port: Serial Wire JTAG
    IF %EnableSerialJTAG%==1 (
        ECHO [S]witch JTAG port setting to Parallel JTAG ^(for most EVB^)
    )
) ELSE (
    ECHO Current default JTAG port: Parallel JTAG
    IF %EnableSerialJTAG%==1 (
        ECHO [S]witch JTAG port setting to Serial Wire JTAG 
        ECHO     ^(for phone or some special EVB^)
    )
)
)
:ECHO [A]ttach only
:ECHO [R]eset and go
ECHO [M]odem attach only (Default)
ECHO [E]xit

SET /p choice=">"

IF '%choice%'=='e' (
    GOTO EXIT
)
IF '%choice%'=='E' (
    GOTO EXIT
)
IF '%choice%'=='x' (
    GOTO EXIT
)
IF '%choice%'=='X' (
    GOTO EXIT
)
IF %EnableSerialJTAG%==1 (
    IF '%choice%'=='s' (
        goto SWITCH_JTAG
    )
    IF '%choice%'=='S' (
        goto SWITCH_JTAG
    )
)

ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F

IF '%choice%'=='a' (
    GOTO ATTACH_ONLY
)
IF '%choice%'=='A' (
    GOTO ATTACH_ONLY
)

IF '%choice%'=='r' (
    GOTO RESET_GO
)
IF '%choice%'=='R' (
    GOTO RESET_GO
)

GOTO MODEM_ATTACH_ONLY

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Reset-Go procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:RESET_GO
ECHO Reset and go.

ECHO Starting AP ^(Cortex-A7^) debugger...
START CVD.exe -Multi -Master -CORE=1 MT6795_MultiCore_AP.csf

:: ping 3 s
ping 127.0.0.1 -n 3 -w 1000 > nul

ECHO [Step 1] Press any key to start MD1 ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -CORE=2 MT6795_MultiCore_MD.csf

GOTO END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ONLY
ECHO Attach only.


ECHO Starting AP ^(Cortex-A7^) debugger...
START CVD.exe -Multi -Master -CORE=1 MT6795_MultiCore_AP_Attach.csf

:: ping 3 s
PING 127.0.0.1 -n 3 -w 1000 > nul

ECHO Start MD ^(Cortex-R4^) debugger...
START CVD.exe -Multi -Slave -CORE=3 MT6795_MultiCore_MD_Attach.csf

GOTO END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Switch JTAG port setting
:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:SWITCH_JTAG

if exist "SerialWireJTAG.txt" (
    DEL  SerialWireJTAG.txt
    ECHO Set Default JTAG port to Parallel JTAG done!
) else (
::copy NUL SerialWireJTAG.txt :: CVD check file exist with file size
    ECHO serial wire jtag >>"SerialWireJTAG.txt"
    ECHO Set Default JTAG port to Serial Wire JTAG done!
)

GOTO END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Modem attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:MODEM_ATTACH_ONLY
ECHO Modem attach only.

ECHO start MD ^(Cortex-R4^) debugger...
START CVD.exe MT6795_MultiCore_MD.cmm

:END
ECHO ************************
ECHO Press any key to start a new debug session...
PAUSE
SET choice=
GOTO SHOW_COMMAND
:EXIT
ECHO ************************
ECHO Bye~
PAUSE

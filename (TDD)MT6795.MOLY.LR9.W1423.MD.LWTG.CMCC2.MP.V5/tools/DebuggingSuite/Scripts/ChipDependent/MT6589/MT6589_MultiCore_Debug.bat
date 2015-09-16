:: 
::  MT6589_MultiCore_Debug.bat
:: 

@echo off
echo kill all CVD.exe ...
taskkill /IM CVD.exe /F

echo [MT6589 Multi-Core Debugging]

:SHOW_COMMAND
echo [A]ttach only
echo [R]eset and go (Default) 
set /p choice=">"

IF '%choice%'=='a' (
    goto ATTACH_ONLY
)
IF '%choice%'=='A' (
    goto ATTACH_ONLY
)

goto RESET_GO

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Reset-Go procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:RESET_GO
echo Reset and go.

:RESET_MD_SELECT
echo Please select modem
echo [1] MD1 (CR4)
echo [2] MD2 (ARM9)
echo [D] Dual-MD (TODO)
set /p md_sel=">"
IF '%md_sel%'=='d' (
    set md_sel=D
    goto RESET_END_SELECT
)
IF '%md_sel%'=='1' (
    goto RESET_END_SELECT
)
IF '%md_sel%'=='2' (
    goto RESET_END_SELECT
)
IF '%md_sel%'=='D' (
    goto RESET_END_SELECT
)
echo Unknown command.
goto RESET_MD_SELECT


:RESET_END_SELECT


echo Starting AP ^(Cortex-A7^) debugger...
start CVD.exe -Multi -Master -CORE=1 MT6589_MultiCore_AP.csf

IF '%md_sel%'=='1' (
    goto MD1_RESET
)
IF '%md_sel%'=='2' (
    goto MD2_RESET
)
IF '%md_sel%'=='D' (
    goto MD1_RESET
)

:MD1_RESET
    echo [Step 1] Press any key to start MD1 ^(Cortex-R4^) debugger...
    pause
    start CVD.exe -Multi -Slave -CORE=5 MT6589_MultiCore_MD1.csf
    
    IF '%md_sel%'=='D' (
        goto MD2_RESET
    )
    goto END

:MD2_RESET
    echo [Step 1] Press any key to start MD2 ^(ARM9^) debugger...
    pause
    start CVD.exe -Multi -Slave -CORE=6 MT6589_MultiCore_MD2.csf

goto END

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
:: Attach only procedure
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

:ATTACH_ONLY
echo Attach only.

:ATTACH_MD_SELECT
echo Please select modem
echo [1] MD1 (CR4)
echo [2] MD2 (ARM9)
set /p md_sel=">"
IF '%md_sel%'=='1' (
    goto ATTACH_END_MD_SELECT
)
IF '%md_sel%'=='2' (
    goto ATTACH_END_MD_SELECT
)
echo Unknown command.
goto ATTACH_MD_SELECT

:ATTACH_END_MD_SELECT
echo Starting AP ^(Cortex-A7^) debugger...
start CVD.exe -Multi -Master -CORE=1 MT6589_MultiCore_AP_Attach.csf

IF '%md_sel%'=='1' (
    goto MD1_ATTACH
)
IF '%md_sel%'=='2' (
    goto MD2_ATTACH
)

:MD1_ATTACH
    echo [Step 1] Press any key to start MD1 ^(Cortex-R4^) debugger...
    pause
    start CVD.exe -Multi -Slave -CORE=5 MT6589_MultiCore_MD1_Attach.csf
    
    goto END

:MD2_ATTACH
    echo [Step 1] Press any key to start MD2 ^(ARM9^) debugger...
    pause
    start CVD.exe -Multi -Slave -CORE=6 MT6589_MultiCore_MD2_Attach.csf

    goto END


:END
pause
exit

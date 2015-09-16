@ECHO off

ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
taskkill /IM _CVD64.exe /F

:: :::::::::::::::::::::::::::::::::::::::::::::: ::
::  Load TinyBL
:: :::::::::::::::::::::::::::::::::::::::::::::: ::

ECHO Load TinyBL ...
:C:\JnDTech\CVI\CVD64\bin\CVD64.exe
START C:\JnDTech\CVI\CVD64\bin\CVD64.exe MT6795_Load_TinyBL.csf

:: ping 3 s
::PING 127.0.0.1 -n 3 -w 1000 > nul
ECHO Press ENTER to load MD image ...
SET /p choice=">>>>>"

ECHO kill all CVD.exe ...
taskkill /IM CVD.exe /F
taskkill /IM _CVD.exe /F
taskkill /IM _CVD64.exe /F

ECHO Start MD ^(Cortex-R4^) debugger ...
START C:\JnDTech\CVI\CVD\Bin\CVD.exe MT6795_MDOnly.csf

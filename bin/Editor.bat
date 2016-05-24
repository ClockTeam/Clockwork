@echo off
if exist "%~dp0ClockworkPlayer.exe" (set "DEBUG=") else (set "DEBUG=_d")
if [%1] == [] (set "OPT1=-w -s") else (set "OPT1=")
start "" "%~dp0ClockworkPlayer%DEBUG%" Scripts/Editor.as %OPT1% %*

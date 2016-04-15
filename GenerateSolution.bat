@echo off

echo Generate build files for specific platform.
echo Type the target platform.
echo.
echo [1]  VC2015 - Windows Desktop
echo [2]  VC2015 - Windows Universal App
echo [3]  VC2015 - Xbox One

echo.

:choice
set /P C="Platform: "
if "%C%"=="1" goto windows
if "%C%"=="2" goto windows_universal
if "%C%"=="x" goto durango
if "%C%"=="xx" goto orbis
goto quit

:windows
Scripts\genie_win.exe --vs=win32 vs2015
goto quit

:windows_universal
Scripts\genie_win.exe --vs=winstore82 vs2015
goto quit

:durango
Scripts\genie_win.exe --vs=durango vs2015
goto quit

:quit

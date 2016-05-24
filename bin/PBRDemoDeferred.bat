@echo off
if exist "%~dp0ClockworkPlayer.exe" (set "DEBUG=") else (set "DEBUG=_d")
"%~dp0ClockworkPlayer%DEBUG%" Scripts/42_PBRMaterials.as -renderpath CoreData/RenderPaths/PBRDeferred.xml %*

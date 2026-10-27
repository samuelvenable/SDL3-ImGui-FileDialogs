@echo off
cd "%LOCALAPPDATA%\catalog\build_*" && echo F | xcopy /y /f "SDL3-*.lib" "%~dp0SDL3.lib"

@echo off
cd "%~dp0out\build\*-*\.cache\catalog\build_*" && echo F | xcopy /y /f "SDL3-*.lib" "%~dp0SDL3.lib"

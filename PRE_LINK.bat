@echo off
cd "%~dp0.cache\catalog\build_*" && echo F | xcopy /y /f "SDL3-*.lib" "%~dp0SDL3.lib"

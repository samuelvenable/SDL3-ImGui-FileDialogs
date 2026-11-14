@echo off
cd "%~dp0out\build\*-*\.cache\catalog\build_*" && echo F | xcopy /y /f "SDL3-*.lib" "%~dp0SDL3.lib"
cd "%~dp0out\build\*-*\.cache\catalog\build_*\include\SDL3" && echo D | xcopy /y /f /s /e "SDL3\" "%~dp0source\SDL3\"

@echo off
cd "%~dp0out\build\*-*\.cache\catalog\build_*\include\SDL3" && echo D | xcopy /y /f /s /e "SDL3\" "%~dp0source\SDL3\"

@echo off
cd "%~dp0out\build\*-*\.cache\catalog\build_*\include" && echo D | xcopy /y /f /s /e "SDL3" "%~dp0source\SDL3"

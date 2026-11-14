@echo off
cd "%~dp0out\build\*-*\.cache\catalog\src_*\src" && echo D | xcopy /y /f /s /e "include\SDL3" "%~dp0source\SDL3"

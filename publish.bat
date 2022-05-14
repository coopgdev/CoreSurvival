@echo off
cls
rmdir /s /q publish
mkdir publish
C:\raylib\w64devkit\bin\mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=publish/CoreSurvival OBJS=main.c BUILD_MODE=DEBUG
pause
Xcopy /E /I /Y resources publish\resources
echo Build complete.
exit
main.exe
@echo off
REM Остановить выполнение при ошибках
setlocal enabledelayedexpansion

echo Build scrn...
cd scrn
make
if errorlevel 1 (
    echo Ошибка сборки scrn
    exit /b 1
)
cd ..

echo Build box...
cd box
make
if errorlevel 1 (
    echo Ошибка сборки box
    exit /b 1
)
cd ..

echo Build success!
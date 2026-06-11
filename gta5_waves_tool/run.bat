@echo off
cd /d "%~dp0"
py -3 gta5_waves.py
if errorlevel 1 (
  echo.
  echo Python через py -3 не запустился, пробую python...
  python gta5_waves.py
)

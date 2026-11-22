@echo off
set "GCC=C:\Users\strap\Documents\winlibs-x86_64-posix-seh-gcc-14.2.0-mingw-w64ucrt-12.0.0-r2 (1)\mingw64\bin\g++.exe"
set "SFML=C:\Users\strap\Documents\SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit\SFML-3.1.0"

"%GCC%" -std=c++17 main.cpp Gra.cpp Gracz.cpp -o space-invaders.exe -I include -I"%SFML%\include" -L"%SFML%\lib" -lsfml-graphics -lsfml-window -lsfml-system
if errorlevel 1 goto koniec

set "PATH=%SFML%\bin;%PATH%"
space-invaders.exe

:koniec
pause
@echo off

REM LD MABESELE

if not exist "..\bin" mkdir "..\bin"

echo Compiling....
g++ libEvoAlg.h libEvoAlg.cpp main.cpp -o ..\bin\main.exe

echo Running...
..\bin\main.exe 20 22 12 7 11


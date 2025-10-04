# [Chaser]

A console based game written in C++.

## how to compile

### Using the provided batch file (Windows):
1. Double click "compile_and_run.bat".

### Manual compilation:
1. Open terminal in the src folder
2. compile: g++ libEvoAlg.h libEvoAlg.cpp main.cpp -o main.exe
3. run: main.exe (pass command line arguments{rows, columns, Player's energy, Number of targets, number of obstacles}) eg. 20 20 15 10 13.

## Game discription:
This is a Two dimensional turn based Game to navigate the world while chasing targets.
The aim is for the human controlled character (P) to move around the game world avoiding obstacles,
and chasing down targets.
The charater must catch all targrts without losing their energy in order to win the game.
The player can move up (W), down (s), left (A) and right (D) at each turn, cannot mtove diagonally.
The player start with user defined number of of units of energy and loses 1 unit of energy after each turn.
When a player arrest a target they gain 10 units of energy.
The player cannot occupy the same space as an immovable obstacle (#)
When the player runs out of energy the game ends in defeat.

# programing language
C++

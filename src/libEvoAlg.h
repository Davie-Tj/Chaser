#ifndef LIBEVOALG_H_INCLUDED
#define LIBEVOALG_H_INCLUDED

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

namespace ChaseSpace{

///Game characters
const int SPACE = 0;
const int PLAYER = 1;
const int TARGET = 2;
const int OBSTACLE = 3;
const char GAME_FEATURES[4] ={'.' , 'P' , 'T' , '#'};

///exit codes
const int SUCCESS = 0;
const int ERR_CONVEG = -1;
const int ERR_NUM_ARGS = -2;

///functions
int convStrtoInt(string strArg);
int** allocMem(int,int);
void printMenu();
void printGame(int**,int,int);
void inFeatures(int** Gamegrid, int ROWS, int COLS, int NumObstacles, int NumTargets);
void movePlayer(int** Gamegrid, int ROWS, int COLS, char chInput, int &Energy);
void moveTargets(int** Gamegrid, int ROWS, int COLS, char Input);
int targetsremaining(int** Gamegrid, int ROWS, int COLS);
void deallocMem(int** &arrWorld,int);


}



#endif // LIBEVOALG_H_INCLUDED

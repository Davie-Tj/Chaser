#include "libEvoAlg.h"

namespace ChaseSpace{
    //allocate memory for 2D array
int** allocMem(int rows,int cols){
int** arrWorld;
arrWorld = new int*[rows];
for(int i=0; i< rows; i++){
  arrWorld[i] = new int[cols];
}
//initialise 2D array
for(int i=0;i<rows;i++){
 for(int j=0; j< cols; j++){
    arrWorld[i][j] = SPACE;
    }
}
return arrWorld;
}

///function to print the menu
void printMenu(){
cout<< "Choose: W - UP , S - DOWN , A - LEFT , D - RIGHT"<<endl;
cout<< "Q - QUIT"<<endl;

}

///funtion to display the game
void printGame(int** arrGrid, int rows, int cols){
for(int r=0; r< rows; r++){
    for(int c=0; c< cols; c++){
        cout<< GAME_FEATURES[arrGrid[r][c]]<<' ';
    }cout<<endl;
}
}
void deallocMem(int** &arrWorld,int rows){
for(int r=0; r<rows; r++){
    delete[] arrWorld[r];
}
    delete [] arrWorld;
    arrWorld = nullptr;
}

///utility funtion to generate random numbers
int RandNumgen(int LB, int UB){
int intRange = UB - LB + 1;

return (rand()% intRange) + LB;
}



///utility funtion to place features
void placefeatures(int** Gamegrid, int Feature, int numFeatures, int ROWS, int COLS){
int intRandRow = 0;
int intRandCol = 0;
for(int i=0; i< numFeatures; i++){
    intRandRow = RandNumgen(0, ROWS-1);
    intRandCol = RandNumgen(0, COLS-1);
    while(Gamegrid[intRandRow][intRandCol] != SPACE){
        intRandRow = RandNumgen(0, ROWS-1);
        intRandCol = RandNumgen(0, COLS-1);
    }
    Gamegrid[intRandRow][intRandCol] = Feature;

}
}

///utility function to place the player
void placePlayer(int** Gamegrid, int ROWS, int Player){
int intRandRow = 0;
int firstCol = 0;
intRandRow = RandNumgen(0, ROWS -1);
while(Gamegrid[intRandRow][firstCol] != SPACE){
    intRandRow = RandNumgen(0, ROWS -1);
}
Gamegrid[intRandRow][firstCol] = Player;

}




///Initialize game features

void inFeatures(int** Gamegrid, int ROWS, int COLS, int NumObstacles, int NumTargets){
// place palyer
placePlayer(Gamegrid,ROWS,PLAYER);
//place Obstacle
placefeatures(Gamegrid, OBSTACLE, NumObstacles, ROWS, COLS);
//place Target
placefeatures(Gamegrid, TARGET, NumTargets, ROWS, COLS);

}

///utility function to find a player
void findPlayer(int** Gamegrid, int ROWS, int COLS, int& Prow, int& Pcol){
for(int r=0; r <ROWS; r++){
    for(int c=0; c < COLS; c++){
        if(Gamegrid[r][c]==PLAYER){
            Prow = r;
            Pcol = c;
            return;
        }
    }
}

}

///utility function to find Targets
void findTargets(int ** Gamegrid, int ROWS, int COLS, int& TROW, int& TCOL){
for(int r =0; r< ROWS; r++){
    for(int c =0; c < COLS; c++){
        if(Gamegrid[r][c] == TARGET){
            TROW = r;
            TCOL = c;
            return;
        }
    }
}


}

///check if destination is valid
bool destisvalid(int ROWS, int COLS, int Drow, int Dcol){
if(Drow < 0 || Drow >=ROWS || Dcol < 0 || Dcol >= COLS){
  return false;
}return true;

}

///function to move the player
void movePlayer(int** Gamegrid, int ROWS, int COLS, char chInput, int &Energy){
int intProw = 0;
int intPcol = 0;
//call funtion to find the player
findPlayer(Gamegrid,ROWS,COLS,intProw,intPcol);
int intDrow = intProw;
int intDcol = intPcol;

switch(tolower(chInput)){
case 'a':{
   intDcol--;
break;
}
case 'w':{
   intDrow--;
break;
}
case 's':{
   intDrow++;
break;
}
case 'd':{
   intDcol++;
break;
}
}
//is destination valid
if(destisvalid(ROWS,COLS,intDrow,intDcol)){
    //make movement
    if(Gamegrid[intDrow][intDcol] ==SPACE){
            //space - palyer
        Gamegrid[intDrow][intDcol] = PLAYER;
          //player - space
        Gamegrid[intProw][intPcol] = SPACE;
        //movement cost energy
        Energy--;
    }else if (Gamegrid[intDrow][intDcol] == TARGET){
    //capture the target
       //target - player
       Gamegrid[intDrow][intDcol] = PLAYER;
       //player - space
       Gamegrid [intProw][intPcol] = SPACE;
       //gains 10 units of energy after every arrest
       Energy = Energy + 10;
    }else if(Gamegrid[intDrow][intDcol] == OBSTACLE){
       //player cannot move over the obstacle
      //obstacle stay and player stay
       Gamegrid[intDrow][intDcol] = OBSTACLE;
       Gamegrid[intProw][intPcol] = PLAYER;
       //player loose energy for bumping onto an obstacle
       Energy--;
    }

}else{
Energy--;
}

}
///funtion to move the Targets
//goes here
void moveTargets(int** Gamegrid, int ROWS, int COLS, char Input){
if(Input == 'A' || 'a' || 'W' || 'w' || 's' || 'S' || 'D' || 'd'){
    int intTDRow = 0;
    int intTDCol = 0;
    int intRandNum = 0;
    for( int r =0; r < ROWS; r++){
        for(int c =0; c < COLS; c++){
                //gen random nums
            intRandNum = rand()%2; //gen random nums between 0 & 1
            //call funtion to find targets
            findTargets(Gamegrid,ROWS,COLS,intTDRow,intTDCol);

                    //chance
                if(intRandNum == 0 && Gamegrid[r][c] == TARGET){
                    intTDRow = r + RandNumgen(0,1);
                    intTDCol = c + RandNumgen(0,1);
                    //check if destination is valid
                    if(intTDRow >=0 && intTDRow < ROWS && intTDCol >=0 && intTDCol < COLS && Gamegrid[intTDRow][intTDCol] ==SPACE){
                    Gamegrid[intTDRow][intTDCol] = TARGET;
                    Gamegrid[r][c] = SPACE;
                }
            }
        }
    }
}


}

///convert arguments to integers

int convStrtoInt(string strArg){

int intNum = 0;

stringstream str(strArg);
str >> intNum;
if(str.fail()){
    cerr << "Failed to convert to integer"<<endl;
    exit(ERR_CONVEG);
}
 return intNum;
}

//number of targets remaining
int targetsremaining(int** Gamegrid, int ROWS, int COLS){
    int intCount = 0;
for (int r =0; r < ROWS; r++){
    for(int c =0; c < COLS; c++){
        if(Gamegrid[r][c] == TARGET){
            intCount ++;
        }
    }
}return intCount;
}



}

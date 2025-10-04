#include "libEvoAlg.h"

using namespace ChaseSpace;


int main(int argc, char** argv) //char arg* []
{
    cout << "Number of arguments :"<<argc<<endl;
    if(argc < 6){
        cerr << "Invalid numebr of arguments"<<endl;
        exit(ERR_NUM_ARGS);
    }

    srand(time(nullptr));
    int intRows = convStrtoInt(argv[1]);
    int intCols = convStrtoInt(argv[2]);
    int intEnergy = convStrtoInt(argv[3]);
    int intNumTargets = convStrtoInt(argv[4]);
    int intNumObstacles = convStrtoInt(argv[5]);

    bool blnContinue = true;
    char chOption = '\0';

    //call function to allocate memory and make our game grid.
    int** arrGrid = allocMem(intRows,intCols);
    //call function to set game features
    inFeatures(arrGrid, intRows, intCols,intNumObstacles,intNumTargets);

    do{
       system("cls");
       //print game.
       printGame(arrGrid, intRows, intCols);
       cout<< "ENERGY LEFT :"<<intEnergy<<endl;
       printMenu();
       cin>>chOption;

       switch(tolower(chOption)){

       case 'a':
       case 'd':
       case 'w':
       case 's':
        {
           //player movement - update game state
           movePlayer(arrGrid,intRows,intCols,chOption,intEnergy);
           //move target
           moveTargets(arrGrid,intRows,intCols,chOption);
           break;
        }
       case 'q':{
       cout<< "BYE BYE ............."<<endl;
       blnContinue = false;
       break;
       }
       default:{
       cerr<< "INVALID OPTION"<<endl;
       cin.ignore();
       break;
       }


}
// end game state
int numTargets = targetsremaining(arrGrid, intRows, intCols);
   if(numTargets <= 0){
    cout << "YOU WON"<<endl;
	system("pause");
    break;
   }else if(intEnergy < 0){
    cout << "PLAYER IS OUT OF ENERGY, YOU LOST" <<endl;
	system("pause");
    break;
   }
    }while(blnContinue);
    deallocMem(arrGrid,intRows);
    return SUCCESS;
}

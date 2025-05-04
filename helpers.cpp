#include "helpers.h"
#include <iostream>
using namespace std;

int generateRandomInt(){
    int generatedNumber = rand() % 5; //Because i want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

bool checkGameStatus(Player& player){
    if(player.getHealth()<=0){
        cout<<"Game Over! You Died!\n"<<endl;
        return true;//ends the game
    }
    if(player.getHealth()>=1 && player.getTreasures()==3){
        cout<<"You Won!\n"<<endl;
        return true;
    }
    return false;// continues the game 

}
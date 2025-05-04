#ifndef HELPERS_H
#define HELPERS_H
#include <fstream>
#include "time.h"
#include "stdlib.h"
#include "player.h"
#include <iostream> 

int generateRandomInt();
bool checkGameStatus(Player& player); //checks conditions for winning and losing
//Template
template <typename T>
void clearBoard(T& board, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            board.setElementAtTile(i, j, ' ');
        }
    }
}
int loadLeaderboardFromUserFiles(string names[], int wins[]);// sorting of the directory (will lead to creation of leaderboard.txt)

#endif
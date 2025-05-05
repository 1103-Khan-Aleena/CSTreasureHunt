#ifndef HELPERS_H
#define HELPERS_H
#include <fstream>
#include <dirent.h>
#include <string>
#include <iostream> 
#include <stdlib.h>
#include "time.h"
#include "player.h"

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

int loadLeaderboardFromUserFiles(string, int);// sorting of the directory (will lead to creation of leaderboard.txt)

void displayMainMenu(string*);

void createFile(string); //Creates a txt file with users name, and writes users name at teh top with endline

void appendStatsToFile(Player&, string); //Appends data after game ends

int readEntireFile(ifstream&, string sentences[]); //Reads entire file and stores in a 2D array

#endif

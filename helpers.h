#ifndef HELPERS_H
#define HELPERS_H
#include "board.h"
#include "userBoard.h"
#include "boardTiles.h"
#include <fstream>
#include "time.h"
#include "stdlib.h"
int generateRandomInt();
//bool checkEmpty(int r, int c, BoardTiles& gameBoard); //Note to self: want to template, update: have to kill
//bool checkSurrounding(int r, int c, BoardTiles& gameBoard); //Also have to kill
//bool checkBound(int r, int c); //Implement after seieng controls, will have to implemnet new parameters
#endif
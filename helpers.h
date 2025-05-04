#ifndef HELPERS_H
#define HELPERS_H
#include <fstream>
#include "time.h"
#include "stdlib.h"
#include "player.h"
int generateRandomInt();
//void updateAll(Player& p, BoardTiles&, UserBoard&);
bool checkGameStatus(Player& player); //checks conditions for winning and losing

#endif
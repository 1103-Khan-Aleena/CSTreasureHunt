#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"// replace? 

class Player {
private:
    int row;
    int col;
    int health;
    int treasuresCollected;

public:
    // Default constructor
    Player();
    // Parameterized constructor
    Player(int, int, int, int);
    //row, col, health, treasuresCollected
   //cppy construtor
    Player(const Player&);

    // Getters
    int getRow();
    int getCol();
    int getHealth(); 
    int getTreasures(); 

    // Setters
    void setPosition(int, int);
    void setHealth(int);
    void changeHealth(int);
    void collectTreasure();
    void displayStats(); 

     //operator overloads
     Player operator+(const Player& other) const;
     Player operator-(const Player& other) const;
};

#endif


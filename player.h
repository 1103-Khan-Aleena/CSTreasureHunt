#ifndef PLAYER_H
#define PLAYER_H
#include <fstream>
using namespace std;

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
   //copy construtor
    Player(const Player&);

    // Getters
    int getRow() const;
    int getCol() const;
    int getHealth()const; 
    int getTreasures() const; 

    // Setters
    void setRow(int);
    void setCol(int);
    void setPosition(int, int);
    void setHealth(int);
    void collectTreasure();

     //operator overloads
    Player& operator-(int amount);
    friend ostream& operator<<(ostream&, const Player&);
};
#endif
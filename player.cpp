#include "player.h"
#include <iostream>
using namespace std;
Player::Player(){
    row=0;
    col=0;
    health=100;
    treasuresCollected=0;
}

Player::Player(int r, int c, int h, int t){
    row=r;
    col=c;
    health=h;
    treasuresCollected=t;
}

Player::Player(const Player& other){
    row=other.row;
    col=other.col;
    health=other.health;
    treasuresCollected=other.treasuresCollected;
}
int Player::getRow() const{
    return row;
}

int Player::getCol() const{
    return col;
}

void Player:: setRow(int newRow) { 
    row = newRow; }

void Player:: setCol(int newCol) { 
        col = newCol; }

int Player::getHealth() const{
    return health;
}
int Player::getTreasures() const{
    return treasuresCollected;
}
void Player::setPosition(int newRow, int newCol){
    row=newRow;
    col=newCol;
}
void Player::setHealth(int newHealth){
    health=newHealth;
}
void Player::collectTreasure(){
    treasuresCollected++;
}

//operator overloads
ostream& operator<<(ostream& out, const Player& p){
    out << "Health: " << p.getHealth() << " | Treasures: " << p.getTreasures() << endl;
    return out;
}

//Subtracter Operator Overload
Player& Player::operator-(int amount){
    health -= amount;
    return *this;
}
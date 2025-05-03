#include "Player.h"
#include <iostream>

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
void Player::changeHealth(int change){
    health+=change;
}
void Player::collectTreasure(){
    treasuresCollected++;
}
void Player::displayStats() const{
    cout<< "("<< row<< ","<< col<<")"<< endl;
    cout<< "Health:"<< health<< "Treasures"<< treasuresCollected<<endl;
}
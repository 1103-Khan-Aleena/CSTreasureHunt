#include "boardTiles.h"
//3 constructors
BoardTiles::BoardTiles(): Board(){
    isSurrounded = false;
    isEmpty = false;
}

BoardTiles::BoardTiles(int r, int c, char** g, bool s, bool e):Board(r, c, g){
    isSurrounded = s;
    isEmpty = e;
}

BoardTiles::BoardTiles(const BoardTiles&rhs):Board(rhs){
    isSurrounded = rhs.isSurrounded;
    isEmpty = rhs.isEmpty;
}

//Getters
bool BoardTiles::getIsSurrouned() const{
    return isSurrounded;
}

bool BoardTiles::getIsEmpty() const{
    return isEmpty;
}

char BoardTiles::getSymbol() const{
    //return symbol;
}

//Setters
void BoardTiles::setIsSurrouned(bool s){
    isSurrounded = s;
}

void BoardTiles::setIsEmpty(bool e){
    isEmpty = e;
}

//Virtual method child implementatiom
void BoardTiles::generateBoard(){
    int element_x, element_y;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            grid[i][j] = '.';
        }
    }
    for(int k = 0; k <= 5; k++){ //generates 5 treasures
        isEmpty = false; //resets when a new treasure is being generated 
        element_x = generateRandomInt();
        element_y = generateRandomInt();
       do{
        int element_x = generateRandomInt();
        int element_y = generateRandomInt();
        if(getElementAtTile(element_x, element_y) != '.'){
            isEmpty = false;
        }
        else{
            isEmpty = true;
        }
       }while(isEmpty == false);
        grid[element_x][element_y] = 'T';
    }
}
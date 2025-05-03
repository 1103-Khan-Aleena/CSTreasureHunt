#include "userBoard.h"
//Virtual Method Implementation
void UserBoard::generateBoard(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(i == x && j == y){ //x and y do not follow a traditional (x,y) coordinate plane        
                grid[i][j] = 'P'; //They represent the rows and columns of the 2D array
            }
            else{
                grid[i][j] = ' ';
            }
        }
    }
}

//3 constructors
UserBoard::UserBoard():Board(){
    x = 0;
    y = 0;
}

UserBoard::UserBoard(int r, int c, char** g, int xcoor, int ycoor):Board(r, c, g){
    x = xcoor;
    y = ycoor;
    generateBoard();
}

UserBoard::UserBoard(const UserBoard& rhs):Board(rhs){
    x = rhs.x;
    y = rhs.y;
}

//Getters and Setters
int UserBoard::getX() const{
    return x;
}

int UserBoard::getY() const{
    return y;
}

void UserBoard::setX(int xcoor){
    x = xcoor;
}

void UserBoard::setY(int ycoor){
    y = ycoor;
}






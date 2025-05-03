#include "helpers.h"

int generateRandomInt(){
    int generatedNumber = rand() % 5; //Because i want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

//Template this so it can pass UserBoard and BoardTile object
/*bool checkEmpty(int r, int c, BoardTiles& gameBoard){
    char s = gameBoard.getElementAtTile(r, c); //Gettintg the element at the given space
    if(s == '.'){ //Dot signifies empty
       return true; 
    }
    return false; //If it makes it past conditional then we know the spot is not empty so retrun false
}

bool checkSurrounding(int r, int c, BoardTiles& gameBoard){ // 
    char above = gameBoard.getElementAtTile(r, c - 1);
    char below = gameBoard.getElementAtTile(r, c + 1);
    char right = gameBoard.getElementAtTile(r + 1, c);
    char left = gameBoard.getElementAtTile(r - 1, c);
    if(r == 0 || c == 0){
        if(c == 0){
            if(right == 'X' && below == 'X'){ //Corner case at (0,0)
                return true;
            }
            if(above == 'X' && right == 'X' && below == 'X'){ //Regular case not at the corner of the board
                return true;
            }
        }
        else if(c == 4){
            if(left == 'X' && below == 'X'){ //Corner case at (0,4)
                return true;
            }
            if(above == 'X' && left == 'X' && below == 'X'){
                return true;
            }
        }
        else if(r == 0){
            if(left == 'X' && below == 'X' && right == 'X'){
                return true;
            }
        }
        else if(r == 4){
            if(left == 'X' && above == 'X' && right == 'X'){
                return true;
            }
        }
         return false; //None of those conditions met, returns false that the treasure is not surrouned  
    }
    else{
        if(above == 'X' && below == 'X' && left == 'X' && right == 'X'){
            return true;
        }
    }
    return false;
}

bool checkBound(){} //Add one and subtract one to users potition dependent on what more the user chooses*/
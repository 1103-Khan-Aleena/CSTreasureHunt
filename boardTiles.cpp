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

//Setters
void BoardTiles::setIsSurrouned(bool s){
    isSurrounded = s;
}

void BoardTiles::setIsEmpty(bool e){
    isEmpty = e;
}

//Other methods
bool BoardTiles::checkEmpty(int r, int c){
    if(getElementAtTile(r, c) == '.'){
        return true;
    }
    else{
        return false; //If condidtional is not met, spot is empty
    }
}

bool BoardTiles::checkSurrounding(int r, int c){
    char above, below, right, left; 
    //char below = getElementAtTile(r, c + 1);
    //char  + 1
    //char left = getElementAtTile(r - 1, c);
    if(r == 0){
        if(c == 0){ //Corner (0,0) case
            right = getElementAtTile(r, c + 1);
            below = getElementAtTile(r + 1, c);
            if(right == 'X' && below == 'X'){ //Corner case at (0,0)
                return true;
            }
        else if(c == 4){ //Corner(0,4) case
            left = getElementAtTile(r - 1, c);
            below = getElementAtTile(r, c + 1);
            if(left == 'X' && below == 'X'){ //Corner case at (0,0)
                return true;
            }
        }
        else{   
            below = getElementAtTile(r + 1, c);
            left = getElementAtTile(r, c - 1);
            if(above == 'X' && right == 'X' && below == 'X'){ //Regular edge case not at the corner of the board
                return true;
            }
        }
        }
    }
    else if(r == 4){
        if(c == 0){ //Corner case for (4,0)
            above = getElementAtTile(r - 1, c);
            right = getElementAtTile(r, c + 1);
            if(right == 'X' && above == 'X'){ //Corner case at (0,4)
                return true;
            }
        else if(c == 4){ //Corner Case for (4,4)
            above = getElementAtTile(r - 1, c);
            left = getElementAtTile(r, c - 1);
            if(above == 'X' && left == 'X'){
                return true;
            }
        }
        else{ //Regular top edge case
            left = getElementAtTile(r, c - 1);
            above = getElementAtTile(r - 1, c);
            right = getElementAtTile(r, c + 1);
            if(above == 'X' && right == 'X' && left == 'X'){
                return true;
            }
        }
        }
    }
    else{
        above = getElementAtTile(r - 1, c);
        below = getElementAtTile(r + 1, c);
        left = getElementAtTile(r, c - 1);
        right = getElementAtTile(r, c + 1);
        if(above == 'X' && below == 'X' && left == 'X' && right == 'X'){
            return true;
        }
    }
    return false;
}

//Generate opponent
void BoardTiles::generateOpponent(){
    int opp_x, opp_y;
    int i = 0;
    for(int j = 0; j < rows; j++){
        for(int k = 0; k < columns; k++){
            if(grid[j][j] == 'O'){
                grid[i][j] = '.';
            }
        }
    }
    while(i < 1){ //generates 1 opponent
        opp_x = generateRandomInt();
        opp_y = generateRandomInt();
        cout << opp_x << ", " << opp_y;
        isEmpty = checkEmpty(opp_x, opp_y);
        if(isEmpty == true){
            grid[opp_x][opp_y] = 'O';
            i++; 
        }
    }
}


//Virtual method child implementation
void BoardTiles::generateBoard(){
    int element_x, element_y;
    srand(time(nullptr));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            grid[i][j] = '.';
        }
    }
    int k = 0;
    while(k < 5){ //generates 5 treasures
        element_x = generateRandomInt();
        element_y = generateRandomInt();
        isEmpty = checkEmpty(element_x, element_y);
        if(isEmpty == true){
            grid[element_x][element_y] = 'X';
            k++; 
        }
    }
    int l = 0;
    while(l < 5){
        element_x = generateRandomInt();
        element_y = generateRandomInt();
        isEmpty = checkEmpty(element_x, element_y);
        isSurrounded = checkSurrounding(element_x, element_y);
        if(isEmpty == true && isSurrounded == false){
            grid[element_x][element_y] = 'T';
            l++;
        }
    }
}
#include "userBoard.h"

//Virtual Method Implementation
void UserBoard::generateBoard(){
    int player_x, player_y;
    for(int i = 0; i < rows; i++){
        player_x = player.getRow();
        player_y = player.getCol();
        for(int j = 0; j < columns; j++){
            if(i == 0 && j == 0){ //x and y do not follow a traditional (x,y) coordinate plane        
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
}

UserBoard::UserBoard(int r, int c, char** g, Player p):Board(r, c, g){
    player = p;
    generateBoard();
}

UserBoard::UserBoard(const UserBoard& rhs):Board(rhs){
    player = rhs.player;
}

//Getters and Setters
Player UserBoard::getPlayer() const{
    return player;
}

void UserBoard::setPlayer(Player p){
    player = p;
}

void UserBoard::updateBoard(Player& p, BoardTiles& gameBoard, int pre_x, int pre_y){
    int player_x, player_y; //x and y do not follow a traditional (x,y) coordinate plane 
    player_x = p.getRow();
    player_y = p.getCol();
    if(gameBoard.getElementAtTile(pre_x, pre_y) ==  'X'){ //Reference hidden board
        if(getElementAtTile(pre_x, pre_y) != 'X'){
            p - 20;
        }
        grid[pre_x][pre_y] = 'X'; //They represent the rows and columns of the 2D array
        grid[player_x][player_y] = 'P'; //If its trap, it will now be on the displayed boards grid, and player will be updated

    }
    else if(gameBoard.getElementAtTile(pre_x, pre_y) ==  'T'){ //Reference hidden board
        gameBoard.setElementAtTile(pre_x, pre_y, '.'); //Once tresures is collected the game board updates that spot to empty
        p.collectTreasure();
        grid[pre_x][pre_y] = ' ';
        grid[player_x][player_y] = 'P';
    }
    else if(gameBoard.getElementAtTile(pre_x, pre_y) ==  'O'){ //Reference hidden board
        gameBoard.setElementAtTile(pre_x, pre_y, '.'); //after opponent is uncovered the spot is now empty
        p - 30; //Opponent decremenets by 30 health
        grid[pre_x][pre_y] = ' ';
        grid[player_x][player_y] = 'P';
    }
    else{
        grid[pre_x][pre_y] = ' '; 
        grid[player_x][player_y] = 'P';
    }
    gameBoard.generateOpponent(); //Each turn regenerate an opponent
}




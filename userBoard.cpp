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

void UserBoard::updateBoard(Player& p, BoardTiles& gameBoard){
    int player_x, player_y;
    player_x = p.getRow();
    player_y = p.getCol();
    if(gameBoard.getElementAtTile(player_x, player_y) == 'X'){ //reference the actual gameboard
        grid[player_x][player_y] = 'X'; //If its trap, it will now be on the displayed boards grid
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(i == player_x && j == player_y){ //x and y do not follow a traditional (x,y) coordinate plane        
                grid[i][j] = 'P'; //They represent the rows and columns of the 2D array
            }
                /*else if(hidden.getElementAtTile(i, j) == 'X'){ //Reference hiddent board
                    grid[i][j] = 'X';
                }*/
            else{
                grid[i][j] = ' ';
            }
        }
    }
}




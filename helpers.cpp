#include "helpers.h"

int generateRandomInt(){
    int generatedNumber = (rand() % 4) + 1; //Because i want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

bool checkGameStatus(Player& player){
    if(player.getHealth()<=0){
        cout << "Game Over! You Died!\n" << endl;
        return true;//ends the game
    }
    if(player.getHealth()>=1 && player.getTreasures()==3){
        cout << "You Won!\n" << endl;
        return true;
    }
    return false;// continues the game 

}
//void updateAll(Player& p, BoardTiles& game, UserBoard& user){
    /*int player_x, player_y;
    player_x = p.getRow();
    player_y = p.getCol();
    if(game.getElementAtTile(player_x, player_y) == 'X'){ //reference the actual gameboard
        user.setElementAtTile(player_x, player_y, 'X'); //If its trap, it will now be on the displayed boards grid
    }
    for(int i = 0; i < user.getRows(); i++){
        for(int j = 0; j < user.getColumns(); j++){
            if(i == player_x && j == player_y){ //x and y do not follow a traditional (x,y) coordinate plane        
                user.setElementAtTile(i, j, 'P'); //They represent the rows and columns of the 2D array
            }
                else if(hidden.getElementAtTile(i, j) == 'X'){ //Reference hiddent board
                    grid[i][j] = 'X';
                }
            else{
                user.setElementAtTile(i, j, ' ');
            }
        }
    }
}*/

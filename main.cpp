#include "helpers.h"

int main(){
    char** displayedBoard = new char*[5];
    char** displayedBoard2 = new char*[5];
    bool s1 = false;
    bool s2 = false;
    for(int k = 0; k < 5; k++){
        displayedBoard[k] = new char[5];
        displayedBoard2[k] = new char[5];
        
    }
    UserBoard userInterface(5, 5, displayedBoard, 2, 2);
    userInterface.generateBoard(); 
    cout << userInterface;
    BoardTiles gameBoard(5, 5, displayedBoard2, s1, s2);
    gameBoard.generateBoard();
    gameBoard.generateOpponent();
    cout << endl << endl <<  gameBoard;
    return 0;
}
#include "userBoard.h"
#include "boardTiles.h"
#include "controls.h"
#include "helpers.h"

int main(){
    Player player1(0, 0, 100, 0);
    char** displayedBoard = new char*[5];
    char** displayedBoard2 = new char*[5];
    bool s1 = false;
    bool s2 = false;
    bool s3 = false;
    bool s4 = false;
    int j = 0;
    char userInput;
    for(int k = 0; k < 5; k++){
        displayedBoard[k] = new char[5];
        displayedBoard2[k] = new char[5];
        
    }
    //Generating both initial states of the boards
    UserBoard userInterface(5, 5, displayedBoard, player1);
    userInterface.generateBoard(); 

    BoardTiles gameBoard(5, 5, displayedBoard2, s1, s2);
    gameBoard.generateBoard();
    gameBoard.generateOpponent();
    cout << gameBoard << endl << endl;

    //The controls of the user interaction
    Controls gamePlay(userInput, s3, s4);
    //Actual game play
    while(j < 10){
        cout << player1;
        cout << userInterface;
        gamePlay.promptForMove(player1);
        cout << "(" << player1.getRow() << ", " << player1.getCol() << ")" << endl;
        userInterface.updateBoard(player1, gameBoard);
        j++;
    }
    cout << endl << endl <<  gameBoard;
    return 0;
}
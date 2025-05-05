// Authors: Aleena Khan & Georgia Guillebeau
#include "controls.h"
#include "userBoard.h"

int main() {
    Player player1(0, 0, 100, 0);
    char** displayedBoard = new char*[5]; //Users Dynamic 2D array
    char** hiddenBoard = new char*[5]; //Actual gameboard's Dynamic 2D array
    for(int k = 0; k < 5; k++){
        displayedBoard[k] = new char[5];
        hiddenBoard[k] = new char[5];
        
    }

    //Variables for boards 
    bool empty, surrounded, valid, bounded, checkGame;
    empty = surrounded = valid = bounded = checkGame = false; //All bools for creation of objects

    //Generating both initial states of the boards
    UserBoard userInterface(5, 5, displayedBoard, player1);
    userInterface.generateBoard(); 
    
    BoardTiles gameBoard(5, 5, hiddenBoard, surrounded, empty);
    gameBoard.generateBoard();
    gameBoard.generateOpponent();

    //Variables for conrtrols and game play 
    int previous_x = 0, previous_y = 0; 
    char userInput; //Used for creating controls object
    string userName;

    displayMainMenu(&userName);
    for(int k = 0; k < 5; k++){
        displayedBoard[k] = new char[5];
        hiddenBoard[k] = new char[5];
        
    }

    //The controls of the user interaction
    Controls gamePlay(userInput, valid, bounded);
    //Actual game play
    while(!checkGame){
        cout << endl << player1;
        cout << userInterface;
        previous_x = player1.getRow(); //update position at end to store PREVIOUS location
        previous_y = player1.getCol();
        gamePlay.promptForMove(player1);
        userInterface.updateBoard(player1, gameBoard, previous_x, previous_y); //Uses previous location to check for trap
        checkGame = checkGameStatus(player1);
    }
    appendStatsToFile(player1, userName);
    return 0;
}
// Authors: Aleena Khan & Georgia Guillebeau
#include "controls.h"
#include "userBoard.h"

int main() {
    Player player1(0, 0, 100, 0);
    char** displayedBoard = new char*[5];
    char** displayedBoard2 = new char*[5];
    bool empty, surrounded, valid, bounded, checkGame;
    empty = surrounded = valid = bounded = checkGame = false; // All bools for creation of objects
    int j = 0, previous_x = 0, previous_y = 0;
    char userInput; // Used for creating controls object

    for (int k = 0; k < 5; k++) {
        displayedBoard[k] = new char[5];
        displayedBoard2[k] = new char[5];
    }

    // Generating both initial states of the boards
    UserBoard userInterface(5, 5, displayedBoard, player1);
    userInterface.generateBoard();

    BoardTiles gameBoard(5, 5, displayedBoard2, surrounded, empty);
    gameBoard.generateBoard();
    gameBoard.generateOpponent();

    // The controls of the user interaction
    Controls gamePlay(userInput, valid, bounded);

    // Actual game play
    while (!checkGame) {
        cout << endl << player1;
        cout << userInterface;
        previous_x = player1.getRow(); // Update position at end to store PREVIOUS location
        previous_y = player1.getCol();
        gamePlay.promptForMove(player1);
        userInterface.updateBoard(player1, gameBoard, previous_x, previous_y); // Uses previous location to check for trap
        checkGame = checkGameStatus(player1);
        j++;
    }

    string names[50]; // Or [10] if you want strictly 10
    int wins[50];

    int numPlayers = loadLeaderboardFromUserFiles(names, wins);

    cout << "Top " << numPlayers << " players:\n";
    for (int i = 0; i < numPlayers; i++) {
        cout << (i + 1) << ". " << names[i] << " - " << wins[i] << " wins\n";
    }

    // Write leaderboard to file
    ofstream outFile("leaderboard.txt");
    for (int i = 0; i < numPlayers; i++) {
        outFile << (i + 1) << ". " << names[i] << " - " << wins[i] << " wins\n";
    }
    outFile.close();

    return 0;
}

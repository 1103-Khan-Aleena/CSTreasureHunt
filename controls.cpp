#include "controls.h"
#include <iostream> 
#include "player.h"
using namespace std;
#include "board.h"
// Default constructor
Controls::Controls() {
    userInput = ' ';
    isValid = false;
    isBounded = false;
}

// Parameterized constructor
Controls::Controls(char input, bool valid, bool bounded) {
    userInput = input;
    isValid = valid;
    isBounded = bounded;
}

// Copy constructor
Controls::Controls(const Controls& other) {
    userInput = other.userInput;
    isValid = other.isValid;
    isBounded = other.isBounded;
}

// Method to check if the input is valid (WASD for example)
bool Controls::checkValidInput() {
    if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D' ||
        userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd') {
        isValid = true;
    } else {
        isValid = false;
    }
    return isValid;
}

// check if move is within boudns
bool Controls::checkBound(Player& player) {
    int row = player.getRow(); 
    int col = player.getCol();
    if (row >= 0 && row < 5 && col >= 0 && col < 5) {
        isBounded = true;
    } else {
        isBounded = false;
    }
    return isBounded;
    }
 
    void Controls::promptForMove(Player& player) {// more of a main function??
        bool validMove = false;

        do {
        // Ask the user for input
            cout << "Enter your move (WASD): ";
            cin >> userInput;

        // check if the input is valid
        if (!checkValidInput()) {
            cout << "Invalid move. Please try again." <<endl;  // If invalid input, continue the loop to prompt again
        }
        
            if (userInput== 'W' || userInput== 'w'){
                player.setRow(player.getRow() - 1);// should move up
            }
            else if(userInput=='A' ||userInput=='a'){
                player.setCol(player.getCol() - 1);
            }
            else if(userInput=='S'||userInput=='s'){
                player.setRow(player.getRow() + 1);
            }
            else if(userInput=='D'||userInput=='d'){
                player.setCol(player.getCol() + 1);
            }
            else{
                cout<<"invalid move :("<< endl;
                return;
            }
            //upadte the player position 
            //player.setRow();
            //player.setCol();

        // upadate board after everymove
       // board.generateBoard(); cant do this bc boar dis an abbsract class 
       //updte he users postion after they move,so player.setRow/set Col to upadted spot
        //cout<<board;
        // Ncheck if the move is within bounds
        if (!checkBound(player)) {
            cout << "Move out of bounds! Try again." << endl;
        } else {
            validMove = true;  // If the move is valid and within bounds, exit the loop
        }

    } while (!validMove);  // Continue looping until the move is valid and within bounds
}

// Getter for userInput
char Controls::getUserInput() {
    return userInput;
}

// Setter for userInput
void Controls::setUserInput(char input) {
    userInput = input;
}
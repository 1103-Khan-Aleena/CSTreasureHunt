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

// Method to check if the input is valid (WASD)
bool Controls::checkValidInput() {
    if (userInput == 'W' || userInput == 'A' || userInput == 'S' || userInput == 'D' ||
        userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd') {
        isValid = true;
    } else {
        isValid = false;
    }
    return isValid;
}

 
void Controls::promptForMove(Player& player) {// more of a main/helper function??
    bool validMove = false;
    do {
    // Ask the user for input
        cout << "Enter your move (W/A/S/D): ";
        cin >> userInput;

    // check if the input is valid
    if (!checkValidInput()) {
        cout << "Invalid input. Please try again." <<endl;  // If invalid input, continue the loop to prompt again
    }
       //temp store players current position at will return to this if the user puts in an out of bound option
        int tempRow=player.getRow();
        int tempCol=player.getCol();
    
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

        // check if the move is within bounds
         if (player.getRow() < 0 || player.getRow() >= 5 || player.getCol() < 0 || player.getCol() >= 5) {
            cout << "Move out of bounds! Try again." << endl;
            player.setRow(tempRow);
            player.setCol(tempCol);
        } else {
            validMove = true;  // If the move is valid and within bounds, exit the loop
        }

    } while (!validMove);  // Continue looping until the move is valid and within bounds
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
// Getter for userInput
char Controls::getUserInput() {
    return userInput;
}

// Setter for userInput
void Controls::setUserInput(char input) {
    userInput = input;
}

ostream& operator<<(ostream& out, Controls& c){
    out << "User Entered: " << c.getUserInput() << endl;
    return out;
}
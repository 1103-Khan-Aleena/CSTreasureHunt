#include "Controls.h"
#include <iostream> 
using namespace std;

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
bool Controls::checkBound(int row, int col) {
    if (row >= 0 && row < 5 && col >= 0 && col < 5) {
        isBounded = true;
    } else {
        isBounded = false;
    }
    return isBounded;
    }
 
    void Controls::promptForMove(int& row, int& col) {// more of a main function??
        bool validMove = false;

        do {
        // Ask the user for input
            cout << "Enter your move (WASD): ";
            cin >> userInput;

        // check if the input is valid
        if (!checkValidInput()) {
            cout << "Invalid move. Please try again." <<endl;  // If invalid input, continue the loop to prompt again
        }

        // move if the input is valid
        switch (userInput) {
            case 'W': row--;
                break; // Move up

            case 'A': col--; 
                break; // Move left

            case 'S': row++; 
                break; // Move down

            case 'D': col++; 
                break; // Move right
        }

        // Ncheck if the move is within bounds
        if (!checkBound(row,col)) {
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
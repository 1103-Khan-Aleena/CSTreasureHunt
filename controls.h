#ifndef CONTROLS_H
#define CONTROLS_H
#include <iostream> 
#include "player.h"

class Controls {
private:
    char userInput;    // Stores the player's input character
    bool isValid;     // Tracks if the input is valid
    bool isBounded;  // Tracks if the input move is within bounds
    
public:
    // Default constructor
    Controls();
    Controls(char, bool, bool);
    Controls( const Controls&);

    bool checkBound(Player& player);//? bc im using players objects row and col
    bool checkValidInput();
    void promptForMove(Player& player);//?? bc im using players obects row and col need to reference?
    char getUserInput();
    void setUserInput(char);

   friend ostream& operator<<(ostream&, const Controls&);
 
};

#endif

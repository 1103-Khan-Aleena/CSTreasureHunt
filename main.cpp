#include "board.h"
#include "userBoard.h"
#include <fstream>


int main(){
    char** displayedBoard = new char*[5];
    for(int k = 0; k < 5; k++){
        displayedBoard[k] = new char[5];
    }
    UserBoard userInterface(5, 5, displayedBoard, 2, 2);
    userInterface.generateBoard(); 
    cout << userInterface;
    return 0;
}
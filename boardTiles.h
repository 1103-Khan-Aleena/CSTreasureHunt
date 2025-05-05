#ifndef BOARD_TILES_H
#define BOARD_TILES_H
#include "board.h"
#include "helpers.h"

class BoardTiles: public Board{
    bool isSurrounded, isEmpty; //Bools act as stauts updates

    public:    
        //Constructors
        BoardTiles();
        BoardTiles(int, int, char**, bool, bool); //The attribites needed to create this object are the ones of the parent class and its bools
        BoardTiles(const BoardTiles&);
        
        //Getters and Setters
        bool getIsSurrouned() const;
        bool getIsEmpty() const;
        void setIsSurrouned(bool);
        void setIsEmpty(bool);
        void setSymbol(char);

         //Other Methods
         void clearBoardTiles(); //Maybe i can template this in some way???
         bool checkEmpty(int, int); //Note to self: want to template , Update: not needed :/
         bool checkSurrounding(int r, int c);
         void generateOpponent();

        //Virtual method child declaration
        void generateBoard() override; //Note to self: when implementing fill with dots initially then begin randomizing  
};
#endif
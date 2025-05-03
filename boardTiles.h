#ifndef BOARD_TILES_H
#define BOARD_TILES_H
#include "board.h"
#include "helpers.h"


class BoardTiles: public Board{
   char symbol; //symbol is more like an indicator 
    bool isSurrounded, isEmpty; //Bools act as stauts updates

    public:    
        //Constructors
        BoardTiles();
        BoardTiles(int, int, char**, bool, bool); //The attribites needed to create this object are the ones of the parent class and its bools
        BoardTiles(const BoardTiles&);
        
        //Getters and Setters
        bool getIsSurrouned() const;
        bool getIsEmpty() const;
        char getSymbol() const; 
        void setIsSurrouned(bool);
        void setIsEmpty(bool);
        void setSymbol(char);

        //Virtual method child declaration
        void generateBoard() override; //Note to self: when implementing fill with dots initially then begin randomizing  

        //Other Methods
        void clearBoardTiles(); //Maybe i can template this in some way???
        void generateOpponent();
        //bool checkEmpty(int r, int c, BoardTiles& gameBoard); //Note to self: want to template , Update: not needed :/
        //bool checkSurrounding(int r, int c, BoardTiles& gameBoard);
        
};
#endif
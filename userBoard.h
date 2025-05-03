#ifndef USER_BOARD_H
#define USER_BOARD_H
#include "board.h"

class UserBoard: public Board{
    //Player variable 
    int x, y; //Temporary player coordninates, delete after combining

    public:
        //Constructors
        UserBoard();
        UserBoard(int, int, char**, int, int);
        UserBoard(const UserBoard&);

        //Getters and setters
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);

        //Virtual method child declariation 
        void generateBoard() override; //Override in child

};
#endif
#ifndef USER_BOARD_H
#define USER_BOARD_H
#include "boardTiles.h"
#include "player.h"

class UserBoard: public Board{
    Player player;

    public:
        //Constructors
        UserBoard();
        UserBoard(int, int, char**, Player);
        UserBoard(const UserBoard&);

        //Getters and setters
        Player getPlayer() const;
        void setPlayer(Player);

        //Virtual method child declariation 
        void generateBoard() override; //Override in child

        //Other Method
        void updateBoard(Player& p, BoardTiles&, int,int);

};
#endif
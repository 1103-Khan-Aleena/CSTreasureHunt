#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class Board{
    protected:
    char** grid;
    int rows, columns;

    public:
        //Constrctors 
        Board();
        Board(int, int, char**);
        Board(const Board&);

        //Getters
        int getRows() const;
        int getColumns() const;
        char getElementAtTile(int, int) const;

        //Setters
        void setRows(int);
        void setColumns(int);
        void setElementAtTile(int, int, char);

        //Purely virtual  method
        virtual void generateBoard() = 0; //NO implementation 

        //Rule of 3
        ~Board();
        Board& operator=(const Board&);

        template <typename T>
        void clearBoard(T&, int r, int c);

        //Insertion operator
        friend ostream& operator<<(ostream&, const Board&);
};
#endif
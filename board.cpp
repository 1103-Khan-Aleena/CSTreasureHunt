#include "board.h"

//3 construtors
Board::Board(){
    rows = 5;
    columns = 5;
    grid = new char*[columns];
    for(int i = 0; i < columns; i++){
        grid[i] = new char[columns];
    }
}

Board::Board(int r, int c, char** g){
    rows = r;
    columns = c;
    grid = new char*[columns];
    for(int k = 0; k < columns; k++){
        grid[k] = new char[columns];
    }
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            grid[i][j] = g[i][j];
        }
    }
}

Board::Board(const Board&rhs){
    rows = rhs.rows;
    columns = rhs.columns;
    grid = new char*[rhs.columns];
    for(int k = 0; k < columns; k++){
        grid[k] = new char[columns];
    }
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            grid[i][j] = rhs.grid[i][j];
        }
    }
}

//Getters and setters
int Board::getRows() const{
    return rows;
}

int Board::getColumns() const{
    return columns;
}

char Board::getElementAtTile(int r, int c) const{
    return grid[r][c];
}

void Board::setRows(int r){
    rows = r;
}

void Board::setColumns(int c){
    columns = c;
}

void Board::setElementAtTile(int r, int c, char element){
    grid[r][c] = element;
}

//Destructor
Board::~Board(){
    for(int i = 0; i < rows; i++){
        delete [] grid[i];
    }
    delete[] grid;
}

//Equal operator
Board& Board::operator=(const Board& rhs){
    rows = rhs.rows;
    columns = rhs.columns;
    grid = new char*[rhs.columns];
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            grid[i][j] = rhs.grid[i][j];
        }
    }
    return *this; //Return *this because it is opertor not copy contructor
}

//Insertion operator
ostream& operator<<(ostream& out, const Board& b){
    for(int i = 0; i < b.getRows(); i++){
        for(int j = 0; j < b.getColumns(); j++){
            out << "[" << b.getElementAtTile(i, j) << "]";
        }
        out << endl; //Goes down line after every row
    }
    return out;
}

template <typename T>
void Board::clearBoard(T& board, int r, int c){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < c; j++){
            board[i][j] = ' ';
        }
    }
}
boards: userBoard.o board.o main.o
	g++ -o boards userBoard.o board.o main.o -g

main.o: main.cpp
	g++ -c main.cpp -g 

user_board.o: userBoard.cpp userBoard.h
	g++ -c userBoard.cpp -g

board_tiles.o: boardTiles.cpp boardTiles.h
board.o: board.cpp board.h
	g++ -c board.cpp -g

clean:
	rm *.o boards
boards: userBoard.o board.o main.o helpers.o board_tiles.o
	g++ -o boards userBoard.o board.o main.o helpers.o boardTiles.o -g

main.o: helpers.h userBoard.h board.h boardTiles.h main.cpp
	g++ -c main.cpp -g 

helpers.h: helpers.cpp helpers.h
	gcc -c helpers.cpp -g

user_board.o: userBoard.cpp userBoard.h
	g++ -c userBoard.cpp -g

board_tiles.o: boardTiles.cpp boardTiles.h
	g++ -c boardTiles.cpp -g

board.o: board.cpp board.h
	g++ -c board.cpp -g

clean:
	rm *.o boards
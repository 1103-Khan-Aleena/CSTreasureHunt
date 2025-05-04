game: player.o helpers.o main.o controls.o board.o userBoard.o board_tiles.o 
	g++ -o game player.o helpers.o main.o controls.o board.o userBoard.o boardTiles.o  -g

player.o: player.cpp player.h
	g++ -c player.cpp -g 

helpers.h: helpers.cpp helpers.h
	gcc -c helpers.cpp -g

main.o: main.cpp player.h helpers.h controls.h userBoard.h board.h boardTiles.h 
	gcc -c main.cpp -g
	
controls.o: controls.cpp controls.h
	g++ -c controls.cpp -g

board.o: board.cpp board.h
	g++ -c board.cpp -g

user_board.o: userBoard.cpp userBoard.h 
	g++ -c userBoard.cpp -g

board_tiles.o: boardTiles.cpp boardTiles.h
	g++ -c boardTiles.cpp -g

clean:
	rm *.o game
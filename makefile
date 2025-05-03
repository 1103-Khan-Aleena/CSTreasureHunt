# Target to create the executable
# Link all object files into the final executable
game: player.o main.o controls.o userBoard.o board.o
	g++ -o game player.o main.o controls.o userBoard.o board.o -g

# Compiling main.o from main.cpp
main.o: main.cpp player.h controls.h userBoard.h board.h
	g++ -c main.cpp -g

# Compiling Player.o from Player.cpp
player.o: player.cpp player.h
	g++ -c player.cpp -g

# Compiling Controls.o from controls.cpp
controls.o: controls.cpp controls.h
	g++ -c controls.cpp -g

# Compiling UserBoard.o from userBoard.cpp
userBoard.o: userBoard.cpp userBoard.h
	g++ -c userBoard.cpp -g

# Compiling Board.o from board.cpp
board.o: board.cpp board.h
	g++ -c board.cpp -g

# Clean up object files and the executable
clean:
	rm *.o game

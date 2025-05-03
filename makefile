# Target to create the executable
game: Player.o main.o
	g++ -o game Player.o main.o -g

# Compiling main.o from main.cpp
main.o: main.cpp Player.h
	g++ -c main.cpp -g

# Compiling Player.o from Player.cpp
Player.o: Player.cpp Player.h
	g++ -c Player.cpp -g

# Clean up object files and the executable
clean:
	rm *.o game

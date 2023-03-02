all:
	g++ -lraylib src/main.cpp src/player.cpp src/level.cpp -o sokoban -Wall -std=c++17

clean:
	rm sokoban

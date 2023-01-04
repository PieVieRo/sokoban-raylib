all:
	g++ -lraylib src/main.cpp src/player.cpp src/block.cpp -o sokoban -Wall -std=c++17

clean:
	rm sokoban

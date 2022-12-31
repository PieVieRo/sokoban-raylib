all:
	g++ -lraylib src/main.cpp src/player.cpp -o sokoban -Wall

clean:
	rm sokoban

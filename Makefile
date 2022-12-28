all:
	g++ -lraylib src/main.cpp -o sokoban -Wall

clean:
	rm sokoban

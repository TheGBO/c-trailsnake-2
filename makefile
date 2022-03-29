all:
	gcc src/main.c src/game.c -o bin/main -lSDL2 -lSDL2_image
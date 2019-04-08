animerperso:animation.o main.o
	gcc animation.o main.o -lSDL -lSDL_image -o animerperso

main.o:main.c
	gcc -c -lSDL -lSDL_image main.c

animation.o:animation.c
	gcc -c -lSDL -lSDL_image -lSDL_ttf animation.c

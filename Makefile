partdec:main.o coin.o background.o camera.o ennemiIA.o game.o
	gcc main.o coin.o background.o camera.o ennemiIA.o game.o -o Partdec -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c 
ennemiIA.o:ennemiIA.c
	gcc -c ennemiIA.c 
coin.o:coin.c
	gcc -c coin.c 
background.o:background.c
	gcc -c background.c 
camera.o:camera.c
	gcc -c camera.c  
game.o:game.c
	gcc -c game.c
clean:
	rm *.o Partdec

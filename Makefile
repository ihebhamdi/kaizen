Rebirth:main.o prince.o background.o camera.o ia.o game.o
	gcc main.o prince.o background.o camera.o ia.o game.o -o Rebirth -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c 
prince.o:prince.c
	gcc -c prince.c  
background.o:background.c
	gcc -c background.c 
camera.o:camera.c
	gcc -c camera.c  
game.o:game.c
	gcc -c game.c
ia.o:ia.c
	gcc -c ia.c
clean:
	rm *.o Rebirth

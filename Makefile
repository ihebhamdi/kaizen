ENNEMIAI:main.o ennemiIA.o background.o camera.o ennemiIA.o game.o
	gcc main.o ennemiIA.o background.o camera.o ennemiIA.o game.o -o ENNEMIAI -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c 
ennemi.o:ennemiIA.c
	gcc -c ennemiIA.c  
background.o:background.c
	gcc -c background.c 
camera.o:camera.c
	gcc -c camera.c  
game.o:game.c
	gcc -c game.c

clean:
	rm *.o ENNEMIAI

Menu.exe:menufct.o menu.o
	gcc menu.o menufct.o -o Menu.exe -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -g

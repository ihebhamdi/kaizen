#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

int main( int argc, char *argv[ ] )
   {
int go=1;
char pause;
initialiser(&m,&set);
    while (go == 1)
    {
        affichage(&m,&set);
    }

pause=getchar();
exit(0);
SDL_QUIT;
}

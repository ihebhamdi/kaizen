#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"
#include "bac1.h"

int main( int argc, char *argv[ ] )
   {
int go=1;
char pause;
    while (go == 1)
    {
        animer_player (player);
    }
pause=getchar();
exit(0);
}

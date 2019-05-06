#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "game.h"


int main( int argc, char *argv[] )
{
//*****************************************************************inisialisation***************************************************************
Game G;



SDL_Surface *ecran=NULL; 

SDL_Init( SDL_INIT_VIDEO ); 
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
    SDL_WM_SetCaption("Rebirth", NULL);


Game_NewGame(&G,ecran);

SDL_Delay(1000);
    SDL_FreeSurface(ecran);
    SDL_Quit();
    return EXIT_SUCCESS;
}


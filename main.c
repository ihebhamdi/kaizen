#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"
int main ()
{
int tempsPrecedent=0,posi=0,tempsActuel=0;
int continuer=1;

int conti=0,opt=1,done;
SDL_Event event;
SDL_Surface* screen=NULL;
SDL_Surface* bg=NULL;
bg=IMG_Load("enigme/start.PNG");
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1080,700,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
while(continuer) 
{ 
jeu(screen);
//
SDL_WaitEvent(&event);
switch (event.type)
{
case SDL_QUIT :
continuer =0;
break ; 
case SDL_KEYDOWN :
switch (event.key.keysym.sym)
{
case SDLK_ESCAPE :
continuer =0 ;
break ;

}
break ;
}
SDL_Flip (screen);
}
SDL_Quit();
return 0;
}

#include "bac1.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char *argv[])
{
int continuer=1;
Background B;
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());


//creation fenetre
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode(1300,700,32,SDL_HWSURFACE);

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_Flip(screen);



charger_Background(&B);
initBackground(&B);




while(continuer)
{
SDL_Event event;
SDL_PollEvent(&event);

blitBackground(&B,screen);
scrol(&B,screen,&event);


if(event.type==SDL_QUIT)
{
break;
}

}







freeBackground(&B);




}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "bac1.h"
#include "objet.h"

	/********** INITIALISATION OBJET **************/

void init_player(Objet *obj)
{
(obj->positionObjet).x=0 ;
(obj->positionObjet).y=355;
}
	/************ CHARGERMENT IMAGE **************/
void chargement_image ()
{
update_obj=IMG_Load("obj.png");
}
void affobj(Objet obj)
{
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1300,700,32,SDL_HWSURFACE);

SDL_BlitSurface(update_obj, NULL, screen, &(obj->positionObjet));

SDL_Flip(screen);

int continuer = 1;
SDL_Event event;
while (continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
}
}
SDL_FreeSurface(update_obj);
}

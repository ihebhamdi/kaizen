#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "menu.h"

int menu=1;
typedef struct menu
{
SDL_Surface *imagefond=NULL;
SDL_Surface *bouttonp = NULL;
SDL_Surface *bouttons = NULL;
SDL_Surface *bouttonq = NULL;


SDL_Rect positiondufond ;
SDL_Rect positionbouttonp;
SDL_Rect positionbouttons;
SDL_Rect positionbouttonq;
}menu;
menu m;
typedef struct settings
{
SDL_Surface *bouttonsound = NULL;
SDL_Surface *bouttonbrightness = NULL;
SDL_Surface *bouttoncredtis = NULL;
SDL_Rect positionbsound;
SDL_Rect positionbbrightness;
SDL_Rect positionbcredtis;
}settings;
settings set;
SDL_Event event={0};SDL_Surface *ecran=NULL;
void initialiser(menu *m, settings *set);
void affichage(menu *m, settings *set);


#endif /* MENU_H_ */

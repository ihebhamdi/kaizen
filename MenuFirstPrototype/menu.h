#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "menu.h"
#include <SDL/SDL_mixer.h>


struct menu
{
SDL_Surface *imagefond;
SDL_Surface *bouttonp;
SDL_Surface *bouttons;
SDL_Surface *bouttonq;


SDL_Rect positiondufond ;
SDL_Rect positionbouttonp;
SDL_Rect positionbouttons;
SDL_Rect positionbouttonq;
};
typedef struct menu menu;
menu m;
struct settings
{
SDL_Surface *bouttonsound;
SDL_Surface *bouttonbrightness;
SDL_Surface *bouttoncredtis;
SDL_Rect positionbsound;
SDL_Rect positionbbrightness;
SDL_Rect positionbcredtis;
};
typedef struct settings settings;
settings set;
SDL_Surface *ecran;
int update_menu();
void initialiser(menu *m, settings *set);
void affichage(menu *m, settings *set);
void pause();


#endif /* MENU_H_ */

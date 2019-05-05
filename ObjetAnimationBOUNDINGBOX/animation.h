#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include "bac1.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/****** DECLARATION DES STRUCTURE *********/
struct Player
{
SDL_Rect positionPlayer;
int react;
SDL_Surface *update_player;
SDL_Surface *image1;
};
typedef struct Player Player;
Player player;
/******* DECLARATION DES VARIABLE *********/

SDL_Event *event;SDL_Surface *screen;


/****** PROTOTYPE DES FONCTION ***********/

void init_player(Player *player ); // initialsation du personnage
void chargement_image () ; //chargement des image du personnnage
void animer_player(Player *player); // animation du personnage

#endif /* ANIMATION_H_ */

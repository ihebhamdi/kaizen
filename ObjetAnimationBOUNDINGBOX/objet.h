#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "bac1.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/****** DECLARATION DES STRUCTURE *********/
typedef struct Objet
{
SDL_Rect positionObjet;
}Objet;

/******* DECLARATION DES VARIABLE *********/
SDL_Surface *screen,*update_obj=NULL;

Objet obj;


/****** PROTOTYPE DES FONCTION ***********/
void init_player(Objet *obj);
void chargement_image ();

#endif 

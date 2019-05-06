/**
* @file ennemiIA.h
* @brief Init et deplacement de l'ennemi et l'utilisation de l'intelligence artificielle
* @author Zeineb Karma
* @version Beta
* @date Mai 06, 2019
*
* 
*
*/




#ifndef ENNEMIIA_H_INCLUDED
#define ENNEMIIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct ennemi
{
int direction;
int image;
SDL_Rect pos;
SDL_Surface *image[9];
int etat;

}ennemi;

void initEnnemi(ennemi*e);
void iADirection( SDL_Rect *ennemiPosition, SDL_Rect personnagePosition,ennemi*e);
void deplacer_ennemi( ennemi*e ,SDL_Surface*ecran, SDL_Rect pos,int *collision);
void blit(ennemi*e,SDL_Rect *pos, SDL_Surface* ecran);
int Collision( SDL_Rect box1,SDL_Rect box2);

#endif


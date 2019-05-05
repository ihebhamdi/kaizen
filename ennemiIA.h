#ifndef ENNEMIAI_H_INCLUDED
#define ENNEMIAI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct ennemi
{
int direction;
int imag;
SDL_Rect pos;
SDL_Surface *image[9];
int etat;

}ennemi;

void initEnnemi(ennemi*e);//thotha fi l'initialisation
void iADirection( SDL_Rect *ennemiPosition, SDL_Rect personnagePosition,ennemi*e);
void deplacer_ennemi( ennemi*e ,SDL_Surface*ecran, SDL_Rect pos,int *collision);//thotha fi l update mtaa lgame
void blit(ennemi*e,SDL_Rect *pos, SDL_Surface* ecran);//thotha fi l'affichage
int Collision( SDL_Rect box1,SDL_Rect box2);

#endif


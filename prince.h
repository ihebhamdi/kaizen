#ifndef PRINCE_H_INCLUDED
#define PRINCE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>





typedef struct prince
{
int i;
SDL_Rect position;
int moving;
int direction;
//SDL_Surface image[14];
SDL_Surface *image[16];
int d;
}prince;


//int Collision(SDL_Rect box1,SDL_Rect box2);

void initprince(prince*p,SDL_Rect* pos);
void marcheavant(prince *p);
void marcheariere(prince *p);
void marchegauche(prince *p);
void marchedroite(prince *p);
void displayprince(prince* p,SDL_Rect *pos,SDL_Surface *ecran);
void freeprince(prince *p);

//void displayprinceagauche(pince*p,SDL_Surface *ecran);
//void displayprincavnat(pince*p,SDL_Surface *ecran);
//void displayprindroite(pince*p,SDL_Surface *ecran);

#endif



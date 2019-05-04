#ifndef  ENIGME_H_INCLUDED 
#define ENIGMLE_H_INCLUDED

#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include<SDL/SDL_ttf.h>
#include<string.h> 
#include<math.h>
#include<time.h>

int val;
SDL_Surface *screen;

void affichage(int val);
int somme(int i);
int factorielle(int nb);
//void resolu();
void pause(); 

#endif  /* ENIGME_H_ */

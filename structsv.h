#ifndef STRUCTSV_H_INCLUDED
#define STRUCTSV_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct score score; 
struct score
{
	SDL_Rect pos_sc;
	SDL_Surface *image;
}sv;


struct Points
{
	int nb,n;
};
typedef struct Points point;
struct Vie
{
	SDL_Rect pos_vie;
	SDL_Surface *image_vie;
};
typedef struct Vie vie;

score sv;
point ps;
vie v;
point p;

void init(score *sv,vie *v);
void affichage(score *sv,point *ps,vie *v,point *p);
int gestion_vie_score(score *sv,point *ps,vie *v,point *p);
//void fin_jeu (point *p,point *ps);
void pause();
#endif

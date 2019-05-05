#include<stdio.h> 
#include<SDL/SDL.h> 
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

typedef struct
{
SDL_Surface *enigme ;
SDL_Rect posenigme ;
char rep[20];
SDL_Surface *posv[15] ;
SDL_Surface *posmsg[15] ;
SDL_Surface * texteenigme ;
Mix_Music * sons ;
int temps ;
int niveau ;
int max;
char quiz ;
int etat;//(enigme resolu=1,enigme faux=-1)
}enigme;

int generatin_aleatoire(int nbalea,int lvl);
void jeu(SDL_Surface *screen);
int  enigmequiz(int quiz, int curseur );
int lvl1 (SDL_Surface *screen);
void Indice(SDL_Surface *ecran,SDL_Surface *Indice,SDL_Rect posIndice);
int lvl2 (SDL_Surface *screen);
int lvl3 (SDL_Surface *screen);
int SDL_SetWindowFullscreen(SDL_Surface* screen , SDL_bool fullscreen);
void initialiser_enigme (enigme e[]);
void afficher_enigme (enigme e[],int lvl,int indice,SDL_Surface *screen);

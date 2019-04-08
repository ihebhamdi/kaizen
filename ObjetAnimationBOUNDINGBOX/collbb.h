#ifndef COLLBB_H_INCLUDED
#define COLLBB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct rect_collision 
{

 int hauteur ; 
int largeur ; 
SDL_Rect position; 
} rect_collision;

int Collision_Bounding_Box (SDL_Rect rec1 ,SDL_Rect position_obstacle) ;


#endif /* COLLBB_H_ */

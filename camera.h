#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>

typedef struct Camera
{
	SDL_Rect camera;

}Camera;

void init_camera(Camera *cam,SDL_Rect posperso,int width,int height);

void poscamera(Camera *cam,SDL_Rect posperso,int width,int height);







#endif

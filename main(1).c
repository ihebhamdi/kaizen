#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "backg.h"
#include "perso.h"
int main()
{

backg b;
perso c;
//
SDL_Surface* screen;
int now=0;
int ex=0;
int pfps=1;
int dt=0;
int run=1;
float pfpss=0;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
screen=SDL_SetVideoMode(1300,700,bpp,SDL_HWSURFACE);

initbackground(&b);
initperso(&c);

while(run){
now=SDL_GetTicks();
dt=now-ex;
if(dt>=pfps)
{
affichebackground(screen,&b);
afficheperso(screen,&c);
run=deplacement(&c);
SDL_Flip(screen);
}else
 SDL_Delay(pfps-dt);
}

freesurfaces(&b);

SDL_Quit();
return 0;

}

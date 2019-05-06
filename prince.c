
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "prince.h"






void initprince(prince*p,SDL_Rect* pos)
{
p->position=*pos;
p->d=0;
//p->velocity=0;
//p->a=0.01;
p->direction=0;

p->image[0]= IMG_Load("m.png");
p->image[1]= IMG_Load("m.png");
p->image[2] =  IMG_Load("m.png");
p->image[3]= IMG_Load("m.png");


p->image[4]= IMG_Load("m.png");
p->image[5]= IMG_Load("m.png");
p->image[6] =  IMG_Load("m.png");
p->image[7]= IMG_Load("m.png");

p->image[8]= IMG_Load("m.png");
p->image[9]=  IMG_Load("m.png");
p->image[10] = IMG_Load("m.png");
p->image[11]= IMG_Load("m.png");

p->image[12] =  IMG_Load("m.png");
p->image[13]= IMG_Load("m.png");
p->image[14] =  IMG_Load("m.png");
p->image[15]= IMG_Load("m.png");
}





void marchedroite(prince *p){



                     p->position.x= p->position.x+20;
p->d++;

if(p->d>3||p->d<0){p->d=0;}

}
void marchegauche(prince *p){


                     p->position.x= p->position.x-20;

                 
p->d++;
if(p->d>8||p->d<4){p->d=4;}

}

void marcheavant(prince *p){



                     p->position.y= p->position.y-20;

                 
p->d++;
if(p->d>12||p->d<8){p->d=9;}

}




void marcheariere(prince *p){



                     p->position.y= p->position.y+20;

                 
p->d++;
if(p->d>15||p->d<12){p->d=12;}

}




void displayprince(prince* p,SDL_Rect *pos,SDL_Surface *ecran)
{




SDL_BlitSurface(p->image[p->d], NULL, ecran, pos);

                              //SDL_Flip(ecran);

}

void freeprince(prince *p)
{


    SDL_FreeSurface(p->image[p->d]);



}



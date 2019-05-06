#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include"coin.h"

int Collision( SDL_Rect box1,SDL_Rect box2)

{

   if((box2.x >= box1.x + box1.w)      || (box2.x + box2.w <= box1.x) || (box2.y >= box1.y + box1.h) || (box2.y + box2.h <= box1.y)) 

          return 0;

   else

          return 1;

}





coin testcollision(SDL_Rect box1,coin c[],int n)
{

int i;
int k;
for(i=0;i<n;i++){

if(Collision( box1, c[i].position)==1)
{
c[i].etat=1;

}

}
return c[i];
}




void initcoin(coin*c)
{

c->etat=0;
c->image= IMG_Load("../img/coin.png");

}

void position(coin*c,int x,int y)
{

c->position.x=x;
c->position.y=y;


}




coin inittableaucoin(coin c[],int n,SDL_Rect pos[]){
int i;

for(i=0;i<n;i++)
{
 initcoin(&c[i]);
 position(&c[i],pos[i].x,pos[i].y);


}
return c[i];


}

void affichercoin (SDL_Surface *ecran,int n,coin c[])
{
int i;

for(i=0;i<n;i++)
{
if(c[i].etat!=1)
SDL_BlitSurface(c[i].image, NULL, ecran,&c[i].position);
SDL_Flip(ecran);

}

}

void freecoin(coin c[],int n)
{int i;
for(i=0;i<n;i++)

    SDL_FreeSurface(c[i].image);



}

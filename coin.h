

#include <SDL/SDL_ttf.h>



typedef struct coin
{
int etat;
SDL_Surface *image;
SDL_Rect position;

}coin;

void initcoin(coin*c);
void position(coin*c,int x,int y);

coin inittableaucoin(coin c[],int n,SDL_Rect pos[]);
void affichercoin (SDL_Surface *ecran,int n,coin c[]);
void freecoin(coin c[],int n);
int Collision( SDL_Rect box1,SDL_Rect box2);
coin testcollision(SDL_Rect box1,coin c[],int n);

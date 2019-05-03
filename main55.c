#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "structsv.h"


int main(int argc, char *argv[])
{

int go=1;
init(&sv,&v);
affichage(&sv,&ps,&v,&p);
gestion_vie_score(&sv,&ps,&v,&p);
while (go == 1)
{ 

//fin_jeu (&p,&ps);
}
SDL_Quit();
}

typedef struct
 {
SDL_Surface* person;
SDL_Event event;
SDL_Rect rect;
}perso;
void initperso(perso *c );
void afficheperso(SDL_Surface* screen, perso *c);
int deplacement(perso* c);

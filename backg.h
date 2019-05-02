typedef struct
 {
SDL_Surface* gamebackglvl1;
SDL_Rect backgr;
}backg;

void affichebackground(SDL_Surface* screen, backg *b);
void initbackground(backg *b);
void freesurfaces(backg *b);


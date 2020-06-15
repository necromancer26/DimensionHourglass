#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct
{
 SDL_Surface * img;
 SDL_Rect p;
}enigmeyacyn;
int enigm(SDL_Surface * screen);
void init_enigme(enigmeyacyn * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigmeyacyn *e,int *alea) ;
 int solution_e (char image [],int *ques) ;
int resolution (int * running,int *run);
int afficher_resultat (SDL_Surface * screen,int s,int r,enigmeyacyn *en,int ques) ;

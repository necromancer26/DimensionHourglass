#ifndef ENNEMIEYA_H_INCLUDED
#define ENNEMIEYA_H_INCLUDED

#include<SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include "menu.h"

typedef enum STATE STATE;
enum STATE { waiting, following, attacking,running_away};
typedef struct Ennemieya
{
    int hp;
    SDL_Surface *Ennemi[7];
    SDL_Rect posennemi;
    STATE state;
    int inum;
    int ixmin;
    int ixmax;
    int d;
} ennemieya;
void animateEnnemi(ennemieya* E);
void updateEnnemiState (ennemieya* E, int dist);
void moveEnnemi(ennemieya* E,Kay  *kay);  //pos heya lposition mta3 ljoueur
void initeneya(ennemieya *E);
#endif
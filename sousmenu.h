#ifndef SOUSMENU_INCLUDED
#define SOUSMENU_INCLUDED

#include<SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
/*------------------------------------------------------------------*/
/*------------------------LES STRUCTURES----------------------------*/
typedef struct SousMenu
{
	SDL_Surface *menu;//
	SDL_Surface *settings;//
	SDL_Surface *quit;//
	SDL_Surface *resume;
	SDL_Surface *save;
	SDL_Rect pmenu;//
	SDL_Rect psettings;//
	SDL_Rect pquit;//
	SDL_Rect presume;
	SDL_Rect psave;


}SousM;

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*-------------------------LES PROTOTYPES-----------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
void displaysousmenu(int *nbmenu,SousM *SM,SDL_Surface *ecran,int *cas);
void initsousmenu(SousM *SM);
int sous_menus(Kay kay,Camera cam);

#endif

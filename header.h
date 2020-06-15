#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<SDL/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/**
* @struct Kay
* @brief main character
*/
typedef struct Kay
{
	SDL_Surface *imgkayd1[4];
	SDL_Surface *imgkayd2[4];
	SDL_Surface *imghp;
	SDL_Rect poskay;
	SDL_Rect posrkay;
	double v;
	double acc;
	double dx;
	int moving;
	int hp;
	int hauteur, saut, hauteurAtteint, posinit;//saut
    SDL_Rect poshp;
	//vie kayvie;
}Kay;
/*------------------------------------------------------------------*/
/**
* @struct Camera
* @brief for scrolling
*/
typedef struct Camera
{
    SDL_Rect pos_cam;
}Camera;
/*------------------------------------------------------------------*/
/**
* @struct Ennemi
* @brief ennemy
*/
typedef struct Ennemi
{
	int hp;
	SDL_Surface *imgennemi[9];
	SDL_Rect posennemi;
}ennemi;
/*------------------------------------------------------------------*/
/**
* @struct Background
* @brief for background
*/
typedef struct Background
{
	SDL_Surface *background,*backmask;
	SDL_Rect posbg;
}Background;
/*------------------------------------------------------------------*/
typedef struct Entite1
{
	SDL_Surface *imges[3];
	SDL_Rect poses;
}ESH;
typedef struct Entite2
{
	SDL_Surface *imges[3];
	SDL_Rect poses;
}ESL;
typedef struct Enigme
{
	SDL_Surface *imgpc;
	SDL_Rect pospc;
}engpc;
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*-------------------------LES PROTOTYPES-----------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
void initES(ESH *helico/*,ESL *light*/);
void acceleration(Kay *kay,Camera *cam,int *aclrt,int *maxj,int *scroll,int *decceleration);
void game();
void initkay(Kay *kay,int *choix);//fct fatma
void animationES(/*ESL *light,*/ESH *helico,/*int *lightanim,*/int *helianim);
void initJoi(Kay *Joi);
void enigme ();
void deplacerkay(Kay *kay,Camera *cam,int *d,int *scroll,Background *backgrd,int *collision);
void character2();
void initen(ennemi *en);
void init_hp(SDL_Surface *imghp,SDL_Surface *ecran,SDL_Rect *poshp);
void init_cam(SDL_Rect *poscam);
void init_background(SDL_Surface *background,SDL_Surface *backmask,SDL_Surface *ecran,SDL_Rect *posbg);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int Test_Collision(SDL_Surface *backmask,SDL_Rect poskay,int *d);
void deplacerSourisHero(Kay *H, SDL_Event event);//DORSAF
void cascollisionBG(Kay *kay,Camera *cam,int *scroll,int *d,int *collision);
int Collision_Bounding_Box (Kay *kay ,ennemi *en) ;
int Collision_Bounding_Box_Enigme (Kay *kay ,engpc *pen) ;
void displayhp(int *continuer,Kay *kay ,SDL_Surface *fecran);
void displaybackground(SDL_Surface *fecran,SDL_Surface *fbackmask,SDL_Surface *fbackgm,SDL_Rect *fbg,SDL_Rect *fpos_cam);
void saut(Kay *kay);
void partageecran(Kay *kay,Camera *cam,int *collision,int *d,Background *backgrd);
void partageecran2(Kay *kay,Camera *cam,int *collision,int *d,Background *backgrd);
void deplacerSouris(Kay *kay, int pos_souris);
void multiplayer(Kay *kay,Kay *joi);
#endif

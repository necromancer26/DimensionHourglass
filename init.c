#include "header.h"
void initkay(Kay *kay,int *choix)//fct fatma
{
	if(*choix==111)
	{
    kay->imgkayd1[0]=IMG_Load("sprite/d21.png");
    kay->imgkayd1[1]=IMG_Load("sprite/d22.png");
    kay->imgkayd1[2]=IMG_Load("sprite/d23.png");
    kay->imgkayd1[3]=IMG_Load("sprite/d24.png");


    kay->imgkayd2[0]=IMG_Load("sprite/d11.png");
    kay->imgkayd2[1]=IMG_Load("sprite/d12.png");
    kay->imgkayd2[2]=IMG_Load("sprite/d113.png");
    kay->imgkayd2[3]=IMG_Load("sprite/d114.png");
	}
	if(*choix==112)
	{
    kay->imgkayd1[0]=IMG_Load("joi/1.png");
    kay->imgkayd1[1]=IMG_Load("joi/2.png");
    kay->imgkayd1[2]=IMG_Load("Joi/3.png");
    kay->imgkayd1[3]=IMG_Load("Joi/4.png");


    kay->imgkayd2[0]=IMG_Load("joi/11.png");
    kay->imgkayd2[1]=IMG_Load("joi/22.png");
    kay->imgkayd2[2]=IMG_Load("joi/33.png");
    kay->imgkayd2[3]=IMG_Load("joi/44.png");
	}
	kay->poskay.x=20;
	kay->poskay.y=640;
	kay->posrkay.x=20;
	kay->posrkay.y=640;


	kay->posinit=kay->poskay.y;
	kay->hauteur=75;
	kay->saut=0;
	kay->hauteurAtteint=0;


}
void multiplayer(Kay *kay,Kay *joi)
{
    kay->imgkayd1[0]=IMG_Load("sprite/d21.png");
    kay->imgkayd1[1]=IMG_Load("sprite/d22.png");
    kay->imgkayd1[2]=IMG_Load("sprite/d23.png");
    kay->imgkayd1[3]=IMG_Load("sprite/d24.png");


    kay->imgkayd2[0]=IMG_Load("sprite/d11.png");
    kay->imgkayd2[1]=IMG_Load("sprite/d12.png");
    kay->imgkayd2[2]=IMG_Load("sprite/d113.png");
    kay->imgkayd2[3]=IMG_Load("sprite/d114.png");

    joi->imgkayd1[0]=IMG_Load("joi/1.png");
    joi->imgkayd1[1]=IMG_Load("joi/2.png");
    joi->imgkayd1[2]=IMG_Load("Joi/3.png");
    joi->imgkayd1[3]=IMG_Load("Joi/4.png");


    joi->imgkayd2[0]=IMG_Load("joi/11.png");
    joi->imgkayd2[1]=IMG_Load("joi/22.png");
    joi->imgkayd2[2]=IMG_Load("joi/33.png");
    joi->imgkayd2[3]=IMG_Load("joi/44.png");
	joi->poskay.x=20;
	joi->poskay.y=640;
	joi->posrkay.x=20;
	joi->posrkay.y=640;

	joi->poskay.x=610;
	joi->poskay.y=640;
	joi->posrkay.x=610;
	joi->posrkay.y=610;

	joi->posinit=kay->poskay.y;
	joi->hauteur=75;
	joi->saut=0;
	joi->hauteurAtteint=0;
	kay->posinit=kay->poskay.y;
	kay->hauteur=75;
	kay->saut=0;
	kay->hauteurAtteint=0;

}
/*------------------------------------------------------------------*/
void initen(ennemi *en)
{
	en->posennemi.x=2000;
	en->posennemi.y=640;
	en->imgennemi[0]=IMG_Load("sprite/2.png");
	en->imgennemi[1]=IMG_Load("sprite/2.png");
	en->imgennemi[2]=IMG_Load("sprite/2.png");
	en->imgennemi[3]=IMG_Load("sprite/2.png");
	en->imgennemi[4]=IMG_Load("sprite/2.png");
	en->imgennemi[5]=IMG_Load("sprite/2.png");
	en->imgennemi[6]=IMG_Load("sprite/2.png");
	en->imgennemi[7]=IMG_Load("sprite/2.png");
}
/*------------------------------------------------------------------*/
/*-------------------------LES INITIALISATION-----------------------*/
void init_hp(SDL_Surface *imghp,SDL_Surface *ecran,SDL_Rect *poshp)
{
	poshp->x=800;
	poshp->y=10;
	SDL_BlitSurface(imghp,NULL,ecran,poshp);
}
void init_cam(SDL_Rect *poscam)
{
	poscam->x=0;
    poscam->y=0;
    poscam->h=1000;
    poscam->w=1200;

}
void init_background(SDL_Surface *background,SDL_Surface *backmask,SDL_Surface *ecran,SDL_Rect *posbg)
{
	posbg->x=200;
	posbg->y=0;
	SDL_BlitSurface(backmask,NULL,ecran,posbg);
	SDL_BlitSurface(background,NULL,ecran,posbg);
}
/*------------------------------------------------------------------*/
void initES(ESH *helico/*,ESL *light*/)
{
	helico->imges[0]=IMG_Load("ES/heli22.png");
	helico->imges[1]=IMG_Load("ES/heli11.png");

	helico->imges[2]=NULL;
	helico->imges[3]=NULL;

	helico->poses.x=800;
	helico->poses.y=100;
}
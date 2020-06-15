#include "header.h"

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*----------------------FONCTION GET PIXEL--------------------------*/
/*------------------------------------------------------------------*/
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}
/*------------------------------------------------------------------*/
/*----------------------FONCTION TEST COLLISION---------------------*/
/*------------------------------------------------------------------*/
int Test_Collision(SDL_Surface *backmask,SDL_Rect poskay,int *d)
{
    SDL_Color color1,color2,color3,color4,color5,color6,color7,color8;

		//gauche
		color1=GetPixel(backmask,poskay.x,poskay.y);//haut zeda
		color5=GetPixel(backmask,poskay.x,poskay.y+poskay.h);//bas zeda
		color4=GetPixel(backmask,poskay.x,poskay.y+(poskay.h/2));
		//haut
		color8=GetPixel(backmask,poskay.x+poskay.w,poskay.y+(poskay.h/2));//droite zeda
		color2=GetPixel(backmask,poskay.x+(poskay.w/2),poskay.y);
		color3=GetPixel(backmask,poskay.x+poskay.w,poskay.y);//droite zeda
		color6=GetPixel(backmask,poskay.x+(poskay.w/2),poskay.y+poskay.h);
		color7=GetPixel(backmask,poskay.x+poskay.w,poskay.y+poskay.h);//doite zeda
	if(*d==1)
	{
		if(((color8.r==255)||(color8.b==255)||(color8.g==255))||((color7.r==255)||(color7.b==255)||(color7.g==255))||((color3.r==255)||(color3.b==255)||(color3.g==255)))
		return 1;
	}
	if(*d==2)
	{
		if(((color1.r==255)||(color1.b==255)||(color1.g==255))||((color5.r==255)||(color5.b==255)||(color5.g==255))||((color4.r==255)||(color4.b==255)||(color4.g==255)))
		return 1;
	}
	if(*d==3)
	{
		if(((color1.r==255)||(color1.b==255)||(color1.g==255))||((color8.r==255)||(color8.b==255)||(color8.g==255))||((color2.r==255)||(color2.b==255)||(color2.g==255)))
		return 1;
	}
	if(*d==4)
	{
		if(((color6.r==255)||(color6.b==255)||(color6.g==255)||(color7.r==255)||(color7.b==255)||(color7.g==255)||(color5.r==255)||(color5.b==255)||(color5.g==255)))
		return 1;
	}
return 0;//collision;
}
/*--------------------------------------------------------------------*/
/*-----------------------EN CAS DE COLLISION--------------------------*/
/*--------------------------------------------------------------------*/
void cascollisionBG(Kay *kay,Camera *cam,int *scroll,int *d,int *collision)
{
if((*collision==1)&&(*scroll==1)&&(*d==1))
{
kay->poskay.x=kay->poskay.x;
kay->posrkay.x-=5;
//kay->posrkay.x=cam->pos_cam.x+(605);
printf("collision");
}
else if((*collision==1)&&(*scroll==0)&&(*d==1))
{
kay->posrkay.x-=5;
kay->poskay.x-=5;
}
else if((*collision==1)&&(*scroll==0)&&(*d==2))
{
kay->posrkay.x+=5;
kay->poskay.x+=5;
}
else if((*collision==1)&&(*scroll==1)&&(*d==2))
{
kay->posrkay.x+=5;
kay->poskay.x=kay->poskay.x;
}
else if((*collision==1)&&(*d==3))
{
kay->poskay.y+=5;
printf("collision");
}
else if((*collision==1)&&(*d==4))
{
kay->poskay.y-=5;
printf("collision");
}
*collision=0;
}/**************************************************************/
//collision bounding box
int Collision_Bounding_Box (Kay *pkay ,ennemi *pen) 
{

	int colli =1 ; 
		if((pkay->poskay.x+pkay->poskay.w)>=(pen->posennemi.x)&&(pkay->poskay.x)<=(pen->posennemi.x+pen->posennemi.w)&&(pkay->poskay.y+pkay->poskay.h)>=(pen->posennemi.y)&&(pkay->poskay.y)<=(pen->posennemi.y+pen->posennemi.h))
	{
		return 0 ; 
	}
	else
	return 1;

}
int Collision_Bounding_Box_Enigme (Kay *pkay ,engpc *pen) 
{

	int colli =1 ; 
		if((pkay->poskay.x+pkay->poskay.w)>=(pen->pospc.x)&&(pkay->poskay.x)<=(pen->pospc.x+pen->pospc.w)&&(pkay->poskay.y+pkay->poskay.h)>=(pen->pospc.y)&&(pkay->poskay.y)<=(pen->pospc.y+pen->pospc.h))
	{
		return 0 ; 
	}
	else
	return 1;

}
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_gfxPrimitives.h"
#include "animation.h"

void DimensionHourglass()
{
Objett tab [220],tab2[220] ;
    Objett surface1,surface2;
    SDL_Surface *ecran=NULL;
    int continuer=1;
    int fr=0;
    int actuel=0;
    int prec=0;
    ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

    load_transition(tab);
    //load_transition1(tab);
    while (continuer)
    {
                  if (fr<=208)   
                   { update_transition(ecran ,tab,&fr) ;
                     if (actuel - prec > 60)
                         {
                           update_transition(ecran ,tab,&fr) ;
                           prec = actuel;

                         }
                      else 
                         {
                           SDL_Delay(25 - (actuel - prec));
                         }
                   }
                   SDL_Flip(ecran);
                   if (fr==209)
                   continuer=0;
    }
    
    

    return ;
}

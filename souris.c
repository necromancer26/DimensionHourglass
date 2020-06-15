#include "header.h"

void deplacerSouris(Kay *kay, int pos_souris)
{
	if(kay->poskay.x < pos_souris)
	{
		kay->poskay.x += 5;
	}
	else if(kay->poskay.x > pos_souris)
	{
		kay->poskay.x -= 5;
	}
}

// fel main
// declaration 
//int pos_souris;
//pos_souris=kay.poskay.x;
//fi west poll switch(event.type)


//appel na3mlouh fou9 SDL_BlitSurface
//deplacerSouris(&kay, pos_souris);

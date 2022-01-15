#include <stdio.h>
#include "config.h"
#include "animations.h"
#include <time.h>

void animation_lapins(Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int lapin,int *carte_piochee)
{
  switch(tour_a_qui)
  {
    case 0 :
    /*De façon à avoir une seule fonction, les conditions sont vérifiées 2 fois
      (dans avancer puis dans cette fonction)*/
      // if(*carte_piochee > 1) Pointeur de pointeur ? Pas terrible...
      // {
        // printf("RENTRÉ");
        if(plateau[J1[lapin].position]== VIDE)
        {
          plateau[J1[lapin].position]=JOUEUR_1;
          afficher_plateau(plateau);
          usleep(TEMPS_ANIMATIONS);
          plateau[J1[lapin].position]=VIDE;
          afficher_plateau(plateau);
        }
        else if(plateau[J1[lapin].position]==JOUEUR_1 || plateau[J1[lapin].position]== JOUEUR_2)
        {
          //on print un lapin au dessus de l'autre
        }
      // }
    break;
    case 1 :
      // if(*carte_piochee > 1)
      // {
        // printf("RENTRÉ");
        if(plateau[J2[lapin].position]== VIDE)
        {
          plateau[J2[lapin].position]=JOUEUR_2;
          afficher_plateau(plateau);
          usleep(TEMPS_ANIMATIONS);
          plateau[J2[lapin].position]=VIDE;
          afficher_plateau(plateau);
        }
        else if(plateau[J1[lapin].position]==JOUEUR_1 || plateau[J1[lapin].position]== JOUEUR_2)
        {
          //on print un lapin au dessus de l'autre
        }
      // }
    break;
  }
}

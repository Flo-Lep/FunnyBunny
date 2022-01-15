//Plateau
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Pour initialiser rand
#include "plateau.h"
#include "config.h"
#include "jeu.h"


void init_plateau(int plateau[],int cases_rotatives[]){

	plateau[NB_CASES-1] = CAROTTE; //On prépare l'affichage de la carte carotte
	int case_alea1=0, case_alea2=0, case_alea3=0;
//ATTRIBUTION DE 3 NOMBRES ALÉATOIRES QUI DIFFÈRENT ENTRE EUX (Les cases rotatives doivent être différentes)
	while ((case_alea1 == case_alea2) || (case_alea1==case_alea3) || (case_alea2==case_alea3))
	{
		case_alea1 = rand()%((NB_CASES-2)+1); //On exclut les valeurs 0 et carotte
		case_alea2 = rand()%((NB_CASES-2)+1); //Entre 1 et 23 pour 25 cases/plateau[23] = case 24
		case_alea3 = rand()%((NB_CASES-2)+1);	//plateau[24] = case25 = carotte
	}
//ON CONSERVE LES 3 NOMBRES DANS LE BUT DE LES RÉUTILISER LORSQUE L'ON PIOCHERA LA CARTE CAROTTE
  cases_rotatives[0] = (case_alea1);
  cases_rotatives[1] = (case_alea2);
  cases_rotatives[2] = (case_alea3);
}

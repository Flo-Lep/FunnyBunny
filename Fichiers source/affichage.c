//AFFICHAGE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "affichage.h"
#include "jeu.h"
#include "lapin.h"

void afficher_plateau(int plateau[]) {
	printf("\n");
	moveto(1,5);printf("\E[32m");printf("*");
	for(int i=0;i<NB_CASES;i++){
		if (plateau[i] == VIDE){
			printf("\E[32m");printf("___");printf("*");printf("\E[0m");
		}
		if (plateau[i] == TROU){
			printf("   ");printf("\E[32m");printf("*");printf("\E[0m");
		}
		if (plateau[i] == JOUEUR_1){
	 		printf("\E[1;36m");printf("L1.");printf("\E[0m");printf("\E[32m");printf("*");printf("\E[0m");
	 	}
		if (plateau[i] == JOUEUR_2){
			printf("\E[1;33m");printf("L2.");printf("\E[0m");printf("\E[32m");printf("*");printf("\E[0m");
		}
		if(plateau[i] == CAROTTE){
			printf("\E[1;31;5m");printf("_C_");printf("\E[0m");printf("\E[32m");printf("*");printf("\E[0m");
		}
	}
	printf("\n");
}

void afficher_nom(char nom_joueur_1[], char nom_joueur_2[], int tour_a_qui){
  if (tour_a_qui==0)
  {
		printf("\E[1;36m");
		moveto(30,2);printf("********** C'EST LE TOUR DE %s **********",nom_joueur_1);
		printf("\E[0m");
    }
  else if (tour_a_qui==1)
  {

		printf("\E[1;33m");
		moveto(30,2);printf("********** C'EST LE TOUR DE %s **********",nom_joueur_2);
		printf("\E[0m");
  }
}

void afficher_infos_joueurs(Lapin J1[],Lapin J2[],char nom_joueur_1[],char nom_joueur_2[])
{
	printf("\n");
	moveto(16,11);printf("\E[1;36m");printf("Lapins de %s :",nom_joueur_1);printf("\E[1;33m");moveto(62,11);printf("Lapins de %s :",nom_joueur_2 );printf("\E[0m");
	moveto(16,13);printf("Lapin n°1 -> pos :%d état :%d",J1[0].position+1,J1[0].etat);moveto(62,13);printf("Lapin n°1 -> pos :%d état :%d",J2[0].position+1,J2[0].etat);
	moveto(16,14);printf("Lapin n°2 -> pos :%d état :%d",J1[1].position+1,J1[1].etat);moveto(62,14);printf("Lapin n°2 -> pos :%d état :%d",J2[1].position+1,J2[1].etat);
	moveto(16,15);printf("Lapin n°3 -> pos :%d état :%d",J1[2].position+1,J1[2].etat);moveto(62,15);printf("Lapin n°3 -> pos :%d état :%d",J2[2].position+1,J2[2].etat);
	moveto(16,16);printf("Lapin n°4 -> pos :%d état :%d",J1[3].position+1,J1[3].etat);moveto(62,16);printf("Lapin n°4 -> pos :%d état :%d",J2[3].position+1,J2[3].etat);
	printf("\n\n");
}

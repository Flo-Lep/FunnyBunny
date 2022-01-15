
/***************************- MAIN -***************************/

//Bibliothèques intégrées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
//Fonctionnalités du jeu
#include "plateau.c"
#include "pioche.c"
#include "affichage.c"
#include "jeu.c"
#include "lapin.c"
#include "menu.c"
#include "animations.c"

//Headers
#include "config.h"
#include "plateau.h"
#include "pioche.h"
#include "jeu.h"
#include "lapin.h"
#include "menu.h"
#include "animations.h"

//AFFICHAGE
#include "affichage.h"

int main(void){
  bool rejouer = true;
  lapin_emoji();
  while(rejouer)
  {
/*************** INITIALISATION ***************/
    //Variables
    srand(time(NULL)); //Pour la fonction rand()
    int plateau[NB_CASES] = {0};
    int pioche[NB_CARTES_TOTAL] = {0};
    int cases_rotatives[NB_CASES_ROTATIVES] = {0};
    int tour_a_qui = 0;
    int carte_piochee = -1;
    int lapin = -1;
    bool win = false;
    char nom_joueur_1[100],nom_joueur_2[100],nom_joueur_3[100];
    int choix_menu = 0;
    //Structures
    Lapin J1[NB_LAPINS]; //Le tableau commence à 0
    Lapin J2[NB_LAPINS];
    init_lapins(J1,J2);
    //Plateau
    init_plateau(plateau,cases_rotatives);
    init_pioche(pioche);
    melanger_pioche(pioche);
/*--------------- AFFICHAGE DU MENU ---------------*/
    menu(&choix_menu);
    switch (choix_menu)
    {
      //JOUER AU JEU
      case 1 :
        nom_joueur(nom_joueur_1,nom_joueur_2,nom_joueur_3);
        lancer_partie(J1,J2,plateau,cases_rotatives,carte_piochee,tour_a_qui,lapin,nom_joueur_1,nom_joueur_2,&win,pioche);
        break;

      //REPRENDRE LA PARTIE
      case 2:
        lecture_sauvegarde(J1,J2,plateau,nom_joueur_1,nom_joueur_2,&tour_a_qui,pioche,cases_rotatives);
        lancer_partie(J1,J2,plateau,cases_rotatives,carte_piochee,tour_a_qui,lapin,nom_joueur_1,nom_joueur_2,&win,pioche);
        break;

      //AFFICHER LES RÈGLES DU JEU
      case 3:
        system("clear");
        regles_croque_carotte();
        break;

      //QUITTER LE JEU
      case 4:
        rejouer = false;
        moveto(25,23);printf("          Vous avez décidé de quitter le jeu");
        moveto(48,24);printf("À BIENTOT !\n\n\n");
        break;

      default:
        moveto(29,23);printf("Erreur de saisie, veuillez changer votre choix");getchar();
        break;

    }
  }
  return 0;
}

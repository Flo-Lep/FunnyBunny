#ifndef JEU_H_
#define JEU_H_
/*----------------------------------------------------*/

typedef enum{
  TROU=-1,
  VIDE,
  JOUEUR_1,
  JOUEUR_2,
  //JOUEUR_3,
  //JOUEUR_4
  CAROTTE = 5,
}plateau_e;

typedef enum{
  CARTE_CAROTTE,
  CARTE_AVANCER_DE_1,
  CARTE_AVANCER_DE_2,
  CARTE_AVANCER_DE_3
}cartes_e;

void selection_lapin(/*Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int *lapin,int carte_piochee,char nom_joueur_1[], char nom_joueur_2[],int pioche[],int cases_rotatives[]*/);
void tourner_carotte(/*Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[]*/);
void avancer(/*Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int lapin,int *carte_piochee*/);
void action_carte(/*Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[],int carte_piochee,int tour_a_qui,int lapin,char nom_joueur_1[], char nom_joueur_2[],bool *win,int pioche[]*/);
void check_win(/*Lapin J1[],Lapin J2[],int plateau[],bool *win,char nom_joueur_1[],char nom_joueur_2[]*/);
void lancer_partie(/*Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[],int carte_piochee,int tour_a_qui,int lapin,char nom_joueur_1[], char nom_joueur_2[],bool *win,int pioche[]*/);

/*----------------------------------------------------*/
#endif

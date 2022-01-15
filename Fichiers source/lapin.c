
#include <stdio.h>
#include "lapin.h"

//NE FONCTIONNE QUE POUR 2 JOUEURS
void init_lapins(Lapin J1[],Lapin J2[]){

  for(int i=0;i<=NB_LAPINS;i++)
  {
    J1[i].couleur = BLEU;
    J1[i].position = DEPART;
    J1[i].etat = VIVANT;
    J2[i].couleur = ROUGE;
    J2[i].position = DEPART;
    J2[i].etat = VIVANT;
  }

  // J1[0].couleur = BLEU; J1[0].position = 13;     J1[0].etat = VIVANT;
  // J1[1].couleur = BLEU; J1[1].position = 15; J1[1].etat = VIVANT;
  // J1[2].couleur = BLEU; J1[2].position = DEPART; J1[2].etat = VIVANT;
  // J1[3].couleur = BLEU; J1[3].position = DEPART; J1[3].etat = VIVANT;
  //
  // J2[0].couleur = ROUGE; J2[0].position = 12; J2[0].etat = VIVANT;
  // J2[1].couleur = ROUGE; J2[1].position = DEPART; J2[1].etat = VIVANT;
  // J2[2].couleur = ROUGE; J2[2].position = DEPART; J2[2].etat = VIVANT;
  // J2[3].couleur = ROUGE; J2[3].position = DEPART; J2[3].etat = VIVANT;
}

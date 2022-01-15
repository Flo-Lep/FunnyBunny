//Pioche
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "config.h"
#include "pioche.h"
#include "jeu.h"

void init_pioche(int pioche[]){
  for(int i=0;i < NB_CARTES_TOTAL;i++)
    {
      pioche[i] = -1;
    }
}

void melanger_pioche(int pioche[]){ //obj : Assigner toutes les cartes de la pioche aux cases valant -1
  //CARTE CAROTTE (OK)
  int i=0;
  while(i < NB_CARTES_CAROTTE)
  {
    int emplacement = (rand()%NB_CARTES_TOTAL);
    if(pioche[emplacement]==-1)//Aucune valeur n'a été assignée
    {
      pioche[emplacement]=CARTE_CAROTTE; //on assigne la carte carotte à la case
      i = i+1;
    }
  }
  //CARTE AVANCER DE 1 (OK)
  int j=0;
  while(j < NB_CARTES_AVANCER_1)
  {
    int emplacement = (rand()%NB_CARTES_TOTAL);
    if(pioche[emplacement]==-1)//Aucune valeur n'a été assignée
    {
      pioche[emplacement]=CARTE_AVANCER_DE_1; //on assigne la carte avancer de 1 à la case
      j = j+1;
    }
  }
  //CARTE AVANCER DE 2 (OK)
  int x=0;
  while(x < NB_CARTES_AVANCER_2)
  {
    int emplacement = (rand()%NB_CARTES_TOTAL);
    if(pioche[emplacement]==-1)//Aucune valeur n'a été assignée
    {
      pioche[emplacement]=CARTE_AVANCER_DE_2; //on assigne la carte avancer de 2 à la case
      x = x+1;
    }
  }
  //CARTE AVANCER DE 3 (OK)
  int y=0;
  while(y < NB_CARTES_AVANCER_3)
  {
    int emplacement = (rand()%NB_CARTES_TOTAL);
    if(pioche[emplacement]==-1)//Aucune valeur n'a été assignée
    {
      pioche[emplacement]=CARTE_AVANCER_DE_3; //on assigne la carte avancer de 3 à la case
      y = y+1;
    }
  }
}

void piocher(int pioche[],int *carte_piochee){
  int case_alea = 0;
  int x = 0;
  int a = 0; //a = carte déjà piochee
  //RESTE T-IL DES CARTES DANS LA PIOCHE ?
  for(int i=0;i<NB_CARTES_TOTAL;i++){
    if((pioche[i])==-1){
      a++;
    }
    //PLUS DE CARTES DISPOS
    if(a == NB_CARTES_TOTAL){
      melanger_pioche(pioche);
      moveto(40,7);printf("La pioche a été mélangée");
    }
  }
  //ON PIOCHE
  while(x==0){
  case_alea = (rand()%NB_CARTES_TOTAL);
    if(pioche[case_alea] != -1){ //si cette carte n'a pas déjà été piochée
      *carte_piochee = pioche[case_alea];
      pioche[case_alea] = -1; //Retire la carte de la pioche
      x++;
    }
  }
  //AFFICHAGE DE LA CARTE PIOCHÉE
  if(*carte_piochee != 0)
  {
    printf("\n");
    moveto(33,8);printf("Vous avez pioché la carte avancer de ");printf("\E[1;4m");printf("%d",*carte_piochee);printf("\E[0m");
  }
  else
  {
    printf("\n");
    moveto(34,8);printf("Vous avez pioché la carte");printf("\E[1;31m"); printf(" carotte..."); printf("\E[0m");
  }
}

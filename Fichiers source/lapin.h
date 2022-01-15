#ifndef LAPIN_H_
#define LAPIN_H_
/*----------------------------------------------------*/
#include <stdio.h>
#include "config.h"
/****************************FONCTIONNEMENT****************************/
/*-CHAQUE JOUEUR DISPOSE D'UN TABLEAU OÙ CHAQUE INDICE CONTIENT LA STRUCTURE D'UN
DE SES LAPINS
-ON VIENT ENSUITE MODIFIER LES DONNEES D'UNE DES STRUCTURES EN FONCTION DU
LAPIN QUE L'ON SOUHAITE MODIFIER*/
/****************************PROTOTYPES****************************/
void init_lapins(/*Lapin J1[],Lapin J2[]*/);
/******************************TYPES******************************/
typedef enum{
  BLEU,   //0    //Couleurs à def ds config ???
  ROUGE,  //1
  VERT,  //2
  JAUNE //3
}couleur_e;

typedef enum{
  MORT, //0
  VIVANT    //1
}etat_e;

typedef enum{
  OUT = -2, //Est affiché pos = -1 lorsque le lapin est mort ds le jeu
  DEPART = -1,
  ARRIVEE = 25
}position_e;

typedef struct{ //La structure "générique" de chaque lapin
  int couleur;
  int position;
  int etat;
} Lapin;

/*----------------------------------------------------*/
#endif

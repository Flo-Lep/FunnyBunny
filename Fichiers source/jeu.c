//JEU
#include <stdio.h>
#include <time.h>
#include <unistd.h> //usleep
#include "lapin.h"
#include "jeu.h"
#include "sauvegarde.c"
#include "animations.h"

//CELA FONCTIONNE UNIQUEMENT POUR 2 JOUEURS...
void selection_lapin(Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int *lapin,int carte_piochee,char nom_joueur_1[], char nom_joueur_2[],int pioche[],int cases_rotatives[]){
  int saisie = 0;
  char buffer[128];
  *lapin = -1;
  while(*lapin == -1){
    printf("\n");
    moveto(34,19);printf("Quel lapin voulez-vous déplacer ? : ");
    fgets(buffer, 128, stdin);
    sscanf(buffer, "%d", &saisie);
    if((saisie<=NB_LAPINS && saisie>=1) || saisie == 9 ) //On vérifie si la saisie est un entier
    {                                                    //compris entre le nombre de lapins
      //LE JOUEUR VEUT QUITTER
      if (saisie==9)
      {
        ecriture_sauvegarde(J1,J2,plateau,nom_joueur_1,nom_joueur_2,tour_a_qui,pioche,cases_rotatives);
        moveto(20,21);printf("                                                                                            ");
        moveto(27,21);printf("Sauvegarde réussie... vous allez quitter la partie...");
        moveto(20,22);printf("                                                                                            ");
        *lapin = 9;
        return;
      }
      //LE JOUEUR SELECTIONNE UN LAPIN
      int lapins_sur_le_chemin = 0;
      switch(tour_a_qui){
        //JOUEUR 1
        case 0:
          //LE LAPIN NE DOIT PAS SORTIR DU PLATEAU ET ETRE VIVANT
          /*Un lapin saute la case sur laquelle figure déjà un autre lapin
          Il est donc nécessaire de rajouter ces cases sautées dans le déplacement
          pour ne pas que le lapin se retrouve hors du plateau*/
          for(int i=1;i<(NB_CASES-J1[saisie-1].position);i++)
          {
            if(plateau[J1[saisie-1].position+i]==JOUEUR_1 || plateau[J1[saisie-1].position+i]==JOUEUR_2)
            {
              lapins_sur_le_chemin += 1;
            }
          }
          /*Nous n'avons plus qu'à vérifier que son déplacement total est compris dans le plateau
          et que le lapin est vivant*/
          if(J1[saisie-1].position+carte_piochee+lapins_sur_le_chemin<=NB_CASES-1)
          {
            if(J1[saisie-1].etat == VIVANT)
            {                                                  //décalage par rapport tableau de struct
              *lapin = saisie-1;                              // J1[0] est le lapin 1
            }
            else
            {
              moveto(20,21);printf("                                                                                            ");
              moveto(31,21);printf("Ce lapin ne fait plus partie du plateau...");
              moveto(20,22);printf("                                                                                            ");
            }
          }
          else
          {
            moveto(20,21);printf("                                                                                            ");
            moveto(24,21);printf("Vous ne pouvez pas déplacer un lapin hors du plateau...");
            moveto(20,22);printf("                                                                                            ");
          }
        break;
        //JOUEUR 2 (même principe)
        case 1:
          for(int i=1;i<(NB_CASES-J2[saisie-1].position);i++)
          {
            if(plateau[J2[saisie-1].position+i]==JOUEUR_1 || plateau[J2[saisie-1].position+i]==JOUEUR_2)
            {
              lapins_sur_le_chemin += 1;
            }
          }
          if(J2[saisie-1].position+carte_piochee+lapins_sur_le_chemin<=NB_CASES-1)
          {
            if(J2[saisie-1].etat == VIVANT)
            {
              *lapin = saisie-1;
            }
            else
            {
              moveto(20,21);printf("                                                                                           ");
              moveto(31,21);printf("Ce lapin ne fait plus partie du plateau...");
              moveto(20,22);printf("                                                                                            ");
            }
          }
          else
          {
            moveto(20,21);printf("                                                                                            ");
            moveto(24,21);printf("Vous ne pouvez pas déplacer un lapin hors du plateau...");
            moveto(20,22);printf("                                                                                            ");
          }
        break;
      }
    }
    else //Le joueur n'a pas saisi un entier compris entre 1 et le nbr de lapins
    {
      moveto(20,21);printf("                                                                                            ");
      moveto(25,21);printf("Erreur de saisie : - Entrez un numero de lapin correct");
      moveto(20,22);printf("                                                                                            ");
      moveto(44,22);printf("- Entrez '9' pour sauvegarder et quitter la partie");
    }
  }
}

void tourner_carotte(Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[]){
  int alea_trou = 0;
	alea_trou = (rand()%2);
  //LA CASE 1 S'OUVRE
	if (alea_trou == 1){
    for(int i=0;i<NB_LAPINS;i++) // On regarde si il y avait un lapin sur la case
    {
      //J1
      if(cases_rotatives[0] == J1[i].position)
      {
        J1[i].etat = MORT;
        J1[i].position = OUT;
      }
      //J2
      if(cases_rotatives[0] == J2[i].position)
      {
        J2[i].etat = MORT;
        J2[i].position = OUT;
      }
    }
    //ON CHANGE L'AFFICHAGE
    plateau[cases_rotatives[0]]=-1;
	}
  //LA CASE 1 NE S'OUVRE PAS
  else
  {
    if(plateau[cases_rotatives[0]]!= JOUEUR_1 && plateau[cases_rotatives[0]]!= JOUEUR_2) //il ne faut pas effacer un lapin dans l'affichage
    {
        plateau[cases_rotatives[0]]=VIDE;
    }
  }
  //MÊME CHOSE POUR LA CASE 2
	alea_trou = (rand()%2);
	if (alea_trou == 1){
    for(int i=0;i<NB_LAPINS;i++)
    {
      if(cases_rotatives[1] == J1[i].position)
      {
        J1[i].etat = MORT;
        J1[i].position = OUT;
      }
      if(cases_rotatives[1] == J2[i].position)
      {
        J2[i].etat = MORT;
        J2[i].position = OUT;
      }
    }
    plateau[cases_rotatives[1]]=-1;
	}
  else
  {
    if(plateau[cases_rotatives[1]]!= JOUEUR_1 && plateau[cases_rotatives[1]]!= JOUEUR_2)
    {
        plateau[cases_rotatives[1]]=VIDE;
    }
  }
  //CASE 3
	alea_trou = (rand()%2);
	if (alea_trou == 1){
    for(int i=0;i<NB_LAPINS;i++) // On regarde si il y avait un lapin sur la case
    {
      if(cases_rotatives[2] == J1[i].position)
      {
        J1[i].etat = MORT;
        J1[i].position = OUT;
      }
      if(cases_rotatives[2] == J2[i].position)
      {
        J2[i].etat = MORT;
        J2[i].position = OUT;
      }
    }
    plateau[cases_rotatives[2]]=-1;
  }
  else
  {
    if(plateau[cases_rotatives[2]]!= JOUEUR_1 && plateau[cases_rotatives[2]]!= JOUEUR_2)
    {
        plateau[cases_rotatives[2]]=VIDE;
    }
  }
  //CONTOURNEMENT BEUG 1ERE CASE
  if(plateau[0]!= JOUEUR_1 && plateau[0]!= JOUEUR_2)
  {
    plateau[0]=VIDE;
  }
}

//J'ai mal lu la règle du jeu... (Florentin) --> Le lapin compte les cases occupées, il ne devrait pas...
/*void avancer (Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int lapin,int carte_piochee){
  printf("lapin = %d\n",lapin);
  //TOUR DU JOUEUR 1
  if(tour_a_qui == 0)
  {
    //CAS 1
    if(plateau[J1[lapin].position+carte_piochee] == VIDE || plateau[J1[lapin].position+carte_piochee] == CAROTTE){
      plateau[J1[lapin].position]=VIDE;   //On libère la case utilisée par le lapin
      J1[lapin].position += carte_piochee; // On actualise la position du lapin dans sa structure
      plateau[J1[lapin].position]=JOUEUR_1; // On utilise la position dans la structure du lapin pour actualiser le plateau
    }
    //CAS 2
    else if(plateau[J1[lapin].position+carte_piochee] == JOUEUR_1 || plateau[J1[lapin].position+carte_piochee] == JOUEUR_2){
      for(int i=1;i<10;i++){ //Si la case est occupée il faut regarder si celles d'après le sont aussi ou non
        if(plateau[J1[lapin].position+carte_piochee+i] == VIDE){
          plateau[J1[lapin].position]=VIDE; // on libère l'ancienne case
          J1[lapin].position += carte_piochee+i; //On déplace le lapin à la case d'après
          plateau[J1[lapin].position]=JOUEUR_1;
          i = 10; //Pour sortir de la boucle for
        }
        else if(plateau[J1[lapin].position+carte_piochee+i] == TROU){
          plateau[J1[lapin].position]=VIDE;
          J1[lapin].etat = MORT;
          J1[lapin].position = OUT;
          i = 10;
        }
      }
    }
    //CAS 3
    else if(plateau[J1[lapin].position+carte_piochee] == TROU){ //CAS 3
      plateau[J1[lapin].position]=VIDE;
      J1[lapin].position += OUT; //On sort le lapin du plateau
      J1[lapin].etat = MORT;
    }
  }
  // TOUR DU JOUEUR 2
  else {
    //CAS 1
    if(plateau[J2[lapin].position+carte_piochee] == VIDE){
      plateau[J2[lapin].position]=VIDE;   //On libère la case utilisée par le lapin
      J2[lapin].position += carte_piochee; // On actualise la position du lapin dans sa structure
      plateau[J2[lapin].position]=JOUEUR_2; // On utilise la position dans la structure du lapin pour actualiser le plateau
    }
    //CAS 2
    else if(plateau[J2[lapin].position+carte_piochee] == JOUEUR_1 || plateau[J2[lapin].position+carte_piochee] == JOUEUR_2){
      for(int i=1;i<10;i++){ //Si la case est occupée il faut regarder si celles d'après le sont aussi ou non
        if(plateau[J2[lapin].position+carte_piochee+i] == VIDE){
          plateau[J2[lapin].position]=VIDE;
          J2[lapin].position += carte_piochee+i; //On déplace le lapin à la case d'après
          plateau[J2[lapin].position]=JOUEUR_2;
          i = 10; //On sort de la boucle for
        }
        else if(plateau[J2[lapin].position+carte_piochee+i] == TROU){
          plateau[J2[lapin].position]=VIDE;
          J2[lapin].etat = MORT;
          J2[lapin].position = OUT; //On déplace le lapin à la case d'après
          i = 10;
        }
      }
    }
    //CAS 3
    else if(plateau[J2[lapin].position+carte_piochee] == TROU){
      plateau[J2[lapin].position]=VIDE;
      J2[lapin].position += OUT;
      J2[lapin].etat = MORT;
    }
  }
}*/

void avancer (Lapin J1[],Lapin J2[],int plateau[],int tour_a_qui,int lapin,int *carte_piochee){
  if(tour_a_qui == 0)//TOUR DU JOUEUR 1
  {
    plateau[J1[lapin].position]=VIDE; // La position anterieure du lapin n'est plus affichée
    int i=1 ;
    //ON MODIFIE LA POSITION DU LAPIN PEU IMPORTE LA CASE SUR LAQUELLE IL ATTÉRIRA
    while (*carte_piochee!=0) // Tant que le chiffre de la carte piochée n'est pas atteint on continue
    {
      //CAS 1
      if (plateau[J1[lapin].position+i] == VIDE || plateau[J1[lapin].position+i] == CAROTTE) // Si le lapin passe par une case Vide ou si il arrive a la dernière case
      {
        J1[lapin].position +=1; // Le lapin avance
        //ANIMATION
        animation_lapins(J1,J2,plateau,tour_a_qui,lapin,&carte_piochee);
        *carte_piochee-=1;  // Et le chiffre de la carte picohée diminue
      }
      //CAS 2
      else if (plateau[J1[lapin].position+i] == TROU)
      {
        J1[lapin].position +=1;
        *carte_piochee-=1;
      }
      //CAS 3
      else if (plateau[J1[lapin].position+i] == JOUEUR_1 || plateau[J1[lapin].position+i] == JOUEUR_2)
      {
        J1[lapin].position ++;
      }
    }
    //EN FONCTION DE LA VALEUR DE LA CASE, ON MODIFIE LA STRUCTURE DU LAPIN
    if (plateau[J1[lapin].position]==TROU)
    {
      J1[lapin].etat = MORT;
      J1[lapin].position = OUT;
    }
    plateau[J1[lapin].position]=JOUEUR_1; // On actualise la position du lapin sur le plateau
  }
  //TOUR DU JOUEUR 2 (MÊME PRINCIPE)
  else
  {
    plateau[J2[lapin].position]=VIDE;
    int i=1 ;
    while (*carte_piochee!=0)
    {
      //CAS 1
      if (plateau[J2[lapin].position+i] == VIDE || plateau[J2[lapin].position+i] == CAROTTE)
      {
        J2[lapin].position +=1;
        //ANIMATION
        animation_lapins(J1,J2,plateau,tour_a_qui,lapin,&carte_piochee);
        *carte_piochee-=1; // Et le chiffre de la carte picohée diminue
      }
      //CAS 2
      else if (plateau[J2[lapin].position+i] == TROU)
      {
        J2[lapin].position +=1;
        *carte_piochee-=1;
      }
      //CAS 3
      else if (plateau[J2[lapin].position+i] == JOUEUR_1 || plateau[J2[lapin].position+i] == JOUEUR_2)
      {
        J2[lapin].position ++;
      }
    }
    if (plateau[J2[lapin].position]==TROU)
    {
      J2[lapin].etat=MORT;
      J2[lapin].position = OUT;
    }
    plateau[J2[lapin].position]=JOUEUR_2;

  }
}

void action_carte(Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[],int carte_piochee,int tour_a_qui,int lapin,char nom_joueur_1[], char nom_joueur_2[],bool *win,int pioche[]){
  if(carte_piochee == CARTE_CAROTTE){
    tourner_carotte(J1,J2,plateau,cases_rotatives);
    getchar();
    //usleep(TEMPS_CAROTTE); //L'utilisateur a le temps de voir l'effet de la carte
  }
  else{
    selection_lapin(J1,J2,plateau,tour_a_qui,&lapin,carte_piochee,nom_joueur_2,nom_joueur_1,pioche,cases_rotatives);
    if(lapin==9){
      *win=true; //pour quitter la boucle dans lancer_partie
      return; //quitte la fonction en cours
    }
    avancer(J1,J2,plateau,tour_a_qui,lapin,&carte_piochee);
  }
}

void check_win(Lapin J1[],Lapin J2[],int plateau[],bool *win,char nom_joueur_1[],char nom_joueur_2[]){
  int lapins_morts_J1 = 0;
  int lapins_morts_J2 = 0;
  //JOUEUR SUR LA CASE CAROTTE
  if(plateau[NB_CASES-1]==JOUEUR_1){ //La plateau[0] est la case 1
    system("clear");
    moveto(33,8);printf("\E[1;31m");printf("********** FIN DE LA PARTIE **********");printf("\E[0m");
    afficher_plateau(plateau);
    moveto(45,19);printf("\E[1;36m");printf("%s",nom_joueur_1);printf("\E[0m");printf(" A GAGNÉ !");
    *win = true;
  }
  else if(plateau[NB_CASES-1]==JOUEUR_2){
    system("clear");
    moveto(33,8);printf("\E[1;31m");printf("********** FIN DE LA PARTIE **********");printf("\E[0m");
    afficher_plateau(plateau);
    moveto(45,19);printf("\E[1;33m");printf("%s",nom_joueur_2);printf("\E[0m");printf(" A GAGNÉ !");
    *win = true;
  }
  //PLUS DE LAPINS DISPOS
  for(int i=0;i<NB_LAPINS;i++){
    if(J1[i].etat == MORT){
      lapins_morts_J1 += 1;
    }
    if(J2[i].etat == MORT){
      lapins_morts_J2 += 1;
    }
  }
  if(lapins_morts_J1 == NB_LAPINS){
    system("clear");
    afficher_plateau(plateau);
    moveto(20,8);printf("FIN DE LA PARTIE, ");printf("\E[1;36m");printf("%s ",nom_joueur_1);printf("\E[0m");printf("N'A PLUS DE LAPINS EN VIE, ");printf("\E[1;33m");printf("%s ",nom_joueur_2);printf("\E[0m");printf("A GAGNÉ !");
    *win = true;
  }
  if(lapins_morts_J2 == NB_LAPINS){
    system("clear");
    afficher_plateau(plateau);
    moveto(20,8);printf("FIN DE LA PARTIE, ");printf("\E[1;36m");printf("%s ",nom_joueur_2);printf("\E[0m");printf("N'A PLUS DE LAPINS EN VIE, ");printf("\E[1;33m");printf("%s ",nom_joueur_1);printf("\E[0m");printf("A GAGNÉ !");
    *win = true;
  }
}

void lancer_partie (Lapin J1[],Lapin J2[],int plateau[],int cases_rotatives[],int carte_piochee,int tour_a_qui,int lapin,char nom_joueur_1[], char nom_joueur_2[],bool *win,int pioche[]){
/*************** DEBUT DE LA PARTIE ***************/
  *win=false;
  while(!*win)
  {
    system("clear");
    afficher_nom(nom_joueur_1,nom_joueur_2,tour_a_qui);
    afficher_plateau(plateau);
    piocher(pioche,&carte_piochee);
    afficher_infos_joueurs(J1,J2,nom_joueur_1,nom_joueur_2);
    action_carte(J1,J2,plateau,cases_rotatives,carte_piochee,tour_a_qui,lapin,nom_joueur_1,nom_joueur_2,win,pioche);
    tour_a_qui = (tour_a_qui+1)%NB_JOUEURS;
    check_win(J1,J2,plateau,win,nom_joueur_1,nom_joueur_2);
  }
/***************FIN DE LA PARTIE***************/
  afficher_infos_joueurs(J1,J2,nom_joueur_1,nom_joueur_2);
  moveto(32,23);printf("Appuyez sur entrer pour retourner au menu");getchar();
}

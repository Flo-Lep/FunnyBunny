
//Sauvegarde
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Pour initialiser rand
#include "config.h"
#include "sauvegarde.h"

void ecriture_sauvegarde(Lapin J1[],Lapin J2[],int plateau[],char nom_joueur_1[], char nom_joueur_2[],int tour_a_qui,int pioche[],int cases_rotatives[]){
	FILE *sauvegarde =fopen("sauvegarde_J1_J2.txt","w");
	if (sauvegarde == NULL)
	{
		printf("\n\n");
		printf("Echec de l'écriture du fichier...\n");
		printf("\n\n");
		exit(1);
	}
	//NOMS DES JOUEURS
	fprintf(sauvegarde,"%s  %s\n",nom_joueur_2,nom_joueur_1);
	//TOUR DU JOUEUR
	fprintf(sauvegarde, "%d\n",tour_a_qui);
	//INFOS LAPINS JOUEURS
	for(int i=0;i<NB_LAPINS;i++){
		fprintf(sauvegarde,"%d  %d\n",J1[i].position,J1[i].etat);
	}
	for(int i=0;i<NB_LAPINS;i++){
		fprintf(sauvegarde,"%d  %d\n",J2[i].position,J2[i].etat);
	}
	//PIOCHE
	for(int i=0 ;i<NB_CARTES_TOTAL ; i++)
    {
      fprintf(sauvegarde,"%d ",pioche[i]);
    }
	//CASES ROTATIVES
	for(int i=0;i<NB_CASES_ROTATIVES;i++){
		fprintf(sauvegarde,"%d ",cases_rotatives[i]);
	}
	//ETAT CASES ROTATIVES
	int var_aux = 0;
	for(int i=0;i<NB_CASES_ROTATIVES;i++){
		var_aux = cases_rotatives[i];   //On passe par une var aux pas réussi sans...
		if(plateau[var_aux-1]==-1){    //Voir jeu.c pour le -1
			fprintf(sauvegarde,"-1 "); //=TROU
		}
		else{
			fprintf(sauvegarde,"0 "); //=VIDE
		}
	}
	fclose(sauvegarde);
}

void lecture_sauvegarde(Lapin J1[],Lapin J2[],int plateau[],char nom_joueur_1[], char nom_joueur_2[],int *tour_a_qui,int pioche[],int cases_rotatives[]){
	FILE *sauvegarde =fopen("sauvegarde_J1_J2.txt","r");
	if (sauvegarde == NULL){
		moveto(15,23);printf("Echec de l'ouverture du fichier de sauvegarde, le fichier n'existe pas...");
		moveto(9,25);printf("Pour sauvegarder une partie en cours, entrez '9' lors de la sélection de votre lapin\n\n");
		exit(1);
	}
	fscanf(sauvegarde,"%s %s\n",nom_joueur_1,nom_joueur_2);
	int var_aux = -1; //Passage par pointeur ds fscanf ne fonctionne pas ? On passe par une var auxiliaire
	fscanf(sauvegarde,"%d\n",&var_aux);
	*tour_a_qui=var_aux;
	//JOUEUR 1
	for(int i=0;i<NB_LAPINS;i++){
		fscanf(sauvegarde,"%d %d\n",&J1[i].position,&J1[i].etat);
	}
	//JOUEUR 2
	for(int i=0;i<NB_LAPINS;i++){
		fscanf(sauvegarde,"%d %d\n",&J2[i].position,&J2[i].etat);
	}
	//PIOCHE
	for(int i=0;i<NB_CARTES_TOTAL;i++){
		fscanf(sauvegarde,"%d\n",&pioche[i]);
	}
	//CASES ROTATIVES
	for(int i=0;i<NB_CASES_ROTATIVES;i++){
		fscanf(sauvegarde,"%d\n",&cases_rotatives[i]);
	}
	//MISE A JOUR PLATEAU
	for(int i=0;i<NB_LAPINS;i++)
	{
		plateau[J1[i].position] = JOUEUR_1;
		plateau[J2[i].position] = JOUEUR_2;
	}
	int var_aux2 = 0;
	for(int i=0;i<NB_CASES_ROTATIVES;i++){
		var_aux2 = cases_rotatives[i];
		fscanf(sauvegarde,"%d\n",&plateau[var_aux2-1]);
	}
	fclose(sauvegarde);
	getchar();
}

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#define moveto(x,y) printf("\033[%d;%dH",y,x)



void lapin_emoji()
{
	system("clear");
  //printf("\E[31m");printf("Agrandissez la taille de votre terminal avec une taille assez importante, \n\nDans la page qui va suivre vous allez pouvoir la régler aux bonnes dimensions\n\n");
  //printf("Vous aurez besoin d'aligner les contours du terminal avec les flèches indiquées sur l'écran \nAfin de profiter pleinement du jeu");printf("\E[0m"); getchar();system("clear");

  moveto(1,4);printf("<---");moveto(97,4);printf("--->");
  printf("\E[1m");
	moveto(47,5);printf("_");
	moveto(46,6);printf("/ \\");
	moveto(45,7);printf("/ _ \\");
  moveto(44,8);printf("| / \\ |");
  moveto(44,9);printf("||   || _______");
  moveto(44,10);printf("||   || |\\     \\");
  moveto(44,11);printf("||   || ||\\     \\");
  moveto(44,12);printf("||   || || \\    |");
  moveto(44,13);printf("||   || ||  \\__/");
  moveto(44,14);printf("||   || ||   ||\n");
  moveto(45,15);printf("\\\\_/ \\_/ \\_//\n");
  moveto(45,16);printf("/   _     _   \\\n");
  moveto(44,17);printf("/               \\\n");
  moveto(44,18);printf("|");printf("\E[1;5;31m");printf("    O     O    ");printf("\E[0m");printf("\E[1m");printf("|");
  moveto(44,19);printf("|   \\  ___  /   |");
  moveto(43,20);printf("/     \\ \\_/ /     \\");
  moveto(42,21);printf("/  -----  |  --\\    \\");
  moveto(42,22);printf("|     \\__/|\\__/ \\   |");
  moveto(42,23);printf("\\       |_|_|       /");
  moveto(43,24);printf("\\_____       _____/");
  moveto(49,25);printf("\\     /");
  moveto(49,26);printf("|     |");printf("\E[0m");
  moveto(1,28);printf("<---");moveto(97,28);printf("--->");


  moveto(33,27);printf("Appuyez sur entrer pour accéder au menu");getchar();
}

void menu()
{
  system("clear");
	printf("\E[1;5;31;42m");moveto(31,3); printf(" BIENVENUE DANS LE JEU DU CROQUE-CAROTTE ! ");printf("\E[0m");
	printf("\E[1;36m");moveto(43,7); printf("Jouer au Jeu : '1'");
  moveto(38,10);printf("Reprendre votre partie : '2'");
	moveto(44,13);printf("Règles du Jeu : '3'");
	moveto(42,16);printf("Quitter le Jeu : '4'");printf("\E[0m");
	printf("\E[1;35m");moveto(38,20);printf("Que souhaitez-vous faire ? :");printf("\E[0m");
}

void nom_joueur(char nom_joueur_1[], char nom_joueur_2[])
{
  system("clear");
  moveto(27,3);printf("\E[1;31m");printf("Choisissez vos prénoms ou surnoms pour la partie !");printf("\E[0m");

  moveto(33,5);printf("Choisissez le nom du premier Joueur : ");scanf("%s",nom_joueur_1);
  for (int i=0; i<strlen(nom_joueur_1); i++)
  {
       nom_joueur_1[i]=toupper(nom_joueur_1[i]);
  }
  moveto(33,6);printf("\E[1;36m");printf("%s",nom_joueur_1);printf("\E[0m");printf(", tu auras cette couleur de pion : "); printf("\E[1;36m");printf("L1.");printf("\E[0m");

  moveto(33,8);printf("Choisissez le nom du second Joueur : ");scanf("%s",nom_joueur_2);//printf("J3");scanf("%s",nom_joueur_3);
  for (int i=0; i<strlen(nom_joueur_2); i++)
  {
     nom_joueur_2[i]=toupper(nom_joueur_2[i]);
  }
  moveto(33,9);printf("\E[1;33m");printf("%s",nom_joueur_2);printf("\E[0m");printf(", tu auras cette couleur de pion : "); printf("\E[1;33m");printf("L2.");printf("\E[0m");

  moveto(28,12);printf("\E[1;31m");printf("Petite précision avant le début de la partie ...");printf("\E[0m");
  moveto(12,14);printf("Si vous avez envie de quitter le jeu sans perdre votre avancée. Pas de panique !");
  moveto(13,15);printf("Il vous suffit d'entrer ");printf("\E[4;35m");printf("'9'");printf("\E[0m");printf(" et votre partie sera automatiquement enregistrée." );

  moveto(30,19);printf("Bonne chance");printf("\E[1;36m");printf(" %s ",nom_joueur_1);printf("\E[0m");printf("et");printf("\E[1;33m");printf(" %s",nom_joueur_2);printf("\E[0m");
  moveto(69,18);printf("\E[1;35m");printf("(\\ _ /)");printf("\E[0m");
  moveto(69,19);printf("\E[1;35m");printf("(='.'=)");;printf("\E[0m");
  moveto(69,20);printf("\E[1;35m");printf("(')-(')");printf("\E[0m");

  moveto(34,23);printf("Appuyez sur entrer pour accéder au Jeu");getchar();getchar();
}




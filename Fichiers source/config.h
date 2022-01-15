//Configuration du Jeu
#ifndef CONFIG_H_
#define CONFIG_H_
/*----------------------------------------------------*/

/*Affichage du menu*/
#define moveto(x,y) printf("\033[%d;%dH",y,x);

/*Nombre de joueurs de la partie*/
#define NB_JOUEURS  (2)

/*Nombre de lapins par joueur*/
#define NB_LAPINS  (4)

/*Nombre de cases du plateau de jeu*/
#define NB_CASES  (25)

/*Nombre de cases pouvant s'ouvrir aléatoirement*/
#define NB_CASES_ROTATIVES  (3)

/*Nombres de cartes dans la pioche*/
#define NB_CARTES_TOTAL (24)
#define NB_CARTES_AVANCER_1 (12)
#define NB_CARTES_AVANCER_2 (4)
#define NB_CARTES_AVANCER_3 (2)
#define NB_CARTES_CAROTTE  (6)

/*Temps en microsecondes de l'animation des lapins*/
#define TEMPS_ANIMATIONS (500000) //5 les "désactive"

/*Temps en microsecondes avant l'effet de la carte carotte*/
//#define TEMPS_CAROTTE (2200000)


/*
Toutes les fonctionnalités ne sont pas modifiables et conduiront
à des erreurs, il est nécéssaire de repenser en grande partie
le code pour que cela fonctionne...
*/

/*----------------------------------------------------*/
#endif

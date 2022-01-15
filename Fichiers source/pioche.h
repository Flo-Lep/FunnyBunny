#ifndef PIOCHE_H_
#define PIOCHE_H_
/*----------------------------------------------------*/
void init_pioche(int pioche[]); //initialise toutes les cases de la pioche à -1
void melanger_pioche(int pioche[]);//Attribue une carte à chaque case de la pioche
void piocher(int pioche[],int *carte_piochee);

/*----------------------------------------------------*/
#endif

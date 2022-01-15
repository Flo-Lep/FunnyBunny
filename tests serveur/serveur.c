
/************ MAIN ************/

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
#include "tests_serveur.c"

typedef struct Menu
{
	int choix_menu;
}Menu;

typedef struct Joueur
{
    char nom_joueur_2[20];   
}Joueur;
typedef struct Lapin
{
    int numero_lapin;   
}Lapin;


//typedef struct User
//{
//	char nom[30];
//	int age;
//}User;




/*void *function(void *arg)
{
	int socket = *(int*)arg;

	char question_menu[] = "Votre choix pour le menu ?";

	Menu menu;
	send(socket, question_menu, strlen(question_menu)+1 ,0);
	recv(socket, &menu , sizeof(menu), 0);
	printf("%d\n",menu.choix_menu);

	close(socket);
	free(arg);
	pthread_exit(NULL);
}
void *function1(void *arg)
{
	int socket = *(int*)arg;

	char question_prenom[] = "Entrez votre nom ou surnom : ";

	Joueur joueur;
	send(socket, question_prenom, strlen(question_prenom)+1 ,0);
	recv(socket, &joueur , sizeof(joueur), 0);
	printf("Votre adversaire s'appelle %s\n",joueur.nom_joueur_2);

	close(socket);
	free(arg);
	pthread_exit(NULL);
}*/
void *function2(void *arg)
{
	int socket = *(int*)arg;

	char question_lapin[] = "Quel lapin voulez-vous deplacer : ";

	Lapin lapin;
	send(socket, question_lapin, strlen(question_lapin)+1 ,0);
	recv(socket, &lapin , sizeof(Lapin), 0);
	printf("vous avez choisi le lapin %d\n",lapin.numero_lapin);

	close(socket);
	free(arg);
	pthread_exit(NULL);
}


/*
	Joueur joueur;
	send(socket, questionJ2, strlen(questionJ2)+1 , 0);
	recv(socket, &joueur , sizeof(joueur), 0);
	printf("Votre adversaire s'appelle %d \n", joueur.prenom);	

	User user;
	char msg[] = "......" ;
	send(socket, msg, strlen(msg)+1 , 0);
	recv(socket, &user , sizeof(user), 0);
	printf("Le joueur s'appelle %s et a %d ans\n", user.nom,user.age);

	send(socket, msg1, strlen(msg1)+1 , 0);
	recv(socket, &nombre , sizeof(nombre), 0);
	printf("numero : %d\n", nombre);
*/
	//send(socket,&user,sizeof(user), 0);

	//close(socket);

int main(void)
{	
	/********VARIABLES*******/
	int choix_menu1 = 0;
	char nom_joueur_1,nom_joueur_2;

	pthread_t clientThread;

	int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port =htons(30000);

	bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind : %d\n",socketServer);

	listen(socketServer, 5);
	printf("listen ...\n");


	struct sockaddr_in addrClient;
	socklen_t csize = sizeof(addrClient);
	int socketClient = accept(socketServer,(struct sockaddr *)&addrClient,&csize);
	printf("accept\n");
	//printf("client : %d\n",socketClient);

	lapin_emoji();
	menu(&choix_menu1);
	scanf("%d\n",&choix_menu1);
	//printf("%d\n",choix_menu1);
	

	int *arg = malloc(sizeof(int));
	*arg =socketClient;
	pthread_create(&clientThread,NULL,function2,arg);
	pthread_join(clientThread,NULL);

	//nom_joueur(&nom_joueur_1,&nom_joueur_2);


	
	

	close(socketServer);
	printf("close\n");
	
	return 0;

}



	/*pthread_t threads[3];
	int *arg = malloc(sizeof(int));
	*arg = socketClient;
	pthread_t *clientThread = malloc(sizeof(pthread));
	pthread_create(&clientThread,NULL,function,arg);*/

	//int *arg = malloc(sizeof(int));
	//*arg = socketClient;
	//pthread_create(&threads, NULL, function, arg);

	/*for(int i=0 ; i<=2 ; i++)
	{
		struct sockaddr_in addrClient;
		socklen_t csize = sizeof(addrClient);
		int socketClient = accept(socketServer,(struct sockaddr *)&addrClient,&csize);
		printf("accept\n");

		printf("client : %d\n",socketClient);

		int *arg = malloc(sizeof(int));
		*arg = socketClient;
		pthread_create(&threads[i], NULL, function, arg);

	}


		User user = {
				.nom = "Théo",
				.age = 18
			};



	for(int i=0 ; i<=1 ; i++)
	{
		pthread_join(threads[i],NULL);
	}*/

	
	//User user;
	


/*TEMPLATE = app
QT += widgets network
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += FenServeur.h
SOURCES += FenServeur.cpp main.cpp

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QApplication>
#include "FenServeur.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	FenServeur fenetre;
	fenetre.show();

	return app.exec();
}*/

/* FONCTION POUR DEMANDER L'AGE ET LE PRENOM

typedef struct User
{
	char nom[30];
	int age;
}User;

typedef struct Menu
{
	int choix_menu;
}Menu;


void *function(void *arg)
{
	int socket = *(int*)arg;


	char msg[] = "Quel est votre nom et votre age ?";
	char msg1[] = "choisissez un numero :";
	int nombre;

	char question[] = "Votre choix menu ?";

	Menu menu;
	send(socket, question, strlen(question)+1 , 0);
	recv(socket, &menu , sizeof(menu), 0);
	printf("%d\n",menu.choix_menu);




	User user;
	send(socket, msg, strlen(msg)+1 , 0);
	send(socket, msg1, strlen(msg1)+1 , 0);

	recv(socket, &user , sizeof(user), 0);
	printf("Le joueur s'appelle %s et a %d ans\n", user.nom,user.age);
	recv(socket, &nombre , sizeof(nombre), 0);
	
	printf("numero : %d\n", nombre);
	
	//send(socket,&user,sizeof(user), 0);

	//close(socket);
	free(arg);
	pthread_exit(NULL);
}*/

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
#include "tests_client.c"


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


int main(void)
{

    /********VARIABLES*******/

    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrClient;

    addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrClient.sin_family = AF_INET;
    addrClient.sin_port =htons(30000);

    connect(socketClient,(const struct sockaddr *)&addrClient, sizeof(addrClient));
    printf("connecté \n"); // Connecté au serveur 

    //lapin_emoji();
    //menu();

    Lapin lapin;
    char question_lapin[60];
    recv(socketClient,question_lapin,60,0);
    scanf("%d \n",&lapin.numero_lapin);
    send(socketClient,&lapin,sizeof(Lapin),0);

    /*Menu menu;

    char question_menu[50];
    recv(socketClient, question_menu , 50 ,0);
    //printf("%s\n",question_menu);
    scanf("%d\n",&menu.choix_menu);
    send(socketClient, &menu , sizeof(Menu) ,0);
    
   

    Joueur joueur;

    char question_prenom[40];
    recv(socketClient, question_prenom , 50 ,0);
    printf("%s\n",question_prenom);
    scanf("%s\n",joueur.nom_joueur_2);
    send(socketClient, &joueur , sizeof(joueur) ,0);*/


    close(socketClient);
    return 0;


}   


/*

    Joueur joueur; 
    char questionJ2[20];
    recv(socketClient, questionJ2 , 20 ,0);
    printf("%s\n",questionJ2);
    scanf("%s\n ",&joueur.prenomJ2);
    send(socketClient, &joueur , sizeof(joueur) ,0);

    typedef struct User
    {
        char nom[30];
        int age;
    }User;

    User user;
    char msg[40];
    char msg1[50];
    int nombre;

    recv(socketClient, msg , 40 ,0);
    recv(socketClient, msg1 , 50 ,0);

    printf("%s\n",msg);
    scanf("%s %d",user.nom, &user.age);

    send(socketClient, &user , sizeof(User) ,0);
    printf("%s\n",msg1);
    scanf("%d",&nombre);*/

    //printf("nom : %s age : %d \n",user.nom, user.age);

    
    //send(socketClient, &nombre , sizeof(nombre) ,0);
    




//recv(socketClient, &user , sizeof(User) ,0);

/*FenServeur::FenServeur()
{
    // Création et disposition des widgets de la fenêtre
    etatServeur = new QLabel;
    boutonQuitter = new QPushButton(tr("Quitter"));
    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(etatServeur);
    layout->addWidget(boutonQuitter);
    setLayout(layout);

    setWindowTitle(tr("ZeroChat - Serveur"));

    // Gestion du serveur
    serveur = new QTcpServer(this);
    if (!serveur->listen(QHostAddress::Any, 50885)) // Démarrage du serveur sur toutes les IP disponibles et sur le port 50585
    {
        // Si le serveur n'a pas été démarré correctement
        etatServeur->setText(tr("Le serveur n'a pas pu être démarré. Raison :<br />") + serveur->errorString());
    }
    else
    {
        // Si le serveur a été démarré correctement
        etatServeur->setText(tr("Le serveur a été démarré sur le port <strong>") + QString::number(serveur->serverPort()) + tr("</strong>.<br />Des clients peuvent maintenant se connecter."));
        connect(serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion()));
    }

    tailleMessage = 0;
}*/
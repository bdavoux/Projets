#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>




#define VEHICULE 100
#define TAILLE_NOM_F 100
#define NON_TROUVE -1
#define MAX_FIDELITE 10 
#define MAX_LOCATIONS 100


// Déclaration du type global



struct client
{
  int num_client; 
  char num_permis[100];
  char date_de_naissance[11]; 
  int annee_permis;
  char nom[100];
  char prenom[100];
  char adresse[100];
  char mail[100];
  char telephone[100];
  int nblocation;

};

struct vehicules
{
  int num_vehicule;
  char type[100];
  char marque[VEHICULE];
  char modele[VEHICULE];
  int annee;
  char immatriculation[VEHICULE];
  int kilometrage;
  char carburant[VEHICULE];
  char statut[VEHICULE];
  char Etat[VEHICULE];
  int prix;
  int surtaxe_jeunepermis; 
  int caution;
  char loue [10]; 




};

struct location
{
  int numero_loc;
  char marque[100];
  char modele[100];
  char date_debut[11];
  char date_fin[11];
  char nom_assurance[100];
  float assurance;
  float option;
  int prix;
  int total;
  int caution;	
  char nom[100];
  char prenom[100];
  char immatriculation[VEHICULE];
  char statut[100];//En cours, terminé
  int num_client;
  int num_vehicule; 



};

struct historique_vehicule
{
int num_vehicule;
char type[100];
char marque[VEHICULE];
char modele[VEHICULE];
int annee;
char immatriculation[VEHICULE];
int kilometrage;
char date_suppressions[10];
};

struct historique_client
{
int num_client;
char nom[100];
char prenom[100];
char adresse[100];
char mail[100];
char telephone[100];
char num_permis[100];
char date_de_naissance[11];
int annee_permis;
int nblocation;
char date_suppressions[10];


};


struct Assurance {
    char nom[100];
    float prix;
};

struct Option {
    char nom[100];
    float prix;
};

struct Fidelite 
{
    int seuilLocations;  // Nombre de locations nécessaires pour obtenir la réduction
    float reduction;     // Pourcentage de réduction
};

struct facture
{
int num_facture;
int numero_loc;
float option;
int prixj;
int total;
int caution;
float assurance;
char marque[100];
char modele[100];
char prenom[100];
char nom[100];
char date_debut[100];
char date_fin[100];
char date_facture[11];
};

struct historique_client historique_client[100];
struct historique_vehicule historique_vehicule[100];
struct facture tabfacture[100];
struct client tabclient[100];
struct vehicules tabvehicule[100];
struct location tabloc[MAX_LOCATIONS];
struct Assurance tabassurances[100];
struct Option taboptions[100];
struct Fidelite niveauxFidelite[MAX_FIDELITE];


int verif_fide=0;
int nbvehicule=0;
int nbreclient = 0;
int nblocation = 0;
int nboptions = 0;
int nbassurances = 0;
int a_sauvegarder=0;
int a_sauvegarderv=0;
int a_sauvegarder_option = 0;
int a_sauvegarder_assurance = 0;
int a_sauvegarderl =0;
int a_sauvegarderf =0;
int a_sauvegarderhc =0;
int a_sauvegarderhv =0;
int nbNiveaux=0;
int nbfacture=0;
int nbhistoriquev=0;
int nbhistoriquec=0;

// Déclarations préliminaires
void verif_sauvegarde_location();
void sauvegarde_location();
void chargement_location();
char* format_date(int j, int m, int a);
int DateValide(int jour, int mois, int annee);
int DateValideLocation(int j, int m, int a);
bool estBissextile(int annee);
void appliquerFidelite(struct location *loue, struct client individu);
void conv_maj(char ch[]);
void conv_immatriculation(char ch[]) ;
int recherche_numvehicule(int numero);
int recherche_numloc(int numero);
int recherche_vehicule(char nomrech[100]);
int recherche_mailclient(char nomrech[100]);
int recherche_client(char nomrech[100]);
int recherche_numclient(int numero);
int recherche_numpermisclient(char nomrech[100]);
void saisie_client ();
void saisie_vehicule();
void affichage_vehicule();
void affichage_client();
void chargement_vehicules();
void chargement_client();
void chargement_fidelite();
void chargement_facture();
void quitter();
void verif_sauvegarde_client();
void verif_sauvegarde_vehicule();
void sauvegarder_vehicules();
void sauvegarde_client();
void modification_vehicule();
void modification_client();
void suppression_vehicule();
void suppression_client();
void clear_input_buffer();
void saisie_location();
void viderBuffer();
void chargement_assurance();
void chargement_option();
void verif_sauvegarde_assurance();
void verif_sauvegarde_option();
void sauvegarde_assurance();
void sauvegarde_option();
void affichage_option();
void affichage_assurance();
void ajouter_assurance();
void ajouter_option();
float saisie_option();
float saisie_assurance();
void affichage_vehicule_dispo();
void affichage_vehicule_indispo();
void affichage_vehicule_dispo_date(char d[], char d_r[]);
int VehiculeDispo(char d[], char d_r[], int i);
void retour_vehicule();
void initialiserFidelite();
void afficher_date();
void affichage_typevehicule() ;
void crefacture(struct location loc);
void historique_affichage_facture();
void generer_facture();
int recherche_numloc(int numero);
void infosclient();
void affichage_historiquev();
void convertir_historiquev(struct vehicules vehicule);
void convertir_historiquec(struct client client);
void affichage_historiquec();
time_t convertirDateEnTime_t(char *date);
int differenceJours(char *date_debut, char *date_fin);
void afficher_location();
void supprimer_espaces_adresse(char *adresse);
int numeroDejaExistantV(int num);
int numeroDejaExistantC(int num);
int recherche_numsuppression(int numero);
void reintegre_cleint();
void compte_30jours();
int estDansLesDerniers30Jours(char *date);
time_t convertirDateEnTime_tsuppr(char *date);
int verifierMDP(char *utilisateur, char *mdp);
void connexion();
void sauvegarder_fidelite();
void verif_sauvegarde_facture();
void sauvegarder_facture();
void chargement_facture();
void verif_sauvegarde_fidelite();
void verif_sauvegarde_histoc();
void verif_sauvegarde_histov();

//void devis_location();

int main() {

    printf("Chargement des données veuillez patienter...\n");
    chargement_vehicules();
    chargement_client();
    chargement_assurance();
    chargement_option();
    chargement_fidelite();
    chargement_location();
    chargement_facture();
    printf("Chargement terminé.\n");
    connexion();

    int choix = -1;

    while (choix != 0) {
        printf("\033[1;36m");
        printf("+-----------------------------------------+\n");
        printf("|           Bienvenue chez PISE           |\n");
        printf("|      Enfin une location au juste prix   |\n");
        printf("\033[0m");
        printf("\033[1;35m");
        printf("+-----------------------------------------+\n");
        printf("| -1-  Gérer les clients                  |\n");
        printf("| -2-  Gérer les véhicules                |\n");
        printf("| -3-  Gestion des locations              |\n");
        printf("| -4-  Gestion des options et assurances  |\n");
        printf("| -5-  Gestion financière                 |\n");
        printf("|                                         |\n");
        printf("| -0-  Quitter                            |\n");
        printf("+-----------------------------------------+\n");
        printf("\033[0m");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Menu de gestion client et fidélité
                {
                    int choixGestionClient = -1;
                    while (choixGestionClient != 0) {
                        printf("\033[1;36m");
                        printf("+----------------------------------------------------+\n");
                        printf("|      Menu de gestion client et fidélité            |\n");
                        printf("| -1-  Programme fidélité                            |\n");
                        printf("| -2-  Afficher les clients                          |\n");
                        printf("| -3-  Saisir un client                              |\n");
                        printf("| -4-  Supprimer un client                           |\n");
                        printf("| -5-  Modifier un client                            |\n");
                        printf("| -6-  Rechercher un client                          |\n");
                        printf("| -7-  Afficher l'historique des supressions clients |\n");
                        printf("| -8-  Reintégrer un client                          |\n");
                        printf("|                                                    |\n");
                        printf("| -0-  Retour au menu principal                      |\n");
                        printf("+----------------------------------------------------+\n");
                        printf("\033[0m");
                        printf("Choix : ");
                        scanf("%d", &choixGestionClient);

                        switch (choixGestionClient) {
                            case 1:
                                // Code pour le programme de fidélité
                                initialiserFidelite();
                                break;
                            case 2:
                                // Code pour afficher les clients
                                affichage_client();
                                break;
                            case 3:
                                // Code pour enregistrer un client
                                saisie_client();
                                break;
                            case 4:
                                // Code pour supprimer un client
                                suppression_client();
                                break;
                            case 5:
                                // Code pour l'historique client
                               modification_client();
                                break;
                            case 6:
                                // Code pour rechercher un client
                                infosclient();
                                break;
                            case 7:
                                // Code pour l'historique client
                                affichage_historiquec();
                                break; 
                            case 8:  
                                reintegre_cleint();  
                                break;
                            case 0:
                                // Retour au menu principal
                                break;
                            default:
                                printf("Choix erroné\n");
                                break;
                        }
                    }
                }
                break;
            case 2:
                // Menu de gestion des véhicules
                {
                    int choixGestionVehicule = -1;
                    while (choixGestionVehicule != 0) {
                        printf("\033[1;36m");
                        printf("+-----------------------------------------+\n");
                        printf("|        Menu de gestion des véhicules    |\n");
                        printf("| -1-  Afficher les véhicules             |\n");
                        printf("| -2-  Saisir un véhicule                 |\n");
                        printf("| -3-  Supprimer un véhicule              |\n");
                        printf("| -4-  Afficher historique des suppresions|\n");
                        printf("| -5-  Modifier un véhicule               |\n");
                        printf("| -6-  Recherche véhicule par type        |\n");
                        printf("|                                         |\n");
                        printf("| -0-  Retour au menu principal           |\n");
                        printf("+-----------------------------------------+\n");
                        printf("\033[0m");
                        printf("Choix : ");
                        scanf("%d", &choixGestionVehicule);

                        switch (choixGestionVehicule) {
                            case 1:
                                // Code pour afficher les véhicules
                                affichage_vehicule();
                                break;
                            case 2:
                                // Code pour enregistrer un véhicule
                                saisie_vehicule();
                                break;
                            case 3:
                                // Code pour supprimer un véhicule
                                suppression_vehicule();
                                break;
                            case 4:
                                // Code pour l'historique des véhicules
                               affichage_historiquev();
                                break;
                            case 5:
                                // Code pour l'historique des véhicules
                                modification_vehicule();
                                break;
                            case 6:
                              // Code pour afficher les véhicules par type
                              affichage_typevehicule();
                              break;
                            case 0:
                                // Retour au menu principal
                                break;
                            default:
                                printf("Choix erroné\n");
                                break;
                        }
                    }
                }
                break;
            case 3:
                // Louer un véhicule
                {
                    int choixLouer = -1;
                    while (choixLouer != 0) {
                        printf("\033[1;36m");
                        printf("+-------------------------------------------------------------------------+\n");
                        printf("|                             Menu de location                            |\n");
                        printf("| -1-  Saisir une location                                                |\n");
                        printf("| -2-  Restituer un véhicule                                              |\n");
                        printf("| -3-  Afficher les véhicules disponibles à la location                   |\n");
                        printf("| -4-  Afficher les locations de l'agence                                 |\n");
                        printf("|                                                                         |\n");
                        printf("| -0-  Retour au menu principal                                           |\n");
                        printf("+-------------------------------------------------------------------------+\n");
                        printf("\033[0m");
                        printf("Choix : ");
                        scanf("%d", &choixLouer);

                        switch (choixLouer) {
                            case 1:
                                // Code pour louer un véhicule
                                saisie_location();
                                break;
                            case 2:
                                // Code pour restituer un véhicule
                                retour_vehicule();
                                break;
                            case 3:
                                affichage_vehicule_dispo();
                                break;
                            case 4:
                                afficher_location();
                                break;
                            case 0:
                                // Retour au menu principal
                                break;
                            default:
                                printf("Choix erroné\n");
                                break;
                        }
                    }
                }
                break;
            case 4:
                // Gestion des assurances et Options de loc
                {
                    int choixLouer = -1;
                    while (choixLouer != 0) {
                        printf("\033[1;36m");
                        printf("+-----------------------------------------+\n");
                        printf("|     Menu de Options et Assurances       |\n");
                        printf("| -1-  Ajouter une Option                 |\n");
                        printf("| -2-  Ajouter une assurance              |\n");
                        printf("| -3-  Afficher les options               |\n");
                        printf("| -4-  Affcher les assurances             |\n");
                        printf("|                                         |\n");
                        printf("| -0-  Retour au menu principal           |\n");
                        printf("+-----------------------------------------+\n");
                        printf("\033[0m");
                        printf("Choix : ");
                        scanf("%d", &choixLouer);

                        switch (choixLouer) {
                            case 1:

                                ajouter_option();
                                break;
                            case 2:

                                ajouter_assurance();
                                break;
                            case 3:

                                affichage_option();
                                break;
                            case 4:

                                affichage_assurance();
                                break;


                            case 0:
                                // Retour au menu principal
                                break;
                            default:
                                printf("Choix erroné\n");
                                break;
                        }
                    }
                }
                break;
            case 5:
            // Gestion des finances de l'agence
            {
                int choixfinance = -1;
                while (choixfinance != 0) {
                    printf("\033[1;36m");
                    printf("+-----------------------------------------------------------------------------+\n");
                    printf("|                                       Finance                               |\n");
                    printf("| -1-  Générer une facture client                                             |\n");
                    printf("| -2-  Afficher le bilan financier de l'entreprise sur les 30 derniers jours  |\n");
                    printf("| -3-  Historique des factures                                                |\n");
                    printf("|                                                                             |\n");
                    printf("| -0-  Retour au menu principal                                               |\n");
                    printf("+-----------------------------------------------------------------------------+\n");
                    printf("\033[0m");
                    printf("Choix : ");
                    scanf("%d", &choixfinance);

                    switch (choixfinance) {
                        case 1:

                            generer_facture();
                            break;
                        case 2:

                            compte_30jours();
                            break;
                        case 3:

                            historique_affichage_facture();
                            break;
                        case 0:
                            // Retour au menu principal
                            break;
                        default:
                            printf("Choix erroné\n");
                            break;
                    }
                   }
                }
                break;
            case 0:
                quitter();
                break;
            default:
                printf("Choix erroné\n");
                break;
        }
    }

}

//-------------------------------------------------------------------
void viderBuffer() 
{
    int c = 0;
    while (c != '\n' && c != EOF) 
  {
        c = getchar();
    }
}

//-------------------------------------------------------------------
void conv_maj(char ch[])
{
  int i, taille       ;

  taille = strlen(ch) ;
  for (i=0 ; i< taille ; i++)
  {
    ch[i] = toupper(ch[i]) ;
  }
}
//----------------------------------------------------------------
void conv_immatriculation(char ch[]) 
{
    int i;
    char t[10]; 


    for (i = 0; i < 2; i++) 
  {
        t[i] = toupper(ch[i]);
    }

    t[2] = '-'; // Ajoute le premier tiret


    for (i = 2; i < 5; i++) 
  {
        t[i + 1] = ch[i]; 
    }

    t[6] = '-'; // Ajoute le second tiret après les chiffres


    for (i = 5; i < 8; i++) {
        t[i + 2] = toupper(ch[i]); // Ajuste l'index dans t pour inclure les deux tirets
    }

    t[9] = '\0'; // Termine la chaîne de caractères correctement

    // Copie le résultat de retour dans ch, nécessite de s'assurer que ch est assez grand
    for (i = 0; i <= 9; i++) {
        ch[i] = t[i];
    }
}
//-----------------------------------------------------------------------
void quitter()
{
  verif_sauvegarde_client();
  verif_sauvegarde_vehicule();
  verif_sauvegarde_assurance();
  verif_sauvegarde_option();
  verif_sauvegarde_location();
  verif_sauvegarde_facture();
  verif_sauvegarde_fidelite();
  verif_sauvegarde_histoc();
  verif_sauvegarde_histov();
  printf("Au revoir\n");
}
//-----------------------------------------------------------------------
int recherche_numvehicule(int numero)
{

  int i ;
  struct vehicules voiture;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbvehicule ; i++)
  {
    voiture = tabvehicule[i];
    if (voiture.num_vehicule==numero)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//----------------------------------------------------------------
int recherche_numloc(int numero)
{

  int i ;
  struct facture fac;
  int numcase=-1;

  
  for (i=0 ; i< nbfacture ; i++)
  {
    fac = tabfacture[i];
    if (fac.numero_loc==numero)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//-----------------------------------------------------------------
int recherche_vehicule(char nomrech[100])
{
    
    int i ;
      struct vehicules voiture;
      int numcase=-1;//NON_TROUVE=-1

      // Boucle recherche
      for (i=0 ; i< nbvehicule ; i++)
      {
        voiture = tabvehicule[i];
        if (strcmp(voiture.immatriculation,nomrech)==0)
        {
          numcase = i ;
        }
      } 
      return numcase ;
    }
//-----------------------------------------------------------------
int recherche_mailclient(char nomrech[100])
{
  int i ;
  struct client individu;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbreclient ; i++)
  {
    individu = tabclient[i];
    if (strcmp(individu.mail,nomrech)==0)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//-----------------------------------------------------------------
int recherche_client(char nomrech[100])
{
  int i ;
  struct client individu;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbreclient ; i++)
  {
    individu = tabclient[i];
    if (strcmp(individu.telephone,nomrech)==0)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//-----------------------------------------------------------------
int recherche_numpermisclient(char nomrech[100])
{
  int i ;
  struct client individu;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbreclient ; i++)
  {
    individu = tabclient[i];
    if (strcmp(individu.num_permis,nomrech)==0)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//---------------------------------------
int recherche_numsuppression(int numero)
{

  int i ;
  struct historique_client historique;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbhistoriquec ; i++)
  {
    historique = historique_client[i];
    if (historique.num_client==numero)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//---------------------------------------------------------------
int recherche_numclient(int numero)
{

  int i ;
  struct client individu;
  int numcase=-1;//NON_TROUVE=-1

  // Boucle recherche
  for (i=0 ; i< nbreclient ; i++)
  {
    individu = tabclient[i];
    if (individu.num_client==numero)
    {
      numcase = i ;
    }
  } 
  return numcase ;
}
//---------------------------------------------------------------

void saisie_vehicule()
{
  struct vehicules voiture ;
  struct vehicules affichages[100];
  int i ;
  int ok,oki;
  char reponse;




  // Boucle de saisie
  i=nbvehicule ;
  while(strcmp(voiture.marque,"FIN")!=0)
  {
    ok=0;
    // saisie de la marque du véhicule
    viderBuffer();
    voiture.marque[0]='\0';
    printf("\nEntrez la marque du vehicule (fin pour terminer) : ");
    scanf("%s",voiture.marque);
    conv_maj(voiture.marque);


    if(strcmp(voiture.marque,"FIN")!=0)
    {
      //type véhicule
      ok=0;
      voiture.type[0]='\0';
      while(ok ==0)
        {

      printf("Entrez le type du vehicule : ");
      scanf("%s",voiture.type);
      conv_maj(voiture.type);
  if (strcmp(voiture.type,"BER")==0)      strcpy(voiture.type,"BERLINE") && (ok=1)   ;
  else if (strcmp(voiture.type,"SP")==0) strcpy(voiture.type,"SPORTIVE") && (ok=1)  ;
    else if (strcmp(voiture.type,"SUV")==0) strcpy(voiture.type,"SUV") && (ok=1);
    else if (strcmp(voiture.type,"CIT")==0) strcpy(voiture.type,"CITADINE") && (ok=1);
    else if (strcmp(voiture.type,"FAM")==0) strcpy(voiture.type,"FAMILIALE") && (ok=1);
  else if (strcmp(voiture.type,"UTI")==0) strcpy(voiture.type,"UTILITAIRE") && (ok=1);
  else if (strcmp(voiture.type,"4X4")==0) strcpy(voiture.type,"4X4") && (ok=1);
    else strcpy(voiture.type,"ERREUR")  ; 
      printf("Type du véhicule : %s\n",voiture.type);	
      }
      // saisie du modèle du véhicule
      voiture.modele[0]='\0';
      printf("Entrez le modèle du véhicule : ");
      scanf("%s",voiture.modele);
      conv_maj(voiture.modele);

        // saisie de l'année du véhicule
      printf("Entrez l'année de fabrication du véhicule : ");
      voiture.annee=0;
      while((voiture.annee<1890)||(voiture.annee>2024))
       {
        scanf("%d",&voiture.annee);
        if ((voiture.annee<1890)||(voiture.annee>2024))
        {
            printf("La date saisie est invalide\n");
            printf("Veillez saisir une nouvelle date : ");
        }
    }

      // saisie de la plaque du véhicule
      voiture.immatriculation[0]='\0';
    printf("Entrez la plaque d'immatriculation du véhicule : ");
      while (1)
      {
             scanf("%s",voiture.immatriculation);
            conv_immatriculation(voiture.immatriculation);

             if(strlen(voiture.immatriculation)!=9)
             {
              printf("le nom de la plaque d'imatriculation est invalide\n")	;
              printf("Veillez réecrire la plaque d'immatriculation : ");
       }
          else{
              if(recherche_vehicule(voiture.immatriculation)==-1)
              {
                  break;
              }
              else{
                  printf("la plaque d'immatriculation existe déjà\n");
                  printf("Veillez réecrire la plaque d'immatriculation : ");
              }
          }
    }
    printf("Plaque d'immatriculation : %s\n",voiture.immatriculation);



      // saisie du kilometrage du véhicule
      printf("Entrez le kilomètrage du véhicule : ");
      voiture.kilometrage=-1;
      while(voiture.kilometrage<0)
      {
        scanf("%d",&voiture.kilometrage);
        if (voiture.kilometrage<0)
        {
          printf("Entrez une valeur cohérente : ");
      }
      }

      // saisie du carburant du véhicule
      ok=0;
      voiture.carburant[0]='\0';
      while(ok ==0)
        {

      printf("Entrez le type de carburant du vehicule : ");
      scanf("%s",voiture.carburant);
      conv_maj(voiture.carburant);
  if (strcmp(voiture.carburant,"SP")==0)      strcpy(voiture.carburant,"ESSENCE") && (ok=1)   ;
  else if (strcmp(voiture.carburant,"GAZ")==0) strcpy(voiture.carburant,"DIESIEL") && (ok=1)  ;
    else if (strcmp(voiture.carburant,"ELE")==0) strcpy(voiture.carburant,"ELECTRIQUE") && (ok=1);
    else strcpy(voiture.carburant,"ERREUR")  ; 
      printf("Type de carburant : %s\n",voiture.carburant);

      }

    // saisie du prix du véhicule

      printf("Entrez le prix de la location du véhicule par jour : ");
      voiture.prix=-1;
      while(voiture.prix<0)
      {
        scanf("%d",&voiture.prix);
        if(voiture.prix<0)
        {
          printf("Entrez une valeur cohérente : ");

    }
    }


      // saisie de la caution du véhicule
      printf("Entrez le prix de la caution du véhicule : ");
      voiture.caution=-1;
      while(voiture.caution<0)
      {
         scanf("%d",&voiture.caution);
         if(voiture.caution<0)
         {
            printf("Entrez une valeur cohérente : ");
       }
    }


    //initialise la surtaxe sur les jeunes permis    
    oki = 0;
    printf("Voulez-vous surtaxer les clients étant en permis probatoire pour ce véhicule ? (répondre 'o' pour oui et 'n' pour non): ");
    while (oki != 1) 
    {
        scanf(" %c", &reponse);  

        if (reponse != 'n' && reponse != 'o') 
      {  // Correction de la condition
          printf("Entrez 'o' pour oui et 'n' pour non: ");
        } 
      else 
      {
            if (reponse == 'o') 
        {
                printf("Combien voulez-vous les surtaxer ( en pourcentage) : ");
                scanf("%d", &voiture.surtaxe_jeunepermis);  
                oki = 1;
            } 
        else 
        {
                voiture.surtaxe_jeunepermis = 0; 
                oki = 1;
            }
        }
      }



      //initialisation de loué
      strcpy(voiture.loue, "NON");
      strcpy(voiture.statut, "DISPONIBLE");

        i= nbvehicule;
    voiture.num_vehicule = 0;
    voiture.num_vehicule= i+1;
    strcpy(voiture.Etat, "EXCELLENT");
      //Vérification si le numéro n'est pas deja attribué
    while (numeroDejaExistantV(voiture.num_vehicule)) {
          voiture.num_vehicule++; 
      }
    printf("Le numéro du véhicule de %s est : %d\n",voiture.immatriculation,voiture.num_vehicule);


      tabvehicule[i++] = voiture;
      a_sauvegarderv=1;

      nbvehicule = i ;

    }
  }

  printf("nombre de vehicule: %d\n", nbvehicule);

}


//--------------------------------------------------
int numeroDejaExistantV(int num) {
    for (int i = 0; i < nbvehicule; i++) {
        if (tabvehicule[i].num_vehicule == num) {
            return 1; 
        }
    }
    return 0; 
}
//------------------------------------------------
int numeroDejaExistantC(int num) {
    for (int i = 0; i < nbreclient; i++) {
        if (tabclient[i].num_client == num) {
            return 1; 
        }
    }
    return 0; 
}
//-------------------------------------------------

void saisie_client ()
{
  struct client individu;
  int ok=0;
  int yes =0;
  int i=0;
  int verif=0;
  int jour,mois,annee;
  int date_valide = 0;
  char rue[100],type_voie[100],nom_voie[100],ville[100],code_postal[100];
  i=nbreclient;

  individu.prenom[0]='\0';
  while(strcmp(individu.prenom,"FIN")!=0)
  {
    viderBuffer();
    // Saisie du prénom
    printf("\nEntrez le prénom du client (fin pour terminer) : ");
    individu.prenom[0]='\0';
    scanf("%s",individu.prenom);
    conv_maj(individu.prenom);
    //if pour rentre dans la saisie		
    if(strcmp(individu.prenom,"FIN")!=0)
      {
        //Saisie du nom
      printf("Entrez le nom du client : ");
      individu.nom[0]='\0';			
      scanf("%s",individu.nom);
      conv_maj(individu.nom);

      //saisie date de naissance
      while(date_valide == 0){
        printf("Entrez la date de naissance du client (DD MM YYYY) : ");
        scanf("%d %d %d", &jour, &mois, &annee);
          if(2024-annee<18)
          {
              date_valide=0;
          }
          else
          {
        date_valide = DateValide(jour, mois, annee);
          }
        if (date_valide==0) {
            printf("Date invalide. Veuillez entrer une date valide.\n");
        }

      }

      char *date = format_date(jour, mois, annee);
      strcpy(individu.date_de_naissance, date);



      //Saisie du numéro de permis
      printf("Entrez le numéro de permis du client : ");
    while(1)
        {
      individu.num_permis[0]='\0';
      scanf("%s",individu.num_permis);     

        if(strlen(individu.num_permis)!=12)
        {  
          printf("Veillez entrer un numéro de permis valide : ");
        }
        else{
            if(recherche_numpermisclient(individu.num_permis)==-1)
                  {
                      break;
                  }
             else{
                    printf("Ce numéro de permis est déjà attribué à un client.\n");
                    printf("Veuillez entrer un autre numéro de permis : ");
                      }
        }
      }
          

      
        

      //saisie de l'année de permis
      printf("En quelle année le permis a été obtenue ? : ");
          while(1)
              {
      scanf("%d",&individu.annee_permis);
                  if(individu.annee_permis<1930 || individu.annee_permis>2024)
                  {
                      printf("Veuillez entrer une année valide : ");
                  }
                  else{
                      break;
                  }
              }

      //Verification telephone
      printf("Entrez le numéro de telephone du client : ");
    while(1)
        {
      individu.telephone[0]='\0';
    scanf("%s",individu.telephone);

        for(i=2;i<8;i++)
        {
          if (individu.telephone[i]!='0')
          {
            verif=1;
          }
        }
        if(strlen(individu.telephone)!=10||(individu.telephone[0]!='0')||(individu.telephone[1]=='0')||(verif!=1))
        {

          printf("Le numéro de téléphone est erroné\n");
          printf("Veillez resaissir le numéro téléphonique : ");
        }
        else{
            if(recherche_client(individu.telephone)==-1)
                   {
                       break;
                   }
                    else{
                        printf("Le numéro de téléphone est déjà utilisé\n");
                        printf("Veillez resaissir le numéro téléphonique : ");

                    }
        }
      }
      
           
        
        


      //verification du mail et s'il est valable
      printf("Entrez le mail du client : ");
        while(1)
            {
      individu.mail[0]='\0';
     scanf("%s",individu.mail);
    conv_maj(individu.mail);
       
        
          ok=0;
          yes=0;
          for(i=0;i<strlen(individu.mail);i++)
          {
            if(individu.mail[i]=='@')  
            {
              ok+=1;
            }
            if(individu.mail[i]=='.')
            {
              yes+=1;
            }
          }
          if ((ok!=1)||(yes<1)||(strlen(individu.mail)<5))
          {
            printf("Le format du mail est incorrect\n");
            printf("Veillez réecrire le mail : ");
          }
         else
          {
              if(recherche_mailclient(individu.mail)==-1)
              {
                  break;
              }
              else{
                  printf("Le mail est déjà utilisé\n");
                  printf("Veillez réecrire le mail : ");
              }
          }
        }
           

        
            

      //Entrée de l'adresse

      printf("Entrez le numéro de rue du client : ");
      scanf("%s",rue);
      conv_maj(rue);

      //Verif type de voie
      ok=0;


    //verififie si le type de voie existe réellement
       while(ok !=1)
        {

      printf("Entrez le type de voie du client : ");
      scanf("%s",type_voie);
      conv_maj(type_voie);
      if(strlen(type_voie)>13)
      {
        printf("Vous avez rentré trop de caractère\n");
      }
      else
      {
        if (strcmp(type_voie,"RUE")==0)      strcpy(type_voie,"RUE") && (ok=1)   ; else if (strcmp(type_voie,"AVENUE")==0)      strcpy(type_voie,"AVENUE") && (ok=1)   ; else if (strcmp(type_voie,"ALLÉE")==0)      strcpy(type_voie,"ALLÉE") && (ok=1)   ; else if (strcmp(type_voie,"ANSE")==0)      strcpy(type_voie,"ANSE") && (ok=1)   ;
        else if (strcmp(type_voie,"BOULEVARD")==0)      strcpy(type_voie,"BOULEVARD") && (ok=1)   ;else if (strcmp(type_voie,"CARREFOUR")==0)      strcpy(type_voie,"CARREFOUR") && (ok=1)   ;else if (strcmp(type_voie,"CHAUSSÉE")==0)      strcpy(type_voie,"CHAUSSÉE") && (ok=1)   ; else if (strcmp(type_voie,"CHEMIN")==0)      strcpy(type_voie,"CHEMIN") && (ok=1)   ; 
          else if (strcmp(type_voie,"CITÉ")==0) strcpy(type_voie,"CITÉ") && (ok=1);else if (strcmp(type_voie,"CLOS")==0) strcpy(type_voie,"CLOS") && (ok=1);else if (strcmp(type_voie,"CÔTE")==0) strcpy(type_voie,"CÔTE") && (ok=1);else if (strcmp(type_voie,"COUR")==0) strcpy(type_voie,"COUR") && (ok=1);else if (strcmp(type_voie,"COUR")==0) strcpy(type_voie,"COUR") && (ok=1);
          else if (strcmp(type_voie,"COURS")==0) strcpy(type_voie,"COURS") && (ok=1);else if (strcmp(type_voie,"DEGRÉ")==0) strcpy(type_voie,"DEGRÉ") && (ok=1);else if (strcmp(type_voie,"DESCENTE")==0) strcpy(type_voie,"DESCENTE") && (ok=1);else if (strcmp(type_voie,"DRÈVE")==0) strcpy(type_voie,"DRÈVE") && (ok=1);else if (strcmp(type_voie,"ESPLANADE")==0) strcpy(type_voie,"ESPLANADE") && (ok=1);
        else if (strcmp(type_voie,"GAFFE")==0) strcpy(type_voie,"GAFFE") && (ok=1);else if (strcmp(type_voie,"IMPASSE")==0) strcpy(type_voie,"IMPASSE") && (ok=1);else if (strcmp(type_voie,"LIAISON")==0) strcpy(type_voie,"LIAISON") && (ok=1);else if (strcmp(type_voie,"MAIL")==0) strcpy(type_voie,"MAIL") && (ok=1);else if (strcmp(type_voie,"MONTÉE")==0) strcpy(type_voie,"MONTÉE") && (ok=1);
        else if (strcmp(type_voie,"PASSAGE")==0) strcpy(type_voie,"PASSAGE") && (ok=1);else if (strcmp(type_voie,"PLACE")==0) strcpy(type_voie,"PLACE") && (ok=1);else if (strcmp(type_voie,"PLACETTE")==0) strcpy(type_voie,"PLACETTE") && (ok=1);else if (strcmp(type_voie,"PONT")==0) strcpy(type_voie,"PONT") && (ok=1);else if (strcmp(type_voie,"PROMENADE")==0) strcpy(type_voie,"PROMENADE") && (ok=1);
        else if (strcmp(type_voie,"QUAI")==0) strcpy(type_voie,"QUAI") && (ok=1);else if (strcmp(type_voie,"RÉSIDENCE")==0) strcpy(type_voie,"RÉSIDENCE") && (ok=1);else if (strcmp(type_voie,"RANG")==0) strcpy(type_voie,"RANG") && (ok=1);else if (strcmp(type_voie,"RAMPE")==0) strcpy(type_voie,"RAMPE") && (ok=1);else if (strcmp(type_voie,"ROUTE")==0) strcpy(type_voie,"ROUTE") && (ok=1);
        else if (strcmp(type_voie,"RUELLE")==0) strcpy(type_voie,"RUELLE") && (ok=1);else if (strcmp(type_voie,"SENTE")==0) strcpy(type_voie,"SENTE") && (ok=1);else if (strcmp(type_voie,"SENTIER")==0) strcpy(type_voie,"SENTIER") && (ok=1);else if (strcmp(type_voie,"SQUARE")==0) strcpy(type_voie,"SQUARE") && (ok=1); else if (strcmp(type_voie,"TRABOULE")==0) strcpy(type_voie,"TRABOULE") && (ok=1);
        else if (strcmp(type_voie,"TRAVERSE")==0) strcpy(type_voie,"TRAVERSE") && (ok=1);else if (strcmp(type_voie,"VENELLE")==0) strcpy(type_voie,"VENELLE") && (ok=1);else if (strcmp(type_voie,"VILLA")==0) strcpy(type_voie,"VILLA") && (ok=1);else if (strcmp(type_voie,"VOIE")==0) strcpy(type_voie,"VOIE") && (ok=1);
        else strcpy(type_voie,"INCORRECT")  ; 
            printf("Type de voie : %s\n",type_voie);
      }



      }

      printf("Entrez le nom de la voie du client: ");
      scanf("%s",nom_voie);
      conv_maj(nom_voie);

      printf("Entrez le nom de la ville du client : ");
      scanf("%s",ville);
      conv_maj(ville);

      //vérifier si le code postal possède 5 caractères
      printf("Entrez le code postal du client : ");
      code_postal[0]='\0';
      while(strlen(code_postal)!=5)
      {
        scanf("%s",code_postal);
        conv_maj(code_postal);
        if(strlen(code_postal)!=5)
        {
          printf("Le Code postal n'est pas au bon format\n");
          printf("Veilliez entrée le code postal au bon format : ");	
        }


      }


      //Entrée de l'adresse au format 

      strcpy(individu.adresse,rue);
      strcat(individu.adresse," ");

      strcat(individu.adresse,type_voie);
      strcat(individu.adresse," ");

      strcat(individu.adresse,nom_voie);
      strcat(individu.adresse," ");

      strcat(individu.adresse,ville);
      strcat(individu.adresse," ");

      strcat(individu.adresse,code_postal);

      printf("%s\n",individu.adresse);

      //initialisation du numéro client
      i= nbreclient;
      individu.num_client= i+1;
      individu.nblocation=0;//pour compte le nombre de location pour la fidélité
      while(numeroDejaExistantC(individu.num_client)){
        individu.num_client++;
      }
      printf("Le numéro client de %s %s est : %d",individu.nom,individu.prenom,individu.num_client);


      tabclient[i++] = individu;
       a_sauvegarder=1;
       nbreclient = i ;
    }
}



  printf("nombre de client est %d\n", nbreclient);


}

void affichage_client()
{
  int i;
  struct client Unclient;

  if (nbreclient == 0)
  {
    printf("Aucun client à afficher\n");
  }
  else
  {
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("%-15s %-15s %-15s %-18s %-20s %-25s %-20s %-20s %-30s\n", "Numéro Client", "Nom", "Prénom", "Date de Naissance", "Numéro de Permis", "Année de permis", "Mail", "Téléphone", "Adresse");
    printf("--------------------------------------------------------------------------------------------------------\n");
    // Boucle d'affichage
    for (i = 0; i < nbreclient; i++)
    {
      Unclient = tabclient[i];
      printf("%-15d %-15s %-15s %-18s %-20s %-15d %-25s %-15s %-30s\n", Unclient.num_client, Unclient.nom, Unclient.prenom, Unclient.date_de_naissance, Unclient.num_permis, Unclient.annee_permis, Unclient.mail, Unclient.telephone, Unclient.adresse);
    }
    printf("--------------------------------------------------------------------------------------------------------\n");
  }
}


void affichage_vehicule() {
    int i;
    struct vehicules voiture;

    if (nbvehicule == 0) {
        printf("Aucun véhicule à afficher\n");
    } else {
        printf("-----------------------------------------------------------\n");
        printf("%-10s %-10s %-10s %-10s %-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s %5s\n","Numéro",
               "Marque", "Modèle","Type", "Année", "Immatriculation", "Kilométrage",
               "Carburant", "loue", "Statut", "État", "Prix TTC","Caution");
        printf("-----------------------------------------------------------\n");

        // Boucle d'affichage
        for (i = 0; i < nbvehicule; i++) {
            voiture = tabvehicule[i];
            printf("%-10d %-10s %-10s %-10s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",voiture.num_vehicule,
                   voiture.marque, voiture.modele,voiture.type, voiture.annee,
                   voiture.immatriculation, voiture.kilometrage,
                   voiture.carburant, voiture.loue, voiture.statut,
                   voiture.Etat, voiture.prix, voiture.caution);
        }
        printf("-----------------------------------------------------------\n");
    }
}
//--------------------------------------------------------------
void afficher_location() {
    int i;
    struct location loue;

    if (nblocation == 0) {
        printf("Aucune location à afficher\n");
    } else {
        printf("------------------------------------------------------------------------------------------------------------------\n");
        printf("%-10s %-10s %-10s %-15s %-15s %-15s %-10s %-10s  %-10s %-10s %-10s %5s\n",
               "Numéro", "Marque", "Statut", "Date début", "Date fin", "Assurance", "Option", "Prix", "Caution",
               "Nom", "Prénom", "Immatriculation");
        printf("------------------------------------------------------------------------------------------------------------------\n");


        for (i = 0; i < nblocation; i++) {
            loue = tabloc[i];
            // Si pas d'assurance, on affiche "Pas Assu"
            char assurance_affiche[20];
            if (loue.assurance == 0) {
                strcpy(assurance_affiche, "PAS_ASSU");
            }
            else {
                strcpy(assurance_affiche, loue.nom_assurance);
            }
            printf("%-10d %-10s %-10s %-15s %-15s %-15s %-10.2f %-10d %-10d %-10s %-10s %-10s\n",
                   loue.numero_loc, loue.marque, loue.statut, loue.date_debut, loue.date_fin, assurance_affiche,
                   loue.option, loue.prix, loue.caution, loue.nom, loue.prenom, loue.immatriculation);
        }
        printf("------------------------------------------------------------------------------------------------------------------\n");
    }
}
// -------------------------------------------------------------
void verif_sauvegarde_client()
{
  char reponse[10];

  if (a_sauvegarder)
  {
    printf("Des données client ont été modifiées\n");
    printf("Voulez-vous faire une sauvegarde (o/n) : ");
    scanf("%s",reponse);
    conv_maj(reponse);

    if (reponse[0] == 'O')
       sauvegarde_client();
    
  }
}
//----------------------------------------------------------------
void verif_sauvegarde_vehicule(){
    char reponse2[10];
    if (a_sauvegarderv)
  {
    printf("Des données sur les véhicules ont été modifiées\n");
    printf("Voulez-vous faire une sauvegarde (o/n) : ");
    scanf("%s",reponse2);
    conv_maj(reponse2);

    if (reponse2[0] == 'O')
       sauvegarder_vehicules();
  }
}
//----------------------------------------------------------------
void sauvegarder_location(){
  int i;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  if (nblocation == 0) {
      printf("Aucune location à sauvegarder\n");
  } else {
      // Ouverture du fichier
      strcpy(NomFichier, "locations.txt");
      fichier = fopen(NomFichier, "w");

      // Boucle de sauvegarde
      for (i = 0; i < nblocation; i++) {
          char assurance_affiche[20];
          if (tabloc[i].assurance == 0) {
              strcpy(tabloc[i].nom_assurance, "PAS_ASSU");
          } 
          fprintf(fichier, "%d %s %s %s %s %s %f %f %d %d %d %s %s %s %s %d %d\n",
                  tabloc[i].numero_loc, tabloc[i].marque, tabloc[i].modele,
                  tabloc[i].date_debut, tabloc[i].date_fin, tabloc[i].nom_assurance,
                  tabloc[i].assurance, tabloc[i].option, tabloc[i].prix,
                  tabloc[i].total, tabloc[i].caution, tabloc[i].nom, tabloc[i].prenom, tabloc[i].immatriculation, tabloc[i].statut, tabloc[i].num_client, tabloc[i].num_vehicule);
      }
      fclose(fichier);
      printf("%d locations sauvegardés\n", nblocation);
      a_sauvegarderl = 0;
  }

}
//----------------------------------------------------------------
void chargement_location(){
  int i, retour;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  // Boucle de chargement
  i = 0;
  strcpy(NomFichier, "locations.txt");
  fichier = fopen(NomFichier, "r");
  if (fichier != NULL) {
      while (!feof(fichier)) {
          retour = fscanf(fichier, "%d %s %s %s %s %s %f %f %d %d %d %s %s %s %s %d %d\n",
              &tabloc[i].numero_loc, tabloc[i].marque, tabloc[i].modele,
              tabloc[i].date_debut, tabloc[i].date_fin, tabloc[i].nom_assurance,
              &tabloc[i].assurance, &tabloc[i].option, &tabloc[i].prix,
              &tabloc[i].total, &tabloc[i].caution, tabloc[i].nom, tabloc[i].prenom, tabloc[i].immatriculation, tabloc[i].statut, &tabloc[i].num_client, &tabloc[i].num_vehicule);


          if (retour != EOF) { // La fin du fichier n'a pas été atteinte par fscanf()
              i++;
          }
      }
      fclose(fichier);
      nblocation = i;
      printf("%d locations chargées\n", nblocation);
  } else {
      printf("Erreur lors de l'ouverture du fichier pour chargement des loactions.\n");
  }

}
//----------------------------------------------------------------
void verif_sauvegarde_location(){
  char reponse3[10];
  if (a_sauvegarderl)
  {
  printf("Des données sur les locations ont été modifiées\n");
  printf("Voulez-vous faire une sauvegarde (o/n) : ");
  scanf("%s",reponse3);
  conv_maj(reponse3);

  if (reponse3[0] == 'O')
     sauvegarder_location();
  }

}
//-----------------------------------------------------------------
void sauvegarder_vehicules() {
    int i;
    FILE *fichier;
    char NomFichier[TAILLE_NOM_F];

    if (nbvehicule == 0) {
        printf("Aucun véhicule à sauvegarder\n");
    } else {
        // Ouverture du fichier
        strcpy(NomFichier, "vehicules.txt");
        fichier = fopen(NomFichier, "w");

        // Boucle de sauvegarde
        for (i = 0; i < nbvehicule; i++) {
            fprintf(fichier, "%s %s %d %s %d %s %s %s %s %d %d %d %d %s\n",
                    tabvehicule[i].marque, tabvehicule[i].modele, tabvehicule[i].annee,
                    tabvehicule[i].immatriculation, tabvehicule[i].kilometrage, tabvehicule[i].carburant,
                    tabvehicule[i].loue, tabvehicule[i].statut, tabvehicule[i].Etat,
                    tabvehicule[i].prix, tabvehicule[i].caution, tabvehicule[i].surtaxe_jeunepermis, tabvehicule[i].num_vehicule, tabvehicule[i].type);
        }
        fclose(fichier);
        printf("%d véhicules sauvegardés\n", nbvehicule);
        a_sauvegarderv = 0;
    }
}
//-------------------------------------------------------------------
void chargement_vehicules() {
    int i, retour;
    FILE *fichier;
    char NomFichier[TAILLE_NOM_F];

    // Boucle de chargement
    i = 0;
    strcpy(NomFichier, "vehicules.txt");
    fichier = fopen(NomFichier, "r");
    if (fichier != NULL) {
        while (!feof(fichier)) {
            retour = fscanf(fichier, "%s %s %d %s %d %s %s %s %s %d %d %d %d %s %d",
                tabvehicule[i].marque, tabvehicule[i].modele, &tabvehicule[i].annee,
                tabvehicule[i].immatriculation, &tabvehicule[i].kilometrage, tabvehicule[i].carburant,
                tabvehicule[i].loue, tabvehicule[i].statut, tabvehicule[i].Etat,
                &tabvehicule[i].prix, &tabvehicule[i].caution, &tabvehicule[i].surtaxe_jeunepermis, &tabvehicule[i].num_vehicule,tabvehicule[i].type,&tabvehicule[i].surtaxe_jeunepermis);


            if (retour != EOF) { // La fin du fichier n'a pas été atteinte par fscanf()
                i++;
            }
        }
        fclose(fichier);
        nbvehicule = i;
        printf("%d véhicules chargés\n", nbvehicule);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement des véhicules.\n");
    }
}
//------------------------------------------------
void sauvegarde_client() {
    FILE *fichier;
    char NomFichier[TAILLE_NOM_F];

    if (nbreclient == 0) {
        printf("Aucun client à sauvegarder\n");
    } else {
        // Ouverture du fichier
        strcpy(NomFichier, "client.txt");
        fichier = fopen(NomFichier, "w");

        // Boucle de sauvegarde
        for (int i = 0; i < nbreclient; i++) {
          supprimer_espaces_adresse(tabclient[i].adresse);
            fprintf(fichier, "%s %s %d %d %s %s %s %s %s %d\n",
                    tabclient[i].num_permis, tabclient[i].date_de_naissance, tabclient[i].annee_permis,
                    tabclient[i].num_client,
                    tabclient[i].nom, tabclient[i].prenom, tabclient[i].adresse,
                    tabclient[i].mail, tabclient[i].telephone, tabclient[i].nblocation);
        }
        fclose(fichier);
        printf("%d clients sauvegardés\n", nbreclient);
        a_sauvegarder = 0;
    }
}
//----------------------------------------------------------------------
void supprimer_espaces_adresse(char *adresse) {
    int i, j = 0;
    for (i = 0; adresse[i] != '\0'; i++) {
        if (adresse[i] != ' ') {
            adresse[j++] = adresse[i];
        }
    }
    adresse[j] = '\0';
}
//----------------------------------------------------------------------
void chargement_client() {
    FILE *fichier;
    char NomFichier[TAILLE_NOM_F];
    int retour;
    int i = 0; 

    // Ouverture du fichier
    strcpy(NomFichier, "client.txt");
    fichier = fopen(NomFichier, "r");

    if (fichier != NULL) {

        while (!feof(fichier)) {
            retour = fscanf(fichier, "%s %s %d %d %s %s %s %s %s %d\n",
                            tabclient[i].num_permis, tabclient[i].date_de_naissance, &tabclient[i].annee_permis,
                            &tabclient[i].num_client,
                            tabclient[i].nom, tabclient[i].prenom, tabclient[i].adresse,
                            tabclient[i].mail, tabclient[i].telephone, &tabclient[i].nblocation);
            if (retour != EOF) {
                i++;
            }
        }
        nbreclient = i; 
        fclose(fichier);
        printf("%d clients chargés\n", nbreclient);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement des clients.\n");
    }
}
//-------------------------------------------------------------
void modification_vehicule() {
    int numero,i;
    struct vehicules vehicule_mod;
    int ImmatriculationRecherche;

  printf("-----------------------------------------------------------\n");
  printf("%-10s %-10s %-20s %-15s %-10s %-10s %-10s \n",
  "Numéro","Marque", "Modèle", "Immatriculation","loue", "Statut","Etat");
        printf("-----------------------------------------------------------\n");

        // Boucle d'affichage
        for (i = 0; i < nbvehicule; i++) {
            vehicule_mod = tabvehicule[i];
            printf("%-10d %-10s %-20s %-15s  %-10s %-10s %-10sd\n",vehicule_mod.num_vehicule,
                   vehicule_mod.marque, vehicule_mod.modele,
                   vehicule_mod.immatriculation, vehicule_mod.loue, vehicule_mod.statut,
                   vehicule_mod.Etat);
        }
        printf("-----------------------------------------------------------\n");

    printf("Numéro du véhicule à modifier : ");
    scanf("%d", &ImmatriculationRecherche);
    numero = recherche_numvehicule(ImmatriculationRecherche);
    if (numero == NON_TROUVE) {
        printf("%d pas trouvé\n", ImmatriculationRecherche);
    } else {
        vehicule_mod = tabvehicule[numero];

        printf("Quels éléments souhaitez-vous modifier ?\n");
        printf("1. Marque\n");
        printf("2. Modèle\n");
        printf("3. Année\n");
        printf("4. Immatriculation\n");
        printf("5. Kilométrage\n");
        printf("6. Carburant\n");
        printf("7. Statut\n");
        printf("8. État\n");
        printf("9. Prix\n");
        printf("10. Caution\n");

        int choix;
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Ancienne marque  : %s\n", vehicule_mod.marque);
                printf("Nouvelle marque : ");
                scanf("%s", vehicule_mod.marque);
                break;
            case 2:
                printf("Ancien modèle  : %s\n", vehicule_mod.modele);
                printf("Nouveau modèle : ");
                scanf("%s", vehicule_mod.modele);
                break;
            case 3:
                printf("Ancienne année  : %d\n", vehicule_mod.annee);
                printf("Nouvelle année  : ");
                scanf("%d", &vehicule_mod.annee);
                while((vehicule_mod.annee<1890)||(vehicule_mod.annee>2024))
           {
              printf("La date saisie est invalide\n");
              printf("Veillez saisir une nouvelle date : ");
              scanf("%d", &vehicule_mod.annee);

        }
                break;

            case 4:
                printf("Ancienne immatriculation : %s\n", vehicule_mod.immatriculation);
                printf("Nouvelle immatriculation : ");
                while (1)
                      {
                             scanf("%s",vehicule_mod.immatriculation);
                            conv_immatriculation(vehicule_mod.immatriculation);

                             if(strlen(vehicule_mod.immatriculation)!=9)
                             {
                              printf("le nom de la plaque d'imatriculation est invalide\n")	;
                              printf("Veillez réecrire la plaque d'immatriculation : ");
                       }
                          else{
                              if(recherche_vehicule(vehicule_mod.immatriculation)==-1)
                              {
                                  break;
                              }
                              else{
                                  printf("la plaque d'immatriculation existe déjà\n");
                                  printf("Veillez réecrire la plaque d'immatriculation : ");
                              }
                          }
                    }
                    printf("Nouvelle plaque d'immatriculation : %s\n",vehicule_mod.immatriculation);
                break;

            case 5:
                printf("Ancien kilométrage  : %d\n", vehicule_mod.kilometrage);
                printf("Nouveau kilométrage  : ");
                scanf("%d", &vehicule_mod.kilometrage);
                break;
            case 6:
                printf("Ancien carburant : %s\n", vehicule_mod.carburant);
                printf("Nouveau carburant : ");
                scanf("%s", vehicule_mod.carburant);
                break;
            case 7:
                printf("Ancien statut : %s\n", vehicule_mod.statut);
                printf("Nouveau statut : ");
                scanf("%s", vehicule_mod.statut);
                break;
            case 8:
                printf("Ancien État : %s\n", vehicule_mod.Etat);
                printf("Nouvel État : ");
                scanf("%s", vehicule_mod.Etat);
                break;
            case 9:
                printf("Ancien prix : %d\n", vehicule_mod.prix);
                printf("Nouveau prix : ");
                scanf("%d", &vehicule_mod.prix);
                break;
            case 10:
                printf("Ancienne caution : %d\n", vehicule_mod.caution);
                printf("Nouvelle caution : ");
                scanf("%d", &vehicule_mod.caution);
                break;
            default:
                printf("Choix invalide\n");
                return;
        }

        tabvehicule[numero] = vehicule_mod;
        a_sauvegarderv = 1;
    }
}
//----------------------------------------------------------------------------------------
void suppression_vehicule() {
    int numero, i;
    struct vehicules vehicule_sup;
    int ImmatriculationRecherche;

  printf("-----------------------------------------------------------\n");
  printf("%-10s %-10s %-20s %-15s %-10s %-10s %-10s \n",
  "Numéro","Marque", "Modèle", "Immatriculation","loue", "Statut","Etat");
        printf("-----------------------------------------------------------\n");

        // Boucle d'affichage
        for (i = 0; i < nbvehicule; i++) {
            vehicule_sup = tabvehicule[i];
            printf("%-10d %-10s %-20s %-15s  %-10s %-10s %-10sd\n",vehicule_sup.num_vehicule,
                   vehicule_sup.marque, vehicule_sup.modele,
                   vehicule_sup.immatriculation, vehicule_sup.loue, vehicule_sup.statut,
                   vehicule_sup.Etat);
        }
        printf("-----------------------------------------------------------\n");

    printf("Numéro de véhicule a supprimer : ");
    scanf("%d", &ImmatriculationRecherche);
    numero = recherche_numvehicule(ImmatriculationRecherche); 
    if (numero == NON_TROUVE) {
        printf("%d pas trouvé\n", ImmatriculationRecherche);
    } else {
      convertir_historiquev(tabvehicule[numero]);
        vehicule_sup = tabvehicule[numero];
        printf("Suppression du véhicule\n");
        printf("-----------------------------------------\n");
        printf("%-15s %-20s %4s\n", "MARQUE", "MODELE", "ANNEE");
        printf("-----------------------------------------\n");
        printf("%-15s %-20s %4d\n", vehicule_sup.marque, vehicule_sup.modele, vehicule_sup.annee);
        printf("-----------------------------------------\n");

        for (i = numero; i < nbvehicule - 1; i++) {
            tabvehicule[i] = tabvehicule[i + 1];

        }
        nbvehicule--;
        a_sauvegarderv = 1; 
        a_sauvegarderhv = 1;
    }
}

void modification_client() {
    int numero,i;
    struct client client_mod;
    int numRecherche;

  printf("-------------------------------------\n");
    printf("%-10s %-10s %-20s\n","NUMERO","NOM","PRENOM"); //si pas de réservation en cours num de réservation = null
    printf("-------------------------------------\n");
    // Boucle d'affichage
    for (i=0 ; i< nbreclient ; i++)
    {
      client_mod = tabclient[i];
      printf("%-10d %-10s %-20s\n",client_mod.num_client,client_mod.nom,client_mod.prenom);
    } 
    printf("-------------------------------------\n"); 

    printf("Numéro client du client à modifier : ");
    scanf("%d", &numRecherche);
    numero = recherche_numclient(numRecherche);
    if (numero == NON_TROUVE) {
        printf("%d pas trouvé\n", numRecherche);
    } else {
        client_mod = tabclient[numero];

        int choix = -1;
        while (choix != 0) {
            printf("Quels éléments souhaitez-vous modifier ?\n");
            printf("1. Nom\n");
            printf("2. Prénom\n");
            printf("3. Date de naissance\n");
            printf("4. Numéro de permis\n");
            printf("5. Année du permis\n");
            printf("6. Numéro de client\n");
            printf("7. Adresse\n");
            printf("8. Adresse mail\n");
            printf("9. Numéro de téléphone\n");
            printf("0. Terminer la modification\n");


            printf("Votre choix : ");
            scanf("%d", &choix);

            switch (choix) {
                case 0: 
                    break;
                case 1:
                    printf("Ancien nom  : %s\n", client_mod.nom);
                    printf("Nouveau nom : ");
                    scanf("%s", client_mod.nom);
                    conv_maj(client_mod.nom);
                    break;
                case 2:
                    printf("Ancien prénom  : %s\n", client_mod.prenom);
                    printf("Nouveau prénom : ");
                    scanf("%s", client_mod.prenom);
                    conv_maj(client_mod.prenom);
                    break;
                case 3:
                    printf("Ancienne date  : %s\n", client_mod.date_de_naissance);
                    printf("Entrez la nouvelle date de naissance du client (DD MM YYYY) : ");                       int jour,mois,annee,date_valide=0;
                    while(date_valide == 0){
                        
                        scanf("%d %d %d", &jour, &mois, &annee);
                          if(2024-annee<18)
                          {
                              date_valide=0;
                          }
                          else
                          {
                        date_valide = DateValide(jour, mois, annee);
                          }
                        if (date_valide==0) {
                            printf("Date invalide. Veuillez entrer une date valide : ");
                        }

                      }

                      char *date = format_date(jour, mois, annee);
                      strcpy(client_mod.date_de_naissance, date);
                    break;
                case 4:
                    printf("Ancien numéro de permis  : %s\n", client_mod.num_permis);
                    printf("Nouveau numéro de permis : ");
                    while(1)
                        {
                      scanf("%s",client_mod.num_permis);     

                        if(strlen(client_mod.num_permis)!=12)
                        {  
                          printf("Veillez entrer un numéro de permis valide : ");
                        }
                        else{
                            if(recherche_numpermisclient(client_mod.num_permis)==-1)
                                  {
                                      break;
                                  }
                             else{
                                printf("Ce numéro de permis est déjà attribué à un client.\n");
                                printf("Veuillez entrer un autre numéro de permis : ");
                                      }
                        }
                      }
                    break;
                case 5:
                    printf("Ancienne année du permis  : %d\n", client_mod.annee_permis);
                    printf("Nouvelle année du permis : ");
                    while(1)
                          {
                    scanf("%d",&client_mod.annee_permis);
                              if(client_mod.annee_permis<1930 || client_mod.annee_permis>2024)
                              {
                                  printf("Veuillez entrer une année valide : ");
                              }
                              else{
                                  break;
                              }
                          }
                    break;
                case 6:
                    printf("Le numéro client n'est pas un champ modifiable\n");
                    break;
                case 7:
                    printf("Ancienne adresse : %s\n", client_mod.adresse);
                    printf("Nouvelle adresse : ");
                    scanf("%s", client_mod.adresse);
                    break;
                case 8:
                    printf("Ancienne adresse mail : %s\n", client_mod.mail);
                    printf("Nouvelle adresse mail : ");
                    while(1)
                        {
                    int ok,yes;
                        client_mod.mail[0]='\0';
                    scanf("%s",client_mod.mail);
                    conv_maj(client_mod.mail);


                      ok=0;
                      yes=0;
                      for(i=0;i<strlen(client_mod.mail);i++)
                      {
                        if(client_mod.mail[i]=='@')  
                        {
                          ok+=1;
                        }
                        if(client_mod.mail[i]=='.')
                        {
                          yes+=1;
                        }
                      }
                      if ((ok!=1)||(yes<1)||(strlen(client_mod.mail)<5))
                      {
                        printf("Le format du mail est incorrect\n");
                        printf("Veillez réecrire le mail : ");
                      }
                     else
                      {
                          if(recherche_mailclient(client_mod.mail)==-1)
                          {
                              break;
                          }
                          else{
                              printf("Le mail est déjà utilisé\n");
                              printf("Veuillez entrer un autre mail : ");
                          }
                      }
                    }
                    break;
                case 9:
                    printf("Ancien numéro de téléphone : %s\n", client_mod.telephone);
                    printf("Nouveau numéro de téléphone : ");
                    while(1)
                        {
                            int verif;
                          client_mod.telephone[0]='\0';
                    scanf("%s",client_mod.telephone);

                        for(i=2;i<8;i++)
                        {
                          if (client_mod.telephone[i]!='0')
                          {
                            verif=1;
                          }
                        }
                        if(strlen(client_mod.telephone)!=10||(client_mod.telephone[0]!='0')||(client_mod.telephone[1]=='0')||(verif!=1))
                        {

                          printf("Le numéro de téléphone est erroné\n");
                          printf("Veillez resaissir le numéro téléphonique : ");
                        }
                        else{
                            if(recherche_client(client_mod.telephone)==-1)
                                   {
                                       break;
                                   }
                                    else{
                                        printf("Le numéro de téléphone est déjà utilisé\n");
                                        printf("Veillez resaissir le numéro téléphonique : ");

                                    }
                        }
                      }

                    break;
                default:
                    printf("Choix invalide\n");
                    break;
            }
        }

        tabclient[numero] = client_mod;
        a_sauvegarder = 1;
    }
}

//--------------------------------------------------------------
void suppression_client() {
    int numero, i;
    struct client client_mod;
    int numRecherche;

  printf("-------------------------------------\n");
    printf("%-10s %-10s %-20s\n","NUMERO","NOM","PRENOM"); //si pas de réservation en cours num de réservation = null
    printf("-------------------------------------\n");
    // Boucle d'affichage
    for (i=0 ; i< nbreclient ; i++)
    {
      client_mod = tabclient[i];
      printf("%-10d %-10s %-20s\n",client_mod.num_client,client_mod.nom,client_mod.prenom);
    } 
    printf("-------------------------------------\n");

    printf("Numero client du client à supprimer : ");
    scanf("%d", &numRecherche);
    numero = recherche_numclient(numRecherche); 
    if (numero == NON_TROUVE) {
        printf("%d pas trouvé\n", numRecherche);
    } else {
        client_mod = tabclient[numero];
      convertir_historiquec(tabclient[numero]);
        printf("Suppression du client\n");
        printf("-----------------------------------------\n");
        printf("%-15s %-20s %-10s\n", "NOM", "PRENOM", "DATE DE NAISSANCE");
        printf("-----------------------------------------\n");
        printf("%-15s %-20s %-10s\n", client_mod.nom, client_mod.prenom, client_mod.date_de_naissance);
        printf("-----------------------------------------\n");

        for (i = numero; i < nbreclient - 1; i++) {
           tabclient[i] = tabclient[i + 1];

        }
        nbreclient--;
        a_sauvegarder= 1;
        a_sauvegarderhc =1;
    }

}
//------------------------------------------------------
void affichage_typevehicule() 
{
    int i,ok;
    char recherche[11];
    struct vehicules voiture;

ok=0;
while(ok ==0)
        {

      printf("Entrez le type de vehicule recherché (r pour quitter) : ");
      scanf("%s",recherche);
      conv_maj(recherche);
    if (strcmp(recherche,"BER")==0)      strcpy(recherche,"BERLINE") && (ok=1)   ;
  else if (strcmp(recherche,"SP")==0) strcpy(recherche,"SPORTIVE") && (ok=1)  ;
    else if (strcmp(recherche,"SUV")==0) strcpy(recherche,"SUV") && (ok=1);
    else if (strcmp(recherche,"CIT")==0) strcpy(recherche,"CITADINE") && (ok=1);
    else if (strcmp(recherche,"FAM")==0) strcpy(recherche,"FAMILIALE") && (ok=1);
  else if (strcmp(recherche,"UTI")==0) strcpy(recherche,"UTILITAIRE") && (ok=1);
  else if (strcmp(recherche,"4X4")==0) strcpy(recherche,"4X4") && (ok=1);
  else if (strcmp(recherche,"R")==0) break;
    else strcpy(recherche,"ERREUR")  ; 
      printf("Type de vehicule recherché : %s\n",recherche);	
      }
  if(ok==1)
  {

      if (nbvehicule == 0) 
    {
          printf("Aucun véhicule à afficher\n");
      } else {
          printf("-----------------------------------------------------------\n");
          printf("%-10s %-10s %-10s %-20s %-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s %5s\n","Numéro",
                 "Marque","Type", "Modèle", "Année", "Immatriculation", "Kilométrage",
                 "Carburant", "loue", "Statut", "État", "Prix H.T","Caution");
          printf("-----------------------------------------------------------\n");

          // Boucle d'affichage
          for (i = 0; i < nbvehicule; i++) 
      {
        voiture = tabvehicule[i];
          if (strcmp(voiture.type,recherche)==0)
          {
              printf("%-10d %-10s %-10s %-20s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",voiture.num_vehicule,
                     voiture.marque,voiture.type, voiture.modele, voiture.annee,
                     voiture.immatriculation, voiture.kilometrage,
                     voiture.carburant, voiture.loue, voiture.statut,
                     voiture.Etat, voiture.prix, voiture.caution);

              printf("-----------------------------------------------------------\n");
          }
      }
  }
}
}
//------------------------------------------------------------------
void affichage_vehicule_dispo() {
    int i;
    struct vehicules voiture;

    // Vérifier s'il y a des véhicules à afficher
    if (nbvehicule == 0) {
        printf("Aucun véhicule à afficher\n");
    } else {
        printf("-----------------------------------------------------------\n");
        printf("%-10s %-10s %-20s %-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s %5s\n",
               "Numéro","Marque", "Modèle", "Année", "Immatriculation", "Kilométrage",
               "Carburant", "loue", "Statut", "État", "Prix","Caution");
        printf("-----------------------------------------------------------\n");

        // Boucle d'affichage
        for (i = 0; i < nbvehicule; i++) {
            voiture = tabvehicule[i];
            if ((strcmp(voiture.statut, "DISPONIBLE") == 0) && (strcmp(voiture.loue, "NON")== 0)) {
                printf("%-10d %-10s %-20s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",
                       voiture.num_vehicule,voiture.marque, voiture.modele, voiture.annee,
                       voiture.immatriculation, voiture.kilometrage,
                       voiture.carburant, voiture.loue, 
                       voiture.statut, voiture.Etat, voiture.prix, voiture.caution);
            }
        }
        printf("-----------------------------------------------------------\n");
    }
}
//-----------------------------------------------------------------
void affichage_vehicule_dispo_date(char d[], char d_r[]) {
    int i,j;
    struct vehicules voiture;
    struct location loue;
      if (nbvehicule == 0) {
          printf("Aucun véhicule à afficher\n");
      } else {
          printf("-----------------------------------------------------------\n");
          printf("%-10s %-10s %-20s %-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s %5s\n",
                 "Numéro","Marque", "Modèle", "Année", "Immatriculation", "Kilométrage",
                 "Carburant", "loue", "Statut", "État", "Prix","Caution");
          printf("-----------------------------------------------------------\n");

          // Boucle d'affichage
          for (i = 0; i < nbvehicule; i++) {
              voiture = tabvehicule[i];
              int vehi_dispo = 1; // Variable pour indiquer si le véhicule est disponible

              // Vérifier si le véhicule est marqué comme non loué
              if ((strcmp(voiture.loue, "NON") == 0) && (strcmp(voiture.statut,"DISPONIBLE")==0)) {
                  // Afficher les informations du véhicule
                  printf("%-10d %-10s %-20s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",
                         voiture.num_vehicule, voiture.marque, voiture.modele, voiture.annee,
                         voiture.immatriculation, voiture.kilometrage,
                         voiture.carburant, voiture.loue, 
                         voiture.statut, voiture.Etat, voiture.prix, voiture.caution);
              } else if ((strcmp(voiture.loue, "OUI") == 0) && (strcmp(voiture.statut,"DISPONIBLE")==0)) {
                  // Vérifier si la location prévue pour le véhicule a des dates en commun avec la plage de dates donnée   
                  for (j = 0; j < nblocation; j++) {
                      loue = tabloc[j];
                      if (loue.num_vehicule == voiture.num_vehicule &&
                          ((strcmp(d, loue.date_debut) >= 0 && strcmp(d, loue.date_fin) <= 0) ||
                           (strcmp(d_r, loue.date_debut) >= 0 && strcmp(d_r, loue.date_fin) <= 0) ||
                           (strcmp(d, loue.date_debut) <= 0 && strcmp(d_r, loue.date_fin) >= 0))) {
                          // La plage de dates intersecte avec une location existante, donc le véhicule n'est pas disponible
                          vehi_dispo = 0;
                          break; // Pas besoin de vérifier d'autres locations pour ce véhicule
                      }
                  }
                  // Si le véhicule est disponible, afficher ses informations
                  if (vehi_dispo == 1) {
                      // Afficher les informations du véhicule
                      printf("%-10d %-10s %-20s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",
                             voiture.num_vehicule, voiture.marque, voiture.modele, voiture.annee,
                             voiture.immatriculation, voiture.kilometrage,
                             voiture.carburant, voiture.loue, 
                             voiture.statut, voiture.Etat, voiture.prix, voiture.caution);
                  }
              }
          }
          printf("-----------------------------------------------------------\n");
      }
}

//-----------------------------------------------------------------
void affichage_vehicule_indispo() {
  int i;
  struct vehicules voiture;

  // Vérifier s'il y a des véhicules à afficher
  if (nbvehicule == 0) {
      printf("Aucun véhicule à afficher\n");
  } else {
      printf("-----------------------------------------------------------\n");
      printf("%-10s %-10s %-20s %-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s %5s\n",
             "Numéro","Marque", "Modèle", "Année", "Immatriculation", "Kilométrage",
             "Carburant", "loue", "Statut", "État", "Prix","Caution");
      printf("-----------------------------------------------------------\n");

      // Boucle d'affichage
      for (i = 0; i < nbvehicule; i++) {
          voiture = tabvehicule[i];
          if ((strcmp(voiture.statut, "EN COURS") == 0) && (strcmp(voiture.loue, "OUI")== 0)) {
              printf("%-10d %-10s %-20s %-10d %-15s %-10d %-10s %-10s %-10s %-10s %-10d %5d\n",
                     voiture.num_vehicule,voiture.marque, voiture.modele, voiture.annee,
                     voiture.immatriculation, voiture.kilometrage,
                     voiture.carburant, voiture.loue, 
                     voiture.statut, voiture.Etat, voiture.prix, voiture.caution);
          }
      }
      printf("-----------------------------------------------------------\n");
  }
}
//----------------------------------------------------------------------------
int VehiculeDispo(char d[], char d_r[], int i){
  struct vehicules voiture = tabvehicule[i];
  struct location loue;
  int j;
  int disponible =1;
  if (strcmp(voiture.statut, "DISPONIBLE") != 0){
    disponible = 0;
  }
  if ((strcmp(voiture.loue, "OUI") == 0) && (strcmp(voiture.statut,"DISPONIBLE")==0)) {

      for (j = 0; j < nblocation; j++) {
          loue = tabloc[j];
          if (loue.num_vehicule == voiture.num_vehicule &&
              ((strcmp(d, loue.date_debut) >= 0 && strcmp(d, loue.date_fin) <= 0) ||
               (strcmp(d_r, loue.date_debut) >= 0 && strcmp(d_r, loue.date_fin) <= 0) ||
               (strcmp(d, loue.date_debut) <= 0 && strcmp(d_r, loue.date_fin) >= 0))) {
              // La plage de dates intersecte avec une location existante, donc le véhicule n'est pas disponible
              disponible = 0;
              break; // Pas besoin de vérifier d'autres locations pour ce véhicule
          }
      }

  }

return disponible;

}
//-----------------------------------------------------------------------------
void saisie_location() 
{
    struct location loue;
    struct Assurance assu;
    int plaque; // Utilisé pour l'entrée de la plaque d'immatriculation
    int numero,ok,i,jeune_permis, days,stock,dispo;
    int jour,mois,annee,jourr,moisr,anneer;
    int date_valide_location = 0,date_valider_location =0;
    float decimal;
    char choix_affichage[10];


   //Saisie des dates de location et vérification
   while((date_valide_location == 0)||(date_valider_location == 0)){
     printf("Entrez la date de début de location souhaitée (JJ MM AAAA) : ");
     scanf("%d %d %d", &jour, &mois, &annee);
     date_valide_location = DateValideLocation(jour, mois, annee);
     printf("Entrez la date de fin de location souhaitée (JJ MM AAAA) : ");
     scanf("%d %d %d", &jourr, &moisr, &anneer);
     date_valider_location = DateValideLocation(jourr, moisr, anneer);
     if ((date_valide_location == 0) || (date_valider_location == 0)) {
         printf("Date invalide. Veuillez entrer des date valides.\n");
     }


   }
  char* date = format_date(jour, mois, annee);
  strcpy(loue.date_debut, date);
  char* dater = format_date(jourr, moisr, anneer);
  strcpy(loue.date_fin, dater);
  days = differenceJours(loue.date_debut, loue.date_fin);

    while(1){
        printf("Pour vous aider, voulez-vous afficher les véhicules disponibles à la location pour ces dates ? (Oui/Non) : ");
        scanf("%s", choix_affichage);
        conv_maj(choix_affichage);
        if(strcmp(choix_affichage,"OUI") == 0 || strcmp(choix_affichage,"O") == 0){
          affichage_vehicule_dispo_date( loue.date_debut, loue.date_fin);
          break;
        }
        else if(strcmp(choix_affichage,"NON") == 0 || strcmp(choix_affichage,"N") == 0){
            break;
        }
        else{
            printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
        }

    }


    while ((1)||(ok!=1)) 
  { // Boucle infinie qui sera interrompue par un "break"
      ok=0;
        printf("Entrez le numéro du véhicule ('0' pour terminer) : ");
        scanf("%d", &plaque); // Lire la plaque d'immatriculation


        // Vérifier si l'utilisateur souhaite terminer
        if (plaque== 0) 
    {
            break; // Sortir de la boucle
        }


        int v = recherche_numvehicule(plaque);


        if (v != -1) 
    { // Si le véhicule est trouvé
            struct vehicules voiture = tabvehicule[v];

                // Vérification de la disponibilité du véhicule
            dispo = VehiculeDispo(loue.date_debut,loue.date_fin,v);
            if (dispo == 0) {
                printf("Le véhicule n'est pas disponible pour la location pour ces dates.\n");
                break; // Sortir de la fonction de saisie de location
            }




            // Copier les informations du véhicule dans la structure de location
            strcpy(tabvehicule[v].loue, "OUI");  
          loue.num_vehicule=voiture.num_vehicule;
            strcpy(loue.marque, voiture.marque);
            strcpy(loue.modele, voiture.modele);
            strcpy(loue.immatriculation, voiture.immatriculation);
          loue.caution=voiture.caution;




            printf("Entrez le numéro client : ");
            scanf("%d", &numero); // Supposer que le numéro est un entier


            int n = recherche_numclient(numero);


            if (n != -1)
       { // Si le client est trouvé
                struct client individu = tabclient[n];


                // Copier les informations du client
                loue.num_client = individu.num_client;
                strcpy(loue.nom, individu.nom);
                strcpy(loue.prenom, individu.prenom);
                //Modification du prix par rapport aux jeunes permis
                jeune_permis=2024 -individu.annee_permis;
                if(jeune_permis<3)
                {
                  decimal=voiture.surtaxe_jeunepermis/100.0;
          loue.prix=voiture.prix*(1+decimal);

        }
        else
        {
            loue.prix=tabvehicule[v].prix;


        }

                ok=1;
                i=nblocation;
                loue.numero_loc=i+1;
                strcpy(loue.statut, "EN_COURS");
                tabloc[i++]=loue;


                float prix_assurance = saisie_assurance();
                float prix_option = saisie_option();

                if (prix_assurance > 0 ){
                    printf("Le prix de l'assurance sélectionnée est : %.2f par jour\n", prix_assurance);
                    for (int z=0;z<nbassurances;z++){
                        assu = tabassurances[z];
                        if (prix_assurance == assu.prix ){
                            strcpy(loue.nom_assurance,assu.nom);
                        }
                    }

                }

                if (prix_option > 0 ){
                    printf("Le prix de l'option sélectionnée est : %.2f par jour\n", prix_option);
                }
                loue.assurance = prix_assurance;
                loue.option = prix_option;
                loue.total = (loue.assurance+loue.option+loue.prix) * days;
                 stock = loue.total;
                 appliquerFidelite(&loue, individu);
                 individu.nblocation+=1;//incremente de 1 le nb location chez le clleint
                 a_sauvegarder =1;
                 tabclient[n]=individu;
                 tabloc[nblocation] = loue;
                 a_sauvegarderl = 1;
                if (ok==1){
                    break;
                }
            } 
      else 
      {
                printf("Numéro client non trouvé.\n");
            }
        } 
    else 
    {
            printf("Numéro du véhicule non trouvé.\n");
        }
    }

    if (ok == 1) {
    int reduction = stock-loue.total;
    printf("\nRécapitulatif de la location :\n");
    printf("------------------------------\n");
    printf("Véhicule loué :\n");
    printf("  - Immatriculation : %s\n", loue.immatriculation);  
    printf("  - Marque : %s\n", loue.marque);
    printf("  - Modèle : %s\n", loue.modele);
    printf("\nClient :\n");
    printf("  - Numéro client : %d\n", loue.num_client);
    printf("  - Nom : %s\n", loue.nom);
    printf("  - Prénom : %s\n", loue.prenom);
    printf("  - Numéro location : %d\n", loue.numero_loc);
    printf("\nDates de location :\n");
    printf("  - Début : %s\n", loue.date_debut);
    printf("  - Fin : %s\n", loue.date_fin);
    printf("- Nombres de jours de location : %d\n", days);
    printf("\nPrix de la location :\n");
    printf("  - Prix total : %d par jour\n", loue.prix); 
    printf("  - Prix de l'assurance : %.2f par jour\n", loue.assurance);
    printf("  - Prix de l'option : %.2f par jour\n", loue.option);
    printf("  - Reduction fidélité : %d\n",reduction); 
    printf("  - Prix total : %.2d\n", loue.total);
    crefacture(loue);
    a_sauvegarderf =1;
}
    nblocation++;
}

//--------------------------

void retour_vehicule() {   
    int numero_loc, i, nbrayure, nbdate,km,j;
    struct location loue;
    struct vehicules voiture;
    char plein[5], rayure[5], date[5], rep[5], netat[100],immatriculation[100];
    float sup = 0, diff;
    bool verif = false;

    printf("Entrez le numéro de location pour restituer le véhicule : ");
    scanf("%d", &numero_loc);

    // Recherche de la location par son numéro
    for (i = 0; i < nblocation; i++) {
        if (tabloc[i].numero_loc == numero_loc && strcmp(tabloc[i].statut, "EN_COURS") == 0) {
            verif = true;
            // Mettre à jour le statut de la location
            strcpy(tabloc[i].statut, "TERMINÉ");
            loue = tabloc[i];

            strcpy(immatriculation, loue.immatriculation);

            // Recherche du véhicule dans le tableau à partir de l'immatriculation
            for (j = 0; j < nbvehicule; j++) {
                if (strcmp(tabvehicule[j].immatriculation, immatriculation) == 0) {
                    voiture = tabvehicule[j];
                    break;  
                }
            }

          printf("----------------------------------\n");

            while (1) {
                printf("Le plein a-t-il été fait ? (Oui/Non) : ");
                scanf("%s", plein);
                conv_maj(plein);
                if (strcmp(plein, "OUI") == 0 || strcmp(plein, "O") == 0) {
                    printf("Le plein a été fait. Merci !\n");
                    break;
                } else if (strcmp(plein, "NON") == 0 || strcmp(plein, "N") == 0) {
                    sup = sup + 50;
                    printf("le plein n'est pas fait, supplément de : %f euros\n", sup);
                    break;
                } else {
                    printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
                }
            }


          printf("----------------------------------\n");



            while (1) {
                printf("La voiture présente des dommages, rayures ? (Oui/Non) : ");
                scanf("%s", rayure);
                conv_maj(rayure);
                if (strcmp(rayure, "OUI") == 0 || strcmp(rayure, "O") == 0) {
                    printf("Entrez le nombre de rayures: ");
                    scanf("%d", &nbrayure);
                    if (loue.assurance>0){
                        printf("le client possède une assurance:%s ,Voulez-vous le sanctionner ? (Oui/Non) : ",loue.nom_assurance);
                        scanf("%s", rep);
                        conv_maj(rep);
                        if (strcmp(rep, "OUI") == 0 || strcmp(rep, "O") == 0) {
                            sup = sup + nbrayure * 10;
                            printf("Supplément de: 10 euros par rayures\n");
                        }
                        else if ((strcmp(rep, "N") == 0) || (strcmp(rep, "NON")) == 0) {
                            printf("Pas de dommage, le client possède une assurance\n");
                        }
                        else {
                            printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
                        }

                    }
                    else{
                        printf("Supplément de: 10 euros par rayures\n");
                        sup = sup + nbrayure * 10;
                    }
                    break;
                } else if (strcmp(rayure, "NON") == 0 || strcmp(rayure, "N") == 0) {
                    printf("Pas de dommage\n");
                    break;
                } else {
                    printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
                }
            }
            printf("----------------------------------\n");
            while (1) {
                printf("La date de retour est prévu pour le: %s\n",loue.date_fin);
                afficher_date();
                printf("La voiture est restituée à la bonne date ? (Oui/Non) : ");
                scanf("%s", date);
                conv_maj(date);
                if (strcmp(date, "NON") == 0 || strcmp(date, "N") == 0) {
                    printf("Entrez le nombre de jour(s) supplémentaire(s): ");
                    scanf("%d", &nbdate);
                    sup = sup + nbdate * 100;
                    printf("En retard, supplément de: 100 euros par jour\n");
                    break;
                } else if (strcmp(date, "OUI") == 0 || strcmp(date, "O") == 0) {
                    printf("Pas de retard\n");
                    break;
                } else {
                    printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
                }
            }
            printf("----------------------------------\n");
            while (1) {
                printf("L'Etat du véhicule avant la location : %s\n",voiture.Etat);
                printf("Le véhicule est restitué dans un état équivalent ? (Oui/Non) : ");
                scanf("%s", date);
                conv_maj(date);
                if (strcmp(date, "NON") == 0 || strcmp(date, "N") == 0) {
                    printf("Entrez le nouvel état du véhicule : ");
                    scanf("%s", netat);
                    conv_maj(netat);
                    strcpy(voiture.Etat,netat);
                    break;
                } else if (strcmp(date, "OUI") == 0 || strcmp(date, "O") == 0) {
                    break;
                } else {
                    printf("Choix invalide, veuillez répondre par 'oui' ou 'non'\n");
                }
            }

           printf("----------------------------------\n");
           printf("Km du véhicule au compteur avant la location : %d\n",voiture.kilometrage);
           printf("Entrez le nombre de km au compteur lors de la restitution: ");
           scanf("%d", &km);
           voiture.kilometrage = km;







            // Mettre à jour le statut de la location
            printf("----------------------------------\n");
            if (sup>0){
                printf("Client sanctionné de: %f euros (en moins sur la caution)\n", sup);
            }
            if (loue.caution - sup >0){
                printf("La caution à restituer au client est: %f euros\n", loue.caution - sup);
            }
            else{
                diff = sup - loue.caution;
                printf("Le client ne perçoit pas de caution et doit payer un supplément de: %f euros\n",diff);
            }

            
            strcpy(tabloc[i].statut, "TERMINÉ");
            printf("La location avec le numéro %d a été marquée comme terminée avec succès.\n", numero_loc);
      a_sauvegarderl = 1;
      a_sauvegarderv = 1;
      tabloc[i] = loue;
      tabvehicule[j] = voiture;
        }
            


        }

    if (!verif){
        printf("Aucune location avec le numéro %d n'est actuellement en cours.\n", numero_loc);
        
    }
    
 }

//---------------------------

float saisie_assurance() {
    struct Assurance assu;
    struct location loc;
    char choix_nom[100];
    bool trouve = false;

    printf("Voulez-vous souscrire une assurance ? (O/N) : ");
    char choix;
    scanf(" %c", &choix);

    if (choix == 'O' || choix == 'o') {
        affichage_assurance();
        while (!trouve) {
            printf("Entrez le nom de l'assurance : ");
            scanf("%s", choix_nom);
            conv_maj(choix_nom);

            for (int i = 0; i < nbassurances; i++) {
                if (strcmp(choix_nom, tabassurances[i].nom) == 0) {
                    trouve = true;
                    return tabassurances[i].prix;
                }
            }
            printf("Assurance non trouvée. Veuillez réessayer.\n");
        }
    }
    return 0.0;
}

// Fonction pour la saisie de l'option
float saisie_option() {
    struct Option op;
    char choix_nom[100];
    bool trouve = false;

    printf("Voulez-vous sélectionner une option ? (O/N) : ");
    char choix;
    scanf(" %c", &choix);

    if (choix == 'O' || choix == 'o') {
        affichage_option();
        while (!trouve) {
            printf("Entrez le nom de l'option : ");
            scanf("%s", choix_nom);
            conv_maj(choix_nom);

            for (int i = 0; i < nboptions; i++) {
                if (strcmp(choix_nom, taboptions[i].nom) == 0) {
                    trouve = true;
                    return taboptions[i].prix;
                }
            }
            printf("Option non trouvée. Veuillez réessayer.\n");
        }
    }
    return 0.0;
}

//--------------------------

void ajouter_option() {
    int i;
    struct Option op;

    // Boucle de saisie
    i = nboptions;
    while (strcmp(op.nom, "FIN") != 0) {
        printf("Nom de l'option (FIN pour terminer) : ");
        scanf("%s", op.nom);
        conv_maj(op.nom);

        if (strcmp(op.nom, "FIN") != 0) {
            printf("Prix de l'option par jour : ");
            scanf("%f", &op.prix);


            taboptions[i++] = op;
            a_sauvegarder_option = 1;
        }
    }
    nboptions = i;
}

void ajouter_assurance() {
    struct Assurance assu;
    int i;

        // Boucle de saisie
    i = nbassurances;
    while (strcmp(assu.nom, "FIN") != 0) {
        printf("Nom de l'assurance (FIN pour terminer) : ");
        scanf("%s", assu.nom);
        conv_maj(assu.nom);

        if (strcmp(assu.nom, "FIN") != 0) {
            printf("Prix de l'assurance par jour : ");
            scanf("%f", &assu.prix);


            tabassurances[i++] = assu;
            a_sauvegarder_assurance = 1;
        }
    }
    nbassurances = i;


}

void affichage_assurance()
{
  int i ;
  struct Assurance assu;

  if (nbassurances == 0)
  {
    printf("Aucune assurance à afficher\n");
  }
  else
  {
    printf("-------------------------------------\n");
    printf("%-10s %6s\n","NOM","PRIX");
    printf("-------------------------------------\n");
    // Boucle d'affichage
    for (i=0 ; i< nbassurances ; i++)
    {
      assu = tabassurances[i];
      printf("%-10s %6.2f\n",assu.nom,assu.prix);
    } 
    printf("-------------------------------------\n"); 
  }
}


void affichage_option()
{
  int i ;
  struct Option op;

  if (nboptions == 0)
  {
    printf("Aucune option à afficher\n");
  }
  else
  {
    printf("-------------------------------------\n");
    printf("%-10s %6s\n","NOM","PRIX");
    printf("-------------------------------------\n");
    // Boucle d'affichage
    for (i=0 ; i< nboptions ; i++)
    {
      op = taboptions[i];
      printf("%-10s %6.2f\n",op.nom,op.prix);
    } 
    printf("-------------------------------------\n"); 
  }
}

void sauvegarde_option()
{
  int i ;
  struct Option op;
  FILE *f1;
  char NomFichier[TAILLE_NOM_F];

  if (nboptions == 0)
  {
    printf("Aucune option à sauvegarder\n");
  }
  else
  {
    // ouverture du fichier
    strcpy(NomFichier, "options.txt");
    f1 = fopen(NomFichier,"w");
    // Boucle de sauvegarde
    for (i=0 ; i< nboptions ; i++)
    {
      op = taboptions[i];
      fprintf(f1,"%s %f\n",op.nom,op.prix);
    }
    fclose(f1); 
    printf("%d Options sauvegardées\n",nboptions);
    a_sauvegarder_option=0;
  }
}
void verif_sauvegarde_option(){
    char reponse2[10];
    if (a_sauvegarder_option)
  {
    printf("Des données sur les Options ont été modifiées\n");
    printf("Voulez-vous faire une sauvegarde (o/n) : ");
    scanf("%s",reponse2);
    conv_maj(reponse2);

    if (reponse2[0] == 'O')
       sauvegarde_option();
  }
}

void sauvegarde_assurance()
{
  int i ;
  struct Assurance assu;
  FILE *f1;
  char NomFichier[TAILLE_NOM_F];

  if (nbassurances == 0)
  {
    printf("Aucune Assurance à sauvegarder\n");
  }
  else
  {
    // ouverture du fichier
    strcpy(NomFichier, "assurance.txt");
    f1 = fopen(NomFichier,"w");
    // Boucle de sauvegarde
    for (i=0 ; i< nbassurances ; i++)
    {
      assu = tabassurances[i];
      fprintf(f1,"%s %f\n",assu.nom,assu.prix);
    }
    fclose(f1); 
    printf("%d Assurances sauvegardées\n",nbassurances);
    a_sauvegarder_assurance=0;
  }
}
void verif_sauvegarde_assurance(){
    char reponse2[10];
    if (a_sauvegarder_assurance)
  {
    printf("Des données sur les assurances ont été modifiées\n");
    printf("Voulez-vous faire une sauvegarde (o/n) : ");
    scanf("%s",reponse2);
    conv_maj(reponse2);

    if (reponse2[0] == 'O')
       sauvegarde_assurance();
  }
}
// ------------------------------------
void chargement_option()
{
  int i, retour ;
  struct Option op;
  FILE *f1;
  char NomFichier[TAILLE_NOM_F];

  // Boucle de chargement
  i=0 ;
  strcpy(NomFichier, "options.txt");
  f1 = fopen(NomFichier,"r");
  if (f1 != NULL) {
  while(! feof(f1))
  {
    retour = fscanf(f1,"%s %f",op.nom,&op.prix);
    if (retour != EOF) 
    {
      conv_maj(op.nom);
      taboptions[i++] = op;
    }
  }
  fclose(f1);
  nboptions = i ;
  printf("%d Options chargées\n",nboptions);
  } 
  else {
        printf("Erreur lors de l'ouverture du fichier pour chargement des options.\n");
    }
}

void chargement_assurance()
{
  int i, retour ;
  struct Assurance assu;
  FILE *f1;
  char NomFichier[TAILLE_NOM_F];

  // Boucle de chargement
  i=0 ;
  strcpy(NomFichier, "assurance.txt");
  f1 = fopen(NomFichier,"r");
  if (f1 != NULL) {
  while(! feof(f1))
  {
    retour = fscanf(f1,"%s %f",assu.nom,&assu.prix);
    if (retour != EOF) 
    {
      conv_maj(assu.nom);
      tabassurances[i++] = assu;
    }
  }
  fclose(f1);
  nbassurances = i ;
  printf("%d Assurances chargées\n",nbassurances);
  } 
  else {
        printf("Erreur lors de l'ouverture du fichier pour chargement des options.\n");
    }
}

void initialiserFidelite()
 {
    printf("Combien de niveaux de fidélité voulez-vous définir? (Maximum %d) ", MAX_FIDELITE);
    scanf("%d", &nbNiveaux);
    if (nbNiveaux > MAX_FIDELITE) 
  {
        printf("Nombre de niveaux limité à %d.\n", MAX_FIDELITE);
        nbNiveaux = MAX_FIDELITE;
    }

    for (int i = 0; i < nbNiveaux; i++) 
  {
        printf("Entrez le seuil de locations pour le niveau %d: ", i + 1);
        scanf("%d", &niveauxFidelite[i].seuilLocations);
        printf("Entrez la réduction (en pourcentage) pour le niveau %d: ", i + 1);
        scanf("%f", &niveauxFidelite[i].reduction);
    }
    verif_fide=1;
}

void appliquerFidelite(struct location *loue, struct client individu) 
{
    float reduction = 0.0;

    // Trouver la réduction applicable basée sur le nombre de locations du client
    for (int i = 0; i < nbNiveaux; i++) 
  {
        if (individu.nblocation >= niveauxFidelite[i].seuilLocations) 
    {
            reduction = niveauxFidelite[i].reduction;
        }
    }

    // Appliquer la réduction au prix de la location si une réduction est trouvée
    if (reduction > 0) 
  {
        loue->total = loue->total * (1 - (reduction / 100.0));
        printf("Une réduction de %.2f%% a été appliquée. Nouveau prix: %d\n", reduction, loue->total);
    }
}

// Si on veut avoir la date du jour

void afficher_date() {
    // Obtenir l'heure actuelle
    time_t temps_actuel;
    struct tm *temps_info;
    char date_format[11]; // 10 caractères pour la date + 1 pour le caractère nul

    time(&temps_actuel);
    temps_info = localtime(&temps_actuel);

    // Formater la date
    strftime(date_format, sizeof(date_format), "%d/%m/%Y", temps_info);

    // Afficher la date
    printf("Date du jour : %s\n", date_format);
}
//---------------------------------------------
void crefacture(struct location loc)
{

struct facture fac;
// Initialiser le générateur de nombres aléatoires
    srand(time(NULL));  
  time_t maintenant;
  time(&maintenant);

  // Convertir en heure locale
  struct tm *infoTemps;
  infoTemps = localtime(&maintenant);

  // Créer une variable pour stocker la date sous forme de chaîne
  char dateAujourdhui[11];  // Assurez-vous que le tableau est suffisamment grand

  // Formatter la date dans la chaîne (format AAAA-MM-JJ)
  sprintf(dateAujourdhui, "%02d/%02d/%04d",infoTemps->tm_mday, infoTemps->tm_mon + 1,  infoTemps->tm_year + 1900);

    // Générer un nombre aléatoire 

fac.num_facture=rand() % (100*loc.numero_loc);
fac.numero_loc=loc.numero_loc;
fac.option=loc.option;
fac.prixj=loc.prix;
fac.total=loc.total;
fac.assurance=loc.assurance;
fac.caution=loc.caution;
strcpy(fac.marque, loc.marque);
strcpy(fac.modele, loc.modele);
strcpy(fac.prenom, loc.prenom);
strcpy(fac.nom, loc.nom);
strcpy(fac.date_debut, loc.date_debut);
strcpy(fac.date_fin, loc.date_fin);
strcpy(fac.date_facture, dateAujourdhui);


tabfacture[nbfacture++]= fac;


}
//---------------------------------------------------------
void historique_affichage_facture()
{
    if (nbfacture == 0) {
        printf("Aucune facture à afficher\n");
    } else {
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("%-15s %-20s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
               "Numéro Facture", "Numéro Location", "Nom", "Prénom", "Option (€)", "Assurance (€)", "Caution (€)", "Prix (€)","Prix H.T(€)" " Date Début", "Date Fin");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < nbfacture; i++) {
            struct facture fac = tabfacture[i];
            float prix_ht = fac.total * 0.8; // Calcul du prix hors taxes avec une réduction de 20%
            printf("%-15d %-18d %-15s %-15s %-15.2f %-13.2f %-13d %-10d %-13.2f %-15s %-15s\n",
                   fac.num_facture, fac.numero_loc, fac.nom, fac.prenom, fac.option, fac.assurance, fac.caution,fac.total,prix_ht, fac.date_debut, fac.date_fin);
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

//-----------------------------------------------
void sauvegarder_facture(){
  int i;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  if (nbfacture == 0) {
      printf("Aucune factures à sauvegarder\n");
  } else {
      // Ouverture du fichier
      strcpy(NomFichier, "factures.txt");
      fichier = fopen(NomFichier, "w");

      // Boucle de sauvegarde
      for (i = 0; i < nbfacture; i++) {
          fprintf(fichier, "%d %d %s %s %f %f %d %d %s %s %d %s %s %s\n",
                  tabfacture[i].num_facture, tabfacture[i].numero_loc, tabfacture[i].nom,
                  tabfacture[i].prenom, tabfacture[i].option, tabfacture[i].assurance,
                  tabfacture[i].caution, tabfacture[i].total, tabfacture[i].date_debut,
                  tabfacture[i].date_fin,tabfacture[i].prixj,tabfacture[i].marque,tabfacture[i].modele,tabfacture[i].date_facture);
      }
      fclose(fichier);
      printf("%d factures sauvegardés\n", nbfacture);
      a_sauvegarderl = 0;
  }

}
//----------------------------------------------------------------
void chargement_facture(){
  int i, retour;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  // Boucle de chargement
  i = 0;
  strcpy(NomFichier, "factures.txt");
  fichier = fopen(NomFichier, "r");
  if (fichier != NULL) {
      while (!feof(fichier)) {
          retour = fscanf(fichier, "%d %d %s %s %f %f %d %d %s %s %d %s %s %s\n",                  
              &tabfacture[i].num_facture, &tabfacture[i].numero_loc, tabfacture[i].nom,
                tabfacture[i].prenom, &tabfacture[i].option, &tabfacture[i].assurance,
                &tabfacture[i].caution, &tabfacture[i].total, tabfacture[i].date_debut,
                tabfacture[i].date_fin,&tabfacture[i].prixj,tabfacture[i].marque,tabfacture[i].modele,tabfacture[i].date_facture);



          if (retour != EOF) { // La fin du fichier n'a pas été atteinte par fscanf()
              i++;
          }
      }
      fclose(fichier);
      nbfacture = i;
      printf("%d factures chargées\n", nbfacture);
  } else {
      printf("Erreur lors de l'ouverture du fichier pour chargement des loactions.\n");
  }

}
//----------------------------------------------------------------
void verif_sauvegarde_facture(){
  char reponse3[10];
  if (a_sauvegarderf)
  {
  printf("Des factures ont été créées\n");
  printf("Voulez-vous faire une sauvegarde (o/n) : ");
  scanf("%s",reponse3);
  conv_maj(reponse3);
  

  if (reponse3[0] == 'O')
     sauvegarder_facture();
  }

}
//----------------------------------------------------------------
    void verif_sauvegarde_fidelite(){
      char reponse3[10];
      if (verif_fide)
      {
      printf("Des fidélités ont été créées\n");
      printf("Voulez-vous faire une sauvegarde (o/n) : ");
      scanf("%s",reponse3);
      conv_maj(reponse3);

      if (reponse3[0] == 'O')
         sauvegarder_fidelite();
      }

    }

//-----------------------------------------------

void generer_facture()
{
    int i, recherche, verif, as = 0, prix;
    char nom[100], voiture[100], date[22];
    int stock, days;

    printf("Quel est le numéro de location de la facture que vous voulez générer ? : ");
    scanf("%d", &recherche);
    verif = recherche_numloc(recherche);
    if (verif == -1)
    {
        printf("Le numéro de location n'existe pas\n");
    }
    else
    {
        struct facture fac = tabfacture[verif];
        days = differenceJours(fac.date_debut, fac.date_fin);
        stock = (fac.assurance + fac.option + fac.prixj) * days;
        strcpy(nom, fac.nom);
        strcat(nom, " ");
        strcat(nom, fac.prenom);
        strcpy(voiture, fac.marque);
        strcat(voiture, " ");
        strcat(voiture, fac.modele);
        as = fac.assurance + fac.option;
        prix = fac.total - as;
        float prix_ht = prix * 0.8; // Calcul du prix hors taxes avec une réduction de 20%
        strcpy(date, fac.date_debut);
        strcat(date, " ");
        strcat(date, fac.date_fin);
        int fidelite = stock - fac.total;
        // Affichage de l'en-tête de la facture
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n                                                           FACTURE CLIENT                                                     \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("NUMERO DE FACTURE : %d\n", fac.num_facture);
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");

        
        printf("Client: %s \n", nom);

        
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");

      
        printf("%-20s %-30s %-25s %-25s %-25s %-25s\n", "Véhicule", "Date de location", "Prix assurance/option", "Prix journalier location", "Prix total HT", "Prix total TTC");

       
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");

        

        printf("%-20s %-30s %-25.2d %-25.2d %-25.2f %-25.2d\n",
               voiture,                     // 'voiture' contient modèle et marque
               date,                        // Date de location
               as,                          // Prix combiné de l'assurance et de la caution
               fac.prixj,
               prix_ht,                    // Prix total hors taxes
               fac.total);                 // Prix total TTC

        
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n             Caution                   Fidelite                               Prix Total                                      \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("              %d                         %d                                     %d                                              \n", fac.caution, fidelite, fac.total);
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    }
}


void infosclient()	
{

  int numero,i;
    struct client client_mod;
    int numRecherche;

  printf("-------------------------------------\n");
    printf("%-10s %-10s %-20s\n","NUMERO","NOM","PRENOM"); //si pas de réservation en cours num de réservation = null
    printf("-------------------------------------\n");
    // Boucle d'affichage
    for (i=0 ; i< nbreclient ; i++)
    {
      client_mod = tabclient[i];
      printf("%-10d %-10s %-20s\n",client_mod.num_client,client_mod.nom,client_mod.prenom);
    } 
    printf("-------------------------------------\n"); 

    printf("Numéro client du client à afficher : ");
    scanf("%d", &numRecherche);
    numero = recherche_numclient(numRecherche);
    if (numero == NON_TROUVE) {
        printf("%d pas trouvé\n", numRecherche);
    } else {
      client_mod = tabclient[numero];
            printf("-------------------------------------\n");
    printf("%-10s %-10s %-20s %-11s %-10s %-6s %-20s %10s %-30s\n","NUMERO","NOM","PRENOM","AGE","numero de permis","Anne de permis","mail","telephone","Adresse"); //si pas de réservation en cours num de réservation = null
    printf("-------------------------------------\n");
    printf("%-10d %-10s %-20s %-11s %-10s %-6d  %-20s %10s %-30s\n",client_mod.num_client,client_mod.nom,client_mod.prenom,client_mod.date_de_naissance,client_mod.num_permis,client_mod.annee_permis,client_mod.mail,client_mod.telephone,client_mod.adresse);

    printf("-------------------------------------\n");
}
}


void affichage_historiquev()
{

int i;
struct historique_vehicule voiture;

if (nbhistoriquev == 0) {
    printf("Aucun véhicule à afficher\n");
} else {
    printf("-----------------------------------------------------------\n");
    printf("%-10s %-10s %-20s %-10s %-15s %-10s %-10s\n","Numéro",
           "Marque", "Modèle", "Année", "Immatriculation", "Kilométrage","Date Suppresseion"
           );
    printf("-----------------------------------------------------------\n");

    // Boucle d'affichage
    for (i = 0; i < nbhistoriquev; i++) {
        voiture = historique_vehicule[i];
        printf("%-10d %-10s %-20s %-10d %-15s %-10d %-10s\n",voiture.num_vehicule,
               voiture.marque, voiture.modele, voiture.annee,
               voiture.immatriculation, voiture.kilometrage,
               voiture.date_suppressions);


    printf("-----------------------------------------------------------\n");
    }
}
}
void convertir_historiquev(struct vehicules vehicule)
{
  struct historique_vehicule historique;
  time_t maintenant;
  time(&maintenant);

  // Convertir en heure locale
  struct tm *infoTemps;
  infoTemps = localtime(&maintenant);

  // Créer une variable pour stocker la date sous forme de chaîne
  char dateAujourdhui[11];  // Assurez-vous que le tableau est suffisamment grand

  // Formatter la date dans la chaîne (format AAAA-MM-JJ)
  sprintf(dateAujourdhui, "%02d/%02d/%04d",infoTemps->tm_mday, infoTemps->tm_mon + 1,  infoTemps->tm_year + 1900);

  // Copier les informations du véhicule dans l'historique
  historique.num_vehicule = vehicule.num_vehicule;
  strcpy(historique.marque, vehicule.marque);
  strcpy(historique.modele, vehicule.modele);
  historique.annee = vehicule.annee;
  strcpy(historique.immatriculation, vehicule.immatriculation);
  historique.kilometrage = vehicule.kilometrage;
  strcpy(historique.date_suppressions, dateAujourdhui);
  // Ajouter l'historique au tableau
  historique_vehicule[nbhistoriquev++] = historique;
}

void convertir_historiquec(struct client client){
  struct historique_client historique;
  time_t maintenant;
  time(&maintenant);
  // Convertir en heure locale
  struct tm *infoTemps;
  infoTemps = localtime(&maintenant);
  // Créer une variable pour stocker la date sous forme de chaîne
  char dateAujourdhui[11];

  sprintf(dateAujourdhui, "%02d/%02d/%04d",infoTemps->tm_mday, infoTemps->tm_mon + 1,  infoTemps->tm_year + 1900);
  // Copier les informations du client dans l'historique
  historique.num_client = nbhistoriquec +1;//numéro de suppression
  strcpy(historique.nom, client.nom);
  strcpy(historique.prenom, client.prenom);
  strcpy(historique.adresse, client.adresse);
  strcpy(historique.mail, client.mail);
  strcpy(historique.telephone, client.telephone);
  strcpy(historique.date_de_naissance, client.date_de_naissance);
  strcpy(historique.num_permis, client.num_permis);
  historique.annee_permis = client.annee_permis;  
  strcpy(historique.date_suppressions, dateAujourdhui);
  // Ajouter l'historique au tableau
  historique_client[nbhistoriquec++] = historique;

}

 void affichage_historiquec()
    {
  int i,RGPD;//verifie si la date de suppression excede les 30 jours
  struct historique_client client;
  time_t maintenant;
  time(&maintenant);
      // Convertir en heure locale
  struct tm *infoTemps;
  infoTemps = localtime(&maintenant);
      // Créer une variable pour stocker la date sous forme de chaîne
  char dateAujourdhui[11];

      sprintf(dateAujourdhui, "%02d/%02d/%04d",infoTemps->tm_mday, infoTemps->tm_mon + 1,  infoTemps->tm_year + 1900);
  

      if (nbhistoriquec == 0) {
          printf("Aucun client à afficher\n");
      } else {
          printf("--------------------------------------------------------------------------------------\n");
          printf("%-10s %-10s %-15s %-15s %-25s %-20s %-10s\n","Numéro",
                 "Nom", "Prenom", "Mail", "Telephone","Adresse","Date Suppresseion"
                 );
        printf("--------------------------------------------------------------------------------------\n");

          // Boucle d'affichage
          for (i = 0; i < nbhistoriquec; i++) {
              client = historique_client[i];
           RGPD= differenceJours(client.date_suppressions,dateAujourdhui);
              if(RGPD>0)
              {
                for (int j = i; j < nbhistoriquec - 1; j++) {
                  historique_client[j] = historique_client[j + 1];
                }
                nbhistoriquec--;
              }
            else
              {


              printf("%-8d %-12s %-10s %-20s %-15s %-25s %-5s\n",client.num_client,
                     client.nom, client.prenom,client.mail, client.telephone,client.adresse,
                     client.date_suppressions);


              printf("--------------------------------------------------------------------------------------\n");
              }
          }
      }

    }

void chargement_fidelite() {
    FILE *fichier;
    char NomFichier[TAILLE_NOM_F];
    int retour;
    int i = 0; 

    // Ouverture du fichier
    strcpy(NomFichier, "fidelite.txt");
    fichier = fopen(NomFichier, "r");

    if (fichier != NULL) {

        while (!feof(fichier)) {
            retour = fscanf(fichier,"%d %f\n",
              &niveauxFidelite[i].seuilLocations, &niveauxFidelite[i].reduction);
            if (retour != EOF) {
                i++;
            }
        }
          nbNiveaux = i; 
        fclose(fichier);
        printf("%d fidélités chargés\n", nbNiveaux);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement des fidélités.\n");
    }
}

char* format_date(int j, int m, int a) {
    static char format[11]; // Tableau pour stocker la date formatée (jj/mm/aaaa\0)
    format[0] = (j / 10) + '0';
    format[1] = (j % 10) + '0';
    format[2] = '/';
    format[3] = (m / 10) + '0';
    format[4] = (m % 10) + '0';
    format[5] = '/';
    format[6] = (a / 1000) + '0';
    format[7] = ((a % 1000) / 100) + '0';
    format[8] = ((a % 100) / 10) + '0';
    format[9] = (a % 10) + '0';
    format[10] = '\0';
    return format; // Retourner la date formatée
}

int DateValide(int j, int m, int a) {
    if (m < 1 || m > 12)
        return 0;
    if (j < 1)
        return 0;
    if (a < 0 || a > 2025) 
        return 0;
  switch (m) {
      case 2:
          if (estBissextile(a)) {
              if (j <= 29) {
                  return 1; 
              } 
              else {
                  return 0; 
              }
          } else {
              if (j <= 28) {
                  return 1; 
              }
              else{
                  return 0; 
              }
          }
      case 4: case 6: case 9: case 11:
          if (j <= 30) {
              return 1; 
          }
          else {
              return 0; 
          }
      default:
          if (j <= 31) {
              return 1; 
          }
          else{
              return 0; 
          }
  }


}

bool estBissextile(int annee) {
      if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
          return true;
      }
      return false;
  }

  int DateValideLocation(int j, int m, int a) {
      int date = DateValide(j, m, a);
      if (date == 0) {
          return 0;
      }
      else {
          time_t temps_actuel = time(NULL);
          struct tm *date_actuelle = localtime(&temps_actuel);
          int jour_actuel = date_actuelle->tm_mday;
          int mois_actuel = date_actuelle->tm_mon + 1;
          int annee_actuelle = date_actuelle->tm_year + 1900;

          if (a < annee_actuelle)
              return 0;
          if (a == annee_actuelle && m < mois_actuel)
              return 0;
          if (a == annee_actuelle && m == mois_actuel && j < jour_actuel)
              return 0;

          return 1; 
      }
  }


time_t convertirDateEnTime_t(char *date) {
    struct tm tm_date = {0};
    sscanf(date, "%d/%d/%d", &tm_date.tm_mday, &tm_date.tm_mon, &tm_date.tm_year);
    tm_date.tm_mon -= 1;  // Les mois en tm sont de 0 à 11
    tm_date.tm_year -= 1900;  // Les années en tm sont depuis 1900
    tm_date.tm_isdst = -1;  // Informations sur l'heure d'été/d'hiver non définies

    return mktime(&tm_date);
}
time_t convertirDateEnTime_tsuppr(char *date) {
    struct tm tm_date = {0};
    sscanf(date, "%d-%d-%d", &tm_date.tm_mday, &tm_date.tm_mon, &tm_date.tm_year);
    tm_date.tm_mon -= 1;  // Les mois en tm sont de 0 à 11
    tm_date.tm_year -= 1900;  // Les années en tm sont depuis 1900
    tm_date.tm_isdst = -1;  // Informations sur l'heure d'été/d'hiver non définies

    return mktime(&tm_date);
}
// Calcule la différence en jours entre deux dates
int differenceJours(char *date_debut, char *date_fin) {
    time_t t_debut = convertirDateEnTime_t(date_debut);
    time_t t_fin = convertirDateEnTime_t(date_fin);

    double seconds = difftime(t_fin, t_debut);
    int days = (int)(seconds / (3600 * 24));  // Convertit les secondes en jours

    return days;
}
void reintegre_cleint()
{
  struct client client;
  struct historique_client historique;
  int i,numero,recherche,max=0;
  
if (nbhistoriquec == 0) {
    printf("Aucun client à afficher\n");
}
else
{
  affichage_historiquec();
  printf("Numéro de client à réintégrer : ");
  scanf("%d", &numero);
  recherche = recherche_numsuppression(numero);
  if (recherche == NON_TROUVE) {
      printf("%d pas trouvé\n", recherche);
  } else {
      historique = historique_client[recherche];
      strcpy(client.nom, historique.nom);
      strcpy(client.prenom, historique.prenom);
      strcpy(client.adresse, historique.adresse);
      strcpy(client.mail, historique.mail);
      strcpy(client.telephone, historique.telephone);
      strcpy(client.date_de_naissance, historique.date_de_naissance);
      strcpy(client.num_permis, historique.num_permis);
      client.annee_permis = historique.annee_permis;
    for(i=0;i<nbreclient;i++)
      {
        if(max<tabclient[i].num_client)
        {
          max=tabclient[i].num_client;
        }
      }
    client.num_client = max+1;
    tabclient[nbreclient++]=client;
    for (i= recherche; i < nbhistoriquec - 1; i++) {
      historique_client[i] = historique_client[i + 1];
    }
    nbhistoriquec--;
    a_sauvegarder=1;
  }
}

}
void compte_30jours()
{
  int i,verif=0,conta=0,nbloc=0;
  struct facture facture;
  time_t maintenant;
  time(&maintenant);
      // Convertir en heure locale
  struct tm *infoTemps;
  infoTemps = localtime(&maintenant);
      // Créer une variable pour stocker la date sous forme de chaîne
  char dateAujourdhui[11];

  sprintf(dateAujourdhui, "%02d/%02d/%04d", infoTemps->tm_mday,infoTemps->tm_mon + 1,  infoTemps->tm_year + 1900);

    
if(nbfacture==0){
  printf("Aucune facture à afficher\n");
}
else{  
  for(i=0;i<nbfacture;i++)
    {
      facture=tabfacture[i];
      verif=differenceJours(facture.date_facture, dateAujourdhui);
      if(verif<30)
      {
        conta+=facture.total;
        nbloc+=1;
      }
    }
  printf("------------------------------------------------------\n");
  printf("%-50s %-50s\n","Location faite","Chiffre d'affaire");
  printf("------------------------------------------------------\n");
  printf("%-50d %-50d\n",nbloc,conta);
  printf("------------------------------------------------------\n");
}
}

//---------------------------------------------------
void connexion() {
    char utilisateur[15];
    char mdp[15];
    int authentifie = 0;

    printf("Bienvenue!\n");

    while (!authentifie) {
        printf("\n");
        printf("=========================================\n");
        printf("              Menu de connexion          \n");
        printf("=========================================\n");
        printf("Nom d'utilisateur : ");
        scanf("%s", utilisateur);

        printf("Mot de passe : ");
        scanf("%s", mdp);

        authentifie = verifierMDP(utilisateur, mdp);

        if (!authentifie) {
            printf("Nom d'utilisateur ou mot de passe incorrect. Veuillez réessayer.\n");
        }
    }

    printf("Connexion réussie!\n");
}
int verifierMDP(char *utilisateur, char *mdp) {
    if (strcmp(utilisateur, "jm.lery") == 0 && strcmp(mdp, "lery75") == 0) {
        return 1; 
    }
    else {
        return 0; 
    }
}
void sauvegarder_fidelite()
{
  int i;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  if (nbNiveaux == 0) {
      printf("Aucune fidélité à sauvegarder\n");
  } else {
      // Ouverture du fichier
      strcpy(NomFichier, "fidelite.txt");
      fichier = fopen(NomFichier, "w");

      // Boucle de sauvegarde
      for (i = 0; i < nbNiveaux; i++) {
          fprintf(fichier, "%d %f\n",
                  niveauxFidelite[i].seuilLocations,niveauxFidelite[i].reduction);
      }
      fclose(fichier);
      printf("%d fidelité sauvegardés\n", nbNiveaux);
 verif_fide=0;
  }

}




void sauvegarder_historique_client(){
  int i;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  if (nbhistoriquec == 0) {
      printf("Aucun historique client à sauvegarder\n");
  } else {
      // Ouverture du fichier
      strcpy(NomFichier, "historique_client.txt");
      fichier = fopen(NomFichier, "w");

      // Boucle de sauvegarde
      for (i = 0; i < nbhistoriquec; i++) {
          fprintf(fichier, "%d %s %s %s %s %s %s %s %d %d %s\n",
                  historique_client[i].num_client,historique_client[i].telephone,historique_client[i].prenom,
          historique_client[i].nom,historique_client[i].adresse,historique_client[i].num_permis,
          historique_client[i].date_de_naissance,historique_client[i].mail,historique_client[i].nblocation,
          historique_client[i].annee_permis,historique_client[i].date_suppressions);
      }
      fclose(fichier);
      printf("%d historique client sauvegardés\n", nbhistoriquec);
  }

}

void sauvegarder_historique_vehicule(){
  int i;
  FILE *fichier;
  char NomFichier[TAILLE_NOM_F];

  if (nbhistoriquev == 0) {
      printf("Aucun historique véhicules à sauvegarder\n");
  } else {
      // Ouverture du fichier
      strcpy(NomFichier, "historique_vehicule.txt");
      fichier = fopen(NomFichier, "w");

      // Boucle de sauvegarde
      for (i = 0; i < nbhistoriquev; i++) {
          fprintf(fichier, "%d %d %s %d %s %s %s %s\n",
            historique_vehicule[i].num_vehicule,historique_vehicule[i].annee,historique_vehicule[i].marque,historique_vehicule[i].kilometrage
            ,historique_vehicule[i].date_suppressions,historique_vehicule[i].immatriculation,historique_vehicule[i].type,historique_vehicule[i].modele);
      }
      fclose(fichier);
      printf("%d historique véhicules sauvegardés\n", nbhistoriquev);
  }

}
void verif_sauvegarde_histoc(){
  char reponse3[10];
  if (a_sauvegarderhc)
  {
  printf("Nouveau client dans l'historique des clients\n");
  printf("Voulez-vous faire une sauvegarde (o/n) : ");
  scanf("%s",reponse3);
  conv_maj(reponse3);

  if (reponse3[0] == 'O')
     sauvegarder_historique_client();
  }

}
void verif_sauvegarde_histov(){
  char reponse3[10];
  if (a_sauvegarderhv)
  {
  printf("Nouveau véhicule dans l'historique des véhicules\n");
  printf("Voulez-vous faire une sauvegarde (o/n) : ");
  scanf("%s",reponse3);
  conv_maj(reponse3);

  if (reponse3[0] == 'O')
     sauvegarder_historique_vehicule();
  }

}


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// les constantes symboliques
#define MAX_ANNONCES 1000
#define NB_CHAMPS 4
#define MAX_CAR_CHAMP 60
#define MAX_CAR_LIGNE 240


// les types
typedef char t_lignes[MAX_CAR_LIGNE];
typedef char t_champ[MAX_CAR_CHAMP];

typedef struct {
        t_champ designation;
        int annee;
        int km;
        int prix;
} t_annonce;

typedef struct {
        t_annonce tabAnnonces[MAX_ANNONCES];
        int nb;
} t_stock;

const t_annonce ANNONCE_VIDE = {"Sans distinction", -1, 0, 0};

// les prototypes des fonctions
void initStock(t_stock *adrAnnonces);
void lectureTexte1(char nomFichier[], t_stock *adrAnnonces);
void lectureTexte2(char nomFichier[], t_stock *adrAnnonces);
void afficheUneAnnonce(t_annonce an);
void afficheAnnonces(t_stock stock);
void afficheAnnoncesPrixMax(t_stock stock);
void sauvegardeBinaire(t_stock stock);
void lectureBinaire(char fichier[30]);
t_stock saisieAnnonce();
void ajoutAnnonceAuStock(t_stock *stock);

int split(char donnees[], char param[NB_CHAMPS][MAX_CAR_CHAMP], char separateur[]);
// les constantes
const char SEPARATEUR[]= "\t";

// le programme principal
int main(){
// Declaration des variables
char* nom_fichier_csv = "annonces.csv";
char* nom_fichier_bin = "annonces.bin";
t_stock stock_auto;
t_annonce annonce;
int choix = -1;
// initialisation des structures
initStock(&stock_auto);
// menu
while(choix != 0){
        printf("---------------------------------------------------------------------\n");
        printf("1 : lire le fichier texte des annonces (pas d'espace dans les champs)\n");
        printf("2 : lire le fichier texte des annonces (fonction split) \n");
        printf("3 : afficher une annonce à partir de son indice\n");
        printf("4 : afficher toutes les annonces\n");
        printf("5 : afficher les annonces prix max\n");
        printf("6 : sauvegarder les annonces dans un fichier binaire\n");
        printf("7 : lire le fichier binaire\n");
        printf("8 : ajouter une annonce au stock\n");
        printf("9 : supprimer une annonce\n");
        printf("votre choix :");
        scanf("%d", &choix);
        
        switch(choix){
            case 0: break;
            case 1: // lire le fichier texte des annonces (pas d'espace dans les champs)
                    lectureTexte1(nom_fichier_csv, &stock_auto);
                    break;
            case 2: // lire le fichier texte des annonces (fonction spilt())
                    afficheUneAnnonce(stock_auto.tabAnnonces[2]);
                    break;
            case 3: // afficher une annonce à partir de son indice
                    break;
            case 4: // afficher toutes les annonces
                    break;
            case 5: // afficher les annonces prix max
                    break;
            case 6: // sauvegarder les annonces dans un fichier binaire
                    break;
            case 7: // lire le fichier binaire des annonces
                    break;
            case 8: // ajouter une annonce dans le fichier binaire
                    break;
            case 9 : // supprimer une annonce
                    break;
            default: printf("erreur de choix\n");
        }
    }
    return EXIT_SUCCESS;
}
// Definition des fonctions et procedures
void initStock(t_stock *adrAnnonces){
        adrAnnonces->nb = 0;
        for (int i = 0; i < MAX_ANNONCES; i ++) {
                adrAnnonces->tabAnnonces[i] = ANNONCE_VIDE;
        }
}
void lectureTexte1(char nomFichier[], t_stock *adrAnnonces){
        FILE *fic;
        system("tr ' ' '_' < %s", nomFichier);
        fic = fopen(nomFichier, "r");
        int i = 0;
        while (!feof(fic) && i < MAX_ANNONCES) {
                printf("Feur");
                sscanf(fic, "%s\t%d\t%d\t%d", 
                &(adrAnnonces->tabAnnonces[i].designation),
                &(adrAnnonces->tabAnnonces[i].annee),
                &(adrAnnonces->tabAnnonces[i].km),
                &(adrAnnonces->tabAnnonces[i].prix));
                i++;
        }
}
void lectureTexte2(char nomFichier[], t_stock *adrAnnonces){

}
void afficheUneAnnonce(t_annonce an){
    printf("%50s|%6d|%10d km |%6d €\n",an.designation, an.annee,an.km, an.prix);
}
int split(char donnees[], char param[NB_CHAMPS][MAX_CAR_CHAMP], char separateur[]){
    char * ptr;
    int nb_val = 0;
    // lecture premiere chaine
    ptr = strtok(donnees, separateur);
    while(ptr != NULL && nb_val < NB_CHAMPS){
        //printf("%s\n", ptr);
        strncpy(param[nb_val],ptr,MAX_CAR_CHAMP);
        param[nb_val][MAX_CAR_CHAMP-1]='\0'; // Termine manuellement avec un caractère nul si nécessaire
        nb_val++;
        // lecture nouvelle chaine
        ptr = strtok(NULL,separateur);
    }
    return nb_val;
}

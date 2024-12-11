#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Constantes symboliques
#define MAX_MESSAGES 20
#define MAX_CAR 80
#define ELT_VIDE "------ce message est vide-------"

// Définitions des types utilisateur
typedef char t_message[MAX_CAR];

typedef struct {
    t_message message;
} t_element;

typedef struct {
    t_element tabElt[MAX_MESSAGES];
    int nb;
} t_file;

// Prototypes des fonctions
t_file initialiser();
int estVide(t_file f);
int estPleine(t_file f);
void enfiler(t_file *f, t_element elt);
t_element defiler(t_file *f);
void vider(t_file *f);
t_element tete(t_file f);
void supprimer_trop_anciens(t_file *f, int nb);
void sauvegardeFichier(t_file *f, const char *nomFichier);
void lectureFichier(t_file *f, const char *nomFichier);
void afficheTous(t_file f);

// Définition des fonctions
t_file initialiser() {
    t_file f;
    f.nb = 0;
    for (int i = 0; i < MAX_MESSAGES; i++) {
        strcpy(f.tabElt[i].message, ELT_VIDE);
    }
    return f;
}

int estVide(t_file f) {
    return f.nb == 0;
}

int estPleine(t_file f) {
    return f.nb == MAX_MESSAGES;
}

void enfiler(t_file *f, t_element elt) {
    if (!estPleine(*f)) {
        f->tabElt[f->nb++] = elt;
    } else {
        printf("La file est pleine !\n");
    }
}

t_element defiler(t_file *f) {
    t_element eltVide;
    strcpy(eltVide.message, ELT_VIDE);
    if (!estVide(*f)) {
        t_element premier = f->tabElt[0];
        for (int i = 1; i < f->nb; i++) {
            f->tabElt[i - 1] = f->tabElt[i];
        }
        f->nb--;
        return premier;
    } else {
        printf("La file est vide !\n");
        return eltVide;
    }
}

void vider(t_file *f) {
    f->nb = 0;
    for (int i = 0; i < MAX_MESSAGES; i++) {
        strcpy(f->tabElt[i].message, ELT_VIDE);
    }
}

t_element tete(t_file f) {
    if (!estVide(f)) {
        return f.tabElt[0];
    } else {
        t_element eltVide;
        strcpy(eltVide.message, ELT_VIDE);
        printf("La file est vide !\n");
        return eltVide;
    }
}

void supprimer_trop_anciens(t_file *f, int nb) {
    if (nb >= f->nb) {
        vider(f);
    } else {
        for (int i = 0; i < f->nb - nb; i++) {
            f->tabElt[i] = f->tabElt[i + nb];
        }
        f->nb -= nb;
    }
}

void sauvegardeFichier(t_file *f, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier) {
        for (int i = 0; i < f->nb; i++) {
            fprintf(fichier, "%s\n", f->tabElt[i].message);
        }
        fclose(fichier);
        vider(f);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
}

void lectureFichier(t_file *f, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier) {
        vider(f);
        t_message msg;
        while (fgets(msg, MAX_CAR, fichier)) {
            msg[strlen(msg) - 1] = '\0'; // Supprimer le \n
            t_element elt;
            strcpy(elt.message, msg);
            enfiler(f, elt);
        }
        fclose(fichier);
    } else {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
}

void afficheTous(t_file f) {
    for (int i = 0; i < f.nb; i++) {
        printf("%d: %s\n", i, f.tabElt[i].message);
    }
}

// Programme principal
int main() {
    t_file maFile = initialiser();
    t_element elt;
    int choix;

    do {
        printf("----------------------------------------------------\n");
        printf("0 : quitter\n");
        printf("1 : afficher le nombre d'elements dans la file\n");
        printf("2 : ajouter un element a la file\n");
        printf("3 : retirer un element et afficher le message\n");
        printf("4 : afficher le message de la tete de file\n");
        printf("5 : vider la file\n");
        printf("6 : la file est-elle vide ?\n");
        printf("7 : la file est-elle pleine ?\n");
        printf("8 : supprimer les messages trop anciens\n");
        printf("9 : sauvegarde dans un fichier texte et vider\n");
        printf("10: lecture des messages du fichier texte\n");
        printf("votre choix : ");
        scanf("%d", &choix);
        getchar(); // Consommer le \n restant
        printf("----------------------------------------------------\n");

        switch (choix) {
            case 0:
                break;
            case 1:
                printf("Nombre d'elements: %d\n", maFile.nb);
                break;
            case 2:
                printf("Saisir un nouveau message : ");
                fgets(elt.message, MAX_CAR, stdin);
                elt.message[strlen(elt.message) - 1] = '\0';
                enfiler(&maFile, elt);
                break;
            case 3:
                elt = defiler(&maFile);
                printf("Message retire: %s\n", elt.message);
                break;
            case 4:
                elt = tete(maFile);
                printf("Message en tete: %s\n", elt.message);
                break;
            case 5:
                vider(&maFile);
                printf("File videe.\n");
                break;
            case 6:
                printf("La file est %s.\n", estVide(maFile) ? "vide" : "non vide");
                break;
            case 7:
                printf("La file est %s.\n", estPleine(maFile) ? "pleine" : "non pleine");
                break;
            case 8: {
                int nb;
                printf("Nombre de messages a supprimer: ");
                scanf("%d", &nb);
                getchar();
                supprimer_trop_anciens(&maFile, nb);
                break;
            }
            case 9: {
                char nomFichier[MAX_CAR];
                printf("Nom du fichier: ");
                fgets(nomFichier, MAX_CAR, stdin);
                nomFichier[strlen(nomFichier) - 1] = '\0';
                sauvegardeFichier(&maFile, nomFichier);
                break;
            }
            case 10: {
                char nomFichier[MAX_CAR];
                printf("Nom du fichier: ");
                fgets(nomFichier, MAX_CAR, stdin);
                nomFichier[strlen(nomFichier) - 1] = '\0';
                lectureFichier(&maFile, nomFichier);
                break;
            }
            default:
                printf("Erreur de saisie\n");
        }
    } while (choix != 0);

    return EXIT_SUCCESS;
}

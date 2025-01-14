#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE 4

#define INIT 1
#define INPUT 2
#define SUM 3
#define MIN 4
#define SEARCH 5
#define AVERAGE 6
#define STOP 7

typedef int carte[TAILLE][TAILLE];

void init(carte values);
void input(carte values);
int total(carte values);
int min(carte values);
int search(carte values, int value);
float average(carte values);
int menu();

int main() {
    int choice;
    int inited = 0;
    int searching;
    carte values;
    printf("Programme carte\n");
    do {
        choice = menu();
        switch (choice)
        {
        case INIT:
            init(values);
            break;
        case INPUT:
            input(values);
            break;
        case SUM:
            printf("Total des altitudes : %d", total(values));
            break;
        case MIN:
            printf("Valeur minimal : %d", min(values));
            break;
        case SEARCH:
            printf("Valeur à chercher : ");
            break;
        case AVERAGE:
            init(values);
            break;
        case STOP:
            init(values);
            break;
        
        default:
            break;
        }

    } while (choice != 7);
    

    return EXIT_SUCCESS;
}

void init(carte values) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            values[i][j] = 0;
        }
    }
}

void input(carte values) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf("Veuillez saisir la valeur %d %d du tableau : ", i, j);
            scanf("%d", values[i][j]);
        }
    }
}

int total(carte values) {
    int tot = 0;
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            tot+= values[i][j];
        }
    }
    return tot;
}

int min(carte values) {
    int min = values[0][0];
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (values[i][j] < min) {
                min = values[i][j];
            }
        }
    }
    return min;
}

int search(carte values, int value) {
    int i, j;
    i = 0;
    j = 0;
    bool trouve = false;
    while (trouve != true && i < TAILLE) {
        while (trouve != true && j < TAILLE) {
            if (values[i][j] == value) {
                trouve = true;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return trouve;
} 

float average(carte values) {
    if (TAILLE != 0) {
        return (total(values) * .0) / (TAILLE * TAILLE);
    } else {
        printf("Division par 0 impossible !");
        return -1;
    }
}

int menu() {
    int choice;
    printf("\n1. Initialiser une carte\n");
    printf("2. Saisir les valeurs d'une carte\n");
    printf("3. Afficher la somme de toutes les altitudes de la carte\n");
    printf("4. Donner l'altitude la plus basse d'une carte\n");
    printf("5. Rechercher une altitude\n");
    printf("6. Afficher la moyenne des altitudes de la carte\n");
    printf("7. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    return choice;
}
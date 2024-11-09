#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define ITERATION_MAX 10

int generer(int borne);
int comparer(int n1, int n2);
int jeu(int nb_secret);

int main() {
    int nb_secret = generer(MAX);
    int iteration;
    iteration = jeu(nb_secret);
    if (iteration <= ITERATION_MAX) {
        printf("Vous avez gagné ! (%d coups)\n", iteration);
    } else {
        printf("Perdu ... (%d coups)\n", iteration);
    }
    return EXIT_SUCCESS;
}

int generer(int borne) {
    srand(time(NULL));
    return rand() % (borne + 1);
}

int comparer(int n1, int n2) {
    int comparaison;
    if (n1 > n2) {
        comparaison = 1;
    } else if (n1 < n2) {
        comparaison = -1;
    } else {
        comparaison = 0;
    }
    return comparaison;
}

int jeu(int nb_secret) {
    int iteration = 0;
    int saisie;
    printf("Tentez de deviner le nombre secret : ");
    scanf("%d", &saisie);
    while (saisie != nb_secret) {
        iteration++;
        if (comparer(saisie, nb_secret) == 1) {
            printf("Le nombre secret est plus petit\n");
        } else {
            printf("Le nombre secret est plus grand\n");
        }
        printf("Tentez de deviner le nombre secret : ");
        scanf("%d", &saisie);
    }
    printf("Le nombre secret est trouvé !\n");
    return iteration;
}
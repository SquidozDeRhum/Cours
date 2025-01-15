#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBSPORT 10
#define NBACT 4
#define ANNEES 30

#define NBP {35.0, 25.0, 20.0, 20.0}
#define COEF1 {0.9, 0.06, 0.08, 0.05}
#define COEF2 {0.03, 0.8, 0.02, 0.03}
#define COEF3 {0.02, 0.03, 0.75, 0.04}
#define COEF4 {0.05, 0.11, 0.15, 0.88}

typedef float t_sports[NBSPORT];
typedef float matrice[NBSPORT][NBSPORT];

void afficherVecteur(t_sports sports, int nb);
void afficherMatrice(matrice coef, int nb);
void produitVectMat(t_sports initial, matrice coef, t_sports result, int nb);
void copierVecteur(t_sports initial, t_sports result, int nb);

int main() {
    t_sports sports = NBP;
    matrice coef = {COEF1,COEF2,COEF3,COEF4};
    t_sports result;

    for (int i = 0; i < ANNEES; i++) {
        produitVectMat(sports, coef, result, NBACT);
        copierVecteur(result, sports, NBACT);
    }

    afficherVecteur(result, NBACT);

    return EXIT_SUCCESS;
}

void afficherVecteur(t_sports sports, int nb) {
    for (int i = 0; i < nb; i ++) {
        printf("Sport %d : %.2f\n", i, sports[i]);
    }
}

void afficherMatrice(matrice coef, int nb) {
    for (int i = 0; i < nb; i ++) {
        for (int j = 0; j < nb; j ++) {
            printf("%5.2f", coef[i][j]); 
        }
        printf("\n");
    }
}

void produitVectMat(t_sports initial, matrice coef, t_sports result, int nb) {
    for (int i = 0; i < nb; i++) {
        result[i] = 0.0;
    }
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < nb; j++) {
            result[i] += initial[j] * coef[i][j];
        }
    }
}

void copierVecteur(t_sports initial, t_sports result, int nb) {
    for (int i = 0; i < nb; i++) {
        result[i] = initial[i];
    }
}
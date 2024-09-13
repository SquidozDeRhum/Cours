#include <stdio.h>
#include <stdlib.h>

int main() {
    float prix1, prix2, diff, pourcentage;
    printf("Veuillez entrer un premier prix : ");
    scanf("%f", &prix1);
    printf("Veuillez entrer un second prix : ");
    scanf("%f", &prix2);
    diff = prix2 / prix1 - 1;
    pourcentage = diff * 100;
    printf("Il y a %.2f %% de différence entre les deux produits", pourcentage);
    return 0;
}
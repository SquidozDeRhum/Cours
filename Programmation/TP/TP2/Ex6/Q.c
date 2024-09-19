#include <stdlib.h>
#include <stdio.h>

int main() {
    int jours, km;
    float prixT, prixE;
    printf("Veuillez saisir le nombre de kilomètres à faire : ");
    scanf("%d", &km);
    printf("Veuillez saisir le nombre de jours de location : ");
    scanf("%d", &jours);
    prixT = 1.2 * km + 10 * jours;
    prixE = 1.0 * km + 15 * jours;
    if (prixT == prixE) {
        printf("Egalité entre les deux\n");
    }
    else if (prixT < prixE) {
        printf("Véhicule thermique moins coûteux (%.2f euros contre %.2f euros)\n", prixT, prixE);
    } else {
        printf("Véhicule électrique moins coûteux (%.2f euros contre %.2f euros)\n", prixE, prixT);
    }
    return 0;
}
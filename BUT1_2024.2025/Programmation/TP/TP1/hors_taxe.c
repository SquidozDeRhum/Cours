#include <stdlib.h>
#include <stdio.h>

int main() {
    float montant, taxe;
    printf("Veuillez entrer un montant TTC : ");
    scanf("%f", &montant);
    printf("Veuillez entrer un pourcentage de taxe : ");
    scanf("%f", &taxe);
    printf("Le montant hors taxe est : %.2f", montant / (1 + taxe / 100));
    return 0;
}
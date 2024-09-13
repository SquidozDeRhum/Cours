#include <stdlib.h>
#include <stdio.h>

int main() {
    float montant, taxe;
    printf("Veuillez entrer un montant hors taxe : ");
    scanf("%f", &montant);
    printf("Veuillez entrer un pourcentage de taxe : ");
    scanf("%f", &taxe);
    printf("Le montant TTC est : %.2f", montant * (1 + taxe / 100));
    return 0;
}
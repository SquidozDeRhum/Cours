#include <stdio.h>
#include <stdlib.h>

#define TAUX 20

int main() {
    char nom[20];
    float salaire, salaireNet;

    printf("Veuillez saisir le nom de l'employé : ");
    scanf("%s", nom);

    while (nom[0] != '*')
    {
        printf("Veuillez saisir le salaire brut de l'employé : ");
        scanf("%f", &salaire);
        salaireNet = salaire * (1. * (100 - TAUX)/100);
        printf("Le salaire net de %s est de %.2f\n", nom, salaireNet);
        printf("Veuillez saisir le nom de l'employé : ");
        scanf("%s", nom);
    }
    return 0;
}
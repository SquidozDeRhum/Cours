#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAUX 20
#define ARRET "*"

void traiterUnEmploye(char nom[20], float salaireBrut, float *totalSalaireNet);
void afficherMoyenne(float totalSalaireNet, int nb_salarie);

int main() {
    int nb_employe = 0;
    float totalSalaireNet, salaireBrut;
    char nom[20];
    totalSalaireNet = 0;
    
    printf("Veuillez donner le nom de l'employé : ");
    scanf("%s", nom);

    while (strcmp(nom, TAUX) != 0) {
        nb_employe++;
        printf("Veuillez donner son salaire brut : ");
        scanf("%f", &salaireBrut);
        traiterUnEmploye(nom, salaireBrut, &totalSalaireNet);
        printf("Veuillez donner le nom de l'employé : ");
        scanf("%s", nom);
    }

    afficherMoyenne(totalSalaireNet, nb_employe);
    
    return EXIT_SUCCESS;
}

void traiterUnEmploye(char nom[20], float salaireBrut, float *totalSalaireNet) {
    float salaireNet = salaireBrut * (1 - (TAUX / 100.0));
    *totalSalaireNet += salaireNet;
    printf("Salaire net de %s : %f\n", nom, salaireNet);
}

void afficherMoyenne(float totalSalaireNet, int nb_salarie) {
    float moyenne;
    if (nb_salarie > 0) {
        moyenne = totalSalaireNet / nb_salarie;
        printf("La salaire moyen est : %.2f\n", moyenne);
    } else {
        printf("Aucun salaire entré\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

#define TAUX 20

void traiterUnEmploye(char nom[20], float *salaireBrut, float *totalSalaireNet);
void afficherMoyenne(float totalSalaireNet, );

int main() {
    
    
    return EXIT_SUCCESS;
}

void traiterUnEmploye(char nom[20], float *salaireBrut, float *totalSalaireNet) {
    float salaireNet = *salaireBrut * (1 - (TAUX / 100));
    *totalSalaireNet += salaireNet;
    printf("Salaire net de %s : %d", nom, salaireNet);
}
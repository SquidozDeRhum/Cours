#include <stdlib.h>
#include <stdio.h>

const int CONSOMAX = 100;
const int CONSOMAX2 = 150;
const float COUTKWH = 0.10;
const float COUTKWH2 = 0.15;
const float COUTKWH3 = 0.2;
const int COUTF = 15;
const float TVA = 1.2;

#define BASSE 'B'
#define MOYENNE 'M'
#define HAUTE 'H'

int main() {
    char catConso;
    float conso, res;
    printf("Veuillez entrer votre consommation électrique : ");
    scanf("%f", &conso);
    if (conso < CONSOMAX) {
        catConso ='B';
    } else if (conso <= CONSOMAX2) {
        catConso = 'M';
    } else {
        catConso = 'H';
    }
    switch (catConso)
    {
    case BASSE:
        res = conso * COUTKWH;
        break;

    case MOYENNE:
        res = CONSOMAX * COUTKWH + (conso - CONSOMAX) * COUTKWH2;
        break;

    case HAUTE:
        res = CONSOMAX * COUTKWH + (CONSOMAX2 - CONSOMAX) * COUTKWH2 + (conso - CONSOMAX2) * COUTKWH3;
        break;
    
    default:
        printf("Une erreur s'est produite\n");
        break;
    }
    res += COUTF;
    res *= TVA;
    printf("Votre montant est de : %.2f\n", res);
    return 0;
}
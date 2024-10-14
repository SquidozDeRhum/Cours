#include <stdlib.h>
#include <stdio.h>

const int CONSOMAX = 100;
const int CONSOMAX2 = 100;
const float COUTKWH = 0.10;
const float COUTKWH2 = 0.15;
const float COUTKWH3 = 0.2;
const int COUTF = 15;
const float TVA = 1.2;

int main() {
    float conso, res;
    printf("Veuillez entrer votre consommation électrique : ");
    scanf("%f", &conso);
    if (conso < CONSOMAX) {
        res = conso * COUTKWH;
    } else if (conso <= CONSOMAX2) {
        res = CONSOMAX * COUTKWH + (conso - CONSOMAX) * COUTKWH2;
    } else {
        res = CONSOMAX * COUTKWH + (CONSOMAX2 - CONSOMAX) * COUTKWH2 + (conso - CONSOMAX2) * COUTKWH3;
    }
    res += COUTF;
    res *= TVA;
    printf("Votre montant est de : %.2f\n", res);
    return 0;
}
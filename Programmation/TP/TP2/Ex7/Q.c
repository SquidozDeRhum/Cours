#include <stdlib.h>
#include <stdio.h>

int main() {
    float conso, res;
    printf("Veuillez entrer votre consommation électrique : ");
    scanf("%f", &conso);
    if (conso < 100) {
        res = conso * 0.10;
    } else if (conso <= 150) {
        res = 100 * 0.10 + (conso - 100) * 0.15;
    } else {
        res = 100 * 0.10 + (conso - 100) * 0.15 + (conso - 150) * 0.2;
    }
    res += 15;
    res *= 1.2;
    printf("Votre montant est de : %.2f\n", res);
    return 0;
}
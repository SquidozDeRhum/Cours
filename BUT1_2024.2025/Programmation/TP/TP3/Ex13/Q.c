#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 0.00003

int main() {

    float value, un, un1;
    un = 1;
    un1 = un;

    printf("Veuillez saisir une valeur : ");
    scanf("%f", &value);

    while (fabs(un*un - value) < EPSILON) {
        un = (un1 + (value/un1))/2;
        un1 = un;
    }

    printf("La racine carré de %2f est %.3f\n", value, un);

    return 0;
}
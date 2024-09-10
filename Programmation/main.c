#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    float rayon;

    printf("Veuillez renseignez un rayon de cercle : ");

    scanf("%f", &rayon);

    printf("L'aire de votre cercle est : %f", pow(rayon, 2) * 3.14);

    return 0;
}
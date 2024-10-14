#include <stdio.h>
#include <stdlib.h>

int main() {
    const float pi = 3.141592;
    float rayon, res;
    printf("Veuillez entrer le rayon du cercle : ");
    scanf("%f", &rayon);
    res = pi * rayon * 2;
    printf("Le périmètre du cercle est : %f", res);
    return 0;
}
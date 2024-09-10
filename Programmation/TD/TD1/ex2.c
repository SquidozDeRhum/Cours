#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float input, res;
    printf("Veuillez entrer un nombre : ");
    scanf("%f", &input);
    res = pow(input, 3);
    printf("Le cube de %f est %f", input, res);
    return 0;
}
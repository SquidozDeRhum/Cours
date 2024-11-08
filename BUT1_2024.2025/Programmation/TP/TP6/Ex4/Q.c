#include <stdio.h>
#include <stdlib.h>

float add(float a, float b);
float dvi(float a, float b);
float sou(float a, float b);
float mul(float a, float b);

int main() {

    float result = sou(add(mul(add(dvi(add(4.5, 1.3), 2.0), 1.1), 5.3), 4.2), 1.0);
    printf("Résulat attendu : 24.4 Résultat obtenu : %.1f\n", result);

    return EXIT_SUCCESS;
}

float add(float a, float b) {
    return a + b;
}

float dvi(float a, float b) {
    return a / b;
}

float sou(float a, float b) {
    return a - b;
}

float mul(float a, float b) {
    return a * b;
}
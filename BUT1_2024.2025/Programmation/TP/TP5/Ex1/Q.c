#include <stdio.h>
#include <stdlib.h>

void division(int a, int b, int * quotient, int * reste);

int main() {
    int a, b, quotient, reste;
    a = 10;
    b = 3;
    division(a, b, &quotient, &reste);
    printf("Quotient de a par b : %d\n", quotient);
    printf("Reste : %d\n", reste);
    return EXIT_SUCCESS;
}

void division(int a, int b, int * quotient, int * reste) {
    if (b != 0) {
        *quotient = a / b;
    } else {
        printf("Erreur de saisie\n");
    }
    *reste = a % b;
}
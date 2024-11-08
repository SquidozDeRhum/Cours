#include <stdio.h>
#include <stdlib.h>

int fac(int n);

int main() {
    int n;

    printf("Entier : ");
    scanf("%d", &n);
    
    printf("Factorielle de %d : %d\n", n, fac(n));

    return EXIT_SUCCESS;
}

int fac(int n) {
    int result = 1;
    for (int i = 1; i < n + 1; i++) {
        result *= i;
    }
    return result;
}
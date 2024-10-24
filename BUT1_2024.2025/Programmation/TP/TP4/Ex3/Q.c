#include <stdio.h>
#include <stdlib.h>

void printMin(int a, int b);

int main() {
    printMin(3, 4);
    return EXIT_SUCCESS;
}

void printMin(int a, int b) {
    if (a < b) {
        printf("%d\n", a);
    } else if (b < a) {
        printf("%d\n", b);
    } else {
        printf("Le deux nombres sont égaux");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea(int borneMax);

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        printf("%d\n", alea(14));
    }
    return EXIT_SUCCESS;
}

int alea(int borneMax) {
    return rand() % borneMax + 1;
}
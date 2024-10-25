#include <stdio.h>
#include <stdlib.h>

void minMax(int *min, int *max);

int main() {
    int min, max;
    minMax(&min, &max);
    printf("Max : %d\n", max);
    printf("Min : %d\n", min);
    
    return EXIT_SUCCESS;
}

void minMax(int *min, int *max) {
    int input;
    printf("Veuillez saisir un entier : ");
    scanf("%d", &input);

    if (input != 0) {
        if (input > 0) {
            *min = input;
            *max = input;
        }
    } else {
        printf("La suite est vide\n");
        *min = -1;
        *max = -1;
    }
    while (input != 0) {
        if (input > 0) {
            if (input < *min) {
                *min = input;
            } else if (input > *max) {
                *max = input;
            }
        }
        printf("Veuillez saisir un entier : ");
        scanf("%d", &input);
    }
}
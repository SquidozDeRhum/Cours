#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, max, size;

    printf("Veuillez entrer le nombre de valeurs de la suite : ");
    scanf("%d", &size);

    if (size > 0) {
        printf("Veuillez saisir un entier : ");
        scanf("%d", &number);
        max = number;
        for (int i = 0; i < size - 1; i++) {
            printf("Veuillez saisir un entier : ");
            scanf("%d", &number);
            if (number > max) {
                max = number;
            }
        }
        printf("La valeur maximale est : %d\n", max);
    }
    else {
        printf("La taille de la liste est invalide\n");
    }
    return 0;
}
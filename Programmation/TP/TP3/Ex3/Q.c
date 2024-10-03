#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, somme, size;
    float result;

    somme = 0;

    printf("Veuillez entrer le nombre de valeurs de la suite : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Veuillez saisir un entier : ");
        scanf("%d", &number);
        somme += number;
    }
    printf("Somme %d\n", somme);
    if (size == 0) {
        printf("Aucune valeur entrée\n");
    }
    else {
        result = (1. * somme) / (1. * size);
        printf("Moyenne des valeurs : %.2f\n", result);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, somme, lenght;
    float result;

    somme = 0;
    number = 0;
    lenght = -1;

    do {
        lenght ++;
        somme += number;
        printf("Veuillez saisir un entier : ");
        scanf("%d", &number);
    } while (number != -1);
    if (lenght == 0) {
        printf("Aucune valeur entrée\n");
    }
    else {
        result = (1. * somme) / (1. * lenght);
        printf("Moyenne des valeurs : %.2f\n", result);
    }
    return 0;
}
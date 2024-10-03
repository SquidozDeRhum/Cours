#include <stdio.h>
#include <stdlib.h>

int main() {
    int value;

    printf("(1) Faire action 1\n");
    printf("(2) Faire action 2\n");
    printf("(0) Quitter\n");
    printf("Veuillez saisir votre choix : ");
    scanf("%d", &value);

    while (value != 0) {
        printf("Erreur : vous devez saisir 1, 2, ou 0");
    }
    

    return 0;
}
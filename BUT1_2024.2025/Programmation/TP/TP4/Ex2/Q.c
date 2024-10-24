#include <stdio.h>
#include <stdlib.h>

#define ARRET 0
#define CHOIX1 1
#define CHOIX2 2

void menu();

int main() {
    int choix;
    menu();
    printf("Choix : ");
    scanf("%d", &choix);
    while (choix != ARRET) {
        if (choix == CHOIX1) {
            printf("Action 1\n");
        } else if (choix == CHOIX2) {
            printf("Action 2\n");
        } else {
            printf("Choix errone\n");
        }
        menu();
        printf("Choix : ");
        scanf("%d", &choix);
    }

    return EXIT_SUCCESS;
}

void menu() {
    printf("0 pour arrêter\n");
    printf("1 pour l'action n°1\n");
    printf("2 pour l'action n°2\n");
}

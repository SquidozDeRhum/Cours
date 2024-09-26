#include <stdlib.h>
#include <stdio.h>

#define GAUCHE 'H'
#define DROITE 'l'
#define DESCENDRE 'j'
#define MONTER 'k'

int main() {

    char direction;

    printf("Veuillez saisir une direction : ");
    scanf("%c", &direction);

    if (direction == GAUCHE) {
        printf("Allez à gauche");
    } else if (direction == DROITE) {
        printf("Allez à droite");
    } else  if (direction == DESCENDRE) {
        printf("Descendre");
    } else if (direction == MONTER) {
        printf("Monter");
    } else {
        printf("Erreur d'entrée");
    }
    return EXIT_SUCCESS;
}
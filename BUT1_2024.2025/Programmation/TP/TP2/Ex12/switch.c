#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define GAUCHE 'H'
#define DROITE 'l'
#define DESCENDRE 'j'
#define MONTER 'k'

int main() {

    char direction;

    printf("Veuillez saisir une direction : ");
    scanf("%c", &direction);

    switch (toupper(direction))
    {
    case GAUCHE:
        printf("Allez à gauche");
        break;

    case DROITE:
        printf("Allez à droite");
        break;

    case DESCENDRE:
        printf("Descendre");
        break;

    case MONTER:
        printf("Monter");
        break;
    
    default:
        printf("Erreur d'entrée");
        break;
    }
    return EXIT_SUCCESS;
}
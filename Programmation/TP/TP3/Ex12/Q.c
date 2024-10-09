#include <stdio.h>
#include <stdlib.h>

int main() {

    char caractereCourant;
    int occurence = 0;

    printf("Veuillez saisir une suite de caractères : ");
    scanf("%c", &caractereCourant);

    while (caractereCourant != '.')
    {
        if (caractereCourant == 'l') {
            scanf("%c", &caractereCourant);
            if (caractereCourant == 'e') {
                occurence++;
            }
        }
        else {
            scanf("%c", &caractereCourant);
        }
    }

    printf("La chaîne 'le' apparaît %d fois\n", occurence);

    return 0;
}
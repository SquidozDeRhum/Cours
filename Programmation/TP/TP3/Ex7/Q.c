#include <stdio.h>
#include <stdlib.h>

#define ACTION1 1
#define ACTION2 2
#define QUITTER 0

int main() {
    int value;

    printf("(1) Faire action 1\n");
    printf("(2) Faire action 2\n");
    printf("(0) Quitter\n");
    printf("Veuillez saisir votre choix : ");
    scanf("%d", &value);

    while (value != 0)
    {
        switch (value)
        {
        case ACTION1:
            printf("Action 1\n");
            break;

        case ACTION2:
            printf("Action 2\n");
            break;
        
        default:
            printf("Erreur : vous devez saisir 1, 2 ou 0\n");
            break;
        }
        printf("Veuillez saisir votre choix : ");
        scanf("%d", &value);
    }
    printf("Au revoir\n");
    
    return 0;
}
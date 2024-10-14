#include <stdlib.h>
#include <stdio.h>

int main() {
    int age, em;
    printf("Veuillez saisir votre âge : ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Vous êtes majeur\n");
        printf("Vous pouvez créer votre entreprise\n");
    } else if (age >= 16) {
        printf("Etes-vous emmancipé(e) ? (1 oui 2 non)");
        scanf("%d", &em);
        if (em == 1) {
            printf("Vous pouvez créer votre entreprise\n");
        } else {
            printf("Vous ne pouvez pas créer votre entreprise\n");
        }
    } else {
        printf("Vous ne pouvez pas créer votre entreprise");
    }
    return EXIT_SUCCESS;
}
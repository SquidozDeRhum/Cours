#include <stdlib.h>
#include <stdio.h>

int main()
{ // Declaration des variables
    char nom[10];
    char groupe[10];
    // Saisie des donnees
    printf("Nom ? ");
    scanf("%s", nom);
    printf("Groupe ? \n");
    fgets(groupe, 10, stdin);
    // Affichage
    printf("Nom=%s\n",nom);
    printf("Groupe=%s\n",groupe);
    return EXIT_SUCCESS;
}

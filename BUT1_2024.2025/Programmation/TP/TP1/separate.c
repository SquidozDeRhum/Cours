#include <stdlib.h>
#include <stdio.h>

int main()
{ // Declaration des variables
    char nom[10];
    char prenom;
    // Saisie des donnees
    printf("Nom ? ");
    fgets(nom, 10, stdin);
    printf("Prenom ? ");
    scanf("%s", prenom);
    // Affichage
    printf("Nom=%s\n",nom);
    printf("Prenom=%s\n",prenom);
    return EXIT_SUCCESS;
}
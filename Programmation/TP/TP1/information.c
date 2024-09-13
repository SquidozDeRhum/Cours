/** 
* @brief pg qui demande un nom et un age et qui les  affiche 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
int  main() 
{  // Declaration des variables
    char  nom[20]; // une chaîne  d'au  plus  20 caractères  (dont  le  caractère  de fin  de chaîne,  donc 19 disponibles) 
    int  age;     // un entier
    // Saisie des donnees
    printf("Bienvenue au département informatique\n"); 
    printf("Quel  est votre nom (au plus 19 caractères, et sans espace) ? : ");
    scanf("%s", nom);
    printf("quel  age as tu ?\n");
    scanf("%d",&age);
    // Affichage
    printf("Bonjour %s\n",nom); 
    printf("Tu as %d année(s)\n", age); 
    return  EXIT_SUCCESS; 
}
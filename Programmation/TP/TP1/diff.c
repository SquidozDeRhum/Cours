/** 
* @brief deux ages sont demandés et leur différence affichée 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
int main(){
    // Declaration des variables
    char nom1[50]; // nom d'une première personne (50 car, dont le caractère de fin de chaîne) 
    int age1;      // déclaration de l'age de la personne numero 1 
    char nom2[50]; // nom d'une deuxième personne  
    int age2;      // déclaration de l'age de la personne numero 2 
    // Saisie des donnees
    printf("Bienvenue au département informatique\n"); 
    printf("Personne numero 1, votre nom SVP (au plus 49 car, et sans espace) : "); 
    scanf("%s", nom1); 
    printf("Personne numero 1, votre age SVP : "); 
    scanf("%d", &age1); 
    printf("Personne numero 2, votre nom SVP (au plus 49 car, et sans espace) :"); 
    scanf("%s", nom2); 
    printf("Personne numero 2, votre age SVP : "); 
    scanf("%d", &age2);
    // Affichage du resultat
    printf("Vous avez %d annees de difference.\n", age2 - age1); 
    return EXIT_SUCCESS; 
}
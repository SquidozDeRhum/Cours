/** 
* @brief quelques affectations 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
// Declaration des constantes
const float PI=3.14159; // déclaration et affectation d’une constante de type réel
int main(){
    // Declaration des variables
    int  un ;  // déclaration d’une variable de type entier 
    float  x; // déclaration d’une variable de type réel
    // Initialisation des donnees
    un = 12; 
    x = 8.42;
    // Affichage
    printf("voici   un   :   %d   et   x   :   %.2f.   Ce   sont   deux   variables.\n",   un,x);   //   quelle différence avec la suite ? 
    printf("voici un : %d", un); 
    printf(" et x : %.2f. Ce sont deux variables.", x); 
    printf("\n");  
    printf("voici un : %.3f", PI); 
    return  EXIT_SUCCESS; 
}
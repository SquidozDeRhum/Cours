/** 
* @brief Recette de far breton pour 8 personnes
*/ 
#include <stdio.h> 
#include <stdlib.h> 
int main(){ 
    // variables contenant les quantités
    float pruneaux, farine, sucre, lait, nbpers; 
    int oeufs; 
    // initialisation des quantités
    pruneaux = 250.0; 
    farine = 200.0; 
    sucre = 150.0; 
    oeufs = 4; 
    lait = 0.75; 
    //Demande du nombre de nbperss
    printf("Pour combien de personnes est le gâteau ?\n");
    scanf("%f", &nbpers);
    // affichage des quantités
    printf("Pour préparer un Far Breton pour 8 nbperss, il faut :\n"); 
    printf(" %5.2f grammes de pruneaux\n",(nbpers * pruneaux) / 8); 
    printf(" %5.2f grammes de farine\n",(nbpers * farine) / 8); 
    printf(" %5.2f grammes de sucre\n",(nbpers * sucre) / 8); 
    printf(" %5.2f oeufs",(nbpers * oeufs) / 8); 
    printf(" %4.2f litre(s) de lait",(nbpers * lait) / 8); 
    return EXIT_SUCCESS; 
}

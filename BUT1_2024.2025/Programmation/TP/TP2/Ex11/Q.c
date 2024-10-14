/**
 * @file classement.c
 * @brief affiche dans quel quart de la promo se situe un étudiant
 * @author enseignantAP1
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define TAILLE_PROMO 120
/**
 * @brief entrée du programme
 * @return EXIT_SUCCESS : arrêt normal du programme
 */
int main() {
    int classement;   // classement de l'étudiant
    printf("Donnez votre classement : ");
    scanf("%d", &classement);

    if (classement<=(TAILLE_PROMO/4)){
        printf("Vous êtes dans le premier quart de la promo\n");
    } else if (classement <= (TAILLE_PROMO/2)){
        printf("Vous êtes dans le deuxième quart de la promo\n");
    } else if (classement<=(TAILLE_PROMO*3/4)){
        printf("Vous êtes dans le troisième quart de la promo\n");
    } else{
        printf("Vous êtes dans le quatrième quart de la promo\n");
    }

    return EXIT_SUCCESS;
}
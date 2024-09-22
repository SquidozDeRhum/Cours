#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char ch1[10], ch2[10], ch3[10];
    printf("Veuillez saisir une première chaine de caractères (10 caractères) : ");
    scanf("%s", ch1);
    printf("Veuillez saisir une seconde chaine de caractères (10 caractères) : ");
    scanf("%s", ch2);
    printf("Veuillez saisir une troisème chaine de caractères (10 caractères) : ");
    scanf("%s", ch3);

    if (strcmp(ch1, ch2) == 0 && strcmp(ch1,ch3) == 0 && strcmp(ch2, ch3) == 0) {
        printf("Ces trois chaînes sont identiques");
    } else if (strcmp(ch1, ch2) < 0 && strcmp(ch1, ch3) < 0) {
        printf("Affichage dans l'ordre alphabétique : \n");
        printf("%s\n", ch1);
        if ((strcmp(ch2, ch3) < 0)) {
            printf("%s\n", ch2);
            printf("%s\n", ch3);
        } else {
            printf("%s\n", ch3);
            printf("%s\n", ch2);
        }
    } else if (strcmp(ch2, ch3) < 0 && strcmp(ch2, ch1) < 0) {
        printf("Affichage dans l'ordre alphabétique : \n");
        printf("%s\n", ch2);
        if ((strcmp(ch1, ch3) < 0)) {
            printf("%s\n", ch1);
            printf("%s\n", ch3);
        } else {
            printf("%s\n", ch3);
            printf("%s\n", ch1);
        }
    } else {
        printf("Affichage dans l'ordre alphabétique : \n");
        printf("%s\n", ch3);
        if ((strcmp(ch1, ch2) < 0)) {
            printf("%s\n", ch1);
            printf("%s\n", ch2);
        } else {
            printf("%s\n", ch2);
            printf("%s\n", ch1);
        }
    }
    return EXIT_SUCCESS;
}
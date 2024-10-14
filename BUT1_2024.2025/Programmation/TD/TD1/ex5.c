#include <stdio.h>
#include <stdlib.h>

int main() {
    float DS1, DS2, TP, moyenneDS, moyenne;
    char nom[50];
    printf("Veuillez entrer votre nom : ");
    scanf("%s", &nom);
    printf("Veuillez entrer votre note au premier DS : ");
    scanf("%f", &DS1);
    printf("Veuillez entrer votre note au second DS : ");
    scanf("%f", &DS2);
    printf("Veuillez entrer votre note au TP : ");
    scanf("%f", &TP);
    moyenneDS = (DS1 + DS2 * 3) / 4;
    moyenne = (moyenneDS * 2 + TP) / 3;
    printf("La moyenne des DS de %s est : %f et sa moyenne général est : %f", nom, moyenneDS, moyenne);
    return 0;
}
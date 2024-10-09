#include <stdio.h>
#include <stdlib.h>

#define COEF1 1.0
#define COEF2 1.0

int main() {

    int nbEtud;
    float n1, n2, result;
    char nom[20];

    printf("Veuillez entrer le nombre d'étudiants du groupe : ");
    scanf("%d", &nbEtud);
    if (nbEtud > 0) {
        for (int i = 0; i< nbEtud; i++) {
            printf("Veuillez saisir le nom de l'étudiant : ");
            scanf("%s", nom);

            printf("Veuillez saisir la note de DS : ");
            scanf("%f", &n1);

            printf("Veuillez saisir la note de TP : ");
            scanf("%f", &n2);

            result = ((n1 * COEF1 + n2 * COEF2) / (COEF1 + COEF2));

            printf("%s a une moyenne de : %.2f\n", nom, result);
        }
    }
    else {
        printf("Le nombre d'étudiant entré est incorrect");
    }
    

    return 0;
}
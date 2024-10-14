#include <stdlib.h>
#include <stdio.h>

const float MOYENNEMIN = 10.0;
const float MOYENNEMINU = 8.0;

int main() {

    float UE1, UE2, moyenne;

    printf("Veuillez donner votre moyenne d'UE1 : ");
    scanf("%f", &UE1);
    printf("Veuillez donner votre moyenne d'UE2 : ");
    scanf("%f", &UE2);
    moyenne = (UE1 + UE2) / 2;
    if (moyenne < MOYENNEMIN) {
        printf("Le jury sera souverain de votre validation de semestre\n");
    } else if (UE1 < MOYENNEMIN || UE2 < MOYENNEMIN) {
        printf("Votre redoublement est acquis de droit, le jury peut toujours décider d'une validation\n");
    } else {
        printf("Votre semestre est validé\n");
    }
    return EXIT_SUCCESS;
}

/*
    Jeu de tests : 
    UE1 = 3; UE2 = 4; -> Jury souverain
    UE1 = 18; UE2 = 0; -> Jury souverain
    UE1 = 18; UE2 = 7; -> Redoublement de droit
    UE1 = 7; UE2 = 18; -> Redoublement de droit
    UE1 = 18; UE2 = 18; -> Semestre validé
*/
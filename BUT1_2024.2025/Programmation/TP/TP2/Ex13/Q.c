#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

const float TEA = 7;
const float TEB = 8;
const float TEC = 9;
const float TED = 10;

const float TAA = 12;
const float TAB = 14;
const float TAC = 16;
const float TAD = 18;

#define PA 'A'
#define PB 'B'
#define PC 'C'
#define PD 'D'

int main() {

    char periode;
    int adultes, enfants;
    float total;
    int jour, mois;

    printf("Veuillez entrer le mois : ");
    scanf("%d", &mois);
    printf("Veuillez entrer le jour : ");
    scanf("%d", &jour);

    if (mois >= 2 && mois <= 3) {
        periode = PA;
    } else if (mois >= 4 && mois <= 5) {
        periode = PB;
    } else if (mois >= 6 && mois <= 7) {
        periode = PC;
    } else if (mois >= 6 && mois <= 9) {
        if (mois == 9 && jour <= 30) {
            periode = PD;
        } else if (mois < 9) {
            periode = PD;
        }
    } else {
        printf("Le parc est fermé\n");
        periode = 'E';
    }

    printf("Veuillez entrer le nombre d'enfants : ");
    scanf("%d", &enfants);
    printf("Veuillez entrer le nombre d'adultes : ");
    scanf("%d", &adultes);

    if ((adultes < 1 || adultes > 10) || (enfants > 10 || enfants < 0)) {
        periode = 'E';
    }

    switch (toupper(periode)) {
        case PA:
            total = TEA * enfants + TAA * adultes;
            break;

        case PB:
            total = TEB * enfants + TAB * adultes;
            break;

        case PC:
            total = TEC * enfants + TAC * adultes;
            break;

        case PD:
            total = TED * enfants + TAD * adultes;
            break;
        
        default:
            fprintf(stderr, "Entrée incorrecte, veuillez réessayer\n");
            return EXIT_FAILURE;
            break;
    }

    printf("Votre total est de : %.2f\n", total);

    return EXIT_SUCCESS;
}

/* 
    periode = G -> ERREUR
    enfants = 15 -> ERREUR
    enfants = -3 -> ERREUR
    ADULTE = 15 -> ERREUR
    ADULTE = -3; -> ERREUR
    ADULTE = 0; enfants = 3; -> ERREUR
    PERIODE = 'A' ADULTE = 1; enfants = 1; -> 19
    PERIODE = 'B' ADULTE = 1; enfants = 1; -> 22
    PERIODE = 'C' ADULTE = 1; enfants = 1; -> 25
    PERIODE = 'D' ADULTE = 1; enfants = 1; -> 28
*/
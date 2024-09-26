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

    printf("Veuillez entrer la période : ");
    scanf("%c", &periode);
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
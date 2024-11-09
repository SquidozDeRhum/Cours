#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIERRE 'P'
#define FEUILLE 'F'
#define CISEAU 'C'
#define MANCHE_GAGNANTE 3

char duel(char act1, char act2);
char bot();
char game();

int main() {
    char gagnant;
    srand(time(NULL));
    
    gagnant = game();

    printf("Le gagnant est : %c\n", gagnant);

    return EXIT_SUCCESS;
}

char duel(char act1, char act2) {
    char result;
    if ((act1 == FEUILLE && act2 == PIERRE) || (act1 == PIERRE && act2 == CISEAU) || (act1 == CISEAU && act2 == FEUILLE)) {
        result = 'G';
    } else if (act1 == act2) {
        result = 'N';
    } else {
        result = 'P';
    }
    return result;
}

char bot() {
    int coup = rand() % 3;
    char coupBot[3] = "PFC";
    return coupBot[coup];
}

char game() {
    char coup, gagnant;
    int pointH = 0;
    int pointB = 0;
    printf("Partie de Pierre Feuille Ciseau !\n");
    while (pointB < MANCHE_GAGNANTE && pointH < MANCHE_GAGNANTE) {
        printf("Veuillez entrer votre coup (P F C) : ");
        scanf(" %c", &coup);
        if (duel(coup, bot()) == 'G') {
            printf("Vous avez gagné cette manche !\n");
            pointH++;
        } else if (duel(coup, bot()) == 'P') {
            printf("Vous avez perdu cette manche ...\n");
            pointB++;
        } else {
            printf("Egalité !\n");
        }
    }

    if (pointH > pointB) {
        gagnant = 'H';
    } else {
        gagnant = 'O';
    }

    return gagnant;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void faireJouer(char j, int *score);
void afficheResultat(int score1, int score2);

#define JOUEURA 'A'
#define JOUEURB 'B'
#define WIN 50

int main() {
    int score1, score2;
    char joueur = JOUEURA;
    score1 = 0;
    score2 = 0;

    while (score1 < WIN && score2 < WIN) {
        if (joueur == JOUEURA) {
            faireJouer(JOUEURA, &score1);
            joueur = JOUEURB;
        } else {
            faireJouer(JOUEURB, &score2);
            joueur = JOUEURA;
        }
    }

    afficheResultat(score1, score2);

    return EXIT_SUCCESS;
}

void faireJouer(char j, int *score) {
    int scoreJ;
    printf("Valeur dé joueur %c : ", j);
    scanf("%d", &scoreJ);
    if (scoreJ == 6) {
        *score += scoreJ;
        printf("Rejouez : ");
        scanf("%d", &scoreJ);
    }
    *score += scoreJ;
}

void afficheResultat(int score1, int score2) {
    printf("Score joueur A : %d\n", score1);
    printf("Score joueur B : %d\n", score2);
    if (score1 > score2) {
        printf("Vainqueur : A\n");
    } else {
        printf("Vainqueur : B\n");
    }
}
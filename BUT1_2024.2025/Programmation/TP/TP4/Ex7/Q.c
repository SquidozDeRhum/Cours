#include <stdio.h>
#include <stdlib.h>

#define PLUS '+'
#define MOINS '-'
#define FOIS '*'
#define DIVISE '/'
#define ARRET ':'

void usage();
void calcul(int a, int b, char c);

int main() {
    int a, b;
    char c;
    usage();
    printf("Veuillez donner un entier, un opérateur et un entier : ");
    scanf("%d %c %d", &a, &c, &b);
    calcul(a, b, c);
    while (c != ':') {
        printf("Veuillez donner un entier, un opérateur et un entier séparé par un espace :");
        scanf("%d %c %d", &a, &c, &b);
        calcul(a, b, c);
    }


    return EXIT_SUCCESS;
}


void usage() {
    printf("Ecrivez une suite d’operations sous la forme:\n");
    printf("<operande> <operateur> <operande>\n");
    printf("Pour terminer utilisez \":\" comme operateur.\n");
    printf("Par exemple \"0 : 0\" stoppe le programme\n");
}

void calcul(int a, int b, char c) {
    switch (c) {
        case PLUS:
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case MOINS:
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case FOIS:
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case DIVISE:
            if (b != 0) {
                printf("%d / %d = %.2f\n", a, b, (a * 1.0) / (b * 1.0));
            }
            else {
                printf("On divise pas par zéro ici\n");
            }
            break;
        case ARRET:
            printf("Au revoir...\n");
            break;
        default:
            printf("ERREUR DE SAISIE\n");
            break;
    }
}
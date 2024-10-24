#include <stdio.h>
#include <stdlib.h>

#define PLUS '+'
#define MOINS '-'
#define FOIS '*'
#define DIVISE '/'

void usage();
void calcul(int a, int b, char c);

int main() {
    usage();


    return EXIT_SUCCESS;
}


void usage() {
    printf("Ecrivez une suite d’operations sous la forme:\n");
    printf("<operande> <operateur> <operande>\n");
    printf("Pour terminer utilisez ":" comme operateur.\n");
    printf("Par exemple "0 : 0" stoppe le programme\n");
}

void calcul(int a, int b, char c) {
    switch () {
        case PLUS:
            printf("%d + %d = %d", a, b, a + b);
            break;
        case MOINS:
            printf("%d - %d = %d", a, b, a - b);
            break;
        case FOIS:
            printf("%d * %d = %d", a, b, a * b);
            break;
        case DIVISE:
            if (b != 0) {
                printf("%d / %d = %f", a, b, (a * 1.0) / (b * 1.0));
            }
            else {
                printf("Chef on divise pas par zéro ici");
            }
            break;
        default:
            printf("ERREUR DE SAISIE FRERE");
            break;
    }
}
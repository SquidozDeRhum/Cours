#include <stdlib.h>
#include <stdio.h>

void ligneTirets(int n);
void ligneCourante(int n);
void corps(int n, int larg);

int main() {
    int h, l;
    printf("Hauteur : ");
    scanf("%d", &h);
    printf("Largeur : ");
    scanf("%d", &l);
    corps(h, l);

    return EXIT_SUCCESS;
}

void ligneTirets(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void ligneCourante(int n) {
    printf("I");
    for (int i = 0; i < n - 2; i++) {
        printf(" ");
    }
    printf("I");
    printf("\n");
}

void corps(int n, int larg) {
    ligneTirets(larg);
    for (int i = 0; i < n; i++) {
        ligneCourante(larg);
    }
    ligneTirets(larg);
}
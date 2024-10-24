#include <stdio.h>
#include <stdlib.h>

void ligneTirets(int n);
void ligneCourante(int n1);
void corps(int n);

int main() {
    int h;
    printf("Hauteur : ");
    scanf("%d", &h);
    corps(h);

    return EXIT_SUCCESS;
}

void ligneTirets(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void ligneCourante(int n1) {
    printf("I");
    for (int i = 0; i < n1 -1; i++) {
        printf(" ");
    }    
    printf("\\");
    printf("\n");
}

void corps(int n) {
    for (int i = 1; i <= n; i++) {
        ligneCourante(i);
    }
    ligneTirets(n+1);
}
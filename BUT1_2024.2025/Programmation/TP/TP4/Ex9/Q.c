#include <stdio.h>
#include <stdlib.h>

void ligneTirets(int n);
void ligneCourante(int n1, int n);
void corps(int n);

int main() {
    int h;
    printf("Hauteur : ");
    scanf("%d", &h);
    corps(h);

    return EXIT_SUCCESS;
}

void ligneTirets(int n) {
    for (int i = 2; i < 2 * n; i++) {
        printf("-");
    }
    printf("\n");
}

void ligneCourante(int n1, int n) {
    for (int i = 0; i < n - n1; i++) {
        printf(" ");
    }    
    printf("/");
    for (int i = 0; i < n1 * 2 - 2; i++) {
        printf(" ");
    }    
    printf("\\");
    printf("\n");
}

void corps(int n) {
    for (int i = 1; i <= n; i++) {
        ligneCourante(i, n);
    }
    ligneTirets(n+1);
}
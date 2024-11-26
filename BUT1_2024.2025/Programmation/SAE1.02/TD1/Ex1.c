#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 300000

typedef int tableau[N];

void tri_insertion(tableau T);

void init_ale(tableau T);

int comp = 0;
int perm = 0;

int main(){
    srand(time(NULL));
    tableau T;
    init_ale(T);
    for (int i = 0; i < N; i++) {
        printf("Elément %d du tableau : %d\n", i, T[i]);
    }
    tri_insertion(T);
    printf("-------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("Elément %d du tableau trié : %d\n", i, T[i]);
    }
    printf("Nombre de comparaisons : %d\nNombre de permutations : %d", comp, perm);
    return EXIT_SUCCESS;
}

void tri_insertion(tableau T) {
    int x, j;
    for (int i = 1; i < N; i++) {
        x = T[i];

        j = i;
        while (j > 0 && T[j - 1] > x) {
            comp++;
            T[j] = T[j-1];
            perm++;
            j--;
        }
        T[j] = x;
    }
}

void init_ale(tableau T) {
    for (int i = 0; i < N; i++) {
        T[i] = rand() % 100000;
    }
}
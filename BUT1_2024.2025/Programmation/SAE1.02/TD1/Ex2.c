#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 300000

typedef int tableau[N];

int partition(tableau T, int debut, int fin, int pivot);

void triRapide(tableau T, int debut, int fin);

void init_ale(tableau T);

int comp = 0;
int perm = 0;

int main() {
    srand(time(NULL));
    tableau T;
    init_ale(T);
    for (int i = 0; i < N; i++) {
        printf("Elément %d du tableau : %d\n", i, T[i]);
    }
    triRapide(T, 0, N - 1);
    printf("-------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("Elément %d du tableau trié : %d\n", i, T[i]);
    }
    printf("Nombre de comparaisons : %d  Nombre de permutations : %d", comp, perm);

    return EXIT_SUCCESS;
}

int partition(tableau T, int debut, int fin, int pivot) {
    int buffer = T[fin];
    T[fin] = T[pivot];
    perm++;
    T[pivot] = buffer;
    perm++;
    int j = debut;
    for (int i = debut; i < fin; i++) {
        if (T[i] <= T[fin]) {
            comp++;
            buffer = T[i];
            T[i] = T[j];
            perm++;
            T[j] = buffer;
            perm++;
            j++;
        }
    }
    buffer = T[fin];
    T[fin] = T[j];
    perm++;
    T[j] = buffer;
    perm++;

    return j;
}

void triRapide(tableau T, int debut, int fin) {
    int pivot;
    if (debut < fin) {
        comp++;
        pivot = (debut + fin) / 2;
        pivot = partition(T, debut, fin, pivot);
        triRapide(T, debut, pivot-1);
        triRapide(T, pivot+1, fin);
    }
}

void init_ale(tableau T) {
    for (int i = 0; i < N; i++) {
        T[i] = rand() % 100000;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 300000

typedef int tableau[N];

void triParTas(tableau T);

void tamiser(tableau T, int noeud, int n);

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
    triParTas(T);
    printf("-------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("Elément %d du tableau trié : %d\n", i, T[i]);
    }
    printf("Nombre de comparaisons : %d  Nombre de permutations : %d", comp, perm);
    
    return EXIT_SUCCESS;
}


void init_ale(tableau T) {
    for (int i = 0; i < N; i++) {
        T[i] = rand() % 100000;
    }
}

void tamiser(tableau T, int noeud, int n) {
    int fils = 2*noeud + 1;
    int buffer;
    if (fils < n && T[fils+1] > T[fils]) {
        comp++;
        fils++;
    }

    if (fils <= n && T[noeud] < T[fils]) {
        comp++;
        buffer = T[fils];
        T[fils] = T[noeud];
        perm++;
        T[noeud] = buffer;
        perm++;
        tamiser(T, fils, n);
    }
}

void triParTas(tableau T) {
    int buffer;
    for (int i = N/2 - 1; i >= 0; i--) {
        tamiser(T, i , N-1);
    }

    for (int i = N-1; i >= 0; i--) {
        buffer = T[i];
        T[i] = T[0];
        perm++;
        T[0] = buffer;
        perm++;
        tamiser(T, 0, i-1);
    }
}
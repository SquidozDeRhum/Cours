#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define MAX 100000

typedef int t_tab[N];

void tri_bulles(t_tab tablo);
void remplirTableau(t_tab t);

int main() {

    srand(time(NULL));
    t_tab tablo;

    remplirTableau(tablo);

    printf("Tableau non trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    tri_bulles(tablo);

    printf("\nTableau trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    return EXIT_SUCCESS;
}

void tri_bulles(t_tab tablo) {
    int buffer;
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (tablo[j] > tablo[j + 1]) {
                buffer = tablo[j];
                tablo[j] = tablo[j + 1];
                tablo[j + 1] = buffer;
            }
        }
    }
}

void remplirTableau(t_tab t) {
    for (int i = 0; i < N; i++) {
        t[i] = rand() % MAX;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define MAX 100000

typedef int t_tab[N];

void triSelection_croi(t_tab tablo);
int minimum(t_tab tablo, int stage);
void remplirTableau(t_tab t);

int main() {

    srand(time(NULL));
    t_tab tablo;

    remplirTableau(tablo);

    printf("Tableau non trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    triSelection_croi(tablo);

    printf("\nTableau trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    return EXIT_SUCCESS;
}

void triSelection_croi(t_tab tablo) {
    int stage = 0;
    int i_min;
    int buffer;
    while (stage < N - 1)
    {
        i_min = minimum(tablo, stage);
        if (tablo[stage] != tablo[i_min]) {
            buffer = tablo[stage];
            tablo[stage] = tablo[i_min];
            tablo[i_min] = buffer;
        }
        stage++;
    }
    
    
}

int minimum(t_tab tablo, int stage) {
    int i_min = stage;
    int min = tablo[stage];
    for (int i = stage + 1; i < N; i++) {
        if (tablo[i] < min) {
            min = tablo[i];
            i_min = i;
        }
    }
    return i_min;
}

void remplirTableau(t_tab t) {
    for (int i = 0; i < N; i++) {
        t[i] = rand() % MAX;
    }
}
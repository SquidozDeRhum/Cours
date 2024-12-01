#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define MAX 100000

typedef int t_tab[N];

void triSelection_dec(t_tab tablo);
int maximum(t_tab tablo, int stage);
void remplirTableau(t_tab t);

int main() {

    srand(time(NULL));
    t_tab tablo;

    remplirTableau(tablo);

    printf("Tableau non trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    triSelection_dec(tablo);

    printf("\nTableau trié : \n");
    for (int i = 0; i < N; i++) {
        printf("Indice %d : %d\n", i, tablo[i]);
    }

    return EXIT_SUCCESS;
}

void triSelection_dec(t_tab tablo) {
    int stage = 0;
    int i_min;
    int buffer;
    while (stage < N - 1)
    {
        i_min = maximum(tablo, stage);
        buffer = tablo[stage];
        tablo[stage] = tablo[i_min];
        tablo[i_min] = buffer;
        stage++;
    }
    
    
}

int maximum(t_tab tablo, int stage) {
    int i_max = stage;
    int max = tablo[stage];
    for (int i = stage + 1; i < N; i++) {
        if (tablo[i] > max) {
            max = tablo[i];
            i_max = i;
        }
    }
    return i_max;
}

void remplirTableau(t_tab t) {
    for (int i = 0; i < N; i++) {
        t[i] = rand() % MAX;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10
#define K 20

typedef int t_tab2dim[N][K];

void initialiser(t_tab2dim tab);
void afficher(t_tab2dim tab);
bool existe(t_tab2dim tab, int value);

int main() {
    t_tab2dim feur;
    initialiser(feur);
    afficher(feur);
    printf("Valeur trouvée : %d\n", existe(feur, 35));

    return EXIT_SUCCESS;
}

void initialiser(t_tab2dim tab) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            tab[i][j] = i + j;
        }
    }
}

void afficher(t_tab2dim tab) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%3d", tab[i][j]);
        }
        printf("\n");
    }
}

bool existe(t_tab2dim tab, int value) {
    int i, j;
    i = 0;
    j = 0;
    bool trouve = false;
    while (trouve != true && i < N) {
        while (trouve != true && j < K) {
            if (tab[i][j] == value) {
                trouve = true;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return trouve;
}
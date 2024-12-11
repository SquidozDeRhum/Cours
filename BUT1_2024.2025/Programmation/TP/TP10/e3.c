#include <stdlib.h>
#include <stdio.h>

#define MAX 198 // 22 équipes de 9 coureurs = 198 coureurs

typedef struct{
    int c_numero;
    int c_temps;
}t_concurrent;

typedef t_concurrent t_tabconc[MAX];

void insere(t_concurrent c, t_tabconc tc, int n);
void permuter(t_concurrent* c1, t_concurrent* c2);
void affiche_classement(t_tabconc tc, int n);

int main() {
    int num, temps;
    int n = 0;
    t_concurrent conc;
    t_tabconc tab;
    printf("Temps du candidat : ");
    scanf("%d", &temps);
    printf("Num du candidat : ");
    scanf("%d", &num);
    if (num != -1) {
        conc.c_numero = num;
        conc.c_temps = temps;

        insere(conc, tab, n);
        n++;
    }
    affiche_classement(tab, n);

    while (num != -1)
    {
        if (n != MAX) {
            printf("Temps du candidat : ");
            scanf("%d", &temps);
            printf("Num du candidat : ");
            scanf("%d", &num);
            if (num != -1) {
                conc.c_numero = num;
                conc.c_temps = temps;

                insere(conc, tab, n);
                n++;
            }
        } else {
            printf("Tableau rempli\n");
            num = -1;
        }
        affiche_classement(tab, n);
    }

    printf("Au revoir :)\n");

    return EXIT_SUCCESS;
}

void insere(t_concurrent c, t_tabconc tc, int n) {
    tc[n] = c;
    int i = 1;
    while (tc[n - i].c_temps > tc[n - i + 1].c_temps && i <= n)
    {
        permuter(&tc[n - i], &tc[n - i + 1]);
        i++;
    }
    
}

void permuter(t_concurrent* c1, t_concurrent* c2) {
    t_concurrent buffer = *c1;
    *c1 = *c2;
    *c2 = buffer;
}

void affiche_classement(t_tabconc tc, int n) {
    for (int i = 0; i < n; i++) {
        printf("Place %d : Num - %d Temps - %d\n", i + 1, tc[i].c_numero, tc[i].c_temps);
    }
}
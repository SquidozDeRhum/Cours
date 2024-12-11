#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NM 12
typedef char t_chaine9[10];

typedef  struct{
    t_chaine9 c_nom;
    int      c_nbJours;
} t_mois;

typedef t_mois t_tabMois[NM];

t_tabMois tMois= { 
    {"janvier",31},
    {"fevrier",28},
    {"mars",31},
    {"avril",30},
    {"mai",31},
    {"juin",30},
    {"juillet",31},
    {"aout",31},
    {"septembre",30},
    {"octobre",31},
    {"novembre",30},
    {"decembre", 31}
};

void display(t_tabMois mois);
int nombreJours(t_chaine9 nomMois);

int main() {
    t_chaine9 mois;
    printf("Veuillez donner un mois (minuscule) : ");
    scanf("%s", mois);
    int result = nombreJours(mois);
    if (result != -1) {
        printf("Le mois de %s a %d jours\n", mois, result);
    } else {
        printf("Erreur, mois entré incorrect\n");
    }

    return EXIT_SUCCESS;
}

void display(t_tabMois mois) {
    for (int i = 0; i < NM; i++) {
        if (mois[i].c_nbJours == 31) {
            printf("%s\n", mois[i].c_nom);
        }
    }
}

int nombreJours(t_chaine9 nomMois) {
    int value = -1;
    int i = 0;
    while (value == -1 && i < NM)
    {
        if (strcmp(tMois[i].c_nom, nomMois) == 0) {
            value = tMois[i].c_nbJours;
        }
        i++;
    }
    return value;
}
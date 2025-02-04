#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define FILELENGHT 21
#define MAX 100

#define CREATEADD 1
#define LIST 2
#define STOP 3
#define TRI 4

typedef char t_chaine50[51] ;
typedef char t_chaine10[11] ;

typedef struct{ 
    t_chaine50 c_nom;   // nom de l’abonné
    t_chaine10 c_num; // numéro de cet abonné
    int c_duree;  // durée pour laquelle il est abonné
} t_abonne ;

typedef t_abonne t_tabAbo[MAX];
int created = 0;

void createadd(char nomFic[]);
void list(char nomFic[]);
void menu();
void copie(char nomFic[], t_tabAbo tab);
void mTrie(t_tabAbo tab, int i);
void permuter(t_abonne *a1, t_abonne *a2);
void tri(char nomFic[]);
void copieFic(char nomFic[], t_tabAbo t, int nb);

int main() {

    int choice;
    char filename[FILELENGHT];
    t_tabAbo feur;

    printf("Nom du fichier : ");
    scanf("%s", filename);
    printf("Fichier existant (0 ou 1) : ");
    scanf("%d", &created);
    menu();
    scanf("%d", &choice);

    while (choice != STOP)
    {
        switch (choice)
        {
        case CREATEADD:
            createadd(filename);
            break;
        case LIST:
            list(filename);
            break;

        case TRI:
            copie(filename, feur);
        }
        menu();
        scanf("%d", &choice);
    } 
    
    return EXIT_SUCCESS;
}

void createadd(char nomFic[]) {

    FILE *f;

    if (created == 0) {
        f =  fopen(nomFic, "w");
        fclose(f);
        created = 1;
    }

    f = fopen(nomFic, "a");

    t_abonne abo;

    printf("Nom : ");
    scanf("%s", abo.c_nom);

    if (strcmp(abo.c_nom, "*") != 0) {
        printf("Num : ");
        scanf("%s", abo.c_num);

        printf("Duree : ");
        scanf("%d", &abo.c_duree);
    }

    while (strcmp(abo.c_nom, "*") != 0)
    {
        fwrite(&abo, sizeof(abo), 1, f);
        printf("Nom : ");
        scanf("%s", abo.c_nom);

       if (strcmp(abo.c_nom, "*") != 0) {
            printf("Num : ");
            scanf("%s", abo.c_num);

            printf("Duree : ");
            scanf("%d", &abo.c_duree);
        }
    }
    
    fclose(f);
}

void list(char nomFic[]) {
    FILE *f;
    f = fopen(nomFic, "r");
    t_abonne abo;
    int i = 0;

    fread(&abo, sizeof(abo), 1, f);

    while (feof(f) != 1)
    {
        printf("Abonne %d : \n", i);
        printf("Nom : %s\n", abo.c_nom);
        printf("Num : %s\n", abo.c_num);
        printf("Duree : %d\n", abo.c_duree);
        printf("\n");
        fread(&abo, sizeof(abo), 1, f);
        i++;
    }
    
}

void menu() {
    printf("\n1 - Créer et remplir/combler un fichier\n");
    printf("2 - Lister le fichier (Faut mettre des trucs dedans sinon ça crash)\n");
    printf("3 - Fin\n");
    printf("4 - Tri\n");
    printf("Choix : ");
}

void copie(char nomFic[], t_tabAbo tab) {
    int i = 0;

    FILE *f;
    f = fopen(nomFic, "r");

    fread(&tab[i], sizeof(tab[i]), 1, f);

    while (feof(f) != 1 && i < MAX)
    {
        mTrie(tab, i);
        i++;
        fread(&tab[i], sizeof(tab[i]), 1, f);
    }    
    fclose(f);
    copieFic(nomFic, tab, i);
}

void mTrie(t_tabAbo tab, int i) {
    int n = 1;
    while (strcmp(tab[i - n].c_nom, tab[i - n + 1].c_nom) > 0 && n <= i)
    {
        permuter(&tab[i - n], &tab[i - n + 1]);
        n++;
    }
    
}

void permuter(t_abonne *a1, t_abonne *a2) {
    t_abonne buffer;
    buffer = *a1;
    *a1 = *a2;
    *a2 = buffer;
}

void copieFic(char nomFic[], t_tabAbo t, int nb) {
    FILE *f;
    f = fopen(nomFic, "w");
    for (int i = 0; i < nb; i++) {
        fwrite(&t[i], sizeof(t[i]), 1, f);
    }
    fclose(f);
}
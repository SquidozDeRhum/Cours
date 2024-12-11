#include <stdlib.h>
#include <stdio.h>

#define TAILLE 21

typedef char chaine20[TAILLE];

typedef struct
{
    chaine20 nom;
    chaine20 prenom;
    int age;
} t_etudiant;

void display(t_etudiant etudiant);
void init(t_etudiant *etudiant);
int compare(t_etudiant e1, t_etudiant e2);

int main() {
    t_etudiant etudiant1, etudiant2;
    printf("Etudiant 1 : \n");
    init(&etudiant1);
    display(etudiant1);

    printf("Etudiant 2 : \n");
    init(&etudiant2);
    display(etudiant2);

    if (compare(etudiant1, etudiant2) == 0) {
        printf("Les deux étudiants ont le même âge\n");
    } else if (compare(etudiant1, etudiant2) == 1) {
        printf("%s %s est plus vieux que %s %s\n", etudiant1.prenom, etudiant1.nom, etudiant2.prenom, etudiant2.nom);
    } else {
        printf("%s %s est plus jeune que %s %s\n",  etudiant1.prenom, etudiant1.nom, etudiant2.prenom, etudiant2.nom);
    }

    return EXIT_SUCCESS;
}

void display(t_etudiant etudiant) {
    printf("Etudiant : %s %s, %d ans.\n", etudiant.prenom, etudiant.nom, etudiant.age);
}

void init(t_etudiant *etudiant) {
    printf("Prenom de l'étudiant : ");
    scanf("%s", etudiant->prenom);
    printf("Nom de l'étudiant : ");
    scanf("%s", etudiant->nom);
    printf("Age de l'étudiant : ");
    scanf("%d", &etudiant->age);
}

int compare(t_etudiant e1, t_etudiant e2) {
    int value;
    if (e1.age == e2.age) {
        value = 0;
    } else if (e1.age > e2.age) {
        value = 1;
    } else {
        value = -1;
    }
    return value;
}
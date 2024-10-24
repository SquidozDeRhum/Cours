#include <stdio.h>
#include <stdlib.h>

#define AUTEUR "Henri Aubrée"
#define MATIERE "Algorithme et Programmation"
#define EXERCICE "Introduction aux procedures"
#define GROUPE "B2"

void info();

int main() {
    info();
    return EXIT_SUCCESS;
}

void info() {
    printf("Auteur : %s\n", AUTEUR);
    printf("Matiere : %s\n", MATIERE);
    printf("Exercice : %s\n", EXERCICE);
    printf("Groupe : %s\n", GROUPE);
}
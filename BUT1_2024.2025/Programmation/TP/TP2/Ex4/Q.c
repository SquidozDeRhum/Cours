#include <stdlib.h>
#include <stdio.h>

int main() {
    int j1, m1, a1, j2, m2, a2;
    //Première date
    printf("Veuillez saisir le jour de la première date : ");
    scanf("%d", &j1);
    printf("Veuillez saisir le mois de la première date : ");
    scanf("%d", &m1);
    printf("Veuillez saisir l'année de la première date : ");
    scanf("%d", &a1);
    //Seconde date
    printf("Veuillez saisir le jour de la seconde date : ");
    scanf("%d", &j2);
    printf("Veuillez saisir le mois de la seconde date : ");
    scanf("%d", &m2);
    printf("Veuillez saisir l'année de la seconde date : ");
    scanf("%d", &a2);
    if (a1 < a2) {
        printf("La date la plus ancienne est la première\n");
    } else if (a1 == a2){
        if (m1 < m2) {
            printf("La date la plus ancienne est la première\n");
        } else if (m1 == m2) {
            if (j1 < j2) {
                printf("La date la plus ancienne est la première\n");
            } else if (j1 == j2) {
                printf("Ces deux dates sont les mêmes\n");
            } else {
                printf("La date la plus ancienne est la seconde\n");
            }
        } else {
            printf("La date la plus ancienne est la seconde\n");
        }
    } else {
        printf("La date la plus ancienne est la seconde\n");
    }
}
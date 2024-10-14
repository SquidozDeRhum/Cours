#include <stdio.h>
#include <stdlib.h>

int main() {
    int annee, res;
    printf("En quelle année êtes-vous né ? ");
    scanf("%d", &annee);
    res = 2030 - annee;
    printf("\n");
    printf("Vous aurez %d ans en 2030.", res);
}
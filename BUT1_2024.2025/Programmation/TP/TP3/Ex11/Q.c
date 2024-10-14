#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count, i;
    char suite[1024];
    count = 0;
    i = 0;
    printf("Veuillez saisir un suite de caractères : ");
    fgets(suite, 1024, stdin);

    while (i < strlen(suite)) {
        if (suite[i] == 'a') {
            count++;
        }
        i++;
    }

    printf("Il y a %d fois la lettre 'a' dans la suite : %s\n", count, suite);

    return 0;
}
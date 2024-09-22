#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char ch1[10], ch2[10];
    int result;
    printf("Veuillez saisir une première chaine de caractères (10 caractères) : ");
    scanf("%s", ch1);
    printf("Veuillez saisir une seconde chaine de caractères (10 caractères) : ");
    scanf("%s", ch2);
    result = strcmp(ch1, ch2);
    if (result == 0) {
        printf("Ces deux chaînes sont identiques\n");
    } else {
        printf("Ces deux chaînes sont différentes\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {

    int value, i, found;

    i = 2;
    found = 0;

    printf("Veuillez saisir un nombre : ");
    scanf("%d", &value);

    while (i < value && found < 1)
    {
        if (value % i == 0) {
            found += 1;
        }
        i++;
    }
    
    if (found < 1) {
        printf("Le nombre est premier\n");
    }
    else {
        printf("Le nombre n'est pas premier\n");
    }

    return 0;
}
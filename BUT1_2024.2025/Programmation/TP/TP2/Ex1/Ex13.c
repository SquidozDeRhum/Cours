#include <stdio.h>
#include <stdlib.h>
int main()
{
    int age;
    printf("Quel est votre age ? ");
    scanf("%d", &age);
    if (age >= 7 && age <= 77)
    {
        printf("Vous pouvez lire le journal de Tintin\n");
    }
    else {
        printf("Vous ne pouvez pas lire le journal de Tintin\n");
    }
    return EXIT_SUCCESS;
}
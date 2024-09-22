#include <stdio.h>
#include <stdlib.h>
int main()
{
    int age;
    printf("Quel est votre age ? ");
    scanf("%d", &age);
    if (age < 7 || age > 77)
    {
     printf("Désolé, vous ne pouvez pas lire le journal de Tintin");
    }
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    char car;
    printf("Veuillez choisir un caractère : ");
    scanf("%c", &car);
    printf("\n");
    printf("   %c   \n", car);
    printf("  %c %c  \n", car, car);
    printf(" %c   %c  \n", car, car);
    printf("%c%c%c%c%c%c%c\n", car, car, car, car, car, car, car);
    return 0;
}
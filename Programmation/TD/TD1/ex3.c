#include <stdio.h>
#include <stdlib.h>

int main() {
    //Echange
    char a, b, c;
    printf("Veuillez entrer la valeur de a : ");
    scanf("%c", &a);
    printf("Veuillez entrer la valeur de b : ");
    scanf("%c", &b);
    printf("a : %c b : %c", a, b);
    c = a;
    a = b;
    b = c;
    printf("a : %c b : %c", a, b);
}
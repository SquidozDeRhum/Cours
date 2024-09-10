#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, res;
    prinf("Veuillez entrer un premier nombre : ");
    scanf("%f", &a);
    prinf("Veuillez entrer un second nombre : ");
    scanf("%f", &b);
    res = (a + b) / 2;
    printf("La moyenne de vos deux nombres est : %f", res);
    return 0;
}
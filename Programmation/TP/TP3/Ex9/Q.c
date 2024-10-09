#include <stdio.h>
#include <stdlib.h>

int main() {

    float value, result;
    int pow;

    printf("Veuillez saisir un réel : ");
    scanf("%f", &value);

    printf("Veuillez saisir une puissance : ");
    scanf("%d", &pow);

    result = value;

    for (int i = 1; i < pow; i++) {
        result *= value;
    }

    printf("%.2f à la puissance %d est égale à : %.2f\n", value, pow, result);

    return 0;
}
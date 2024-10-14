#include <stdio.h>
#include <stdlib.h>
int main (){
    int result = 1;
    int n;

    printf("Veuillez entrer un entier naturel : ");
    scanf("%d", &n);

    for (int i = 1; i<=n; i++) {
        result *= i;
    }
    printf("Result : %d\n", result);
    return 0;
}
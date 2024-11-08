#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fcalcul(int v1, int v2);

int main() {
    float hyp;
    int c1, c2;

    printf("Premier côté : ");
    scanf("%d", &c1);
    printf("Second côté : ");
    scanf("%d", &c2);

    hyp = fcalcul(c1, c2);
    printf("Hyp : %.2f\n", hyp);

    return EXIT_SUCCESS;
}

float fcalcul(int v1, int v2) {
    return sqrtf(v1 * v1 + v2 * v2);
}
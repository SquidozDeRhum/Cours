#include <stdio.h>
#include <stdlib.h>

int main() {
    float p, s, t, q, m1, m2, mt;
    printf("Veuillez saisir une première température (8:00): ");
    scanf("%f", &p);
    printf("Veuillez saisir une seconde température (10:00): ");
    scanf("%f", &s);
    printf("Veuillez saisir une troisième température (14:00): ");
    scanf("%f", &t);
    printf("Veuillez saisir une quatrième température (16:00): ");
    scanf("%f", &q);
    m1 = (p + s) / 2;
    m2 = (t + q) / 2;
    mt = (m1 + m2) / 2;
    printf("La moyenne des températures du matin est : %.1f \n", m1);
    printf("La moyenne des températures de l'après-midi est : %.1f \n", m2);
    printf("La moyenne des températures de la journée est : %.1f \n", mt);
}
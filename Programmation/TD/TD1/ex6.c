#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool code, acc, res;
    int age, heures;
    printf("Avez-vous le code ?");
    scanf("%d", &code);
    printf("Avez-vous fait de la conduite accompagnée ?");
    scanf("%d", &acc);
    printf("Quel âge avez-vous ?");
    scanf("%d", &age);
    printf("Combien d'heures de conduite avez-vous fait ?");
    scanf("%d", &heures);
    if (acc == true) {
        bool an;
        printf("Avez-vous fait plus d'un an de conduite accompagnée ?");
        scanf("%d", &an);
        if (an == true && code == true && age > 18 && heures > 0) {
            res = true;
        }
        else res = false;
    }
    else {
        if (code == true && age > 18 && heures > 25) {
            res = true;
        }
        else res = false;
    }
    printf("Possibilité de passer le permis : %d", res);
}
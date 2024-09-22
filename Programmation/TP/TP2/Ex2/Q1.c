#include <stdlib.h>
#include <stdio.h>

int main() {
    int age;
    printf("Veuillez saisir votre âge : ");
    scanf("%d", &age);
    if (age > 18) {
        printf("Vous êtes majeur");
    } else {
        print("Vous êtes mineur");
    }
}
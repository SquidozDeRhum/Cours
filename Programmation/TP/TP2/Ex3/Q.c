#include <stdlib.h>
#include <stdio.h>

int main() {
    int place, sec;
    printf("Quelle est votre place en demi-finale ? ");
    scanf("%d", &place);
    if (place == 1 || place == 2) {
        printf("Vous êtes qualifié !\n");
    }
    else if (place == 3) {
        printf("Quel est votre temps ? ");
        scanf("%d", &sec);
        if (sec < 47) {
            printf("Vous êtes qualifié !\n");
        }
        else {
            printf("Vous n'êtes pas qualifié ;(\n");
        }
    }
    else {
        printf("Vous n'êtes pas qualifié ;(\n");
    }
    return 0;
}
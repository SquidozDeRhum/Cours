#include <stdio.h>
#include <stdlib.h>

int ET(int b1, int b2);
int OU(int b1, int b2);
int OUEX(int b1, int b2);

void add_b(int b1, int b2, int c);

int main() {
    int b1, b2, c;
    for (int i = 0; i < 8; i++) {
        scanf("%d %d %d", &b1, &b2, &c);
        printf("%d %d %d\n", b1, b2, c);
        add_b(b1, b2, c);
    }

    return EXIT_SUCCESS;
}

int ET(int b1, int b2) {
    return b1 * b2;
}

int OU(int b1, int b2) {
    return (b1 + b2) - (b1 * b2);
}

int OUEX(int b1, int b2) {
    return (b1 + b2) - 2 * (b1 * b2);
}

void add_b(int b1, int b2, int c) {
    int s, cout;
    s = OUEX(OUEX(b1, b2), c);
    cout = OU(ET(OUEX(b1, b2), c), ET(b1, b2));
    printf("S : %d\n", s);
    printf("Cout : %d\n", cout);
}
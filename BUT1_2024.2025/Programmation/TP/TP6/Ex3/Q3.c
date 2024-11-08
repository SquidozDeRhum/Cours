#include <stdio.h>
#include <stdlib.h>

int fac(int n);
void test();

int main() {
    test();
    return EXIT_SUCCESS;
}

int fac(int n) {
    int result = 1;
    for (int i = 1; i < n + 1; i++) {
        result *= i;
    }
    return result;
}

void test(){
    printf("valeur attendue : %d valeur obtenue : %d\n",1, fac(0));
    printf("valeur attendue : %d valeur obtenue : %d\n",1, fac(1));
    printf("valeur attendue : %d valeur obtenue : %d\n",2, fac(2));
    printf("valeur attendue : %d valeur obtenue : %d\n",6, fac(3));
    printf("valeur attendue : %d valeur obtenue : %d\n",5040, fac(7));
}
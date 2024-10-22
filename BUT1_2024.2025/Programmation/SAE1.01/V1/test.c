#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {

    printf("Feur");
    fflush(stdout);

    usleep(999999);

    printf("Jaaj");
}
#include <stdio.h>
#include <time.h>
# include "fonctions_date.h"
int main() {
    char date[MAX_SIZE];
    long temps;
    temps = time(NULL); // date et heure de l'instant 
    printf("%ld\n",temps);
    date2str(temps, date);
    printf("%s\n", date);
    temps = date2int(date);
    printf("%ld\n", temps);
    return 0;
}
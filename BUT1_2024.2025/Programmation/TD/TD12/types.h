#ifndef TYPES_H
#define TYPES_H

#include "const.h"

// définition des types
typedef char t_message [MAX_CAR];
typedef struct{
    t_message message;
    char date[MAX_SIZE];
}t_element;
typedef struct{
    t_element tabElt[MAX_MESSAGES];
    int nb;
}t_file;

#endif
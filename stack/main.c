//
// Created by rabah on 09/12/2025.
//

#include "stack.h"
#include <stdio.h>

int main() {

    Stack sta = new_stack();

    if (is_empty(sta))
        printf("La pile est vide \n");
    else
        printf("La pile n'est pas vide \n");

    sta = push_stack(sta, 14);
    sta = push_stack(sta, 15);

    print_stack(sta);

    if (is_empty(sta))
        printf("La pile est vide \n");
    else
        printf("La pile n'est pas vide \n");



    sta = clear_stack(sta);

    if (is_empty(sta))
        printf("La pile est vide \n");
    else
        printf("La pile n'est pas vide \n");




    return 0;
}


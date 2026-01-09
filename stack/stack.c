//
// Created by rabah on 09/12/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

Stack new_stack(void)
{
    return NULL;
}

Bool is_empty(Stack st)
{
    return st == NULL;
}

Stack push_stack(Stack st, int value) {
    StackElement *element;

    element = (StackElement*)malloc(sizeof(StackElement));

    if(element == NULL){
        printf("Problème allocation dynamique");
        exit(1);
    }

    element->value = value;
    element->next = st;

    return element;
}

Stack clear_stack(Stack st)
{
    StackElement *element;

    if (is_empty(st))
        return new_stack();

    element = st -> next;
    free(st);

    return clear_stack(element);
}

void print_stack(Stack st) {
    StackElement *element = st;

    while (!is_empty(element)) {
        printf("%d ", element->value);
        element = element->next;
    }

    printf("\n");
}


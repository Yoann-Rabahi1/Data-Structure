//
// Created by rabah on 09/12/2025.
//


#ifndef STACK_STACK_H
#define STACK_STACK_H

// Type booléen
typedef enum {
    false,
    true
}Bool;

// définition d'une pile
typedef struct StackElement {
    int value;
    struct StackElement* next;
}StackElement, *Stack;

Stack new_stack(void);
Bool is_empty(Stack st);
Stack push_stack(Stack st, int value);
Stack clear_stack(Stack st);

void print_stack(Stack st);

#endif //STACK_STACK_H
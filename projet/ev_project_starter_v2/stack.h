#ifndef DS_STACK_H
#define DS_STACK_H

// structure du maillon pour la stack

typedef struct StNode{
    int v; // attribut de la valeur du noeud
    struct StNode* next; // attribut de l'adresse pointant vers le prochain maillon de la pile
}StNode;

// structure de la pile

typedef struct Stack{
    StNode* top; // attribut du haut de la pile
} Stack;

void st_init(Stack* s);            /* O(1) */
int  st_push(Stack* s, int v);     /* O(1) */
int  st_pop(Stack* s, int* out);   /* O(1) */
int  st_is_empty(Stack* s);        /* O(1) */
void st_clear(Stack* s);           /* O(n) */

#endif

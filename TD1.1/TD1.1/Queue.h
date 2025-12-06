//
// Created by maman on 07/11/2025.
//

#ifndef TD1_1_SQUEUE_H
#define TD1_1_SQUEUE_H

#include "tree.h"
#include <stdlib.h>

typedef struct{
    struct Qnode* next;
    const Tnode* tnode;
}Qnode;
typedef struct  {
    Qnode* head;
    Qnode* tail;
}Queue;

void queue_init(Queue*);
int queue_is_empty(const Queue* q);

int queue_enqueue(Queue* q, Tnode *tnode);
int queue_dequeue(Queue* q, Tnode **out);

#endif //TD1_1_SQUEUE_H
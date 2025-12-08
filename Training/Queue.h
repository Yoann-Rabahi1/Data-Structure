//
// Created by rabah on 06/12/2025.
//

#ifndef TRAINING_QUEUE_H
#define TRAINING_QUEUE_H

#include "tree.h"
#include <stdlib.h>

typedef struct Qnode{
    struct Qnode* next;
    const TNode* tnode;
}Qnode;
typedef struct Queue{
    Qnode* head;
    Qnode* tail;
}Queue;

void queue_init(Queue*);
int queue_is_empty(const Queue* q);

int queue_enqueue(Queue* q, TNode *tnode);
int queue_dequeue(Queue* q, TNode **out);

#endif //TRAINING_QUEUE_H
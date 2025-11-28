#ifndef E2FE47F3_C438_49DB_857E_C7204F48C52B
#define E2FE47F3_C438_49DB_857E_C7204F48C52B

#include "slist.h";

typedef struct QNode{
    const TNode *node;
    struct QNode *next;
} QNode;

typedef struct Queue{
    QNode *head;
    QNode *tail;
} Queue;

//todolist

void queue_init(Queue* q);
int queue_is_empty(const Queue* q);
int queue_enqueue(Queue* q, TNode *tnode);
int queue_dequeue(Queue* q, TNode **out);
void queue_clear(Queue *q);


#endif /* E2FE47F3_C438_49DB_857E_C7204F48C52B */

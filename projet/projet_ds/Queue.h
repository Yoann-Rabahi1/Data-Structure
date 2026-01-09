//
// Created by rabah on 09/01/2026.
//

#ifndef PROJET_DS_QUEUE_H
#define PROJET_DS_QUEUE_H

typedef struct QNode { Event e; struct QNode* next; } QNode;
typedef struct Queue { QNode* head; QNode* tail; } Queue;

void q_init(Queue* q);                  /* O(1) */
int  q_is_empty(Queue* q);              /* O(1) */
int  q_enqueue(Queue* q, Event e);      /* O(1) */
int  q_dequeue(Queue* q, Event* out);   /* O(1) */
void q_clear(Queue* q);                 /* O(n) */

#endif //PROJET_DS_QUEUE_H
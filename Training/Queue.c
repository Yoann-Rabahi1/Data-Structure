//
// Created by rabah on 06/12/2025.
//

#include "Queue.h"

#include "Queue.h"


void queue_init(Queue* q) {
    q->head = NULL;
    q->tail= NULL;
}

int queue_is_empty(const Queue* q) {
    return q->head==NULL;
}

int queue_enqueue(Queue* q, TNode* tnode) {
    int res = 0;
    Qnode *new = (Qnode *)malloc(sizeof(Qnode));
    if (new) {
        res=1;
        new->tnode = tnode;
        new->next = NULL;
        if (queue_is_empty(q)) {
            q->head = new;
            q->tail = new;
        }
        else {
            q->tail->next = new;
            q->tail = new;
        }
    }
    return res;
}

int queue_dequeue(Queue *q, TNode** out) {

    if (queue_is_empty(q)) {
        return 0; // Échec
    }

    Qnode* h = q->head;
    *out = h->tnode;

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(h);

    return 1; // Succès
}
#include "queue.h"

void queue_init(Queue *q){
    q->head=NULL;
    q->tail=NULL;
}

int queue_enqueue(Queue* q, TNode *tnode){
    QNode *nouv=(QNode *)malloc(sizeof(QNode));
    int res = 0;
    if(nouv){
        res=1;
        nouv->tdnode=tnode;
        nouv->next=NULL;
        if(queue_is_empty(q)){
            q->head = q->tail = nouv;
        }
    }

    else{
        q->tail->next=nouv;
        q->tail = nouv;
    }
    return res;

}

int queue_dequeue(Queue* q, TNode **out){
    int res = 0;
    if(!queue_is_empty(q)){
        res = 1;
        QNode *h= q->head;
        *out = h->tnode;
        q->head = h->next;
        if(q->head==NULL){
            q->tail = NULL;
        }
        free(h);
    }

}
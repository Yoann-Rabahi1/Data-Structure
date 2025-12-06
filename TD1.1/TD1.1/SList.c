//

#include <stdio.h>
#include "SList.h"
#include <stdlib.h>

void ds_slist_init(SList *list)
{
    list->head = NULL;
}

SList ds_slist_create() {
    SList list;
    list.head = NULL;
    return list;
}

SNode* ds_slist_create_node(int val) {
    SNode *pnode = (SNode*)malloc(sizeof(SNode));
    pnode->data = val;
    pnode->next = NULL;
    return pnode;
}

int ds_slist_is_empty(const SList* list) {
    return list->head==NULL;
}

int ds_slist_insert_head(SList *list, int value) {
    printf("la node %d à était ajoutée à la tête de la liste\n",value);
    SNode *n = ds_slist_create_node(value);
    n->next = list->head;
    list->head = n;
    return 0;
}

int ds_slist_insert_tail(SList *list, int value) {
    printf("la node %d à était ajoutée à la fin de la liste\n",value);
    SNode *n = ds_slist_create_node(value);
    if (ds_slist_is_empty(list)) {
        list->head = n;
    }
    else {
        SNode *tmp = list->head;
        while (tmp->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next = n;
    }
    return 0;
}

int ds_slist_insert_at(SList* list, int index, int value) {
    printf("la node %d à était ajoutée à l'index %d de la liste\n",value,index);
    if (index == 0) {
        ds_slist_insert_head(list,value);
    }
    else {
        int n = 0;
        SNode *curr = list->head;
        while (curr != NULL && n<(index-1)){
            curr=curr->next;
            n++;
        }
        if (curr) {
            SNode *node = ds_slist_create_node(value);
            node->next = curr->next;
            curr->next = node;
        }

    }
    return 0;
}

int ds_slist_remove_head(SList *list) {
    if (ds_slist_is_empty(list)) {
        printf("your list is already empty");
    }
    else {
        SNode *tmp = list->head;
        list->head=list->head->next;
        printf("la node %d à était enlever de la liste\n",tmp->data);
        free(tmp);

    }
    return 0;
}

void ds_slist_remove_tail(SList *list) {
    if (ds_slist_is_empty(list)) {
        printf("ta liste est déjà vide");
    }
    else {
        SNode *curr = list->head;
        SNode *tmp;
        while (curr ->next != NULL) {
            tmp=curr;
            curr = curr->next;
        }
        tmp->next = NULL;

        free(curr);
    }
}

SNode* ds_slist_find(const SList * list,int value) {
    SNode* res =NULL;
    if (ds_slist_is_empty(list)) {
        printf("your list is empty");
    }
    else {
        SNode* curr = list->head;
        while (curr->next != NULL && res == NULL) {
            if (curr->data == value) {
                res = curr;
            }
            curr = curr->next;
        }
    }
    return res;
}
SNode* ds_list_find_rec(SNode * node,int value) {
    if (node->data == value) {
        return node;
    }
    if (node->next == NULL) {
        return NULL;
    }
    return ds_list_find_rec(node->next,value);
}
void ds_slist_print(const SList *list) {
    SNode *curr = list->head;
    if (ds_slist_is_empty(list)) {
        printf("ta liste est vide");
    }
    else {
        printf("[");
        while(curr->next!=NULL) {
            printf("%d ->",curr->data);
            curr=curr->next;
        }
        printf("%d]\n",curr->data);
    }
}
void ds_slist_print_rec_back(SNode* node) {
    if (node != NULL) {
        if (node->next != NULL){
            printf("[%d | @ ] -> ",node->data);
            ds_slist_print_rec_back(node->next);
        }
        else {
            printf("[%d | @ ] -> NULL\n",node->data);
        }
    }
}
void ds_slist_print_rec(SList *L) {
    ds_slist_print_rec_back(L->head);
}


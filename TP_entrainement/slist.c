//
// Created by rabah on 06/11/2025.
//

#include "slist.h"

#include <stdio.h>

#include "stdlib.h"

SNode *ds_slist_create_node(int data) {
    SNode *pnode = (SNode *)malloc(sizeof(SNode));
    if (!pnode) return NULL;
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

void ds_slist_init(SList *plist) {
    plist->head = NULL;
}

SList ds_slist_create(void) {
    SList list;
    list.head = NULL;
    return list;
}

int ds_slist_is_empty(const SList *plist) {
    return plist->head == NULL;
}

int ds_slist_insert_head(SList *plist, int value) {
    SNode *newnode = ds_slist_create_node(value);
    if (!newnode) return 0;
    newnode->next = plist->head;
    plist->head = newnode;
    return 1;
}

int ds_slist_insert_tail(SList *plist, int value) {
    SNode *newnode = ds_slist_create_node(value);
    if (!newnode) return 0;
    if (ds_slist_is_empty(plist))
        plist->head = newnode;
    else {
        SNode *cur = plist->head;
        while (cur->next) cur = cur->next;
        cur->next = newnode;
    }
}

void ds_slist_print_rec(const SNode *pnode) {
    if (pnode) {
        printf("%d", pnode->data);
        if (pnode->next) printf("-> ");
            ds_slist_print_rec(pnode->next);
    }
}

void ds_slist_print_V1(const SList *plist) {
    printf("[");
    ds_slist_print_rec(plist->head);
    printf("]");
}

void ds_slist_print(const SList *plist) {
    // parcours iteratif
    const SNode *cur = plist->head;
    printf("[ ");
    while (cur) {
        printf("%d ", cur->data);
        if (cur->next) printf("-> ");
        cur =cur->next;
    }
    printf(" ]\n");
}

int ds_slist_insert_at(SList *plist, int index, int value) {
    int ok = 0;
    if (index == 0)
        ok = ds_slist_insert_head(plist, value);
    else if (index > 0 && !ds_slist_is_empty(plist)) {
        SNode *cur = plist->head;
        int i = 0;
        while (cur && i < (index - 1)) {
            cur = cur->next;
            i++;
        }
        if (cur) {
            SNode *pnew = ds_slist_create_node(value);
            pnew->next = cur->next;
            cur->next = pnew;
            ok = 1;
        }
    else
        return ok;
    }
    return 0;
}


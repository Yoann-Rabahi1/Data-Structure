#include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free
#include "slist.h"

#include <stdbool.h>

SNode *ds_slist_create_node(int data) {
    // allocation d'un maillon
    SNode *pnode = (SNode *)malloc(sizeof(SNode));
    if (!pnode) return NULL;
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}


void ds_slist_init(SList *plist) {
    // tête vide
    plist->head = NULL;
}

SList ds_slist_create(void) {
    // liste vide par valeur
    SList list;
    list.head = NULL;
    return list;
}

int ds_slist_is_empty(const SList *plist) {
    // vrai si tête nulle
    return plist->head == NULL;
}

int ds_slist_insert_head(SList *plist, int value) {
    // insère en tête
    SNode *new_node = ds_slist_create_node(value);
    if (!new_node) return 0;
    new_node->next = plist->head;
    plist->head = new_node;
    return 1;
}

int ds_slist_insert_tail(SList *plist, int value) {
    // insère en fin
    SNode *new_node = ds_slist_create_node(value);
    if (!new_node) return 0;
    if (ds_slist_is_empty(plist)) {
        plist->head = new_node;
    } else {
        SNode *cur = plist->head;
        while (cur->next) cur = cur->next;
        cur->next = new_node;
    }
    return 1;
}

void ds_slist_print(const SList *plist) {
    // parcours itératif
    const SNode *cur = plist->head;
    printf("\n[");
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("]\n");
}

void ds_slist_print_rec(const SNode *pnode) {
    // affichage récursif d'une chaîne
    if (pnode) {
        printf("%d", pnode->data);
        if (pnode->next) printf(" -> ");
        ds_slist_print_rec(pnode->next);
    }
}

void ds_slist_print_v1(const SList *plist) {
    // wrapper récursif
    printf("[");
    ds_slist_print_rec(plist->head);
    printf("]\n");
}

SNode* ds_slist_find(const SList *plist, int value) {
    SNode *res=NULL;
    SNode *cur = plist->head;
    while (cur && res==NULL) {
        if (cur->data == value) {
            res = cur;
        }
        cur = cur->next;
    }
    return res;
}

SNode* ds_slist_first_rec_from_node(const SNode *start, int value) {
    if (start==NULL) return NULL;
    if (start->data == value) return start;
    return ds_slist_first_rec_from_node(start->next, value);
}

int ds_slist_insert_at(SList *plist, int index, int value) {
    int ok = 0;
    if (index == 0) {
        ok = ds_slist_insert_head(plist, value);
    }
    else if (index > 0 && !ds_slist_is_empty(plist)) {
        SNode *cur = plist ->head;
        int i = 0;
        while (cur && i < (index - 1)) {
            cur = cur->next;
            cur++;
        }
        if (cur) {
            SNode *pnew = ds_slist_create_node(value);
            pnew ->next = cur->next;
            cur->next = pnew;
            ok = 1;
        }
    }else
        return ok;
    return 0;
}


int ds_slist_remove_head(SList *plist, int *out) {
    if (ds_slist_is_empty(plist)) {
        SNode *res=plist->head;
        plist->head = plist->head->next;
    }
}
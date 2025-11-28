//
// Created by rabah on 10/10/2025.
#include <stddef.h> // NULL

#ifndef DATA_STRUCTURE_SLIST_H
#define DATA_STRUCTURE_SLIST_H

typedef struct SNode { int data; struct SNode *next;} SNode;
typedef struct SList { SNode *head; } SList;

SNode *ds_slist_create_node(int data);
SNode* ds_slist_find(const SList *plist, int value);
SNode* ds_slist_find_rec_from_node(const SNode *start, int value);

int ds_slist_remove_head(SList *plist, int *out);

void    ds_slist_init(SList *list);
SList   ds_slist_create(void);

int    ds_slist_is_empty(const SList *plist);
int    ds_slist_insert_head(SList *list, int value);
int    ds_slist_insert_tail(SList *list, int value);
int    ds_slist_insert_at(SList *plist, int index, int value);


void   ds_slist_print(const SList *plist);
void   ds_slist_print_rec(const SNode *pnode);
void   ds_slist_print_v1(const SList *plist);
#endif //DATA_STRUCTURE_SLIST_H
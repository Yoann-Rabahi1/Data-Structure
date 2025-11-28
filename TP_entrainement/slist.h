//
// Created by rabah on 06/11/2025.
//

#ifndef V1_SLIST_H
#define V1_SLIST_H

typedef struct SNode { int data; struct SNode *next; } SNode;
typedef struct SList { SNode *head; } SList;

SNode *ds_slist_create_node(int data);
SNode* ds_slist_find(const SList *plist, int value);
SNode* ds_slist_find_rec_from_node(const SNode *start, int value);

void ds_slist_init(SList *list);
int ds_slist_is_empty(const SList *list);
int ds_slist_insert_head(SList *list, int value);
int ds_slist_insert_tail(SList *list, int value); /* O(n) en
head-only */
int ds_slist_insert_at(SList *list, int index, int value);
int ds_slist_remove_head(SList *list, int *out);
int ds_slist_remove_tail(SList *list, int *out); /* O(n) */
int ds_slist_remove_value(SList *list, int value);
SNode* ds_slist_find(const SList *list, int value);
void ds_slist_print_V1(const SList *list);
void ds_slist_print(const SList *list);
void ds_slist_clear(SList *list);

#endif //V1_SLIST_H
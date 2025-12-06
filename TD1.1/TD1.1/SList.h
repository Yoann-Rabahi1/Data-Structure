//
//

#ifndef TD1_1_SLIST_H
#define TD1_1_SLIST_H


typedef struct SNode {
    int data;
    struct SNode* next;
}SNode;

typedef struct SList {
    SNode* head;
}SList;

void ds_slist_init(SList *list);
SList ds_slist_create();
SNode* ds_slist_create_node(int data);
int ds_slist_is_empty(const SList* list);

int ds_slist_insert_head(SList *list, int value);
int ds_slist_insert_tail(SList * list, int value);
int ds_slist_insert_at(SList* list, int index, int value);

int ds_slist_remove_head(SList *list);
void ds_slist_remove_tail(SList *list);
int ds_slist_remove_value(SList *list, int value);

SNode* ds_slist_find(const SList * list,int value);
SNode* ds_list_find_rec(SNode * node,int value);

void ds_slist_print(const SList *list);
void ds_slist_print_rec(SList*);
void ds_slist_print_rec_back(SNode*);
void ds_slist_clear(SList *list);


#endif //TD1_1_SLIST_H

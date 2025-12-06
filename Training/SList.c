//
// Created by rabah on 06/12/2025.
//

#include "SList.h"
#include <stdlib.h>
#include <stdio.h>

SNode* ds_slist_create_node(int data) {
    SNode *pnode = (SNode *)malloc(sizeof(SNode));
    pnode -> data = data;
    pnode -> next = NULL;
    return pnode;
}

void ds_slist_init(SList *plist) {
    plist -> head = NULL;
}


int ds_slist_is_empty(const SList *plist) {
    return plist -> head == NULL; // renverra True si vrai et False sinon
}

int ds_slist_insert_head(SList *plist, int value) {
    printf("La valeur %d a été ajouté à la liste\n", value);
    SNode *pnode = ds_slist_create_node(value);
    pnode -> next = plist -> head;
    plist -> head = pnode;
    return 1;
}

int ds_slist_insert_tail(SList *plist, int value) {
    printf("La valeur %d a été ajouté à la liste \n", value);
    SNode *pnode = ds_slist_create_node(value);
    if (ds_slist_is_empty(plist)) {
        plist -> head = pnode;
    }
    else {
        SNode *tmp = plist -> head;
        while (tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = pnode;
    }return 1;
}

int ds_slist_insert_at(SList *plist, int index, int value) {
    printf("la node %d à était ajoutée à l'index %d de la liste\n",value,index);
    if (index == 0) {
        ds_slist_insert_head(plist, value);
    }
    else {
        int n = 0;
        SNode *cur = plist->head;
        while (cur != NULL && n < index - 1) {
            cur = cur -> next;
            n ++;
        }

        if (cur) {
            SNode *pnode = ds_slist_create_node(value);
            pnode -> next = cur -> next;
            cur -> next = pnode;
        }
    } return 0;
}

int ds_slist_remove_head(SList *plist) {
    if (ds_slist_is_empty(plist)) {
        printf("La liste est déjà vide");
    }
    else {
        SNode *tmp = plist -> head;
        plist -> head = plist -> head -> next;
        printf("la node %d a été enlevée de la liste\n",tmp->data);
        free(tmp);
    } return 0;
}

int ds_slist_remove_value(SList *plist, int value) {
    if (ds_slist_is_empty(plist)) {
        printf("La liste est vide\n");
        return 0;
    }
    SNode *cur = plist->head;
    SNode *prev = NULL;

    while (cur != NULL && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        return 0;
    }
    if (prev == NULL) {
        plist->head = cur->next; // La nouvelle tête devient le nœud suivant
    }
    else {
        prev->next = cur->next;
    }
    free(cur);
    return 1; // Succès
}

SNode* ds_slist_find(const SList *plist, int value) {

    if (ds_slist_is_empty(plist)) {
        printf("La liste est vide\n");
        return NULL; // Toujours retourner NULL (plutôt que 0) pour un pointeur
    }
    SNode *cur = plist -> head;

    while (cur != NULL && cur->data != value) {
        cur = cur -> next;
    }

    if (cur == NULL) {
        printf("La valeur %d n'a pas été trouvée dans la liste.\n", value);
        return NULL;
    }

    else {
        printf("L'adresse de la valeur %d est : %p\n", value, (void*)cur);
    }
    return cur;
}

void ds_slist_print(const SList *plist) {
    SNode *cur = plist -> head;
    if (ds_slist_is_empty(plist)) {
        printf("La liste est vide\n");
    }

    else {
        printf("[ ");
        while (cur->next != NULL) {
            printf("%d ->", cur -> data);
            cur = cur -> next;
        }
        printf("%d ]\n", cur -> data);
    }
}

void ds_slist_clear(SList *plist) {

}

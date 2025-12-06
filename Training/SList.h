//
// Created by rabah on 06/12/2025.
//

#ifndef TRAINING_SLIST_H
#define TRAINING_SLIST_H

typedef struct SNode {int data; struct SNode *next;} SNode;
typedef struct SList{SNode *head;} SList;


SNode* ds_slist_create_node(int data);

SList ds_slist_create();
void ds_slist_init(SList *plist); // intialise une liste vide
int ds_slist_is_empty(const SList *plist); // retourne 1 si vide et 0 sinon
int ds_slist_insert_head(SList *plist, int value); // permet d'inserer une valeur en head
int ds_slist_insert_tail(SList *plist, int value); /* O(n) en
head-only */
int ds_slist_insert_at(SList *plist, int index, int value); // permet d'inserer une valeur dans un index
int ds_slist_remove_head(SList *plist); // permet d'enlever le noeud du head
int ds_slist_remove_tail(SList *plist); /* O(n) */
int ds_slist_remove_value(SList *plist, int value); // permet de supprimer une valeur
SNode* ds_slist_find(const SList *plist, int value); // permet de renvoyer l'adresse d'un noeud d'une valeur dans une SList
void ds_slist_print(const SList *plist); // permet d'afficher une SList
void ds_slist_clear(SList *plist); // permet de nettoyer une SList

#endif //TRAINING_SLIST_H
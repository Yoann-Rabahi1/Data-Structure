//
// Created by rabah on 09/01/2026.
//

#ifndef PROJET_DS_NARY_H
#define PROJET_DS_NARY_H

typedef struct NNode {
    int id;
    int items_count;
    struct NNode** child;
    int child_count;
    int child_cap;
} NNode;

NNode* n_create(int id);
int    n_attach(NNode* parent, NNode* child);
void   n_bfs_print(NNode* root);
void   n_clear(NNode* root);

#endif //PROJET_DS_NARY_H


#ifndef DATA_STRUCTURE_TNODE_H
#define DATA_STRUCTURE_TNODE_H
#include "queue.h"


typedef struct TNode {int data; struct TNode *left; struct TNode *right;} TNode;

typedef struct BTree {
    TNode *root;
} BTree;

void ds_btree_init(BTree* tree);
TNode* ds_btree_create_node(int value);
int ds_btree_attach_left(TNode* parent, TNode* child);
int ds_btree_attach_right(TNode* parent, TNode* child);
int ds_btree_is_empty(const BTree* tree);
int ds_btree_size(TNode *node);

void ds_btree_preorder_display(const TNode *pnode);

void ds_btree_preorder(const TNode *pnode, ds_visit_fn visit);
void ds_btree_inorder(const TNode *pnode, ds_visit_fn visit);
void ds_btree_postorder(const TNode *pnode, ds_visit_fn visit);

int bs_btree_height(TNode *pnode);
TNode* bs_btree_find(TNode *pnode, int value);
int ds_btree_depth_of(TNode *pnode, int val);

void ds_btree_level_order(TNode *pnode, ds_visit_fn visit);

void ds_bsttree_add(BTree* tree, int value);

#endif //DATA_STRUCTURE_TNODE_H

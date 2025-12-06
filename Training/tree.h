//
// Created by rabah on 06/12/2025.
//

#ifndef TRAINING_TREE_H
#define TRAINING_TREE_H

typedef struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
}TNode;

typedef struct BTree {
    TNode *root;
}BTree;

typedef void(ds_visit_fn(TNode*));

void ds_BTree_init(BTree* tree);
void ds_BTree_clear(BTree* tree);

TNode* ds_BTree_create_node(int value);
int ds_BTree_attach_left(TNode* parent, int child_value);
int ds_BTree_attach_right(TNode* parent, TNode* child);

void ds_BTree_print_preorder(TNode* root);
void ds_BTree_visit_preorder(TNode* root, ds_visit_fn visit);
void ds_BTree_plus_3(TNode*);
void ds_BTree_print_inorder(TNode* root);
void ds_BTree_print_postorder(TNode* root);

int ds_BTree_size(TNode* root);
int ds_BTree_height(TNode* root);
TNode* ds_BTree_find(TNode* root,int val);
int ds_BTree_depth_of(TNode* root);

int ds_BTree_is_empty(const BTree* tree);

void ds_BTree_level_order(TNode* root, ds_visit_fn visit);
void ds_BTree_print_node(TNode* node);

TNode * ds_bstree_max(TNode *pnode);
TNode * ds_bstee_min(TNode *pnode);

void ds_bstree_to_array(TNode * pnode, int * array, int * i);

BTree * ds_bstree_from_array(int * array, int size);

#endif //TRAINING_TREE_H
//
// Created by Moi on 17/10/2025.
//

#ifndef TD1_1_TREE_H
#define TD1_1_TREE_H


typedef struct Tnode {
    int data;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

typedef struct Btree {
    Tnode* root;
}Btree;

typedef void(ds_visit_fn(Tnode*));

void ds_btree_init(Btree* tree);
void ds_btree_clear(Btree* tree);

Tnode* ds_btree_create_node(int value);
int ds_btree_attach_left(Tnode* parent, int child_value);
int ds_btree_attach_right(Tnode* parent, Tnode* child);

void ds_btree_print_preorder(Tnode* root);
void ds_btree_visit_preorder(Tnode* root, ds_visit_fn visit);
void ds_btree_plus_3(Tnode*);
void ds_btree_print_inorder(Tnode* root);
void ds_btree_print_postorder(Tnode* root);

int ds_btree_size(Tnode* root);
int ds_btree_height(Tnode* root);
Tnode* ds_btree_find(Tnode* root,int val);
int ds_btree_depth_of(Tnode* root);

int ds_btree_is_empty(const Btree* tree);

void ds_btree_level_order(Tnode* root, ds_visit_fn visit);
void ds_btree_print_node(Tnode* node);

Tnode * ds_bstree_max(Tnode *pnode);
Tnode * ds_bstee_min(Tnode *pnode);

void ds_bstree_to_array(Tnode * pnode, int * array, int * i);

Btree * ds_bstree_from_array(int * array, int size);

#endif //TD1_1_TREE_H
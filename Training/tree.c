//
// Created by rabah on 06/12/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void ds_btree_init(BTree *tree) {
    tree->root = NULL;
}

TNode * ds_btree_create_node(int value) {
    TNode * node = (TNode *)malloc(sizeof(TNode));

    if (!node) return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int ds_btree_attach_left(TNode *parent, int child_value) {
    if (!parent) return 0;
    if (parent->left) return 0;

    TNode *child = ds_btree_create_node(child_value);
    parent->left = child;
    return 1;
}

int ds_btree_attach_right(TNode *parent, int child_value) {
    if (!parent) return 0;
    if (parent->right) return 0;

    TNode *child = ds_btree_create_node(child_value);
    parent->right = child;
    return 1;
}

void ds_btree_print_preorder(TNode *root) {
    if (!root) return;
    printf("%d ", root->data);
    ds_btree_print_preorder(root->left);
    ds_btree_print_preorder(root->right);
}

void ds_btree_print_inorder(TNode* root) {
    if (!root) return;
    ds_btree_print_inorder(root->left);
    printf("%d ",root->data);
    ds_btree_print_inorder(root->right);
}
void ds_btree_print_postorder(TNode* root) {
    if (!root) return;
    ds_btree_print_postorder(root->left);
    ds_btree_print_postorder(root->right);
    printf("%d ", root->data);
}

void ds_btree_visit_preorder(TNode* root, ds_visit_fn visit) {
    if (!root) return;
    visit(root);
    ds_btree_visit_preorder(root->left, visit);
    ds_btree_visit_preorder(root->right, visit);
}

void ds_btree_visit_postorder(TNode* root, ds_visit_fn visit) {
    if (!root) return;
    ds_btree_visit_postorder(root->left,visit);
    ds_btree_visit_postorder(root->right,visit);
    visit(root);
}

void ds_btree_print_node(TNode *pnode) {
    printf("%d ", pnode->data);
}

void ds_btree_print(TNode* pnode) {
    printf("%d", pnode->data);
}

void ds_btree_free_node(TNode* pnode) {
    if (!pnode) return;
    free(pnode);
}

void ds_btree_clear(BTree *tree) {
    ds_btree_visit_postorder(tree->root, ds_btree_free_node);
}

int ds_btree_height(TNode* root) {
    if (!root) return 0;
    int hl = ds_btree_height(root->left);
    int hr = ds_btree_height(root->right);
    return 1 + (hl > hr ? hl : hr);
}

TNode * ds_btree_find(TNode *pnode, int value) {
    if (pnode==NULL) return NULL;
    if (value == pnode->data) return pnode;
    return ds_btree_find(pnode->left, value);
}

TNode * ds_bstree_find(TNode *pnode, int value) {
    if (pnode == NULL) return NULL;
    if (value == pnode->data) return pnode;
    if (value<pnode->data) return ds_bstree_find(pnode->left, value);
    return ds_bstree_find(pnode->right, value);
}

TNode * ds_bstree_max(TNode *pnode) {
    if (pnode) {
        if (pnode->right == NULL) return pnode;
        return ds_bstree_max(pnode->right);
    }
    return NULL;
}

TNode * ds_bstree_min(TNode *pnode) {
    if (pnode) {
        if (pnode->left == NULL) return pnode;
        return ds_bstree_min(pnode->left);
    }
    return NULL;
}

void ds_bstree_to_array(TNode * pnode, int * array, int * i) {
    if (pnode == NULL) return;
    ds_bstree_to_array(pnode->left, array, i);
    array[*i] = (pnode->data);
    *(i) = *i + 1;
    ds_bstree_to_array(pnode->left, array, i);
}

TNode* add_node(TNode* node, int value) {
    if (node == NULL) {
        return ds_btree_create_node(value);
    }
    if (value < node->data)
        node->left = add_node(node->left, value);
    else if (value > node->data)
        node->right = add_node(node->right, value);
    return node;
}

void ds_bstree_add(BTree* tree, int value) {
    tree->root = add_node(tree->root, value);
}


BTree * ds_bstree_from_array(int * array, int size) {
    BTree* T;
    ds_btree_init(T);
    for (int i = 0;i<size;i++) {
        ds_bstree_add(T,array[i]);
    }
    return T;
}
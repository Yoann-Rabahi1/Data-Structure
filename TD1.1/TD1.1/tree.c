//
// Created by Moi on 17/10/2025.
//

#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>



void ds_btree_init(Btree* tree) {
    tree->root = NULL;
}

Tnode* ds_btree_create_node(int value) {
    Tnode* node = (Tnode*)malloc(sizeof(Tnode));
    if (!node) return NULL;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int ds_btree_attach_left(Tnode* parent, int child_value) {
    if (!parent) return 0;
    if (parent->left) return 0;
    Tnode *child = ds_btree_create_node(child_value);
    parent->left = child;
    return 1;
}
int ds_btree_attach_right(Tnode* parent, Tnode* child) {
    if (!parent) return 0;
    if (parent->right) return 0;
    parent->right = child;
    return 1;
}

void ds_btree_print_preorder(Tnode* root) {
    if (!root) return;
    printf("%d ",root->data);
    ds_btree_print_preorder(root->left);
    ds_btree_print_preorder(root->right);
}

void ds_btree_print_inorder(Tnode* root) {
    if (!root) return;
    ds_btree_print_inorder(root->left);
    printf("%d ",root->data);
    ds_btree_print_inorder(root->right);
}
void ds_btree_print_postorder(Tnode* root) {
    if (!root) return;
    ds_btree_print_postorder(root->left);
    ds_btree_print_postorder(root->right);
}

void ds_btree_plus_3(Tnode* root) {
    root->data += 3;
}

void ds_btree_print_node(Tnode* node) {
    printf("%d ",node->data);
}

void ds_btree_visit_preorder(Tnode* root, ds_visit_fn visit) {
    if (!root) return;
    visit(root);
    ds_btree_visit_preorder(root->left, visit);
    ds_btree_visit_preorder(root->right, visit);
}

void ds_btree_visit_postorder(Tnode* root, ds_visit_fn visit) {
    if (!root) return;
    ds_btree_visit_postorder(root->left,visit);
    ds_btree_visit_postorder(root->right,visit);
    visit(root);
}

void ds_btree_free_node(Tnode* node) {
    free(node);
}

void ds_btree_clear(Btree* tree) {
    ds_btree_visit_postorder(tree->root,ds_btree_free_node);
    tree->root = NULL;
}

int ds_btree_height(Tnode* root) {
    if (!root) return -1;
    int hl = ds_btree_height(root->left);
    int hr = ds_btree_height(root->right);
    return (hl>hr?hl+1:hr+1); //
}

Tnode * ds_btree_find(Tnode *pnode,int val) {
    if (pnode==NULL) return NULL;
    if (val == pnode->data) return pnode;
    return ds_btree_find(pnode->left,val);
}

void ds_btree_level_order(Tnode* root, ds_visit_fn visit) {
    if (root) {
        Queue q;
        queue_init(&q);
        queue_enqueue(&q, root);
        while (!queue_is_empty(&q)) {
            Tnode *curr;
            queue_dequeue(&q,&curr);
            visit(curr);
            if (curr->left) queue_enqueue(&q,curr->left);
            if (curr->right) queue_enqueue(&q,curr->right);
        }
    }
}

// void ds_bstree_add_to_node(Tnode* cur, int val) {
//     if (cur) {
//         if (val < cur->data) {
//             if (cur->right==NULL) cur
//         }
//     }
// }
//
void ds_bstree_add(Btree* tree, int value) {
    return;
}

Tnode * ds_bstree_find(Tnode *pnode, int val) {
    if (pnode == NULL) return NULL;
    if (val == pnode->data) return pnode;
    if (val<pnode->data) return ds_bstree_find(pnode->left, val);
    return ds_bstree_find(pnode->right, val);
}

Tnode * ds_bstree_max(Tnode *pnode) {
    if (pnode) {
        if (pnode->right == NULL) return pnode;
        return ds_bstree_max(pnode->right);
    }
    return NULL;
}

Tnode * ds_bstree_min(Tnode *pnode) {
    if (pnode) {
        if (pnode->left == NULL) return pnode;
        return ds_bstree_min(pnode->left);
    }
    return NULL;
}

void ds_bstree_to_array(Tnode * pnode, int * array, int * i) {
    if (pnode == NULL) return;
    ds_bstree_to_array(pnode->left, array, i);
    array[*i] = (pnode->data);
    *(i) = *i + 1;
    ds_bstree_to_array(pnode->left, array, i);
}

Btree * ds_bstree_from_array(int * array, int size) {
    Btree* T;
    ds_btree_init(T);
    for (int i = 0;i<size;i++) {
        ds_bstree_add(T,array[i]);
    }
    return T;
}
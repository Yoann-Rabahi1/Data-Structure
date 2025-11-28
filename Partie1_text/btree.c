//
// Created by rabah on 17/10/2025.
//

#include "btree.h"
#include <stdlib.h>  /* malloc, free */

/* init — O(1) */
void ds_btree_init(BTree* tree) {
    tree->root = 0;
}

/* create node — O(1) */
TNode* ds_btree_create_node(int value) {
    TNode* n = (TNode*)malloc(sizeof * n);
    if (!n) return 0;
    n->data = value;
    n->left = 0;
    n->right = 0;
    return n;
}

/* attach left/right — O(1), no overwrite */
int ds_btree_attach_left(TNode* parent, TNode* child) {
    if (!parent || parent->left) return 0;
    parent->left = child;
    return 1;
}
int ds_btree_attach_right(TNode* parent, TNode* child) {
    if (!parent || parent->right) return 0;
    parent->right = child;
    return 1;
}

/* is_empty — O(1) */
int ds_btree_is_empty(const BTree* tree) {
    return tree->root == 0;
}

int ds_btree_size(TNode *node) {
    if (node == NULL) return 0;
    return 1 + ds_btree_size(node->left) + ds_btree_size(node->right);
}


void ds_btree_preorder_display(const TNode *pnode){

}

void ds_btree_inorder(const TNode *pnode, ds_visit_fn visit){
    if(pnode !=NULL){
        printf("%d", pnode->data);

    }
}


int ds_btree_height(TNode *pnode){
    int hl = ds_btree_height(pnode->left);
    int hr = ds_btree_height(pnode->right);
    return ((hl>hr) ? hl:hr) + 1;
}

void ds_btree_clear(BTree* tree){

}

void ds_btree_level_order(TNode *pnode, ds_visit_fn visit){
    if(pnode!=NULL && visit!=NULL){
        Queue q;
        queue_init(&);
        queue_enqueue(&q, pnode);
        while(!queue_is_empty(&q)){
            TNode* cur;
            queue_dequeue(&q, &cur);
            visit(cur->data);
            if(cur->left!=NULL) queue_dequeue(&q, cur->left);
            if(cur->right!=NULL) queue_dequeue(&q, cur->right);

        }
    }
}

void ds_bsttree_add_to_node(TNode *cur, int value){
    if(cur){
        if(value < cur->data){
            if(cur->left==NULL) cur->left = ds_btree_create_node(value);
            else ds_bsttree_add(cur->left, value);
        }
        else{
            if(cur->right==NULL) cur->right = ds_btree_create_node(value);
            else ds_bsttree_add_to_node(cur->right, value);
        }
    }
}

void ds_bsttree_add(BTree* tree, int value){
    if(ds_btree_is_empty(tree)){
        tree->root = ds_btree_create_node(value);
    }else{
        TNode* cur = tree->root;
        if(value < cur->data){
            if(cur->left==NULL) cur->left = ds_btree_create_node(value);
            else ds_bsttree_add(tree, value);
        }
        else{
            if(cur->right==NULL) cur->right = ds_btree_create_node(value);
            else ds_bsttree_add(tree, value);
        }
    }
}
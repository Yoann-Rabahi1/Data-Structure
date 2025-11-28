#include <stdio.h>
#include "slist.h"

int main_SLIST(void) {
    // nœud créé à la main
    SNode n1;
    n1.data = 0;
    n1.next = NULL;
    printf("n1.data = %d\n", n1.data);

    // nœud via la fabrique (pointeur)
    SNode *n2 = ds_slist_create_node(20);
    printf("n2->data = %d\n", n2->data);

    // pointeur vers n2
    SNode *pnode = n2;
    printf("pnode->data = %d\n", pnode->data);

    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''");

    // liste 1 : init sur variable
    SList L;
    ds_slist_init(&L);

    // liste 2 : création par valeur
    SList L2 = ds_slist_create();
    (void)L2; // évite un warning si non utilisé

    printf("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''");

    // insertions
    ds_slist_insert_head(&L, 10);
    ds_slist_insert_head(&L, 20);
    ds_slist_insert_head(&L, 30);
    ds_slist_insert_tail(&L, 100);
    ds_slist_insert_tail(&L, 200);

    // affichages
    ds_slist_print(&L);
    ds_slist_print_v1(&L);



    ds_slist_insert_at(&L, 1, 1000);
    ds_slist_print(&L);

    return 0;
}

#include "btree.h"



int main(void) {
    BTree T; ds_btree_init(&T);

    /*       8
           /   \
          3     10
         / \      \
        1   6      14
           / \     /
          4   7   13
    */
    TNode* n8 = ds_btree_create_node(8);
    TNode* n3 = ds_btree_create_node(3);
    TNode* n10 = ds_btree_create_node(10);
    TNode* n1 = ds_btree_create_node(1);
    TNode* n6 = ds_btree_create_node(6);
    TNode* n14 = ds_btree_create_node(14);
    TNode* n4 = ds_btree_create_node(4);
    TNode* n7 = ds_btree_create_node(7);
    TNode* n13 = ds_btree_create_node(13);

    T.root = n8;
    ds_btree_attach_left(n8, n3);   ds_btree_attach_right(n8, n10);
    ds_btree_attach_left(n3, n1);   ds_btree_attach_right(n3, n6);
    ds_btree_attach_left(n6, n4);   ds_btree_attach_right(n6, n7);
    ds_btree_attach_right(n10, n14);
    ds_btree_attach_left(n14, n13);

    //ds_btree_clear(&T);
    return 0;
}
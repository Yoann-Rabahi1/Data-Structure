#include <stdio.h>
#include "Slist.h"
#include "tree.h"
int main(void) {
    Btree T;
    ds_btree_init(&T);

    Tnode* n1 = ds_btree_create_node(8);
    T.root = n1;
    ds_btree_attach_left(n1,5);
    Tnode* n2 = ds_btree_create_node(3);
    ds_btree_attach_right(T.root,n2);
    ds_btree_print_preorder(T.root);
    ds_btree_attach_left(n2, 9);
    Tnode* n3 = ds_btree_create_node(7);
    ds_btree_attach_right(n2,n3);
    ds_btree_visit_preorder(T.root,ds_btree_plus_3);
    /*       11
     *      /  \
     *     8    6
     *         / \
     *        12 10
     */
    printf("\n");
    ds_btree_print_preorder(T.root);
    printf("\n");
    printf("Height of the tree : %d\n",ds_btree_height(T.root));
    //ds_btree_clear(&T);
    //ds_btree_print_preorder(T.root);
    printf("affichage en largeur : ");
    ds_btree_level_order(T.root,ds_btree_print_node);
    return 0;

}

/*
    SNode n1;
    SNode n2;
    SList list;
    ds_slist_init(&list);
    SList list2 = ds_slist_create();
    if (ds_slist_is_empty(&list)) {
        printf("je suis la\n");
    }
    ds_slist_insert_head(&list,10);
    ds_slist_insert_head(&list,20);
    ds_slist_insert_head(&list,30);
    ds_slist_insert_tail(&list,40);
    if (ds_slist_is_empty(&list) == 0) {
        printf("je suis pas vide \n");
    }
    ds_slist_print(&list);
    ds_slist_insert_at(&list,2,45);
    ds_slist_print(&list);
    ds_slist_print_rec(&list);
    ds_slist_remove_head(&list);
    ds_slist_print(&list);
    ds_slist_remove_tail(&list);
    ds_slist_print(&list);

    SNode * node_1 = ds_list_find_rec((&list)->head,120);

    ds_slist_insert_at(&list,1,15);
    ds_slist_print(&list);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"


int main() {

    // noeud crée à la main
    SNode n1;
    n1.data = 10;
    n1.next = NULL;
    printf("%d\n", n1.data);

    // noeud via la fabrique (pointeur)

    printf("---------------------------------\n");


    SNode *n2 = ds_slist_create_node(10);
    printf("n2 -> data = %d\n", n2->data);

    printf("---------------------------------\n");
    // pointeur vers n2
    SNode *pnode = n2;
    printf("pnode->data = %d\n", pnode->data);

    // liste 1 : init sur variable

    SList L;
    ds_slist_init(&L);


    printf("---------------------------------\n");

    ds_slist_insert_head(&L, 10);
    ds_slist_insert_head(&L, 20);
    ds_slist_insert_head(&L, 30);
    ds_slist_insert_tail(&L, 100);
    ds_slist_insert_tail(&L, 200);
    ds_slist_insert_tail(&L, 300);


    ds_slist_print(&L);
    ds_slist_print_V1(&L);


    return 0;
}

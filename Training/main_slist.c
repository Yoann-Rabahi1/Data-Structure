//
// Created by rabah on 06/12/2025.
//

#include <stdlib.h> // Nécessaire pour malloc
#include <string.h>
#include "SList.h"


int main() {

    SList *plist = (SList *)malloc(sizeof(SList));


    plist->head = NULL;

    // Maintenant, l'insertion est sûre
    ds_slist_insert_head(plist, 5);
    ds_slist_insert_head(plist, 6);
    ds_slist_insert_head(plist, 7);
    ds_slist_insert_tail(plist, 100);
    ds_slist_insert_tail(plist, 200);
    ds_slist_insert_tail(plist, 300);

    ds_slist_print(plist);


    return 0;
}
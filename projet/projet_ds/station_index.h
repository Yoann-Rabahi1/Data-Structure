//
// Created by rabah on 09/01/2026.
//

#ifndef PROJET_DS_STATION_INDEX_H
#define PROJET_DS_STATION_INDEX_H

// structure des information pour une station

typedef struct StationInfo {
    int power_kW;      /* puissance */
    int price_cents;   /* tarif en centimes */
    int slots_free;    /* places libres */
    int last_ts;       /* dernière mise à jour */
} StationInfo;

// structure du maillon des stations

typedef struct StationNode {
    int station_id; // attribut : id
    StationInfo info; // attribut : toutes les infos issue de la structure StationInfo
    struct StationNode* left; // attribut : left pointant vers un maillon station
    struct StationNode* right; // attribut : left pointant vers un maillon station
    int height; // attribut : height permettant de connaître la position du maillon dans l'AVL
} StationNode;

// structure pour la racine de l'AVL

typedef struct StationIndex {
    StationNode* root; // attribut : permettant d'initialiser un maillon station en root
} StationIndex;

void si_init(StationIndex* idx);
StationNode* si_find(StationNode* r, int id);           /* O(log n) */
void si_add(StationIndex* idx, int id, StationInfo in); /* AVL insert */
int  si_delete(StationIndex* idx, int id);              /* AVL delete */
int  si_to_array(StationNode* r, int* ids, int cap);    /* inorder fill */
void si_print_sideways(StationNode* r);                 /* debug */
void si_clear(StationIndex* idx);                       /* postorder free */


#endif //PROJET_DS_STATION_INDEX_H
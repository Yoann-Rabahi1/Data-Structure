//
// Created by rabah on 09/12/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Player {
    signed char username[25];
    int hp;
    int mp;
}Player;

void create_player(Player *p) {
    strcpy(p->username, "Yo");
    p->hp = 100;
    p->mp = 100;
}

int main()
{

    Player p1 = {"", 0, 0};

    create_player(&p1);

    printf("Prenom : %s | hp : %d | mp : %d \n", p1.username, p1.hp, p1.mp);

    strcpy(p1.username, "Mark Evans"); // strcpy pour modifier un char
    p1.hp -= 20;
    p1.mp -= 20;


    printf("Prenom : %s | hp : %d | mp : %d \n", p1.username, p1.hp, p1.mp);

    return 0;
}
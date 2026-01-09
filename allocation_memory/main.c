//
// Created by rabah on 09/12/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sizeof(<donnee>) : retourne la taille en octect d'une donnée
// malloc(<taille_octets>) : alloue dynamiquement une zone mémoire
// free(<donnee_allouee>) : libère la mémoire allouée

int main() {

    int nb_joueur = 0;
    int *liste_joueur = NULL;
    int i = 0;

    printf("Combien de joueurs ? : ");
    scanf("%d", &nb_joueur);

    liste_joueur = malloc(sizeof(int) * nb_joueur);

    if (liste_joueur == NULL)
        exit(1);

    for (i = 0; i < nb_joueur; i++) {
        printf("Joueur %d -> numero %d \n", i + 1, i * 3);
        liste_joueur[i] = i * 3;
    }

    for (i = 0; i < nb_joueur; i++) {
        printf("[%d]", liste_joueur[i]);
    }

    free(liste_joueur);

    return 0;

}
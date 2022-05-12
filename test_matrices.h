//
// Created by maela on 10/04/2022.
//

#ifndef PROJET_SDD1_TAKUZU_TEST_MATRICES_H
#define PROJET_SDD1_TAKUZU_TEST_MATRICES_H

typedef struct {
    int i;
    int j;
} COORDS;


int ligne_remplie(int y, int **tab, int size);

int colonne_remplie(int x, int **tab, int size);

int test_suite(int y, int x, int **tab, int size);

int test_autour(int y, int x, int **tab, int size);

int test_case(int y, int x, int **tab, int size);

int test_remplissage(int **tab, int size);

int verif_grille(int **grille_jeu, int **grille_soluc, int size);

int verif_valide(int **grille_jeu, COORDS coords, int size, int val);

int grille_valide(int **grille, int size);

int verif_tab_id(int *tab1, int *tab2, int size);

int verif_all_lignes_idd(int **tab, int size);

#endif //PROJET_SDD1_TAKUZU_TEST_MATRICES_H

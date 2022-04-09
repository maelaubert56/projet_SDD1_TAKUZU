#ifndef PROJET_SDD1_TAKUZU_RESOLUTION_H
#define PROJET_SDD1_TAKUZU_RESOLUTION_H

typedef struct
{
    int i;
    int j;
} COORDS ;


void resoudre();
int **remplir_matrice(int size);
int** generer_masque(int size,int niveau);
int verif_grille(int** grille_jeu,int** grille_soluc,int size);
COORDS choisir_case(int** tab, int size);

#endif //PROJET_SDD1_TAKUZU_RESOLUTION_H

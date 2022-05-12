#include "generateur_grille.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "test_matrices.h"
#include "affichage.h"
#include "time.h"

int *int_to_bin(int nombre, int size) {
    int *code_binaire = (int *) malloc(sizeof(int) * size);
    int i;
    for (i = 0; i <= size - 1; i++) {
        if ((int) pow(2, size - 1 - i) <= nombre) {
            code_binaire[i] = 1;
            nombre -= (int) pow(2, size - 1 - i);
        } else code_binaire[i] = 0;
    }
    return code_binaire;
}

int verif_ligne(int *code_binaire, int size) {
    int cpt = 0, i;
    for (i = 0; i < size; i++) {
        if (code_binaire[i] == 0) {
            cpt++;
        }
        if ((i < size - 3) && (code_binaire[i] == code_binaire[i + 1] && code_binaire[i] == code_binaire[i + 2]))
            return 0;
        if ((i > size - 3) && (code_binaire[i] == code_binaire[i - 1] && code_binaire[i] == code_binaire[i - 2]))
            return 0;
    }
    if (cpt == size / 2) return 1;
    else return 0;
}

int **lignes_valides(int size, int *cpt) {
    int **tab = (int **) malloc(sizeof(int *) * (int) pow(2, size));
    int j = 0;
    for (int i = 0; i < (int) pow(2, size); i++) {
        tab[j] = (int *) malloc(sizeof(int) * size);
        tab[j] = int_to_bin(i, size);
        if (verif_ligne(tab[j], size) == 1) j++;
    }
    *cpt = j;

    return tab;
}


void afficher_lignes_valides(size) {
    printf("Lignes (colonnes) valides :\n");
    for (int i = 0; i < (int) pow(2, size); i++) {
        int *tab = int_to_bin(i, size);
        if (verif_ligne(tab, size) == 1) {
            printf("\n\t->  ");
            for (int j = 0; j < size; j++) {
                printf("%d ", tab[j]);
            }
        }
    }

    /*
    for(int i=0;i<(int)pow(2,size);i++){
        for
    */
    printf("\n");
}

int **generer_grille(int size) {
    /*
    int soluc4[4][4] =  {    {1,0,0,1},
                             {1,0,1,0},
                             {0,1,1,0},
                             {0,1,0,1}   };
    int** soluc = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        soluc[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            soluc[i][j]=soluc4[i][j];
        }
    }
    printf("grille valide ? : %d \n", grille_valide(soluc,size));
    wait_for_enter();*/
    printf("generation grille");
    int cpt; // nombre de lignes valides
    int **lignes = lignes_valides(size, &cpt);

    int **tab = (int **) malloc(sizeof(int *) * size);


    int i, j = size - 1;

    int *indices = (int *) malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) {
        indices[i] = 0;
        tab[i] = lignes[0];
    }
    int z;
    printf("cpt=%d\n", cpt);

    srand(time(NULL));
    int random = rand() % cpt;
    printf("random = %d\n", random);
    for (i = 0; i < random; i++) {
        decaler_lignes_droite(lignes, cpt);
    }
    for (i = 0; i < size; i++)printf("%d   ", lignes[0][i]);

    while (1) {
        printf("\nj=%d  |  indices : %d %d %d %d %d %d %d %d ", j, indices[0], indices[1], indices[2], indices[3],
               indices[4], indices[5], indices[6], indices[7]);
        afficher_matrice(tab, size);
        //wait_for_enter();
        //printf("grille valide ? : %d \n", grille_valide(tab,size));
        if (grille_valide(tab, size) == 1) {
            return tab;
        } else {
            while (indices[j] == cpt - 1 && j != 0) {
                indices[j] = 0;
                j--;
            }
            indices[j]++;
            j = size - 1;
        }
        for (z = 0; z < size; z++) {
            tab[z] = lignes[indices[z]];
        }
    }
}

int **decaler_lignes_droite(int **tab, int size) {
    int *temp = tab[size - 1];
    for (int i = size; i > 0; i--) {
        tab[i] = tab[i - 1];
    }
    tab[0] = temp;
    printf("décale\n");
    return tab;
}


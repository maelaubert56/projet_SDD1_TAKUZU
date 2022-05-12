#include "generateur_grille.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "test_matrices.h"
#include "affichage.h"
#include "time.h"

int bin_to_int(int *code_binaire, int size){
    int i, nombre=0;
    for(i=0;i<size;i++){
        nombre += code_binaire[i] * (int)pow(2,i);
    }
    return nombre;
}


int* int_to_bin(int nombre, int size){
    int* code_binaire = (int*) malloc(sizeof(int)*size);
    int i;
    for (i = 0; i <= size-1; i++){
        if((int)pow(2,size-1-i) <= nombre){
            code_binaire[i] = 1;
            nombre -= (int)pow(2,size-1-i);
        }
        else code_binaire[i] = 0;
    }
    return code_binaire;
}

int verif_ligne( int* code_binaire, int size){
    int cpt=0,i;
    for(i=0;i<size;i++){
        if (code_binaire[i]==0){
            cpt++;
        }
        if ((i< size-3) && (code_binaire[i]==code_binaire[i+1] && code_binaire[i]==code_binaire[i+2])) return 0;
        if ((i > size-3) && (code_binaire[i]==code_binaire[i-1] && code_binaire[i]==code_binaire[i-2])) return 0;
    }
    if (cpt == size/2) return 1;
    else return 0;
}

int** lignes_valides(int size, int* cpt){
    int** tab = (int**)malloc(sizeof(int*)*(int)pow(2,size));
    int j=0;
    for(int i=0;i<(int)pow(2,size);i++){
        tab[j] = (int*)malloc(sizeof(int)*size);
        tab[j] = int_to_bin(i,size);
        if(verif_ligne(tab[j], size) == 1) j++;
    }
    *cpt = j;

    return tab;
}


void afficher_lignes_valides(size){
    printf("Lignes (colonnes) valides :\n");
    for(int i=0;i<(int)pow(2,size);i++){
        int* tab = int_to_bin(i,size);
        if(verif_ligne(tab, size) == 1) {
            printf("\n\t->  ");
            for (int j = 0; j < size; j++) {
                printf("%d ", tab[j]);
            }
        }
    }
    printf("\n");
}
int** generer_grille(int size){
    int **grid = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        grid[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            grid[i][j]=-1;
        }
    }
    gen_grid(grid,0,size);
    printf("Matrice %dx%d generee:\n",size,size);
    afficher_matrice(grid,size,1);
    wait_for_enter();

}


int gen_grid(int** grille,int pos,int size){

    //afficher_matrice(grille,size,1);
    if (pos == size*size)
        return 1;

    int i = pos/size, j = pos%size;
    if (grille[i][j] != -1)
        return gen_grid(grille, pos+1,size);

    for (int k=0; k <= 1; k++)
    {
        if (verif_valide_gen(grille,(COORDS){i,j},size,k)==1)
        {
            grille[i][j] = k;
            if (gen_grid(grille, pos+1,size)==1)
                return 1;
        }
    }
    grille[i][j] = -1;
    return 0;
}





int** decaler_lignes_droite(int** tab, int size){
    int* temp = tab[size-1];
    for(int i=size;i>0;i--){
        tab[i]=tab[i-1];
    }
    tab[0] = temp;
    printf("décale\n");
    return tab;
}


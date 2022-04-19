#include "generateur_grille.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int verif_ligne(int* code_binaire, int size){
    int cpt=0,i;
    for(i=0;i<size;i++){
        if (code_binaire[i]==0){
            cpt++;
        }
        if ((i!= size-3) && (code_binaire[i]==code_binaire[i+1] && code_binaire[i]==code_binaire[i+2])) return 0;
    }
    if (cpt == size/2) return 1;
    else return 0;
}

int** lignes_valides(int size, int* cpt){
    int** tab = (int**)malloc(sizeof(int*)*(int)pow(2,size));
    int j=0;
    for(int i=0;i<(int)pow(2,size);i++){
        tab[j] = (int*)malloc(sizeof(int)*4);
        tab[j] = int_to_bin(j,size);
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

    /*
    for(int i=0;i<(int)pow(2,size);i++){
        for
    */
    printf("\n");
}
void generer_grille(int size){
    printf("generation grille");
}
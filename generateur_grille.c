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
    for (i = size; i >= 0; i--){
        if((int)pow(2,i) > nombre){
            printf("%d - %d\n",i, nombre);
            code_binaire[size - i] = 1;
            nombre -= (int)pow(2, i);

        }
        else code_binaire[size - i] = 0;
    }
    return code_binaire;
}

void generer_grille(){
    int size = 4;
    int* tab = int_to_bin(1,4);
    for(int i=0; i<size; i++){
        printf("%d ",tab[i]);
    }
}
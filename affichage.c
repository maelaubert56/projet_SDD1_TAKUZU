
#include <stdio.h>
#include "affichage.h"

void afficher_matrice(int **tab,int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}
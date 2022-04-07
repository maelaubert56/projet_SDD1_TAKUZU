#include <stdlib.h>
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


int** appliquer_masque(int **solution, int **masque, int size){

    int **grille_jeu = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        grille_jeu[i] = malloc(sizeof(int)*size);
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(masque[i][j] == 1) grille_jeu[i][j] = solution[i][j];
            else grille_jeu[i][j] = -1;
        }
    }
    return grille_jeu;
}



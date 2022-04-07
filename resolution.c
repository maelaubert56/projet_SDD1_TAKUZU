#import "affichage.h"
#include "resolution.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int** generer_masque(int size,int niveau){
    int i,j;
    int **masque = malloc(sizeof(int*)*size);
    for(i=0; i<size; i++){
        masque[i] = malloc(sizeof(int)*size);
        for(j =0;j<size;j++) { masque[i][j] = 0; }
    }

    srand( time( NULL ) );
    int nb_case;
    switch(niveau){
        case 1: nb_case = (int)(size*size*0.5); break;
        case 2: nb_case = (int)(size*size*0.4); break;
        case 3: nb_case = (int)(size*size*0.3); break;
    }
    while (nb_case != 0) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if ((rand() % size == 1) && (masque[i][j] != 1) && nb_case != 0) {
                    masque[i][j] = 1;
                    nb_case--;
                }
            }
        }
    }
    return masque;
}


int **remplir_matrice(int size) {

    int **mat = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        mat[i] = malloc(sizeof(int)*size);
    }

    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("\nEntrez la valeur pour l'indice %d-%d : ", i, j);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
    return mat;
}


void resoudre(int **masque, int size){

    int solution[4][4] = {{1, 0, 0, 1},
                          {1, 0, 1, 0},
                          {0, 1, 1, 0},
                          {0, 1, 0, 1}};

    /*
    int solution[8][8] = {{0,1,0,1,1,0,0,1},
                              {1,0,0,1,0,0,1,1},
                              {0,1,1,0,0,1,1,0},
                              {1,1,0,0,1,1,0,0},
                              {0,0,1,1,0,0,1,1},
                              {0,1,0,1,1,0,1,0},
                              {1,0,1,0,1,1,0,0},
                              {1,0,1,0,0,1,0,1},
        };*/

    int **tab_solution = malloc(sizeof(int*)*size);
    int **tab_masque = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        tab_solution[i] = malloc(sizeof(int)*size);
        tab_masque[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            tab_solution[i][j]=solution[i][j];
            printf("pok\n");
            tab_masque[i][j]=masque[i][j];
        }
    }

    afficher_matrice(appliquer_masque(tab_solution,tab_masque,size),size);
}
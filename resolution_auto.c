#include "resolution_auto.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test_matrices.h"


int resolve_auto(){

    // passage de la grille jeu dans un tableau dynamique
    /*
    int size = 4;
    int jeu[4][4] =    {    {1,-1,-1,-1},
                            {-1,-1,1,-1},
                            {0,-1,1,0},
                            {-1,1,-1,-1}   };

    *//*
    int size = 8;
    int jeu[8][8] ={
            {-1,-1,0,-1,-1,-1,1,-1},
            {-1,-1,-1,-1,1,-1,1,-1},
            {-1,-1,-1,-1,-1,-1,-1,0},
            {1,-1,0,-1,-1,1,-1,-1},
            {-1,-1,-1,-1,-1,-1,0,-1},
            {-1,1,1,-1,-1,-1,-1,-1},
            {-1,-1,1,-1,-1,-1,-1,1},
            {-1,-1,-1,0,-1,-1,-1,-1}};
    */
    int size = 6;
    int jeu[6][6] = {
            {-1,-1,-1,-1,-1,-1},
            {-1,1,-1,-1,-1,-1},
            {-1,-1,-1,0,-1,0},
            {-1,-1,-1,0,-1,-1},
            {0,-1,-1,-1,1,-1},
            {-1,-1,0,0,-1,0}
    };

    int **tab = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++){
        tab[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            tab[i][j]=jeu[i][j];

        }
    }

    int state, x=0, y=0;

    afficher_matrice(tab,size,0);

    while (y < size){
        while(x < size){
            if (tab[y][x] == -1) {
                state = test_case(y, x, tab, size);
                if (state != -1) {
                    tab[y][x] = state;
                    sleep(1);
                    printf("------------------------------------------\n");
                    afficher_matrice(tab, size,0);

                    x=0,y=0;
                }
                else x++;
            }
            else x++;
        }
        y++;
        x=0;
    }
    printf("\nMatrice resolue ! \n\n");
}



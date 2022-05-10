#include "resolution_auto.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "test_matrices.h"
#include <conio.h>
#include "fonctions_utilitaires.h"


void resolve_auto(){
    printf("------------ Résolution automatique d'une grille ------------\n");
    int continuer_menu = 1;
    int num_taille;
    int size;
    while(continuer_menu == 1) {
        printf("Entrez la taille de la matrice à résoudre : \n\t1 - 4*4\n\t2 - 8*8\n\t3 - 16*16\n==>");
        num_taille = saisieint();
        switch (num_taille) {
            case 1:
                size = 4;
                continuer_menu = 0;
                break;
            case 2:
                size = 8;
                continuer_menu = 0;
                break;
            case 3:
                size = 16;
                continuer_menu = 0;
                break;
            default:
                printf("Vous devez entrer un chiffre entre 1 et 3...");
                break;
        }
    }
    // passage de la grille jeu dans un tableau dynamique
    // TODO choix entre 4 et 8
    int jeu4[4][4] =    {    {1,-1,-1,-1},
                             {-1,-1,1,-1},
                             {0,-1,1,0},
                             {-1,1,-1,-1}   };
    int soluc4[4][4] =  {    {1,0,0,1},
                            {1,0,1,0},
                            {0,1,1,0},
                            {0,1,0,1}   };

    int jeu8[8][8] ={
            {-1,-1,0,-1,-1,-1,1,-1},
            {-1,-1,-1,-1,1,-1,1,-1},
            {-1,-1,-1,-1,-1,-1,-1,0},
            {1,-1,0,-1,-1,1,-1,-1},
            {-1,-1,-1,-1,-1,-1,0,-1},
            {-1,1,1,-1,-1,-1,-1,-1},
            {-1,-1,1,-1,-1,-1,-1,1},
            {-1,-1,-1,0,-1,-1,-1,-1}};
    int soluc8[8][8];

    int jeu6[6][6] = {
            {-1,-1,-1,-1,-1,-1},
            {-1,1,-1,-1,-1,-1},
            {-1,-1,-1,0,-1,0},
            {-1,-1,-1,0,-1,-1},
            {0,-1,-1,-1,1,-1},
            {-1,-1,0,0,-1,0}    };
    int soluc6[6][6];

    int jeu16[16][16] = {
            {-1,-1,-1,0,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1},
            {-1,-1,1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,-1,-1,1},
            {0,0,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,1,-1,-1,-1,-1},
            {0,-1,-1,0,-1,-1,-1,0,0,-1,-1,-1,0,-1,-1,-1},
            {-1,1,1-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1},
            {-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
            {0,1,-1,-1,-1,1,1,-1,1,-1,-1,-1,0,-1,-1,-1},
            {-1,-1,-1,0,-1,-1,0,-1,0,-1,0,-1,-1,0,-1,-1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,-1},
            {-1,0,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,-1},
            {0,0,-1,-1,1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
            {-1,-1,-1,-1,-1,-1,1,-1,-1,-1,0,-1,0,-1,-1,0},
            {-1,-1,1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1},
            {-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,0}   };
    int soluc16[16][16]= {
            {1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1},
            {0,1,1,0,1,0,1,0,1,0,0,1,0,0,1,1},
            {0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,0},
            {1,0,0,1,0,0,1,0,1,0,1,1,0,1,1,0},
            {0,1,1,0,1,0,1,0,0,1,0,1,0,0,1,1},
            {0,1,1,0,1,1,0,1,0,1,0,0,1,1,0,0},
            {1,0,0,1,0,0,1,0,1,0,1,1,0,1,0,1},
            {1,1,0,1,1,0,0,1,0,0,1,0,1,0,1,0},
            {0,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0},
            {1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,1},
            {0,1,0,1,0,0,1,0,1,0,1,1,0,0,1,1},
            {1,0,0,1,0,1,0,1,0,1,1,0,0,1,1,0},
            {0,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1},
            {1,1,0,1,1,0,1,0,1,0,0,1,0,0,1,0},
            {0,0,1,0,0,1,0,1,1,0,1,0,1,0,1,1},
            {1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,0}   };


    int **tab = malloc(sizeof(int*)*size);
    int** soluc = malloc(sizeof(int*)*size);
    //faire tableau des matrices
    if (size==4){
        for(int i=0; i<size; i++){
            tab[i] = malloc(sizeof(int)*size);
            soluc[i] = malloc(sizeof(int)*size);
            for (int j=0; j<size; j++){
                tab[i][j]=jeu4[i][j];
                soluc[i][j]=soluc4[i][j];

            }
        }
    }
    if (size==8) {
        for(int i=0; i<size; i++){
            tab[i] = malloc(sizeof(int)*size);
            soluc[i] = malloc(sizeof(int)*size);
            for (int j=0; j<size; j++){
                tab[i][j]=jeu8[i][j];
                soluc[i][j]=soluc8[i][j];

            }
        }
    }
    if (size==16) {
        for(int i=0; i<size; i++){
            tab[i] = malloc(sizeof(int)*size);
            soluc[i] = malloc(sizeof(int)*size);
            for (int j=0; j<size; j++){
                tab[i][j]=jeu16[i][j];
                soluc[i][j]=soluc16[i][j];
            }
        }
    }
    int state, x=0, y=0;

    afficher_matrice(tab,size,0);

    while (y < size){
        //printf("\ty=%d\n",y);
        while(x < size){

            if (tab[y][x] == -1) {
                state = test_case(y, x, tab, size);
                //printf("\t\tx=%d | state=%d\n",x,state);
                if (state != -1) {
                    //printf("case placée (je crois)\n");
                    tab[y][x] = state;
                    //wait_for_enter();
                    printf("------------------------------------------\n");
                    afficher_matrice(tab, size,0);
                    //printf("\tmodifié :  y=%d | x=%d\n",y,x);
                    x=0,y=0;
                }
                else x++;
            }
            else x++;
        }

        if (x==size && y==size-1 && (test_remplissage(tab,size) == 0)){
            modif_mat_bloquee(tab,soluc,size);
            //wait_for_enter();
            printf("------------------------------------------\n");
            afficher_matrice(tab, size,0);
            y=0,x=0;
        }
        else{
            y++;
            x=0;
        }


    }
    printf("\n\tMatrice resolue ! \n");
    wait_for_enter();
}

int modif_mat_bloquee(int** mat_jeu, int** soluc, int size){
    for(int x=0;x<size;x++){
        for(int y=0;y<size;y++){
            if(mat_jeu[y][x]==-1) {
                //printf("triche dans soluc : %d\n",soluc[y][x]);
                mat_jeu[y][x] = soluc[y][x];
                return 1;
            }
        }
    }
    return 0;
}

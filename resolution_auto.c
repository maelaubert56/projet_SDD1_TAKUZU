#include "resolution_auto.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ligne_remplie(int y,int** tab, int size);
int colonne_remplie(int x,int** tab, int size);
int test_suite (int y, int x, int** tab, int size);
int test_autour(int y, int x, int** tab, int size);
int test_case(int y, int x, int** tab, int size);

int resolve_auto(){

    // passage de la grille jeu dans un tableau dynamique

    int size = 4;
    int jeu[4][4] =    {    {1,-1,-1,-1},
                            {-1,-1,1,-1},
                            {0,-1,1,0},
                            {-1,1,-1,-1}   };

    /*
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
    *//*
    int size = 6;
    int jeu[6][6] = {
            {-1,-1,-1,-1,-1,-1},
            {-1,1,-1,-1,-1,-1},
            {-1,-1,-1,0,-1,0},
            {-1,-1,-1,0,-1,-1},
            {0,-1,-1,-1,1,-1},
            {-1,-1,0,0,-1,0}
    };*/

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

// tests
int ligne_remplie(int y,int** tab, int size){ // renvoit -1 si pas remplie, renvoie 0 ou 1 si on a le max de 0 ou de 1
    int i;
    int tabsomme[3] = {0,0}; // nombre de cases à 0, 1
    for(i=0;i<size;i++){
        if (tab[y][i] == 0) tabsomme[0]++;
        else if (tab[y][i] == 1) tabsomme[1]++;
    }
    if (tabsomme[0] == size/2) return 0;
    if (tabsomme[1] == size/2) return 1;
    return -1;
}

int colonne_remplie(int x,int** tab, int size){ // renvoit -1 si pas remplie, renvoie 0 ou 1 si on a le max de 0 ou de 1
    int i;
    int tabsomme[3] = {0,0}; // nombre de cases à 0, 1
    for(i=0;i<size;i++){
        if (tab[i][x] == 0) tabsomme[0]++;
        else if (tab[i][x] == 1) tabsomme[1]++;
    }
    if (tabsomme[0] == size/2) return 0;
    if (tabsomme[1] == size/2) return 1;
    return -1;
}

int test_suite (int y, int x, int** tab, int size){ // renvoie -1 si pas de suite, 0 si suite de 0, 1 si suite de 1

    if ((x > 1) && (tab[y][x-1]==tab[y][x-2])) return tab[y][x-1]; // on test a gauche de la case
    if ((x < size-2) && (tab[y][x+1]==tab[y][x+2])) return tab[y][x+1]; // on test a droite de la case
    if ((y > 1) && (tab[y-1][x]==tab[y-2][x])) return tab[y-1][x]; // on test au dessus de la case
    if ((y < size-2) && (tab[y+1][x]==tab[y+2][x])) return tab[y+1][x]; // on test en dessous de la case
    return -1;
}

int test_autour(int y, int x, int** tab, int size){ // renvoie -1 si pas entouré, 0 si entouré de 0, 1 si entouré de 1
    if ((x > 0) && (x<size-1) && (tab[y][x-1]==tab[y][x+1])) return tab[y][x-1]; // on test a l'horizontale
    if ((y > 0) && (y<size-1) && (tab[y-1][x]==tab[y+1][x])) return tab[y-1][x]; // on test a la verticale
    return -1;
}


int test_case(int y, int x, int** tab, int size){
    int temp;

    temp = ligne_remplie(y,tab,size);
    if (temp!=-1) return (temp+1)%2;

    temp = colonne_remplie(x,tab,size);
    if (temp!=-1) return (temp+1)%2;

    temp = test_suite(y,x,tab,size);
    if (temp!=-1) return (temp+1)%2;

    temp = test_autour(y,x,tab,size);
    if (temp!=-1) return (temp+1)%2;

    return -1;
}


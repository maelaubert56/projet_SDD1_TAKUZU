#import "affichage.h"
#include "resolution.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>


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
    for(int i=0; i<size; i++){
        tab_solution[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            tab_solution[i][j]=solution[i][j];
        }
    }
    int **grille_jeu = appliquer_masque(tab_solution,masque,size);

    int gagne = 0, val;
    COORDS coords;
    while (gagne != 1){
        // on choisis une case et une valeur
        coords = choisir_case(grille_jeu,size);
        do{
            printf("\nEntrez la valeur de cette case (0 ou 1): ");
            scanf("%d",&val);
        }while (val !=1 && val != 0);

        //on vérifie que cette valeur corresponds à la solution
        if(val != tab_solution[coords.i][coords.j]) printf("Cette valeur est fausse... ");
        else grille_jeu[coords.i][coords.j] = val;

        //on regarde si la grille est résolue
        if (verif_grille(grille_jeu,tab_solution,size) == 1) gagne = 1;

        printf("\n");
    }
    printf("Bravo, vous avez resolu la grille:\nAppuyez sur entrer pour continuer:");
    fflush(stdout);
    _getch();  // permet de mettre une pause avant de revenir au menu quand l'utilisateur appuie sur une touche.
    afficher_matrice(grille_jeu,size,0);
}


COORDS choisir_case(int** tab, int size){
    COORDS coords;
    afficher_matrice(tab,size,0);
    do{
        printf("\nChoisissez la case grace aux indices de 0 a 3 (la colonne puis la ligne) :");
        scanf("%d %d",&coords.i, &coords.j);
    }while(tab[coords.i][coords.j]!=-1);
    printf("\n");
    return coords;
}

int verif_grille(int** grille_jeu,int** grille_soluc,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if (grille_jeu[i][j] != grille_soluc[i][j]) return 0;
        }
    }
    return 1;
}
#include "resolution.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>

int* nbparligne(int **tab, int size,int num_ligne,int orientation);

int resolve_auto(){
    printf("resolv auto\n");

    int jeu[4][4] =    {    {1,-1,-1,-1},
                            {-1,-1,1,-1},
                            {0,-1,1,0},
                            {-1,1,-1,-1}   };

    int size = 4;
    int **tab = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        tab[i] = malloc(sizeof(int)*size);
        for (int j=0; j<size; j++){
            tab[i][j]=jeu[i][j];
        }
    }

    int* tabsomme = nbparligne(tab,size,0,0);
    printf("%d",tabsomme);
}


int* nbparligne(int **tab, int size,int num_ligne,int orientation){
    int i;
    int tabsomme[3] = {0,0,0}; // nombre de cases à 0, 1, -1
    if (orientation == 0){
        for(i=0;i<size;i++){
            if (tab[num_ligne][i] == 0) tabsomme[0]++;
            else if (tab[num_ligne][i] == 1) tabsomme[1]++;
            else tabsomme[2]++;
        }
    }

    return tabsomme;
}
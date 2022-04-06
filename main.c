#include <stdio.h>
#include "resolution.h"
#include <stdlib.h>
#include <string.h>

//prototypes:
int menu_resoudre_manuel();
int menu_generer_grille();
void afficher_matrice(int **p,int size);



int main() {




    int choix = 0, continuer = 1;

    while (continuer == 1) {
        printf("----------------- BIENVENUE SUR NOTRE TAKUZU ! ---------------\n");
        printf("Veuillez choisir une option : \n");
        printf("\t1 - R%csoudre une grille \n", 130);
        printf("\t2 - R%csoudre une grille automatiquement \n", 130);
        printf("\t3 - G%cn%crer une grille de Takuzu\n", 130, 130);
        printf("\t4 - Quitter le jeu\n");
        printf("==>");
        scanf("%d", &choix);
        switch (choix) {
            case 1: {
                menu_resoudre_manuel();
                break;
            }
            case 2: {
                resolve_auto(tab,size);
                break;
            }
            case 3: {
                menu_generer_grille();
                break;
            }
            case 4: {
                continuer = 0;
                break;
            }
            default : {
                printf("Vous devez entrer une valeur entre 1 et 5...\n");
                break;
            }
        }
    }
    return 0;
}


// fonctions des menus
int menu_resoudre_manuel() {
    int solution[4][4] = {  {1,0,0,1},
                            {1,0,1,0},
                            {0,1,1,0},
                            {0,1,0,1}   };

    int masque[4][4] = {    {1,0,0,0},
                            {0,0,1,0},
                            {1,0,1,1},
                            {0,1,0,0}   };

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

    int choice, continuer = 1;
    while (continuer == 1) {
        printf("----------------- Resoudre une grille ---------------\n");
        printf("Veuillez choisir une option : \n");
        printf("\t - Choisir la taille \n");
        printf("\t2 - Saisir un masque manuellement \n");
        printf("\t3 - G%cn%crer un masque automatiquement\n", 130, 130);
        printf("\t4 - Jouer \n");
        printf("\t5 - Retour\n");
        printf("==>");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("taille \n");
                break;
            }
            case 2: {
                printf("manuel \n");
            }
                break;
            case 3: {
                printf("automatique\n");
                break;
            }
            case 4: {
                printf("jouer\n");
                afficher_matrice(tab, 4);
                break;
            }
            case 5: {
                continuer = 0;
                break;
            }
            default : {
                printf("Vous devez entrer une valeur entre 1 et 5...\n");
                break;
            }
        }
    }
    return 0;
}

int menu_generer_grille(){
    int taille,choice, continuer = 1;
    while (continuer == 1) {
        printf("Choisir la taille de la matrice\n\t1 - matrice 4x4\n\t2 - matrice 8x8\n==>");
        scanf("%d", &taille);
        taille*=4;
        printf("Veuillez choisir une option : \n");
        printf("\t1 - Afficher l'ensemble des lignes et colonnes valides \n");
        printf("\t2 - G%cn%crer une grille de Takuzu\n", 130, 130);
        printf("\t3 - Retour\n");
        printf("==>");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("afficher \n");
                break;
            }
            case 2: {
                printf("grille \n");
            }
                break;
            case 3:{
                continuer = 0;
                break;
            }
            default : {
                printf("Vous devez entrer une valeur entre 1 et 3...\n");
                break;
            }
        }
        return 0;
    }
}

// autres fonctions
void afficher_matrice(int **tab,int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}
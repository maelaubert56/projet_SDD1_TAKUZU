#include <stdio.h>
#include "resolution_auto.h"
#include <stdlib.h>
#include "affichage.h"
#include "resolution.h"


//prototypes:
int menu_resoudre_manuel();
int menu_generer_grille();


int main(){




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
                resolve_auto();
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
    // valeurs par default si le joueur veut lancer directement
    int choice, continuer = 1, size = 4, num_niveau=1;
    int** masque = generer_masque(size,num_niveau);
    char *mode = "auto", *niveau = "facile";
    while (continuer == 1) {

        printf("----------------- Resoudre une grille ---------------\n");
        printf("   Taille : %dx%d\t\tMasque : %s\t\tNiveau : %s\n",size,size, mode, niveau);
        printf("Veuillez choisir une option : \n");
        printf("\t1 - Choisir la taille \n");
        printf("\t2 - Saisir un masque manuellement \n");
        printf("\t3 - G%cn%crer un masque automatiquement\n", 130, 130);
        printf("\t4 - Jouer \n");
        printf("\t5 - Retour\n");
        printf("==>");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("------------ Choisisez entre 4x4 ou 8x8 ------------\n");
                printf("\t4 -> 4x4\n\t8 -> 8x8\n==>");
                scanf("%d",&size);
                generer_masque(size,num_niveau); // genere un masque pour eviter un conflit entre la taille de la solution et la taille du masque
                break;
            }
            case 2: {
                mode = "personnalise";
                printf("------------ Entrez le masque ------------\n");
                masque = remplir_matrice(size);
                printf("Votre masque est :\n");
                afficher_matrice(masque,size);
                printf("\n");
                break;
            }

            case 3: {
                mode = "auto";
                printf("------------ Generation automatique du masque ------------\n");
                printf("Entrez le niveau de difficulte : \n\t1 - facile\n\t2 - moyen\n\t3 - difficile\n==>");
                scanf("%d",&num_niveau);
                switch(num_niveau){
                    case 1: niveau = "facile"; break;
                    case 2: niveau = "moyen"; break;
                    case 3: niveau = "difficile"; break;
                }

                printf("Masque genere automatiquement ...\n");
                masque = generer_masque(size,num_niveau);
                printf("Votre masque est :\n");
                afficher_matrice(masque,size);
                printf("\n");
                break;
            }
            case 4: {
                resoudre(masque,size);
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

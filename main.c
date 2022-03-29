#include <stdio.h>



void afficher_matrice_4x4(int **p){
    int size = 4;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d\t",*(*(p + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int solution[4][4] = {  {1,0,0,1},
                            {1,0,1,0},
                            {0,1,1,0},
                            {0,1,0,1}   };

    int masque[4][4] = {    {1,0,0,0},
                            {0,0,1,0},
                            {1,0,1,1},
                            {0,1,0,0}   };

    int jeu[4][4] =    {    {1,0,0,0},
                            {0,0,1,0},
                            {1,0,1,1},
                            {0,1,0,0}   };


    int choix =0,continuer=1,choix1=0,choix3=0,taille=0;
    int** p=(int**)*solution;
    while (continuer ==1) {
        printf("----------------- BIENVENUE SUR NOTRE TAKUZU ! ---------------\n");
        printf("Veuillez choisir une option : \n");
        printf("1 - R%csoudre une grille \n",130);
        printf("2 - R%csoudre une grille automatiquement \n",130);
        printf("3 - G%cn%crer une grille de Takuzu\n",130,130);
        printf("4 - Quitter le jeu\n");
        printf("==>");
        scanf("%d",&choix);
        switch( choix )
        {
            case 1:{
                printf("Veuillez choisir une option : \n");
                printf("1 - Choisir la taille \n");
                printf("2 - Saisir un masque manuellement \n");
                printf("3 - G%cn%crer un masque automatiquement\n",130,130);
                printf("4 - Jouer \n");
                printf("==>");
                scanf("%d",&choix1);
                switch( choix1 )
                {
                    case 1:{
                        printf("taille \n");
                        break;}
                    case 2:{
                        printf("manuel \n");}
                        break;
                    case 3:{
                        printf("automatique\n");
                        break;}
                    case 4:{
                        printf("jouer\n");
                        break;}
                    default :{
                        printf("Autre\n");
                        afficher_matrice_4x4(&p);
                        break;}
                }
                break;}
            case 2:{
                printf("2 - R%csoudre une grille automatiquement \n",130);}
                break;
            case 3:{
                printf("Choisir la taille de la matrice\nEntrez 4 pour une matrice 4x4\nEntrez 8 pour une matrice 8x8\n");
                printf("==>");
                scanf("%d",&taille);
                printf("Veuillez choisir une option : \n");
                printf("1 - Afficher l’ensemble des lignes et colonnes valides \n");
                printf("2 - G%cn%crer une grille de Takuzu\n",130,130);
                printf("==>");
                scanf("%d",&choix3);
                switch( choix3 )
                {
                    case 1:{
                        printf("afficher \n");
                        break;}
                    case 2:{
                        printf("grille \n");}
                        break;
                    default :{
                        printf("Autre\n");
                        break;}
                }
                break;}
            case 4:{
                continuer=0;
                break;}
            default :{
                printf("Autre\n");
                break;}
        }
    }
    return 0;
}

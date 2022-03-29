#include <stdio.h>

int main() {
    int choix =0,continuer=1,choix1=0;
    while (continuer ==1) {
        printf("-----------------BIENVENU SUR NOTRE TAKUZU ! ---------------\n");
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
                printf("1 - Choisir la taille \n",130);
                printf("2 - Saisir un masque manuellement \n",130);
                printf("3 - G%cn%crer un masque automatiquement\n",130,130);
                printf("4 - Jouer \n",130);
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
                        continuer=0;
                        break;}
                }
                break;}
            case 2:{
                printf("2 - R%csoudre une grille automatiquement \n",130);}
                break;
            case 3:{
                printf("3 - G%cn%crer une grille de Takuzu\n",130,130);
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

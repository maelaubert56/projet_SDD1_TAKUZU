#include <stdio.h>

int main() {
    int choix =0,continuer=1;
    while (continuer ==1) {
        printf("-----------------BIENVENU SUR NOTRE TAKUZU ! ---------------\n");
        printf("Veuillez choisir une option : \n");
        printf("1 - R%csoudre une grille \n",130);
        printf("2 - R%csoudre une grille automatiquement \n",130);
        printf("3 - G%cn%crer une grille de Takuzu\n",130,130);
        printf("==>");
        scanf("%d",&choix);
        switch( choix )
        {
            case 1:{
                printf("1 - R%csoudre une grille \n",130);
                break;}
            case 2:{
                printf("2 - R%csoudre une grille automatiquement \n",130);}
                break;
            case 3:{
                printf("3 - G%cn%crer une grille de Takuzu\n",130,130);
                break;}
            default :{
                printf("Autre\n");
                continuer=0;
                break;}
        }
    }
    return 0;
}

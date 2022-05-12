#ifndef PROJET_SDD1_TAKUZU_AFFICHAGE_H
#define PROJET_SDD1_TAKUZU_AFFICHAGE_H

void afficher_matrice(int **tab,int size, int indices);
int** appliquer_masque(int **solution, int **masque, int size);
void clear_screen();
void wait_for_enter();
void color(int t,int f);
#endif //PROJET_SDD1_TAKUZU_AFFICHAGE_H

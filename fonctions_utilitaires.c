#include "fonctions_utilitaires.h"
#include <stdio.h>
#include <stdlib.h>

int saisieint() {
    char* str = (char*) malloc(10*sizeof(char));
    fgets(str,10,stdin); //recuperation de la chaine
    int result= 0;
    int puiss= 1;
    int no_digit = 1;

    while (('-' == (*str)) || ((*str) == '+'))
    {
        if (*str == '-')
            puiss = puiss * -1;
        str++;
    }

    while ((*str >= '0') && (*str <= '9'))
    {
        no_digit = 0;
        result = (result * 10) + ((*str) - '0');
        str++;
    }

    if (no_digit == 1) return -100;
    else return (result * puiss);
}


#include <iostream>
#include <stdalign.h>
#include <stdio.h> //para função gets
#include <stdlib.h> // para alocação dinamica malloc

using namespace std;

int main (){

    char *vnome;

    vnome = (char *) /*Aqui (char *) é pra converter o valor do malloc em um ponteiro char*/ malloc(sizeof(char));

    gets(vnome); //isso é pra pegar nomes complexos com espaço etc (funciona como o cin)...

    cout << vnome;

    system ("\npause");
    return 0;
}
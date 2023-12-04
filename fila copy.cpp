#include <iostream>
#include <stdlib.h>
#include <queue> //biblioteca para filas

/*Metodos da fila
empty
size
front
back
push
pop*/

using namespace std;

int main(){
    string N;
    int i=0, tam=0;

    queue <string> cartas;

    if (cartas.empty() || cartas.size() == 0 /*esses dois comandos da no mesmo*/){
        cout <<"fila vazia \n\n";
    }else{
        cout <<"fila com cartas \n\n";
    }

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    
    cout << "Tamanho da fila: " << cartas.size() << "\n";
    cout << "Ultima carta adicionada: " << cartas.back() << "\n";
    cout << "Primeira carta adicionada: " << cartas.front() << "\n";
    cout << "Informe qual carta deseja adicionar: ";

    cartas.pop();

    cin >> N;
    cartas.push(N);


    cout << "Tamanho da fila: " << cartas.size() << "\n";
    cout << "Ultima carta adicionada: " << cartas.back() << "\n";
    cout << "Primeira carta adicionada: " << cartas.front() << "\n";

    while(N[i] != '\0') { //esse '\0' é pra indicar o final da palavra inserida
        i++;
        tam++;
    }

    for (i = 0; i < tam; i++){
        cout << N[i];
    }

    while (!cartas.empty()){
        cout << "primeira Carta: " << cartas.front() << "\n\n";
        cartas.pop();
    }

    cout << "\ndeu bom\n" << tam;
    system ("pause");
    return 0;
}
#include <iostream>
#include <stack> //biblioteca para pilha
#include <stdlib.h>

using namespace std;

int main() {

    string N;
    int i=0, tam=0;

    stack <string> cartas;

    if (cartas.empty() || cartas.size() == 0 /*esses dois comandos da no mesmo*/){
        cout <<"Pilha vazia \n\n";
    }else{
        cout <<"pilha com cartas \n\n";
    }

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    
    cout << "Tamanho da pilha: " << cartas.size() << "\n";
    cout << "Carta do topo " << cartas.top() << "\n";
    cout << "Informe qual carta deseja adicionar: ";

    cartas.pop();

    cin >> N;
    cartas.push(N);


    cout << "Tamanho da pilha: " << cartas.size() << "\n";
    cout << "Carta do topo " << cartas.top() << "\n";

    while(N[i] != '\0') { //esse '\0' é pra indicar o final da palavra inserida
        i++;
        tam++;
    }

    for (i = 0; i < tam; i++){
        cout << N[i];
    }

    cout << "deu bom" << tam;
    system ("pause");
    return 0;
}
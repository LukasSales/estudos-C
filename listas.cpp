#include <iostream>
#include <list>

/*
funcão_fron - manipula o elemento do começo da lista
funcão_back - manipula o elemento do final da lista

*/

using namespace std;

int main(){

    list <int> aula(5,50); /*uma lista de 5 posições e com 50 elementos em cada*/
    list <int> aulas;
    list<int>::iterator it; /*para manipular elementos de qualquer posição*/

    int tam = 10;

    for (int i =0; i < tam; i++){
        aulas.push_front(i);
    }

    it = aulas.begin();
    advance(it,5); /*Aqui informa qual posição quero inserir*/

    aulas.insert(it,10); /*Aqui informa qual valor vou inserir*/
    aulas.insert(it,11); /*Aqui informa qual valor vou inserir*/

    aulas.sort(); /*ordena os valores*/
    aulas.reverse(); /*Reverte os valores*/

    cout << "Tamanho da lista: " << aulas.size() << "\n\n";

    tam = aulas.size();

    for (int i=0; i< tam; i++){
        cout << aulas.front() << "\n\n";
        aulas.pop_front();
    }

    return 0;
}
#include <iostream>
#include <list>

/*
funcão_fron - manipula o elemento do começo da lista
funcão_back - manipula o elemento do final da lista
aulas.clear() - remove tudo de uma vez
*/

using namespace std;

int main(){

    list <int> aula(5,50); /*uma lista de 5 posições e com 50 elementos em cada*/
    list <int> aulas, teste;
    list<int>::iterator it; /*para manipular elementos de qualquer posição*/

    int tam = 10;

    for (int i =0; i < tam; i++){
        aulas.push_front(i);
        teste.push_back(i*10);
    }

    it = aulas.begin();
    advance(it,5); /*Aqui informa qual posição quero inserir*/

    aulas.insert(it,10); /*Aqui informa qual valor vou inserir*/
    aulas.insert(it,11); /*Aqui informa qual valor vou inserir*/

    aulas.erase(--it); /*remove um elemento que esta no advance(11)*/
    aulas.merge(teste); /*Vai migrar os elementos de teste para a lista aulas*/

    cout << "Tamanho da lista: " << aulas.size() << "\n\n";

    tam = aulas.size();


    for (int i=0; i< tam; i++){
        cout << aulas.front() << "\n\n";
        aulas.pop_front();
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int *p;
    int vetor[10]; //array

    p = vetor; // aqui estou atribuindo o primeiro endereço do array(vetor) para o ponteiro (poderia ser escrito como p = &vetor[0];)

    *p = 0;
    cout << "\n" << p << " E seu valor é: " << *p << "\n";
    *(p++);
    *p = 10;
    cout << "\n" << p << " E seu valor é: " << *p << "\n";
    *(p++);
    *p = 20;
    cout << "\n" << p << " E seu valor é: " << *p << "\n";
    *(p++);
    *p = 30;
    cout << "\n" << p << " E seu valor é: " << *p << "\n";

    return 0;
}
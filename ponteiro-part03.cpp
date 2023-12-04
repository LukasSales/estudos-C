#include <iostream>
#include <stdalign.h>

using namespace std;


void somar(float *var, float valor);

void ptar(float *v, int contador);

int main() {
    int N;

    cin >> N;
    float num = 0;
    float vetor[N];

    somar(&num,15); //como o primeiro parametro é um ponteiro, quando se passa o endereço de uma variavel, ela será alterada pela função externa
    ptar(vetor,N); //quando for vetor não precisa por o & de endereço.

    cout << num << "\n";

    for (int i = 0; i < N; i++){
        cout << vetor[i] << "\n";
    }


    system ("pause");

    return 0;
}

void somar(float *var, float valor){
    *var +=valor;

}

void ptar(float *v, int contador){
    for (int i = 0; i < contador; i++){
        v[i] = i;
    }
}
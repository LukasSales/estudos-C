#include <iostream>
#include <stdalign.h>

using namespace std;

void fatorial (int numb, int resp = 1, int aux = 0);
void fibonnaci(int valor, int auxx =0, int inicio = 0, int resul = 1);

int main (){
    int N,M;

    cin >> N;
    cin >> M;

    fatorial(N);
    cout << "\n\n";
    fibonnaci(M);

    system("pause");

    return 0;
}


void fatorial (int numb, int resp, int aux){
    if (1 < numb){
        cout << numb << " * ";
        fatorial(--numb, resp*= numb, aux = 1);
    }else if(numb > 0){
        cout << numb << " = " << resp;
        fatorial(--numb, resp*= numb, aux = 1);
    } else if ((numb == 0) && (aux == 0)){
        cout << numb << " = " << resp;
    }
}

void fibonnaci(int valor, int auxx, int inicio, int resul){
    if (valor > 0){
        cout << inicio << ", ";
        fibonnaci (--valor, auxx = inicio, inicio = resul, resul = resul + auxx);
    } else{
        cout << inicio << ".";
    }
}
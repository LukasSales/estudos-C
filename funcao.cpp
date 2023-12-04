#include <iostream>
#include <stdlib.h>

using namespace std;

void texto();
int soma(int a, int b);
void tr(string tra[4]);

int main() {
    int resp;
    string transp[4]={"Carro", "moto", "barco", "skate"};

    resp = soma(5,4);
    texto();
    cout << "Valor da respsota:" << resp << "\n";
    cout << "Valor da respsota:" << soma(100,15) << "\n";

    tr(transp);

    system ("pause");

    return 0;
}

int soma(int a, int b){
    return a + b;

}

void texto(){
    cout << "\nOla mundo!\n";
}

void tr(string tra[4]){
    for (int i=0; i<4;i++){
        if (i < 3){
        cout <<tra[i] << " ";}
        else{
        cout << tra[i] << "\n\n" << "Terminou" << "\n\n";
    }
    }
}
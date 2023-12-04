#include <iostream>
#include <stdalign.h>
#include <string>

using namespace std;

int main() {

    string frase;
    char sobrenome;
    int i, contador;

    getline(cin,frase);
    contador = frase.size();

    for (i=0; i < contador; i++){
        cout << frase[i];

        if (i == 1){
            cout << "\n";
            sobrenome = frase[i];
            cout << sobrenome;
        }
    }

    system ("pause");

    return 0;
}
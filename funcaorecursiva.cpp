#include <iostream>
#include <stdlib.h>

using namespace std;

void contador(int num, int cont=0);

int main(){

    contador(20);

    system("pause");

    return 0;
}


void contador(int num, int cont){
    cout << cont << "\n";
    if (cont<num){
        contador(num,++cont);
    }
}
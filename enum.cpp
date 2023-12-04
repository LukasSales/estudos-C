#include <iostream>

using namespace std;

int main(){
    enum armas{fuzil =100, revolve = 8, rifle = 4, escopeta = 12};
    armas armaSel;

    armaSel = rifle; // aqui vai mostrar o valor de 4, que é o que foi armazenado em rifle

    cout << armaSel;
 
    return 0;
}
#include <iostream>

using namespace std;

int main() {

    string veiculo = "Carro";
    string *pv;

    pv = &veiculo;

    cout << veiculo << "\n";
    cout << pv << "\n";
    cout << *pv << "\n";

    *pv = "Moto"; // no endereço apontado por pv adciione o valor moto
    cout << *pv << "\n";
    cout << veiculo << "\n";

    return 0;
}
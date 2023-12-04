#include <iostream>

using namespace std;

struct Carro{
    string nome;
    string cor;
    int pot;
    int velMax;
    int vel;
    /*Aqui é uma estrutura com 4 caracteristicas, nome, cor, potencia e velocidade maxima*/

    /*Metodos para inserir valores*/

    void inserir(string stnome, string stcor, int stpot, int stvelMax){
        nome = stnome;
        cor = stcor;
        pot = stpot;
        velMax = stvelMax;
        vel = 0;
    }

    void mostrar(){
        cout << "Nome.........:" << nome << "\n";
        cout << "Cor.........:" << cor << "\n";
        cout << "Potencia.........:" << pot << "\n";
        cout << "Velocidade Maxima.........:" << velMax << "\n";
        cout << "Velocidade Atual.........:" << vel << "\n";

    }

    void mudaVel(int mudv){
        vel = mudv;
        if (vel > velMax){
            vel = velMax;
        }
        if (vel < 0){
            vel = 0;
        }

    }
};

int main() {

    Carro car1, car2, car3;

    car1.nome = "marquinhos";
    car1.cor = "vermelho";
    car1.pot = 450;
    car1.velMax = 350;

    car2.nome = "relampago";
    car2.cor = "preto";
    car2.pot = 500;
    car2.velMax = 400;

    cout << "Nome: " << car1.nome << "\n";
    cout << "Cor: " << car1.cor << "\n";
    cout << "Potencia: " << car1.pot << "\n";
    cout << "Velocidade maxima: " << car1.velMax << ".\n";

    cout << "Nome: " << car2.nome << "\n";
    cout << "Cor: " << car2.cor << "\n";
    cout << "Potencia: " << car2.pot << "\n";
    cout << "Velocidade maxima: " << car2.velMax << ".\n";

    /*Aqui vai ser usado os metodos da struct*/

    car3.inserir("Lucas", "Branco", 750,500);
    car3.mostrar();
    car3.mudaVel(850);
    car3.mostrar();
    car3.mudaVel(450);
    car3.mostrar();

    return 0;
}
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

    /*Agora vamos utilizar um array com ponteiro*/
    Carro *carros= new Carro[5]; //é necessario ser um ponteiro

    Carro car1, car2, car3, car4, car5;

    carros[0] = car1; carros[1] = car2; carros[2] = car3; carros[3] = car4; carros[4] = car5;

    carros[0].inserir("Marquinhs", "Branco", 450, 600);
    carros[1].inserir("Velocidade", "Preto", 250, 800);
    carros[2].inserir("Busão", "Amarelo", 700, 350);
    carros[3].inserir("Comum", "Cinza", 350, 120);
    carros[4].inserir("Relampago", "Vermelho", 450, 750);

    for (int i = 0; i < 5; i++){
        carros[i].mostrar();
    }



    return 0;
}
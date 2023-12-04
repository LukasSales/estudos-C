#include <iostream>
#include <stdalign.h>


using namespace std;

class Veiculo {

private:
    int velMax;
    string nome;
    bool ligado=false;
    void setVelMax (int vm);

public:

    int vel;
    int tipo;
    Veiculo(int tp);
    int getVelMax();
    bool getLigado();
    void setLigado (int l);
};  

void Veiculo::setLigado (int l){
    if (l == 1){
        ligado = true;
    }else if (l == 0){
        ligado = false;
    }
}
bool Veiculo::getLigado(){
    return ligado;
}
void Veiculo::setVelMax (int vm){
    velMax = vm;
}

int Veiculo::getVelMax(){

    return velMax;
}

Veiculo::Veiculo(int tp){
    tipo = tp;
    if (tipo == 1){
        nome = "Carro";
        setVelMax(200);

    } else if (tipo == 2){
        nome = "Aviao";
        setVelMax(800);

    }else if (tipo == 3){
        nome = "Navio";
        setVelMax(120);

    }
}

int main() {

    Veiculo *v1 = new Veiculo(1);
    Veiculo *v2 = new Veiculo(2);
    Veiculo *v3 = new Veiculo(3);

    cout << v1->getVelMax();
    cout << v2->getVelMax();
    cout << v3->getVelMax();

    v1->setLigado(1);
    v2->setLigado(0);
    v3->setLigado(1);

    if (v1->getLigado()){
        cout << "Veiculo esta ligado" << endl;
    } else {
        cout << "Veiculo esta desligado" << endl;
    }

    if (v2->getLigado()){
        cout << "Veiculo esta ligado" << endl;
    } else {
        cout << "Veiculo esta desligado" << endl;
    }

    if (v3->getLigado()){
        cout << "Veiculo esta ligado" << endl;
    } else {
        cout << "Veiculo esta desligado" << endl;
    }

    system ("Pause");
    return 0;
}
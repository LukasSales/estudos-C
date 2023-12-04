#include <iostream>

using namespace std;

/*Objetos são as instancias das classes*/

class aviao {

    private:



    public:

    int vel = 0;
    int velMax;
    string tipo;

    void ini(int tp);

};


    void aviao::ini(int tp){

        if (tp == 1){
            this->velMax = 800;
            this->tipo = "Jato";
        } else if (tp == 2){
            this->velMax = 350;
            this->tipo = "Monomotor";
        }else if (tp == 3){
            this->velMax = 180;
            this->tipo = "Planador";
        }
    }

int main() {


    aviao *av1 = new aviao();
    aviao *av2 = new aviao();

    av1->ini(1);
    av2->ini(2);

    cout << av1->velMax;
    cout << av2->tipo;

    return 0;
}
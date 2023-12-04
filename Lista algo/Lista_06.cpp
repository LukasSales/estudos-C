#include <iostream>

using namespace std;

class celula {
public:
    int valor;
    int pai;
    int Pesquerda;
    int Pbaixo;
    bool Pvertical = true;
    bool Phorizontal = true;

    // construtor padrão
    celula() {
        valor = 0;
        pai = 0;
        Pesquerda = 0;
        Pbaixo = 0;
    }

    celula(int v) {
        valor = v;
        pai = v;
        Pesquerda = 0;
        Pbaixo = 0;
    }

    void attPai(int Npai){
        pai = Npai;
    }

    void attvalorPleft(int v_paredeesquer) {
        Pesquerda = v_paredeesquer;
    }

    void attvalorPdown(int v_paredebaixo) {
        Pbaixo = v_paredebaixo;
    }

    int obtervalor() {
        return valor;
    }

    int obterpai(){
        return pai;
    }

    bool verificPvertical(){
        return Pvertical;
    }

    bool verificPhorizontal(){
        return Phorizontal;
    }

    void excluirPvertical(){
        Pvertical = false;
    }
    void excluirPhorizontal(){
        Phorizontal = false;
    }
};



int main(){

    int parada;
    int caso=0;
    int Tlabirinto = 0;
    int Qntparedesexcluidas = 0;
    int Parederemovida = 0;
    int Qntconsultas = 0;


    cin >> parada;
    cin.ignore();

    while (parada != 0){
       scanf("%d %d %d", &Tlabirinto, &Qntparedesexcluidas, &Qntconsultas);
       celula Matriz[Tlabirinto][Tlabirinto];
       int valor = 0;
       int valorparedes = 0;

       for (int i = 0; i < Tlabirinto; i++){
        for (int j = 0; j < Tlabirinto; j++){
            Matriz[i][j] = celula(valor);

            if(j != (Tlabirinto-1)){
            Matriz[i][j].attvalorPleft(valorparedes);
            Matriz[i][j].attvalorPdown(valorparedes+(Tlabirinto-1));
            
            }
            else {
            Matriz[i][j].attvalorPdown(valorparedes+(Tlabirinto-1));
            valorparedes =(Tlabirinto-1);
            };
            valor ++;
            valorparedes ++;
        }
       };

       while (Qntparedesexcluidas != 0){

        int Nparede;
        bool encontrado = false;

        cin >> Nparede;

        for (int i = 0; i < Tlabirinto && !encontrado; i++){
            for (int j = 0; j < Tlabirinto; j++){

                if (Matriz[i][j].Pesquerda == Nparede){
                    Matriz[i][j].excluirPvertical();
                    Matriz[i][j+1].attPai(Matriz[i][j].obterpai());
                    encontrado = true;
                    break;
                }

                else if (Matriz[i][j].Pbaixo == Nparede){
                    Matriz[i][j].excluirPhorizontal();
                    Matriz[i+1][j].attPai(Matriz[i][j].obtervalor());
                    encontrado = true;
                    break;
                }
            }
        }

        Qntparedesexcluidas --;
       }

        int consulta = 0;
       while (Qntconsultas != 0){
        int Priparent, Segparent;
        int Paiaux, Linhaaux, Colunaaux;
        bool encontrado = false;
        bool Pai_filho = false;
        
        scanf ("%d %d", &Priparent, &Segparent);

        if (Priparent <= Tlabirinto){
            Paiaux = Matriz[0][Priparent].obterpai();
        } else {
            Linhaaux = (Priparent/Tlabirinto);
            Colunaaux = Priparent - Tlabirinto;
            Paiaux = Matriz[Linhaaux][Colunaaux].obterpai();
        }

        if (Segparent <= Tlabirinto){
            if (Matriz[0][Segparent].obterpai() == Paiaux){
                Pai_filho = true;
            }
        } else {
            Linhaaux = (Priparent/Tlabirinto);
            Colunaaux = Priparent - Tlabirinto;
            if ( Matriz[Linhaaux][Colunaaux].obterpai() == Paiaux){
                Pai_filho = true;
            }
        }

        if (Pai_filho == true){
            cout << caso << "." << consulta << " " << 1 << endl;
        }
        else{
            cout << caso << "." << consulta << " " << 0 << endl;

        };

        Qntconsultas --;
        consulta ++;
       };
       
        cout << endl;
        parada --;
        caso ++;
    };

    return 0;
}
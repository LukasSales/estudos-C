#include <iostream>

using namespace std;

class celula {
public:
    int valor;
    int pai;
    int tamanho;

    // construtor padrão
    celula() {
        valor = 0;
        pai = 0;
        tamanho = 1;
    }

    celula(int v) {
        valor = v;
        pai = v;
        tamanho = 1;
    }

    void attPai(int Npai){
        pai = Npai;
    }

    int obtervalor() {
        return valor;
    }

    int obterpai(){
        return pai;
    }

    int obtertamanho(){
        return tamanho;
    }

    void atttamanho(int novo_tamanho){
        tamanho = novo_tamanho;
    }
};

// Função para encontrar o representante de uma célula
int find(int x, celula Matriz[]){
    if(Matriz[x].obterpai() != x){
        Matriz[x].attPai(find(Matriz[x].obterpai(), Matriz));
    }
    return Matriz[x].obterpai();
}

// Função para unir dois conjuntos
void unite(int x, int y, celula Matriz[]){
    int rep_x = find(x, Matriz);
    int rep_y = find(y, Matriz);
    if(rep_x != rep_y){
        if(Matriz[rep_x].obtertamanho() < Matriz[rep_y].obtertamanho()){
            swap(rep_x, rep_y);
        }
        Matriz[rep_y].attPai(rep_x);
        Matriz[rep_x].atttamanho(Matriz[rep_x].obtertamanho() + Matriz[rep_y].obtertamanho());
    }
}


int main(){

    int parada;
    int caso=0;
    int Tlabirinto = 0;
    int Qntparedesexcluidas = 0;
    int Parederemovida = 0;
    int Qntconsultas = 0;
    int Primeiracel;


    cin >> parada;
    cin.ignore();

    while (parada != 0){
        scanf("%d %d %d", &Tlabirinto, &Qntparedesexcluidas, &Qntconsultas);
       
       celula Matriz[Tlabirinto*Tlabirinto];
       int valor = 0;
       int ciclo = ((2*Tlabirinto) - 1);
       int LimRestVerti = (Tlabirinto - 2);

        for (int i = 0; i < Tlabirinto*Tlabirinto; i++){
            Matriz[i] = celula(valor);
            valor ++;
            }

        while (Qntparedesexcluidas != 0){

            int Nparede;
            bool encontrado = false;

            cin >> Nparede;

            if (Nparede % ciclo <= LimRestVerti){
                int Primeiracel = 0;

                Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + (Nparede%ciclo));

                unite(Primeiracel, Primeiracel+1, Matriz);

            } /*Aqui entra se for parede vertical*/

            else {
                if (Nparede < ciclo){
                    Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + (Nparede%ciclo) - 2);
                    unite(Primeiracel, Primeiracel+Tlabirinto, Matriz);
                }

            } /*Aqui entra se for parede horizontal*/

            Qntparedesexcluidas --;
        }

        int consulta = 0;
            while (Qntconsultas != 0){
            int Priparent, Segparent;
            bool Pai_filho = false;
            
            scanf ("%d %d", &Priparent, &Segparent);


            if (Matriz[Segparent].obterpai() == Matriz[Priparent].obterpai()){
                Pai_filho = true;
            }

            if (Pai_filho == true){
                cout << caso << "." << consulta << " " << 1 << endl;
            }
            else{
                cout << caso << "." << consulta << " " << 0 << endl;

            }

            Qntconsultas --;
            consulta ++;
        }
       
        cout << endl;
        parada --;
        caso ++;
    }

    return 0;
};
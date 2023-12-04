#include <iostream>

using namespace std;

class No{
private:
    string v;
    No* prox;

public:
    No(string v){
        this->v = v;
        this->prox = NULL;
    }

    string obterValor(){
        return v;
    }

    No* obterProx(){
        return prox;
    }

    void setProx(No* p){
        prox = p;
    }

};

class Lista{
    private:
        No* cabeca;
        No* cauda;

    public:
    Lista(){
        cabeca = NULL;
        cauda = NULL;
    }

    Lista(string v){
        cabeca = new No(v);
        cauda = cabeca;
    }
    
    virtual ~Lista(){
        delete cabeca;
    }

    void mostrar (){
        No* c = cabeca;

        if (vazia()){
            cout << "A lista esta vazia";
        } else {
            while (c != NULL){
                if(c->obterProx()!=NULL){
                cout << c->obterValor() << " ";
                } else{
                cout << c->obterValor() << "\n";
                }
                c = c->obterProx();
            }
        }

    }

    void inserir_inicio (string v){
        No* novo_no = new No(v);
        novo_no->setProx(cabeca);
        cabeca = novo_no;
    }

    void inserir_final(string v){
        No* novo_no = new No(v);

        if (vazia()){
            cabeca = novo_no;
            cauda = novo_no;
        } else{
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    bool vazia(){
        return (cabeca == NULL);
    }
};

int main(){
    int N;
    cin >> N;
    bool stop = false;
    string comando, carta;

    Lista array[N];

    while (stop == false){
        getline(cin,comando);

        if (comando[0] == 'E') {
            stop = true;

        } else if (comando[0] == 'D'){
            comando.erase(0,4);

            for (int i = 0; i < N; i++){
                carta.erase();

                for (int j = 0; j < 2; j++){
                carta += comando[j];
            }
            comando.erase(0,3);
            array[i].inserir_final(carta);
            //Aqui tem que ser a função ou lista
            //aqui eu deveria chamar uma função para inserir os valores 
            }

        }else if (comando[0] == 'P'){
            comando.erase(0,4); //aqui ele vai apagar até o espaço
            int jogador = 0;
            jogador = stoi(comando);
            array[jogador].mostrar();

        }
    }

    return 0;
}
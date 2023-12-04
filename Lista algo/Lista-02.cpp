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
                cout << c->obterValor() << endl;
                }
                c = c->obterProx();
            }
        }

    }

    void mostrar_p(int contador){

        for (int i=1; i < contador; i++){
            cout << cabeca->obterValor() << " ";
            cabeca = cabeca->obterProx();
        }
        cout << cabeca->obterValor() << endl;


    }

    string pegar_valor(){
        No* c = cabeca;
        string valor;
        valor = c->obterValor();
        return valor;
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

    string removerADC(){
        string carta;
        if (cabeca->obterProx() != NULL){
            carta = cabeca->obterValor();
            cabeca = cabeca->obterProx();
        } else{
            carta = cabeca->obterValor();
            cabeca = NULL;
        }
        return carta;
    }

    void limparRodada(){

        while (cabeca != NULL){
            cabeca = cabeca->obterProx();
        }
    }

    string partida(){
        string valor1,valor2, letra1, letra2, result;
        int valor_1, valor_2;
        bool empate = false;

        while (cabeca->obterProx() != NULL){
            valor1 = cabeca->obterValor();
            letra1 = cabeca->obterValor();
            valor2 = cabeca->obterProx()->obterValor();
            letra2 = cabeca->obterProx()->obterValor();

            valor1 = valor1.erase(1);
            valor2 = valor2.erase(1); 
            letra1 = letra1.erase(0,1);
            letra2 = letra2.erase(0,1); 

            valor_1 = stoi(valor1);
            valor_2 = stoi(valor2);

            if ((valor_1 > valor_2)){
                cabeca->setProx(cabeca->obterProx()->obterProx());
                

            }else if((valor_2 > valor_1)){
                cabeca = (cabeca->obterProx());

            }else if ((valor_1 == valor_2)){

                if ((letra2 != letra1)){

                    if ((letra2 != "P")){

                        if((letra1 == "P")){
                            cabeca->setProx(cabeca->obterProx()->obterProx());
        

                        }else if ((letra1 == "O")){
                            cabeca->setProx(cabeca->obterProx()->obterProx());
        
                        } else if((letra1 == "E") && letra2 != "O"){
                            cabeca->setProx(cabeca->obterProx()->obterProx());

                        } else{
                            cabeca = (cabeca->obterProx());

                        }
                    }else{
                        cabeca = (cabeca->obterProx());
                    }
                } else {
                    if (cabeca->obterProx()->obterProx() == NULL){
                        empate = true;
                        cabeca = (cabeca->obterProx());
                    }else{
                    cabeca = (cabeca->obterProx());
                    }
                }
            }
        }
        if (empate == true){
            result = "-1";

        }else{
            result = cabeca->obterValor();
        }

        return result;
    }


    bool vazia(){
        return (cabeca == NULL);
    }
};

void veriVencedor(string cartas[], string crt, int n_roda){
        int vencedor = 0, i=0;

        if (crt == "-1"){
            cout << n_roda << " " << crt << endl;
        }
        else{
            while (cartas[i] != crt){
                vencedor ++;
                i ++;
            }
                cout << n_roda << " " << vencedor << endl;
        }
    }

int main(){
    int N, n_rodada=-1;
    cin >> N;
    bool stop = false;
    string comando, carta, carta_rodada;
    string lista_rodada_aux[N];

    Lista array[N], lista_rodada[1], cuzcuz[1];

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
            }

        }else if (comando[0] == 'P'){
            
                cuzcuz[0].mostrar_p(N);

        } else if (comando[0] == 'R'){
            n_rodada ++;

            for (int i=0; i<N; i++){
                carta_rodada.erase();
                
                carta_rodada = array[i].removerADC();
                lista_rodada[0].inserir_final(carta_rodada);
                cuzcuz[0].inserir_inicio(carta_rodada);
                lista_rodada_aux[i] = carta_rodada;

            } 
            carta = lista_rodada[0].partida();
            veriVencedor(lista_rodada_aux, carta, n_rodada);
            lista_rodada[0].limparRodada();
        }
    }
    return 0;
}
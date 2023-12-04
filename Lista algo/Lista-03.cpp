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

        if (vazia()){
            carta="0";

        }else{

        if (cabeca->obterProx() != NULL){
            carta = cabeca->obterValor();
            cabeca = cabeca->obterProx();
        } else{
            carta = cabeca->obterValor();
            cabeca = NULL;
        }
        }
        return carta;
    }

    void limparRodada(){

        while (cabeca != NULL){
            cabeca = cabeca->obterProx();
        }
    }

    int qtdCartas(){
       if (vazia()){
        return 0;
       }else {
        No* c = cabeca;
        int tam = 0;
        do {
            c = c->obterProx();
            tam++;
        }while (c);
        return tam;
       }
    }

    string partida(){
        string valor1,valor2, letra1, letra2, result;
        int valor_1, valor_2;

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
        

                        }else if ((letra1 == "O") || ((letra1 == "E") && letra2 != "O")){
                            cabeca->setProx(cabeca->obterProx()->obterProx());
        
                        } else{
                            cabeca = (cabeca->obterProx());

                        }
                    }else{
                        cabeca = (cabeca->obterProx());
                    }
                } else {
                    cabeca = (cabeca->obterProx());
                    }
            }
        }
        result = cabeca->obterValor();

        return result;
    }
int verifLista(){
        int verificadorLista;
        if (vazia()){
            verificadorLista = 0;
        } else {
            verificadorLista = 1;
        }
        return verificadorLista;
    }

    bool vazia(){
        return (cabeca == NULL);
    }
};

int veriVencedor(string cartas[], string crt, int n_roda, int n_jogadores){
        int vencedor = 0, i=0, verif_empa=0;

        for (int i=0; i< n_jogadores; i++){
            if (cartas[i] == crt){
                verif_empa ++;
            }
        }
        if (verif_empa == 1){

        while (cartas[i] != crt){
            vencedor ++;
            i ++;
        }
    } else {
        vencedor = -1;
    }
        return vencedor;
        }

    int verificVencedor(int listVencedor[], int parada){
        bool troca = false;
        int temp, resul;

        while ((parada > 0 ) && (troca == false)){
            troca = true;

            for (int i = 0; i < parada; i++){

                if (listVencedor[i] < listVencedor[i+1]){
                    troca = false;
                    temp = listVencedor[i];
                    listVencedor[i] = listVencedor[i+1];
                    listVencedor[i+1] = temp;
                }
            }
        }
    resul = listVencedor[0];
    return resul;
    }

int main(){
   int N, n_rodada=-1, qtdCarts=0, qtdJogadoresZerados, result, vencedorParti;
    int verifVencedor = 0;
    cin >> N;
    bool stop = false;
    string comando, carta, carta_rodada;
    string lista_rodada_aux[N];
    int lista_vencedor[N];

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

        } else if (comando[0] == 'R'){
            n_rodada ++;
            qtdJogadoresZerados =0;
            result = 0;
            bool pararPartida = false;

            while (pararPartida == false){


                for (int i=0; i<N; i++){
                    carta_rodada.erase();
                    
                    cout << "\nsituacao jogador " << i << ": "; 
                    array[i].mostrar();

                    carta_rodada = array[i].removerADC();
                    if (carta_rodada != "0"){

                    lista_rodada[0].inserir_final(carta_rodada);
                    cuzcuz[0].inserir_inicio(carta_rodada);
                    lista_rodada_aux[i] = carta_rodada;

                    cout << "\nsituacao das cartas do round " << n_rodada << ": " << lista_rodada_aux[i];
                    } else{
                        lista_rodada_aux[i] = carta_rodada;
                        qtdJogadoresZerados ++;
                    }

                } 
                carta = lista_rodada[0].partida();
                result = veriVencedor(lista_rodada_aux, carta, n_rodada, N);
                lista_rodada[0].limparRodada();

                if ((qtdJogadoresZerados >= (N-1)) || (result != -1)){
                    pararPartida = true;
                } else {
                    pararPartida = false;
                }
            }
            if (qtdJogadoresZerados == N){
                cout << "-1 -1 -1" << endl;
            }else{

                qtdCarts = cuzcuz[0].qtdCartas();
                cout << "\nquantidade de cartas cuzcuz: " << qtdCarts <<"Situacao cuzcuz: ";

                for (int i = 0; i < qtdCarts; i++){
                    cuzcuz[0].mostrar();

                    carta_rodada = cuzcuz[0].removerADC();
                    array[result].inserir_final(carta_rodada);
                }
                cout << n_rodada << " " << result << " " << qtdCarts << endl;
            }
        }
    }
    for (int i = 0; i < N; i++){
    lista_vencedor[i] = array[i].qtdCartas();

    if (lista_vencedor[i] != 0){
        verifVencedor ++;
    }
}

vencedorParti = verificVencedor(lista_vencedor,N);

if (verifVencedor > 0){
    for (int i=0; i < N; i++){
        if (lista_vencedor[i] == vencedorParti){
            result = i;
        }
    }
    cout << result << endl;
} else {
    cout << "-1";
}
    return 0;
}
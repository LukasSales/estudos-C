#include <iostream>

using namespace std;

class Cliente {
public:
    int timestamp;
    string key_cliente;
    int n_posicao;

    Cliente(int T, string Key, int posicao) {
        timestamp = T;
        key_cliente = Key;
        n_posicao = posicao;
    }

    string obterkey(){

        return key_cliente;
    }

    int obtern_posicao(){

        return n_posicao;
    }
};

class Node {
public:
    Cliente cliente;
    Node* next;

    Node(Cliente c) : cliente(c) {
    next = NULL;
    }
};

class HashTable {
private:
    int max_cliente;
    int max_posicoes;
    int quant_cliente;
    int Lmax;
    Node** tabela;

public:
    HashTable(int tam_vetor, int max) {
        quant_cliente = 0;
        Lmax = max;
        max_posicoes = tam_vetor;
        tabela = new Node*[tam_vetor];

        for (int i = 0; i < tam_vetor; i++) {
            tabela[i] = NULL;
        }
    }

    ~HashTable() {
        for (int i = 0; i < max_posicoes; i++) {
            Node* nodeAtual = tabela[i];
            while (nodeAtual != NULL) {
                Node* proximo = nodeAtual->next;
                delete nodeAtual;
                nodeAtual = proximo;
            }
        }
        delete[] tabela;
    }

    int hashFunction(int timestamp) {
        int hash = 0;
        hash = (timestamp % max_posicoes); 

        return hash;
    }

    void relacaoinser(int hash, int quant_elem_hash){
        cout << hash << " " << quant_elem_hash << endl;
    }

    void inserir(int timestamp, string key_cliente, int n_posicao) {
        int quant_elem_hash = 1;
        float fator_carga = ((float) quant_cliente / (float) max_posicoes);
        if (fator_carga > Lmax){
            rehashing();
        }

        int hash = hashFunction(timestamp);
        Cliente cliente(timestamp, key_cliente, n_posicao);
        Node* novoNode = new Node(cliente);
        quant_cliente ++;

        if (tabela[hash] == NULL) {
            tabela[hash] = novoNode;
            relacaoinser(hash, quant_elem_hash);

        } else {
            Node* nodeAtual = tabela[hash];
            quant_elem_hash ++;
            while (nodeAtual->next != NULL) {
                quant_elem_hash ++;
                nodeAtual = nodeAtual->next;
            }
            nodeAtual->next = novoNode;
            relacaoinser(hash, quant_elem_hash);
            }}

    void rehashing() {
        cout << "==============================rehashing realizado=============================" << endl;
        int novo_tam = ((2 * max_posicoes) + 1);
        Node** nova_tabela = new Node*[novo_tam];

        for (int i = 0; i < novo_tam; i++) {
            nova_tabela[i] = NULL;
        }

        for (int i = 0; i < max_posicoes; i++) {
            Node* nodeAtual = tabela[i];

            while (nodeAtual != NULL) {
                Node* proximo = nodeAtual->next;

                int novo_hash =((nodeAtual->cliente.timestamp) % novo_tam);

                Node* novoNode = new Node(nodeAtual->cliente);
                novoNode->next = NULL;

                if (nova_tabela[novo_hash] == NULL) {
                    nova_tabela[novo_hash] = novoNode;
                } else {
                    Node* nodeAux = nova_tabela[novo_hash];
                    while (nodeAux->next != NULL) {
                        nodeAux = nodeAux->next;
                    }
                    nodeAux->next = novoNode;
                }

                nodeAtual = proximo;
            }
        }

        max_posicoes = novo_tam;
        delete[] tabela;
        tabela = nova_tabela;
}

    
    void buscar(int timestamp) {
        int posic_hash = 0;
        int hash = hashFunction(timestamp);
        bool busca = false;
        Node* nodeAtual = tabela[hash];
        while (nodeAtual != NULL) {
            if (nodeAtual->cliente.timestamp == timestamp) {
                cout << nodeAtual->cliente.obterkey() << " " << posic_hash << endl;
                busca = true;
            }
            posic_hash ++;
            nodeAtual = nodeAtual->next;
        }
        if (busca == false){
            cout << "-1 -1" << endl;
        }
    }

};

int main(){
    int tam_vetor, i=0, j = 1;
    int max;
    int key_client, timestamp;
    string cliente_int;
    int n_posicao = 0;

    string comando, cliente;
    bool stop = false;

    getline(cin,comando);

    while (comando[i] != ' '){
        cliente += comando[i];
        j += 1;
        i += 1;
        }

    tam_vetor = stoi(cliente);
    max = stoi(comando.erase(0,j));
    HashTable tabela(tam_vetor, max);

    while (stop == false){
        getline(cin,comando);

        if (comando[0] == 'E') {
            stop = true;

        } else if (comando[0] == 'N'){
            i = 0;
            j = 1;
            comando.erase(0,4);
            cliente.erase();

            while (comando[i] != ' '){
            cliente += comando[i];
            j += 1;
            i += 1;
            }

            timestamp = stoi(cliente);
            cliente_int = comando.erase(0,j);
            tabela.inserir(timestamp, cliente_int, n_posicao);
            n_posicao += 1;
            }

        else if (comando[0] == 'Q'){
            cliente = comando.erase(0,4);
            timestamp = stoi(cliente);
            tabela.buscar(timestamp);
        }
        }

    return 0;
}
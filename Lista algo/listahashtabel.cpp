#include <iostream>

using namespace std;

class Cliente {
public:
    int timestamp;
    string key_cliente;
    int index;

    Cliente(int T, string Key, int posic) {
        timestamp = T;
        key_cliente = Key;
        index = posic;
    }

    int obterindex(){
        return index;
    }

    string obterkey(){

        return key_cliente;
    }

    void attindex(int n){
        if (n != 0){
            index = n;
        }
    }

};

class Node {
public:
    Cliente cliente;
    Node* next;
    int tamanhoslot;

    Node(Cliente c) : cliente(c) {
    next = NULL;
    tamanhoslot = 0;
    }

    int obtertamanhoslot(){

        return tamanhoslot;
    }

    void atttamanhoslot(int n){
        tamanhoslot = n;
    }
};

class HashTable {
private:
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

    void relacaoinser(int hash){
        int quant_elem_hash = 0;
        Node* nodeAtual = tabela[hash];

        while (nodeAtual != NULL){
            quant_elem_hash++;
            nodeAtual = nodeAtual->next;
        }
        cout << hash << " " << quant_elem_hash << endl;
    }

    void attposicao(){

        for (int i = 0; i < max_posicoes; i++) {
            Node* nodeAtual = tabela[i];
            int posicao = 0;

        while (nodeAtual != NULL) {
            nodeAtual->cliente.attindex(posicao);
            Node* proximo = nodeAtual->next;
            posicao++;
            }
            nodeAtual->atttamanhoslot(posicao);
        }

    }

    void inserir(int timestamp, string key_cliente) {
        float fator_carga = ((float) quant_cliente / (float) max_posicoes);
        if (fator_carga > Lmax){
            rehashing();
            attposicao();
        }

        int posic_hash = 0;
        int hash = hashFunction(timestamp);
        Cliente cliente(timestamp, key_cliente, 0);
        Node* novoNode = new Node(cliente);
        quant_cliente ++;

        if (tabela[hash] == NULL) {
            tabela[hash] = novoNode;

        } else {
            posic_hash ++;
            Node* nodeAtual = tabela[hash];
            while (nodeAtual->next != NULL) {
                nodeAtual = nodeAtual->next;
                posic_hash ++;
            }
            nodeAtual->next = novoNode;
            nodeAtual->next->cliente.attindex(posic_hash);
            nodeAtual->atttamanhoslot(posic_hash);
            }

        relacaoinser(hash);
    }

    void rehashing() {
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
        Node* nodeAnterior = NULL;
        Node* nodeAtual2 = nova_tabela[novo_hash];
        while (nodeAtual2 != NULL && nodeAtual2->cliente.timestamp <= novoNode->cliente.timestamp) {
            nodeAnterior = nodeAtual2;
            nodeAtual2 = nodeAtual2->next;
        }
        if (nodeAnterior == NULL) {
            novoNode->next = nova_tabela[novo_hash];
            nova_tabela[novo_hash] = novoNode;
        } else {
            novoNode->next = nodeAnterior->next;
            nodeAnterior->next = novoNode;
        }
    }

    nodeAtual = proximo;
}
}

        max_posicoes = novo_tam;
        delete[] tabela;
        tabela = nova_tabela;
}
    
    void buscar(int timestamp) {
        int hash = hashFunction(timestamp);
        bool busca = false;
        Node* nodeAtual = tabela[hash];
        int tamanho_lista = tabela[hash]->obtertamanhoslot();

        nodeAtual = tabela[hash];
        int inicio = 0;
        int fim = tamanho_lista - 1;
        int meio;

        while (inicio <= fim) {
            meio = (inicio + fim) / 2;
            Node* nodeMeio = nodeAtual;

            for (int i = 0; i < meio; i++) {
                nodeMeio = nodeMeio->next;
            }

            if (nodeMeio->cliente.timestamp == timestamp) {
                cout << nodeMeio->cliente.obterkey() << " " << nodeAtual->cliente.obterindex() << endl;
                busca = true;
                break;
            } else if (nodeMeio->cliente.timestamp < timestamp) {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
        }

        if (busca == false) {
            cout << "-1 -1" << endl;
        }
    }

};

int main(){
    int tam_vetor, i=0, j = 1;
    int max;
    int key_client, timestamp;
    string cliente_int;

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
            tabela.inserir(timestamp, cliente_int);
            }

        else if (comando[0] == 'Q'){
            cliente = comando.erase(0,4);
            timestamp = stoi(cliente);
            tabela.buscar(timestamp);
        }
        }

    return 0;
}
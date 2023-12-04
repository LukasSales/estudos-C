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

    void relacaoinser(int hash){
        int quant_elem_hash = 0;
        Node* nodeAtual = tabela[hash];

        while (nodeAtual != NULL){
            quant_elem_hash++;
            nodeAtual = nodeAtual->next;
        }
        cout << hash << " " << quant_elem_hash << endl;
    }

    void inserir(int timestamp, string key_cliente, int n_posicao) {
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

    } else {
        Node* nodeAtual = tabela[hash];
        Node* nodeAnterior = NULL;
        while (nodeAtual != NULL && nodeAtual->cliente.timestamp < timestamp) {
            nodeAnterior = nodeAtual;
            nodeAtual = nodeAtual->next;
        }
        if (nodeAnterior == NULL) {
            novoNode->next = tabela[hash];
            tabela[hash] = novoNode;
        } else {
            nodeAnterior->next = novoNode;
            novoNode->next = nodeAtual;
        }
    }
    relacaoinser(hash);
    imprimirClientes();
}

    void rehashing() {
        cout << "começo do rehashing" << endl;
        imprimirClientes();
        int novo_tam = ((2 * max_posicoes) + 1);
        Node** nova_tabela = new Node*[novo_tam];

        for (int i = 0; i < novo_tam; i++) {
            nova_tabela[i] = NULL;
        }

        // Criar um vetor temporário de nós para armazenar os nós da tabela antiga
        Node** temp = new Node*[quant_cliente];
        int pos = 0;
        for (int i = 0; i < max_posicoes; i++) {
            Node* nodeAtual = tabela[i];
            while (nodeAtual != NULL) {
                temp[pos++] = nodeAtual;
                nodeAtual = nodeAtual->next;
            }
        }

        // Ordenar o vetor temporário em ordem crescente de timestamp
        for (int i = 0; i < quant_cliente; i++) {
            for (int j = i + 1; j < quant_cliente; j++) {
                if (temp[j]->cliente.timestamp < temp[i]->cliente.timestamp) {
                    Node* aux = temp[i];
                    temp[i] = temp[j];
                    temp[j] = aux;
                }
            }
        }

        // Inserir os nós ordenados na nova tabela
        for (int i = 0; i < quant_cliente; i++) {
            Node* nodeAtual = temp[i];
            int novo_hash = hashFunction(nodeAtual->cliente.timestamp);

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
        }

        // Atualizar a tabela com a nova tabela e o novo tamanho
        max_posicoes = novo_tam;
        delete[] tabela;
        tabela = nova_tabela;
        delete[] temp;
        cout << "Fim do heashing" << endl;
        imprimirClientes();
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

    void imprimirClientes() {
        for (int i = 0; i < max_posicoes; i++) {
            int posic_hash = 0;
            Node* nodeAtual = tabela[i];
            while (nodeAtual != NULL) {
                cout << "-------------------inicio---------------------------------- " << i << endl;
                cout << "numero de elementos: " << quant_cliente << endl;
                cout << "número da tabela: " << max_posicoes << endl;
                cout << "Timestamp: " << nodeAtual->cliente.timestamp << endl;
                cout << "Key do cliente: " << nodeAtual->cliente.key_cliente << endl;
                cout << "Posição na lista: " << nodeAtual->cliente.n_posicao << endl << endl;
                cout << "Posição hash: " << posic_hash << endl;
                cout << "Hash: " << (nodeAtual->cliente.timestamp % max_posicoes) << endl;
                cout << "--------------------fim---------------------------------" << endl;
                posic_hash++;
                nodeAtual = nodeAtual->next;
            }
    }
}
};

int main(){
    int tam_vetor, i=0, j = 1;
    int max;
    int key_client, timestamp;
    string cliente_int;
    int n_posicao = 0;

    /*cin >> tam_vetor;
    cin >> max;*/
    /*cout << "o fator de carga é:" << (float)max / (float)tam_vetor;*/

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
            //tabela.imprimirClientes();
            }
            //Aqui tem que ser a função ou lista
            //aqui eu deveria chamar uma função para inserir os valores 

        else if (comando[0] == 'Q'){
            cliente = comando.erase(0,4);
            timestamp = stoi(cliente);
            tabela.buscar(timestamp);
        }
        }

    return 0;
}
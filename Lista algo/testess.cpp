#include <bits/stdc++.h>
using namespace std;

int itens; // itens
int Minimo_itens; // mínimo de itens
int Limite_gasto;  // limite de gasto
int resultado;

int weight[30];
int profit[30];


class Bag{
    public:
        vector < vector < int > > matrixBag; //Matriz da DP
        vector < int > size, value; //Listas com os valores recebidos

        Bag (int S, int N){
            vector < vector < int > > mAux(N+1, vector < int >(S+1, -1)); // Criar uma matriz N+1xS+1 pondo em todos valores -1 paa poderem ser alterados depois n fn
            vector < int > lAux(N+1, 0); // Mesma coisa, so que dessa vez a lista para adicionar as paradas
            this->matrixBag = mAux;
            this->size = lAux;
            this->value = lAux;
            setBag(S, N);
        }

        // Pondo todos os
        void setBag(int S, int N){
            for(int i = 0; i < N+1; ++i){
                for(int j = 0; j < S+1; ++j){
                    if (i == 0 || j == 0) this->matrixBag[i][j] = 0;
                }
            }
        }

        int findMaxValue(int i, int j){
            if (this->matrixBag[i][j] < 0){ // Se o valor estiver zerado

                int val;
                

                if (j < size[i]) {
                    val = findMaxValue(i-1, j);
                }else {
                    val = max(findMaxValue(i-1, j), value[i] + findMaxValue(i-1, j-size[i]));
                }

                this->matrixBag[i][j] = val;
            }
            return this->matrixBag[i][j];
        } 
};


int main()
{

    int contador;
    cin >> contador;
    for (int i = 0; i < contador; i++) 
    {
        cin >> itens; // leia o número de itens disponíveis

        Bag bag = Bag(itens-1,itens-1);
        for (int i = 0; i < itens; i++) cin >> profit[i]; // leia os preços dos itens


        for(int i = 0; i < itens; ++i){
            bag.size[i+1] = 1;
            bag.value[i+1] = profit[i];
        }

        resultado = bag.findMaxValue(itens-1, itens-1); // Valores do elemento da pota da matriz ou seja o maior de todos
        cout << "caso " << i << ": " << resultado << endl; // imprime o resultado para o caso atual
    }

	return 0;
}
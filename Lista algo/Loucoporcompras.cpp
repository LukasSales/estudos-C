#include <bits/stdc++.h>
using namespace std;

int itens; // itens
int Minimo_itens; // mínimo de itens
int Limite_gasto;  // limite de gasto
int resultado;

int weight[30];
int profit[30];


int max(int a, int b) { return (a > b) ? a : b; }

// Limite_gasto é a capacidade da mochila
int knapSack(int Limite_gasto, int wt[], int val[], int n)
{

	// caso base
	if (n == 0 || Limite_gasto == 0)
		return 0;

    // se o peso for maior que a capcidade da mochila, então ele não é adicionado
	if (wt[n - 1] > Limite_gasto)
		return knapSack(Limite_gasto, wt, val, n - 1);

	// retorna o maximo de dois casos.
	else
		return max(
			val[n - 1]
				+ knapSack(Limite_gasto - wt[n - 1], wt, val, n - 1),
			knapSack(Limite_gasto, wt, val, n - 1));
}


int main()
{
    int contador;
    cin >> contador;
    for (int i = 0; i < contador; i++) 
    {
        cin >> itens; // leia o número de itens disponíveis
        for (int i = 0; i < itens; i++) cin >> profit[i], weight[i] = 1; // leia os preços dos itens
        cin >> Minimo_itens >> Limite_gasto; // leia a quantidade mínima de itens que devem ser escolhidos e o valor máximo que pode ser gasto
        resultado = 0; // zere o contador
        resultado = knapSack(Limite_gasto, weight, profit, Minimo_itens+1);
        cout << "caso " << i << ": " << resultado << endl; // imprime o resultado para o caso atual
    }

	return 0;
}
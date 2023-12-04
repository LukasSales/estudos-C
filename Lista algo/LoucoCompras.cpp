#include<iostream>

using namespace std;


int P[29]; 
int resultado;

void backtrack(int contador_aux, int soma, int items, int teto_gasto, int itens, int minimo_itens)
{
    if (soma > teto_gasto) 
    return;
    
    if (contador_aux == itens)
    { 
        if (items >= minimo_itens) resultado++;
        return;
    }
    backtrack(contador_aux + 1, soma + P[contador_aux], items + 1, teto_gasto, itens, minimo_itens);
    backtrack(contador_aux + 1, soma, items, teto_gasto, itens, minimo_itens);
}

int main() {

    int itens; 
    int minimo_itens;
    int teto_gasto; 
    int contador;

    cin >> contador;
    for (int contador_aux = 0; contador_aux < contador; contador_aux++) 
    {
        cin >> itens;

        for (int contador = 0; contador < itens; contador++) cin >> P[contador];
        resultado = 0;

        scanf("%d %d", &minimo_itens, &teto_gasto);
        backtrack(0, 0, 0, teto_gasto, itens, minimo_itens);
        cout << "caso " << contador_aux << ": " << resultado << endl;
        
    }
}
#include <iostream>

using namespace std;
 

const int MAXN = 1000; // definindo o tamanho máximo da matriz

int pai[MAXN*MAXN]; // array para armazenar os pais de cada elemento

int find(int x) { // função find do Union-Find
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void unite(int a, int b) { // função unite do Union-Find
    a = find(a);
    b = find(b);
    pai[a] = b;
}

void makeSet(int n)
    {
        for (int i = 0; i < n; i++) {
            pai[i] = i;
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

        makeSet(Tlabirinto*Tlabirinto);
       
        int ciclo = ((2*Tlabirinto) - 1);
        int LimRestVerti = (Tlabirinto - 2);

        while (Qntparedesexcluidas != 0){

            
            int Nparede;
            int Primeiracel = 0;

            cin >> Nparede;

            if (Nparede % ciclo <= LimRestVerti){

                Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + (Nparede%ciclo));

                unite(Primeiracel, Primeiracel+1); 
            } /*Aqui entra se for parede vertical*/

            else {
                Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + ((Nparede-Tlabirinto+1)%ciclo));
                unite(Primeiracel, Primeiracel + Tlabirinto);

            } /*Aqui entra se for parede horizontal*/

            Qntparedesexcluidas --;
        }

            int consulta = 0;
            while (Qntconsultas != 0){
                int Priparent, Segparent;
                
                scanf ("%d %d", &Priparent, &Segparent);


                if (find(Priparent) == find(Segparent)) /*Aqui é pra verificar se os dois tem o mesmo pai*/{
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
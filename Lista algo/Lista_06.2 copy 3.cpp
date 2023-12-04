#include <bits/stdc++.h>
using namespace std;
 
class DisjSet {
    int *rank, *parent, n;
 
public:
   

    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    int find(int x)
    {

        if (parent[x] != x) {
 

            parent[x] = find(parent[x]);
 
        }
 
        return parent[x];
    }
 
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset)
            return;

        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }

        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

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

        DisjSet obj(Tlabirinto*Tlabirinto);
       
        int ciclo = ((2*Tlabirinto) - 1);
        int LimRestVerti = (Tlabirinto - 2);

        while (Qntparedesexcluidas != 0){

            
            int Nparede;
            bool encontrado = false;
            int Primeiracel = 0;

            cin >> Nparede;

            if (Nparede % ciclo <= LimRestVerti){

                Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + (Nparede%ciclo));

                obj.Union(Primeiracel, Primeiracel+1); 
            } /*Aqui entra se for parede vertical*/

            else {
                Primeiracel = ((Tlabirinto*int(Nparede/ciclo)) + ((Nparede-Tlabirinto+1)%ciclo));
                obj.Union(Primeiracel, Primeiracel + Tlabirinto);

            } /*Aqui entra se for parede horizontal*/

            Qntparedesexcluidas --;
        }

            int consulta = 0;
            while (Qntconsultas != 0){
                int Priparent, Segparent;
                
                scanf ("%d %d", &Priparent, &Segparent);


                if (obj.find(Priparent) == obj.find(Segparent)) /*Aqui é pra verificar se os dois tem o mesmo pai*/{
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
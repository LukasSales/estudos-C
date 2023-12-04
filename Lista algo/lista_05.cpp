#include <iostream>

using namespace std;

class Celula{
    public:
    int valor; 
    bool north_cima = false;
    bool south_baixo = false;
    bool east_direita = false;
    bool west_esquerda = false;
    bool teleporte = false;

    void atualizar_cordenada(int n){
        if (n == 0){
            north_cima = true;
        }
        else if (n == 1){
            south_baixo = true;
        }
        else if (n == 2){
            east_direita = true;
        }
        else if (n == 3){
            west_esquerda = true;

        }
    }
};

int main(){
    int contador, N, M;
    char comando[4];
    cin >> contador;

    for (int i; i < contador; i++){
        cin >> M >> N;
        Celula labirinto[M][N];

        for (int j; j < (M); j++){
            cin >> comando;
            for (int l; l < (M); l++){

            int contador_aux = 0;
            while (comando[contador_aux]!= '\0'){
                
                if (comando[contador_aux] == 'N'){/*norte*/
                    labirinto[j][l].atualizar_cordenada(0);
                }
                else if (comando[contador_aux] == 'S'){/*sul*/
                    labirinto[j][l].atualizar_cordenada(1);

                }
                else if (comando[contador_aux] == 'E'){/*leste*/
                    labirinto[j][l].atualizar_cordenada(2);

                }
                else if (comando[contador_aux] == 'W') /*oeste*/{
                    labirinto[j][l].atualizar_cordenada(3);

                }
                contador_aux++;
            }
            }
        }
    }


    return 0;
    };
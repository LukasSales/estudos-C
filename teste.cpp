#include <iostream>

using namespace std;

int main(){

    int matriz[3][4];
    int l,c,N;

    for (l=0;l<3;l++){
        for (c=0;c<4;c++){
            cin >> matriz[l][c];
        }
    }


    for (l=0;l<3;l++){
        for (c=0;c<4;c++){
            cout << matriz[l][c] << ' ';
        }
        cout << '\n';
    }

    cin >> N;

    return 0;
}
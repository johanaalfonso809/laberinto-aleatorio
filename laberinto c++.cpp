#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int F,C;
    int numero; //tamaño de la matriz
    cout<<"ingrese tamaño de matriz desde 9: ";
    cin>>numero;
    F= numero;
    C=numero;

    char matriz[F][C]; //DECLARAR que tipo de MATRIZ 
    //llenar mi matriz con '.'
    for (int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            matriz[i][j]='#';
        }
    }
    //generar posible camino
    for (int i=1; i<F; i++){
        matriz[i][0]='.';
    }
    for (int j=1; j<C; j++){
        matriz[F-1][j]='.';
    } 

    //crear entrada y salidad
    matriz[0][0]='E';
    matriz[F-1][C-1]='S';
    
    //imprimir matriz i
    for(int i=0; i<F; i++){
        for (int j=0; j<C; j++){
            cout <<matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
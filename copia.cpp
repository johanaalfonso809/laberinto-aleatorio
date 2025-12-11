#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    int n;
    cout<< "ingresa numero";
    cin>>n;

    vector<vector<char>> matriz(n, vector<char>(n, '#')); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j]='#';
        }
    }
    //imprimir 
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matriz[i][j];
        }
    cout<< endl;
    }

    return 0;
}


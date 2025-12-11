#include <iostream>
#include <vector>
#include <algorithm>//(random_device, mt19937).
#include <random> //time(0)
#include <ctime>
using namespace std;

// Constantes
const char PARED = '#';
const char CAMINO = '.';
const char ENTRADA = 'E';
const char SALIDAD = 'S';
const char SOLUCION= ' ';

// Movimientos
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Generador aleatorio global
random_device rd;
mt19937 rng(rd());

void dfs_generador(int x, int y, vector<vector<char>> &matriz, int n) {
    //marcar la celda actual como camino
    matriz[x][y] = CAMINO;

    // Definir y mezclar el orden de las direcciones
    vector<int> dir = {0, 1, 2, 3};
    shuffle(dir.begin(), dir.end(), rng);
    
    // Explorar vecinos en orden aleatorio
    for (int i = 0; i < 4; i++) {
        int d = dir[i]; 

        // El 'paso' de la DFS debe ser de dos celdas
        int nx = x + dx[d] * 2; 
        int ny = y + dy[d] * 2;
        
        // Verificar límites
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            
            // Verificar si el destino sigue siendo un Muro (no visitado)
            if (matriz[nx][ny] == PARED) {
                
                // Cavar el muro intermedio.
                // Esta es la celda que está entre (x,y) y (nx,ny)
                matriz[x + dx[d]][y + dy[d]] = CAMINO;

                // Llamada recursiva al nuevo punto de inicio
                dfs_generador(nx, ny, matriz, n);
            }
        }
    }
}
//Funcion bactraking 
bool buscarCamino(int x, int y, vector<vector<char>>& matriz, int n){
    if(x<0 || x>=n || y<0 || y>=n){  
        return false;}
    //caso base
    if (matriz[x][y]== SALIDAD){
        return true;
    }
    //para solo moverse por camino
    if(matriz[x][y]== PARED || matriz[x][y]== SOLUCION){
        return false; }

    // Si la celda es la Entrada, la marcamos como solución para poder pasar.
    // Si la celda es un Camino '.', la marcamos como solución temporal.
    if (matriz[x][y] != ENTRADA) {
        matriz[x][y] = SOLUCION;}
    //explorar los 4 vecino
    for(int i=0; i<4; i++){
        int nx= x + dx[i];
        int ny= y + dy[i];

        if (buscarCamino(nx, ny, matriz, n)) {
            return true; //True por que se encontro camino
        }
    }
    if (matriz[x][y] != ENTRADA){
        matriz[x][y]= CAMINO; //Desmarcar por que no lleva a salidad
    } 
    return false;
        


}

int main() {
    
    srand(time(0)); 

    int n;
    cout << "Ingrese tamano de matriz impar desde : ";
    cin >> n;

    // verificar numero ingresado
    if (n % 2 == 0 ) {
        cout << "Debe ser impar " << endl;
        n = 9;
    }

    // Inicializar matriz completamente con PARED
    vector<vector<char>> matriz(n, vector<char>(n, PARED));

    // Iniciar la generación por DFS desde la esquina (0,0)
    dfs_generador(0, 0, matriz, n);

    // Definir Entrada (E) y Salida (S)
    matriz[0][0] = ENTRADA; 
    matriz[n - 1][n - 1] = SALIDAD; 
    
    // Aseguramos que los bordes de la entrada y salida sean caminos.
    // matriz[0][1] = CAMINO; 
    matriz[n-1][n-1] = SALIDAD;
    matriz[n-2][n-2] = PARED; // Por si acaso

    buscarCamino(0, 0, matriz, n);

    // Imprimir laberinto
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }



    return 0;
}
#include<string>
#include<iostream>

using namespace std;

const int matrix_fil = 1000;
const int matrix_col = 1000;

string tablero[matrix_fil][matrix_col];

int enteros[matrix_fil][matrix_col];

int algoritmo(int i,int j){
    int filas = 0;
    int col = 0;
    if (enteros[i][j] != -10000)
        return enteros[i][j];
    enteros[i][j] = {0};
    string entrada = tablero[i][j];
    for (int l = 1; l <=entrada.size()+1 ; l++) {
        if (entrada[l] >='0' and entrada[l]<='9'){
            filas = filas*10+entrada[l]-'0';
        } else if(entrada[l]>= 'A' && entrada[l] <='Z'){
            col =col*26+entrada[l]-'A'+1;
        }else if (entrada[l] == '+' || l == entrada.size()){
            enteros[i][j] += algoritmo(filas,col);
            filas = col = 0;
        }
    }
    return enteros[i][j];
}

void imprimir(int **matriz , int filas , int col){
    int i,j;
    for ( i = 1; i <= filas; ++i) {
        for (j = 1; j < col; ++j) {
            cout<<enteros[i][j]<<" ";
        }
        cout<<enteros[i][j]<<endl;
    }
};

int main(){
    int col,filas,spread;
    cin>>spread;
    for (int k= 0; k < spread; k++) {
        cin>>col>>filas;
        for (int i =1; i <=filas; i++) {
            for (int j = 1; j <= col; j++) {
                string dato;
                cin>>dato;
                if (dato.at(0) == '='){
                    tablero[i][j] = dato;
                    enteros[i][j] = -10000;
                } else{
                    enteros[i][j] = atoi(dato.c_str());//Convert to integer
                }
            }
        }
        for (int i = 1; i <= filas; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (enteros[i][j] == -10000)
                    algoritmo(i,j);
            }
        }
        imprimir(reinterpret_cast<int **>(**enteros), filas, col);
    }
    return 0;
}

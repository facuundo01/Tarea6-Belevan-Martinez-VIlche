#include <iostream>
#include <fstream>

using namespace std;

void ingresarSistemas(vector<vector<double>> &matriz, vector<double> &terminos, int n){
  cout << "ingrese los coeficientes de la matriz (" << n << "x" << n << "):\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << "a[" << i+1 << "][" << j+1 << "]= ";
      cin >> matriz[i][j];
    }
    cout << "Termino independiente b[" << i+1 << "]= " << endl;
    cin >> terminos[i];
    }
}
void mostrarMatriz(const<vector<double>> &matriz, const vector<double> &terminos){
  int n = matriz.size();
  cout << "\nSistema representativo:\n";
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      cout << matriz[i][j] << " ";
    }
    cout << "| " << terminos [i] << endl;
}
}

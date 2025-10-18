#include "entrada_salida.h"
#include <iostream>
#include <fstream>
using namespace std;

void ingresarSistema(vector<vector<double>> &matriz, vector<double> &terminos, int n) {
    cout << "Ingrese los coeficientes de la matriz (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i+1 << "][" << j+1 << "] = ";
            cin >> matriz[i][j];
        }
        cout << "Termino independiente b[" << i+1 << "] = ";
        cin >> terminos[i];
    }
}

void guardarResultados(const vector<double> &soluciones, const string &archivo) {
    ofstream salida(archivo);
    if (!salida) {
        cerr << "Error al abrir el archivo para guardar resultados.\n";
        return;
    }
    salida << "Soluciones del sistema:\n";
    for (int i = 0; i < soluciones.size(); i++) {
        salida << "x" << i+1 << " = " << soluciones[i] << endl;
    }
    salida.close();
    cout << "Resultados guardados en " << archivo << endl;
}


#include "entrada_salida.h"
#include <iostream>
#include <fstream>
using namespace std;

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



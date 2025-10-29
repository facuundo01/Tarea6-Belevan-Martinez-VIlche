#include "InDatos.h"
#include <iostream>
#include <fstream>
using namespace std;

void guardarResultados(const vector<double> &soluciones, const string &archivo) {
   static int NumProblema = 1;
    ofstream salida(archivo, ios::app);
    if (!salida) {
        cerr << "Error al abrir el archivo para guardar resultados.\n";
        return;
    }
    if (soluciones.empty()) {
        salida << "No se encontraron soluciones (Posiblemente infinitas o sin solucion).\n";
        salida << "-------------------------\n";
    } else {
        salida << "\nSoluciones del sistema " << NumProblema << ":\n";
        for (int i = 0; i < soluciones.size(); i++) {
            salida << "x" << i + 1 << " = " << soluciones[i] << endl;
        }
        salida << "-------------------------\n";
    }
    salida.close();
    cout << "Resultados guardados en " << archivo << endl;
	NumProblema++;
}




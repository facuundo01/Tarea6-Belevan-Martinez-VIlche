#ifndef ENTRADA_SALIDA_H
#define ENTRADA_SALIDA_H

#include <vector>
using namespace std;

void ingresarSistema(vector<vector<double>> &matriz, vector<double> &terminos, int n);
void mostrarMatriz(const vector<vector<double>> &matriz, const vector<double> &terminos);
void guardarResultados(const vector<double> &soluciones, const string &archivo);

#endif

#pragma once


#include <vector>
#include <iostream>
using namespace std;

void cargarMatriz(vector<vector<double>>& matriz, double filas, double columnas);
void mostrarMatriz(const vector<vector<double>>& matriz, double filas, double columnas);
void intercambiarFilas(vector<vector<double>>& matriz, double fila1, double fila2, double columnas);
void multiplicarFilaPorEscalar(vector<vector<double>>& matriz, double fila, double escalar, double columnas);

void restarFilas(std::vector<std::vector<double>>& mat, double filaPivote, double filaObjetivo, double factor, double columnas);

double DeterminanteSarrus(const vector<vector<double>> &matriz);
double DeterminanteLaplace(const vector<vector<double>> &matriz); // recursivo
vector<vector<double>> menorMatriz(const vector<vector<double>> &matriz, double fila, double col);





#pragma once


#include <vector>
#include <iostream>
using namespace std;

void cargarMatriz(vector<vector<int>>& matriz, int filas, int columnas);
void mostrarMatriz(const vector<vector<int>>& matriz, int filas, int columnas);
void intercambiarFilas(vector<vector<int>>& matriz, int fila1, int fila2, int columnas);
void multiplicarFilaPorEscalar(vector<vector<int>>& matriz, int fila, int escalar, int columnas);

void restarFilas(std::vector<std::vector<int>>& mat, int filaPivote, int filaObjetivo, int factor, int columnas);

double determinanteSarrus(const vector<vector<double>> &matriz);
double determinanteLaplace(const vector<vector<double>> &matriz); // recursivo
vector<vector<double>> menorMatriz(const vector<vector<double>> &matriz, int fila, int col);




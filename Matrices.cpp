#include "Matrices.h"

// Carga de una matriz por teclado
void cargarMatriz (vector<vector<int>>& matriz, int filas, int columnas) {
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
			cin >> matriz[i][j];
		}
	}
}
// Muestra la matriz formateada
void mostrarMatriz (const vector<vector<int>>& matriz, int filas, int columnas) {
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}
// Intercambia dos filas de la matriz
void intercambiarFilas (vector<vector<int>>& matriz, int fila1, int fila2, int columnas) {
	for (int j = 0; j < columnas; ++j) {
		swap(matriz[fila1][j], matriz[fila2][j]);
	}
}
// Multiplica una fila por un escalar
void multiplicarFilaPorEscalar (vector<vector<int>>& matriz, int fila, int escalar, int columnas) {
	for (int j = 0; j < columnas; ++j) {
		matriz[fila][j] *= escalar;
	}
}
// Resta una fila origen a otra destino, multiplicando por un factor
void restarFilas(std::vector<std::vector<int>>& mat, int filaPivote, int filaObjetivo, int factor, int columnas) {
    for (int j = 0; j < columnas; j++) {
        mat[filaObjetivo][j] -= factor * mat[filaPivote][j];
    }
}




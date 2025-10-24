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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int DeterminanteSarrus(const vector<vector<int>> &matriz) {
    if (matriz.size() != 3) return 0; // seguridad
    int det = 0;
    det = matriz[0][0]*matriz[1][1]*matriz[2][2] +
          matriz[0][1]*matriz[1][2]*matriz[2][0] +
          matriz[0][2]*matriz[1][0]*matriz[2][1] -
          matriz[0][2]*matriz[1][1]*matriz[2][0] -
          matriz[0][0]*matriz[1][2]*matriz[2][1] -
          matriz[0][1]*matriz[1][0]*matriz[2][2];
    return det;
}

vector<vector<int>> menorMatriz(const vector<vector<int>> &matriz, int fila, int col) {
    int n = matriz.size();
    vector<vector<int>> menor(n-1, vector<int>(n-1));
    int r = 0, c;
    for (int i = 0; i < n; i++) {
        if (i == fila) continue;
        c = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) continue;
            menor[r][c] = matriz[i][j];
            c++;
        }
        r++;
    }
    return menor;
}

int DeterminanteLaplace(const vector<vector<int>> &matriz) {
    int n = matriz.size();
    if (n == 1) return matriz[0][0];
    if (n == 2) return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
    int det = 0;
    for (int j = 0; j < n; j++) {
        vector<vector<int>> menor = menorMatriz(matriz, 0, j);
        det += ( (j%2==0 ? 1 : -1) * matriz[0][j] * DeterminanteLaplace(menor) );
    }
    return det;
}






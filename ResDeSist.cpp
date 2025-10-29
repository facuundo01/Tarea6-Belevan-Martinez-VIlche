// ResDeSist.cpp
// Resolución de sistemas de ecuaciones por el método de Gauss-Jordan (solo enteros)

#include <iostream>
#include <vector>
#include <cstdlib>  // para abs()
#include <stdexcept>
#include "matrices.h"
#include "ResDeSist.h"

using namespace std;

vector<double> resolverPorGaussJordan(vector<vector<double>> A, vector<double> b) {
    try {
        int n = A.size();
        int columnas = n + 1;
        // Crear matriz aumentada [A | b]
        vector<vector<double>> mat(n, vector<double>(columnas));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = A[i][j];
            }
            mat[i][n] = b[i];
        }

        cout << "\n--- Matriz aumentada inicial ---\n";
        mostrarMatriz(mat, n, columnas);

        // Proceso de Gauss-Jordan
        for (int i = 0; i < n; i++) {
            double pivote = mat[i][i];

            // Si el pivote es 0, buscar otra fila para intercambiar
            if (pivote == 0) {
                bool intercambio = false;
                for (int k = i + 1; k < n; k++) {
                    if (mat[k][i] != 0) {
                        intercambiarFilas(mat, i, k, columnas);
                        pivote = mat[i][i];
                        cout << "Intercambio fila " << i + 1 << " con fila " << k + 1 << endl;
                        mostrarMatriz(mat, n, columnas);
                        intercambio = true;
                        break;
                    }
                }
                if (!intercambio) {
                    continue; // No se puede continuar con este pivote
                }
            }

            // Normalizar la fila pivote para hacer que el pivote sea 1 (solo si divisible)
            if (pivote != 1.0) {
                multiplicarFilaPorEscalar(mat, i, 1.0 / pivote, columnas);
            }

            cout << "Fila " << i + 1 << " normalizada:" << endl;
            mostrarMatriz(mat, n, columnas);

            // Hacer ceros en la columna del pivote
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    double factor = mat[k][i];
                    if (factor != 0)
                        restarFilas(mat, i, k, factor, columnas);
                }
            }

            cout << "Después de eliminar columna " << i + 1 << ":" << endl;
            mostrarMatriz(mat, n, columnas);
        }

        // Comprobar filas para detectar sistemas incompatibles o infinitas soluciones
        for (int i = 0; i < n; i++) {
            bool filaCero = true;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    filaCero = false;
                    break;
                }
            }

            if (filaCero && mat[i][n] != 0) {
                throw runtime_error("El sistema no tiene solucion unica.");
            }

            if (filaCero && mat[i][n] == 0) {
                throw runtime_error("El sistema tiene infinitas soluciones.");
            }
        }

        // Extraer las soluciones (cada variable está en la última columna)
        vector<double> soluciones(n);
        for (int i = 0; i < n; i++) {
            soluciones[i] = mat[i][n];
        }

        cout << "--- Soluciones ---" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << soluciones[i] << endl;
        }

        return soluciones;
    }
    catch (runtime_error& e) {
        cerr << "Se produjo un error: " << e.what() << endl;
        return {};
    }
}

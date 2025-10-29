#include <iostream>
#include <vector>
#include "Matrices.h"
#include "ResDeSist.h"
#include "InDatos.h"

using namespace std;

int main() {
    do {
        double n;
        cout << "Ingrese cantidad de ecuaciones/incognitas: ";
        cin >> n;

        vector<vector<double>> A(n, vector<double>(n));
        vector<double> b(n);

        cout << "Cargar matriz de coeficientes:\n";
        cargarMatriz(A, n, n);

        cout << "Ingrese terminos independientes:\n";
        for (int i = 0; i < n; i++) cin >> b[i];

        double det = 0;
        if (n == 3) {
            det = DeterminanteSarrus(A);
            cout << "Determinante (Sarrus): " << det << endl;
        }
        else if (n > 3) {
            det = DeterminanteLaplace(A);
            cout << "Determinante (Laplace): " << det << endl;
        }
        else if (n == 2) {
            det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
            cout << "Determinante (2x2): " << det << endl;
        }


        vector<double> soluciones = resolverPorGaussJordan(A, b);

        cout << "\nSoluciones:\n";
        for (int i = 0; i < soluciones.size(); i++) {
            cout << "x" << i + 1 << " = " << soluciones[i] << endl;
        }


        guardarResultados(soluciones, "resultados.txt");

        char opcion;
		cout << "\n¿Desea resolver otro sistema? (s/n): ";
		cin >> opcion;
        if (opcion == 'n' || opcion == 'N') {
			break;
        }
    } while (true);
}






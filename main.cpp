#include <iostream>
#include <vector>
#include "Matrices.h"
#include "ResDeSist.h"
#include "InDatos.h"

using namespace std;

int main() {
    int n;
    cout << "Ingrese cantidad de ecuaciones/incognitas: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<int> b(n);

    cout << "Cargar matriz de coeficientes:\n";
    cargarMatriz(A, n, n);

    cout << "Ingrese terminos independientes:\n";
    for (int i = 0; i < n; i++) cin >> b[i];

    int det = 0;
    if (n == 3) {
        det = DeterminanteSarrus(A);
        cout << "Determinante (Sarrus): " << det << endl;
    } else if (n > 3) {
        det = DeterminanteLaplace(A);
        cout << "Determinante (Laplace): " << det << endl;
    } else if (n == 2) {
        det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        cout << "Determinante (2x2): " << det << endl;
    }

    if (det == 0) {
        cout << "El sistema no tiene solucion unica.\n";
        return 0;
    }

    vector<int> soluciones = resolverPorGaussJordan(A, b);

    cout << "\nSoluciones:\n";
    for (int i = 0; i < soluciones.size(); i++) {
        cout << "x" << i+1 << " = " << soluciones[i] << endl;
    }


    guardarResultados(soluciones, "resultados.txt");


    return 0;
}






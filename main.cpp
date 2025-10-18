#include <iostream>
#include <vector>
#include "matrices.h"
#include "ResDeSist.h"

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

    resolverPorGaussJordan(A, b);

    return 0;
}



#include <iostream>
using namespace std;

void generarMatriz(int **matriz, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Ingrese valor para la posicion " << i << ", " << j << ": ";
			cin >> matriz[i][j];
		}
	}
}

void mostrarMatriz(int **matriz, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

void matrizTraspuesta(int **matriz, int m, int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cout << matriz[i][j];

		}
		cout << endl;
	}
}

int main() {
	int n, m;
	int **matriz;

	do {
		cout << "Ingrese numero de filas (m): ";
		cin >> m;
		cout << "Ingrese numero de columnas (n): ";
		cin >> n;
	} while (n < 0 && n>10 || m < 0 && m>10);

	matriz = new int*[m];
	for (int i = 0; i < m; i++) {
		matriz[i] = new int[n];
	}

	generarMatriz(matriz, m, n);
	cout << "MATRIZ INCIAL" << endl;
	mostrarMatriz(matriz, m, n);
	cout << endl << "MATRIZ TRASPUESTA" << endl;
	matrizTraspuesta(matriz, m, n);



	delete[] matriz;


	system("pause");
	return 0;
}
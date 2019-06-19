#include <iostream>
using namespace std;

void generarMatriz(int **matriz, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Ingrese un numero para la posicion " << i + 1 << ", " << j + 1 << ": ";
			cin >> matriz[i][j];
		}
	}
}

void mostrarMatriz(int **matriz, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j];
		}
		cout << endl;
	}
}

void simetrica(int **matriz, int n) {
	int cont = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matriz[i][j] == matriz[j][i]) {
				cont++;
			}
		}
	}

	if (cont == n * n) {
		cout << "La matriz ES SIMETRICA." << endl;
	}
	else {
		cout << "La matriz NO ES SIMETRICA." << endl;
	}
}

int main() {
	int n, m;
	int **matriz;
	cout << "Ingrese n: ";
	cin >> n;
	matriz = new int*[n];
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
	}


	generarMatriz(matriz, n);
	cout << "MATRIZ" << endl;
	mostrarMatriz(matriz, n);
	cout << endl;
	simetrica(matriz, n);





	system("pause");
	return 0;
}
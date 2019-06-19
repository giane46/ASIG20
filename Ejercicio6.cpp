#include <iostream>
using namespace std;

void generarMatriz(int &n, int **matriz) {
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			cout << "Ingrese el valor para lo posicion " << i << ", " << j << ": ";
			cin >> matriz[i][j];
		}
	}
}

void mostrarMatriz(int &n, int **matriz) {

	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			cout << matriz[i][j] << "\t";
		}
		cout << endl;
	}
}

void matrizResultante(int &n, int **matriz, int **matrizResul) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j) {
				matrizResul[i][j] = 0;
			}
			else {
				matrizResul[i][j] = matriz[i][j] + matriz[j][i];
			}
		}
	}
}

void mostrarResultado(int &n, int **matrizResul) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrizResul[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	int n;
	do {
		cout << "Ingrese n: ";
		cin >> n;
	} while (n < 2 && n > 50);

	int **matriz;
	matriz = new int*[n];
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
	}

	int **matrizResul;
	matrizResul = new int*[n];
	for (int i = 0; i < n; i++) {
		matrizResul[i] = new int[n];
	}



	generarMatriz(n, matriz);
	cout << "MATRIZ INICIAL" << endl;
	mostrarMatriz(n, matriz);
	cout << endl << endl;
	matrizResultante(n, matriz, matrizResul);
	cout << "MATRIZ RESULTANTE" << endl;
	mostrarResultado(n, matrizResul);



	system("pause");
	return 0;
}
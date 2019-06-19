#include <iostream>
#include <time.h>
using namespace std;
#define filas 4 //mesas de votacion
#define columnas 5 //candidatos

void generarVotos(int **votos, int &fila, int &columna) {
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			votos[i][j] = rand() % 51;
		}
	}
}

void mostrarMesas(int &mesa) {
	switch (mesa) {
	case 0:
		cout << "Mesa 1";
		break;
	case 1:
		cout << "Mesa 2";
		break;
	case 2:
		cout << "Mesa 3";
		break;
	case 3:
		cout << "Mesa 4";
		break;
	}
}

void mostrarVotos(int **votos, int &fila, int &columna) {
	cout << "\t\tCANDIDATOS" << endl;
	cout << "\t";
	for (int j = 0; j < columna; j++) {
		cout << j + 1 << "\t";
	}
	cout << endl;
	for (int i = 0; i < fila; i++) {
		mostrarMesas(i);
		for (int j = 0; j < columna; j++) {
			cout << "\t" << votos[i][j];
		}
		cout << endl;
	}
}

int votosPorCandidato(int **votos, int &fila, int &candidato) {
	int suma = 0;
	for (int i = 0; i < fila; i++) {
		suma += votos[i][candidato];
	}
	return suma;
}

int votosTotal(int **votos, int &fila, int &columna) {
	int sumaTotal = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			sumaTotal += votos[i][j];
		}
	}
	return sumaTotal;
}

int main() {
	srand(time(NULL));
	int **votos;
	int fila = filas;
	int columna = columnas;
	votos = new int *[filas];
	for (int i = 0; i < filas; i++) {
		votos[i] = new int[columnas];
	}

	generarVotos(votos, fila, columna);
	mostrarVotos(votos, fila, columna);

	float *sumaCand = new float[5];
	float *sumaTotal = new float[5];
	float *porcentaje = new float[5];
	int mayor = 0;
	int masVotado;
	int ganador1 = 0;
	int ganador2 = 0;
	for (int i = 0; i < columna; i++) {
		sumaCand[i] = votosPorCandidato(votos, fila, i);
		sumaTotal[i] = votosTotal(votos, fila, columna);
		porcentaje[i] = sumaCand[i] / sumaTotal[i] * 100;
		cout << "El total de votos obtenidos por el candidato " << i + 1 << " es " << sumaCand[i] << " votos con un " << porcentaje[i] << "%" << endl;

		if (sumaCand[i] > mayor) {
			mayor = sumaCand[i];
			masVotado = i;
		}
		/*FALTA INDICAR LOS QUE PASAN A SEGUNDA VUELTA*/
		/*if (porcentaje[i] >= 50) {
			ganador1 = masVotado;
		}
		else if (porcentaje[i] < 50) {
			int aux1 = porcentaje[0];
			int aux2;
			if (aux1 > porcentaje[i]) {
				ganador1 = i;
				aux2 = porcentaje[i];
			}
			if (aux2 > ganador1 && aux2 != ganador1) {
				ganador2 = i;
			}
		}
	}*/
		cout << "El candidato mas votado fue el " << masVotado + 1 << endl;
		/*if (ganador2 == 0) {
			cout << "El candidato ganador es " << ganador1 + 1 << endl;
		}
		else if (ganador2 != 0) {
			cout << "Los candidatos que pasan a segunda vuelta son " << ganador1 + 1 << " y " << ganador2 + 1 << endl;
		}*/

		/*for (int i = 0; i < columna; i++) {

			if {
				int aux = porcentaje[0];
				if (aux < porcentaje[1]) {
					ganador2 = aux;
				}
			}
		}
		cout << "Los candidatos que pasan a segunda vuelta son " << ganador1 + 1 << " y " << ganador2 + 1 << endl;*/




	}
	system("pause");
	return 0;
}
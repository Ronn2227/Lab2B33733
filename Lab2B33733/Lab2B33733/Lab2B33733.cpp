// Lab2B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pirata.h"

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

int _tmain(int argc, _TCHAR* argv[]) {
	srand((unsigned int)time(NULL));
	ofstream fileTabla;
	fileTabla.open("tabla-comparativa.txt");// Archivo con tabla comparativa.

	for (int i = 1; i <= 30; i++) {
		Pirata almaNegra;

		// Se obtiene el tick de inicio.
		auto inicio = std::chrono::high_resolution_clock::now();

		// =-= Inicio código a medir =-=
		almaNegra.buscarTesoroRecursivo();
		// =-= Fin código a medir =-=

		// Se obtiene el tick de final.
		auto fin = std::chrono::high_resolution_clock::now();

		// Se convierte a nanosegundos.
		nanoseconds ns = duration_cast<nanoseconds>(fin - inicio);

		almaNegra.imprimirTesoroRecursivo(); // Guarda en el archivo para recursivo la solucion.

		// Se obtiene el tick de inicio.
		auto inicio2 = std::chrono::high_resolution_clock::now();

		// =-= Inicio código a medir =-=
		almaNegra.buscarTesoroNoRecursivo();
		// =-= Fin código a medir =-=

		// Se obtiene el tick de final.
		auto fin2 = std::chrono::high_resolution_clock::now();

		// Se convierte a nanosegundos.
		nanoseconds ns2 = duration_cast<nanoseconds>(fin2 - inicio2);

		almaNegra.imprimirTesoroNoRecursivo(); // Guarda en el archivo para no recursivo la solucion.

		// Se guarda en el archivo de tabla comparativa.
		fileTabla << "Ejecucion " << i << ": " << endl;
		fileTabla << "La duracion del algoritmo recursivo es de:    " << ns.count() << " ns" << endl;
		fileTabla << "La duracion del algoritmo no recursivo es de: " << ns2.count() << " ns" << endl;
		fileTabla << endl;
		system("pause"); // Detiene para poder revisar la respuesta cada ejecucion;
	}

	system("pause");
	return 0;
}


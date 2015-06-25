#pragma once

#include "Tesoro.h"

using namespace std;

class Pirata {

private:
	
	ofstream fileRecursivo;
	ofstream fileNoRecursivo;

	Tesoro tesoro;

	int anillos; // Cantidad de anillos.
	int collares; // Cantidad de collares.
	int coronas; // Cantidad de coronas.
	int monedas; // Cantidad de monedas.
	int tesoros; // Cantidad de tesoros.
	int saco; // Peso que le cabe al saco.
	int valor; // Valor de la mejor combinación.

	int* vecTesoro; // Vector de enteros donde se guarda la mejor conbinación.

	Robable** posiblesTesoros;

	void vecCeros(); // Inicializa todos las posiciones de todos los vectores en 0.
	void buscarTesoro(int posicion, int valAcum, int pesAcum, int* vecSelec); // Busca la mejor combinación del tesoro recursivamente.
	void buscarIterativo(); // Busca la mejor combinación del tesoro de manera no recursiva (puntos extra).
	int calcularPeso(int* vecSelec); // Calcula el peso total que tienen los elementos seleccionados representados en vecSelec.
	int calcularValor(int* vecSelec); // Calcula el peso total que tienen los elementos seleccionados representados en vecSelec.

public:

	Pirata();
	virtual ~Pirata();

	void buscarTesoroRecursivo();
	void buscarTesoroNoRecursivo();
	void imprimirTesoroNoRecursivo(); // Guarda en el archivo la mejor combinación no recursiva.
	void imprimirTesoroRecursivo(); // Guarda en el archivo la mejor combinación recursiva.
};


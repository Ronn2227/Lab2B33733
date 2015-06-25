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
	int valor; // Valor de la mejor combinaci�n.
	//int peso; // Peso acumulado en la busqueda.

	int* vecBuscTesoro; // Vector de enteros con el que se realizar� la busqueda.

	int* vecTesoro; // Vector de enteros donde se guarda la mejor conbinaci�n.

	Robable** posiblesTesoros;

	void vecCeros(); // Inicializa todos las posiciones de todos los vectores en 0.
	void buscarTesoro(int posicion, int valAcum, int pesAcum, int* vecSelec); // Busca la mejor combinaci�n del tesoro recursivamente.
	void buscarMejorado(); // Busca la mejor combinaci�n del tesoro de manera no recursiva (puntos extra).

public:

	Pirata();
	virtual ~Pirata();

	void imprimirTesoroNoRecursivo(); // Guarda en el archivo la mejor combinaci�n no recursiva.
	void buscarTesoroRecursivo();
	void buscarTesoroNoRecursivo();
	void imprimirTesoroRecursivo(); // Guarda en el archivo la mejor combinaci�n recursiva.
};


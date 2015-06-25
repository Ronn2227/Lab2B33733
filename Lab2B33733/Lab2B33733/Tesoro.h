#pragma once

#include "Anillo.h"
#include "Collar.h"
#include "Corona.h"
#include "Moneda.h"
#include "Robable.h"

using namespace std;

class Tesoro {
private:

	ofstream file;

	int anillos; // Cantidad de anillos.
	int collares; // Cantidad de collares.
	int coronas; // Cantidad de coronas.
	int monedas; // Cantidad de monedas.
	int tesoros; // Cantidad de tesoros en total.
	int identificador; // Con lo que se asigna los id de cada objeto del tesoro.
	int avanzado; // Cuanto se ha avanzado en el vector de tesoros.
	Robable ** vecTesoros; // Vector de tesoros.

public:

	Tesoro();
	virtual ~Tesoro();

	int getCantAnillos(); // Devuelve cantidad de anillos.
	int getCantCollares(); // Devuelve cantidad de collares.
	int getCantCoronas(); // Devuelve cantidad de coronas.
	int getCantMonedas(); // Devuelve cantidad de monedas.
	int getCantTesoros(); // Devuelve cantidad total de tesoros.
	Robable** getTesoro(); // Devuelve vector de tesoros .
};


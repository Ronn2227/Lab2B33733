#include "stdafx.h"
#include "Pirata.h"



Pirata::Pirata() {
	fileRecursivo.open("robado-recursivo.txt");
	fileNoRecursivo.open("robado-no-recursivo.txt");

	this->anillos = tesoro.getCantAnillos();
	this->collares = tesoro.getCantCollares();
	this->coronas = tesoro.getCantCoronas();
	this->monedas = tesoro.getCantMonedas();
	this->tesoros = tesoro.getCantTesoros();
	this->saco = rand() % 1001 + 1000; // Setea la capacidad del saco en un valor aleatorio entre 1000 y 2000.
	this->valor = 0; // Inicializa el valor de la mejor combinaci�n en 0.
	//this->peso = 0; // Inicializa el peso acumulado en 0.

	//this->vecBuscTesoro = new int[tesoros];

	this->vecTesoro = new int[tesoros];

	this->posiblesTesoros = tesoro.getTesoro();

	vecCeros();
}


Pirata::~Pirata() {
	for (int i = 0; i < tesoros; i++) {
		this->posiblesTesoros[i] = 0;
		delete this->posiblesTesoros[i];
	}
	//delete posiblesTesoros; //(no se hace el delete a posibleTesoros porque se borra a lo que apunta vecTesoros en Tesoro y se cae el programa cuando se le hace delete en el desctructor del Tesoro)
	vecCeros();
	delete vecBuscTesoro;
	delete vecTesoro;

	fileRecursivo.close();
	fileNoRecursivo.close();
}

void Pirata::vecCeros(){
	for (int i = 0; i < tesoros; ++i) {
		//this->vecBuscTesoro[i] = 0;
		this->vecTesoro[i] = 0;
	}
}

void Pirata::imprimirTesoroRecursivo() {
	fileRecursivo << "Al saco le caben: " << saco << " gramos" << endl;
	fileRecursivo << "El valor m�ximo conseguido fue de: " << valor << endl;
	fileRecursivo << "Los articulos que llenaron el saco fueron: " << endl;
	fileRecursivo << endl;
	for (int i = 0; i < tesoros; i++) {
		if (this->vecTesoro[i] == 1){
			Anillo * ani = dynamic_cast<Anillo *>(posiblesTesoros[i]);
			if (ani != 0){
				fileRecursivo << "Anillo: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Collar * col = dynamic_cast<Collar *>(posiblesTesoros[i]);
			if (col != 0){
				fileRecursivo << "Collar: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Corona * cor = dynamic_cast<Corona *>(posiblesTesoros[i]);
			if (cor != 0){
				fileRecursivo << "Corona: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Moneda * mon = dynamic_cast<Moneda *>(posiblesTesoros[i]);
			if (mon != 0){
				fileRecursivo << "Moneda: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}
		}
	}

	fileRecursivo << endl;
}

void Pirata::imprimirTesoroNoRecursivo() {
	fileNoRecursivo << "Al saco le caben: " << saco << " gramos" << endl;
	fileNoRecursivo << "El valor m�ximo conseguido fue de: " << valor << endl;
	fileNoRecursivo << "Los articulos que llenaron el saco fueron: " << endl;
	fileNoRecursivo << endl;
	for (int i = 0; i < tesoros; i++) {
		if (this->vecTesoro[i] == 1){
			Anillo * ani = dynamic_cast<Anillo *>(posiblesTesoros[i]);
			if (ani != 0){
				fileNoRecursivo << "Anillo: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Collar * col = dynamic_cast<Collar *>(posiblesTesoros[i]);
			if (col != 0){
				fileNoRecursivo << "Collar: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Corona * cor = dynamic_cast<Corona *>(posiblesTesoros[i]);
			if (cor != 0){
				fileNoRecursivo << "Corona: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}

			Moneda * mon = dynamic_cast<Moneda *>(posiblesTesoros[i]);
			if (mon != 0){
				fileNoRecursivo << "Moneda: " << posiblesTesoros[i]->getId() << " " << "peso: " << posiblesTesoros[i]->getPeso() << " " << "valor: " << posiblesTesoros[i]->getValor() << endl;
			}
		}
	}

	fileNoRecursivo << endl;
}

void Pirata::buscarTesoroRecursivo() {
	buscarTesoro(0, 0, 0, vecTesoro);
}

void Pirata::buscarTesoro(int posicion, int valAcum, int pesAcum, int* vecSelec) {
	int* vecSeleccionados = new int[tesoros];
	int valorAcumulado;
	int pesoAcumulado;

	for (int i = 0; i < tesoros; i++) {
		vecSeleccionados[i] = vecSelec[i];
	}

	if (posicion + 1 < tesoros) {
		buscarTesoro(posicion + 1, valAcum, pesAcum, vecSeleccionados);
	}

	if (pesAcum + posiblesTesoros[posicion]->getPeso() <= saco) {
		vecSeleccionados[posicion] = 1;
		valorAcumulado = valAcum + posiblesTesoros[posicion]->getValor();
		pesoAcumulado = pesAcum + posiblesTesoros[posicion]->getPeso();
		if (valorAcumulado > valor) {
			valor = valorAcumulado;
			for (int i = 0; i < tesoros; i++) {
				this->vecTesoro[i] = vecSeleccionados[i];
			}
		}
	}

	if (posicion + 1 < tesoros && pesoAcumulado + posiblesTesoros[posicion + 1]->getPeso() <= saco) {
		buscarTesoro(posicion + 1, valorAcumulado, pesoAcumulado, vecSeleccionados);
	}
}

void Pirata::buscarMejorado() {

}
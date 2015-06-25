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
	this->valor = 0; // Inicializa el valor de la mejor combinación en 0.
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
	delete vecTesoro;

	fileRecursivo.close();
	fileNoRecursivo.close();
}

void Pirata::vecCeros(){
	for (int i = 0; i < tesoros; ++i) {
		this->vecTesoro[i] = 0;
	}

	this->valor = 0;
}

void Pirata::imprimirTesoroRecursivo() {
	fileRecursivo << "Al saco le caben: " << saco << " gramos" << endl;
	fileRecursivo << "El valor máximo conseguido fue de: " << valor << endl;
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
	fileNoRecursivo << "El valor máximo conseguido fue de: " << valor << endl;
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
	vecCeros();
	buscarTesoro(0, 0, 0, vecTesoro);
}

void Pirata::buscarTesoro(int posicion, int valAcum, int pesAcum, int* vecSelec) {
	int* vecSeleccionados = new int[tesoros];
	int valorAcumulado = 0;
	int pesoAcumulado = 0;

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

		if (posicion + 1 < tesoros) {
			buscarTesoro(posicion + 1, valorAcumulado, pesoAcumulado, vecSeleccionados);
		}
	}
	/*
	if (posicion + 1 < tesoros && pesoAcumulado + posiblesTesoros[posicion + 1]->getPeso() <= saco) {
		buscarTesoro(posicion + 1, valorAcumulado, pesoAcumulado, vecSeleccionados);
	}
	*/
}

void Pirata::buscarTesoroNoRecursivo() {
	buscarIterativo();
}

void Pirata::buscarIterativo() {
	vecCeros();
	int cantidadIteraciones = 1;
	int* vecSeleccionados = new int[tesoros];

	for (int i = 0; i < tesoros; i++) { // Se calcula la cantidad posibles de iteraciones finales segun el tamaño del vector.
		cantidadIteraciones = cantidadIteraciones * 2;
	}

	for (int i = 0; i < cantidadIteraciones; i++) {
		int temp = i;
		int donde = tesoros - 1;

		for (int j = 0; j < tesoros; j++) {
			vecSeleccionados[j] = 0;
		}

		if (temp == 1) {
			vecSeleccionados[donde] = temp;
		}
		else {
			while (temp != 0) { // Se calcula el valor binario de i que sirve para llenar el vector de seleccionados con todas las posibles combinaciones.
				if (temp / 2 > 1) {
					vecSeleccionados[donde] = temp % 2;
					temp = temp / 2;
				}
				else {
					vecSeleccionados[donde] = temp % 2;
					donde--;
					vecSeleccionados[donde] = temp / 2;
					temp = 0;
				}
				donde--;
			}
		}

		if (calcularPeso(vecSeleccionados) <= saco){
			if (calcularValor(vecSeleccionados) > valor) {
				valor = calcularValor(vecSeleccionados);
				for (int j = 0; j < tesoros; j++) {
					this->vecTesoro[j] = vecSeleccionados[j];
				}
			}
		}
	}
}

int Pirata::calcularPeso(int* vecSelec) {
	int pesAcum = 0;

	for (int i = 0; i < tesoros; i++) {
		if (vecSelec[i] == 1) {
			pesAcum = pesAcum + posiblesTesoros[i]->getPeso();
		}
	}

	return pesAcum;
}

int Pirata::calcularValor(int* vecSelec) {
	int valAcum = 0;

	for (int i = 0; i < tesoros; i++) {
		if (vecSelec[i] == 1) {
			valAcum = valAcum + posiblesTesoros[i]->getValor();
		}
	}

	return valAcum;
}
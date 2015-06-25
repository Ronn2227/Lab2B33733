#include "stdafx.h"
#include "Tesoro.h"


Tesoro::Tesoro(){
	file.open("tesoro.txt");

	this->anillos = rand() % 3 + 5; // Setea cantidad de anillos en un valor aleatorio entre 5 y 7.
	this->collares = rand() % 4 + 2; // Setea cantidad de collares en un valor aleatorio entre 2 y 5.
	this->coronas = rand() % 5 + 1; // Setea cantidad de coronas en un valor aleatorio entre 1 y 5.
	this->monedas = rand() % 6 + 5; // Setea cantidad de monedas en un valor aleatorio entre 5 y 10.
	this->tesoros = anillos + collares + coronas + monedas;
	this->identificador = 1;
	this->avanzado = 0;
	this->vecTesoros = new Robable*[tesoros];

	for (int i = 0; i < anillos; i++) { // Llena el vector de tesoros con los anillos correspondientes.
		this->vecTesoros[avanzado] = new Anillo(identificador);
		file << "Anillo: " << vecTesoros[avanzado]->getId() << " " << "peso: "
			<< vecTesoros[avanzado]->getPeso() << " " << "valor: "
			<< vecTesoros[avanzado]->getValor() << endl;
		identificador++;
		avanzado++;
	}

	file << endl;

	for (int i = 0; i < collares; i++) { // Llena el vector de tesoros con los collares correspondientes.
		this->vecTesoros[avanzado] = new Collar(identificador);
		file << "Collar: " << vecTesoros[avanzado]->getId() << " " << "peso: "
			<< vecTesoros[avanzado]->getPeso() << " " << "valor: "
			<< vecTesoros[avanzado]->getValor() << endl;
		identificador++;
		avanzado++;
	}

	file << endl;

	for (int i = 0; i < coronas; i++) { // Llena el vector de tesoros con las coronas correspondientes.
		this->vecTesoros[avanzado] = new Corona(identificador);
		file << "Corona: " << vecTesoros[avanzado]->getId() << " " << "peso: "
			<< vecTesoros[avanzado]->getPeso() << " " << "valor: "
			<< vecTesoros[avanzado]->getValor() << endl;
		identificador++;
		avanzado++;
	}

	file << endl;

	for (int i = 0; i < monedas; i++) { // Llena el vector de tesoros con las monedas correspondientes.
		this->vecTesoros[avanzado] = new Moneda(identificador);
		file << "Moneda: " << vecTesoros[avanzado]->getId() << " " << "peso: "
			<< vecTesoros[avanzado]->getPeso() << " " << "valor: "
			<< vecTesoros[avanzado]->getValor() << endl;
		identificador++;
		avanzado++;
	}

	file.close();
}


Tesoro::~Tesoro() {
	for (int i = 0; i < tesoros; ++i) { //Elimina el vector de tesoros.
		this->vecTesoros[i] = 0;
		delete this->vecTesoros[i];
	}
	delete vecTesoros;
}

int Tesoro::getCantAnillos() {
	return anillos;
}

int Tesoro::getCantCollares() {
	return collares;
}

int Tesoro::getCantCoronas() {
	return coronas;
}

int Tesoro::getCantMonedas() {
	return monedas;
}

int Tesoro::getCantTesoros() {
	return tesoros;
}

Robable** Tesoro::getTesoro(){
	return vecTesoros;
}
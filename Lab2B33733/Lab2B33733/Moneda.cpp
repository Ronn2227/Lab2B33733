#include "stdafx.h"
#include "Moneda.h"


Moneda::Moneda(int id) {
	this->id = id;
	this->peso = rand() % 101 + 100;
	this->valor = rand() % 100 + 1;
}


Moneda::~Moneda() {
}

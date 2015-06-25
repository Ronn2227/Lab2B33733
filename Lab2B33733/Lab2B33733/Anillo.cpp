#include "stdafx.h"
#include "Anillo.h"


Anillo::Anillo(int id) {
	this->id = id;
	this->peso = rand() % 101 + 200;
	this->valor = rand() % 101 + 100;
}


Anillo::~Anillo() {
}

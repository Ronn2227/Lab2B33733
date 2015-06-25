#include "stdafx.h"
#include "Collar.h"


Collar::Collar(int id) {
	this->id = id;
	this->peso = rand() % 501 + 500;
	this->valor = rand() % 2001 + 2000;
}


Collar::~Collar() {
}

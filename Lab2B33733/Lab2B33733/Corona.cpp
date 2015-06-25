#include "stdafx.h"
#include "Corona.h"


Corona::Corona(int id) {
	this->id = id;
	this->peso = rand() % 1501 + 500;
	this->valor = rand() % 9001 + 1000;
}


Corona::~Corona() {
}

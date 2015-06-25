#include "stdafx.h"
#include "Robable.h"


Robable::Robable(){
}


Robable::~Robable(){
}

void Robable::setPeso(int peso){
	this->peso = peso;
}

int Robable::getPeso() {
	return peso;
}

void Robable::setValor(int valor) {
	this->valor = valor;
}

int Robable::getValor() {
	return valor;
}

void Robable::setId(int id) {
	this->id = id;
}

int Robable::getId() {
	return id;
}

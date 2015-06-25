#pragma once

using namespace std;

class Robable{

public:
	int peso, valor, id;

	Robable();
	virtual ~Robable();

	void setPeso(int);
	int getPeso();
	void setValor(int);
	int getValor();
	void setId(int);
	int getId();
};


// Lab2B33733.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Robable.h"
#include "Pirata.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));

	Pirata barbaSucia;
	
	barbaSucia.imprimirTesoroNoRecursivo();
	barbaSucia.buscarTesoroRecursivo();
	barbaSucia.imprimirTesoroRecursivo();

	//barbaSucia.buscarTesoroNoRecursivo();

	return 0;
}


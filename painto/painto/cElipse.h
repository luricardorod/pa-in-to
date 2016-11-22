#pragma once
#include "cFiguras.h"
#define ClsId_Elipse 3

class cElipse:cFiguras
{
public:
	float radio1, radio2;
	int GetClsId();
	cElipse();
	~cElipse();
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
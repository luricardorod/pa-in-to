#pragma once
#include "cRectangulo.h"

class cRectanguloRedondeado:public cRectangulo
{
public:
	float radio;
	int GetClsId();
	cRectanguloRedondeado();
	~cRectanguloRedondeado();
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
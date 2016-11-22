#pragma once
#include "cRectangulo.h"
#define ClsId_RectanguloRedondeado 2

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
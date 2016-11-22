#pragma once
#include "cFiguras.h"

class cElipse :public cFiguras
{
public:
	float radio1, radio2;
public:
	cElipse();
	~cElipse();
	
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};
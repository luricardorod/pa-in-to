#pragma once
#include "cFiguras.h"

class cLinea:public cFiguras
{
public:
	Point p1, p2;
public:
	cLinea();
	~cLinea();
	
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};
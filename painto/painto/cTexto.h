#pragma once
#include "cFiguras.h"

class cTexto:public cFiguras
{
public:
	string texto;
	Point p1, p2, p3, p4;
public:
	cTexto();
	~cTexto();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};
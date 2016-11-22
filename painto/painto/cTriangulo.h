#pragma once
#include "cFiguras.h"

class cTriangulo:public cFiguras
{
public:
	Point p1, p2, p3;
public:
	cTriangulo();
	~cTriangulo();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};
#pragma once
#include "cFiguras.h"

class cLinea:public cFiguras
{
public:
	Point p1, p2;
	int GetClsId();
	cLinea();
	~cLinea();

	void Dibujar();
	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
};
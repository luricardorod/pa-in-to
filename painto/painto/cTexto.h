#pragma once
#include "cFiguras.h"

class cTexto:public cFiguras
{
public:
	Point p1, p2, p3, p4;
	int GetClsId();
	cTexto();
	~cTexto();

	void Dibujar();
	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
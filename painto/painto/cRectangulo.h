#pragma once
#include "cFiguras.h"
#include "CDibujable.h"

class cRectangulo :public cFiguras
{
public:
	Point p1, p2, p3, p4;
	int GetClsId();
	cRectangulo();
	~cRectangulo();

	void Dibujar();
	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
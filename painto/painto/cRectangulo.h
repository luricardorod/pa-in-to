#pragma once
#include "cFiguras.h"

class cRectangulo:public cFiguras
{
public:
	Point p1, p2, p3, p4;
public:
	cRectangulo();
	~cRectangulo();

	virtual void setColorLinea(Vector3f nuevoColor);
	virtual Vector3f getColorLinea();

	virtual bool hitTest(Point mouseCoords);

	virtual void Guardar(ofstream &salida);
	virtual void Cargar(ifstream &entrada);
	virtual int GetClsId();
	virtual void Dibujar();
};
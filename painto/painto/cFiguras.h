#pragma once
#include "cSeleccionable.h"

struct Vector3f
{
	int x; int y; int z;
};

struct Point
{
	float x; float y;
};
class cFiguras:public cSeleccionable
{
public:
	Vector3f colorRelleno;
	Vector3f colorLinea;
	virtual void setColorLinea(int nuevoColor) = 0;
	virtual int getColorLinea() = 0;
	Point posicion;
	long id_Nombre;
	virtual bool hitTest() = 0;
	cFiguras();
	~cFiguras();
};


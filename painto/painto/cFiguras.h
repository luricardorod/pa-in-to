#pragma once
#include "cSeleccionable.h"

struct Vector3f
{
	float x; float y; float z;
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
	virtual void setColorLinea(Vector3f nuevoColor) = 0;
	virtual Vector3f getColorLinea() = 0;
	Point posicion;
	long id_Nombre;
	//virtual bool hitTest() = 0;
	cFiguras();
	~cFiguras();
};
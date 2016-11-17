#pragma once
#include "cSeleccionable.h"

class cFiguras:public cSeleccionable
{
public:
	// colorRelleno;
	// colorLinea;
	int posicion;
	long id_nombre;
	bool hitTest();
	cFiguras();
	~cFiguras();
};


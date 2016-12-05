#pragma once
#include "CDibujable.h"

class cSeleccionable :public CDibujable
{
public:
	bool visible;
	bool desbloqueado;
	string nombre;
public:
	virtual bool hitTest(Point mouseCoords) = 0;
};
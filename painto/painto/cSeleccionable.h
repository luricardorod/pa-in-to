#pragma once
#include "CDibujable.h"

class cSeleccionable :public CDibujable
{
public:
	bool visible;
	bool bloqueado;
	bool seleccionado;
public:
	virtual bool hitTest(Point mouseCoords) = 0;
};
#pragma once
#include "CDibujable.h"
class cSeleccionable:public CDibujable
{
public:
	bool visible;
	bool bloqueado;
	bool seleccionado;
	virtual bool hitTest() = 0;
};


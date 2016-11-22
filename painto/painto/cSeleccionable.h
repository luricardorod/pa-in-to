#pragma once
#include "CDibujable.h"

class cSeleccionable:public CDibujable
{
public:
	bool visible;
	bool bloqueado;
	bool seleccionado;
public:
	virtual bool hitTest(Point mouseCoords) = 0;

	virtual void Guardar(ofstream &salida) = 0;
	virtual void Cargar(ifstream &entrada) = 0;
	virtual int GetClsId() = 0;
	virtual void Dibujar() = 0;
};
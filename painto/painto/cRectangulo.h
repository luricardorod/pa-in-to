#pragma once
#include "cFiguras.h"

class cRectangulo:public cFiguras
{
public:
	float base, altura;
public:
	cRectangulo();
	~cRectangulo();

	virtual bool hitTest(Point mouseCoords);

	virtual void Guardar(ofstream &salida);
	virtual void Cargar(ifstream &entrada);
	virtual int GetClsId();
	virtual void Dibujar();
};
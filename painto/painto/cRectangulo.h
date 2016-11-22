#pragma once
#include "cFiguras.h"
#include "CDibujable.h"
#define ClsId_Rectangulo 1

class cRectangulo:public cFiguras
{
public:
	Point p1, p2, p3, p4;
	int GetClsId();
	void Dibujar();
	cRectangulo();
	~cRectangulo();
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
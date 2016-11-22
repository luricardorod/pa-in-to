#pragma once
#include "cFiguras.h"
#define ClsId_Triangulo 4

class cTriangulo:cFiguras
{
public:
	Point p1, p2, p3;
	int GetClsId();
	cTriangulo();
	~cTriangulo();
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
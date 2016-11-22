#pragma once
#include "cFiguras.h"

class cElipse :public cFiguras
{
public:
	float radio1, radio2;
	int GetClsId();
	void Dibujar();
	cElipse();
	~cElipse();
	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	bool hitTest(Point mouseCoords);
	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};
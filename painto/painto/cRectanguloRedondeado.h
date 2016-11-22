#pragma once
#include "cRectangulo.h"

class cRectanguloRedondeado:public cRectangulo
{
public:
	float radio;
public:
	cRectanguloRedondeado();
	~cRectanguloRedondeado();

	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();

	bool hitTest(Point mouseCoords);

	void Guardar(ofstream &salida);
	void Cargar(ifstream &entrada);
	int GetClsId();
	void Dibujar();
};
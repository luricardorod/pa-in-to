#pragma once
#include "cFiguras.h"
#include <vector>

class cTiraDeLinea:public cFiguras
{
public:
	std::vector<Point> listaDePuntos;
	int GetClsId();
	cTiraDeLinea();
	~cTiraDeLinea();

	void Dibujar();
	void setColorLinea(Vector3f nuevoColor);
	Vector3f getColorLinea();
	bool hitTest(Point mouseCoords);

	void Guardar(ofstream & salida);
	void Cargar(ifstream & entrada);
};